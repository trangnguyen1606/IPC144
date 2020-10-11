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


// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// -------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"



// -------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
void clearKeyboard(void)
{
    while (getchar() != '\n'); // empty execution code block on purpose
}


// pause:
void pause(void)
{
    printf("(Press Enter to Continue)");
    clearKeyboard();
}


// getInt:
int getInt(void)
{
    char NL = 'x';
    int value = 0;
    while (NL != '\n')
    {
        scanf("%d%c", &value, &NL);

        if (NL != '\n')
        {
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
            clearKeyboard();
        }

    }
    return value;
}


// getIntInRange:
int getIntInRange(int min, int max)
{
    int usr_integer = getInt();
    while (usr_integer < min || usr_integer > max)
    {
        printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
        usr_integer = getInt();
    }
    return usr_integer;
}

// yes:
int yes(void)
{
    char yNo = 'x', junk = 'x';
    int value;
    while (junk != '\n')
    {
        scanf(" %c%c", &yNo, &junk);
        if (junk != '\n')
        {
            printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
            clearKeyboard();
        }
        else if (yNo == 'y' || yNo == 'Y')
        {
            value = 1;
        }
        else if (yNo == 'n' || yNo == 'N')
        {
            value = 0;
        }
        else
        {
            junk = 'x';
        }
    }
    return value;
}


// menu:
int menu(void)
{
    int choice = 0;
    printf("Contact Management System\n");
    printf("-------------------------\n");
    printf("1. Display contacts\n");
    printf("2. Add a contact\n");
    printf("3. Update a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Search contacts by cell phone number\n");
    printf("6. Sort contacts by cell phone number\n");
    printf("0. Exit\n\n");
    printf("Select an option:> ");
    choice = getIntInRange(0, 6);
    printf("\n");
    return choice;
}


