//==============================================
// Name:           Nguyen Thi Thuy Trang
// Student Number: 131104192
// Email:          tnguyen-thi-thuy@myseneca.ca
// Section:        NLL
// Workshop:       4 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:

#include <stdio.h>

int main(void)
{
    int day;
    int day_high[10], day_low[10];
    int i;
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
    return 0;
}



