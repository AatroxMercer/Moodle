#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int num[3];

	for (int i = 0; i < 3; i++)
	{
		cin >> num[i];
	}

	sort(num, num + 3);

	for (int i = 0; i < 3; i++)
	{
		cout << num[i];
		if (i - 3)
		{
			cout << " ";
		}
	}
	cout << endl;

	return 0;
}