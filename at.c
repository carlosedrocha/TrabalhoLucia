#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>


#define TAM 25
#define SEED 20


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

void trocaPosicao (Dados dados[], int de, int para) {
    Dados temp = dados[de];
    dados[de] = dados[para];
    dados[para] = temp;
}

int particao(Dados dados[], int inferior, int superior) {

    int li = inferior; // limite inferior
    int ls = superior; // limite superior   
    Dados aux = dados[li]; // pivo
    //int maiorAltura = dados[superior].altura;
    printf("=========================particao de %2.f e %2.f==============================",dados[li].altura, dados[ls].altura);

    while( li < ls ) {

        while(dados[li].altura >= aux.altura) {
            li++;
        }
        printf("\n li pos while: %d\n", li);
        while(dados[ls].altura < aux.altura) {
            ls--;
        }
        printf("\n ls pos while: %d\n", ls);

        if (li < ls) {
            trocaPosicao(dados, li, ls);
        }
    }
    
    trocaPosicao(dados, ls, inferior);   
    // printf("================================================================");
    printf("\n ls --- %d\n", ls);

    return ls;
}



void quickSort(Dados dados[], int inferior, int superior){

    int li = inferior; // limite inferior
    int ls = superior; // limite superior
    
    printf("\n\tli: %d, altura na posicao: %f, ls: %d, altura na posicao: %f\n", li, dados[li].altura, ls, dados[ls].altura);
    
    if (li < ls) {
        
        int j = particao(dados, li, ls); // pivo
        printf("\nj pos particao=%d", j);

        if (inferior < j - 1) {
            quickSort(dados, li, j-1);
        }

        if (j < superior) {
            quickSort(dados, j+1, superior);
        }
        
    }

}




int main() {
   
    Dados dados[TAM];
    int inferior = 0;
    int superior = TAM - 1;
    clock_t tempo;
    double tempo_execucao;

    tempo = clock(); //armazena tempo

    printf("Variavel tempo %lf", &tempo); //
    printf("Endereco variavel tempo %lf", tempo); //

    // preenche os dados
    preencherDados(dados);
    
    // imprime os dados
    imprimirDados(dados); 


    //QuickSort
    quickSort(dados,inferior, superior);
    //imprime os dados
    printf("\nApos quickSort\n");
    imprimirDados(dados); 

    // // BubbleSort
    // bubbleSort(dados);
    // // imprime os dados
    // printf("\nApos BubbleSort\n");
    // imprimirDados(dados); 

    printf("Variavel tempo %lf", &tempo); //
    printf("Endereco variavel tempo %lf", tempo); //
    tempo = clock() - tempo; //tempo final - tempo inicial
    //imprime o tempo na tela
    
    printf("termino %ld || Tempo de execucao: %lf milisegundos"), tempo, (((double)tempo)/((CLOCKS_PER_SEC/1000)));

    return 0;

}