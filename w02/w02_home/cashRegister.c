


//==============================================
// Name:           Nguyen Thi Thuy Trang
// Student Number: 131104192
// Email:          tnguyen-thi-thuy@myseneca.ca
// Section:        NLL
// Workshop:       2 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Paste your in-lab code below and upgrade it to the at-home specifications
#include <stdio.h>

	int main(void)
	{
		double amt, GST, balanceowing, balanceowing_loonies, balanceowing_quarters, balanceowing_dimes, balanceowing_nickels, balanceowing_pennies;
		int loonies, quarters, dimes, nickels, pennies;
		int sub_balanceowing, sub_loonies, sub_balanceowing_loonies, sub_quarters, amountcents;

		printf("Please enter the amount to be paid: $");
		scanf("%lf", &amt);

		//Display GST and balance owing
		GST = amt * .13 + .005;
		printf("GST: %.2lf\n", GST);
		balanceowing = amt + GST;
		printf("Balance owing: $%.2lf\n", balanceowing);

		//For loonies, quarters, using 'dollar' unit
		loonies = balanceowing;//How many Loonies are required. 1 Loonie = 1 dollar
		sub_balanceowing = balanceowing * 100;
		sub_loonies = loonies * 100;
		balanceowing_loonies = (double)(sub_balanceowing % sub_loonies) / 100;
		printf("Loonies required: %d, balance owing $%.2lf\n", loonies, balanceowing_loonies);

		
		quarters = (balanceowing_loonies * 100) / 25;//How many Quarters are required. 1 Quarter = 0.25 dollar
		sub_balanceowing_loonies = balanceowing_loonies * 100;
		sub_quarters = quarters * 0.25 * 100;
		balanceowing_quarters = (double)(sub_balanceowing_loonies % sub_quarters) / 100;
		printf("Quarters required: %d, balance owing $%.2lf\n", quarters, balanceowing_quarters);

		//For dimes, nickels and pennies, using the 'cents' unit
		amountcents = balanceowing_quarters * 100;//Transfer the amount to cents
		dimes = amountcents / 10;//How many dimes are required? 1 dime = 10 cents
		balanceowing_dimes = (double)(amountcents % 10)/100;
		printf("Dimes required: %d, balance owing $%.2lf\n", dimes, balanceowing_dimes);

		amountcents = balanceowing_dimes * 100;//Transfer the amount to cents
		nickels= amountcents / 5;//How many nickels are required? 1 nickel = 5 cents
		balanceowing_nickels = (double)(amountcents% 5)/100;
		printf("Nickels required: %d, balance owing $%.2lf\n", nickels, balanceowing_nickels);

		amountcents = balanceowing_nickels * 100;//Transfer the amount to cents
		pennies = amountcents;//How many pennies are required? 1 pennie = 1 cent
		balanceowing_pennies = (double)(amountcents % 1) / 100;
		printf("Pennies required: %d, balance owing $%.2lf\n", pennies, balanceowing_pennies);
		
		return 0;

	}



