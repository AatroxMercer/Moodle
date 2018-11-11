#include <iostream>
using namespace std;

void init(int& min, int& max) {
	if (min > max)
	{
		min = min + max;
		max = min - max;
		min = min - max;
	}
}

int Euclid(int min, int max) {
	if (max % min)
	{
		return Euclid(max % min, min);
	}
	else
	{
		return min;
	}
}

int main(int argc, char const *argv[])
{
	int min, max;
	int divsor, multiple;

	cin >> min >> max;
	init(min, max);

	divsor = Euclid(min, max);
	multiple = min * max / divsor;

	cout << divsor << " " << multiple << endl;
	return 0;
}
