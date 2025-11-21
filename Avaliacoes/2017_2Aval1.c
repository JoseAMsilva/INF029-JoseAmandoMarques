#include <stdio.h>
#include <stdlib.h>

#define TAM 10
void clear_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int insereChar(char *vet, char c, int itens) {
    if (itens < TAM) {
        for (int i = 0; i < TAM; i++) {
            if (vet[i] == '\0') {
                vet[i] = c;
                return 1;
            }
        }
    }
    return 0;
}

void imprimeVetor(char *vet) {
    for (int i = 0; i < TAM; i++) {
        if (vet[i] != '\0') {
            printf("%c ", vet[i]);
        } else {
            break;
        }
    }
    printf("\n");
}

void exluirCaractere(char *vetor, int itens){
    vetor[itens-1] = '\0';
}

void trocarCaractere(char *vetor, char caractere, int itens){
    int i;
    for (i = 0; vetor[i] > caractere || i == itens; i++);
    vetor[i] = caractere;
}

int menu(){
    int valida = 0;
    int escolha;
    while (!valida){
        printf("Menu:\n");
        printf("1. Inserir caractere\n");
        printf("2. Imprimir vetor\n");
        printf("3. Excluir caractere\n");
        printf("4. Trocar caractere\n");
        printf("-1. Sair\n");
        scanf("%d", &escolha);
        clear_stdin();
        if (escolha >= 0 && escolha <= 4){
            valida = 1;
            return escolha;
        } else {
            printf("Escolha invalida. Tente novamente.\n");
        }
    }
    return escolha;
}

int main() {
    char vetor[TAM] = {'\0'};
    char caractere;
    int itens = 0;
    int escolha = 0;
    int sair = 0;
    while (!sair){
        switch (escolha){
            case -1:
            {
                sair = 1;
                break;
            }
            case 0: 
            {
                escolha = menu();
                break;
            }
            case 1:
            {
                scanf("%c", &caractere);
                clear_stdin();
                if (insereChar(vetor, caractere, itens))
                {
                    printf("Caractere %c adicionado", caractere);
                    itens++;
                }
                else{
                    printf("Vetor cheio\n");
                }
                escolha = 0;
                break;
            }
            case 2:
            {
                if (itens <= 0){    
                    printf("vetor vazio");
                }else{
                    imprimeVetor(vetor);
                }
                escolha = 0;
                break;
            }
            case 3:
            {
                if (itens <= 0){
                    printf("Vetor Vazio");
                }else{
                    exluirCaractere(vetor, itens);
                     itens--;
                } 
                escolha = 0;
                break;
            }
            case 4: 
            {
                if (itens <= 0){
                    printf("vetor vazio");
                }else{
                    scanf("%c", &caractere);
                    clear_stdin();
                    trocarCaractere(vetor, caractere, itens);
                }
                escolha = 0;
                break;
            }
        }
    }

    return 0;
}