#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int num, temp;
	int sum;

	cin >> num;
	sum = 0;

	for (int i = 0; i < num; ++i)
	{
		cin >> temp;
		sum += temp;
	}

	cout << sum << endl;

	return 0;
}