//PRESENTATION BRANCH
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <vector>
#include <string>
#include <conio.h>
#include <sstream>

using namespace std;

//Prototypes (commented are added to Class)
string read_dbFileName_item_ID();
string read_transFileName_trans_ID();
//void addProduct_CASE_1(string dbFileName, int item_ID);
//void displayProducts_CASE_2(string dbFileName);
void productSearch_CASE_3(string fileName);
void categoryFilter_CASE_4(struct MainDB_LinkedList_Node *head);
void updateProduct_CASE_5(struct MainDB_LinkedList_Node *head);
void sortProduct_CASE_6(struct MainDB_LinkedList_Node* head);
void deleteProduct_CASE_7(struct MainDB_LinkedList_Node* head);

void addPurchase_CASE_1();
void viewPurchase_CASE_2(string transFileName);
void sortPurchase_CASE_3(struct TransDB_LinkedList_Node* head);
void purchaseDetails_CASE_4();

//Nodes

//SORTED LINKED LIST
struct MainDB_Sort_LinkedList_Node{
    int item_ID;
    string title;
    string author;
    int qty;
    string category;

    struct MainDB_Sort_LinkedList_Node* link = NULL;
};

struct MainDB_Sort_LinkedList_Node* Sort_Head = NULL;
struct MainDB_Sort_LinkedList_Node* Sort_CurrentNode = NULL;
struct MainDB_Sort_LinkedList_Node* Sort_LastNode = NULL;
struct MainDB_Sort_LinkedList_Node* Sort_TempNode = NULL;

void insertEnd_v2_Sort(//Proprietary Naming Convention for Developers//Function Taken from Templates created by Ifhaam & Allan//PassByReference:D!Value
    struct MainDB_Sort_LinkedList_Node** headPtr,
    struct MainDB_Sort_LinkedList_Node** lastNodePtr,
    int item_ID,
    string title,
    string author,
    int qty,
    string category)

{
    struct MainDB_Sort_LinkedList_Node* Sort_CurrentNode = new  MainDB_Sort_LinkedList_Node;
    //CurrentNode = (struct MainDB_LinkedList_Node*)malloc(sizeof(MainDB_LinkedList_Node)); GIVES HUGE ERROR !
    Sort_CurrentNode->item_ID = item_ID;
    Sort_CurrentNode->title = title;
    Sort_CurrentNode->author = author;
    Sort_CurrentNode->qty = qty;
    Sort_CurrentNode->category = category;

    Sort_CurrentNode->link = NULL;

    if (*headPtr == NULL)
    {
        *headPtr = Sort_CurrentNode;
        *lastNodePtr = Sort_CurrentNode;
    }
    else
    {
        Sort_TempNode = *lastNodePtr;
        Sort_TempNode->link = Sort_CurrentNode;
        *lastNodePtr = Sort_CurrentNode;
    }
}

void Sort_PrintNode(struct MainDB_Sort_LinkedList_Node* head)
{
    struct MainDB_Sort_LinkedList_Node* reader = head;
    if (reader == NULL)
    {
        std::cout << "LinkedList Empty";
    }
    else
    {
        //reader = Head;
        while (reader != NULL)
        {
            cout << "Item ID : " << reader->item_ID << endl;
            cout << "Book Title : " << reader->title << endl;
            cout << "Author : " << reader->author << endl;
            cout << "QTY : " << reader->qty << endl;
            cout << "Category : " << reader->category << endl;
            cout << "----------------------------------" << endl;
            reader = reader->link;
        }
    }
}


//MAIN LINKED LIST

struct MainDB_LinkedList_Node {
    int item_ID;
    string title;
    string author;
    int qty;
    string category;

    struct MainDB_LinkedList_Node* link = NULL;
};


struct MainDB_LinkedList_Node* Head = NULL;
struct MainDB_LinkedList_Node* CurrentNode = NULL;
struct MainDB_LinkedList_Node* LastNode = NULL;
struct MainDB_LinkedList_Node* TempNode = NULL;

//LocalFunctions
void insertEnd_v2(//Proprietary Naming Convention for Developers//Function Taken from Templates created by Ifhaam & Allan//PassByReference:D!Value
    struct MainDB_LinkedList_Node** headPtr,
    struct MainDB_LinkedList_Node** lastNodePtr,
    int item_ID,
    string title,
    string author,
    int qty,
    string category)

