#include <stdio.h>
#include <stdlib.h>

#define TAM 1000

void geraVet(int []);
void exibeVet(int []);
int buscaLinear(int [], int, int);
void ordenaVet(int v[]);

int main(void){
    int vet[TAM];
    int k, result;
    int n = TAM;
    
    printf("\nAlgoritimo para busca linear em vetores de tamanho n.\n");
    printf("\nVetor Sendo Gerado...");
    geraVet(vet);
    ordenaVet(vet);

    printf("\n\nInforme o número a ser buscado no vetor: ");
    scanf(" %d", &k);
    
    result = buscaLinear(vet, n, k);

    if (result != 0){
        printf("\n\nO número %d foi encontrado com sucesso!!!", k);
        printf("\nO vetor Sera exibido para comprovação do usuário...\n\n");
    } else {
        printf("\n\nO número %d não foi encontrado!!!", k);
        printf("\nO vetor Sera exibido para comprovação do usuário...\n\n");
    }
    exibeVet(vet);

    return 0;
}

int buscaLinear(int v[], int n, int k){
    for (int i = 1; i < n; i++){
        if (v[i] == k){
            return i;
        }
    }
    return 0;
}

void geraVet(int v[]){
    for (int i = 0; i < TAM; i++){
        v[i] = rand() %100;
    }
}

void exibeVet(int v[]){
    printf("\nVetor Gerado:\n");
    for (int i = 0; i < TAM; i++){
        printf("%d\t", v[i]);
    }    
    printf("\n");
}

void ordenaVet(int v[]){
    int i, j, aux;
    for( i=0; i<TAM; i++ ){
        for( j=i+1; j<TAM; j++ ){
            if( v[i] > v[j] ){
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}