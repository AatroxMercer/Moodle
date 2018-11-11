#include <iostream>
using namespace std;

int count(int index) {
	int temp = 0;
	while (index % 5 == 0) {
		index /= 5;
		temp++;
	}
	return temp;
}

int main(int argc, char const *argv[])
{
	int M;
	int countZero;

	cin >> M;

	countZero = 0;
	for (int i = 5; i <= M; i += 5)
	{
		countZero += count(i);
	}

	cout << countZero << endl;

	return 0;
}