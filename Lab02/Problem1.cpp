#include <iostream>
using namespace std;

class Stack 
{
private:
    int* arr = new int;
    int top;
    int size;
public:
    Stack(int s) 
    {
        top = -1;
        size = s;
        arr = new int[size];
    }

    void isFull()
    {
        if (top == size - 1)
        {
            cout << "stack is full " << endl;
        }
        else
            cout << "stack is not full " << endl;
    }
    void isEmpty()
    {
        if (top == -1)
        {
            cout << "stack is empty" << endl;
            return;
        }
        else
            cout << "stack is not empty" << endl;
    }
    void push(int value) 
    {
        if (top == size - 1) 
        {
            cout << "stack is full " << endl;
            return;
        }
        top++;
        arr[top] = value;
    }
    void pop()
    {
        if (top == -1) 
        {
            cout << "stack is empty" << endl;
            return;
        }
        else
            top--;
        cout<<arr[top]<< "Elemet has been poped\n";
        size--;
    }
    void Top() 
    {
        if (top == -1) 
        {
            cout << "stack is empty" << endl;
            return;
        }
        cout << arr[top] << endl;
    }
    void Display()
    {
        int temp = top;
        if (top == -1)
        {
            cout << "stack is empty" << endl;
        }
        for (int i = 0; i < size; i++)
        {
            cout << arr[temp]<<endl;
            temp--;
        }
    }
};

int main()
{
    int choice;
    int size;
    cout << "Enter the size of stack (Array): ";
    cin >> size;
    Stack s(size);
    while (1)
    {
        cout << "\t1. isFull\n"
            "\t2. isEmpty\n"
            "\t3. Push\n"
            "\t4. Pop\n"
            "\t5. Top\n"
            "\t6. Display\n"
            "\t0. Exit\n\n"
            "\tChoice: ";
        cin >> choice;
        if (choice == 1)
        {
            s.isFull();
        }
        else if (choice == 2)
        {
            s.isEmpty();
        }
        else if (choice == 3)
        {
            int number;
            cout << "Enter element to Push: ";
            cin >> number;
            s.push(number);
        }
        else if (choice == 4)
        {
            s.pop();
        }
        else if (choice == 5)
        {
            s.Top();
        }
        else if (choice == 6)
        {
            s.Display();
        }
        else if (choice == 0)
            exit(0);
        else
            cout << "Invalid Choice\n";
    }
    return 0;
}