{
    struct MainDB_LinkedList_Node* CurrentNode = new  MainDB_LinkedList_Node;
    //CurrentNode = (struct MainDB_LinkedList_Node*)malloc(sizeof(MainDB_LinkedList_Node)); GIVES HUGE ERROR !
    CurrentNode->item_ID = item_ID;
    CurrentNode->title = title;
    CurrentNode->author = author;
    CurrentNode->qty = qty;
    CurrentNode->category = category;

    CurrentNode->link = NULL;

    if (*headPtr == NULL)
    {
        *headPtr = CurrentNode;
        *lastNodePtr = CurrentNode;
    }
    else
    {
        TempNode = *lastNodePtr;
        TempNode->link = CurrentNode;
        *lastNodePtr = CurrentNode;
    }
}

void PrintNode(struct MainDB_LinkedList_Node* head)
{
    struct MainDB_LinkedList_Node* reader = head;
    if (reader == NULL)
    {
        std::cout << "LinkedList Empty";
    }
    else
    {
        //reader = Head;
        while (reader != NULL)
        {
            cout << "Item ID : " << reader->item_ID << endl;
            cout << "Book Title : " << reader->title << endl;
            cout << "Author : " << reader->author << endl;
            cout << "QTY : " << reader->qty << endl;
            cout << "Category : " << reader->category << endl;
            cout << "----------------------------------" << endl;
            reader = reader->link;
        }
    }
}


void CPY_dbFile_to_MainDB_LinkedList()
{
    system("CLS");
    ifstream in_dbFile;
    in_dbFile.open(("dbFile.txt"), std::ios::app); //PRINTING ENTIRE FILE
    int read_ID, read_QTY;
    string str_read_ID, read_Title, read_Author, str_read_QTY, read_Category;
    string line;


    int tempID = 1;
    while (getline(in_dbFile, line))
    {

        stringstream strStream(line);
        getline(strStream, str_read_ID, ',');
        getline(strStream, read_Title, ',');
        getline(strStream, read_Author, ',');
        getline(strStream, str_read_QTY, ',');
        getline(strStream, read_Category);


            stringstream conv; // ::: OVERWRITE conv OBJECT ::: --> IF FAIL : COUNT LINES, CREATE ARRAY OF OBJ
            conv << str_read_ID;
            conv >> read_ID;

            stringstream conv2; // ::: OVERWRITE conv OBJECT ::: --> IF FAIL : COUNT LINES, CREATE ARRAY OF OBJ
            conv << str_read_QTY;
            conv >> read_QTY;

        //read_ID = stoi(str_read_ID);
        //read_QTY = stoi(str_read_QTY);
        tempID = read_ID;

        insertEnd_v2(
            &Head,
            &LastNode,
            read_ID,
            read_Title,
            read_Author,
            read_QTY,
            read_Category);

    }
    in_dbFile.close();
    //system("CLS");
}

void CPY_MainDB_LinkedList_to_dbFile(struct MainDB_LinkedList_Node* head, string dbFileName) //pass Head as value head assign to printer //Realised can just use head
{//IMPORANT !!! CHANGE CODE TO ONLY SAVE WHATS NOT IN THE FILE ALREADY :)D
    ofstream out_dbFile;
    system("CLS");
    cout << "Writing LinkedList from RAM to Local Database..." << endl;
    //out_dbFile.open((dbFileName + ".txt"), std::ios::app);
    out_dbFile.open((dbFileName + ".txt"), std::ios::app);

    struct MainDB_LinkedList_Node* printer = head;
        //can add if statement to verify if changes were brought
        //reader = Head;

    //vector<string> write_Line;

    while (printer != NULL)
        {
            vector<string> write_Line;

            string str_write_ID = to_string(printer->item_ID);
            string write_Name = printer->title;
            string write_Author = printer->author;
            string str_write_QTY = to_string(printer->qty);
            /*
             string str_write_QTY;
            stringstream ss; // ^ CAN REFACTOR TO 2 LINES USING ABOVE METHOD ^
            ss << write_QTY;
            ss >> str_write_QTY;
            */
            string write_Category = printer->category;

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
            printer = printer->link;
        }
        out_dbFile.close();
        cout<<"Done..";
        Sleep(1450);
        system("CLS");
}

//TRANSACTION FILE NODE
struct TransDB_LinkedList_Node{
    int trans_ID;
    string title;
    string author;
    int qty;
    string category;

    struct TransDB_LinkedList_Node* link = NULL;
};

