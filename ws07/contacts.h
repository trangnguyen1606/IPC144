//==============================================
// Name:           Nguyen Thi Thuy Trang    
// Student Number: 131104192
// Email:          tnguyen-thi-thuy@myseneca.ca 
// Section:        NLL
// Date:           
//==============================================
// Assignment:     1
// Milestone:      4
//==============================================

// Structure type Name declaration (Milestone 1)
struct Name
{
    char firstName[31];
    char middleInitial[7];
    char lastName[36];
};

// Structure type Address declaration 
struct Address
{
    int streetNumber;
    char street[41];
    int apartmentNumber;
    char postalCode[8];
    char city[41];
};




// Structure type Numbers declaration
struct Numbers
{
    char cell[11];
    char home[11];
    char business[11];
};




// Structure type Contact declaration
struct Contact
{
    struct Name name;
    struct Address address;
    struct Numbers numbers;
};


//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// ====== Milestone 4 =======

// Get and store from standard input the values for Name
void getName(struct Name* name);


// Get and store from standard input the values for Address
void getAddress(struct Address* address);


// Get and store from standard input the values for Numbers
void getNumbers(struct Numbers* numbers);