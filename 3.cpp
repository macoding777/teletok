#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

void insertionSortAsc(int arr[])
{
    int i, j, key;
    for (i = MAX - 2; i >= 0; i--)
    {
        key = arr[i];
        j = i + 1;
        while (j < MAX && key > arr[j])
        {
            arr[j - 1] = arr[j];
            j++;
        }
        arr[j - 1] = key;
    }
}

void insertionSortDesc(int arr[])
{
    int i, j, key;
    for (i = MAX - 2; i >= 0; i--)
    {
        key = arr[i];
        j = i + 1;
        while (j < MAX && key < arr[j])
        {
            arr[j - 1] = arr[j];
            j++;
        }
        arr[j - 1] = key;
    }
}

int main()
{
    int data_awal[MAX], data_asc[MAX], data_desc[MAX];
    int i;
    long t1, t2;

    printf("Data awal : \n");
    for (i = 0; i < MAX; i++)
    {
        srand(time(NULL) * (i + 1));
        data_awal[i] = rand() % 100 + 1;
        printf("%d ", data_awal[i]);
    }

    for (i = 0; i < MAX; i++)
    {
        data_asc[i] = data_awal[i];
        data_desc[i] = data_awal[i];
    }

    printf("\n\nHasil pengurutan ascending : \n");
    time(&t1);
    insertionSortAsc(data_asc);
    time(&t2);
    for (i = 0; i < MAX; i++)
        printf("%d ", data_asc[i]);
    printf("\nWaktu = %ld\n", t2 - t1);

    printf("\nHasil pengurutan descending : \n");
    time(&t1);
    insertionSortDesc(data_desc);
    time(&t2);
    for (i = 0; i < MAX; i++)
        printf("%d ", data_desc[i]);
    printf("\nWaktu = %ld\n", t2 - t1);

    return 0;
}
