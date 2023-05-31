#include <stdio.h>

void print(char c[], int size)
{
    char tmp[size];

    int first = 0;
    int last = size - 2; //string style + one more character
    int i;
    int idx = 0;

    for (i = size; i >= 0; i--)
    {
        if (c[i] == ' ')
        {
            first = i + 1;

            int j;

            for (j = first; j <= last; j++)
            {
                tmp[idx++] = c[j];
            }

            tmp[idx++] = ' ';
            last = first - 2;
        }
    }

    int j;
    for (j = 0; j <= last; j++)
    {
        tmp[idx] = c[j];
        idx++;
    }
    printf("Output: \"%s\"\n", tmp);
}

int main()
{
    char c[] = "Chung toi da co gang het suc!";
    char size = sizeof(c) / sizeof(char);
    printf("Input: \"%s\"\n", c);
    print(c, size);
    return 0;
}
