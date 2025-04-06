#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>

double calcularPi(int n) {
    double soma = 0.0;
    for (int k = 0; k < n; k++) {
        soma += (k % 2 == 0 ? 1.0 : -1.0) / (2 * k + 1);
    }
    return soma * 4.0;
}

int main() {
    int iteracoes[] = {1000, 10000, 100000, 1000000, 10000000, 100000000};
    int num_testes = sizeof(iteracoes) / sizeof(iteracoes[0]);

    for (int i = 0; i < num_testes; i++) {
        int n = iteracoes[i];
        clock_t inicio = clock();
        double pi_aproximado = calcularPi(n);
        clock_t fim = clock();

        double erro = fabs(M_PI - pi_aproximado);
        double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

        printf("Iteracoes: %d | pi aproximado: %.10f \n Erro: %e | Tempo: %.6f segundos\n\n", 
               n, pi_aproximado, erro, tempo);
    }

    return 0;
}
