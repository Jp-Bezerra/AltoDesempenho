#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000000

void inicializarVetor(double v[N]) {
    for (int i = 0; i < N; i++) {
        v[i] = i * 2.0 + 1.0;
    }
}

double somaAcumulativa(double v[N]) {
    double soma = 0.0;
    for (int i = 0; i < N; i++) {
        soma += v[i];
    }
    return soma;
}

double somaPipeline(double v[N]) {
    double s1 = 0.0, s2 = 0.0, s3 = 0.0, s4 = 0.0;

    for (int i = 0; i < N; i += 4) {
        s1 += v[i];
        s2 += v[i + 1];
        s3 += v[i + 2];
        s4 += v[i + 3];
    }

    return s1 + s2 + s3 + s4;
}

int main() {
    static double vetor[N];

    inicializarVetor(vetor);

    clock_t inicio = clock();
    double resultado1 = somaAcumulativa(vetor);
    clock_t fim = clock();
    double tempo1 = (double)(fim - inicio) / CLOCKS_PER_SEC;
    
    inicio = clock();
    double resultado2 = somaPipeline(vetor);
    fim = clock();
    double tempo2 = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Soma acumulativa: %f (Tempo: %f segundos)\n", resultado1, tempo1);
    printf("Soma com pipeline: %f (Tempo: %f segundos)\n", resultado2, tempo2);

    return 0;
}
