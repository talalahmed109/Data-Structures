#include<iostream>
using namespace std;

class sort
{
public:

	void bubbleSort(int* const array, const int size)
	{

		for (int i = 0; i < size - 1; i++)
			 {
				 for (int j = 0; j < size - 1; j++) 
				 {				
					 if (array[j] > array[j + 1]) 
					 {
					 swap(&array[j], &array[j + 1]);
					
				     }
			      }
		      } 
	}
	void swap(int* element1, int* element2)
	{
		int Swap = *element1;
		*element1 = *element2;
		*element2 = Swap;
	}	
};

int main()
{
	sort s;
	int* arr;
	int size = 0;
	cout << "Enter size of array: ";
	cin >> size;
	arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		cout << "Enter Element: ";
		cin >> arr[i];
	}

	s.bubbleSort(arr, size);

	cout << "\nArray:\n ";
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	return 0;
}