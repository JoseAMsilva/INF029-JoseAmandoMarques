// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: José Amando Marques da Silva
//  email: joseamando5974@gmail.com
//  Matrícula: 20251160019
//  Semestre: 2025.2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016 - 17/10/2025

// #################################################

#include <stdio.h>
#include "trabalho1.h" 
#include <stdlib.h>
#include <string.h>

DataQuebrada quebraData(char data[]);
int ehbissexto(int ano);
int diasNoMes(int mes, int ano);
int datafinalehmaior(DataQuebrada dqInicial, DataQuebrada dqFinal);
int extrairDigitos(int num, int* entrada);
void formatarPalavra(char *palavra);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
  int datavalida = 1;

    DataQuebrada dq;
    dq = quebraData(data);
    int dia = dq.iDia;
    int mes = dq.iMes;
    int ano = dq.iAno;

    if (!dq.valido){
        datavalida = 0;
        return datavalida;
    }

    if ( ano <= 0 || ano > 2025)
    {
        datavalida = 0;
        return datavalida;
    }
    if (mes < 1 || mes > 12)
    {
        datavalida = 0;
        return datavalida;
    }
    if (dia <= 0 || dia > diasNoMes(mes, ano))
    {
        datavalida = 0;
        return datavalida;
    }

  //printf("%s\n", data);

  if (datavalida)
      return 1;
  else
      return 0;
}

// /*
//  Q2 = diferença entre duas datas
//  @objetivo
//     Calcular a diferença em anos, meses e dias entre duas datas
//  @entrada
//     uma string datainicial, uma string datafinal. 
//  @saida
//     Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
//     1 -> cálculo de diferença realizado com sucesso
//     2 -> datainicial inválida
//     3 -> datafinal inválida
//     4 -> datainicial > datafinal
//     Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
//  */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{
      //verifique se a data final não é menor que a data inicial
        DataQuebrada dqInicial = quebraData(datainicial);
        DataQuebrada dqFinal = quebraData(datafinal);
        if (!datafinalehmaior(dqInicial, dqFinal)){
            dma.retorno = 4;
            return dma;
        }
        //calcule a distancia entre as datas
        dma.qtdDias = dqFinal.iDia - dqInicial.iDia;
        dma.qtdMeses = dqFinal.iMes - dqInicial.iMes;
        dma.qtdAnos = dqFinal.iAno - dqInicial.iAno;

        if (dma.qtdMeses < 0){
            dma.qtdMeses += 12;
            dma.qtdAnos--;
        }

        if (dma.qtdDias < 0){
        dma.qtdDias += diasNoMes((dqFinal.iMes == 1) ? 12 : dqFinal.iMes - 1, (dqFinal.iMes == 1) ? dqFinal.iAno - 1 : dqFinal.iAno);
        dma.qtdMeses--;
        }
    
        //se tudo der certo
        dma.retorno = 1;
        return dma;
    }
    
}

// /*
//  Q3 = encontrar caracter em texto
//  @objetivo
//     Pesquisar quantas vezes um determinado caracter ocorre em um texto
//  @entrada
//     uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
//         Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
//  @saida
//     Um número n >= 0.
//  */
int q3(char *texto, char c, int isCaseSensitive)
{
    formatarPalavra(texto);
    int qtdOcorrencias = 0;
    if (isCaseSensitive == 1){
        for (int i = 0; texto[i] != '\0'; i++){
            if (texto[i] == c){
                qtdOcorrencias++;
            }
        }   
    }else{
        for (int i = 0; texto[i] != '\0'; i++){
            if (texto[i] == c || texto[i] == c - 32 || texto[i] == c + 32){
                qtdOcorrencias++;
            }
        }
    }
    return qtdOcorrencias;
}
// /*
//  Q4 = encontrar palavra em texto
//  @objetivo
//     Pesquisar todas as ocorrências de uma palavra em um texto
//  @entrada
//     uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
//  @saida
//     Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
//     O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
//         posicoes[0] = 13;
//         posicoes[1] = 16;
//         Observe que o índice da posição no texto deve começar ser contado a partir de 1.
//         O retorno da função, n, nesse caso seria 1;

