//==============================================
// Name:           Nguyen Thi Thuy Trang
// Student Number: 131104192
// Email:          tnguyen-thi-thuy@myseneca.ca
// Section:        NLL
// Workshop:       4 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Place your code below
#include <stdio.h>

int main(void)
{
    int day;
    int day_high[10], day_low[10];
    int i;
    int highest = -100, lowest = 100, day_highest = 0, day_lowest = 0;
    int number;
    float total, average;
    printf("---=== IPC Temperature Calculator V2.0 ===---");
    day = printf("\nPlease enter the number of days, between 3 and 10, inclusive: ");
    scanf("%d", &day);
    while (day < 3 || day >10)
    {
        day = printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
        scanf("%d", &day);
        printf("\n");
    }
    for (i = 1; i <= day; i++)
    {
        day_high[i] = printf("Day %d - High: ", i);
        scanf("%d", &day_high[i]);
        day_low[i] = printf("Day %d - Low: ", i);
        scanf("%d", &day_low[i]);
    }
    for (i = 0; i <= day; i++)
    {
        if (i == 0)
        {
            printf("\nDay  ");
            printf("Hi  ");
            printf("Low\n");
        }
        else
        {
            printf("%d    ", i);
            printf("%d    ", day_high[i]);
            printf("%d\n", day_low[i]);
        }
    }
    //Find out the highest and lowest temp
    for (i = 1; i <= day; i++)
    {
        if (day_high[i] > highest)
        {
            highest = day_high[i];
            day_highest = i;
        }
        if (day_low[i] < lowest)
        {
            lowest = day_low[i];
            day_lowest = i;
        }
    }
    printf("\nThe highest temperature was %d, on day %d", highest, day_highest);
    printf("\nThe lowest temperature was %d, on day %d", lowest, day_lowest);
    printf("\n");
    //Calculate and display the average temperature for a period entered by the user, until he enters any negative value
    do
    {
        number = printf("\nEnter a number between 1 and 5 to see the average temperature for the entered number of days, enter a negative number to exit: ");
        scanf("%d", &number);
        if (number < 0)
        {
            printf("\nGoodbye!\n");
        }
        while (number > 5 || (number >= 0 && number < 1))
        {
            number = printf("\nInvalid entry, please enter a number between 1 and 5, inclusive: ");
            scanf("%d", &number);
        }
        if (number >= 1 && number <= 5)
        {
            average = 0;
            for (i = 1; i <= number; i++)
            {
                total = day_high[i] + day_low[i];
                average = average + total / (2 * number);
            }
            printf("\nThe average temperature up to day %d is: %.2f\n", number, average);
        }
    } while (number > 0);
    return 0;
}
