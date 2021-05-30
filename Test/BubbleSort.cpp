#include <iostream>

using namespace std;


int arr[10] = {9,5,1,3,5,2,7,8,4,2}; //THIS IS THE INITIAL UNSORTED ARRAY

int arrSize()
{
    return sizeof(arr)/sizeof(int); //A FUNCTION TO GET THE LENGTH OF THE ARRAY
}

struct LinkedList{
    int data;
    struct LinkedList * link = NULL;
};

void bubbleSort(struct LinkedList** head, int count);

int main(int argc, char* argv[])
{
    LinkedList * head;
    LinkedList * newNode;

    head = (LinkedList*)malloc(sizeof(LinkedList));
    newNode = (LinkedList*)malloc(sizeof(LinkedList));

    newNode->data = 9;
    head = newNode;

    newNode = (LinkedList*)malloc(sizeof(LinkedList));
    newNode->data = 5;
    head->link = newNode;

    newNode = (LinkedList*)malloc(sizeof(LinkedList));
    newNode->data = 1;
    head->link->link = newNode;

    newNode = (LinkedList*)malloc(sizeof(LinkedList));
    newNode->data = 3;
    head->link->link->link = newNode;

    newNode = (LinkedList*)malloc(sizeof(LinkedList));
    newNode->data = 5;
    head->link->link->link->link = newNode;

    newNode = (LinkedList*)malloc(sizeof(LinkedList));
    newNode->data = 2;
    head->link->link->link->link->link = newNode;

    newNode = (LinkedList*)malloc(sizeof(LinkedList));
    newNode->data = 7;
    head->link->link->link->link->link->link = newNode;

    newNode = (LinkedList*)malloc(sizeof(LinkedList));
    newNode->data = 8;
    head->link->link->link->link->link->link->link = newNode;

    newNode = (LinkedList*)malloc(sizeof(LinkedList));
    newNode->data = 4;
    head->link->link->link->link->link->link->link->link = newNode;

    newNode = (LinkedList*)malloc(sizeof(LinkedList));
    newNode->data = 2;
    head->link->link->link->link->link->link->link->link->link = newNode;

    newNode->link = NULL;

    cout << "UNSORTED LINKED LIST : " << endl;
    for(LinkedList* i = head; i->link != NULL; i = i->link)
        cout << i->data << " | ";

    bubbleSort(&head,10);

    cout << endl<< "\nAFTER SORTING : " << endl;
    for(LinkedList* i = head; i->link != NULL; i = i->link)
        cout << i->data << " | ";

    return 0;
}

void bubbleSort(struct LinkedList** head, int count)
{
    struct LinkedList** h;
    int i, j, swapped;

    for (i = 0; i <= count; i++)
    {
        h = head;
        swapped = 0;

        for(j = 0; j < count - i - 1; j++)
        {
            struct LinkedList* p1 = *h;
            struct LinkedList* p2 = p1->link;

            if (p1->data > p2->data)
            {
                struct LinkedList* tmp = p2->link;
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
}


/*
void sortList(LinkedList* h, int size)
{
    LinkedList * start;

    for(start = h; start->link != NULL; start = start->link )
    {
        for(LinkedList* temp = )
    }
}
*/



/*
int main(int argc, char* argv[])
{
    //THIS IS THE ALGORITHM
    int x;
    for(x=0; x<arrSize(); x++)
    {
        for(int i=1; i<(arrSize()- x) ; i++)
        {
            cout<<"Pass : " << i << endl;
            if(arr[i] < arr[i-1]){
                int temp = arr[i-1];
                arr[i-1] = arr[i];
                arr[i] = temp;
            }
        }
    }

    for(int i=0; i<arrSize(); i++)
        cout << arr[i] << " | ";
}
*/