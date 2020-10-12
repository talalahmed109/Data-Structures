//Problem 2
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
struct Node* head = NULL;

void insert(int n)
{
    Node* newNode = new Node;
    newNode->data = n;
    newNode->next = head;
    head = newNode;
}
void Display()
{
    if (head == NULL)
    {
        cout << "List is empty!!\n";

    }
    struct Node* temp = head;
    cout << "Linked list: \n";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void selectionSort()
{
    
    Node* temp = head;
    while(temp)
    {
        Node* min = temp;
        Node* r = temp->next;
        while (r) {
            if (min->data > r->data)
                min = r;

            r = r->next;
        }
        
        int x = temp->data;
        temp->data = min->data;
        min->data = x;
        temp = temp->next;
    }
}
void bubbleSort()
{
    int swapped;

    Node *tempHead;
    Node *tempEnd = NULL;
    do
    {
        swapped = 0;
        tempHead = head;
        while(tempHead->next != tempEnd)
        {
            if (tempHead->data > tempHead->next->data)
            {
                int temp = tempHead->data;
                tempHead->data = tempHead->next->data;
                tempHead->next->data = temp;
                swapped = 1;
            }
            tempHead = tempHead->next;
        }
        tempEnd = tempHead;

    }while(swapped);
}
int main()
{
    int choice;
    cout<<"\t\t\tMAIN MENU\n"
          "\t\t1. Insert\n"
          "\t\t2. Display\n"
          "\t\t3. Selection Sort\n"
          "\t\t4. Bubble Sort\n";
    cout<<"\t\tChoice: ";
    cin>>choice;
    while(choice)
    {
        if(choice == 1)
        {
            int data;
            cout<<"Enter Element: ";
            cin>>data;
            insert(data);
        }
        if(choice==2)
        {
            Display();
        }
        if(choice==3)
        {
            selectionSort();
            cout<<"Sorted ";
            Display();
        }
        if(choice==4)
        {
            bubbleSort();
            cout<<"Sorted ";
            Display();
        }
        cout<<"\n\t\tChoice: ";
        cin>>choice;
    }
    return 0;
}
