#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000

void porLinhas(double matriz[N][N], double vetor[N], double resultado[N]) {
    for (int i = 0; i < N; i++) {
        resultado[i] = 0;
        for (int j = 0; j < N; j++) {
            resultado[i] += matriz[i][j] * vetor[j];
        }
    }
}

void porColunas(double matriz[N][N], double vetor[N], double resultado[N]) {
    for (int i = 0; i < N; i++) {
        resultado[i] = 0;
    }
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            resultado[i] += matriz[i][j] * vetor[j];
        }
    }
}

double medirTempoLinhas(double matriz[N][N], double vetor[N], double resultado[N]) {
    clock_t inicio = clock();
    porLinhas(matriz, vetor, resultado);
    clock_t fim = clock();
    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

double medirTempoColunas(double matriz[N][N], double vetor[N], double resultado[N]) {
    clock_t inicio = clock();
    porColunas(matriz, vetor, resultado);
    clock_t fim = clock();
    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

int main() {
    static double matriz[N][N];
    static double vetor[N];
    static double resultado[N];
    
    for (int i = 0; i < N; i++) {
        vetor[i] = rand() % 10;
        for (int j = 0; j < N; j++) {
            matriz[i][j] = rand() % 10;
        }
    }
    
    double tempoLinhas = medirTempoLinhas(matriz, vetor, resultado);
    double tempoColunas = medirTempoColunas(matriz, vetor, resultado);
    
    printf("Tempo (acesso por linhas): %f segundos\n", tempoLinhas);
    printf("Tempo (acesso por colunas): %f segundos\n", tempoColunas);
    
    return 0;
}
