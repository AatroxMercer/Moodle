#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a, b, c;

	cin >> a >> b >> c;

	for (int i = c; i < 100; i += 7)
	{
		if (i % 3 == a && i % 5 == b)
		{
			cout << i << endl;
			return 0;
		}
	}

	cout << "No answer" << endl;
	return 0;
}