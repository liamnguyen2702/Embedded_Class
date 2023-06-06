#include <stdio.h>

int isEqual(char str1[], char str2[])
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
            return 0;
        i++;
    }
    return (str1[i] == '\0' && str2[i] == '\0');
}

void counter(char str[])
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }

    char words[100][100]; // Array to store words
    char word[100];
    int wordIndex = 0;
    int counts[100] = {0};
    int num_words = 0;

    int i;
    for (i = 0; i <= len; i++)
    {
        if (str[i] == ' ' || str[i] == ',' || str[i] == '\0' || str[i] == '.' || str[i] == '?' || str[i] == '!')
        {
            word[wordIndex] = '\0';

            if (wordIndex > 0)
            {
                int found = 0;
                int j;
                for (j = 0; j < num_words; j++)
                {
                    if (isEqual(word, words[j]))
                    {
                        counts[j]++;
                        found = 1;
                        break;
                    }
                }

                if (!found)
                {
                    for (j = 0; word[j] != '\0'; j++)
                    {
                        words[num_words][j] = word[j];
                    }
                    words[num_words][wordIndex] = '\0';
                    counts[num_words] = 1;
                    num_words++;
                }
            }

            wordIndex = 0;
        }
        else
        {
            word[wordIndex] = str[i];
            wordIndex++;
        }
    }
    for (i = 0; i < num_words; i++)
    {
        printf("The word: \"%s\" appears %d times.\n", words[i], counts[i]);
    }
}

int main()
{
    char str[] = "mot hai ba,  ba ba ba   ba bon, mot ba, bon, hai, mot";
    counter(str);
    return 0;
}
