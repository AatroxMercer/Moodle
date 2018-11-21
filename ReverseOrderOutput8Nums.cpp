#include <iostream>
#include <cstring>
using namespace std;

const int _max = 8;
int input[_max];

int main(int argc, char const *argv[])
{
	memset(input, 0, sizeof(input));

	for (int i = 0; i < _max; ++i)
	{
		cin >> input[i];
	}

	for (int i = 0; i < _max; ++i)
	{
		cout << input[_max-1-i] << " ";
	}

	cout << endl;

	return 0;
}
