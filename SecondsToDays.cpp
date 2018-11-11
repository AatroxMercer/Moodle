#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
	int input;
	int days, hours, minutes, seconds;

	cin >> input;
	seconds = input;

	days = seconds / (60 * 60 * 24);
	seconds %= (60 * 60 * 24);
	hours = seconds / (60 * 60);
	seconds %= (60 * 60);
	minutes = seconds / 60;
	seconds %= 60;

	printf("%d seconds = %d days, %d hours, %d minutes, %d seconds\n", input, days, hours, minutes, seconds);

	return 0;
}