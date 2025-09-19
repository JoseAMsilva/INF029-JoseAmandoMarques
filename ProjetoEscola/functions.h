#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifndef functions
#define functions

#define true 1
#define false 0
#define tam_Aluno 3

void linhas()
{
    printf("----------------------------------\n");
}

int escolhaMain()
{
    int opcao;
    printf("0 - Sair\n");
    printf("1 - Alunos\n");
    printf("2 - Professores\n");
    printf("3 - Disciplinas\n");
    scanf("%d", &opcao);
    return opcao;
}

/// Printar Escolha módulo aluno 
int moduloAluno(void)
{
    int listaAlunos[tam_Aluno];
    int opcaoAluno;
    linhas();
    printf("Modulo Aluno\n");
    linhas();

    int sairAluno = false;
    while (!sairAluno)
    {
        printf("0 - Voltar\n");
        printf("1 - Cadastrar Aluno\n");
        printf("2 - Listar Alunos\n");
        printf("3 - Atualizar Aluno\n");
        printf("4 - Excluir Aluno\n");
        scanf("%d", &opcaoAluno);

        switch (opcaoAluno)
        {
            case 0:
            {
                sairAluno = true;
                break;
            }
            case 1:
            {
                linhas();
                printf("Cadastrar Aluno\n");
                linhas();

                int matricula;
                int qtdeAlunos = 0;
                printf("Digite a matricula do aluno: ");
                scanf("%d", &matricula);

                if (matricula < 0)
                {
                    printf("Matricula invalida\n");
                    break;
                }
                else
                {
                    if (qtdeAlunos >= tam_Aluno)
                    {
                        printf("Lista cheia\n");
                        break;
                    }
                    for (int i = 0; i < tam_Aluno; i++)
                    {
                        if (listaAlunos[i] == matricula)
                        {
                            printf("ERRO! Matricula %d ja cadastrada\n", matricula);
                            break;
                        }
                        else
                        {
                            listaAlunos[qtdeAlunos] = matricula;
                            qtdeAlunos++;
                            linhas();
                            printf("Aluno de matricula %d cadastrado com sucesso\n", matricula);
                            linhas();
                            break;
                        }
                    }
                }
                break;
            }
            case 2:
            {
                printf("Listar Alunos\n");
                break;
            }
            case 3:
            {
                printf("Atualizar Aluno\n");
                break;
            }
            case 4:
            {
                printf("Excluir Aluno\n");
                break;
            }
            default:
            {
                printf("Opcao invalida\n");
                break;
            }
        }
    }
    return sairAluno;
}
/// print Inicial
void bem_Vindos()
{
    linhas();
    printf("Bem vindo ao projeto escola\n");
    linhas();
    printf("Escolha qual modulo\n");
}

/// print fim do programa
void fim_Programa()
{
    linhas();
    printf("Fim do programa\n");
    linhas();
}

#endif // FUNCTIONS