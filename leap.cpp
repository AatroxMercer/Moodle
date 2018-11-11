#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int year;
	char is_leap;

	cin >> year;
	is_leap = 'N';

	if (!(year % 4) && year % 100 || !(year % 400)) {
		is_leap = 'Y';
	}

	cout << is_leap << endl;

	return 0;
}