//==============================================
// Name:           Nguyen Thi Thuy Trang
// Student Number: 131104192
// Email:          tnguyen-thi-thuy@myseneca.ca
// Section:        NLL
// Workshop:       2 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Start your code below:
#include<stdio.h>

int main(void)
{
	
	double amt,balanceowing_loonies,balanceowing_quarters;
	int loonies, quarters;

	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amt);
	
	//Display the loonies and balance owing
	loonies = amt;
	balanceowing_loonies = amt - loonies;
	printf("Loonies required: %d, balance owing $%.2lf\n", loonies, balanceowing_loonies);
	//Display the quarters and balance owing 
	quarters = balanceowing_loonies / 0.25;
	balanceowing_quarters = balanceowing_loonies - quarters*0.25;
	printf("Quarters required: %d, balance owing $%.2lf\n", quarters,balanceowing_quarters);
		
	return 0;
}
