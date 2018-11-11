#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
using namespace std;

const int _max = 1000;

bool check(int num) {
	for (int i = 2; i <= sqrt(num); ++i)
	{
		if (num % i == 0)
		{
			return false;
		}
	}

	if (num <= 1)
	{
		return false;
	}
	
	return true;
}

int main(int argc, char const *argv[])
{
	int count = 0;

	for (int i = 0; i <= _max; ++i)
	{
		if (check(i))
		{
			cout << setw(5) << i;
			if (!(++count % 5))
			{
				cout << endl;
			}
		}
	}

	return 0;
}