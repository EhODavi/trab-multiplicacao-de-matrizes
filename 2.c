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

// Função que preenche a matriz com O's
void preencheMatriz(long long int** matriz, int ordem) {
    for(int i = 0; i < ordem; i++) {
        for(int j = 0; j < ordem; j++) {
            matriz[i][j] = 0;
        }
    }
}

// Função que realiza a leitura dos dados da matriz
void leMatriz(long long int** matriz, int ordem) {
    for(int i = 0; i < ordem; i++) {
        for(int j = 0; j < ordem; j++) {
            scanf("%lli", &matriz[i][j]);
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

// Função que calcula a nova ordem da matriz (caso n != 2^k)
int novaOrdemMatriz(int ordem) {
    int novaordem = 1;
    int auxiliar = ordem;

    // Transforma a ordem dada em potência de 2
    while((auxiliar / 2) > 0) {
        auxiliar /= 2;
        novaordem *= 2;
    }

    // Se a novaordem for diferente de ordem, quer dizer que a ordem dada não é do tipo 2^k
    if(novaordem != ordem) {
        novaordem *= 2;
    }

    return novaordem;
}

// Função que realiza a soma de duas matrizes
void somaMatriz(long long int** matrizA, long long int** matrizB, long long int** matrizC, int ordem) {
    for(int i = 0; i < ordem; i++) {
        for(int j = 0; j < ordem; j++) {
            matrizC[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }
}

// Função que realiza a substração de duas matrizes
void subtraiMatriz(long long int** matrizA, long long int** matrizB, long long int** matrizC, int ordem) {
    for(int i = 0; i < ordem; i++) {
        for(int j = 0; j < ordem; j++) {
            matrizC[i][j] = matrizA[i][j] - matrizB[i][j];
        }
    }
}

// Função que copia a matrizB para a matrizA
void copiaMatriz(long long int** matrizA, int linhaInicialA, int colunaInicialA, int linhaFinalA, int colunaFinalA,
                 long long int** matrizB, int linhaInicialB, int colunaInicialB, int linhaFinalB, int colunaFinalB) {
    int tamanhoVetor = (linhaFinalA - linhaInicialA + 1) * (colunaFinalA - colunaInicialA + 1);
    long long int* vetorAuxiliar = malloc(sizeof(long long int) * tamanhoVetor);

    int contador = 0;
    
    // Copia a matrizB para um vetorAuxiliar
    for(int i = linhaInicialB; i <= linhaFinalB; i++) {
        for(int j = colunaInicialB; j <= colunaFinalB; j++) {
            vetorAuxiliar[contador] = matrizB[i][j];
            contador++;
        }
    }

    contador = 0;

    // Copia o vetorAuxiliar para a matrizA
    for(int i = linhaInicialA; i <= linhaFinalA; i++) {
        for(int j = colunaInicialA; j <= colunaFinalA; j++) {
            matrizA[i][j] = vetorAuxiliar[contador];
            contador++;
        }
    }

    free(vetorAuxiliar);
}

// Função que multiplica as matrizes A e B, gerando C
void multiplicaMatriz(long long int** matrizA, long long int** matrizB, long long int** matrizC, int ordem) {
    // Caso base da função recursiva
    if(ordem == 1) {
        matrizC[0][0] = matrizA[0][0] * matrizB[0][0];
        return;
    }

    // Alocando as quatro submatrizes da matrizA
    long long int** matrizA11 = alocaMatriz(ordem / 2);
    long long int** matrizA12 = alocaMatriz(ordem / 2);
    long long int** matrizA21 = alocaMatriz(ordem / 2);
    long long int** matrizA22 = alocaMatriz(ordem / 2);

    // Alocando as quatro submatrizes da matrizB
    long long int** matrizB11 = alocaMatriz(ordem / 2);
    long long int** matrizB12 = alocaMatriz(ordem / 2);
    long long int** matrizB21 = alocaMatriz(ordem / 2);
    long long int** matrizB22 = alocaMatriz(ordem / 2);

    // Alocando as matrizes que vieram de uma soma
    long long int** somaMatrizA11A22 = alocaMatriz(ordem / 2);
    long long int** somaMatrizA21A22 = alocaMatriz(ordem / 2);
    long long int** somaMatrizA11A12 = alocaMatriz(ordem / 2);
    long long int** somaMatrizA21A11 = alocaMatriz(ordem / 2);
    long long int** somaMatrizA12A22 = alocaMatriz(ordem / 2);

    // Alocando as matrizes que vieram de uma soma
    long long int** somaMatrizB11B22 = alocaMatriz(ordem / 2);
    long long int** somaMatrizB12B22 = alocaMatriz(ordem / 2);
    long long int** somaMatrizB21B11 = alocaMatriz(ordem / 2);
    long long int** somaMatrizB11B12 = alocaMatriz(ordem / 2);
    long long int** somaMatrizB21B22 = alocaMatriz(ordem / 2);

    // Alocando as matrizes auxiliares 
    long long int** M1 = alocaMatriz(ordem / 2);
    long long int** M2 = alocaMatriz(ordem / 2);
    long long int** M3 = alocaMatriz(ordem / 2);
    long long int** M4 = alocaMatriz(ordem / 2);
    long long int** M5 = alocaMatriz(ordem / 2);
    long long int** M6 = alocaMatriz(ordem / 2);
    long long int** M7 = alocaMatriz(ordem / 2);

    // Criando as quatro submatrizes da matrizC
    long long int** matrizC11;
    long long int** matrizC12;
    long long int** matrizC21;
    long long int** matrizC22;

    // Alocando as matrizes que vieram de uma soma
    long long int** somaMatrizM1M7 = alocaMatriz(ordem / 2);
    long long int** somaMatrizM4M5 = alocaMatriz(ordem / 2);
    long long int** somaMatrizM1M4M5M7 = alocaMatriz(ordem / 2);
    long long int** somaMatrizM3M5 = alocaMatriz(ordem / 2);
    long long int** somaMatrizM2M4 = alocaMatriz(ordem / 2);
    long long int** somaMatrizM1M2 = alocaMatriz(ordem / 2);
    long long int** somaMatrizM3M6 = alocaMatriz(ordem / 2);
    long long int** somaMatrizM1M2M3M6 = alocaMatriz(ordem / 2);

    // Extraindo as submatrizes das matrizes A e B
    copiaMatriz(matrizA11, 0, 0, ordem / 2 - 1, ordem / 2 - 1, matrizA, 0, 0, ordem / 2 - 1, ordem / 2 - 1);
    copiaMatriz(matrizA12, 0, 0, ordem / 2 - 1, ordem / 2 - 1, matrizA, 0, ordem / 2, ordem / 2 - 1, ordem - 1);
    copiaMatriz(matrizA21, 0, 0, ordem / 2 - 1, ordem / 2 - 1, matrizA, ordem / 2, 0, ordem - 1, ordem / 2 - 1);
    copiaMatriz(matrizA22, 0, 0, ordem / 2 - 1, ordem / 2 - 1, matrizA, ordem / 2, ordem / 2, ordem - 1, ordem - 1);
    copiaMatriz(matrizB11, 0, 0, ordem / 2 - 1, ordem / 2 - 1, matrizB, 0, 0, ordem / 2 - 1, ordem / 2 - 1);
    copiaMatriz(matrizB12, 0, 0, ordem / 2 - 1, ordem / 2 - 1, matrizB, 0, ordem / 2, ordem / 2 - 1, ordem - 1);
    copiaMatriz(matrizB21, 0, 0, ordem / 2 - 1, ordem / 2 - 1, matrizB, ordem / 2, 0, ordem - 1, ordem / 2 - 1);
    copiaMatriz(matrizB22, 0, 0, ordem / 2 - 1, ordem / 2 - 1, matrizB, ordem / 2, ordem / 2, ordem - 1, ordem - 1);

    // Realizando as operações de soma e subtração
    somaMatriz(matrizA11, matrizA22, somaMatrizA11A22, ordem / 2);
    somaMatriz(matrizB11, matrizB22, somaMatrizB11B22, ordem / 2);
    somaMatriz(matrizA21, matrizA22, somaMatrizA21A22, ordem / 2);
    subtraiMatriz(matrizB12, matrizB22, somaMatrizB12B22, ordem / 2);
    subtraiMatriz(matrizB21, matrizB11, somaMatrizB21B11, ordem / 2);
    somaMatriz(matrizA11, matrizA12, somaMatrizA11A12, ordem / 2);
    subtraiMatriz(matrizA21, matrizA11, somaMatrizA21A11, ordem / 2);
    somaMatriz(matrizB11, matrizB12, somaMatrizB11B12, ordem / 2);
    subtraiMatriz(matrizA12, matrizA22, somaMatrizA12A22, ordem / 2);
    somaMatriz(matrizB21, matrizB22, somaMatrizB21B22, ordem / 2);
    
    // Realizando o passo recursivo da função recursiva
    multiplicaMatriz(somaMatrizA11A22, somaMatrizB11B22, M1, ordem / 2);
    multiplicaMatriz(somaMatrizA21A22, matrizB11, M2, ordem / 2);
    multiplicaMatriz(matrizA11, somaMatrizB12B22, M3, ordem / 2);
    multiplicaMatriz(matrizA22, somaMatrizB21B11, M4, ordem / 2);
    multiplicaMatriz(somaMatrizA11A12, matrizB22, M5, ordem / 2);
    multiplicaMatriz(somaMatrizA21A11, somaMatrizB11B12, M6, ordem / 2);
    multiplicaMatriz(somaMatrizA12A22, somaMatrizB21B22, M7, ordem / 2);

    // Realizando as operações de soma e subtração
    somaMatriz(M1, M7, somaMatrizM1M7, ordem / 2);
    subtraiMatriz(M4, M5, somaMatrizM4M5, ordem / 2);
    somaMatriz(somaMatrizM1M7, somaMatrizM4M5, somaMatrizM1M4M5M7, ordem / 2);
    somaMatriz(M3, M5, somaMatrizM3M5, ordem / 2);
    somaMatriz(M2, M4, somaMatrizM2M4, ordem / 2);
    subtraiMatriz(M1, M2, somaMatrizM1M2, ordem / 2);
    somaMatriz(M3, M6, somaMatrizM3M6, ordem / 2);
    somaMatriz(somaMatrizM1M2, somaMatrizM3M6, somaMatrizM1M2M3M6, ordem / 2);

    // Atribuindo o resultado final
    matrizC11 = somaMatrizM1M4M5M7;
    matrizC12 = somaMatrizM3M5;
    matrizC21 = somaMatrizM2M4;
    matrizC22 = somaMatrizM1M2M3M6;

    // Copiando as submatrizes de C para a matrizC
    copiaMatriz(matrizC, 0, 0, ordem / 2 - 1, ordem / 2 - 1, matrizC11, 0, 0, ordem / 2 - 1, ordem / 2 - 1);
    copiaMatriz(matrizC, 0, ordem / 2, ordem / 2 - 1, ordem - 1, matrizC12, 0, 0, ordem / 2 - 1, ordem / 2 - 1);
    copiaMatriz(matrizC, ordem / 2, 0, ordem - 1, ordem / 2 - 1, matrizC21, 0, 0, ordem / 2 - 1, ordem / 2 - 1);
    copiaMatriz(matrizC, ordem / 2, ordem / 2, ordem - 1, ordem - 1, matrizC22, 0, 0, ordem / 2 - 1, ordem / 2 - 1);

    // Desalocando as quatro submatrizes da matrizA
    liberaMatriz(matrizA11, ordem / 2);
    liberaMatriz(matrizA12, ordem / 2);
    liberaMatriz(matrizA21, ordem / 2);
    liberaMatriz(matrizA22, ordem / 2);

    // Desalocando as quatro submatrizes da matrizB
    liberaMatriz(matrizB11, ordem / 2);
    liberaMatriz(matrizB12, ordem / 2);
    liberaMatriz(matrizB21, ordem / 2);
    liberaMatriz(matrizB22, ordem / 2);

    // Desalocando as matrizes que vieram de uma soma
    liberaMatriz(somaMatrizA11A22, ordem / 2);
    liberaMatriz(somaMatrizA21A22, ordem / 2);
    liberaMatriz(somaMatrizA11A12, ordem / 2);
    liberaMatriz(somaMatrizA21A11, ordem / 2);
    liberaMatriz(somaMatrizA12A22, ordem / 2);

    // Desalocando as matrizes que vieram de uma soma
    liberaMatriz(somaMatrizB11B22, ordem / 2);
    liberaMatriz(somaMatrizB12B22, ordem / 2);
    liberaMatriz(somaMatrizB21B11, ordem / 2);
    liberaMatriz(somaMatrizB11B12, ordem / 2);
    liberaMatriz(somaMatrizB21B22, ordem / 2);

    // Desalocando as matrizes auxiliares
    liberaMatriz(M1, ordem / 2);
    liberaMatriz(M2, ordem / 2);
    liberaMatriz(M3, ordem / 2);
    liberaMatriz(M4, ordem / 2);
    liberaMatriz(M5, ordem / 2);
    liberaMatriz(M6, ordem / 2);
    liberaMatriz(M7, ordem / 2);

    // Desalocando as matrizes que vieram de uma soma
    liberaMatriz(somaMatrizM1M7, ordem / 2);
    liberaMatriz(somaMatrizM4M5, ordem / 2);
    liberaMatriz(somaMatrizM1M4M5M7, ordem / 2);
    liberaMatriz(somaMatrizM3M5, ordem / 2);
    liberaMatriz(somaMatrizM2M4, ordem / 2);
    liberaMatriz(somaMatrizM1M2, ordem / 2);
    liberaMatriz(somaMatrizM3M6, ordem / 2);
    liberaMatriz(somaMatrizM1M2M3M6, ordem / 2);

}

int main() {
    // Declaração de variáveis
    long long int** matrizA;
    long long int** matrizB;
    long long int** matrizC;
    int ordem, novaOrdem;

    // Lendo a ordem das matrizes
    scanf("%d", &ordem);
    
    // Calculando a novaOrdem da matriz
    novaOrdem = novaOrdemMatriz(ordem); 

    // Alocando as matrizes de acordo com a ordem dada
    matrizA = alocaMatriz(ordem);
    matrizB = alocaMatriz(ordem);
    matrizC = alocaMatriz(ordem);

    // Lendo os dados das matrizes A e B
    leMatriz(matrizA, ordem);
    leMatriz(matrizB, ordem);

    // Se a ordem for diferente da novaOrdem, quer dizer que a ordem dada não é do tipo 2^k
    if(ordem != novaOrdem) {
       // Alocando as matrizes auxiliares
       long long int** matrizAuxiliarA = alocaMatriz(novaOrdem);
       long long int** matrizAuxiliarB = alocaMatriz(novaOrdem);
       long long int** matrizAuxiliarC = alocaMatriz(novaOrdem);
       
       // Prenchendo as matrizes auxiliares com 0's
       preencheMatriz(matrizAuxiliarA, novaOrdem);
       preencheMatriz(matrizAuxiliarB, novaOrdem);
       preencheMatriz(matrizAuxiliarC, novaOrdem);
       
       // Copiando as matrizes informadas para as auxiliares
       copiaMatriz(matrizAuxiliarA, 0, 0, ordem - 1, ordem - 1, matrizA, 0, 0, ordem - 1, ordem - 1);
       copiaMatriz(matrizAuxiliarB, 0, 0, ordem - 1, ordem - 1, matrizB, 0, 0, ordem - 1, ordem - 1);

       // Multiplicando as matrizes A e B, gerando C
       multiplicaMatriz(matrizAuxiliarA, matrizAuxiliarB, matrizAuxiliarC, novaOrdem);

       // Copiando a matrizAuxiliarC para a matrizC
       copiaMatriz(matrizC, 0, 0, ordem - 1, ordem - 1, matrizAuxiliarC, 0, 0, ordem - 1, ordem - 1);
       
       // Desalocando as matrizes auxiliares
       liberaMatriz(matrizAuxiliarA, novaOrdem);
       liberaMatriz(matrizAuxiliarB, novaOrdem);
       liberaMatriz(matrizAuxiliarC, novaOrdem);

    } else {
        // Multiplicando as matrizes A e B, gerando C
        multiplicaMatriz(matrizA, matrizB, matrizC, ordem);
    }

    // Imprimindo a matriz C no terminal
    escreveMatriz(matrizC, ordem);

    // Desalocando todas as matrizes
    liberaMatriz(matrizA, ordem);
    liberaMatriz(matrizB, ordem);
    liberaMatriz(matrizC, ordem);

    return 0;
}