//  */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    formatarPalavra(strTexto);
    formatarPalavra(strBusca);
    int qtdOcorrencias = 0;
    for (int i = 0; i < 30; i++){
        posicoes[i] = -1;
    }
    int j = 0;
    for (int i = 0; strTexto[i] != '\0'; i++){
        if (strTexto[i] == strBusca[j]){
            if (j == 0){
                posicoes[qtdOcorrencias * 2] = i + 1;
            }
            j++;
            if (strBusca[j] == '\0'){
                posicoes[qtdOcorrencias * 2 + 1] = i + 1;
                qtdOcorrencias++;
                j = 0;
            }
        }else{
            j = 0;
        }
    }
    return qtdOcorrencias;
}

// /*
//  Q5 = inverte número
//  @objetivo
//     Inverter número inteiro
//  @entrada
//     uma int num.
//  @saida
//     Número invertido
//  */

int q5(int num)
{
    int numInvertido = 0;
    int resto;
    while (num != 0){
        resto = num % 10;
        numInvertido = numInvertido * 10 + resto;
        num /= 10;
    }
    num = numInvertido;

    return num;
}

// /*
//  Q6 = ocorrência de um número em outro
//  @objetivo
//     Verificar quantidade de vezes da ocorrência de um número em outro
//  @entrada
//     Um número base (numerobase) e um número de busca (numerobusca).
//  @saida
//     Quantidade de vezes que número de busca ocorre em número base
//  */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias = 0;
    int digitosBase[50];
    int digitosBusca[50];
    int tamBase = 0;
    int tamBusca = 0;

    tamBase = extrairDigitos(numerobase, digitosBase);
    tamBusca = extrairDigitos(numerobusca, digitosBusca);

    if (tamBusca == 0 || tamBusca > tamBase) {
        return 0;
    }

    for (int i = 0; i <= tamBase - tamBusca;) {
        int encontrado = 1;
        for (int j = 0; j < tamBusca; j++) {
            if (digitosBase[i + j] != digitosBusca[j]) {
                encontrado = 0;
                break;
            }
        }
        if (encontrado) {
            qtdOcorrencias++;   
            i = i + tamBusca;
        } else {
            i++;
        }
    }
    return qtdOcorrencias;
}

// /*
//  Q7 = jogo busca palavras
//  @objetivo
//     Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
//  @entrada
//     Uma matriz de caracteres e uma string de busca (palavra).
//  @saida
//     1 se achou 0 se não achou
//  */

