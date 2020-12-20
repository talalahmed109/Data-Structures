#include<iostream>
#include<stack>

using namespace std;

class Queue
{
private:
    stack<int> stack1;
    stack<int> stack2;

public:
    void enqueue(int data)
    {
        stack1.push(data);
    }

    void dequeue()
    {
        int data;

        if (stack1.empty() && stack2.empty())        //if both stacks are empty
        {
            cout << endl << "Queue is empty." << endl;
            return;
        }

        else if (stack2.empty())         //if stack-2 is empty then insert elements from stack-1 to stack-2
        {
            while (!stack1.empty())
            {
                data = stack1.top();
                stack1.pop();
                stack2.push(data);
            }
        }
        data = stack2.top();
        stack2.pop();

        cout << endl << data << " is deleted." << endl;
    }
    void display()
    {
        stack<int> stack11;
        stack<int> stack22;
        stack11 = stack1;
        stack22 = stack2;

        while (!stack22.empty())
        {
            cout << endl << stack22.top();
            stack22.pop();
        }
        while (!stack11.empty())
        {
            cout << endl << stack11.top();
            stack11.pop();
        }
    }
};

int main()
{
    Queue q;
    int choice, data;

    while (1)
    {
        cout << endl;
        cout << "\n1. Insert data into queue." << endl;
        cout << "2. Delete data from queue." << endl;
        cout << "3. Display the data." << endl;
        cout << "4. EXIT." << endl;

        cout << "\nCHOICE: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << endl << "Enter data to be inserted: ";
            cin >> data;
            q.enqueue(data);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            cout << "Data: ";
            q.display();
            break;

        case 4:
            exit(0);
            break;

        default:
            cout << "\nINVALID CHOICE..." << endl;
        }
    }
    return 0;

}