#ifndef function_h
#define function_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

typedef struct dados_carro
{
  char modelo[20];
  char marca[20];
  char placa[8];
  char cor[10];
  char ativo;
  int ano;
  int potencia;
}carros;

carros registro[100];

int checarPlaca(char placa[]);
int encontrarIndice(char placa[]);
void cadastro(void);
void listar(void);
void atualizar(char placa[]);
void deletar(void);

int qtdeCarros = 0;

void cadastro()
{
  int parar, escolhaAdd;
  parar = escolhaAdd = 0;
  while(parar == 0)
    {
      fflush(stdin);
      char placa[8];
      int valido = 0;

      printf("\nDigite a marca do carro:\n>>");
      fgets(registro[qtdeCarros].marca, 20, stdin);
      size_t ln = strlen(registro[qtdeCarros].marca) - 1;
      if (registro[qtdeCarros].marca[ln] == '\n')
          registro[qtdeCarros].marca[ln] = '\0';
      fflush(stdin);

      printf("\nDigite o modelo do carro:\n>>");
      fgets(registro[qtdeCarros].modelo, 20, stdin);
      ln = strlen(registro[qtdeCarros].modelo) - 1;
      if (registro[qtdeCarros].modelo[ln] == '\n')
          registro[qtdeCarros].modelo[ln] = '\0';
      fflush(stdin);

      while(valido == 0)
      {
        printf("\nDigite a placa do carro:\n>>");
        fgets(placa, 8, stdin);
        ln = strlen(placa) - 1;
        if (placa[ln] == '\n')
            placa[ln] = '\0';
        fflush(stdin);

        if (checarPlaca(placa) == 1)
        {
          printf("\nPlaca ja cadastrada!\n");
          continue;
        }
        else
        {
          strcpy(registro[qtdeCarros].placa, placa);
          valido = 1;
        }
      }
      
      printf("\nDigite a cor do carro:\n>>");
      fgets(registro[qtdeCarros].cor, 10, stdin);
      ln = strlen(registro[qtdeCarros].cor) - 1;
      if (registro[qtdeCarros].cor[ln] == '\n')
          registro[qtdeCarros].cor[ln] = '\0';
      fflush(stdin);

      printf("\nDigite o ano do carro:\n>>");
      scanf("%d", &registro[qtdeCarros].ano);

      printf("\nDigite a potencia do carro:\n>>");
      scanf("%d", &registro[qtdeCarros].potencia);

      registro[qtdeCarros].ativo = 'A';//Ativo
      qtdeCarros++;//Próximo Carro

      printf("Cadastrado com sucesso!\n");

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
  if (qtdeCarros == 0)
  {
    printf("Nenhum carro cadastrado!\n");
    return;
  }
  for(int i = 0; i < 100; i++)
    {
      if (registro[i].ativo == 'A')
      {
         printf("======================\n");
      
        printf("Marca: %s\n", registro[i].marca);
    
        printf("Modelo: %s\n", registro[i].modelo);
    
        printf("Placa: %s\n", registro[i].placa);
    
        printf("Cor: %s\n", registro[i].cor);
    
        printf("Ano: %d\n", registro[i].ano);

        printf("Potencia: %d\n", registro[i].potencia);

        printf("======================\n");
      }
    }
  return;
}

void atualizar(char placa[])
{
  int posicaoIndice, escolhaAtt, pararAtt;
  escolhaAtt = pararAtt = 0;

  posicaoIndice = encontrarIndice(placa);

  if (posicaoIndice != PLACA_NAO_ENCONTRADA)
  {
    do{
      printf("O que deseja atualizar?\n1 - Marca\n2 - Modelo\n3 - Placa\n4 - Cor\n5 - Ano\n6 - Potencia\n7 - Cancelar\n>>");
      scanf("%d", &escolhaAtt);

      switch(escolhaAtt)
      {
        case 1:
        {
          fflush(stdin);
          printf("Digite a nova marca:\n>>");
          fgets(registro[posicaoIndice].marca, 20, stdin);
          size_t ln = strlen(registro[posicaoIndice].marca) - 1;
          if (registro[posicaoIndice].marca[ln] == '\n')
            registro[posicaoIndice].marca[ln] = '\0';
          fflush(stdin);
          break;
        }
        case 2: 
        {
          fflush(stdin);
          printf("Digite o novo modelo:\n>>");
          fgets(registro[posicaoIndice].modelo, 20, stdin);
          size_t ln = strlen(registro[posicaoIndice].modelo) - 1;
          if (registro[posicaoIndice].modelo[ln] == '\n')
            registro[posicaoIndice].modelo[ln] = '\0';
          fflush(stdin);
          break;
        }
        case 3:
        {
          fflush(stdin);
          int valido = 0;
          char placa[8];

          while(valido == 0)
        {
          printf("Digite a nova placa:\n>>");
          fgets(placa, 8, stdin);
          size_t ln = strlen(placa) - 1;
          if (placa[ln] == '\n')
              placa[ln] = '\0';
          fflush(stdin);

          if (checarPlaca(placa) == 1)
          {
            printf("\nPlaca ja cadastrada!\n");
            continue;
          }
          else
          {
            strcpy(registro[posicaoIndice].placa, placa);
            valido = 1;
          }
        }
          break;
        }
        case 4:
        {
          fflush(stdin);
          printf("Digite a nova cor:\n>>");
          fgets(registro[posicaoIndice].cor, 20, stdin);
          size_t ln = strlen(registro[posicaoIndice].cor) - 1;
          if (registro[posicaoIndice].cor[ln] == '\n')
            registro[posicaoIndice].cor[ln] = '\0';
          fflush(stdin);
          break;
        }
        case 5:
        {
          printf("Digite o novo ano:\n>>");
          scanf("%d", &registro[posicaoIndice].ano);
          break;
        }
        case 6:
        {
          printf("Digite a nova potencia:\n>>");
          scanf("%d", &registro[posicaoIndice].potencia);
          break;
        }
        case 7:
        {
          break;
        }
        default:
        {
          printf("Opcao invalida!\n");
          break;
        }
      }
      printf("Atualizado com sucesso!\n");

      printf("Deseja atualizar mais alguma coisa?\n0 - Sim\n1 - Nao\n>>");
      scanf("%d", &pararAtt);
      if(pararAtt == 2)
      {
        pararAtt = 1;
      }
    }while (pararAtt != 1);
  }
  else
  {
    printf("Placa nao encontrada!\n");
  }
  return;
}

void deletar(void)
{
  char placaDel[8];
  int posicaoIndice;
  fflush(stdin);
  printf("Digite a placa do carro que deseja deletar:\n>>");
  fgets(placaDel, 8, stdin);
  size_t ln = strlen(placaDel) - 1;
  if (placaDel[ln] == '\n')
      placaDel[ln] = '\0';
  fflush(stdin);

  posicaoIndice = encontrarIndice(placaDel);

  if (posicaoIndice != PLACA_NAO_ENCONTRADA)
  {
    registro[posicaoIndice].ativo = 'D';
    printf("Deletado com sucesso!\n");
    qtdeCarros--;
  }
  else
  {
    printf("Placa nao encontrada!\n");
  }
  return;
}

int encontrarIndice(char placa[])
{
  for (int i = 0; i < qtdeCarros; i++)
  {
    if (registro[i].ativo == 'A')
    {
      if (strcmp(registro[i].placa, placa) == 0)
      {
        return i;
      }
    }
  }
  return PLACA_NAO_ENCONTRADA;
}

int checarPlaca(char placa[])
{
  for (int i = 0; i < qtdeCarros; i++)
  {
    if (registro[i].ativo == 'A')
    {
      if (strcmp(registro[i].placa, placa) == 0)
      {
        return 1;
      }
    }
  }
  return 0;
}

#endif // function_h