int q7(char matriz[8][10], char palavra[5])
 {
    #define LINHAS 8
    #define COLUNAS 10
     int achou = 0;
     int tamanhoPalavra = strlen(palavra);
     int i, j;

     if (tamanhoPalavra == 0)
     {
        return 0;
     }

     int deltaLinha[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
     int deltaColuna[8] = { 0, 0, -1, 1, -1, 1, -1, 1};

     for (i = 0; i < LINHAS; i++)
     {
        for (j = 0; j < COLUNAS; j++)
        {
            if (matriz[i][j] == palavra[0])
            {
                for (int direcao = 0; direcao < 8; direcao++)
                {
                    achou = 1;
                    int k;
                    for (k = 1; k < tamanhoPalavra; k++)
                    {
                        int proximaLinha = i + deltaLinha[direcao] * k;
                        int proximaColuna = j + deltaColuna[direcao] * k;

                        if (proximaLinha < 0 || proximaLinha >= LINHAS || proximaColuna < 0 || proximaColuna >= COLUNAS)
                        {
                            achou = 0;
                            break;
                        }
                        if (matriz[proximaLinha][proximaColuna] != palavra[k])
                        {
                            achou = 0;
                            break;
                        }
                    }
                    if (achou)
                    {
                        return 1;
                    }
                }
            }
        }
     }
     return achou;
 }

DataQuebrada quebraData(char data[]){
    DataQuebrada dq;
    char sDia[3];
    char sMes[3];
    char sAno[5];
    int i;
    dq.valido = 1;

    for (i = 0; data[i] != '/'; i++){
        sDia[i] = data[i];  
    }
    if(i == 1 || i == 2){ 
        sDia[i] = '\0';  
    }else {
        dq.valido = 0;
    }
    int j = i + 1; 
    i = 0;

    for (; data[j] != '/'; j++){
        sMes[i] = data[j];
        i++;
    }
    if(i == 1 || i == 2){ 
        sMes[i] = '\0';  
        }else {
        dq.valido = 0;
    }

    j = j + 1; 
    i = 0;
    for(; data[j] != '\0'; j++){
        sAno[i] = data[j];
        i++;
    }
    if(i == 2 || i == 4){
        sAno[i] = '\0'; 
        }else {
        dq.valido = 0;
    }
    dq.iDia = atoi(sDia);
    dq.iMes = atoi(sMes);
    dq.iAno = atoi(sAno);
    return dq;
}

int ehbissexto(int ano){
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int diasNoMes(int mes, int ano) {
    int dias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (mes == 2 && ehbissexto(ano))
        return 29;
    return dias[mes - 1];
}

int datafinalehmaior(DataQuebrada dqInicial, DataQuebrada dqFinal){
    if (dqFinal.iAno > dqInicial.iAno){
        return 1;
    }else if (dqFinal.iAno == dqInicial.iAno && dqFinal.iMes > dqInicial.iMes){
        return 1;
    }else if (dqFinal.iAno == dqInicial.iAno && dqFinal.iMes == dqInicial.iMes && dqFinal.iDia > dqInicial.iDia){
        return 1;
    }else{
        return 0;
    }
}

int extrairDigitos(int num, int* entrada) {
    int tempEntrada[50];
    int count = 0;

    if (num == 0) {
        entrada[0] = 0;
        return 1;
    }

    while (num > 0) {
        tempEntrada[count] = (int)(num % 10);
        num = num / 10;
        count++;
    }

    for (int i = 0; i < count; i++) {
        entrada[i] = tempEntrada[count - 1 - i];
    }

    return count;
}
void formatarPalavra(char *palavra)
{
    //a -93 a -96, A -125 a -128, e -86 a -88, E -118 a -120, i -82 a -84, I -114 a -116, o -75 a -78, O -107 a -110, u -69 a -71, U -101 a -103 c -89, C -121
    char semAcento[100];
    int codigo[strlen(palavra)];
    int i, j;
    for (int i = 0; i < strlen(palavra); i++)
    {
        codigo[i] = (int)palavra[i];
    }
    

    for (i = 0, j = 0; i < strlen(palavra); i++)
    {
        if (codigo[i] == -61)
        {
            switch (codigo[i + 1])
            {
            case -93:
            case -94:
            case -95:
            case -96:
                semAcento[j] = 'a';
                j++;
                break;
            case -125:
            case -126:
            case -127:
            case -128:
                semAcento[j] = 'A';
                j++;
                break;
            case -86:
            case -87:
            case -88:
                semAcento[j] = 'e';
                j++;
                break;
            case -118:
            case -119:
            case -120:
                semAcento[j] = 'E';
                j++;
                break;
            case -82:
            case -83:
            case -84:
                semAcento[j] = 'i';
                j++;
                break;
            case -114:
            case -115:
            case -116:
                semAcento[j] = 'I';
                j++;
                break;
            case -75:
            case -76:
            case -77:
            case -78:
                semAcento[j] = 'o';
                j++;
                break;
            case -107:
            case -108:
            case -109:
            case -110:
                semAcento[j] = 'O';
                j++;
                break;
            case -69:
            case -70:
            case -71:
                semAcento[j] = 'u';
                j++;
                break;
            case -101:
            case -102:
            case -103:
                semAcento[j] = 'U';
                j++;
                break;
            case -89:
                semAcento[j] = 'c';
                j++;
                break;
            case -121:
                semAcento[j] = 'C';
                j++;
                break;
            }
        }
        if (codigo[i] > 0)
        {
            semAcento[j] = palavra[i];
            j++;
        }
    }
    semAcento[j] = '\0';
    strcpy(palavra, semAcento);
}