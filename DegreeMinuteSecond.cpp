#include <cstdio>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	float degree, minute, second;

	cin >> degree >> minute >> second;
	cout << degree << " degrees, " << minute << " minutes, " << second << " seconds = ";

	minute += second / 60;
	degree += minute / 60;

	cout << degree << " degrees" << endl;
	
	return 0;
}