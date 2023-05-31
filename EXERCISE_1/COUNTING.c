#include <stdio.h>

int findMax(int arr[], int size)
{
    int max = arr[0];
    int i = 1;
    for (; i < size; i++)
    {
        max = arr[i] >= max ? arr[i] : max; //
    }
    return max;
}

int findMin(int arr[], int size)
{
    int min = arr[0];
    int i = 1;
    for (; i < size; i++)
    {
        min = arr[i] <= min ? arr[i] : min;
    }
    return min;
}

void count(int arr[], int length) // O(n)
{
    int i;

    int temp[findMax(arr, length)];
    int size2 = findMin(arr, length) < 0 ? -findMin(arr, length) : findMin(arr, length);
    int temp2[size2];

    for (i = 0; i < sizeof(temp) / sizeof(int); i++)
    {
        temp[i] = 0;
    }
    for (i = 0; i < sizeof(temp2) / sizeof(int); i++)
    {
        temp2[i] = 0;
    }

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

    for (i = 0; i < sizeof(temp) / sizeof(int); i++)
    {
        if (temp[i] != 0)
            printf("value: %d - appears %d tims\n", i, temp[i]);
    }
    for (i = 0; i < sizeof(temp2) / sizeof(int); i++)
    {
        if (temp2[i] != 0)
            printf("value: %d - appears %d tims\n", -i, temp2[i]);
    }
    printf("--------------------------\n");
}

int findMax2(char arr[], int size)
{
    int max = arr[0];
    int i = 1;
    for (; i < size; i++)
    {
        max = arr[i] >= max ? arr[i] : max;
    }
    return max;
}

void count2(char arr[], int length) // O(n)
{
    int i;

    int temp[findMax2(arr, length)];

    for (i = 0; i < sizeof(temp) / sizeof(int); i++)
    {
        temp[i] = 0;
    }

    for (i = 0; i < length; i++)
    {
        temp[arr[i]]++;
    }

    for (i = 0; i < sizeof(temp) / sizeof(int); i++)
    {
        if (temp[i] != 0)
            printf("value: %c - appears %d tims\n", i, temp[i]);
    }
}

int main()
{
    int arr[] = {4, 6, 5, 7, 4, 6, 4, 7, 5, 6, 4, 7, 8, 3, 6, 5, 7, 3, 6, 3, 5, 6, 5, 7, 5, 7, 3};
    count(arr, sizeof(arr) / sizeof(arr[0]));

    char arr2[] = "ljhsdlfkjhsdklajhlsdkajfhklsadf\n\n \u1234 bmncvxhskjdahfjklhsadfbnmhjksdljkhfsdafhjk";
    count2(arr2, sizeof(arr2) / sizeof(arr2[0]));
}

