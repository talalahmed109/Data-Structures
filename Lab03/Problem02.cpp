//Poroblem 2


#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
class Queue
{
public:
	node* rear, * front;
	bool check = false;
	Queue()
	{
		rear = NULL;
		front = NULL;
	}
	void enqueue(int a)
	{
		node* newnode = new node;
		newnode->data = a;
		newnode->next = NULL;
		if (front == NULL)
		{
			front = newnode;
		}
		else
		{
			rear->next = newnode;
		}
		rear = newnode;
	}
	int dequeue()
	{
		if (IsEmpty())
		{
			cout << "Queue is EMPTY :(\n";
			return 0;
		}
		else
		{
			node* ptr;
			ptr = front;
			int dat = front->data;
			front = front->next;
			ptr = NULL;
			delete ptr;
			return dat;
		}
	}
	bool IsEmpty()
	{
		if (front == NULL)
		{
			return true;
		}
		else if (front != NULL)
		{
			return false;
		}
	}
	bool isFull()
	{
		if (front != NULL)
		{
			return true;
		}
		else if (front == NULL)
			return false;
	}
};
int main()
{
	Queue a;
	int data, option = 0;
	while (option != 5)
	{
		cout << "1-Enqueue\n2-Dequeue\n3-IsEmpty\n4-IsFull\n5-Exit\n";
		cin >> option;
		if (option == 1)
		{
			cout << "Enter Data That You Want to Enqueue in Queue : ";
			cin >> data;
			a.enqueue(data);
		}
		else if (option == 2)
		{
			if (a.IsEmpty())
			{
				data = a.dequeue();
			}
			else
			{
				data = a.dequeue();
				cout << " " << data << " : Dequeued From Queue\n";
			}
		}
		else if (option == 3)
		{
			if (a.IsEmpty())
			{
				cout << "Queue Is Empty :(\n";
			}
			else
			{
				cout << "Queue Is Not Empty :)\n";
			}
		}
		else if (option == 4)
		{
			if (a.isFull())
			{
				cout << "Queue Is Full :)\n";
			}
			else
			{
				cout << "Queue Is Not Full :(\n";
			}
		}
	}
	system("pause");
	return 0;
}