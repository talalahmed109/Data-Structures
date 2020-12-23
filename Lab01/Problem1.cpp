#include<iostream>
using namespace std;

class Swap
{
private:
	int* arr1, * arr2;
public:
	Swap()
	{
		arr1 = NULL, arr2 = NULL;
	}

	void insert(int size1, int size2)
	{
		arr1 = new int[size1];
		cout << "First Array: \n";
		for (int i = 0; i < size1; i++)
		{
			cout << "Enter Element: ";
			cin >> arr1[i];
		}
		
		arr2 = new int[size2];
		cout << "Second Array: \n";
		for (int j = 0; j < size2; j++)
		{
			cout << "Enter Element: ";
			cin >> arr2[j];
		}
	}

	void swap(int s1, int s2)
	{
		int size;
		if (s1 > s2)
			size = s1;
		else
			size = s2;
		int* temp = new int[size];
		for (int i = 0; i < size; ++i)
		{
			temp[i] = arr1[i];
			arr1[i] = arr2[i];
			arr2[i] = temp[i];
		}
	}
	void display(int s1,int s2)
	{
		cout << "\nArrays after swapping : \n ";
		cout << "Array 1: \n";

		for (int i = 0; i <s2; i++)
		{
			cout << arr1[i] << " ";
		}
		cout << "\nArray 2: \n";
		for (int i = 0; i <s1; i++)
		{
			cout << arr2[i] << " ";
		}
	}
};
int main()
{
	int size1 = 0, size2 = 0;
	Swap s;

	cout << "Enter size of Array 1: ";
	cin >> size1;
	cout << "Enter size of Array 2: ";
	cin >> size2;

	s.insert(size1,size2);

	s.swap(size1,size2);

	s.display(size1, size2);

	return 0;
}