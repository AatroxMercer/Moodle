#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int _max = 10;
double input[_max];

bool cmp(double left, double right) {
	return left > right;
}

int main(int argc, char const *argv[])
{
	memset(input, 0, sizeof(input));

	for (int i = 0; i < _max; ++i)
	{
		cin >> input[i];
	}

	sort(input, input+_max, cmp);

	for (int i = 0; i < _max; ++i)
	{
		cout << input[i] << " ";
	}

	cout << endl;

	return 0;
}