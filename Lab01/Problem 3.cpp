
#include<iostream>
using namespace std;

class Array
{
private:
	int* arr;
	int size;

public:

	Array()
	{
		size = 0;
		arr = NULL;
	}

	Array(int s)
	{
		size = s;
		arr = new int[size];
	}


	void insert()
	{
		cout << "Enter elements for Array: " << endl;
		for (int i = 0; i < size; ++i)
		{
			cout << "Enter Elemnet:";
			cin >> arr[i];
		}
	}
	void display()
	{
		cout << "\nArray:\n ";
		for (int i = 0; i < size; ++i)
		{
	     	cout << arr[i] << " ";	
		}
	}

	int largest()
	{
		int large = 0;
		for (int i = 0; i < size; ++i)
		{
			if (arr[i] > arr[i + 1])
				large = arr[i];
		}
		return large;
	}
	int smallest()
	{
		int small = arr[0];
		for (int i = 0; i < size; ++i)
		{
			if (arr[i] < small)
			{
				small = arr[i];
			}
		}
		return small;
	}


	~Array()
	{
		delete[]arr;
	}
};

int main()
{
	int size;
	cout << "Enter size of Array: ";
	cin >> size;
	Array A(size);
	A.insert();
	A.display();

	cout << "\nLargest Element: " << A.largest() << endl;
	cout << "\nSmallest Element: " << A.smallest() << endl;

	return 0;
}
