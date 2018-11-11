#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int input;

	cin >> input;

	for (int i = 1; i <= input; ++i)
	{
		for (int j = i; j < input; ++j)
		{
			cout << '.';
		}
		for (int k = i; k > 0; --k)
		{
			cout << '*';
		}
		cout << endl;
	}

	return 0;
}