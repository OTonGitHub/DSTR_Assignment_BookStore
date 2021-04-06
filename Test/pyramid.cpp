//pyramid of 10 rows

#include <iostream>
using namespace std;

int main()
{
    int row = 10;
    int star = 1;
    int spaces = 10;
    char space = ' ';
    int temp;

    for (int i = 1; i <= 10; i++)
    {
        temp = 1;
        for (int i = 1; i <= spaces; i++)
        {
            printf(" ");
        }
        while (temp <= star)
        {
            printf(" * ");
            temp++;
        }
        for (int i = 1; i <= spaces; i++)
        {
            printf(" ");
        }
        spaces--;
        star += 2;
        printf("\n");

    }

    star = 19;
    spaces = 1;
    for (int i = 1; i<=10; i++){

        for(int i = 1; i <= spaces; i ++){
            printf(" ");
        }
        for(int i = 1; i <= star; i ++){
            printf(" * ");
        }
        for(int i = 1; i <= spaces; i++){
            printf(" ");
        }
        spaces++;
        star -= 2;
        printf("\n");
    }

    return 0;
}
