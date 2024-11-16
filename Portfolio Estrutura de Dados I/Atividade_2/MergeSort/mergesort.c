#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int array[], int esquerda, int meio, int direita)
{
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    int L[n1], R[n2];

    for(int i = 0; i < n1; i++)
    {
        L[i] = array[esquerda + i];
    }
    for(int j = 0; j < n2; j++)
    {
        R[j] = array[meio + 1 + j];
    }

    int i = 0, j = 0, k = esquerda;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    
    while(i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int array[], int esquerda, int direita)
{
    if(esquerda < direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;

        mergesort(array, esquerda, meio);
        mergesort(array, meio + 1, direita);

        merge(array, esquerda, meio, direita);
    }
}

void exibir(int array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(void)
{
    int n = 100000;  
    int array[n];

    srand(time(NULL));  
    

    for(int i = 0; i < n; i++)
    {
        array[i] = rand() % 100;
    }

    printf("Array original:\n");
    exibir(array, n);

    mergesort(array, 0, n - 1);

    printf("Array ordenado com mergesort:\n");
    exibir(array, n);

    clock_t inicio = clock();  // Início do cronômetro

    mergesort(array, 0, n - 1);

    clock_t fim = clock();  // Fim do cronômetro

    printf("Array ordenado com mergesort:\n");
    exibir(array, n);

    double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %.6f segundos\n", tempo_execucao);

    return 0;
}