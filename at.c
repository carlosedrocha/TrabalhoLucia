#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>


#define TAM 4
#define SEED 5

typedef struct Dados{
    float altura,peso;
    int idade;
} Dados;

void imprimirDados(Dados dados[]){
    int i=0;
    for(i; i<TAM; i++){
        printf("\tAltura: %.2f m",dados[i].altura);
        printf("\tPeso: %.2f Kg ",dados[i].peso);
        printf("\tIdade: %d Anos",dados[i].idade);
        printf("\n");
    }
}

void preencherDados(Dados dados[]) {
    
    srand(SEED);

    for(int i=0; i<TAM; i++){
        dados[i].altura = 0.1 + rand() * (2.20 - 0.00) / RAND_MAX;  ;
        dados[i].peso =0.00 + rand() * (200.00 - 15.00) / RAND_MAX;     
        dados[i].idade = (rand() % 101);

        printf("Altura: %.2f \n", dados[i].altura);
        printf("Peso: %.2f \n", dados[i].peso);
        printf("Idade: %d\n\n", dados[i].idade);
    }
    
    return;

}

void bubbleSort (Dados dados[]) { // Ordena pelo tamanho de forma decrescente
    Dados aux;
    printf("=========================BubbleSort==============================");

    for (int cont = 1; cont < TAM; cont++) {
        // printf("\n[%d] ", cont);

        for (int j = 0; j < TAM - 1; j++) {
          //  printf("%d, ", j);

            if (dados[j].altura < dados[j + 1].altura) {  
                aux = dados[j];
                dados[j] = dados[j + 1];
                dados[j + 1] = aux;
            }
        }
    }
}

int main() {
   
    Dados dados[TAM];
    
    // preenche os dados
    preencherDados(dados);
    
    // imprime os dados
    imprimirDados(dados); 

    // BubbleSort
    bubbleSort(dados);

    // imprime os dados
    printf("\nApos bubble sort\n");
    imprimirDados(dados); 

    return 0;

}