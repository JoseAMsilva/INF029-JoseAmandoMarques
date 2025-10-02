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
    char nome[40];
    char sexo;
    int idade;
    char cpf[15];
    char funcao;//A- Aluno, P- Professor
    char situacao; //A- Ativo, I- Inativo
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
int matriculaGlobal = 0;//Variável global para gerar matrículas únicas
int numDisciplinas = 0;//Número de disciplinas cadastradas
disciplina disciplinas[20];//Vetor para armazenar até 20 disciplinas
pessoa aluno;//Estrutura para aluno
pessoa alunos[100];//Vetor para armazenar até 100 alunos
int numAlunos = 0;//Número de alunos cadastrados
pessoa professores[50];//Vetor para armazenar até 50 professores
pessoa professor;//Estrutura para professor
int numProfessores = 0;//Número de professores cadastrados
//
//Protótipos
//
int menuPrincipal();//Função do menu principal
int menuAluno();//Função do menu aluno
int menuProfessor();//Função do menu professor
int menuDisciplina();//Função do menu disciplina
void cadastrarDisciplina();//Função para cadastrar disciplina
void listarDisciplinas();//Função para listar disciplinas
void alterarAlunoDisciplina();//Função para alterar aluno em disciplina
int menuRelatorios();//Função do menu relatorios
int cadastrarAluno(pessoa *aluno);//Função para cadastrar aluno
void listarAlunos();//Função para listar alunos
void listarAlunosPorSexo();//Função para listar alunos por sexo
void listarAlunosOrdemAlfabetica();//Função para listar alunos em ordem alfabética
void ordenarAlunosPorDataNascimento();//Função para ordenar alunos por data de nascimento
int cadastrarProfessor(pessoa *professor);//Função para cadastrar professor
void listarProfessores();//Função para listar professores
void listarProfessoresPorSexo();//Função para listar professores por sexo
void listarProfessoresOrdemAlfabetica();//Função para listar professores em ordem alfabética
void ordenarProfessoresPorDataNascimento();//Função para ordenar professores por data de nascimento
void listarAniversariantesDoMes();//Função para listar aniversariantes do mês
void listarAlunosPorSexo();//Função para listar alunos por sexo
void listarAlunosOrdemAlfabetica();//Função para listar alunos em ordem alfabética
void ordenarAlunosPorDataNascimento();//Função para ordenar alunos por data de nascimento
int cadastrarProfessor(pessoa *professor);//Função para cadastrar professor
void listarProfessores();//Função para listar professores
void listarProfessoresPorSexo();//Função para listar professores por sexo
void listarProfessoresOrdemAlfabetica();//Função para listar professores em ordem alfabética
void ordenarProfessoresPorDataNascimento();//Função para ordenar professores por data de nascimento
void listarAniversariantesDoMes();//Função para listar aniversariantes do mês
void alterarPessoa(pessoa *entrada);//Função para alterar aluno
void excluirPessoa(pessoa *entrada);//Função para excluir aluno
void cadastrarNome(pessoa *entrada);//Função para cadastrar o nome
void nomeDisciplina(disciplina *entrada);//Função para cadastrar o nome da disciplina
void codigoDisciplina(disciplina *entrada);//Função para cadastrar o código da disciplina
int validarNome(char nome[]);//Função para validar o nome
void cadastrarSexo(pessoa *entrada);//Função para cadastrar o sexo
void cadastrarCPF(pessoa *entrada);//Função para cadastrar o CPF
int validarCPF(char cpf[]);//Função para validar o CPF
void cadastrarData(pessoa *entrada);//Função para cadastrar a data de nascimento
int buscarPessoas();//Função para buscar pessoas
int buscarPessoas();//Função para buscar pessoas
void cadastraMatricula(pessoa *entrada);//Função para cadastrar a matrícula
void flush_in();//Função para limpar o buffer do teclado
//
//Menu principal
//
int menuPrincipal()
{
    int escolhaMain;
    printf("MENU PRINCIPAL:\n1- Alunos\n2- Professores\n3- Disciplinas\n4- Relatorios\n5- Busca\n6- Sair\n>>");
    printf("MENU PRINCIPAL:\n1- Alunos\n2- Professores\n3- Disciplinas\n4- Relatorios\n5- Busca\n6- Sair\n>>");
    scanf("%d", &escolhaMain);
    flush_in();
    if (escolhaMain >= 1 && escolhaMain <= 6)
    if (escolhaMain >= 1 && escolhaMain <= 6)
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
        printf("MENU ALUNOS:\n1- Cadastrar\n2- Listar\n3- Alterar\n4- Excluir\n5- Voltar\n>>");
        scanf("%d", &escolhaAluno);
        flush_in();//Limpa o buffer do teclado removendo o '\n' que fica após o scanf

        if (escolhaAluno >= 1 && escolhaAluno <= 5)
        {
            switch (escolhaAluno)
            {
                aluno.funcao = 'A';//Define a função como aluno
                aluno.funcao = 'A';//Define a função como aluno
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
                    listarAlunos();
                    break;
                }
                case 3:
                {
                    alterarPessoa(&aluno);
                    break;
                }
                case 4:
                {
                    excluirPessoa(&aluno);
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
int menuProfessor()
{
    int voltar = false;
    int escolhaProfessor;
    while (!voltar)
    {
        printf("MENU PROFESSORES:\n1- Cadastrar\n2- Listar\n3- Alterar\n4- Excluir\n5- Voltar\n>>");
        scanf("%d", &escolhaProfessor);
        flush_in();//Limpa o buffer do teclado removendo o '\n' que fica após o scanf

        if (escolhaProfessor >= 1 && escolhaProfessor <= 5)
        {
            professor.funcao = 'P';//Define a função como professor
            switch (escolhaProfessor)
            {
                case 1:
                {
                    int retorno = cadastrarProfessor(&professor);
                    if (retorno)
                    {
                        printf("Professor cadastrado com sucesso\n");
                    }
                    break;
                }
                case 2:
                {
                    listarProfessores();
                    break;
                }
                case 3:
                {
                    alterarPessoa(&professor);
                    break;
                }
                case 4:
                {
                    excluirPessoa(&professor);
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
int menuDisciplina()
{
    int escolhaDisciplina;
    int voltar = false;
    while (!voltar)
    {
        printf("MENU DISCIPLINA:\n1- Cadastrar\n2- Listar\n3- Alterar aluno \n4- Excluir\n5- Voltar\n>>");
        scanf("%d", &escolhaDisciplina);
        flush_in();//Limpa o buffer do teclado removendo o '\n' que fica após o scanf


     if (escolhaDisciplina >= 1 && escolhaDisciplina <= 5)
        {
            switch (escolhaDisciplina)
            {
                disciplina novaDisciplina;
                case 1:
                {
                    cadastrarDisciplina(&novaDisciplina);
                    break;
                }

                case 2:
                {
                    listarDisciplinas();
                    break;
                }

                case 3:
                {
                    alterarAlunoDisciplina();
                    break;
                }
                case 4:
                {
                    printf("Funcao nao implementada ainda\n");
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
//Menu relatórios
//
int menuRelatorios()
{
    int escolhaRelatorios;
    int voltar = false;

    while (!voltar)
    {
        printf("MENU RELATORIOS\n1- Listar Alunos por Sexo\n2- Listar Alunos em ordem alfabetica\n3- Ordenar Alunos por data de nascimento\n4- Listar Professores por Sexo\n5- Listar Professores em ordem alfabetica\n6- Ordenar Professores por data de nascimento\n7- Aniversariantes do mes\n8- Voltar\n>>");
        scanf("%d", &escolhaRelatorios);
        flush_in();//Limpa o buffer do teclado removendo o '\n' que fica após
        if (escolhaRelatorios >= 1 && escolhaRelatorios <= 8)
        {
            switch (escolhaRelatorios)
            {
                case 1:
                {
                    if (numAlunos == 0)
                    {
                        printf("Nenhum aluno cadastrado.\n");
                        break;
                    }
                    listarAlunosPorSexo();
                    break;
                }
                case 2:
                {
                    if (numAlunos == 0)
                    {
                        printf("Nenhum aluno cadastrado.\n");
                        break;
                    }
                    listarAlunosOrdemAlfabetica();
                    break;
                }
                case 3:
                {
                    if (numAlunos == 0)
                    {
                        printf("Nenhum aluno cadastrado.\n");
                        break;
                    }
                    ordenarAlunosPorDataNascimento();
                    break;
                }
                case 4:
                {
                    if (numProfessores == 0)
                    {
                        printf("Nenhum professor cadastrado.\n");
                        break;
                    }
                    listarProfessoresPorSexo();
                    break;
                }
                case 5:
                {
                    if (numProfessores == 0)
                    {
                        printf("Nenhum professor cadastrado.\n");
                        break;
                    }
                    listarProfessoresOrdemAlfabetica();
                    break;
                }
                case 6:
                {
                    if (numProfessores == 0)
                    {
                        printf("Nenhum professor cadastrado.\n");
                        break;
                    }
                    ordenarProfessoresPorDataNascimento();
                    break;
                }
                case 7:
                {
                    if (numProfessores == 0 && numAlunos == 0)
                    {
                        printf("Nenhuma pessoa cadastrada.\n");
                        break;
                    }
                    listarAniversariantesDoMes();
                    break;
                }
                case 8:
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
//Função para cadastrar aluno
//
int cadastrarAluno(pessoa *novoAluno)
{
    cadastrarNome(novoAluno);
    cadastrarSexo(novoAluno);
    novoAluno->funcao = 'A';//Define a função como aluno
    cadastrarCPF(novoAluno);
    cadastrarData(novoAluno);
    cadastraMatricula(novoAluno);
    novoAluno->situacao = 'A';//Define a situação como ativa
    alunos[numAlunos] = *novoAluno;//Adiciona o novo aluno ao vetor de alunos

    numAlunos++;//Incrementa o número de alunos cadastrados
    return true;
}
//
//Função para listar alunos
//
void listarAlunos()
{
    if (numAlunos == 0)
    {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    printf("Lista de Alunos Cadastrados:\n");
    for (int i = 0; i < numAlunos; i++)
    {
        printf("Matricula: %d\n", alunos[i].matricula);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Sexo: %c\n", alunos[i].sexo);
        printf("CPF: %s\n", alunos[i].cpf);
        printf("Data de Nascimento: %02d/%02d/%04d\n", alunos[i].dataNasc.dia, alunos[i].dataNasc.mes, alunos[i].dataNasc.ano);
        printf("Idade: %d\n", alunos[i].idade);
        printf("\n");
    }
}
//
//Função para listar alunos por sexo
//
void listarAlunosPorSexo()
{
    char sexo;
    int encontrado = false;
    printf("Digite o sexo dos alunos a serem listados (M/F/O)\n>>");
    scanf("%c", &sexo);
    flush_in();//Limpa o buffer do teclado removendo o '\n' que fica após o scanf
    sexo = toupper(sexo);//Converte para maiúsculo

    if (sexo != 'M' && sexo != 'F' && sexo != 'O')
    {
        printf("Erro---Sexo invalido. Digite M para Masculino, F para Feminino ou O para Outro.\n");
        return;
    }

    for (int i = 0; i < numAlunos; i++)
    {
        if (alunos[i].sexo == sexo)
        {
            printf("Matricula: %d\n", alunos[i].matricula);
            printf("Nome: %s\n", alunos[i].nome);
            printf("Sexo: %c\n", alunos[i].sexo);
            printf("CPF: %s\n", alunos[i].cpf);
            printf("Data de Nascimento: %02d/%02d/%04d\n",
            alunos[i].dataNasc.dia, alunos[i].dataNasc.mes, alunos[i].dataNasc.ano);
            printf("Idade: %d\n", alunos[i].idade);
            printf("\n");
            encontrado = true;
        }
    }
    if (!encontrado)
    {
        printf("Nenhum aluno cadastrado com o sexo %c.\n", sexo);
    }
    
    return;
}
//
//Função para listar alunos em ordem alfabética
//
void listarAlunosOrdemAlfabetica()
{
    //Cria um vetor temporário para ordenar os alunos
    pessoa alunosTemp[100];
    memcpy(alunosTemp, alunos, numAlunos * sizeof(pessoa));

    //Ordena o vetor temporário usando o algoritmo de bolha
    for (int i = 0; i < numAlunos - 1; i++)
    {
        for (int j = 0; j < numAlunos - i - 1; j++)
        {
            if (strcmp(alunosTemp[j].nome, alunosTemp[j + 1].nome) > 0)
            {
                pessoa temp = alunosTemp[j];
                alunosTemp[j] = alunosTemp[j + 1];
                alunosTemp[j + 1] = temp;
            }
        }
    }

    //Imprime a lista de alunos ordenada
    printf("Lista de Alunos em Ordem Alfabetica:\n");
    for (int i = 0; i < numAlunos; i++)
    {
        printf("Matricula: %d\n", alunosTemp[i].matricula);
        printf("Nome: %s\n", alunosTemp[i].nome);
        printf("Sexo: %c\n", alunosTemp[i].sexo);
        printf("CPF: %s\n", alunosTemp[i].cpf);
        printf("Data de Nascimento: %02d/%02d/%04d\n", alunosTemp[i].dataNasc.dia, alunosTemp[i].dataNasc.mes, alunosTemp[i].dataNasc.ano);
        printf("Idade: %d\n", alunosTemp[i].idade);
        printf("\n");
    }
}
//
//Função para ordenar alunos por data de nascimento
//
void ordenarAlunosPorDataNascimento()
{
    //Cria um vetor temporário para ordenar os alunos
    pessoa alunosTemp[100];
    memcpy(alunosTemp, alunos, numAlunos * sizeof(pessoa));

    //Ordena o vetor temporário usando o algoritmo de bolha
    for (int i = 0; i < numAlunos - 1; i++)
    {
        for (int j = 0; j < numAlunos - i - 1; j++)
        {
            if (alunosTemp[j].dataNasc.ano > alunosTemp[j + 1].dataNasc.ano)
            {
                pessoa temp = alunosTemp[j];
                alunosTemp[j] = alunosTemp[j + 1];
                alunosTemp[j + 1] = temp;
            }
            else if (alunosTemp[j].dataNasc.ano == alunosTemp[j + 1].dataNasc.ano)
            {
                if (alunosTemp[j].dataNasc.mes > alunosTemp[j + 1].dataNasc.mes)
                {
                    pessoa temp = alunosTemp[j];
                    alunosTemp[j] = alunosTemp[j + 1];
                    alunosTemp[j + 1] = temp;
                }
                else if (alunosTemp[j].dataNasc.mes == alunosTemp[j + 1].dataNasc.mes)
                {
                    if (alunosTemp[j].dataNasc.dia > alunosTemp[j + 1].dataNasc.dia)
                    {
                        pessoa temp = alunosTemp[j];
                        alunosTemp[j] = alunosTemp[j + 1];
                        alunosTemp[j + 1] = temp;
                    }
                }
            }
        }
    }
    //Imprime a lista de alunos ordenada por data de nascimento
    printf("Lista de Alunos em Ordem por Data de Nascimento:\n");
    for (int i = 0; i < numAlunos; i++)
    {
        printf("Matricula: %d\n", alunosTemp[i].matricula);
        printf("Nome: %s\n", alunosTemp[i].nome);
        printf("Sexo: %c\n", alunosTemp[i].sexo);
        printf("CPF: %s\n", alunosTemp[i].cpf);
        printf("Data de Nascimento: %02d/%02d/%04d\n",
        alunosTemp[i].dataNasc.dia, alunosTemp[i].dataNasc.mes, alunosTemp[i].dataNasc.ano);
        printf("Idade: %d\n", alunosTemp[i].idade);
        printf("\n");
    }
    return;
}
//
//Função para cadastrar professor
//
int cadastrarProfessor(pessoa *novoProfessor)
{
    cadastrarNome(novoProfessor);
    cadastrarSexo(novoProfessor);
    novoProfessor->funcao = 'P';//Define a função como professor
    cadastrarCPF(novoProfessor);
    cadastrarData(novoProfessor);
    cadastraMatricula(novoProfessor);
    novoProfessor->situacao = 'A';//Define a situação como ativa
    professores[numProfessores] = *novoProfessor;//Adiciona o novo professor ao vetor de professores
    numProfessores++;//Incrementa o número de professores cadastrados
    return true;
}
//
//Função para listar professores
//
void listarProfessores()
{
    if (numProfessores == 0)
    {
        printf("Nenhum professor cadastrado.\n");
        return;
    }

    printf("Lista de Professores Cadastrados\n");
    for (int i = 0; i < numProfessores; i++)
    {
        printf("Matricula: %d\n", professores[i].matricula);
        printf("Nome: %s\n", professores[i].nome);
        printf("Sexo: %c\n", professores[i].sexo);
        printf("CPF: %s\n", professores[i].cpf);
        printf("Data de Nascimento: %02d/%02d/%04d\n", professores[i].dataNasc.dia, professores[i].dataNasc.mes, professores[i].dataNasc.ano);
        printf("Idade: %d\n", professores[i].idade);
        printf("\n");
    }
}
//
//Função para listar professores por sexo
//
void listarProfessoresPorSexo()
{
    char sexo;
    int encontrado = false;

    printf("Digite o sexo dos professores a serem listados (M/F/O)\n>>");
    scanf("%c", &sexo);
    flush_in();//Limpa o buffer do teclado removendo o '\n' que
    sexo = toupper(sexo);//Converte para maiúsculo

    if (sexo != 'M' && sexo != 'F' && sexo != 'O')
    {
        printf("Erro---Sexo invalido. Digite M para Masculino, F para Feminino ou O para Outro.\n");
        return;
    }
    for (int i = 0; i < numProfessores; i++)
    {
        if (professores[i].sexo == sexo)
        {
            printf("Matricula: %d\n", professores[i].matricula);
            printf("Nome: %s\n", professores[i].nome);
            printf("Sexo: %c\n", professores[i].sexo);
            printf("CPF: %s\n", professores[i].cpf);
            printf("Data de Nascimento: %02d/%02d/%04d\n",
            professores[i].dataNasc.dia, professores[i].dataNasc.mes, professores[i].dataNasc.ano);
            printf("Idade: %d\n", professores[i].idade);
            printf("\n");
            encontrado = true;
        }
    }
    if (!encontrado)
    {
        if (sexo == 'M') {
            printf("Nenhum professor cadastrado com o sexo Masculino.\n");
        } else if (sexo == 'F') {
            printf("Nenhuma professora cadastrada com o sexo Feminino.\n");
        } else {
            printf("Nenhum professor cadastrado com o sexo Outro.\n");
        }
    }
    return;
}
//
//Função para listar professores em ordem alfabética
//
void listarProfessoresOrdemAlfabetica()
{
    //Cria um vetor temporário para ordenar os professores
    pessoa professoresTemp[50];
    memcpy(professoresTemp, professores, numProfessores * sizeof(pessoa));

    //Ordena o vetor temporário usando o algoritmo de bolha
    for (int i = 0; i < numProfessores - 1; i++)
    {
        for (int j = 0; j < numProfessores - i - 1; j++)
        {
            if (strcmp(professoresTemp[j].nome, professoresTemp[j + 1].nome) > 0)
            {
                pessoa temp = professoresTemp[j];
                professoresTemp[j] = professoresTemp[j + 1];
                professoresTemp[j + 1] = temp;
            }
        }
    }

    //Imprime a lista de professores ordenada
    printf("Lista de Professores em Ordem Alfabetica:\n");
    for (int i = 0; i < numProfessores; i++)
    {
        printf("Matricula: %d\n", professoresTemp[i].matricula);
        printf("Nome: %s\n", professoresTemp[i].nome);
        printf("Sexo: %c\n", professoresTemp[i].sexo);
        printf("CPF: %s\n", professoresTemp[i].cpf);
        printf("Data de Nascimento: %02d/%02d/%04d\n", professoresTemp[i].dataNasc.dia, professoresTemp[i].dataNasc.mes, professoresTemp[i].dataNasc.ano);
        printf("Idade: %d\n", professoresTemp[i].idade);
        printf("\n");
    }
}
//
//Função para ordenar professores por data de nascimento
//
void ordenarProfessoresPorDataNascimento()
{
    //Cria um vetor temporário para ordenar os professores
    pessoa professoresTemp[50];
    memcpy(professoresTemp, professores, numProfessores * sizeof(pessoa));
    //Ordena o vetor temporário
    for (int i = 0; i < numProfessores - 1; i++)
    {
        for (int j = 0; j < numProfessores - i - 1; j++)
        {
            if (professoresTemp[j].dataNasc.ano > professoresTemp[j + 1].dataNasc.ano)
            {
                pessoa temp = professoresTemp[j];
                professoresTemp[j] = professoresTemp[j + 1];
                professoresTemp[j + 1] = temp;
            }
            else if (professoresTemp[j].dataNasc.ano == professoresTemp[j + 1].dataNasc.ano)
            {
                if (professoresTemp[j].dataNasc.mes > professoresTemp[j + 1].dataNasc.mes)
                {
                    pessoa temp = professoresTemp[j];
                    professoresTemp[j] = professoresTemp[j + 1];
                    professoresTemp[j + 1] = temp;
                }
                else if (professoresTemp[j].dataNasc.mes == professoresTemp[j + 1].dataNasc.mes)
                {
                    if (professoresTemp[j].dataNasc.dia > professoresTemp[j + 1].dataNasc.dia)
                    {
                        pessoa temp = professoresTemp[j];
                        professoresTemp[j] = professoresTemp[j + 1];
                        professoresTemp[j + 1] = temp;
                    }
                }
            }
        }
    }
    //Imprime a lista de professores ordenada por data de nascimento
    printf("Lista de Professores em Ordem por Data de Nascimento:\n");
    for (int i = 0; i < numProfessores; i++)
    {
        printf("Matricula: %d\n", professoresTemp[i].matricula);
        printf("Nome: %s\n", professoresTemp[i].nome);
        printf("Sexo: %c\n", professoresTemp[i].sexo);
        printf("CPF: %s\n", professoresTemp[i].cpf);
        printf("Data de Nascimento: %02d/%02d/%04d\n",
        professoresTemp[i].dataNasc.dia, professoresTemp[i].dataNasc.mes, professoresTemp[i].dataNasc.ano);
        printf("Idade: %d\n", professoresTemp[i].idade);
        printf("\n");
    }

    return;
}
//
//Função para listar aniversariantes do mês
//
void listarAniversariantesDoMes()
{
    int mesAtual;
    int encontrado = false;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    mesAtual = tm.tm_mon + 1;

    for (int i = 0; i < numAlunos; i++)
    {
        if (alunos[i].dataNasc.mes == mesAtual)
        {
            printf("Matricula: %d\n", alunos[i].matricula);
            printf("Nome: %s\n", alunos[i].nome);
            printf("Sexo: %c\n", alunos[i].sexo);
            printf("CPF: %s\n", alunos[i].cpf);
            printf("Data de Nascimento: %02d/%02d/%04d\n",
            alunos[i].dataNasc.dia, alunos[i].dataNasc.mes, alunos[i].dataNasc.ano);
            printf("Idade: %d\n", alunos[i].idade);
            printf("\n");
            encontrado = true;
        }
    }

    for (int i = 0; i < numProfessores; i++)
    {
        if (professores[i].dataNasc.mes == mesAtual)
        {
            printf("Matricula: %d\n", professores[i].matricula);
            printf("Nome: %s\n", professores[i].nome);
            printf("Sexo: %c\n", professores[i].sexo);
            printf("CPF: %s\n", professores[i].cpf);
            printf("Data de Nascimento: %02d/%02d/%04d\n",
            professores[i].dataNasc.dia, professores[i].dataNasc.mes, professores[i].dataNasc.ano);
            printf("Idade: %d\n", professores[i].idade);
            printf("\n");
            encontrado = true;
        }
    }

    if (!encontrado)
    {
        printf("Nenhum aniversariante no mes %d.\n", mesAtual);
    }
    return;
}
//
//Função para cadastrar disciplina
//
void cadastrarDisciplina(disciplina *novaDisciplina)
{
    if(numDisciplinas >= 20) {
        printf("Erro---Número máximo de disciplinas atingido.\n");
        return false;
    }

    nomeDisciplina(novaDisciplina);
    codigoDisciplina(novaDisciplina);
    printf("Digite o semestre da disciplina:\n>>");
    scanf("%d", &novaDisciplina->semestre);
    flush_in();
    // Incrementa o contador global
    disciplinas[numDisciplinas] = *novaDisciplina;
    numDisciplinas++;
    printf("Disciplina cadastrada com sucesso!\n");
    return;
}
//
//Função para listar disciplinas
//
void listarDisciplinas(){

    if (numDisciplinas == 0)
    {
        printf("Nenhuma disciplina cadastrada.\n");
        return;
    }

    int escolhaListar;
    char digitarCodigo[10];
    int voltar = false;

    while (!voltar)
    {
        printf("Listar Disciplinas:\n1- Listar todas as disciplinas \n2- Listar uma disciplina\n3- Voltar\n>>");
        scanf("%d", &escolhaListar);
        flush_in();//Limpa o buffer do teclado removendo o '\n' que fica após o scanf

        switch(escolhaListar){
            case 1:
            {
                for(int i = 0; i < numDisciplinas; i++){

                    printf("Disciplina %d:\n", i+1);
                    printf("Nome: %s\n", disciplinas[i].nome);
                    printf("Codigo: %s\n", disciplinas[i].codigo);
                    printf("Semestre: %d\n", disciplinas[i].semestre);
                    printf("\n");
                }
                break;
            }
            case 2:
            {
                printf("Digite o código da disciplina: \n");
                fgets(digitarCodigo, 10, stdin);
            
                digitarCodigo[strcspn(digitarCodigo, "\n")] = '\0'; // remove \n

                    int encontrado = false;
                    for(int i = 0; i < numDisciplinas; i++) {
                        if(strcmp(digitarCodigo, disciplinas[i].codigo) == 0) { // strcmp retorna 0 se iguais
                            printf("Disciplina encontrada:\n");
                            printf("Nome: %s\n", disciplinas[i].nome);
                            printf("Código: %s\n", disciplinas[i].codigo);
                            printf("Semestre: %d\n", disciplinas[i].semestre);
                            encontrado = 1;
                        }
                    }
                    if (!encontrado) {
                        printf("Disciplina no encontrada.\n");
                    }
                    break;
            }
            case 3:
            {
                printf("Voltando...\n");
                voltar = true;
                break;
            }
            default:
            {
                printf("Opcao invalida.\n");
                break;
            }
        }
    }
    return;
}
//
//Função para alterar aluno em disciplina
//
void alterarAlunoDisciplina() {
    char digitarCodigo[10];
    int encontradoDisciplina = 0;

    printf("Digite o codigo da disciplina:\n>>");
    fgets(digitarCodigo, 10, stdin);
    digitarCodigo[strcspn(digitarCodigo, "\n")] = '\0';

    for(int i = 0; i < numDisciplinas; i++) {
        if(strcmp(digitarCodigo, disciplinas[i].codigo) == 0) { // disciplina encontrada
            encontradoDisciplina = 1;
            printf("Disciplina encontrada:\n");
            printf("Nome: %s\n", disciplinas[i].nome);
            printf("Codigo: %s\n", disciplinas[i].codigo);
            printf("Semestre: %d\n", disciplinas[i].semestre);

            int opcao;
            printf("O que deseja fazer?\n1- Adicionar aluno\n2- Remover aluno\n3- Voltar\n>>");
            scanf("%d", &opcao);
            flush_in();

            if(opcao == 1) { // adicionar aluno
                if(disciplinas[i].numAlunos >= 50){
                    printf("Erro---Disciplina cheia!\n");
                    return;
                }

                int matricula;
                printf("Digite a matricula do aluno a adicionar:\n>>");
                scanf("%d", &matricula);
                flush_in();

                int encontradoAluno = 0;
                for(int j = 0; j < numAlunos; j++){
                    if(alunos[j].matricula == matricula){
                        disciplinas[i].alunos[disciplinas[i].numAlunos] = alunos[j];
                        disciplinas[i].numAlunos++;
                        printf("Aluno %s adicionado a disciplina %s!\n", alunos[j].nome, disciplinas[i].nome);
                        encontradoAluno = 1;
                        break;
                    }
                }
                if(!encontradoAluno){
                    printf("Aluno com matricula %d nao encontrado.\n", matricula);
                }
            }
            else if(opcao == 2){ // remover aluno
                int matricula;
                printf("Digite a matricula do aluno a remover:\n>>");
                scanf("%d", &matricula);
                flush_in();

                int encontradoAluno = 0;
                for(int j = 0; j < disciplinas[i].numAlunos; j++){
                    if(disciplinas[i].alunos[j].matricula == matricula){
                        // move todos os alunos posteriores uma posição para trás
                        for(int k = j; k < disciplinas[i].numAlunos - 1; k++){
                            disciplinas[i].alunos[k] = disciplinas[i].alunos[k+1];
                        }
                        disciplinas[i].numAlunos--;
                        printf("Aluno removido com sucesso!\n");
                        encontradoAluno = 1;
                        break;
                    }
                }
                if(!encontradoAluno){
                    printf("Aluno com matricula %d nao esta nessa disciplina.\n", matricula);
                }
            }
            else if(opcao == 3){
                printf("Voltando...\n");
                return;
            }
            else{
                printf("Opçao invalida.\n");
            }   
            break; // sai do loop das disciplinas, já encontramos
        }
    }

    if(!encontradoDisciplina){
        printf("Disciplina nao encontrada.\n");
    }

    return;
}
//
//Função para buscar Pessoas
//
int buscarPessoas()
{
    if (numAlunos == 0 && numProfessores == 0)
    {
        printf("Nenhuma pessoa cadastrada.\n");
        return false;
    }
    //Usa-se uma cópia temporária para não alterar a ordem original dos alunos e professores
    pessoa alunosTemp[50];
    pessoa professoresTemp[50];
    memcpy(alunosTemp, alunos, numAlunos * sizeof(pessoa));
    memcpy(professoresTemp, professores, numProfessores * sizeof(pessoa));

    int volta = false;
    int encontrado = false;
    char nomeBusca[40];

    while (!volta)
    {
        int valido = true;
        printf("Insira o nome das pessoas a serem buscadas ou digite [0] para cancelar (ao menos 3 caracteres)\n>>");
        fgets(nomeBusca, sizeof(nomeBusca), stdin);
        nomeBusca[strcspn(nomeBusca, "\n")] = 0; //Remove o '\n' do final da string

        if (strcmp(nomeBusca, "0") == 0)
        {
            volta = true;
            break;
        }
        int carcteres = strlen(nomeBusca);

        if (carcteres < 3)
        {
            printf("Erro---Numero de caracteres invalidos.\n");
            valido = false;
        }
        
        if (valido)
        {
            for (int i = 0; i < numAlunos; i++)
            {
                if (strstr(strlwr(alunosTemp[i].nome), strlwr(nomeBusca)) != NULL)
                {
                    printf("Matricula: %d\n", alunos[i].matricula);
                    printf("Nome: %s\n", alunos[i].nome);
                    printf("Sexo: %c\n", alunos[i].sexo);
                    printf("CPF: %s\n", alunos[i].cpf);
                    printf("Data de Nascimento: %02d/%02d/%04d\n",
                    alunos[i].dataNasc.dia, alunos[i].dataNasc.mes, alunos[i].dataNasc.ano);
                    printf("Idade: %d\n", alunos[i].idade);
                    printf("\n");
                    encontrado = true;
                }
            }
            for (int i = 0; i < numProfessores; i++)
            {
                if (strstr(strlwr(professoresTemp[i].nome), strlwr(nomeBusca)) != NULL)
                {
                    printf("Matricula: %d\n", professores[i].matricula);
                    printf("Nome: %s\n", professores[i].nome);
                    printf("Sexo: %c\n", professores[i].sexo);
                    printf("CPF: %s\n", professores[i].cpf);
                    printf("Data de Nascimento: %02d/%02d/%04d\n",
                    professores[i].dataNasc.dia, professores[i].dataNasc.mes, professores[i].dataNasc.ano);
                    printf("Idade: %d\n", professores[i].idade);
                    printf("\n");
                    encontrado = true;
                }
            }
            if (!encontrado)
            {
                printf("Nenhuma pessoa encontrada com o nome %s.\n", nomeBusca);
            }
        }   
    }

    return 0;
}
//
//Função para alterar pessoa
//
void alterarPessoa(pessoa *entrada)
{
    int encontrado = false;
    int matricula;
    int escolha;

    if (entrada->funcao == 'A')
    {
        if (numAlunos == 0)
        {
            printf("Erro---Nenhum aluno cadastrado.\n");
            return;
        }
        encontrado = false;
        printf("Digite a matricula do aluno a ser alterado\n>>");
        scanf("%d", &matricula);
        flush_in();//Limpa o buffer do teclado removendo o '\n' que fica após o scanf
        if (numAlunos == 0)
        {
            printf("Erro---Nenhum aluno cadastrado.\n");
            return;
        }
        for (int i = 0; i < numAlunos; i++)
        {
            if (alunos[i].matricula == matricula)
            {
                encontrado = true;
                while (escolha != 5)
                {
                    printf("Informe qual dado quer alterar:\n1- Nome\n2- Sexo\n3- CPF\n4- Data de Nascimento\n5- Cancelar\n>>");
                    scanf("%d", &escolha);
                    flush_in();//Limpa o buffer do teclado removendo o '\n' que fica após o scanf
                    switch (escolha)
                    {
                        case 1:
                        {
                            cadastrarNome(&alunos[i]);
                            break;
                        }
                        case 2:
                        {
                            cadastrarSexo(&alunos[i]);
                            break;
                        }
                        case 3:
                        {
                            cadastrarCPF(&alunos[i]);
                            break;
                        }
                        case 4:
                        {
                            cadastrarData(&alunos[i]);
                            break;
                        }
                        case 5:
                        {
                            printf("Alteracao cancelada\n");
                            return;
                        }
                        default:
                        {
                            printf("Erro---Opcao invalida\n");
                            return;
                        }
                    }
                    printf("Aluno com matricula %d alterado com sucesso\n", matricula);
                }
                
            }
        }
        if (!encontrado)
        {
            printf("Erro---Aluno com matricula %d nao encontrado\n", matricula);
        }
    }

    else if (entrada->funcao == 'P')
    {
        if (numProfessores == 0)
        {
            printf("Erro---Nenhum professor cadastrado.\n");
            return;
        }
        encontrado = false;

        printf("Digite a matricula do professor a ser alterado\n>>");
        scanf("%d", &matricula);
        flush_in();//Limpa o buffer do teclado removendo o '\n' que fica após o scanf
        if (numProfessores == 0)
        {
            printf("Erro---Nenhum professor cadastrado.\n");
            return;
        }
        for (int i = 0; i < numProfessores; i++)
        {
            if (professores[i].matricula == matricula)
            {
                encontrado = true;
                while (escolha != 5)
                {
                    printf("Informe qual dado quer alterar:\n1- Nome\n2- Sexo\n3- CPF\n4- Data de Nascimento\n5- Cancelar\n>>");
                    scanf("%d", &escolha);
                    flush_in();//Limpa o buffer do teclado removendo o '\n' que fica após o scanf
                    switch (escolha)
                    {
                        case 1:
                        {
                            cadastrarNome(&professores[i]);
                            break;
                        }
                        case 2:
                        {
                            cadastrarSexo(&professores[i]);
                            break;
                        }
                        case 3:
                        {
                            cadastrarCPF(&professores[i]);
                            break;
                        }
                        case 4:
                        {
                            cadastrarData(&professores[i]);
                            break;
                        }
                        case 5:
                        {
                            printf("Alteracao cancelada\n");
                            return;
                        }
                        default:
                        {
                            printf("Erro---Opcao invalida\n");
                            return;
                        }
                    }
                    printf("Professor com matricula %d alterado com sucesso\n", matricula);
                }

                
            }
        }
        if (!encontrado)
        {
            printf("Erro---Aluno com matricula %d nao encontrado\n", matricula);
        }
    }

    else if (entrada->funcao == 'P')
    {
        if (numProfessores == 0)
        {
            printf("Erro---Nenhum professor cadastrado.\n");
            return;
        }
        encontrado = false;

        printf("Digite a matricula do professor a ser alterado\n>>");
        scanf("%d", &matricula);
        flush_in();//Limpa o buffer do teclado removendo o '\n' que fica após o scanf
        if (numProfessores == 0)
        {
            printf("Erro---Nenhum professor cadastrado.\n");
            return;
        }
        for (int i = 0; i < numProfessores; i++)
        {
            if (professores[i].matricula == matricula)
            {
                encontrado = true;
                while (escolha != 5)
                {
                    printf("Informe qual dado quer alterar:\n1- Nome\n2- Sexo\n3- CPF\n4- Data de Nascimento\n5- Cancelar\n>>");
                    scanf("%d", &escolha);
                    flush_in();//Limpa o buffer do teclado removendo o '\n' que fica após o scanf
                    switch (escolha)
                    {
                        case 1:
                        {
                            cadastrarNome(&professores[i]);
                            break;
                        }
                        case 2:
                        {
                            cadastrarSexo(&professores[i]);
                            break;
                        }
                        case 3:
                        {
                            cadastrarCPF(&professores[i]);
                            break;
                        }
                        case 4:
                        {
                            cadastrarData(&professores[i]);
                            break;
                        }
                        case 5:
                        {
                            printf("Alteracao cancelada\n");
                            return;
                        }
                        default:
                        {
                            printf("Erro---Opcao invalida\n");
                            return;
                        }
                    }
                    printf("Professor com matricula %d alterado com sucesso\n", matricula);
                }

            }
        }
        if (!encontrado)
        {
            printf("Erro---Professor com matricula %d nao encontrado\n", matricula);
            printf("Erro---Professor com matricula %d nao encontrado\n", matricula);
        }
    }
}
//
//Função para excluir aluno
//
void excluirPessoa(pessoa *entrada)
{
    if (entrada->funcao == 'A')
    {
        if (numAlunos == 0)
        {
            printf("Erro---Nenhum aluno cadastrado.\n");
            return;
        }

        int matricula;
        int encontrado = false;
        printf("Digite a matricula do aluno a ser excluido\n>>");
        scanf("%d", &matricula);
        flush_in();//Limpa o buffer do teclado removendo o '\n' que fica após o scanf

        for (int i = 0; i < numAlunos; i++)
        {
            if (alunos[i].matricula == matricula)
            {
                encontrado = true;
                //Move todos os alunos após o aluno a ser excluído uma posição para trás
                for (int j = i; j < numAlunos - 1; j++)
                {
                    alunos[j] = alunos[j + 1];
                }
                numAlunos--;//Decrementa o número de alunos cadastrados
                printf("Aluno com matricula %d excluido com sucesso\n", matricula);
                break;
            }
        }
        if (!encontrado)
        {
            printf("Erro---Aluno com matricula %d nao encontrado\n", matricula);
        }
    }
    if (entrada->funcao == 'P')
    {
        if (numProfessores == 0)
        {
            printf("Erro---Nenhum professor cadastrado.\n");
            return;
        }

        int matricula;
        int encontrado = false;
        printf("Digite a matricula do professor a ser excluido\n>>");
        scanf("%d", &matricula);
        flush_in();//Limpa o buffer do teclado removendo o '\n' que fica após o scanf
        for (int i = 0; i < numProfessores; i++)
        {
            if (professores[i].matricula == matricula)
            {
                encontrado = true;
                //Move todos os professores após o professor a ser excluído uma posição para trás
                for (int j = i; j < numProfessores - 1; j++)
                {
                    professores[j] = professores[j + 1];
                }
                numProfessores--;//Decrementa o número de professores cadastrados
                printf("Professor com matricula %d excluido com sucesso\n", matricula);
                break;
            }
        }
        if (!encontrado)
        {
            printf("Erro---Professor com matricula %d nao encontrado\n", matricula);
        }
    }
    if (entrada->funcao == 'P')
    {
        if (numProfessores == 0)
        {
            printf("Erro---Nenhum professor cadastrado.\n");
            return;
        }

        int matricula;
        int encontrado = false;
        printf("Digite a matricula do professor a ser excluido\n>>");
        scanf("%d", &matricula);
        flush_in();//Limpa o buffer do teclado removendo o '\n' que fica após o scanf
        for (int i = 0; i < numProfessores; i++)
        {
            if (professores[i].matricula == matricula)
            {
                encontrado = true;
                //Move todos os professores após o professor a ser excluído uma posição para trás
                for (int j = i; j < numProfessores - 1; j++)
                {
                    professores[j] = professores[j + 1];
                }
                numProfessores--;//Decrementa o número de professores cadastrados
                printf("Professor com matricula %d excluido com sucesso\n", matricula);
                break;
            }
        }
        if (!encontrado)
        {
            printf("Erro---Professor com matricula %d nao encontrado\n", matricula);
        }
    }
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
            nome[i] = tolower(nome[i]);//Converte todo o nome para minúsculo

            if (i == 0 || nome[i - 1] == ' ')
            {
                nome[i] = toupper(nome[i]);
            }
            i++;
        }
    }

    strcpy(entrada->nome, nome);//Copia o nome validado para a estrutura
}
//
//Função para cadastrar nome na disciplina
//
void nomeDisciplina(disciplina *entrada)
{
    int valido = false;
    char nomeDisciplina[50];

    while(!valido)
    {
        printf("Digite o nome da disciplina\n>>");
        fgets(nomeDisciplina, 50, stdin);
        nomeDisciplina[strcspn(nomeDisciplina, "\n")] = '\0';//Remove o '\n' do final da string, se houver
        valido = validarNome(nomeDisciplina);

        for (int j = 0; j < numDisciplinas; j++)
        {
            if (strcmp(nomeDisciplina, disciplinas[j].nome) == 0)
            {
                printf("Erro---Nome ja cadastrado\n");
                valido = false;
            }
        }
    }
    if (valido)
        {
            //Transformar a primeira letra de cada palavra em maiúscula
            int i = 0;
            
            while (nomeDisciplina[i] != '\0')
            {
                nomeDisciplina[i] = tolower(nomeDisciplina[i]);//Converte todo o nome para minúsculo

                if (i == 0 || nomeDisciplina[i - 1] == ' ')
                {
                    nomeDisciplina[i] = toupper(nomeDisciplina[i]);
                }
                i++;
            }
        }
    strcpy(entrada->nome, nomeDisciplina);//Copia o nome validado para a estrutura
}
//
//Função para cadastrar código da disciplina
//
void codigoDisciplina(disciplina *entrada)
{
    int valido = false;
    char codigoDisciplina[10];

    while(!valido)
    {
        printf("Digite o codigo da disciplina (maximo 6 caracteres)\n>>");
        fgets(codigoDisciplina, 10, stdin);
        codigoDisciplina[strcspn(codigoDisciplina, "\n")] = '\0';//Remove o '\n' do final da string, se houver

        valido = verficarCodigoDisciplina(codigoDisciplina);
    }

    if (valido)
    {
        for (int i = 0; codigoDisciplina[i] != '\0'; i++)
        {
            codigoDisciplina[i] = toupper(codigoDisciplina[i]); // Converte para maiúsculo
        }

        strcpy(entrada->codigo, codigoDisciplina);//Copia o codigo validado para a estrutura
    }
    return;
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
    if (strlen(nome) > 50)
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
//Função para verificar o código da disciplina
//
int verficarCodigoDisciplina(char codigo[])
{
    int i = 0;
    while (codigo[i] != '\0')
    {
        if (codigo[i] >= 'a' && codigo[i] <= 'z' || codigo[i] >= 'A' && codigo[i] <= 'Z' || codigo[i] >= '0' && codigo[i] <= '9')
        {
            i++;
        }
        else
        {
            printf("Erro---Codigo invalido, nao adicone acentos ou caracteres especiais\n");
            return false;
        } 
    }

    for (int j = 0; j < numDisciplinas; j++)
    {
        if (strcmp(codigo, disciplinas[j].codigo) == 0)
        {
            printf("Erro---Codigo ja cadastrado\n");
            return false;
        }
    }

    if (strlen(codigo) > 6)
    {
        printf("Erro---Codigo muito grande\n");
        return false;
    }
    else if (strlen(codigo) < 3)
    {
        printf("Erro---Codigo muito pequeno\n");
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
}
//
//Função para cadastrar CPF
//
void cadastrarCPF(pessoa *entrada)
{
    char cpf[15];
    int valido = false;
    int retorno = false;
    int cadastrado = false;
    int i, cont;
    i = cont = 0;

    //int retorno;
    while (!valido)
    {
        printf("Insira o CPF\n>>");
        fgets(cpf, 15, stdin);
        fflush(stdin);
        cpf[strcspn(cpf, "\n")] = '\0';//Remove o '\n' do final da string, se houver
        retorno = validarCPF(cpf);//Chama a função para validar o CPF retornando true ou false
        retorno = validarCPF(cpf);//Chama a função para validar o CPF retornando true ou false

        if (retorno)
        {
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
        if (numAlunos > 0)
            {
                for (int j = 0; j < numAlunos; j++)
                {
                    if (strcmp(cpf, alunos[j].cpf) == 0)
                    {
                        printf("Erro---CPF ja cadastrado\n");
                        cadastrado = true;
                        break;
                    }
                }
            }
            if (cadastrado)
            {
                valido = false;
                cadastrado = false;
                continue;
            }
            else
            {
                valido = true;
            }   
        }
    }
    //Formata o CPF para o padrão xxx.xxx.xxx-xx se não estiver nesse formato
    
    strcpy(entrada->cpf, cpf);//Copia o CPF validado para a estrutura
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
    int dia, mes, ano, idade;
    int valido = false;

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int anoAtual = tm.tm_year + 1900;//Ano atual

    while (!valido)
    {
        printf("Digite a data de nascimento (DD MM AAAA)\n>>");
        scanf("%d %d %d", &dia, &mes, &ano);
        flush_in();//Limpa o buffer do teclado removendo o '\n' que fica após o scanf

        //verifca se alguma data esta vazia
        if (dia == 0 || mes == 0 || ano == 0)
            {
                printf("Erro---Data invalida\n");
                continue;
            }

        if (ano < 1900 || ano > anoAtual)
        {
            printf("Erro---Ano invalido\n");
            continue;
        }
        if (mes < 1 || mes > 12)
        {
            printf("Erro---Mes invalido\n");
            continue;
        }
        if (dia < 1 || dia > 31)
        {
            printf("Erro---Dia invalido\n");
            continue;
        }
        //Verifica se o dia é válido para o mês
        if (mes == 2)
        {
            //Verifica se é ano bissexto
            if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
            {
                if (dia > 29)
                {
                    printf("Erro---Dia invalido para fevereiro em ano bissexto\n");
                    continue;
                }
            }
            else
            {
                if (dia > 28)
                {
                    printf("Erro---Dia invalido para fevereiro em ano nao bissexto\n");
                    continue;
                }
            }
        }
        else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
        {
            if (dia > 30)
            {
                printf("Erro---Dia invalido para o mes %d\n", mes);
                continue;
            }
        }

        valido = true;//Se chegou aqui, a data é válida
    }

    //Calcula a idade
    idade = anoAtual - ano;
    //Se o mês atual é menor que o mês de nascimento, ou se é o mesmo mês e o dia atual é menor que o dia de nascimento, subtrai 1 da idade
    if (mes > (tm.tm_mon + 1) || (mes == (tm.tm_mon + 1) && dia > tm.tm_mday))
    {
        idade--;
    }
    entrada->dataNasc.dia = dia;
    entrada->dataNasc.mes = mes;
    entrada->dataNasc.ano = ano;
    entrada->idade = idade;
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
//Função para deiar a primeira letra de cada palavra em maiúscula
//
void strfirstupper(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        str[i] = tolower(str[i]);//Converte todo o nome para minúsculo

        if (i == 0 || str[i - 1] == ' ')
        {
            str[i] = toupper(str[i]);
        }
        i++;
    }
}
//
//Função para deiar a primeira letra de cada palavra em maiúscula
//
void strfirstupper(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        str[i] = tolower(str[i]);//Converte todo o nome para minúsculo

        if (i == 0 || str[i - 1] == ' ')
        {
            str[i] = toupper(str[i]);
        }
        i++;
    }
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