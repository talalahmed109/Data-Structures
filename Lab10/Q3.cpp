// Lab10
// Q3:

#include <iostream> 
using namespace std;


class maxHeap {
public:
	maxHeap() {}
	~maxHeap() {}

	void maxHeapify(int arr[], int n, int i)
	{
		int largest = i;
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		if (l < n && arr[l] > arr[largest])
			largest = l;
		if (r < n && arr[r] > arr[largest])
			largest = r;
		if (largest != i) {
			swap(arr[i], arr[largest]);
			maxHeapify(arr, n, largest);
		}
	}
	void minHeapify(int arr[], int n, int i)
	{
		int smallest = i;
		int l = 2 * i + 1;
		int r = 2 * i + 2;

		if (l < n && arr[l] < arr[smallest])
			smallest = l;

		if (r < n && arr[r] < arr[smallest])
			smallest = r;

		if (smallest != i) {
			swap(arr[i], arr[smallest]);

			minHeapify(arr, n, smallest);
		}
	}


	void buildMaxHeap(int arr[], int n)
	{
		int a = (n / 2) - 1; // a = starting index
		for (int i = a; i >= 0; i--) {
			maxHeapify(arr, n, i);
		}
	}
	void build_minHeap(int arr[], int n) {
		int a = (n / 2) - 1;
		for (int i = a; i >= 0; i--) {
			minHeapify(arr, n, i);
		}
	}

	void ExtractMax(int arr[], int n, int k)
	{
		for (int i = n / 2 - 1; i >= 0; i--)
			maxHeapify(arr, n, i);
		for (int i = n - 1; i >= k - 1; i--)
		{
			swap(arr[0], arr[i]);
			maxHeapify(arr, i, 0);
		}
	}
	void ExtractMin(int arr[], int n, int k)
	{
		for (int i = n / 2 - 1; i >= 0; i--)
			minHeapify(arr, n, i);
		for (int i = n - 1; i >= k - 1; i--)
		{
			swap(arr[0], arr[i]);
			minHeapify(arr, i, 0);
		}
	}
	void displayHeap(int arr[], int n)
	{
		for (int i = 0; i < n; ++i)
			cout << arr[i] << " ";
		cout << "\n";
	}
};


int main()
{
	maxHeap obj;
	int n, largestElement;
	cout << "Enter Size Of Max Heap Array : ";
	cin >> n;
	int* array = new int[n];
	cout << "Input Array Elements:\n";
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}
	cout << "Max Heap : ";
	obj.buildMaxHeap(array, n);
	obj.displayHeap(array, n);
	cout << "Min Heap : ";
	obj.build_minHeap(array, n);
	obj.displayHeap(array, n);
	cout << "Enter how many Largest/Smallest Elements you want to see : ";
	cin >> largestElement;
	int op;

	cout << "\nSmallest Elements Are : ";
	obj.ExtractMin(array, n, largestElement);
	int j = n - 1;
	for (int i = 0; i < largestElement; i++)
	{
		cout << array[j] << " ";
		j--;
	}

	cout << "\nLargest Elements Are: ";
	obj.ExtractMax(array, n, largestElement);
	int jj = n - 1;
	for (int i = 0; i < largestElement; i++)
	{
		cout << array[jj] << " ";
		jj--;
	}


	return 0;
}
