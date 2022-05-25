#include"main.h"


int main() {

  setlocale(LC_ALL, "Portuguese");
  bool continuar = true;

  while (true) { // repeticao.
    char FileName[255],
      Key[255],
      resposta;
    int i;
    printf("\n\t-----------------------------------------------------------------");
    printf("\n\t|Voce deseja criptografar ou descriptografar ? Responda C ou D.\t|\t\n");
    printf("\t-----------------------------------------------------------------");
    printf("\n\n\t\tresposta:");
    gets( & resposta); //pega de resposta do usuario a pergunta feita no printf a cima 
    resposta = tolower(resposta);

    if (resposta != 'c' && resposta != 'd') { // confere se o usuario digitou corretamente.

      printf("\n\t\tNao e um caracter valido, coloque apenas C ou D !!!!!!!!!\n\n");

      continue;

    } else if (resposta == 'c') {

      printf("\n\t\tDigite o nome do arquivo com o formato .txt como {NOME_DO_ARUIVO.txt} \n\n\t\t Nome do Arquivo : "); //digitar o arquivo .txt
      gets(FileName); // pega o nome do arquivo que deve estar contido no mesmo local do programa.
      printf("\n\t\tDigite a senha: ");
      gets(Key); // pega o nivel que voce queira movimentar ASCII.
      Encode(Key, FileName);
      printf("\n\t\t---------------------------");
      printf("\n\t\t| Programa criptografado. |\n");
      printf("\t\t---------------------------\n\n");
      printf("\n\t\tPressione qualquer tecla para continuar...");
      getchar();
    } else if (resposta == 'd') {
      printf("\n\t\tDigite o nome do arquivo com o formato .txt como {NOME_DO_ARUIVO.txt} \n\n\t\n\t\tDigite o nome do Arquivo: ");
      gets(FileName);
      printf("\n\t\tsenha do arquivo :");
      gets(Key);
      Decode(Key, FileName);

      printf("\n\t\t---------------------------");
      printf("\n\t\t| Programa desptografado. |\n");
      printf("\t\t---------------------------\n\n");
      
	getchar();
	if(getchar() == 'egg'){}

    while (true) {

      printf("\n\t\tDeseja continuar ? S ou N: ");
      gets( & resposta);
      resposta = tolower(resposta);

      if (resposta == 's') {

        break;
      } else if (resposta == 'n') {

        printf("\n\t\t-------------------------");
        printf("\n\t\t|Programa Finalizado !!!|");
        printf("\n\t\t-------------------------\n\n");
        continuar = false;
        break;
      } else {
        printf("\n\t\tDigite apenas S ou N !!!!!!!!!\n\n");
      }
    }
    if (resposta == 'n') {
      break;
    }
  }

}
}

