#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

void amontoar(int array[], int n, int i)
{
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < n && array[esquerda] > array[maior])
    {
        maior = esquerda;
    }

    if (direita < n && array[direita] > array[maior])
    {
        maior = direita;
    }

    if (maior != i) 
    {
        swap(&array[i], &array[maior]);
        amontoar(array, n, maior);
    }
}

void heapsort(int arr[], int n) 
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        amontoar(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) 
    {
        swap(&arr[0], &arr[i]);
        amontoar(arr, i, 0);
    }
}

void exibir(int array[], int size) {
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(void) {
    int n = 50;  
    int array[n];

    srand(time(NULL));  

    for (int i = 0; i < n; i++)
    {
        array[i] = rand() % 100;
    }

    printf("Array original:\n");
    exibir(array, n);

    heapsort(array, n);
    
    printf("Array ordenado com Heapsort:\n");
    exibir(array, n);

    clock_t inicio = clock();  // Início do cronômetro

    heapsort(array, n);

    clock_t fim = clock();  // Fim do cronômetro

    printf("Array ordenado com Heapsort:\n");
    exibir(array, n);

    double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %.6f segundos\n", tempo_execucao);

    return 0;
}