#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int min, max;
	int sum;

	sum = 0;
	cin >> min >> max;

	for (int i = min; i <= max; ++i)
	{
		sum += i;
	}

	cout << sum << endl;

	return 0;
}