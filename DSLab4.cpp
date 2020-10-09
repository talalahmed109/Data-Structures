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

int Search ()
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
    goto A;
}

int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    Display();
    Search();
    return 0;
}