#include <stdio.h>

int isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    else
        return 0;
}

int calculateDays(int day, int month, int year)
{
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    long long int totalDays = 0;

    int i;
    for (i = 1583; i < year; i++)
    {
        if (isLeapYear(i))
            totalDays += 366;
        else
            totalDays += 365;
    }

    for (i = 0; i < month - 1; i++)
    {
        if (i == 1 && isLeapYear(year))
            totalDays += 29;
        else
            totalDays += daysInMonth[i];
    }

    totalDays += day;

    return (totalDays % 7);
}

const char *getDayName(int dayOfWeek)
{
    const char *dayNames[] = {"Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};
    return dayNames[dayOfWeek];
}

int main()
{
    int day, month, year;

    printf("Enter the date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &day, &month, &year);
    
     if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1)
    {
        printf("Invalid date.\n");
        return 1;
    }

    int weekDays = calculateDays(day, month, year);
    const char *dayName = getDayName(weekDays);
    printf("That day is: %s\n", dayName);

    return 0;
}
