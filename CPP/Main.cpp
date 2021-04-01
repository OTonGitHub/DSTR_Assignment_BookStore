#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

//Prototypes
void mainMenu();
int menuValidation(int choice);
void printInventoryMenu();
void printTransactionMenu();

//Main method
int main()
{
    mainMenu();
    return 0;
}

//Functions
void mainMenu()
{
    cout << "GITHUB BRANCH CHECK";
    cout << "Push to Main Branch";
    system("CLS");
    int choice;
    cout << "__WELCOME TO BOOK-O-MATRIX__" << endl;
    cout << "[1] INVENTORY MANAGEMENT" << endl;
    cout << "[2] TRANSACTION MANAGEMENT" << endl;
    cout << "\nOPTION : ";
    cin >> choice;

    if (choice == 1)
    {
        switch (menuValidation(choice))
        {
        case 7:
            mainMenu();
            break;

        default:
            break;
        }
    }
    else
    {
        switch (menuValidation(choice))
        {
        case 5:
            mainMenu();
            break;

        default:
            break;
        }
    }
    menuValidation(choice);
}

// ::: INVENTORY MENU :::
void printInventoryMenu()
{
    cout << "\t\n\n___INVENTORY MENU___" << endl;
    cout << "[1] addProduct()" << endl;
    cout << "[2] displayProducts()" << endl;
    cout << "[3] categoryFilter()" << endl;
    cout << "[4] updateProduct()" << endl;
    cout << "[5] sortProduct()" << endl; //SORT ON AVAILABLE QTY
    cout << "[6] deleteproduct()" << endl;
    cout << "[7] mainMenu()" << endl;
    cout << "[0] exit()";
}

int menuValidation(int choice)
{
    if (choice == 1)
    {
        int choice = 0;
        boolean isValid = false;

        do
        {
            isValid = true;
            printInventoryMenu();
            cout << "\nChoice : ";
            cin >> choice;

            if (choice < 0 || choice > 7)
            {
                cout << "INVALID OPTION, TRY AGAIN IN 3 SECONDS...";
                Sleep(3000);
                system("CLS");
                isValid = false;
            }

        } while (isValid == false);
        return choice;
    }
    else
    {

        int choice = 0;
        boolean isValid = false;

        do
        {
            isValid = true;
            printTransactionMenu();
            cout << "\nChoice : ";
            cin >> choice;

            if (choice < 0 || choice > 5)
            {
                cout << "INVALID OPTION, TRY AGAIN IN 3 SECONDS...";
                Sleep(3000);
                system("CLS");
                isValid = false;
            }

        } while (isValid == false);
        return choice;
    }
}

void addProduct()
{
}

void displayProducts()
{
}

void productSearch()
{
}

void categoryFilter()
{
}

void updateProduct()
{
}

void sortProduct()
{
}

void deleteProduct()
{
}

// ::: TRANSACTION MENU :::
void printTransactionMenu()
{
    cout << "\t\n\n___TRANSACTION MENU___" << endl;
    cout << "[1] addPurchase()" << endl;
    cout << "[2] viewPurchase()" << endl;
    cout << "[3] sortPurchase()" << endl;
    cout << "[4] purchaseDetails()" << endl;
    cout << "[5] mainMenu()" << endl;
    cout << "[0] exit()";
}

void addPurchase()
{
}

void viewPurchase()
{
}

void sortPurchase()
{
}

void purchaseDetails()
{
}