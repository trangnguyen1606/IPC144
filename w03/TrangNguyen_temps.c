//==============================================
// Name:           Nguyen Thi Thuy Trang
// Student Number: 131104192
// Email:          tnguyen-thi-thuy@myseneca.ca
// Section:        NLL
// Workshop:       3 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#include<stdio.h>
#define NUMS 4

int main(void)
{
	int input_hightemp, input_lowtemp;
	int day;
	int value;
	int highest_temp = 0, lowest_temp = 0;
	int highesttemp_day = 0, lowesttemp_day = 0;
	float avelow = 0, avehigh = 0;

	printf("---=== IPC Temperature Analyzer ===---");
	for (day = 1; day <= NUMS; day++)
	{
		printf("\nEnter the high value for day %i: ",day);
		scanf("%i", &input_hightemp);
    do
    {
      printf("\nEnter the low value for day %i: ",day);
      scanf("%i", &input_lowtemp);
      if(input_hightemp<input_lowtemp || input_hightemp >=40 || input_lowtemp <=-40)
      {
        printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low\n");
        day -= 1;
        avehigh = avehigh - input_hightemp;//Return to the average high temperature before adding the high value
		avelow = avelow - input_lowtemp;//Return to the average low temperature before adding the low value
      }
      value=1;
    }while (value==0);		
    avehigh = avehigh + input_hightemp;
    avelow = avelow + input_lowtemp;
  
    /*Calculate the highest temperature and which day it occurs. Compare the recent input of high temperature with the previous one(s). The value of the previous one(s) is stored in a variable called highest_temp. If highest_temp < recent input, highest_temp will get the value of recent input and become highest again. If in the next inputtings, there are no numbers > highest_temp so highest_temp it will be the highest. When input passes its highest number to highest_temp, store the day of this incident to a new variable called highesttemp_day*/
		if (highest_temp < input_hightemp)
		{
			highest_temp = input_hightemp;
			highesttemp_day = day;
		}
		else if (highest_temp == 0)
		{
			highest_temp = input_hightemp;//if the first input <0 and users dont input any numbers >0, highest_temp will be zero. this code is to avoid this mistake
			highesttemp_day = day;
		}
		//Calculate the lowest temperature and which day it occurs. The logic is the same with the highest temperature
		if (lowest_temp > input_lowtemp)
		{
			lowest_temp = input_lowtemp;
			lowesttemp_day = day;
		}
		else if (lowest_temp == 0)
		{
			lowest_temp = input_lowtemp; //if the first input >0 and users dont input any numbers <0, lowest_temp will be zero. this code is to avoid this mistake
			lowesttemp_day = day;
		}
  }
	printf("\nThe average (mean) LOW temperature was: %.2f\n", avelow / (day-1));
	printf("The average (mean) HIGH temperature was: %.2f\n", avehigh / (day-1));
	printf("The average (mean) temperature was: %.2f\n", (avelow + avehigh) / ((day - 1) * 2));
	printf("The highest temperature was %d, on day %d\n", highest_temp, highesttemp_day);
	printf("The lowest temperature was %d, on day %d\n", lowest_temp, lowesttemp_day);
	return 0; 
}  