// Prjeto escola criado para a matéria Laboratório de programação INF029 do curso de ADS sob tutoria do professor Renato Novaes; Pariticipantes: José Amando Marques, Lorena Duarte e Lucas Costa

#include "functions.h"

int main()
{
    int sair = false;
    int listaAlunos[tam_Aluno];
    bem_Vindos();

    while (!sair)
    {
        int opcaoMain = escolhaMain();

        switch (opcaoMain)
        {
            case 0:
            {
                sair = true;
                break;
            }
            case 1:
            {
                int sairAluno = false;

                sairAluno = moduloAluno();
                
                if (sairAluno)
                    break;
            }
            case 2:
            {
                printf("Professores\n");
                break;
            }
            case 3:
            {
                printf("Disciplinas\n");
                break;
            }
            default:
            {
                printf("Opcao invalida\n");
                break;
            }
        }
    }
    fim_Programa();
    system("pause");
}