// contactManagerSystem:
void contactManagerSystem(void)
{
    struct Contact contacts[MAXCONTACTS] = {
  { {"Rick",{'\0'},"Grimes"},
    { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
    { "4161112222", "4162223333", "4163334444" } },
  {
    { "Maggie", "R.", "Greene" },
    { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
    { "9051112222", "9052223333", "9053334444" } },
  {
    { "Morgan", "A.", "Jones" },
    { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
    { "7051112222", "7052223333", "7053334444" } },
  {
    { "Sasha", {'\0'}, "Williams" },
    { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
    { "9052223333", "9052223333", "9054445555" } },
    };
    int done = 0;
    int options;

    while (done == 0)
    {
        options = menu();
        switch (options)
        {
        case 1:
            displayContacts(contacts,MAXCONTACTS);
            pause();
            break;
        case 2:
            addContact(contacts, MAXCONTACTS);
            pause();
            break;
        case 3:
            updateContact(contacts, MAXCONTACTS);
            pause();
            break;
        case 4:
            deleteContact(contacts, MAXCONTACTS);
            pause();
            break;
        case 5:
            searchContacts(contacts, MAXCONTACTS);
            pause();
            break;
        case 6:
            //sortContacts(contacts,MAXCONTACTS);
            printf("<<< Feature to sort is unavailable >>>\n\n");
            pause();
            break;
        case 0:
            printf("Exit the program? (Y)es/(N)o: ");
            if (yes() == 1) {
                printf("\nContact Management System: terminated");
                done = 1;
            }
        }
        printf("\n");
    }
}
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char phoneNum[])
{

    int needInput = 1;

    while (needInput == 1) {
        int i;
        scanf("%11[^\n]", phoneNum);
        clearKeyboard();
        //check if phoneNum contains special characters or letters
        for (i = 0; i < strlen(phoneNum) && needInput == 1; i++)// how to cut
        {
            if (phoneNum[i] <= 47 || phoneNum[i] >= 58)//check if phoneNum are out of number's range in ASCII table
            {
                needInput = 2; //using flag to stop the loop if a special character or letter is found
            }
            else
            {
                needInput = 1;//if no special character or letter is found, keep looping until the rest of the number 
            }
        }
        // (String Length Function: validate entry of 10 characters)

        if (strlen(phoneNum) == 10 && needInput == 1)// using needInput here to count the numbers only, not the mixtype like 222-222-22 which also has 10 characters
        {

            needInput = 0; // escape the loop
        }

        else //becareful with the {}
        {
            printf("Enter a 10-digit phone number: ");
            needInput = 1; // keep looping
        }
    }
}


// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
    int i;
    int found = -1;
    for (i = 0; i < size; i++)
    {
        if (strcmp(contacts[i].numbers.cell, cellNum) == 0)
        {
            found = i;
            i = size; 
        }
        else
        {
            found = -1;
        }
    }
    return found;
}

// displayContactHeader
void displayContactHeader(void)
{
    int i,j;
    char title[] = "Contacts Listing";
    for (i = 0; i < 3; i++)// using 2D array writing helps me to avoid mistakes and modify contents
    {
        for (j = 0; j < 79; j++)
        {
            if ((i == 0 || i == 2) && (j == 0 || j == 78))
            {
                printf("+");
            }
            else if ((i == 0 || i == 2) && (j > 0 || j < 78))
            {
                printf("-");
            }
            else if (i == 1 && j == 31)
            {
                printf("%s", title);
            }
            else if ((i == 1) && ((j>0 && j < 79 - strlen(title))))
            {
                printf(" ");
            }
            else if ((i == 1) && (j == 0 || j == 78))
            {
                printf("|");
            }
        }
        printf("\n");
    }
}

// displayContactFooter
void displayContactFooter(int count)
{
    int i;
    for (i = 0; i < 79; i++)
    {
        if (i == 0 || i == 78)
        {
            printf("+");
        }
        else
        {
            printf("-");
        }
    }
    printf("\n");
    printf("Total contacts: %d\n\n", count);
}

// displayContact:
void displayContact(const struct Contact* contact)
{
    printf(" %s ", contact->name.firstName);
    if (strlen(contact->name.middleInitial) != 0)//check if middleInitial exists
    {
        printf("%s ", contact->name.middleInitial);
    }
    printf("%s", contact->name.lastName);
    printf("\n");
    printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
    printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
    if (contact->address.apartmentNumber > 0)
    {
        printf("Apt# %d, ", contact->address.apartmentNumber);
    }
    printf("%s, %s\n",contact->address.city,contact->address.postalCode);
}

// displayContacts:
void displayContacts(const struct Contact contacts[], int size)
{
    displayContactHeader();
    int i, count = 0;
    for (i = 0; i < size; i++)
    {
        if (strlen(contacts[i].numbers.cell) > 0)
        {
            displayContact(&contacts[i]);
            count++;
        }
    }
    displayContactFooter(count);
}

// searchContacts:
void searchContacts(const struct Contact contacts[], int size)
{
    int position;
    char phoneNum[11];
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(phoneNum);
    position = findContactIndex(contacts, size, phoneNum);
    if (position != -1)
    {
        printf("\n");
        displayContact(&contacts[position]);
    }
    else
    {
        printf("*** Contact NOT FOUND ***\n");
    }
    printf("\n");
}

// addContact:
void addContact(struct Contact contacts[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (strlen(contacts[i].numbers.cell) == 0)
        {
            getContact(&contacts[i]);
            printf("--- New contact added! ---\n\n");
            i = size; //break
        }
        else if (i == size - 1)
        {
            printf("*** ERROR: The contact list is full! ***\n\n");
            i = size;
        }
    }
}

// updateContact:
void updateContact(struct Contact contacts[], int size)
{
    int position;
    char phoneNum[11];
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(phoneNum);
    position = findContactIndex(contacts, size, phoneNum);
    if (position == -1)
    {
        printf("*** Contact NOT FOUND ***\n");
    }
    else
    {
        printf("\nContact found:\n");
        displayContact(&contacts[position]);
        printf("\n");
        printf("Do you want to update the name? (y or n): ");
        if (yes() == 1)
        {
            getName(&contacts[position].name);
        }
        printf("Do you want to update the address? (y or n): ");
        if (yes() == 1)
        {
            getAddress(&contacts[position].address);
        }
        printf("Do you want to update the numbers? (y or n): ");
        if (yes() == 1)
        {
            getNumbers(&contacts[position].numbers);
        }
        printf("--- Contact Updated! ---\n");
    }
    printf("\n");
}

// deleteContact:
void deleteContact(struct Contact contacts[], int size)
{
    int position;
    char phoneNum[11];
    struct Contact tmp = { {"\0"} };
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(phoneNum);
    position = findContactIndex(contacts, size, phoneNum);
    if (position == -1)
    {
        printf("*** Contact NOT FOUND ***\n");
    }
    else
    {
        printf("\nContact found:\n");
        displayContact(&contacts[position]);
        printf("\n");
        printf("CONFIRM: Delete this contact? (y or n): ");
        if (yes() == 1)
        {
            contacts[position] = tmp;//assign null variables to delete the contacts 
            printf("--- Contact deleted! ---\n");
        }
    }
    printf("\n");
}
// sortContacts:
/*void sortContacts(struct Contact contacts[], int size)
{
    struct Contact sub;
    int i;
    int j;

    //Bubble Sort:
    for (i = size - 1; i > 0; i--) {
        for (j = 0; j < size; j++) {
            if (strcmp(contacts[j].numbers.cell, contacts[j + 1].numbers.cell) > 0) {
                sub = contacts[j];
                contacts[j] = contacts[j + 1];
                contacts[j + 1] = sub;
            }
        }
    }
    printf("--- Contacts sorted! ---\n\n");  
}*/
