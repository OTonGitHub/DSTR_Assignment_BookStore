#include <iostream>
#include <sstream>
#include <string>
#include <limits>

using namespace std;

/*int main()
{

    int qty;

    cout << "\nQTY : ";
    cin >> qty;

    while (cin.fail())
    {
        cin.clear(); //clear's fail flag
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        cout << "Invalid Input, Try Again..\n";
        cout << "\nQTY : ";
        cin >> qty;
    }

    stringstream ss;

    string str_qty;
    ss << qty;
    ss >> str_qty;

    cout << "\n\nQTY : " << str_qty;

    return 0;
}*/

int main()
{
    int qty;
    string line;
    while (getline(cin, line))
    {
        stringstream ss(line);
        if (ss >> qty)
        {
            if (ss.eof())
            {
                break;
            }
        }
        cout << "\nInvalid Input, Try Again : ";
    }
    cout << "\n\nQTY : " << qty;

    return main();
}