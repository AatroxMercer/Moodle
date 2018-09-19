#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int int1, int2;

	cin >> int1 >> int2;

	cout << (int1>int2?int2:int1) << " " << (int1>int2?int1:int2) << endl;

	return 0;
}