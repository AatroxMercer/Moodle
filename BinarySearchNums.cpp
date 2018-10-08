#include <iostream>
#include <cstring>
using namespace std;

const int _max = 10;
double input[_max];
double sample;

int binarySearch(int left, int middle, int right) {
	if (middle == left || middle == right)
	{
		if (input[middle] - sample)
		{
			return -1;
		}
		else {
			return middle;
		}
	}
	
	if (input[middle] == sample)
	{
		return middle;
	}
	else if (input[middle] > sample)
	{
		return binarySearch(left, (left + middle) / 2 ,middle);
	}
	else if (input[middle] < sample)
	{
		return binarySearch(middle, (middle + right) / 2, right);
	}
}

int main(int argc, char const *argv[])
{
	int left, middle, right;

	memset(input, 0, sizeof(input));
	for (int i = 0; i < _max; ++i)
	{
		cin >> input[i];
	}
	cin >> sample;
	left = 0;
	right = _max - 1;
	middle = (left + right) / 2;

	cout << binarySearch(left, middle, right) << endl;

	return 0;
}