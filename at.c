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

void particao(Dados dados[], int inferior, int superior, Dados pivo) {
    Dados aux = dados[inferior];
    int menorAltura = dados[inferior].altura;
    int maiorAltura = dados[superior].altura;
    while(maiorAltura > menorAltura) {
        while(dados[inferior].altura <= aux.altura) {
            inferior--;
        }
    }

    while(dados[superior].altura > aux.altura) {
        superior++;
    }

    if (inferior < superior) {
        dados[superior] = aux;
    }
    dados[superior] = dados[inferior];
    pivo = dados[superior];

}

void quickSort(Dados dados[], int inferior, int superior){
    Dados j = dados[inferior]; // pivo

    if(dados[inferior].altura < dados[superior].altura) {
        particao(dados, inferior, superior, j);
        quickSort(dados, inferior, superior);
    }

}


int main() {
   
    Dados dados[TAM];
    int inferior = 0;
    int superior = TAM;
    // preenche os dados
    preencherDados(dados);
    
    // imprime os dados
    imprimirDados(dados); 


    // QuickSort
    quickSort(dados,inferior, superior);
    // imprime os dados
    printf("\nApos quickSort\n");
    imprimirDados(dados); 

    // BubbleSort
    bubbleSort(dados);
    // imprime os dados
    printf("\nApos BubbleSort\n");
    imprimirDados(dados); 
    return 0;

}