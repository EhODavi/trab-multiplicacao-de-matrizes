#include <stdio.h>
#include <stdlib.h>

// Função que aloca uma matriz
long long int** alocaMatriz(int ordem) {
    long long int** matriz = malloc(sizeof(long long int*) * ordem);

    for(int i = 0; i < ordem; i++) {
        matriz[i] = malloc(sizeof(long long int) * ordem);
    }

    return matriz;
}

// Função que desaloca uma matriz
void liberaMatriz(long long int** matriz, int ordem) {
    for(int i = 0; i < ordem; i++) {
        free(matriz[i]);
    }

    free(matriz);
}

// Função que realiza a leitura dos dados da matriz
void leMatriz(long long int** matriz, int ordem) {
    for(int i = 0; i < ordem; i++) {
        for(int j = 0; j < ordem; j++) {
            scanf("%lli", &matriz[i][j]);
        }
    }
}

// Função que multiplica as matrizes A e B, gerando C
void multiplicaMatriz(long long int** matrizA, long long int** matrizB, long long int** matrizC, int ordem) {
    for(int i = 0; i < ordem; i++) {
        for(int j = 0; j < ordem; j++) {
            int somatorio = 0;
            
            for(int z = 0; z < ordem; z++) {
                somatorio += matrizA[i][z] * matrizB[z][j];
            }

            matrizC[i][j] = somatorio;
        }
    }
}

// Função que imprime uma matriz no terminal
void escreveMatriz(long long int** matriz, int ordem) {
    for(int i = 0; i < ordem; i++) {
        printf("%lli", matriz[i][0]);
        
        for(int j = 1; j < ordem; j++) {
            printf(" %lli", matriz[i][j]);
        }
        
        printf("\n");
    }
}

int main() {
    // Declaração de variáveis
    long long int** matrizA;
    long long int** matrizB;
    long long int** matrizC;
    int ordem;

    // Lendo a ordem das matrizes
    scanf("%d", &ordem);

    // Alocando as matrizes de acordo com a ordem dada
    matrizA = alocaMatriz(ordem);  
    matrizB = alocaMatriz(ordem);
    matrizC = alocaMatriz(ordem);

    // Lendo os dados das matrizes A e B
    leMatriz(matrizA, ordem);
    leMatriz(matrizB, ordem);

    // Multiplicando as matrizes A e B, gerando C
    multiplicaMatriz(matrizA, matrizB, matrizC, ordem);

    // Imprimindo a matriz C no terminal
    escreveMatriz(matrizC, ordem);

    // Desalocando todas as matrizes
    liberaMatriz(matrizA, ordem);
    liberaMatriz(matrizB, ordem);
    liberaMatriz(matrizC, ordem);

    return 0;
}