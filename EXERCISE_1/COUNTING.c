#include <stdio.h>

int temp[32000];
int temp2[32000];

void count(int arr[], int length)
{

    int i;
    for (i = 0; i < length; i++)
    {
        if (arr[i] >= 0)
        {
            temp[arr[i]]++;
        }
        else
        {
            temp2[-arr[i]]++;
        }
    }

    for (i = 0; i < 32000; i++)
    {
        if (temp[i] != 0)
            printf("Value: %d appears %d times\n", i, temp[i]);
        if (temp2[i] != 0)
            printf("Value: %d appears %d times\n", -i, temp2[i]);
    }
}

int main()
{
    int arr[] = {4, -5, 7, 2, 9, 8, 3, 7, 4, 8, 5, 9, 6, -7, 4, 6, 4, 8, 5, -6, 8, 5, 6, 4};
    count(arr, sizeof(arr) / sizeof(arr[0]));
}
