#include <iostream>
using namespace std;

const int _max = 3;
int matrix1[_max][_max], matrix2[_max][_max];
int matrix[_max][_max];

int Multiplication() {
	for (int i = 0; i < _max; ++i)
	{
		for (int j = 0; j < _max; ++j)
		{
			for (int k = 0; k < _max; ++k)
			{
				matrix[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	for (int i = 0; i < _max; ++i)
	{
		for (int j = 0; j < _max; ++j)
		{
			cin >> matrix1[i][j];
		}
	}
	for (int i = 0; i < _max; ++i)
	{
		for (int j = 0; j < _max; ++j)
		{
			cin >> matrix2[i][j];
		}
	}
	for (int i = 0; i < _max; ++i)
	{
		for (int j = 0; j < _max; ++j)
		{
			matrix[i][j] = 0;
		}
	}

	Multiplication();

	for (int i = 0; i < _max; ++i)
	{
		for (int j = 0; j < _max; ++j)
		{
			cout << matrix[i][j];
			if (j - _max + 1)
			{
				cout << " ";
			}
		}
		cout << endl;
	}

	return 0;
}