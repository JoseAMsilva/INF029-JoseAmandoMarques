//
// Prjeto Escola criado para a matéria Laboratório de programação INF029 sob tutoria do professor Renato Novaes
//Integrantes: José Amando Marques, Lorena Duarte e Lucas Costa
//
#include "main.h"//Inclusão do arquivo de cabeçalho

int main()
{
    //dados para testes
    strcpy(alunos[0].nome, "Jose Amando Marques");
    strcpy(alunos[0].cpf, "789.853.354-14");
    alunos[0].sexo = 'M';
    alunos[0].dataNasc.dia = 15;
    alunos[0].dataNasc.mes = 6;
    alunos[0].dataNasc.ano = 2000;
    alunos[0].idade = 24;
    alunos[0].matricula = matriculaGlobal+1;
    alunos[0].funcao = 'A';
    alunos[0].situacao = 'A';
    numAlunos++;
    matriculaGlobal++;

    strcpy(alunos[1].nome, "Lorena Duarte");
    strcpy(alunos[1].cpf, "687.021.432-00");
    alunos[1].sexo = 'F';
    alunos[1].dataNasc.dia = 22;
    alunos[1].dataNasc.mes = 11;
    alunos[1].dataNasc.ano = 1999;
    alunos[1].idade = 24;
    alunos[1].matricula = matriculaGlobal+1;
    alunos[1].funcao = 'A';
    alunos[1].situacao = 'A';
    numAlunos++;
    matriculaGlobal++;

    strcpy(professores[0].nome, "Lucas Costa");
    strcpy(professores[0].cpf, "415.357.108-36");
    professores[0].sexo = 'M';
    professores[0].dataNasc.dia = 5;
    professores[0].dataNasc.mes = 3;
    professores[0].dataNasc.ano = 1990;
    professores[0].idade = 34;
    professores[0].matricula = matriculaGlobal+1;
    professores[0].funcao = 'P';
    professores[0].situacao = 'A';
    numProfessores++;
    matriculaGlobal++;

    strcpy(professores[1].nome, "Ana Silva");
    strcpy(professores[1].cpf, "226.464.135-54");
    professores[1].sexo = 'F';
    professores[1].dataNasc.dia = 15;
    professores[1].dataNasc.mes = 8;
    professores[1].dataNasc.ano = 1985;
    professores[1].idade = 38;
    professores[1].matricula = matriculaGlobal+1;
    professores[1].funcao = 'P';
    professores[1].situacao = 'A';
    numProfessores++;
    matriculaGlobal++;

    strcpy(alunos[2].nome, "Carlos Eduardo");
    strcpy(alunos[2].cpf, "215.967.346-15");
    alunos[2].sexo = 'M';
    alunos[2].dataNasc.dia = 10;
    alunos[2].dataNasc.mes = 12;
    alunos[2].dataNasc.ano = 2001;
    alunos[2].idade = 23;
    alunos[2].matricula = matriculaGlobal+1;
    alunos[2].funcao = 'A';
    alunos[2].situacao = 'A';
    numAlunos++;
    matriculaGlobal++;

    strcpy(alunos[3].nome, "Mariana Souza");
    strcpy(alunos[3].cpf, "377.942.125-01");
    alunos[3].sexo = 'F';
    alunos[3].dataNasc.dia = 25;
    alunos[3].dataNasc.mes = 7;
    alunos[3].dataNasc.ano = 2002;
    alunos[3].idade = 22;
    alunos[3].matricula = matriculaGlobal+1;
    alunos[3].funcao = 'A';
    alunos[3].situacao = 'A';
    numAlunos++;
    matriculaGlobal++;

    strcpy(professores[2].nome, "Roberto Lima");
    strcpy(professores[2].cpf, "157.789.165-23");
    professores[2].sexo = 'M';
    professores[2].dataNasc.dia = 30;
    professores[2].dataNasc.mes = 1;
    professores[2].dataNasc.ano = 1975;
    professores[2].idade = 48;
    professores[2].matricula = matriculaGlobal+1;
    professores[2].funcao = 'P';
    professores[2].situacao = 'A';
    numProfessores++;
    matriculaGlobal++;

    //fim dos dados para testes

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
                
                menuAtual = buscarPessoas();
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
    return 0; 
}