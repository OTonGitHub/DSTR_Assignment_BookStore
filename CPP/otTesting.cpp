#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <vector>
#include <string>
#include <conio.h>
#include <sstream>

using namespace std;

/*stringstream ss;
    ss << write_ID;
    ss >> */

int main()
{
    string dbFileName = "otTextFile";
    int item_ID = 0;
    ofstream out_dbFile;
    ifstream in_dbFile;
    int count;

    in_dbFile.open((dbFileName + ".txt"), std::ios::app); //RECIEVING ID;
    string idLine;
    string str_tempID;

    while (getline(in_dbFile, idLine))
    {
        stringstream getID(idLine);     // ::: OVERWRITE getID OBJECT :::
        getline(getID, str_tempID, ',');
        stringstream conv;              // ::: OVERWRITE conv OBJECT ::: --> IF FAIL : COUNT LINES, CREATE ARRAY OF OBJ
        conv << str_tempID;
        conv >> item_ID;
        //tempID = stoi(str_tempID);
    }

    //if(tempID >= 0){
      //  item_ID = tempID;
    //}

    cout << "targer item_ID : " << item_ID << endl;
    _getch();   //TRANSFFERED TANSFERRED TRANSFERRED TRANSFERRED TRANSFERRED
    in_dbFile.close();

    out_dbFile.open((dbFileName + ".txt"), std::ios::app);
    int write_QTY;
    string write_Name, write_Author, write_Category;
    item_ID++;
    cout << "ID : " << item_ID <<endl;
    cout << "Name : ";
    getline(cin, write_Name);
    cout << "Author : ";
    getline(cin, write_Author);
    cout << "QTY : ";
    cin >> write_QTY;
    cout << "Category : ";
    cin.ignore();
    getline(cin, write_Category);

    vector<string> write_Line;

    string str_write_ID;
    str_write_ID = to_string(item_ID);

    string str_write_QTY;
    stringstream ss;     // ^ CAN REFACTOR TO 2 LINES USING ABOVE METHOD ^
    ss << write_QTY;
    ss >> str_write_QTY;

    write_Line.push_back(str_write_ID);
    write_Line.push_back(write_Name);
    write_Line.push_back(write_Author);
    write_Line.push_back(str_write_QTY);
    write_Line.push_back(write_Category);

    count = 1;
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
             << read_ID  << endl;
        cout << read_Name << endl;
        cout << read_Author << endl;
        cout << read_QTY << endl;
        cout << read_Category << endl;
    }
    in_dbFile.close();

    return 0;
}

/* string stringLine = fileItem; //BUG
        char charLine[100];           //stringLine.length() inside charLine[] not required, DynamicAlloc                    //BUG
        strcpy(charLine, stringLine.c_str());
        int readID = stoi(stringLine); //BUG
        cout << readID + 1 << endl;
        if (readID >= 0 || readID <= 100)
        /*{ //BUG
        cout << endl
                 << readID << endl;
            _getch();
        TESTING, NOT REQUIRED
        item_ID = readID; //BUG
        }
    }
    in_dbFile.close(); */
