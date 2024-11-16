#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particao(int array[], int menor, int maior) {
    int pivot = array[maior];
    int i = menor - 1;

    for (int j = menor; j < maior; j++) {
        if (array[j] <= pivot) {
            i++;
            troca(&array[i], &array[j]);
        }
    }
    troca(&array[i + 1], &array[maior]);
    return i + 1;
}

void QuickSort(int array[], int menor, int maior) {
    if (menor < maior) {
        int pi = particao(array, menor, maior);

        QuickSort(array, menor, pi - 1);
        QuickSort(array, pi + 1, maior);
    }
}

void exibir(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(void) {
    int n = 50;
    int array[n];
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        array[i] = rand() % 100;
    }

    printf("Array original:\n");
    exibir(array, n);

    // Medição do tempo de execução
    clock_t inicio = clock();
    QuickSort(array, 0, n - 1);
    clock_t fim = clock();

    printf("Array ordenado:\n");
    exibir(array, n);

    double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %.6f segundos\n", tempo_execucao);

    return 0;
}
