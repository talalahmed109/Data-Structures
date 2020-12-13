#include<iostream>
using namespace std;
class Queue
{
	int* Qarray;
	int size, front, rear, No_Of_Items;
public:
	Queue() //Default Constructor
	{
		Qarray = NULL;
		size = 0;
		front = -1;
		rear = -1;
		No_Of_Items = 0;
	}
	Queue(int size) //Overloaded Constructor
	{
		Qarray = new int[size];
		this->size = size;
		front = -1;
		rear = -1;
		No_Of_Items = 0;
	}
	~Queue()
	{
		delete[] Qarray;
	}
	void enqueue(int data)
	{
		if (IsFull())
		{
			cout << "The Queue is full You Can't Enqueue More Elements NOW To do so You have to Dequeue some Data :(" << endl;
		}
		else
		{
			rear = rear + 1;
			Qarray[rear] = data;
			No_Of_Items++;
		}
	}
	int dequeue()
	{
		int a = 0;
		if (IsEmpty())
		{
			cout << "The Queue is Empty  :(" << endl;
		}
		else
		{
			front = front + 1;
			a = Qarray[front];
			No_Of_Items--;
			return a;
		}
		return a;
	}
	bool IsEmpty()
	{
		if (rear == front)
		{
			rear = -1;
			front = -1;
			return true;
		}
		else
		{
			return false;
		}
	}
	bool IsFull()
	{
		if (No_Of_Items >= size)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
int main()
{
	int data, size, option = 0;
	cout << "Enter Size Of Queue : ";
	cin >> size;
	Queue a(size);
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
				cout << data << " : Dequeued From Queue\n";
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
			if (a.IsFull())
			{
				cout << "Queue Is Full :(\n";
			}
			else
			{
				cout << "Queue Is Not Full :)\n";
			}
		}
		else if (option == 5)
		{
			exit(1);
		}
	}
	system("pause");
	return 0;
}