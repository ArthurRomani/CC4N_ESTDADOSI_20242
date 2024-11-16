
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define SIZE 50

void troca(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int array[], int n)
{
    int i, j;
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(array[j] > array[j + 1])
            {
                troca(&array[j], &array[j + 1]);
            }
        }
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
    srand(time(NULL));

    for(int i = 0; i < SIZE; i++)
    {
        array[i] = rand() % 100;
    }

    printf("\n Vetor nao ordenado \n");
    exibir(array, SIZE);

    bubbleSort(array, SIZE);

    printf("\n Vetor ordenado pela funcao bubbleSort \n");
    exibir(array, SIZE);

    return 0;
}
