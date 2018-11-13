#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	long long input;
	long long output;

	cin >> input;
	output = 1;

	for (long long i = 2; i <= input; ++i)
	{
		output *= i;
	}

	cout << output << endl;

	return 0;
}