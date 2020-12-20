#include<iostream>
using namespace std;

class Stack
{

public:
    int data;
    Stack* next;
    Stack()
    {
        data = 0;
        next = NULL;
    }
};
Stack* top = NULL;
int Size = 0;

void isEmpty()
{
    if (top == NULL && Size == 0)
        cout << "Stack is Empty!\n";
    else
        cout << "Stack is not Empty!\n";
}

void push(int x)
{
    Stack* node;
    node = new Stack();
    node->data = x;
    node->next = top;
    top = node;
    cout << x << " is pushed\n";
    Size++;
}
int pop()
{
    if (top == NULL && Size == 0)
    {
        cout << "stack is empty\n";
        return INT_MIN;
    }
    else
    {
        Size--;
        int temp = top->data;
        Stack* tempNode = top;
        top = top->next;
        delete tempNode;
        return temp;
    }
}
void Display()
{
    if (top == NULL && Size == 0)
    {
        cout << "\tList is empty!" << endl;
        return;
    }
    Stack* temp;
    temp = new Stack();
    temp = top;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        //pop();
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    cout << "\n\t\t1. Push\n";
    cout << "\t\t2. Pop\n";
    cout << "\t\t3. To Check if Stack is Empty\n";
    cout << "\t\t4. Display\n";
    cout << "\t\t0. Exit\n";
    int choice;
    cout << "\n\t\tEnter your choice: ";
    cin >> choice;
    while (choice)
    {
        if (choice == 1)
        {
            int data;
            cout << "\nEnter element: ";
            cin >> data;
            push(data);
        }
        else if (choice == 2)
        {
            int item = pop();
            if (item == INT_MIN) {}
            else
                cout << "Popped element: " << item << endl;
        }
        else if (choice == 3)
        {
            isEmpty();
        }
        else if (choice == 4)
        {
            cout << "\tData in Stack: \n";
            Display();
        }
        else
            cout << "Invalid number, try again!\n";
        cout << "Enter your choice: ";
        cin >> choice;
    }
    return 0;
}
