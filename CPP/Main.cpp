//FT. FILESYSTEM  ::: ITERATION 3.0
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <vector>
#include <string>
#include <conio.h>
#include <sstream>

using namespace std;

//Prototypes
string read_dbFileName_item_ID();
//void addProduct_CASE_1(string dbFileName, int item_ID);
//void displayProducts_CASE_2(string dbFileName);
void productSearch_CASE_3(string fileName);

//Classes
class MenuClass
{

private:
    void printInventoryMenu()
    {
        cout << "\t___INVENTORY MENU___" << endl;
        cout << "[1] addProduct()" << endl;
        cout << "[2] displayProducts()" << endl;
        cout << "[3] productSearch()" << endl;
        cout << "[4] categoryFilter()" << endl;
        cout << "[5] updateProduct()" << endl;
        cout << "[6] sortProduct()" << endl; //SORT ON AVAILABLE QTY
        cout << "[7] deleteproduct()" << endl;
        cout << "[8] mainMenu()" << endl;
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
class InventoryClass
{
private:
    string dbFileName;
    int item_ID;

public:
    InventoryClass(string dbFileName, int item_ID)
    {
        this->dbFileName = dbFileName;
        this->item_ID = item_ID;
    }

    int addProduct_CASE_1(string dbFileName, int item_ID)
    {
        ofstream out_dbFile;
        system("CLS");
        out_dbFile.open((dbFileName + ".txt"), std::ios::app);
        int write_QTY;
        string write_Name, write_Author, write_Category, temp_str_write_QTY;
        item_ID++;
        cout << "ID : " << item_ID << endl;
        cin.ignore(); // <-- SUSPECTED CAUSE : _GETCH() FROM LINE:162
        cout << "Name : ";
        getline(cin, write_Name);
        cout << "Author : ";
        getline(cin, write_Author);
        cout << "QTY : ";
        // cin >> write_QTY; //CRASHES ON NON-NUMERIC VALUE ::: FIXING :::
        while (getline(cin, temp_str_write_QTY))
        {
            stringstream getQTY(temp_str_write_QTY);
            if (getQTY >> write_QTY)
            {
                if (getQTY.eof())
                {
                    break;
                }
            }
            cout << "NON-NUMERIC INPUT DETECTED, TRY AGAIN...\n";
            cout << "QTY : ";
        }
        cout << "Category : ";
        cin.ignore();
        getline(cin, write_Category);

        vector<string> write_Line;

        string str_write_ID;
        str_write_ID = to_string(item_ID);

        string str_write_QTY;
        stringstream ss; // ^ CAN REFACTOR TO 2 LINES USING ABOVE METHOD ^
        ss << write_QTY;
        ss >> str_write_QTY;

        write_Line.push_back(str_write_ID);
        write_Line.push_back(write_Name);
        write_Line.push_back(write_Author);
        write_Line.push_back(str_write_QTY);
        write_Line.push_back(write_Category);

        int count = 1;
        for (string line : write_Line)
        {
            if (count == 5)
            {
                out_dbFile << line << endl;
            }
            else
            {
                out_dbFile << line << ",";
            }
            count++;
        }
        out_dbFile.close();

        cout << "\n\nUpdating DATABASE...";
        Sleep(1450);
        system("CLS");

        return item_ID;
    }

    void displayProducts_CASE_2(string dbFileName)
    {
        system("CLS");
        ifstream in_dbFile;
        in_dbFile.open((dbFileName + ".txt"), std::ios::app); //PRINTING ENTIRE FILE
        int read_ID, read_QTY;
        string str_read_ID, read_Name, read_Author, str_read_QTY, read_Category;
        string line;
        while (getline(in_dbFile, line))
        {
            stringstream strStream(line);
            getline(strStream, str_read_ID, ',');
            getline(strStream, read_Name, ',');
            getline(strStream, read_Author, ',');
            getline(strStream, str_read_QTY, ',');
            getline(strStream, read_Category);

            read_ID = stoi(str_read_ID);
            read_QTY = stoi(str_read_QTY);

            cout << endl
                 << read_ID << endl;
            cout << read_Name << endl;
            cout << read_Author << endl;
            cout << read_QTY << endl;
            cout << read_Category << endl;
        }
        in_dbFile.close();
        cout << "\nEnter any Key to Continue..";
        _getch();
        system("CLS");
    }
};

//Main method

int item_ID; //GLOBAL
int main()
{
    ifstream in_dbFile;
    ofstream out_dbFile;
    string dbFileName;
    string str_item_ID;

    stringstream get_readFile_getID(read_dbFileName_item_ID());
    getline(get_readFile_getID, dbFileName, ',');
    getline(get_readFile_getID, str_item_ID);

    stringstream conv_str_item_ID_to_item_ID;

    conv_str_item_ID_to_item_ID << str_item_ID;
    conv_str_item_ID_to_item_ID >> item_ID;

    InventoryClass inventoryClassObj(dbFileName, item_ID);

    bool isValid;
    MenuClass mainObj;

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
                int choice = mainObj.menuValidation(8, 1);
                switch (choice)
                {

                case 1:
                {
                    item_ID = inventoryClassObj.addProduct_CASE_1(dbFileName, item_ID);
                    break;
                }
                case 2:
                {
                    inventoryClassObj.displayProducts_CASE_2(dbFileName);
                    break;
                }
                case 3:
                    productSearch_CASE_3(dbFileName);
                    break;

                case 7:
                    //Repeat
                    break;

                case 0:
                    exit(3);

                default:
                    break;
                }
                if (choice == 7)
                {
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
                if (choice == 5)
                {
                    break;
                }
            }
        }
    }

