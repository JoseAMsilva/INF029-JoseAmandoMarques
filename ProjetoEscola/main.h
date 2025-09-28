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
    char cpf[15];
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
//Atributos: nome, código, semestre, professor, alunos matriculados e número de alunos
//
typedef struct Disciplina
{
    char nome[20];
    char codigo[10];
    int semestre;
    int numAlunos;//Número de alunos matriculados na disciplina
    pessoa professor;
    pessoa alunos[50];//Vetor para armazenar até 50 alunos
    
}disciplina;
//
//Variáveis globais
//
int matriculaGlobal = 1;//Variável global para gerar matrículas únicas
int numDisciplinas = 0;//Número de disciplinas cadastradas
disciplina disciplinas[20];//Vetor para armazenar até 20 disciplinas
pessoa alunos[100];//Vetor para armazenar até 100 alunos
int numAlunos = 0;//Número de alunos cadastrados
pessoa professores[50];//Vetor para armazenar até 50 professores
int numProfessores = 0;//Número de professores cadastrados
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
int validarCPF(char cpf[]);//Função para validar o CPF
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
        flush_in();//Limpa o buffer do teclado removendo o '\n' que fica após o scanf

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
    //
    //Implementar menu professor
    //
}
void menuDisciplina()
{
    printf("Menu Disciplina\n");
    //
    //Implementar menu disciplina
    //
}

