#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int num;
		cin >> num;
	int sum;
	int _vector[2][num];

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < num; ++j)
		{
			cin >> _vector[i][j];
		}
	}

	sum = 0;
	for (int i = 0; i < num; ++i)
	{
		sum += _vector[0][i] * _vector[1][i];
	}

	cout << sum << endl;
	
	return 0;
}