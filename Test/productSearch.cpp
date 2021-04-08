#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

void productSearch(string fileName) // Combine with Categoryilter
{
    system("CLS");
    string searchString;
    int searchID;
    bool use_searchID = true;
    bool matchFound;

    struct bkStoreRecordNode{
        int itemID;
        string bookName;
        string Author;
        int qty;
        string category;
        struct bkStoreRecordNode * linkPtr;
    };

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
    if (use_searchID && matchFound)
    {
        cout << "\nMATCH FOUND !" << endl;
    }
    else
    {
        cout << "\nSORRY! NO MATCH" << endl;
    }
}

int main()
{
    productSearch("dbFile");
}
