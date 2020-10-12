#include <iostream>
using namespace std;

struct node {
    int iData;
    node* next;

public:
    int getData()
    {
        return iData;
    }

    void setValue(int iData)
    {
        this->iData = iData;
    }
};
class linkedList {

    node* start;
    int size;

public:
    linkedList()
    {
        size = 0;
        start = new node;
        start->iData = 0;
        start->next = NULL;
    }
    void addNode()
    {
        node* S = start;
        while (S->next != NULL)
            S = S->next;
        node* temp = new node;
        temp->next = NULL;
        temp->iData = 0;
        S->next = temp;
        S = NULL;
        delete (S);
        size++;
    }
    void display()
    {
        int i = 1;
        node* S = start->next;
        cout<<"Result: ";
        while (S != NULL)
        {
            if(i % 2 != 0)
                cout << S->getData()<<"->";
            S = S->next;
            i++;
        }
        i = 1;
        S = start->next;
        while (S != NULL)
        {
            if(i % 2 == 0)
                cout << S->getData() ;
            S = S->next;
            i++;
        }
    }
    int getSize()
    {
        return size;
    }

    void getInput()
    {
        int input, i = 1;
        node* S = start->next;
        while (S != NULL)
        {
            cout << "\n Enter value for node number " << i << ": ";
            cin >> input;
            S->setValue(input);
            S = S->next;
            i++;
        }
    }
};
int main()
{
    linkedList myList;
    int sizeOfList = 0;
    cout << "\n Enter the size of linked list: ";
    cin >> sizeOfList;
    for (int i = 0; i < sizeOfList; i++)
        myList.addNode();
    myList.getInput();
    myList.display();
}
