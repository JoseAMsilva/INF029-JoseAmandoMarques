//
// Prjeto Escola criado para a matéria Laboratório de programação INF029 sob tutoria do professor Renato Novaes
//Integrantes: José Amando Marques, Lorena Duarte e Lucas Costa
//
#include "main.h"//Inclusão do arquivo de cabeçalho

int main()
{
    int sair = false;
    int menuAtual = 0;

    while (!sair)
    {
        switch (menuAtual)
        {
            case 0:
            {
                menuAtual = menuPrincipal();
                break;
            }
            case 1:
            {
                menuAtual = menuAluno();
                break;
            }  
            case 2:
            {
                menuAtual = menuProfessor();
                break;
            }
            case 3:
            {
                menuAtual = menuDisciplina();
                break;
            }
            case 4:
            {
                menuAtual = menuRelatorios();
                break;
            }
            case 5:
            {
                printf("Buscas ainda não implementadas...\n");
                menuAtual = 0;
                break;
            }
            case 6:
            {
                printf("Saindo...\n");
                sair = true;
                break;
            }

            default:
            {
                printf("Opção inválida\n");
                break;
            }
        }
    }
    printf("Fim do programa\n");
    system("pause");
}