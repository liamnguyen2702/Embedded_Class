#include <stdio.h>
#include <string.h>
#include <math.h>

// int calculate()
// {

// }

void firstEquation(char *eqt)
{
    int a, b;
    char o;
    int i;

    for (i = 0; i < strlen(eqt); i++)
    {
        if (eqt[i] == 'x')
        {
            a = eqt[i - 1] - '0';
            o = eqt[i + 2];
        }
        else if (eqt[i] == '=')
            b = eqt[i - 2] - '0';
    }

    switch (o)
    {
    case '-':
        printf("x = %.1f", (float)b / a);
        break;

    case '+':
        printf("x = %.1f", (float)-b / a);
        break;
    }
}

void quadraticEquation(char *eqt)
{
    float a, b, c, delta, x1, x2;
    char o, l;
    int i;

    for (i = 0; i < strlen(eqt); i++)
    {
        if (eqt[i] == '^')
            a = eqt[i - 2] - '0';
        else if (eqt[i] == 'x' && i > 5)
        {
            if (eqt[i - 3] == '-')
                b = -(eqt[i - 1] - '0');
            else if (eqt[i - 3] == '+')
                b = eqt[i - 1] - '0';
        }
        else if (eqt[i] == '=')
        {
            if (eqt[i - 4] == '-')
                c = -(eqt[i - 2] - '0');
            else if (eqt[i - 4] == '+')
                c = eqt[i - 2] - '0';
        }
    }

    if (eqt[1] == '^')
        a = 1;
    if (eqt[0] == '-')
        a = a * (-1);

    printf("a = %.2f\tb = %.2f\t c = %.2f\n", a, b, c);
    delta = pow(b, 2) - 4 * a * c;

    // printf("%f\n", delta);

    if (delta > 0)
    {
        x1 = (-b - sqrt(delta)) / (2 * a);
        x2 = (-b + sqrt(delta)) / (2 * a);
        printf("The equation has 2 distinct solutions:\nx1 = %.2f\tx2 = %.2f", x1, x2);
    }
    else if (delta == 0)
    {
        x1 = -b / (2 * a);
        printf("The equation has double solutions: x1 = x2 = %.2f", x1);
    }
    else
        printf("The equation has no solution!");
}

int check(char *eqt)
{
    int i;
    for (i = 0; i < strlen(eqt); i++)
    {
        if (eqt[i] == '^')
        {
            quadraticEquation(eqt);
            return;
        }
    }

    firstEquation(eqt);
}

int main()
{
    char arr[100];

    printf("Enter your eqution: ");
    fgets(arr, sizeof(arr), stdin);

    check(arr);

    return 0;
}
