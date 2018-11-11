#include <iostream>
#include <iomanip>
using namespace std;;

int main(int argc, char const *argv[])
{
	double a = 3.5;
	int b = 10;

	cout << left << fixed << setw(6) << setfill('0') << setprecision(2) << a << endl;
	cout << a;
	return 0;
}
