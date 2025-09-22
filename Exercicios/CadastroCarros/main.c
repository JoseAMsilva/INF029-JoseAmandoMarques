#include "function.h"

int main(void) {
  int escolhaMain, placaDel, sair;
  escolhaMain = placaDel = sair = 0;
  while(sair == 0)
    {
      printf("1 - Cadastrar\n2 - Listar\n3 - Atualizar\n4 - Deletar\n5 - Sair\n>>");
      scanf("%d", &escolhaMain);
      switch(escolhaMain)
      {
        case 1:
        {
          cadastro();
          break;
        }
        case 2:
        {
          printf("listando...\n");
          listar();
          break;
        }
        case 3:
        {
          char placaAtt[8];
          fflush(stdin);
          printf("Insira a placa do carro que quer atualizar\n");
          fgets(placaAtt, 8, stdin);
          size_t ln = strlen(placaAtt) - 1;

          if (placaAtt[ln] == '\n')
              placaAtt[ln] = '\0';
          atualizar(placaAtt);
          break;
        }
        case 4:
        {
          printf("Deletando...\n");
          deletar();
          break;
        }
        case 5:
        {
          printf("Saindo...\n");
          sair = 1;
          break;
        }
        default:
        {
          printf("Opcao invalida!\n");
          break;
        }
      }
    }

    return 0;
}