    return 0;
}

//FUNCITONS TO BE ADDED

// ::: INVENTORY MENU :::

string read_dbFileName_item_ID()
{
    string return_dbFileName_item_ID;
    system("CLS");
    ofstream out_dbFile;
    ifstream in_dbFile;

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
        in_dbFile.open((dbFileName + ".txt"), std::ios::app);
    }
    else
    {
        cout << "Enter DATABASE File Name [w/out .txt] : ";
        cin >> dbFileName;
        Sleep(1250);
        system("CLS");
        in_dbFile.open((dbFileName + ".txt"), std::ios::app);
    }

    if (in_dbFile.is_open())
    {
        cout << "Connected to DATABSE File Successfully.." << endl;
        Sleep(990);
        cout << "Reading DATABASE, Grabbing item_ID.." << endl;

        string idLine;
        string str_tempID;
        int tempID = 0;
        // cout << endl          // NOT REQUIRED ::: DELETE ::: ONLY USED FOR TESTING
        //      << tempID;
        while (getline(in_dbFile, idLine))
        {
            stringstream getID(idLine); // ::: OVERWRITE getID OBJECT :::
            getline(getID, str_tempID, ',');
            stringstream conv; // ::: OVERWRITE conv OBJECT ::: --> IF FAIL : COUNT LINES, CREATE ARRAY OF OBJ
            conv << str_tempID;
            conv >> tempID;
            //tempID = stoi(str_tempID);
        }
        item_ID = tempID; //*

        // cout << "\n\ngrabbed tempID : " << tempID << endl;
        // cout << "targer item_ID : " << item_ID << endl;     // NOT REQUIRED ::: DELETE ::: ONLY USED FOR TESTING
        // _getch();

        Sleep(1450);
        system("CLS");
    }
    else
    {
        cerr << "ERROR :: Unable to Connect to DATABASE"; //CERR USED INSTEAD              OF COUT
        Sleep(3000);
        system("CLS");
    }

    in_dbFile.close();

    string str_itemID;

    stringstream conv_item_ID_to_str;

    conv_item_ID_to_str << item_ID;
    conv_item_ID_to_str >> str_itemID;

    return_dbFileName_item_ID = dbFileName + "," + str_itemID;

    return return_dbFileName_item_ID;
}

void productSearch_CASE_3(string fileName) // Combine with Categoryilter
{
    cin.ignore();
    system("CLS");
    string searchString;
    int searchID;
    bool use_searchID = true;
    bool matchFound;

    cout << "SEARCH [ID OR Name/Author] : ";
    getline(cin, searchString);

    stringstream searchStringStream(searchString);
    if (searchStringStream >> searchID)
    {
        if (searchStringStream.eof())
        {
            searchStringStream >> searchString;
        }
        else
        {
            use_searchID = false;
        }
    }
    else
    {
        use_searchID = false;
    }

    if (use_searchID == true)
    {
        ifstream in_dbFile;
        string line;
        int grabbedID;
        in_dbFile.open((fileName + ".txt"), std::ios::app);
        while (getline(in_dbFile, line))
        {
            stringstream pull_itemID(line);
            string str_itemID;
            int itemID;
            getline(pull_itemID, str_itemID, ',');
            grabbedID = stoi(str_itemID);
            if (searchID == grabbedID)
            {
                matchFound = true;
                break;
            }
            else
            {
                matchFound = false;
            }
        }
    }
    else
    {
        cout << "\nSEARCH BOOK_NAME / AUTHOR..." << endl;
    }

    if (use_searchID)
    {
        cout << "SEARCHING BY ID.." << endl;
        Sleep(500);
        if (matchFound)
        {
            cout << "MATCH FOUND !" << endl;
        }
        if (!matchFound)
        {
            cout << "SORRY! NO MATCH" << endl;
        }
    }
    cout << "\nEnter any Key to Continue..";
        _getch();
    system("CLS"); //MOVE TO MAIN MENU TO REFACTOR
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