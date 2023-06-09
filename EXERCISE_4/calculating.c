#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int charToInt(char c)
{
    return c - '0';
}

void deleteChar(char *eqt, int a, int b)
{
    int i;
    for (i = a - 1; i < b + 2; i++)
    {
        eqt[i] = ' ';
    }
}

int findOpenBrackets(char *eqt, int t) // Ham tim dau ngoac mo
{
    int length = strlen(eqt);

    int i;
    for (i = t; i < length; i++)
    {
        if (eqt[i] == '(')
        {
            t = i + 1;
            break;
        }
    }
    return t;
}

int findCloseBrackets(char *eqt, int t) // Ham tim dau ngoac dong
{
    int length = strlen(eqt);

    int i;
    for (i = t; i < length; i++)
    {
        if (eqt[i] == ')')
        {
            t = i - 1;
            break;
        }
    }
    return t;
}

char *cutString(char *eqt, int t1, int t2)
{
    int length = t2 - t1 + 1;
    char *temp = (char *)malloc((length + 1) * sizeof(char));
    int i;
    for (i = t1; i <= t2; i++)
    {
        temp[i - t1] = eqt[i];
    }
    temp[length] = '\0';
    // printf("%s\t", temp);
    return temp;
}

float sumCalculate(char *eqt)
{
    float izero = charToInt(eqt[0]);
    float ifour = charToInt(eqt[4]);

    float result = 0;
    char operator= eqt[2];
    switch (operator)
    {
    case '+':
        result = izero + ifour;
        return result;
        break;
    case '-':
        result = izero - ifour;
        return result;
        break;
    case '*':
        result = izero * ifour;
        return result;
        break;
    case '/':
        result = izero / ifour;
        return result;
        break;
    }
}

void insertFloatValue(char *input, float value, int position)
{
    char floatValue[6];
    snprintf(floatValue, sizeof(floatValue), " %.2f ", value);
    memmove(input + position + strlen(floatValue), input + position, strlen(input) - position + 1);
    strncpy(input + position, floatValue, strlen(floatValue));
}

float calculateExpression(char *expression)
{
    float result = 0.0;
    char operator= '\0';
    char *token = strtok((char *)expression, " ");

    while (token != NULL)
    {
        if (isdigit(token[0]))
        {
            float value = atof(token);
    
            if (operator== '*')
            {
                result *= value;
            }
            else if (operator== '/')
            {
                if (value != 0.0)
                {
                    result /= value;
                }
                else
                {
                    printf("Error: Division by zero.\n");
                    return 0.0;
                }
            }
            else
            {
                result = value;
            }
        }
        else
        {
            operator= token[0];
        }

        token = strtok(NULL, " ");
    }

    insertFloatValue(expression, result, operator);

    return result;
}

float priorityCalculate(char *eqt)
{
    int stop = 0;

    int t = 0;
    int b = findOpenBrackets(eqt, t);  // b: begin
    int e = findCloseBrackets(eqt, b); // e: end
    int d = findOpenBrackets(eqt, e);  // d: dau
    int c = findCloseBrackets(eqt, d); // c: cuoi

    char *ng1 = cutString(eqt, b, e);
    deleteChar(eqt, b, e);
    // eqt[b + 2] = ' '; // Delete the operator

    float parenthesis1 = sumCalculate(ng1);

    insertFloatValue(eqt, parenthesis1, b); // insert

    char *ng2 = NULL;
    if (d != 0 && c != 0)
    {
        ng2 = cutString(eqt, d + 6, c + 6);
        deleteChar(eqt, d + 6, c + 6);

        sumCalculate(ng2);
    }

    float parenthesis2 = ng2 != NULL ? sumCalculate(ng2) : 0.0;
    insertFloatValue(eqt, parenthesis2, d + 7);

    float result = 0;
    int i;
    int length = strlen(eqt);

    if (ng2 == NULL)
    {
        for (i = 0; i < length; i++)
        {
            if (eqt[i] == '*' || eqt[i] == '/')
            {
                float left = charToInt(eqt[i - 2]);
                float right = charToInt(eqt[i + 2]);
                char before = eqt[i - 2];
                char after = eqt[i + 2];

                if (eqt[i] == '*') // NHAN
                {
                    if (before != ')' && after != '(')
                        result = left * right;

                    else if (before == ')' && after != '(')
                        result = parenthesis1 * right;

                    else if (before != ')' && after == '(')
                        result = left * parenthesis1;

                    // eqt[i] = ' ';
                    printf("%.2f\n", result);
                    stop = i;

                    // printf("Dung ne: %d", stop);

                    break;
                }

                else // CHIA
                {
                    if (before != ')' && after != '(')
                        result = left / right;

                    else if (before == ')' && after != '(')
                        result = parenthesis1 / right;

                    else if (before != ')' && after == '(')
                        result = left / parenthesis1;

                    eqt[i] = ' ';

                    printf("%.2f\n", result);
                    stop = i;
                    // printf("Dung ne: %d", stop);
                    break;
                }
            }
        }
    }

    else if (ng2 != NULL)
    {
        for (i = 0; i < length; i++)
        {
            if (eqt[i] == '*' || eqt[i] == '/')
            {
                float left = charToInt(eqt[i - 2]);
                float right = charToInt(eqt[i + 2]);
                char before = eqt[i - 2];
                char after = eqt[i + 2];

                if (eqt[i] == '*') // NHAN
                {
                    if (before != ')' && after != '(')
                    {
                        eqt[strcspn(eqt, "\n")] = '\0';
                        result = calculateExpression(eqt);

                        // result = left * right;
                    }
                    else if (before == ')' && after != '(')
                    {
                        if (before == eqt[e + 1])
                            result = parenthesis1 * right;
                        else if (before == eqt[c + 1])
                            result = parenthesis2 * right;
                    }

                    else if (before != ')' && after == '(')
                    {
                        if (after == eqt[b - 1])
                            result = left * parenthesis1;
                        else if (after == eqt[d - 1])
                            result = left * parenthesis2;
                    }

                    else if (before == ')' && after == '(')
                        result = parenthesis1 * parenthesis2;

                    // eqt[i] = ' ';
                    printf("\t\t\t%s", eqt);
                    printf("\t%.2f\n", result); // 35
                    stop = i;
                    // printf("Dung ne: %d", stop);

                    break;
                }

                else
                {
                    if (before != ')' && after != '(')
                        result = left / right;

                    else if (before == ')' && after != '(')
                    {
                        if (before == eqt[e + 1])
                            result = parenthesis1 / right;
                        else if (before == eqt[c + 1])
                            result = parenthesis2 / right;
                    }

                    else if (before != ')' && after == '(')
                    {
                        if (after == eqt[b - 1])
                            result = left / parenthesis1;
                        else if (after == eqt[d - 1])
                            result = left / parenthesis2;
                    }

                    else if (before == ')' && after == '(')
                    {
                        result = parenthesis1 / parenthesis2;
                    }

                    eqt[i] = ' ';
                    printf("\t\t%.2f\n", result);
                    stop = i;
                    // printf("Dung ne: %d", stop);

                    break;
                }
            }
        }
    }

    return result;
}

int main()
{
    char arr[100];

    printf("Enter your equation: ");
    fgets(arr, sizeof(arr), stdin);

    float result = priorityCalculate(arr);
    printf("Result: %.2f\n", result);

    printf("%s", arr);
    return 0;
}
