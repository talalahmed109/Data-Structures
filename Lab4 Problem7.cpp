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
        cout << temp->data <<" ";
        temp = temp->next;
    }
}

Node *reverse(Node *head)   //reverse the string (second part)
{
    Node *p , *q;
    if(head == NULL)
        return head;
    p = head;
    q = p->next;
    if(q == NULL)
        return p;
    q = reverse(q);
    p->next->next = p;
    p->next = NULL;
    return q;
}

void isPalindrome()
{
    Node *p , *q ,*first_start,*second_start;
    p = head;
    q = head;

    if(p->next == NULL)
    {
        cout<<"It is  palindrome";
        return;
    }
    while(1)
    {
        p = p->next->next;
        if(p == NULL)
        {
            second_start = q->next;
            break;
        }
        if(p->next == NULL)
        {
            second_start = q->next->next;
            break;
        }
        q = q->next;
    }
    q->next = NULL;
    second_start = reverse(second_start);
    first_start = head;
    while(first_start!=NULL && second_start!=NULL)
    {
        if(first_start->data == second_start->data)
        {
            first_start = first_start->next;
            second_start = second_start->next;
        }
        else
        {
            cout<<"\n Not  Palindrome";
            return;
        }
    }
    cout<<"It is  Palindrome";
}
int main()
{
    int choice;
    cout<<"\t\t\tMAIN MENU\n"
          "\t\t1. Insert\n"
          "\t\t2. Display\n"
          "\t\t3. To check if List is Palindrome\n";
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
            isPalindrome();
        }
        cout<<"\t\tChoice: ";
        cin>>choice;
    }
    return 0;
}
