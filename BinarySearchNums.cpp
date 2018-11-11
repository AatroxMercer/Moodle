#include <iostream>
#include <cstring>
using namespace std;

const int _max = 10;
double input[_max];
double sample;

int binarySearch(int left, int middle, int right) {
	// cout << left << middle << right << input[middle] << endl;
	if (middle == left || middle == right)
	{
		if (input[left] == sample)
		{
			return left;
		}
		else if (input[right] == sample)
		{
			return right;
		}
		else {
			return -1;
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
	memset(input, 0, sizeof(input));
	for (int i = 0; i < _max; ++i)
	{
		cin >> input[i];
	}
	cin >> sample;

	cout << binarySearch(0, (_max - 1) / 2, _max - 1) << endl;

	return 0;
}