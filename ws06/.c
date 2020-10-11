//==============================================
// Name:           NGUYEN THI THUY TRANG
// Student Number: 131104192
// Email:          tnguyen-thi-thuy@myseneca.ca
// Section:        NLL
// Date:          
//==============================================
// Assignment:     1
// Milestone:      2
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:


int main(void)
{
    // Declare variables here:
    struct Name thename = {{'\0'}};
    struct Address theaddress = {0,{'\0'},0,{'\0'},{'\0'}};
    struct Numbers thenumbers = {{'\0'}};
    char yNo;

    // Display the title
    printf("Contact Management System\n");
    printf("-------------------------\n");

    // Contact Name Input:
    printf("Please enter the contact's first name: ");
    scanf("%30s%*c", thename.firstName);
    printf("Do you want to enter a middle initial(s)? (y or n): ");
    scanf("%c%*c", &yNo);
    if (yNo == 'y' || yNo == 'Y')
    {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]%*c", thename.middleInitial);
    }
    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]%*c", thename.lastName);

    // Contact Address Input:
    printf("Please enter the contact's street number: ");
    do
    {
        scanf("%d%*c", &theaddress.streetNumber);
    } while (theaddress.streetNumber < 0);
    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]%*c", theaddress.street);
    printf("Do you want to enter an apartment number? (y or n): ");
    scanf("%c%*c", &yNo);
    if (yNo == 'y' || yNo == 'Y')
    {
        printf("Please enter the contact's apartment number: ");
        do
        {
            scanf("%d%*c", &theaddress.apartmentNumber);
        } while (theaddress.apartmentNumber < 0);
    }
    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]%*c", theaddress.postalCode);
    printf("Please enter the contact's city: ");
    scanf("%40[^\n]%*c", theaddress.city);
    // Contact Numbers Input:
    printf("Do you want to enter a cell phone number? (y or n): ");
    scanf("%c%*c", &yNo);
    if (yNo == 'y' || yNo == 'Y')
    {
        printf("Please enter the contact's cell phone number: ");
        scanf("%10[^\n]%*c", thenumbers.cell);
    }
    printf("Do you want to enter a home phone number? (y or n): ");
    scanf("%c%*c", &yNo);
    if (yNo == 'y' || yNo == 'Y')
    {
        printf("Please enter the contact's home phone number: ");
        scanf("%10[^\n]%*c", thenumbers.home);
    }
    printf("Do you want to enter a business phone number? (y or n): ");
    scanf("%c%*c", &yNo);
    if (yNo == 'y' || yNo == 'Y')
    {
        printf("Please enter the contact's business phone number: ");
        scanf("%10[^\n]%*c", thenumbers.business);
    }
    printf("\n");
    // Display Contact Summary Details
    printf("Contact Details\n");
    printf("---------------\n");
    printf("Name Details:\n");
    printf("First name: %s\n", thename.firstName);
    printf("Middle initial(s): %s\n", thename.middleInitial);
    printf("Last name: %s\n", thename.lastName);
    printf("\n");
    printf("Address Details:\n");
    printf("Street number: %d\n", theaddress.streetNumber);
    printf("Street name: %s\n", theaddress.street);
    printf("Apartment: %d\n", theaddress.apartmentNumber);
    printf("Postal code: %s\n", theaddress.postalCode);
    printf("City: %s\n", theaddress.city);
    printf("\n");
    printf("Phone Numbers:\n");
    printf("Cell phone number: %s\n", thenumbers.cell);
    printf("Home phone number: %s\n", thenumbers.home);
    printf("Business phone number: %s\n", thenumbers.business);
    printf("\n");

    // Display Completion Message
    printf("Structure test for Name, Address, and Numbers Done!\n");

    return 0;
}