int cadastrarAluno(pessoa *novoAluno)
{
    cadastrarNome(novoAluno);
    cadastrarSexo(novoAluno);
    novoAluno->funcao = 'A';//Define a função como aluno
    cadastrarCPF(novoAluno);
    cadastrarData(novoAluno);
    cadastraMatricula(novoAluno);
    alunos[numAlunos] = *novoAluno;//Adiciona o novo aluno ao vetor de alunos
    numAlunos++;//Incrementa o número de alunos cadastrados
    return true;
}
//
//Função para cadastrar o nome
//
void cadastrarNome(pessoa *entrada)
{
    char nome[40];
    int valido = false;

    while (!valido)
    {
        printf("Digite o nome\n>>");
        fgets(nome, 40, stdin);
        fflush(stdin);
        nome[strcspn(nome, "\n")] = '\0';//Remove o '\n' do final da string, se houver

        valido = validarNome(nome);//Chama a função para validar o nome retornando true ou false
    }

    if (valido)
    {
        //Transformar a primeira letra de cada palavra em maiúscula
        int i = 0;
        
        while (nome[i] != '\0')
        {
            if (i == 0 || nome[i - 1] == ' ')
            {
                nome[i] = toupper(nome[i]);
            }
            i++;
        }
    }

    strcpy(entrada->nome, nome);//Copia o nome validado para a estrutura
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
        if (nome[i] >= 'a' && nome[i] <= 'z' || nome[i] == ' ' || nome[i] >= 'A' && nome[i] <= 'Z')
        {
            i++;
        }
        else
        {
            printf("Erro---Nome invalido, nao adicone numeros, acentos ou aracteres especiais\n");
            return false;
        } 
    }
    if (strlen(nome) > 40)
    {
        printf("Erro---Nome muito grande\n");
        return false;
    }
    else if (strlen(nome) < 4)
    {
        printf("Erro---Nome muito pequeno\n");
        return false;
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
        flush_in();//Limpa o buffer do teclado removendo o '\n' que fica após o scanf
        sexo = toupper(sexo);//Converte para maiúsculo

        if (sexo == 'M' || sexo == 'F' || sexo == 'O')//M- Masculino, F- Feminino, O- Outro
        {
            valido = true;
        }
        else
        {
            printf("Erro---Sexo invalido. Digite M para Masculino, F para Feminino ou O para Outro.\n");
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
    char cpf[15];
    int valido = false;
    int i, cont;
    i = cont = 0;

    //int retorno;
    while (!valido)
    {
        printf("Insira o CPF\n>>");
        fgets(cpf, 15, stdin);
        fflush(stdin);
        cpf[strcspn(cpf, "\n")] = '\0';//Remove o '\n' do final da string, se houver
        valido = validarCPF(cpf);//Chama a função para validar o CPF retornando true ou false
    }

    while(cpf[i] != '\0')
    {
        if (cpf[i] == '.' || cpf[i] == '-')
        {
            cont++;
        }
        i++;
    }

    if (cont == 0)
    {
        sprintf(cpf, "%c%c%c.%c%c%c.%c%c%c-%c%c",
        cpf[0], cpf[1], cpf[2],
        cpf[3], cpf[4], cpf[5],
        cpf[6], cpf[7], cpf[8],
        cpf[9], cpf[10]);
    }
    strcpy(entrada->cpf, cpf);//Copia o CPF validado para a estrutura
    printf("O CPF %s foi cadastrado com sucesso\n", entrada->cpf);//Teste
}
//
//Função para validar CPF
//
int validarCPF(char cpf[])
{
    char digitos[11];
    int contaDigitos = 0;
    int contaPontos = 0;
    int contaHifen = 0;
    char dig1, dig2, dig3, dig4, dig5, dig6, dig7, dig8, dig9, dig10, dig11;
    int i = 0;

    while (cpf[i] != '\0')
    {
        if (cpf[i] >= '0' && cpf[i] <= '9')
        {
            contaDigitos++;
            digitos[contaDigitos - 1] = cpf[i];
            i++;
        }
        else if (cpf[i] == '.')//Ignora pontos e hífen
        {
            contaPontos++;
            i++;
        }
        else if (cpf[i] == '-')//Ignora pontos e hífen
        {
            contaHifen++;
            i++;
        }
    }

    if (contaDigitos != 11 || contaPontos > 2 || contaHifen > 1)
    {
        printf("Erro---CPF invalido numero de digitos\n");
        return false;
    }

    //Atribui os dígitos às variáveis correspondentes
        dig1 = digitos[0];
        dig2 = digitos[1];
        dig3 = digitos[2];
        dig4 = digitos[3];
        dig5 = digitos[4];
        dig6 = digitos[5];
        dig7 = digitos[6];
        dig8 = digitos[7];
        dig9 = digitos[8];
        dig10 = digitos[9];
        dig11 = digitos[10];

        //Verifica se todos os dígitos são iguais
        if (dig1 == dig2 && dig2 == dig3 && dig3 == dig4 && dig4 == dig5 && dig5 == dig6 && dig6 == dig7 && dig7 == dig8 && dig8 == dig9 && dig9 == dig10 && dig10 == dig11)
        {
            printf("Erro---CPF invalido numeros iguais\n");
            return false;
        }
        //Cálculo do primeiro dígito verificador
        int soma1 = (dig1 - '0') * 10 + (dig2 - '0') * 9 + (dig3 - '0') * 8 + (dig4 - '0') * 7 + (dig5 - '0') * 6 + (dig6 - '0') * 5 + (dig7 - '0') * 4 + (dig8 - '0') * 3 + (dig9 - '0') * 2;

        int resto = soma1 * 10 % 11;//Cálculo do resto da divisão por 11

        if (resto == 10)
        {
            resto = 0;
        }

        //Cálculo do segundo dígito verificador
        int soma2 = (dig1 - '0') * 11 + (dig2 - '0') * 10 + (dig3 - '0') * 9 + (dig4 - '0') * 8 + (dig5 - '0') * 7 + (dig6 - '0') * 6 + (dig7 - '0') * 5 + (dig8 - '0') * 4 + (dig9 - '0') * 3 + (resto) * 2;
        //Cálculo do resto da divisão por 11
        int resto2 = soma2 * 10 % 11;

        if (resto2 == 10)
        {
            resto2 = 0;
        }

        //Verifica se os dígitos verificadores calculados são iguais aos dígitos informados
        if (resto != (dig10 - '0') || resto2 != (dig11 - '0'))
        {
            printf("Erro---CPF invalido\n");
            return false;
        }
    return true;
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
    matriculaGlobal++;//Incrementa a variável global para gerar uma nova matrícula
    entrada->matricula = matriculaGlobal;//Define a matrícula como a variável global
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