//==============================================
// Name:           Nguyen Thi Thuy Trang
// Student Number: 131104192
// Email:          tnguyen-thi-thuy@myseneca.ca
// Section:        NLL
// Workshop:       5 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 4    
// Declare Struct Employee 
struct Employee
{
    int ID, age;
    double salary;
};
/* main program */
int main(void)
{
    int option = 0;
    int i = 0, j;
    int inputID, value, k;
    struct Employee emp[SIZE] = { {0} };// and initialize all elements to zero  

    printf("---=== EMPLOYEE DATA ===---\n\n");

    do
    {
        printf("1. Display Employee Information\n");
        printf("2. Add Employee\n");
        printf("3. Update Employee Salary\n");
        printf("4. Remove Employee\n");
        printf("0. Exit\n\n");
        printf("Please select from the above options: ");

        scanf("%d", &option);
        printf("\n");

        switch (option)
        {
        case 0:
            printf("Exiting Employee Data Program. Good Bye!!!\n");
            break;
        case 1:
            printf("EMP ID  EMP AGE EMP SALARY\n");
            printf("======  ======= ==========\n");
            for (j = 0; j < SIZE; j++)
            {
                if (emp[j].ID > 0) 
                {
                    printf("%6d%9d%11.2lf\n", emp[j].ID, emp[j].age, emp[j].salary);
                }
                else
                    continue;//keep finding values whose ID > 0
            }
            printf("\n");
            break;
        case 2:
            printf("Adding Employee\n");
            printf("===============\n");
            // Check for limits on the array and add employee 
            if (i >= SIZE)
            {
                printf("ERROR!!! Maximum Number of Employees Reached\n");
            }
            else
            {
                emp[i].ID = printf("Enter Employee ID: ");
                scanf("%d", &emp[i].ID);
                emp[i].age = printf("Enter Employee Age: ");
                scanf("%d", &emp[i].age);
                emp[i].salary = printf("Enter Employee Salary: ");
                scanf("%lf", &emp[i].salary);
                i++;
            }
            printf("\n");
            break;
            // Expand the option list to include option 3 & 4 after 
            // "3. Update Employee Salary"
        case 3:
            printf("Update Employee Salary\n");
            printf("======================\n");
            do {
                value = 0; //keep the do-while loop working until inputing right ID
                printf("Enter Employee ID: ");
                scanf("%d", &inputID);
                for (k = 0; k < SIZE; k++)//check all ID if they match with inputID
                {
                    if (inputID == emp[k].ID)
                    {
                        printf("The current salary is %.2lf\n", emp[k].salary);
                        printf("Enter Employee New Salary: ");
                         scanf("%lf", &emp[k].salary);
                        printf("\n");
                        value = 1;// break do-while loop when finding out the matched ID
                        break;
                    }
                }
                if (value == 0)// if no IDs are matched, print Errors
                {
                    printf("*** ERROR: Employee ID not found! ***\n");
                }
            } while (value == 0);
            break;
            // "4. Remove Employee"
        case 4:
            printf("Remove Employee\n");
            printf("===============\n");
            do {
                value = 0;
                printf("Enter Employee ID: ");
                scanf("%d", &inputID);
                for (k = 0; k < SIZE; k++)
                {
                    if (inputID == emp[k].ID)
                    {
                        i = k;//assign the added values with the same position of the removed ones
                        printf("Employee %d will be removed\n\n", emp[k].ID);
                        emp[k].ID = 0;// after removing, this position will be zero (not be printed) while others in the array remain the same
                        value = 1;
                    }
                }
                if (value == 0)
                {
                    printf("*** ERROR: Employee ID not found! ***\n");
                }
            } while (value == 0);
            break;

        default:
            printf("ERROR: Incorrect Option: Try Again\n\n");
        }
    } while (option != 0);
    return 0;
}


