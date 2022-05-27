#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insertSort(int arr[], int n)
{
    int i, key, j;
    i = 1;
FOR:
    if (i < n)
    {
        key = arr[i];
        j = i - 1;
    WHILE:
        if ((j >= 0) && (arr[j] > key))
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            goto WHILE;
        }
        arr[j + 1] = key;
        i++;
        goto FOR;
    }
}
void printArray(int arr[], int n)
{
    int i = 0;
FOR:
    if (i < n)
    {
        printf("%d", arr[i]);
        i++;
        goto FOR;
    }
    printf("\n");
}
int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertSort(arr, n);
    printArray(arr, n);

    return 0;
}