struct TransDB_LinkedList_Node* Trans_Head = NULL;
struct TransDB_LinkedList_Node* Trans_CurrentNode = NULL;
struct TransDB_LinkedList_Node* Trans_LastNode = NULL;
struct TransDB_LinkedList_Node* Trans_TempNode = NULL;

void insertEnd_v2_Trans(//Proprietary Naming Convention for Developers//Function Taken from Templates created by Ifhaam & Allan//PassByReference:D!Value
    struct TransDB_LinkedList_Node** headPtr,
    struct TransDB_LinkedList_Node** lastNodePtr,
    int item_ID,
    string title,
    string author,
    int qty,
    string category)

{
    struct TransDB_LinkedList_Node* Trans_CurrentNode = new  TransDB_LinkedList_Node;
    //CurrentNode = (struct MainDB_LinkedList_Node*)malloc(sizeof(MainDB_LinkedList_Node)); GIVES HUGE ERROR !
    Trans_CurrentNode->trans_ID = item_ID;
    Trans_CurrentNode->title = title;
    Trans_CurrentNode->author = author;
    Trans_CurrentNode->qty = qty;
    Trans_CurrentNode->category = category;

    Trans_CurrentNode->link = NULL;

    if (*headPtr == NULL)
    {
        *headPtr = Trans_CurrentNode;
        *lastNodePtr = Trans_CurrentNode;
    }
    else
    {
        Trans_TempNode = *lastNodePtr;
        Trans_TempNode->link = Trans_CurrentNode;
        *lastNodePtr = Trans_CurrentNode;
    }
}

void Trans_PrintNode(struct TransDB_LinkedList_Node* head)
{
    struct TransDB_LinkedList_Node* reader = head;
    if (reader == NULL)
    {
        std::cout << "LinkedList Empty";
    }
    else
    {
        //reader = Head;
        while (reader != NULL)
        {
            cout << "Transaction ID : " << reader->trans_ID << endl;
            cout << "Book Title : " << reader->title << endl;
            cout << "Author : " << reader->author << endl;
            cout << "QTY : " << reader->qty << endl;
            cout << "Category : " << reader->category << endl;
            cout << "----------------------------------" << endl;
            reader = reader->link;
        }
    }
}

void CPY_transFile_to_TransDB_LinkedList()
{
    system("CLS");
    ifstream in_transFile;
    in_transFile.open(("transFile.txt"), std::ios::app); //PRINTING ENTIRE FILE
    int read_ID, read_QTY;
    string str_read_ID, read_Title, read_Author, str_read_QTY, read_Category;
    string line;


    int tempID = 1;
    while (getline(in_transFile, line))
    {

        stringstream strStream(line);
        getline(strStream, str_read_ID, ',');
        getline(strStream, read_Title, ',');
        getline(strStream, read_Author, ',');
        getline(strStream, str_read_QTY, ',');
        getline(strStream, read_Category);

        read_ID = stoi(str_read_ID);
        read_QTY = stoi(str_read_QTY);
        tempID = read_ID;

        insertEnd_v2_Trans(
            &Trans_Head,
            &Trans_LastNode,
            read_ID,
            read_Title,
            read_Author,
            read_QTY,
            read_Category);

    }
    in_transFile.close();
    //system("CLS");
}

void CPY_TransDB_LinkedList_to_transFile(struct TransDB_LinkedList_Node* head, string dbFileName) //pass Head as value head assign to printer //Realised can just use head
{//IMPORANT !!! CHANGE CODE TO ONLY SAVE WHATS NOT IN THE FILE ALREADY :)D
    ofstream out_transFile;
    system("CLS");
    cout << "Writing LinkedList from RAM to Local Database..." << endl;
    //out_dbFile.open((dbFileName + ".txt"), std::ios::app);
    out_transFile.open((dbFileName + ".txt"));

    struct TransDB_LinkedList_Node* printer = head;
        //can add if statement to verify if changes were brought
        //reader = Head;

    //vector<string> write_Line;

    while (printer != NULL)
        {
            vector<string> write_Line;

            string str_write_ID = to_string(printer->trans_ID);
            string write_Name = printer->title;
            string write_Author = printer->author;
            string str_write_QTY = to_string(printer->qty);
            /*
             string str_write_QTY;
            stringstream ss; // ^ CAN REFACTOR TO 2 LINES USING ABOVE METHOD ^
            ss << write_QTY;
            ss >> str_write_QTY;
            */
            string write_Category = printer->category;

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
                out_transFile << line << endl;
                }
                else
                {
                    out_transFile << line << ",";
                }
                count++;
            }   
            printer = printer->link;
        }
        out_transFile.close();
        cout<<"\nSaving Transaction File..Done..";
        Sleep(1450);
        system("CLS");
}

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
        cout << "[0] Save Changes & exit()";
    }

    void printTransactionMenu()
    {
        cout << "\t___TRANSACTION MENU___" << endl;
        cout << "[1] addPurchase()" << endl;
        cout << "[2] viewPurchase()" << endl;
        cout << "[3] sortPurchase()" << endl;
        cout << "[4] purchaseDetails()" << endl;
        cout << "[5] mainMenu()" << endl;
        cout << "[0] Save Changes & exit()";
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
        system("CLS");
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
        //cin.ignore();
        getline(cin, write_Category);

        
            insertEnd_v2(
            &Head,
            &LastNode,
            item_ID,
            write_Name,
            write_Author,
            write_QTY,
            write_Category);

            cout << "\n\nUpdating DATABASE...";
            Sleep(1450);
            system("CLS");
            return item_ID;

    };
    
    void displayProducts_CASE_2(string dbFileName)
    {
        system("CLS");
        PrintNode(Head);
        cout << "\nEnter any Key to Continue..";
        _getch();
        system("CLS");
    }
        
    };

