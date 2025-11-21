#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void clear_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int menu();
int verificarVaretas(char vareta[], int lista[]);
int validaEntrada(char vareta[], int *d1, int *d2, int *d3, int *d4);
int formaTriangulo(int a, int b, int c);

int menu(void) {
    int opcao;
    while(1){
        printf("1 Verificar varetas\n");
        printf("2 Sair\n");

        if (scanf("%d", &opcao) != 1) {
            clear_stdin();
            printf("Entrada invalida\n");
            continue; 
        }
        clear_stdin();
        
        switch (opcao)
        {
            case 1: return 1;
            case 2: return -1;
            default: printf("Opcao invalida!\n");
        }
    }
}
int formaTriangulo(int a, int b, int c) {
    if (a + b > c && a + c > b && b + c > a) {
        return 1; 
    } else {
        return 0; 
    }
}

int validaEntrada(char vareta[], int *d1, int *d2, int *d3, int *d4) {
    if (!d1 || !d2 || !d3 || !d4) {
        return 0; 
    }

    int tam = (int)strlen(vareta);
    if (tam > 0 && vareta[tam-1] == '\n') {
        vareta[tam-1] = '\0';
        tam--;
    }

    if (tam < 7 || tam > 15) {
        return 0;
    }

    int *destinos[] = {d1, d2, d3, d4};
    int num_grupos_encontrados = 0;
    int numero_atual = 0;
    int contagem_digitos = 0;

    for (int i = 0; i < tam; i++) {
        char c = vareta[i];
        
        if (c >= '0' && c <= '9') {
            if (contagem_digitos >= 3) {
                return 0; 
            }
            numero_atual = numero_atual * 10 + (c - '0');
            contagem_digitos++;
        }
        
        else if (c == '-') {
            if (contagem_digitos == 0 || num_grupos_encontrados >= 4) {
                return 0;
            }

            if (numero_atual < 1 || numero_atual > 100) {
                return 0; 
            }
            
            *destinos[num_grupos_encontrados] = numero_atual;
            num_grupos_encontrados++;

            numero_atual = 0;
            contagem_digitos = 0;
        }
        
        else {
            return 0;
        }
    }

    if (contagem_digitos == 0 || num_grupos_encontrados != 3) {
        return 0; 
    }
    
    if (numero_atual < 1 || numero_atual > 100) {
        return 0; 
    }
    
    *destinos[num_grupos_encontrados] = numero_atual;
    num_grupos_encontrados++;
    return 1;
}

int verificarVaretas(char vareta[], int lista[])
{
    int d1, d2, d3, d4;
    if (validaEntrada(vareta, &d1, &d2, &d3, &d4)){

        if (formaTriangulo(d1, d2, d3))
        {
            lista[0] = d1;
            lista[1] = d2;
            lista[2] = d3;
            return 1;
        }
        else if (formaTriangulo(d1, d2, d4))
        {
            lista[0] = d1;
            lista[1] = d2;
            lista[2] = d4;
            return 1;
        }
        else if (formaTriangulo(d1, d3, d4))
        {
            lista[0] = d1;
            lista[1] = d3;
            lista[2] = d4;
            return 1;
        }
        else if (formaTriangulo(d2, d3, d4))
        {
            lista[0] = d2;
            lista[1] = d3;
            lista[2] = d4;
            return 1;
        }
        else
        {
            return 0; 
        }
    }
    else{
        return 0; 
    }
}


int main(void){
    int escolha;

    escolha = menu(); 

    if (escolha == 1){
        char vareta[20];
        int lista[3];

        printf(">> ");
        
        fgets(vareta, sizeof(vareta), stdin); 
        
        if (verificarVaretas(vareta, lista)){
            printf("%d, %d, %d\n", lista[0], lista[1], lista[2]);
        }
        else{
            printf("Varetas nao formam um triangulo\n");
        }
    }
    else if (escolha == -1){
        printf("Saindo do programa..\n");
    }
    
    return 0;
}