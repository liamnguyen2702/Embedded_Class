#include <stdio.h>
#include <string.h>
#include <math.h>
#include "function.h"

void firstEquation(char *eqt)
{
    int a = 0, b = 0;
    char o = '\0';
      
    unsigned int eqt_length = strlen(eqt);
    unsigned int i;

    for (i = 0; i < eqt_length; i++) {
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
    float a = 0, b = 0, c = 0, delta, x1, x2;
       
    unsigned int eqt_length = strlen(eqt);
    unsigned int i;

    for (i = 0; i < eqt_length; i++) {
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
    unsigned int eqt_length = strlen(eqt);
    unsigned int i;

    for (i = 0; i < eqt_length; i++) {
        if (eqt[i] == '^')
        {
            quadraticEquation(eqt);
            return 0;
        }
    }
    firstEquation(eqt);
    return 0;
}
