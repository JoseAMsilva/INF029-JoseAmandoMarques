#ifndef MAIN_H//ifndef para evitar inclusões múltiplas
#define MAIN_H//define para evitar inclusões múltiplas
//
//Projeto Escola
//Inclusão de bibliotecas
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//
//Constantes
//
#define invalido -1
#define true 1
#define false 0
//
//Estrutura para pessoa
//A mesma estrutura serve para aluno e professor
//Atributos: matrícula, nome, sexo, CPF, data de nascimento e função
//Função: A- Aluno, P- Professor
//
typedef struct Pessoa
{
    int matricula;
    char nome[20];
    char sexo;
    char cpf[11];
    char funcao;//A- Aluno, P- Professor
    struct data
    {
        int dia;
        int mes;
        int ano;
    }dataNasc;
    
}pessoa;
//
//Estrutura para disciplina
//Atributos: nome, código, semestre e professor
//
typedef struct Disciplina
{
    char nome[20];
    char codigo[10];
    int semestre;
    pessoa professor;
    
}disciplina;
//
//Protótipos
//
int menuPrincipal();//Função do menu principal
int menuAluno();//Função do menu aluno
void menuProfessor();//Função do menu professor
void menuDisciplina();//Função do menu disciplina
int cadastrarAluno(pessoa *aluno);//Função para cadastrar aluno
void cadastrarNome(pessoa *entrada);//Função para cadastrar o nome
int validarNome(char nome[]);//Função para validar o nome
void cadastrarSexo(pessoa *entrada);//Função para cadastrar o sexo
void cadastrarCPF(pessoa *entrada);//Função para cadastrar o CPF
void cadastrarData(pessoa *entrada);//Função para cadastrar a data de nascimento
void cadastraMatricula(pessoa *entrada);//Função para cadastrar a matrícula
void flush_in();//Função para limpar o buffer do teclado
//
//Menu principal
//
int menuPrincipal()
{
    int escolhaMain;
    printf("ESCOLHA UMA OPCAO:\n1- Alunos\n2- Professores\n3- Disciplinas\n4- Sair\n>>");
    scanf("%d", &escolhaMain);
    flush_in();
    if (escolhaMain >= 1 && escolhaMain <= 4)
    {
        return escolhaMain;
    }
    else
    {
        return invalido;
    }
}
//
//Menu aluno
// 
int menuAluno()
{
    int escolhaAluno;
    int voltar = false;
    while (!voltar)
    {
        printf("ESCOLHA UMA OPCAO:\n1- Cadastrar\n2- Listar\n3- Alterar\n4- Excluir\n5- Voltar\n>>");
        scanf("%d", &escolhaAluno);
        flush_in();

        if (escolhaAluno >= 1 && escolhaAluno <= 5)
        {
            switch (escolhaAluno)
            {
                pessoa aluno;
                case 1:
                {
                    int retorno = cadastrarAluno(&aluno);
                    if (retorno)
                    {
                        printf("Aluno cadastrado com sucesso\n");
                    }

                    break;
                }
                case 2:
                {
                    printf("Listar\n");
                    break;
                }
                case 3:
                {
                    printf("Alterar\n");
                    break;
                }
                case 4:
                {
                    printf("Excluir\n");
                    break;
                }
                case 5:
                {
                    printf("Voltando...\n");
                    voltar = true;
                    break;
                }
            }
        }
    }
    return 0;
}
//
//Menu professor
//
void menuProfessor()
{
    printf("Menu Professor\n");
}
void menuDisciplina()
{
    printf("Menu Disciplina\n");
}

int cadastrarAluno(pessoa *novoAluno)
{
    cadastrarNome(novoAluno);
    cadastrarSexo(novoAluno);
    novoAluno->funcao = 'A';//Define a função como aluno
    cadastrarCPF(novoAluno);
    cadastrarData(novoAluno);
    cadastraMatricula(novoAluno);
    return true;
}
//
//Função para cadastrar o nome
//
void cadastrarNome(pessoa *entrada)
{
    int retorno;
    char nome[40];
    int valido = false;

    while (!valido)
    {
        printf("Digite o nome\n>>");
        fgets(nome, 40, stdin);
        fflush(stdin);
        nome[strcspn(nome, "\n")] = '\0';

        retorno = validarNome(nome);
        
        if (retorno)
        {
            valido = true;
        }
    }

    strcpy(entrada->nome, nome);
    printf("O nome %s foi cadastrado com sucesso\n", entrada->nome);//Teste para ver se o nome foi cadastrado corretamente
}
//
//Função para validar o nome
//
int validarNome(char nome[])
{
    int i = 0;
    while (nome[i] != '\0')
    {
        if (nome[i] >= 'a' && nome[i] <= 'z')
        {
            i++;
        }
        else
        {
            return invalido;
        } 
    }
    if (strlen(nome) > 40)
    {
        printf("Erro---Nome muito grande\n");
        return invalido;
    }
    else if (strlen(nome) < 3)
    {
        printf("Erro---Nome muito pequeno\n");
        return invalido;
    }
    else
    {
        return true;
    }
}
//
//Função para cadastrar o sexo
//
void cadastrarSexo(pessoa *entrada)
{
    char sexo;
    int valido = false;
    while (!valido)
    {
        printf("Digite o sexo\n>>");
        scanf("%c", &sexo);
        flush_in();
        sexo = toupper(sexo);//Converte para maiúsculo

        if (sexo == 'M' || sexo == 'F' || sexo == 'O')
        {
            valido = true;
        }
        else
        {
            printf("Sexo inválido. Digite M, F ou O.\n");
        }
    }
    entrada->sexo = sexo;
    printf("O sexo %c foi cadastrado com sucesso\n", entrada->sexo);//Teste para ver se o sexo foi cadastrado corretamente
}
//
//Função para cadastrar CPF
//
void cadastrarCPF(pessoa *entrada)
{
    printf("Cadastrando CPF...\n");
    //
    //Implementar função para cadastrar CPF
    //
}
//
//Função para cadastrar data
//
void cadastrarData(pessoa *entrada)
{
    printf("Cadastrando data...\n");
    //
    //Implementar função para cadastrar data
    //
}
//
//Função para cadastrar matrícula
//
void cadastraMatricula(pessoa *entrada)
{
    printf("Cadastrando matrícula...\n");
    //
    //Implementar função para cadastrar matricula
    //
}
//
//Função para limpar o buffer do teclado
//
void flush_in() {
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}

#endif//MAIN_H