#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int arr[], int n)
{
    int i, j, min_p;
    for (i = 0; i < n-1; i++)
    {
        min_p = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_p])
                min_p = j;
        swap(&arr[min_p], &arr[i]);
    }
}

void print(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
   int arr[] = {4, 5, 7, 2, 9, 8, 3, 7, 4, 8, 5, 9, 6, 7, 4, 6, 4, 8, 5, 6, 8, 5, 6, 4};
   int n = sizeof(arr)/sizeof(arr[0]);
   sort(arr, n);

   print(arr, n);
   return 0;
}
