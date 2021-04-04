//FT. FILESYSTEM ::: ITERATION 2.0
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <vector>
#include <string>
#include <conio.h>

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
    std::ofstream out_dbFile;
    std::ifstream in_dbFile;
    boolean isValid;

    string dbFileName;
    string yn;
    int item_ID = 0;

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
        dbFileName = "dbFile";
        out_dbFile.open((dbFileName + ".txt"), std::ios::app);
    }
    else
    {
        cout << "Enter DATABASE File Name [w/out .txt] : ";
        cin >> dbFileName;
        Sleep(1250);
        system("CLS");
        out_dbFile.open((dbFileName + ".txt"), std::ios::app);
    }

    if (out_dbFile.is_open())
    {
        cout << "Connected to DATABSE File Successfully.." << endl;
        Sleep(1450);
        system("CLS");
    }
    else
    {
        cerr << "ERROR :: Unable to Connect to DATABASE"; //CERR USED INSTEAD OF COUT
        Sleep(3000);
        system("CLS");
    }

    //TEST OUTSTREAM                                                   ::: PASSED :::
    //out_dbFile << "DATABASE MANAGEMENT" << endl;
    out_dbFile.close();

    in_dbFile.open((dbFileName + ".txt"), std::ios::app); //RECIEVING ID FROM LIST
    string fileItem;
    while (getline(in_dbFile, fileItem))
    {
        string stringLine = fileItem; //BUG
        char charLine[100];           //stringLine.length() inside charLine[] not required, DynamicAlloc                    //BUG
        strcpy(charLine, stringLine.c_str());
        int readID = atoi(charLine); //BUG
        //if (readID >= 0 || readID <= 100)
        //{ //BUG
            /*cout << endl
                 << readID << endl;
            _getch();*/ //TESTING, NOT REQUIRED
            item_ID = readID; //BUG
        //}
    }
    in_dbFile.close();

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
            while (true)
            {
                int choice = mainObj.menuValidation(7, 1);
                switch (choice)
                {

                case 1:
                {
                    out_dbFile.open((dbFileName + ".txt"), std::ios::app);
                    vector<string> bookDataVector; // ::: REMINDER ::: STUDY VECTORS
                    system("CLS");
                    int id;
                    string id_string, name, author, category;
                    cout << "__ADDING NEW ITEM__" << endl;

                    cout << "\nID : " << item_ID << endl;
                    cout << "NAME : ";
                    cin.ignore();
                    getline(cin, name);    
                    cout << "AUTHOR NAME : ";
                    getline(cin, author);
                    cout << "CATEGORY : ";
                    getline(cin, category);
                    //cin.ignore();

                    id_string = to_string(item_ID);
                    bookDataVector.push_back(id_string);
                    bookDataVector.push_back(name);
                    bookDataVector.push_back(author);
                    bookDataVector.push_back(category);

                    //out_dbFile << to_string(id) << endl; //CAN'T PLACE INT TYPE IN VECTOR<STRING>
                    for (string item : bookDataVector)
                    {
                        out_dbFile << item << endl;
                    }
                    out_dbFile << endl;
                    out_dbFile.close(); //IMPORTANT
                                        //TEST OUTSTEAM

                    item_ID++;
                    cout << "\n\nUpdating DATABASE...";
                    Sleep(1450);
                    system("CLS");
                    break;
                }
                case 2:
                {
                    system("CLS");
                    cout << "READING FROM " << dbFileName << "..." << endl;
                    Sleep(1250);
                    in_dbFile.open(dbFileName + ".txt");
                    string fileItem; //REPITITIVE MUTABLE STRING ?? MOVE OUT OF SWITCH CASE INTO WHILE(TRUE) TO MAKE GLOBALLY AVAIABLE INSIDE SWITCH CASE

                    /*getline(in_dbFile, fileItem); //DID NOT READ ENTIRE LINE !
                while (!in_dbFile.eof())
                {
                    cout << fileItem << endl; //SPITS OUT
                    in_dbFile >> fileItem;    //STRANGE BEHAVIOUR ::: CHECK WITH DEBUGGER //WARNING ::::::: MUTABLE TYPE (STRING) OVERWRITTEN ?
                }*/

                    unsigned int lineNumber = 0; //unsigned = positive int
                    while (getline(in_dbFile, fileItem))
                    {
                        cout << "[" << lineNumber << "] " << fileItem << endl;
                        lineNumber++;
                    }

                    in_dbFile.close(); //IMPORTANT
                    cout << "\nEnter any Key to Continue..";
                    _getch();
                    system("CLS");
                    break;
                }
                case 7:
                    //Repeat
                    break;

                case 0:
                    exit(3);

                default:
                    break;
                }
                if(choice == 7){
                    break;
                }
            }
        }
        else
        {
            while (true)
            {   
                int choice = mainObj.menuValidation(5, 2);
                switch (choice)
                {
                case 5:
                    //Repeat
                    break;
                case 0:
                    exit(3);

                default:
                    break;
                }
                if(choice == 5){
                    break;
                }
            }
        }
    }

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