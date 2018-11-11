#include <iostream>
#include <cmath>
using namespace std;

const int _max = 1000000;

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
	int M;
	int A = 2, B = _max;

	cin >> M;

	for (int i = 0; i < _max; ++i)
	{
		if (check(i))
		{
			if (i >= M)
			{
				if (i - M < B)
				{
					A = i;
					B = i- M;
				}

				break;
			}
			A = i;
			B = M - i;
		}
	}

	cout << A << " " << B << endl;

	return 0;
}