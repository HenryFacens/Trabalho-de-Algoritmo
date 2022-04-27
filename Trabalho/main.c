#include"main.h"

int main()
{inicio:
setlocale(LC_ALL, "Portuguese");
	char FileName[255], Key[255],resposta;
int i;
	printf("\n\t-----------------------------------------------------------------");
	printf("\n\t|Voce deseja criptografar ou descriptografar ? Responda C ou D.\t|\t\n");
	printf("\t-----------------------------------------------------------------");
	printf("\n\n\t\tresposta:");
	gets(&resposta);
	tolower(resposta);
if(resposta !='c'&& resposta !='d')
{ 

printf("\n\t\tNao e um caracter valido, coloque apenas C ou D !!!!!!!!!\n\n");
goto inicio;

}
else if(resposta=='c')
{


	printf("\n\t\tDigite o nome do arquivo com o formato .txt como {NOME_DO_ARUIVO.txt} \n\n\t\t Nome do Arquivo : "); //digitar o arquivo .txt
		gets(FileName);
	printf("\n\t\tDigite a senha: ");
		gets(Key);
	Encode(Key, FileName);
	printf("\n\t\t---------------------------");
	printf("\n\t\t| Programa criptografado. |\n");
		printf("\t\t---------------------------\n\n");
	printf("\n\t\tPressione qualquer tecla para continuar...");
	getchar();
}
	else if(resposta=='d'){
	printf("\n\t\tDigite o nome do arquivo com o formato .txt como {NOME_DO_ARUIVO.txt} \n\n\t\n\t\tDigite o nome do Arquivo: ");
		gets(FileName);
	Decode(Key, FileName);
	printf("\n\n\tsenha do arquivo :");
		gets(Key);
	printf("\n\t\t---------------------------");
	printf("\n\t\t| Programa desptografado. |\n");
		printf("\t\t---------------------------\n\n");


}

yesorno:
	printf("\n\t\tDeseja continuar ? S ou N: ");
	gets(&resposta);
	tolower(resposta);
	
	if(resposta!='s'&& resposta!='n'){
		
		printf("\n\t\tDigite apenas S ou N !!!!!!!!!\n\n");
		goto yesorno;
	}
	
	
	else if(resposta=='s'){
		goto inicio;
	
	}
	else{
		printf("\n\t\t-------------------------");
	printf("\n\t\t|Programa Finalizado !!!|");
	printf("\n\t\t-------------------------\n\n");
}
}