//Main method

int item_ID; //GLOBAL
int trans_ID; //GlOBAL

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

    //TRANSACTION FILE
    ifstream in_transFile;
    ofstream out_transFile;
    string transFileName;
    string str_trans_ID;

    stringstream get_readTransFile_getTransID(read_transFileName_trans_ID());
    getline(get_readTransFile_getTransID, transFileName,',');
    getline(get_readTransFile_getTransID, str_trans_ID);

    stringstream conv_str_trans_ID_to_trans_ID;

    conv_str_trans_ID_to_trans_ID << str_trans_ID;
    conv_str_trans_ID_to_trans_ID >> trans_ID;



    CPY_dbFile_to_MainDB_LinkedList();
    CPY_transFile_to_TransDB_LinkedList();

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

                case 4:
                {
                    categoryFilter_CASE_4(Head);
                    break;
                }

                case 5:
                {
                    updateProduct_CASE_5(Head);
                    break;
                }

                case 6:
                {
                    sortProduct_CASE_6(Head);
                    break;
                }

                case 7:
                {
                    deleteProduct_CASE_7(Head);
                    break;
                }

                case 0:
                    CPY_MainDB_LinkedList_to_dbFile(Head, dbFileName);
                    CPY_TransDB_LinkedList_to_transFile(Trans_Head, "transFile");
                    exit(3);

                default:
                    break;
                }
                if (choice == 8)
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
                case 1:
                    addPurchase_CASE_1();
                    break;

                case 2:
                    viewPurchase_CASE_2(transFileName);
                    break;

                case 3:
                    sortPurchase_CASE_3(Trans_Head);
                    break;

                case 4:
                    purchaseDetails_CASE_4();
                    break;

                case 0:
                    CPY_TransDB_LinkedList_to_transFile(Trans_Head, "transFile");
                    CPY_MainDB_LinkedList_to_dbFile(Head, dbFileName);
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

    //CPY_MainDB_LinkedList_to_dbFile(Head, dbFileName); Moved to SwitchCase (0){exit}
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

//READ TRANSACTION FILE
string read_transFileName_trans_ID()
{
    string return_transFileName_trans_ID;
    system("CLS");
    ofstream out_transFile;
    ifstream in_transFile;

    boolean isValid;
    string transFileName;
    int item_ID = 0;



        transFileName = "transFile";
        in_transFile.open((transFileName + ".txt"), std::ios::app);
    

        string idLine;
        string str_tempID;
        int tempID = 0;

        while (getline(in_transFile, idLine))
        {
            stringstream getID(idLine); // ::: OVERWRITE getID OBJECT :::
            getline(getID, str_tempID, ',');
            stringstream conv; // ::: OVERWRITE conv OBJECT ::: --> IF FAIL : COUNT LINES, CREATE ARRAY OF OBJ
            conv << str_tempID;
            conv >> tempID;
        }
        item_ID = tempID; //*

    in_transFile.close();

    string str_itemID;

    stringstream conv_item_ID_to_str;

    conv_item_ID_to_str << item_ID;
    conv_item_ID_to_str >> str_itemID;

    return_transFileName_trans_ID = transFileName + "," + str_itemID;

    return return_transFileName_trans_ID;
}
  


