//FT. FILESYSTEM
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

//Prototypes

//Classes
class MenuClass
{

private:
    void printInventoryMenu()
    {
        cout << "\t___INVENTORY MENU___" << endl;
        cout << "[1] addProduct()" << endl;
        cout << "[2] displayProducts()" << endl;
        cout << "[3] categoryFilter()" << endl;
        cout << "[4] updateProduct()" << endl;
        cout << "[5] sortProduct()" << endl; //SORT ON AVAILABLE QTY
        cout << "[6] deleteproduct()" << endl;
        cout << "[7] mainMenu()" << endl;
        cout << "[0] exit()";
    }

    void printTransactionMenu()
    {
        cout << "\t___TRANSACTION MENU___" << endl;
        cout << "[1] addPurchase()" << endl;
        cout << "[2] viewPurchase()" << endl;
        cout << "[3] sortPurchase()" << endl;
        cout << "[4] purchaseDetails()" << endl;
        cout << "[5] mainMenu()" << endl;
        cout << "[0] exit()";
    }

public:
    MenuClass() // ... :::: PRIVATE CLASS :::: ...
    {
        cout << "Menu Class Object Created Successfully..\n";
        Sleep(1450);
    }

    int menuValidation(int maxValue, int menu)
    {
        {
            int choice = 0;
            boolean isValid = false;

            do
            {
                isValid = true;
                if (menu == 1)
                {
                    printInventoryMenu();
                }
                else
                {
                    printTransactionMenu();
                }
                cout << "\nChoice : ";
                cin >> choice;

                if (choice < 0 || choice > maxValue)
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
};

//Main method

int main()
{
    system("CLS");
    std::ofstream dbFile;
    boolean isValid;

    string yn;

    int chances = 4;
    do
    {

        isValid = true;
        cout << "Would you Like to Open Default DATABASE ? [y/N]...  ";
        cin >> yn;
        //getline(cin,yn); cin.ignore();

        if (yn != "Y" && yn != "y" && yn != "N" && yn != "n")
        {
            isValid = false;
            if (chances < 2)
            {
                cout << "INVALID FILE NAME AFTER 3 TRIES, PROGRAM WILL EXIT NOW..";
                exit(3);
            }
            cout << "\nINVALID INPUT, USE : 'Y', 'y', 'N', 'n'" << endl;
            chances--;
            cout << "PROGRAM WILL EXIT AFTER [" << chances << "] TRIES !";
            Sleep(3000);
            
        }
        system("CLS");
    } while (isValid == false);

    if (yn == "Y" || yn == "y")
    {
        dbFile.open("dbFile.txt", std::ios::app);
    }
    else
    {
        string dbFileName;
        cout << "Enter DATABASE File Name [w/out .txt] : ";
        cin >> dbFileName;
        Sleep(1250);
        system("CLS");
        dbFile.open((dbFileName+".txt"), std::ios::app);
    }

    if (dbFile.is_open())
    {
        cout << "Connected to DATABSE File Successfully.." << endl;
        Sleep(1450);
        system("CLS");
    }
    else
    {
        cout << "ERROR :: Unable to Connect to DATABASE";
        Sleep(3000);
        system("CLS");
    }

    dbFile << "DATABASE FILE GENERATED" << endl;

    vector<string> names;
    names.push_back("OT");
    names.push_back("Allan");

    for (string name : names)
    {
        dbFile << name << endl;
    }

    MenuClass mainObj;
    //boolean isValid;

    while (true)
    {
        int choice = 0;

        do
        {
            isValid = true;
            system("CLS");
            cout << "__WELCOME TO BOOK-O-MATRIX__" << endl;
            cout << "[1] INVENTORY MANAGEMENT" << endl;
            cout << "[2] TRANSACTION MANAGEMENT" << endl;
            cout << "\nOPTION : ";
            cin >> choice;
            if (choice < 1 || choice > 2)
            {
                cout << "\nINVALID SUB-SYSTEM SELECTED, TRY AGAIN..";
                Sleep(2250);
                isValid = false;
            }
        } while (isValid == false);

        cout << "\n\nREDIRECTING TO SUB-SYSTEM...";
        Sleep(1500);
        system("CLS");

        if (choice == 1)
        {
            switch (mainObj.menuValidation(7, 1))
            {
            case 7:
                //Repeat
                break;

            case 0:
                exit(3);

            default:
                break;
            }
        }
        else
        {
            switch (mainObj.menuValidation(5, 2))
            {
            case 5:
                //Repeat
                break;
            case 0:
                exit(3);

            default:
                break;
            }
        }
    }

    dbFile.close();
    return 0;
}

//FUNCITONS TO BE ADDED

// ::: INVENTORY MENU :::

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