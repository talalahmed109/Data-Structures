
#include<iostream>
using namespace std;

class matrix
{
private:
	int** matrix1;
	int** matrix2;
	int** multi;
	int** add;
	int row1, col1, row2, col2;

public:
	matrix()
	{
		row1 = 3, col1 = 3, row2 = 3, col2 = 3;
		matrix1 = new int* [row1];
		for (int i = 0; i < row1; ++i)
		{
			*(matrix1 + i) = new int[col1];
		}
		matrix2 = new int* [row2];
		for (int i = 0; i < col1; ++i)
		{
			*(matrix2 + i) = new int[col2];
		}
		multi = new int* [row1];
		for (int i = 0; i < row1; ++i)
		{
			*(multi + i) = new int[col2];
		}
		add = new int* [row1];
		for (int i = 0; i < row1; ++i)
		{
			*(add + i) = new int[col2];
		}
	}

	void insert()
	{
		cout << "Enter elements for First Matrix:" << endl;
		for (int i = 0; i < row1; ++i)
		{
			for (int j = 0; j < col1; ++j)
			{
				cout << "Enter Elemnet:";
				cin >> matrix1[i][j];
			}
		}
		cout << "Enter elements for Second Matrix:" << endl;
		for (int i = 0; i < row2; ++i)
		{
			for (int j = 0; j < col2; ++j)
			{
				cout << "Enter Elemnet:";
				cin >> matrix2[i][j];
			}
		}
	}

	void Add()
	{
		for (int i = 0; i < row1; i++)
		{
			for (int j = 0; j < col2; j++)
			{
				add[i][j] = 0;
				add[i][j] = matrix1[i][j] + matrix2[i][j];
			}
		}
	}

	void multiply()
	{
		for (int i = 0; i < row1; i++)
		{
			for (int j = 0; j < col2; j++)
			{
				multi[i][j] = 0;
				for (int k = 0; k < row2; k++)
				{
					multi[i][j] = multi[i][j] + matrix1[i][k] * matrix2[k][j];
				}
			}
		}
	}

	void display()
	{
		cout << "\nFirst Matrix is:" << endl;
		for (int i = 0; i < row1; ++i)
		{
			for (int j = 0; j < col1; ++j)
			{
				cout << matrix1[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		cout << "\nSecond Matrix is:" << endl;
		for (int i = 0; i < row2; ++i)
		{
			for (int j = 0; j < col2; ++j)
			{
				cout << matrix2[i][j] << " ";
			}
			cout << endl;
		}

		cout << "\nMatrix Multipliction is:" << endl;
		for (int i = 0; i < row1; ++i)
		{
			for (int j = 0; j < col2; ++j)
			{
				cout << multi[i][j] << " ";
			}
			cout << endl;
		}

		cout << "\nMatrix Addition is:" << endl;
		for (int i = 0; i < row1; ++i)
		{
			for (int j = 0; j < col2; ++j)
			{
				cout << add[i][j] << " ";
			}
			cout << endl;
		}
	}

	~matrix()
	{
		delete[]matrix1;
		delete[]matrix2;
		delete[]multi;
		delete[]add;
	}
};

int main()
{
	matrix M;
	M.insert();
	M.multiply();
	M.Add();
	M.display();

	return 0;
}
