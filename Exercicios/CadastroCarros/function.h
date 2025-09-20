#ifndef function_h
#define function_h
#include <stdio.h>
#include <stdlib.h>
#define TAM 4

typedef struct
{
  char modelo[20];
  char marca[20];
  char placa[8];
  char cor[10];
  char ativo;
  int ano;
  int potencia;
}carros[TAM];

carros registro[100];

void cadastro(void)
{
  int parar, escolhaAdd, posicaoAdd;
  parar = escolhaAdd = posicaoAdd = 0;
  while(parar == 0)
    {
      printf("Digite a marca do carro:\n>>");
      fgets(registro[posicaoAdd]->marca, 20, stdin);
      fflush(stdin);

      printf("\nDigite o modelo do carro:\n>>");
      fgets(registro[posicaoAdd]->modelo, 20, stdin);
      fflush(stdin);

      printf("\nDigite a placa do carro:\n>>");
      fgets(registro[posicaoAdd]->placa, 8, stdin);
      fflush(stdin);

      printf("\nDigite a cor do carro:\n>>");
      fgets(registro[posicaoAdd]->cor, 10, stdin);
      fflush(stdin);

      printf("\nDigite o ano do carro:\n>>");
      scanf("%d", &registro[posicaoAdd]->ano);

      printf("\nDigite a potencia do carro:\n>>");
      scanf("%d", &registro[posicaoAdd]->potencia);
      registro[posicaoAdd]->ativo = 'A';
      posicaoAdd++;
      printf("\nDeseja cadastrar outro carro?\n1 - Sim\n2 - Nao\n>>");
      scanf("%d", &escolhaAdd);
      if(escolhaAdd == 2)
      {
        parar = 1;
      }
    }
  return;
}

void listar(void)
{
  printf("Carros cadastrados:\n");
  for(int i = 0; i < TAM; i++)
    {
      if (registro[i]->ativo == 'A')
      {
        printf("Modelo: %s", registro[i]->modelo);
        printf("Marca: %s", registro[i]->marca);
        printf("Placa: %s", registro[i]->placa);
        printf("Cor: %s", registro[i]->cor);
        printf("Ano: %d", registro[i]->ano);
        printf("Potencia: %d", registro[i]->potencia);
        printf("\n");
      }
    }
  return;
}

#endif // function_h