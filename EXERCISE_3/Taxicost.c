#include <stdio.h>

float calculateCost(float distance)
{
    float cost;

    if (distance <= 1)
        cost = 14;
    else if (distance <= 30)
        cost = 14 + (distance - 1) * 10;
    else
        cost = 14 + 29 * 10 + (distance - 30) * 8;
    return cost;
}

int main()
{
    float distance = 41.5;

    printf("Cost = %.2f thousand dong\n", calculateCost(distance));

    return 0;
}
