#include<stdio.h>
#include<conio.h>
#include<stdbool.h>

#define TEMP_FILE_NAME "FACENS PROJECT"


// Funcao simples para criar uma copia do arquivo

bool CopyFile(char INPUT_FILE_NAME[255], char OUTPUT_FILE_NAME[255]) {

    FILE *input_file, *output_file;		//definindo o arquivo de entrada e saida "input_file ==> output_file" 
    char character;

    input_file = fopen(INPUT_FILE_NAME, "r");	// Abrindo o arquivo no modo de leitura apenas para copiar os dados.
    output_file = fopen(OUTPUT_FILE_NAME, "w");	// Abrindo o modo de reescrever o arquivo de entrada "input_file"
    if ((input_file == NULL) || (output_file == NULL)) {	 // Verificando os arquivos se foram criados de forma bem sucedida.
        return false;	// Caso os arquivos nao sejam criados ou acessados de forma correta, cancelar funcao.
    }

    character = fgetc(input_file); //pegando o primeiro caractere do documento de entrada.
    
    while (character != EOF) {   	// EOF=erro ==> executar apenas enquanto tiver caracteres restantes.
		fputc(character, output_file); 	// adicionando o caractere copiado do arquivo de entrada para o arquivo de saida.
        character = fgetc(input_file);		// pegando o proximo caractere do documento de entrada.
    }

    fclose(input_file); // fechando o arquivo de entrada
    fclose(output_file); // fechando o arquivo de saida 
}


bool encryption(char key[], char INPUT_FILE_NAME[], int method){

    FILE *original_file, *temp_file; //Arquivo original a se codificado/decodificado ih arquivo temporario para armazenar codificacao. 
    char character;

    //CopyFile(INPUT_FILE_NAME, "backup.txt");
	
    original_file = fopen(INPUT_FILE_NAME, "r"); //Arquivo original sendo lido
    temp_file = fopen(TEMP_FILE_NAME, "w"); //Arquivo temporario sendo escrito
    if ((original_file == NULL) || (temp_file == NULL)) {// Verificando os arquivos se foram criados de forma bem sucedida.
        return 0; // Caso os arquivos nao sejam criados ou acessados de forma correta, cancelar funcao.
    }
    
    character = fgetc(original_file); //pegando o primeiro caractere do documento de entrada.
    int position_key = 0; // index da posicao de cada caractere da senha, comecando em 0.
    while (character != EOF) { // EOF=erro ==> executar apenas enquanto tiver caracteres restantes.
    
		/*
	Aqui pegamos a posicao na tabela ASCII de acordo com cada letra da senha.
	Adicionado a posicao do char da senha, no conteudo do arquivo, criando um ciclo a seguir:

	Senha123Senha123Senha123Senha123S
	Esse seria o conteudo do arquivo.

	Na primeira linha temos S da senha e E do conteudo, portando:
	S = 83
	E = 69
	83+69 = 152
	152 = '\x98'
*/

		character += key[position_key]*method; // Movimenta o char de acordo com o valor adotado na variavel "position_key" , assim movimentando o char na tabela ASCII.
		
        fputc(character, temp_file); // Copia as caracteres do arquivo temporario uma por uma.
        
        if (key[position_key] == '\0') { // Caso chegue no fim da senha recomecar leitura da senha, pelo index 0
            position_key = 0;
            
        }
        else { // Continuando leitura da senha.
            position_key += 1;
            
        }
        
        character = fgetc(original_file); // pegando o proximo caractere do documento de entrada.
        
    }

    fclose(original_file); // fecha o arquivo original
    
    fclose(temp_file); // fecha o arquivo temporario
	
    CopyFile(TEMP_FILE_NAME, INPUT_FILE_NAME); //Copia arquivo temporario codificado para o arquivo original 

    if (!remove(TEMP_FILE_NAME)) { //exclue o arquivo temporario criado 
        return true; // Arquivo temporario exluido
    }
    else {
        return false; //funcionou o codigo mas ele nao removeu o arquivo temporario. 
    }
}


bool Encode(char key[], char INPUT_FILE_NAME[]) { // o Bool apenas troca o valor do METHOD, assim movimentando a tabela de acordo com a position_key utilizada.
    return encryption(key, INPUT_FILE_NAME, 1);
}

bool Decode(char key[], char INPUT_FILE_NAME[]) { // o Bool apenas troca o valor do METHOD, assim movimentando a tabela de acordo com a position_key utilizada.
    return encryption(key, INPUT_FILE_NAME, -1);
}
