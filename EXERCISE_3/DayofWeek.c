#include <stdio.h>

int day, month, year;

int isLeapyear(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                return 1;
            else
                return 0;
        }
        else
            return 1;
    }
    else
        return 0;
}

int input(int d, int m, int y)
{
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    long long int totalDays = 77;

    int i;
    for (i = 1583; i < year; i++)
    {
        if (isLeapyear(i))
            totalDays += 366;
        else
            totalDays += 365;
    }

    for (i = 0; i < month - 1; i++)
    {
        if (i == 1 && isLeapyear(year))
            totalDays += 29;
        else
            totalDays += daysInMonth[i];
    }

    totalDays += day;

    return (totalDays % 7);
}

void DayofWeek(int number)
{
    char *dayname;

    switch (number)
    {
    case 0:
        dayname = "Friday";
        break;
    case 1:
        dayname = "Saturday";
        break;
    case 2:
        dayname = "Sunday";
        break;
    case 3:
        dayname = "Monday";
        break;
    case 4:
        dayname = "Tuesday";
        break;
    case 5:
        dayname = "Wednesday";
        break;
    case 6:
        dayname = "Thursday";
        break;
    }
    printf("That day is: %s\n", dayname);
}

int main()
{
    printf("Enter the date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &day, &month, &year);

    DayofWeek(input(day, month, year));

    return 0;
}

