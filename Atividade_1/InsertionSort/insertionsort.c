#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

void insertionSort(int array[], int n)
{
    int i, key, j;

    for(i = 1; i < n; i++)
    {
        key = array[i];
        j = i - 1;
        while(j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
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

int main()
{
    int array[SIZE];
    srand(time(NULL));  // Corrigido aqui

    for(int i = 0; i < SIZE; i++)
    {
        array[i] = rand() % 100;
    }

    printf("\n Vetor nao ordenado: \n");
    exibir(array, SIZE);

    insertionSort(array, SIZE);

    printf("\n Vetor ordenado pelo Insertion Sort: \n");
    exibir(array, SIZE);

    return 0;
}
