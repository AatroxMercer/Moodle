#include <iostream>
using namespace std;

const int _max = 50;
int F[_max+1];

int main(int argc, char const *argv[])
{
	int n;

	cin >> n;
	F[1] = 1;
	F[2] = 1;

	for (int i = 3; i <= n; ++i)
	{
		F[i] = F[i-1] + F[i-2];
	}

	cout << F[n] << endl;

	return 0;
}