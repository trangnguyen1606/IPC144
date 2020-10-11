//==============================================
// Name:           NGUYEN THI THUY TRANG
// Student Number: 131104192
// Email:          tnguyen-thi-thuy@myseneca.ca
// Section:        NLL
// Date:           
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "contacts.h"
#include "contactHelpers.h"
// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+



// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

// getName:
void getName(struct Name* name)
{

    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]", (*name).firstName);
    clearKeyboard();
    printf("Do you want to enter a middle initial(s)? (y or n): ");
    if (yes() == 1)
    {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]", (*name).middleInitial);
        clearKeyboard();
    }
    else {
        strcpy(name->middleInitial, "\0");
    }
    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]", (*name).lastName);
    clearKeyboard();
}

// getAddress:
void getAddress(struct Address* address)
{
    do
    {
        printf("Please enter the contact's street number: ");
        (*address).streetNumber = getInt();
        if ((*address).streetNumber <= 0)
        {
            printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
            (*address).streetNumber = getInt();
        }

    } while ((*address).streetNumber <= 0);

    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]", (*address).street);
    clearKeyboard();
    printf("Do you want to enter an apartment number? (y or n): ");
    if (yes() == 1)
    {
        do
        {
            printf("Please enter the contact's apartment number: ");
            (*address).apartmentNumber = getInt();
            if ((*address).apartmentNumber < 0)
            {
                printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
                (*address).apartmentNumber = getInt();
            }
        } while ((*address).apartmentNumber < 0);
    }
    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]", (*address).postalCode);// and be careful with number of chars, 8 will attach city's input
    clearKeyboard();
    printf("Please enter the contact's city: ");
    scanf("%40[^\n]", (*address).city);
    clearKeyboard();
}
// getNumbers:
void getNumbers(struct Numbers* numbers)
{       
    printf("Please enter the contact's cell phone number: ");
    getTenDigitPhone((*numbers).cell);
    printf("Do you want to enter a home phone number? (y or n): ");
    if (yes() == 1)
    {
        printf("Please enter the contact's home phone number: ");
        getTenDigitPhone((*numbers).home);
    }
    else {
        strcpy(numbers->home, "\0");//assign a value to null
    }
    printf("Do you want to enter a business phone number? (y or n): ");
    if (yes() == 1)
    {
        printf("Please enter the contact's business phone number: ");
        getTenDigitPhone((*numbers).business);
    }
    else {
        strcpy(numbers->business, "\0");
    }
}


// getContact:
void getContact(struct Contact* contact)
{
    getName(&(*contact).name);
    getAddress(&(*contact).address);
    getNumbers(&(*contact).numbers);
    return;
}