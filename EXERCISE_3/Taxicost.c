#include <stdio.h>

float calculateCost(float km)
{
    float cost;

    if (km <= 1)
        cost = 14;
    else if (km <= 30)
        cost = (km - 1) * 10 + 14;
    else
        cost = 14 + 29 * 10 + (km - 30) * 8;
    return cost;
}

int main()
{
    float km = 1;

    printf("Cost = %.2f thousand dong\n", calculateCost(km));

    return 0;
}
