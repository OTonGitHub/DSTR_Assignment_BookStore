#include <iostream>
using namespace std;

int main()
{

    struct ac
    {
        int temp;
        bool isOn;
        ac *acPtr;
    };

    ac ac3;
    ac3.temp = 25;
    ac3.isOn = true;
    ac3.acPtr = NULL;

    ac ac2;
    ac2.temp = 16;
    ac2.isOn = true;
    ac2.acPtr = &ac3;

    ac ac1;
    ac1.temp = 32;
    ac1.isOn = false;
    ac1.acPtr = &ac2;

    cout << "\n____AC 1_____" << endl;
    cout << "Temp : " << ac1.temp << endl;
    cout << "isOn : " << ac1.isOn << endl;
    cout << "acPtr : " << ac1.acPtr << endl;

    cout << "\n____AC 2_____" << endl;
    cout << "temp : " << ac1.acPtr->temp << endl;
    cout << "isOn : " << ac1.acPtr->isOn << endl;
    cout << "acPtr : " << ac1.acPtr->acPtr << endl;

    cout << "\n____AC 2_____" << endl;
    cout << "temp : " << ac1.acPtr->acPtr->temp << endl;
    cout << "isOn : " << ac1.acPtr->acPtr->isOn << endl;
    cout << "acPtr : " << ac1.acPtr->acPtr->acPtr << endl;





    return 0;
}