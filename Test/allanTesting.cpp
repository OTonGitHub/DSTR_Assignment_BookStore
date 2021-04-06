#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <vector>
#include <string>
#include <conio.h>

using namespace std;

int main()
{
    string dbFileName = "allanTextFile";
    int item_ID = 0;
    ofstream out_dbFile;
    ifstream in_dbFile;

    out_dbFile.open((dbFileName + ".txt"), std::ios::app);
    out_dbFile << "HELLO WORLD";

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
            _getch();*/
        //TESTING, NOT REQUIRED
        item_ID = readID; //BUG
        //}
    }
    in_dbFile.close();
    return 0;
}