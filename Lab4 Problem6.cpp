//Problem6
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
// S is used for traversing through the list
class linkedList {
public:

    node* start;
    int size;
    linkedList()
    {
        size = 0;
        start = new node;
        start->iData = 0;
        start->next = NULL;
    }
    void addNode() {
        node *S = start;
        while (S->next != NULL)
            S = S->next;
        node *temp = new node;
        temp->next = NULL;
        temp->iData = 0;
        S->next = temp;
        S = NULL;
        delete (S);
        size++;
    }
    node* reverseDisplay(node* S)
    {
        if (S == NULL)
            return S;
        reverseDisplay(S->next);
        cout<<S->getData()<<" ";
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
    cout<<"List is reverse: \n";
    myList.reverseDisplay(myList.start->next);
    return 0;
}