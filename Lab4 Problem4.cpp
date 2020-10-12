//Problem #4
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
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void Search ()
{
    int s;
    A:cout << "Enter number to search: ";
    cin >> s;
    struct Node* temp = head;
    while (temp != NULL)
    {
        if (temp->data == s)
        {
            goto A;
        }
        temp = temp->next;
    }
    cout << "Number Not Found\n";
}

int main()
{
    int choice;
    cout<<"\t\t\tMAIN MENU\n"
          "\t\t1. Insert\n"
          "\t\t2. Display\n"
          "\t\t3. Search\n";
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
            Search();
        }
        cout<<"\t\tChoice: ";
        cin>>choice;
    }
    return 0;
}