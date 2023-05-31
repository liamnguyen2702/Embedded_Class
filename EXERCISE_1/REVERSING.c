#include <stdio.h>

void print(char c[], int size)
{
    char tmp[size];

    int dau = 0;
    int duoi = size - 2;
    int i;
    int idx = 0;

    for (i = size; i >= 0; i--)
    {
        if (c[i] == ' ')
        {
            dau = i + 1;
            int j;
            for (j = dau; j <= duoi; j++)
            {
                tmp[idx++] = c[j];
            }
            tmp[idx++] = ' ';
            duoi = dau - 2;
        }
    }
    int j;
    for (j = 0; j <= duoi; j++)
    {
        tmp[idx++] = c[j];
    }
    printf("output: \"%s\"\n", tmp);
}

int main()
{
    char c[] = "Chung toi da co gang het suc !";
    char size = sizeof(c) / sizeof(char);
    printf("input: \"%s\"\n", c);
    print(c, size);

    return 0;
}