void productSearch_CASE_3(string fileName) // Combine with Categoryilter
{
    CPY_MainDB_LinkedList_to_dbFile(Head, fileName);
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

void categoryFilter_CASE_4(struct MainDB_LinkedList_Node *head)
{
    bool found = false;
    system("CLS");
    string categFilter;
    cout << "Enter Category Filter : ";
    cin >> categFilter;


    struct MainDB_LinkedList_Node* reader = head;
    Sleep(1450);
    if (reader == NULL)
    {
        std::cout << "LinkedList Empty";
    }
    else
    {
        while (reader != NULL)
        {
            if(reader->category == categFilter)
            {
                found = true;
            cout << "Item ID : " << reader->item_ID << endl;
            cout << "Book Title : " << reader->title << endl;
            cout << "Author : " << reader->author << endl;
            cout << "QTY : " << reader->qty << endl;
            cout << "Category : " << reader->category << endl;
            cout << "----------------------------------" << endl;
            }
            reader = reader->link;
        }
        if(found != true)
            {
                cout << "No such Category Found..";
            }
            cout<<"\nPress any key to continue..";
            _getch();
            system("cls");
    }

}

void updateProduct_CASE_5(struct MainDB_LinkedList_Node *head)
{
    bool found = false;
    system("CLS");
    string itemID;
    cout << "Enter Item ID to update Item : ";
    cin >> itemID;


    struct MainDB_LinkedList_Node* reader = head;
    Sleep(1450);
    if (reader == NULL)
    {
        std::cout << "LinkedList Empty";
    }
    else
    {
        while (reader != NULL)
        {
            if(reader->item_ID == stoi(itemID))
            {
                found = true;
            cout << "Item ID : " << reader->item_ID << endl;
            cout << "Book Title : " << reader->title << endl;
            cout << "Author : " << reader->author << endl;
            cout << "QTY : " << reader->qty << endl;
            cout << "Category : " << reader->category << endl;
            cout << "----------------------------------" << endl;

            cout << "What would you like to change ?" << endl;
            cout << "[1] Book Title" << endl;
            cout << "[2] Author" << endl;
            cout << "[3] QTY" << endl;
            cout << "[4] Category" << endl;

            int choice;
            cout << "Choice : ";
            cin >> choice;

            switch (choice)
            {
                case 1:
                {
                    string bookTitle;
                    cout << "New Book Title : ";
                    cin.ignore();
                    getline(cin, bookTitle);
                    reader->title = bookTitle;
                    //strcpy(reader->title,bookTitle); DID NOT WORK, NEEDS CHAR TO STR CONV
                    break;
                }

                case 2:
                {
                    string author;
                    cout << "New Author : ";
                    cin.ignore();
                    getline(cin,author);
                    reader->author = author;
                    //strcpy(reader->title,bookTitle); DID NOT WORK, NEEDS CHAR TO STR CONV
                    break;
                }

                case 3:
                {
                    int qty;
                    cout << "New QTY : ";
                    cin >> qty;
                    reader->qty = qty;
                    //strcpy(reader->title,bookTitle); DID NOT WORK, NEEDS CHAR TO STR CONV
                    break;
                }

                case 4:
                {
                    string category;
                    cout << "New Category : ";
                    cin.ignore();
                    getline(cin, category);
                    reader->category = category;
                    break;
                }

                default:
                {
                    break;
                }
            }
            }
            reader = reader->link;
        }
        if(found != true)
            {
                cout << "No such ID Found..";
            }else
            {
                cout << "\nChanges Applied..";
            }
            cout<<"\nPress any key to continue..";
            _getch();
            system("cls");
    }
}

void sortProduct_CASE_6(struct MainDB_LinkedList_Node* head)
{
    struct MainDB_LinkedList_Node* reader = head; // can refactor by removing line and initiating as reader instead of head
    if (reader == NULL)
    {
        std::cout << "LinkedList Empty"; 
    }
    else
    {
        while (reader != NULL)
        {
            //change to passbyValue//change to passbyValue
            insertEnd_v2_Sort
            (
                &Sort_Head, 
                &Sort_LastNode, 
                reader->item_ID,
                reader->title,
                reader->author,
                reader->qty,
                reader->category
            );
            reader = reader->link;
        }
    }
    
    
    struct MainDB_Sort_LinkedList_Node** h;
    int i, j, swapped;
    int count = item_ID - 1;

    for (i = 0; i <= count; i++)
    {
        h = &Sort_Head;
        swapped = 0;

        for(j = 0; j < count - i - 1; j++)
        {
            struct MainDB_Sort_LinkedList_Node* p1 = *h;
            struct MainDB_Sort_LinkedList_Node* p2 = p1->link;

            if (p1->qty > p2->qty)
            {
                struct MainDB_Sort_LinkedList_Node* tmp = p2->link;
                p2->link = p1;
                p1->link = tmp;
                *h = p2;
                
                swapped = 1;
            }

            h = &(*h)->link;
        }

        if (swapped == 0)
            break;
    }
    

    cout << "Sorted Linked List.." << endl;
    Sort_PrintNode(Sort_Head);

    cout << "\nPress any key to continue..";
    _getch();
    system("cls");
}

void deleteProduct_CASE_7(struct MainDB_LinkedList_Node* head)
{
    system("cls");
    int itemID;
    cout << "[Delete] Book ID : ";
    cin >> itemID;
    
    //can use switch case
    if (Head == NULL)
    {
        cout << "List Already Empty, Nothing to Delete.." << endl;
    }
    else if(itemID == 1)
    {
        if(Head->link == NULL)
        {
            free(Head);
            Head = NULL;
            item_ID--;
        }else
        {
            struct MainDB_LinkedList_Node* temp = Head;
            Head = Head->link;
            free(temp);
            temp = NULL; //because temp still contains invalid memory location of deleted node earlier using free()
        
            item_ID --;

            TempNode = Head;
            while(TempNode != NULL)
            {
                TempNode->item_ID--;
                TempNode = TempNode->link;
            }
        }
    }
    else if(itemID == LastNode->item_ID)
    {
        struct MainDB_LinkedList_Node* temp1 = Head;
        struct MainDB_LinkedList_Node* temp2 = Head;

        while(temp1->link != NULL)
        {
            temp2 = temp1;
            temp1 = temp1->link;
        }
        temp2->link = NULL;
        free(temp1);
        temp1 = NULL;

        item_ID--;

        TempNode = Head;
            while(TempNode != NULL)
            {
                TempNode->item_ID--;
                TempNode = TempNode->link;
            }
    }
    else
    {
        struct MainDB_LinkedList_Node* previous = Head;
        struct MainDB_LinkedList_Node* current = Head;
        while(current->item_ID != itemID)
        {
            previous = current;
            current = current->link; 
        }
        previous->link = current->link;
        free(current);
        current = NULL;

        item_ID--;
        TempNode = previous;
            while(TempNode != NULL)
            {
                TempNode->item_ID--;
                TempNode = TempNode->link;
            }
    }
    //add IF Flag for IF no LL
    cout << "Deleted Succesfully..]";
    Sleep(1450);
    system("CLS");
}

// ::: TRANSACTION MENU :::

void addPurchase_CASE_1()
{
    int write_QTY;
        string write_Name, write_Author, write_Category, temp_str_write_QTY;
        trans_ID++;
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
        //cin.ignore();
        getline(cin, write_Category);

        
            insertEnd_v2_Trans(
            &Trans_Head,
            &Trans_LastNode,
            item_ID,
            write_Name,
            write_Author,
            write_QTY,
            write_Category);

            cout << "\n\nUpdating DATABASE...";
            Sleep(1450);
            system("CLS");
            //return item_ID;
}

void viewPurchase_CASE_2(string transFileName)
{
    CPY_TransDB_LinkedList_to_transFile(Trans_Head, "transFile");
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
        in_dbFile.open((transFileName + ".txt"), std::ios::app);
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

void sortPurchase_CASE_3(struct TransDB_LinkedList_Node* head)//RED RED RED RED RED RED RED RED RED RED FLAG :: CODE RED
{

    struct TransDB_LinkedList_Node* reader = head; // can refactor by removing line and initiating as reader instead of head
    if (reader == NULL)
    {
        std::cout << "LinkedList Empty";
    }
    else
    {
        while (reader != NULL)
        {
            //change to passbyValue//change to passbyValue
            insertEnd_v2_Trans
            (
                &Trans_Head, 
                &Trans_LastNode, 
                reader->trans_ID,
                reader->title,
                reader->author,
                reader->qty,
                reader->category
            );
            reader = reader->link;
        }
    }
    
    cout << "Sorted Linked List.." << endl;
    Trans_PrintNode(Trans_Head);

    cout << "\nPress any key to continue..";
    _getch();
    system("cls");

}

void purchaseDetails_CASE_4()
{
    system("cls");
    Trans_PrintNode(Trans_Head);
    cout << "Press any key to continue..";
    _getch();
    system("cls");
}