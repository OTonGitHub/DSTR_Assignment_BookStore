#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <windows.h>

using namespace std;

void productSearch_CASE_3(string fileName) // Combine with Categoryilter
{
    system("CLS");
    string searchString;
    int searchID;
    bool use_searchID = true;
    bool matchFound;

    struct bkStoreRecordNode
    {
        int itemID;
        string bookName;
        string Author;
        int qty;
        string category;
        struct bkStoreRecordNode *linkPtr;
    };

    

    ifstream in_dbFile;
    in_dbFile.open((fileName + ".txt"), std::ios::app);
    string line;
    while (getline(in_dbFile, line))
    {

    }

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

        in_dbFile.close();
    }
    else
    {
        //OPEN FILE OR LINKED-LIST HERE:::
        cout << "\nSEARCH BOOK_NAME / AUTHOR..." << endl;
    }

    if (use_searchID)
    {
        cout << "SEARCHING BY ID.." << endl;
        Sleep(500);
        if (matchFound)
        {
            cout << "\nMATCH FOUND !" << endl;
        }
        if (!matchFound)
        {
            cout << "\nSORRY! NO MATCH" << endl;
        }
    }
}

int main()
{
    productSearch_CASE_3("dbFile");
}
