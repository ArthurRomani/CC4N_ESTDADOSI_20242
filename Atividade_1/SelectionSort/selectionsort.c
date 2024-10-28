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

void selectionSort(int array[], int n)
{
    int i, j, min;
    for(i = 0; i < n - 1; i++)
    {
        min = i;
        for(j = i + 1; j < n; j++)
        {
            if(array[j] < array[min])
            {
                min = j;
            }
        }
        troca(&array[min], &array[i]);
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

    selectionSort(array, SIZE);

    printf("\n Vetor ordenado poe Selection Sort \n");
    exibir(array, SIZE);

    return 0;
}
