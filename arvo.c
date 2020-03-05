#include <stdio.h>
#include <stdlib.h>

#define TAM 1000
#define TAM2 999

int buscaBin(int [], int, int, int);
void geraVet(int []);
void ordenaVet(int []);
void exibeVet(int []);

int main(void){
    int vet[TAM];
    int s = 0;
    int e = TAM2;
    int k, result;
    
    printf("\nAlgoritimo para busca em arvore binarea em vetores de tamanho n.\n");

    printf("\nVetor Sendo Gerado...");
    geraVet(vet);
    ordenaVet(vet);

    printf("\n\nInforme o número a ser buscado no vetor: ");
    scanf(" %d", &k);
    
    result = buscaBin(vet, s, e, k);

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

int buscaBin(int vet[], int s, int e, int k){
    int m;
    if (s <= e){
        m = (e + s) / 2;
        printf("%d", m);
        printf("\nA");
        if (vet[m] == k){
            printf("\n\nFinish");
            return m;
        } 
        if (k < vet[m]){
            printf("\nB");
            return buscaBin(vet, s, m-1, k);
        }
        printf("\nC");
        return buscaBin(vet, m+1, e, k);
    }
    printf("\nD\n");
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