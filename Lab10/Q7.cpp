#include <iostream>
using namespace std;

class minHeap {

	int* arr;
	int size;
	int capacity;

public:

	minHeap(int capacity)
	{
		size = 0;
		this->capacity = capacity;
		arr = new int[capacity];
	}

	void insert(int data)
	{
		if (size == capacity)
		{
			cout << "\n Heap overflow." << endl;
			return;
		}

		arr[size] = data;
		int i = size;
		while (i != 0 && arr[i] < arr[parent(i)])
		{
			swap(arr[i], arr[parent(i)]);
			i = parent(i);
		}

		size++;
	}

	int extractMin()
	{
		if (size == 0)
		{
			cout << "\n The heap is empty." << endl;
			return 0;
		}

		int val = arr[0];

		size--;

		arr[0] = arr[size];

		minHeapify(0);

		return val;
	}

	void minHeapify(int index)
	{
		int smallest = index;

		if (arr[left(index)] < arr[index] && left(index) < size)
			smallest = left(index);

		// Comparing with the smallest here in case the first if was true.
		if (arr[right(index)] < arr[smallest] && right(index) < size)
			smallest = right(index);

		// Checking if any of the ifs were true
		if (smallest != index)
		{
			swap(arr[smallest], arr[index]);
			minHeapify(smallest);
		}
	}

	void maxHeapify(int index)
	{
		int greatest = index;

		if (arr[left(index)] > arr[index] && left(index) < size)
			greatest = left(index);

		if (arr[right(index)] > arr[greatest] && right(index) < size)
			greatest = right(index);

		if (greatest != index)
		{
			swap(arr[greatest], arr[index]);
			maxHeapify(greatest);
		}
	}

	void toMaxHeap()
	{
		for (int i = size - 1; i >= 0; i--)
			maxHeapify(i);
	}

	void deleteElement(int element)
	{
		int index = -1;

		for (int i = 0; i < size; i++)
		{
			if (arr[i] == element)
				index = i;
		}

		if (index == -1)
		{
			cout << "\n Element doesn't exist in the heap." << endl;
			return;
		}

		// Assign the index the minimum value possible and then extract it.
		arr[index] = INT_MIN;

		while (index != 0 && arr[parent(index)] > arr[index])
		{
			swap(arr[parent(index)], arr[index]);
			index = parent(index);
		}

		extractMin();
	}


	int parent(int i)
	{
		return (i - 1) / 2;
	}

	int left(int i)
	{
		return 2 * i + 1;
	}

	int right(int i)
	{
		return 2 * i + 2;
	}

	void display()
	{
		for (int i = 0; i < size; i++)
			cout << arr[i] << " ";
	}
};

void menu()
{
		cout << "\n Choose an option: "
			<< "\n\n\t 1 - Insert Element"
			<< "\n\n\t 2 - Delete Element"
			<< "\n\n\t 3 - Convert to Max Heap"
			<< "\n\n\t 4 - Display Heap"
			<< "\n\n\t 5 - Exit"
			<< "\n\n Enter: ";
}

int main()
{
	minHeap bruh(1000);

	int option, input;

	menu();
	cin >> option;

	while (1)
	{
		switch (option)
		{
		case 1:

			cout << "\n Enter the element you want to insert: ";
			cin >> input;

			bruh.insert(input);

			break;
		case 2:

			cout << "\n Enter the element you want to delete: ";
			cin >> input;

			bruh.deleteElement(input);

			break;
		case 3:

			bruh.toMaxHeap();

			cout << "\n Converted successfully." << endl;

			break;
		case 4:

			bruh.display();

			break;
		case 5:

			exit(0);

			break;
		default:

			cout << "\n Please enter a valid option!" << endl;

			break;
		}

		cout << "\n Press any key to continue..." << endl;
		system("pause > 0");
		system("cls");
		menu();
		cin >> option;
	}
}
