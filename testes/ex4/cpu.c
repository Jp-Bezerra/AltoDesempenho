#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <sys/time.h>
#include <math.h>

#define tam 100000000

double tempoAtual() {
    struct timeval tempo;
    gettimeofday(&tempo, NULL);
    return tempo.tv_sec + tempo.tv_usec / 1000000.0;
}

int main(int argc, char *argv[]) {
    int numThreads = atoi(argv[1]);
    omp_set_num_threads(numThreads);

    double resultado = 0.0;
    double tempoInicio = tempoAtual();

    #pragma omp parallel for reduction(+:resultado)
    for (int i = 0; i < tam; i++) {
        double x = 1.0;
        for (int j = 0; j < 10; j++) {
            x = sin(x) * cos(x) + tan(x) + log(x + 1.0) + sqrt(x + 2.0) + exp(x / 100.0);
        }
        resultado += x;
    }

    double tempoFim = tempoAtual();
    printf("Resultado: %f\n", resultado);
    printf("Tempo de execucaoo (limitado por CPU) com %d threads: %f segundos\n", numThreads, tempoFim - tempoInicio);

    return 0;
}
