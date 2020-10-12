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
    struct Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void reverse()
{
    Node* current = head;
    Node *prev = NULL, *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;

}
int main()
{
    int choice;
    cout<<"\t\t\tMAIN MENU\n"
          "\t\t1. Insert\n"
          "\t\t2. Display\n"
          "\t\t3. Reverse\n";
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
            reverse();
            cout<<"Reversed Linked List: \n";
            Display();
        }
        cout<<"\n\t\tChoice: ";
        cin>>choice;
    }
    return 0;
}
