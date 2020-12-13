#include<iostream>
using namespace std;
struct node
{
	int priority;
	int data;
	node* next;
}*head;
class queue
{
	int size;
	node* rear;
public:
	queue()
	{
		head = NULL;
		rear = NULL;
		size = 0;
	}
	~queue() {}
	bool isempty()
	{
		if (head == NULL)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	void  enqueue(int p, int data)
	{
		node* newnode = new node;
		newnode->data = data;
		newnode->priority = p;
		newnode->next = NULL;
		if (head == NULL || p < head->priority)
		{
			head = newnode;
		}
		else
		{
			while (newnode->next != NULL && newnode->next->priority <= p)
				newnode = newnode->next;
			rear->next = newnode;
		}
		rear = newnode;
	}
	void dequeue()
	{
		if (isempty())		
		{
		    cout << "Queue is EMPTY :(\n";
		}
		else
		{
			node* ptr;
			ptr = head; 
			head->data;
			head = head->next;
			ptr = NULL;
			delete ptr;
		}
	}
	void display()
	{
		if (head == NULL)
		{
			cout << "Queue is empty \n";
		}
		else
		{

			node* ptr;
			ptr = head;
			if (ptr == NULL)
				cout << "Queue is empty\n";
			else 
			{
				cout << "Priority Queue Items \n";
				while (ptr != NULL) {
					cout << ptr->priority << " " << ptr->data << endl;
					ptr = ptr->next;
				}
			}
		}
		cout << endl;
	}
};
int main()
{
	int n;
	queue Q;
a:	cout << "\t 1.Check if queue is empty.\n\t 2. Enter data in queue \n\t 3. Dequeue data  \n\t 4. Display the data \n\t 5. to exit \n\t Choice: ";
	cin >> n;
	if (n == 1)
	{
		if (Q.isempty()) 
		{
			cout << "Queue is empty" << endl;
		}
		else 
		{
			cout << "Queue is not empty" << endl;
			Q.display();
		}
		goto a;
	}
	if (n == 2)
	{

		int data, n, p;
		cout << "Enter the number of element you add in queue" << endl;
		cin >> n;
		cout << "ENTER THE DATA YOU WANT TO ADD & Priority IN QUEUE \n";
		for (int i = 0; i < n; i++)
		{
			cout << "Data:";
			cin >> data;
			cout << endl;
			cout << "Priority:";
			cin >> p;
			Q.enqueue(p, data);
		}
		goto a;
	}
	if (n == 3)
	{
		int n;
		cout << "Enter the number of element you want to dequeue" << endl;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			Q.dequeue();
		}
		goto a;
	}
	if (n == 4)
	{
		Q.display();
		goto a;
	}
	if (n == 5)
	{
		goto z;
	}
	else
	{
		cout << "Inncorrect Input\n";
		goto a;
	}
z:
	system("pause");
	return 0;
}