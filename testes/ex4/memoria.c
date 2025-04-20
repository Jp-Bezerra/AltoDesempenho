#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <sys/time.h>

#define tam 100000000

double tempoAtual() {
    struct timeval tempo;
    gettimeofday(&tempo, NULL);
    return tempo.tv_sec + tempo.tv_usec / 1000000.0;
}

int main(int argc, char *argv[]) {
    int numThreads = atoi(argv[1]);
    omp_set_num_threads(numThreads);

    double *vetor1 = malloc(sizeof(double) * tam);
    double *vetor2 = malloc(sizeof(double) * tam);
    double *vetor3 = malloc(sizeof(double) * tam);
    double *vetor4 = malloc(sizeof(double) * tam);
    double *vetorResultado = malloc(sizeof(double) * tam);

    for (int i = 0; i < tam; i++) {
        vetor1[i] = 1.0;
        vetor2[i] = 1.0;
        vetor3[i] = 1.0;
        vetor4[i] = 1.0;
    }

    double tempoInicio = tempoAtual();

    #pragma omp parallel for
    for (int i = 0; i < tam; i++) {
        vetorResultado[i] = vetor1[i] + vetor2[i] + vetor3[i] + vetor4[i];
    }

    double tempoFim = tempoAtual();
    printf("Tempo de execucao (limitado por memoria) com %d threads: %f segundos\n", numThreads, tempoFim - tempoInicio);

    free(vetor1);
    free(vetor2);
    free(vetor3);
    free(vetor4);
    free(vetorResultado);

    return 0;
}
