#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{	
	freopen("input.in", "r", stdin);
	freopen("outpit.out", "w", stdout);

	int min, max;
	int temp;

	cin >> min;
	max = min;

	for (int i = 1; i < 5; ++i)
	{
		cin >> temp;
		if (temp > max) {
			max = temp;
		} else if (temp < min) {
			min = temp;
		}
	}

	cout << min << " " << max << endl;

	return 0;
}