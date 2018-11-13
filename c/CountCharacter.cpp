#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int _max = 1000;
char input[_max];

int main(int argc, char const *argv[])
{
	int inputLength;

	memset(input, 0, sizeof(input));
	gets(input);
	// puts(input);
	
	inputLength = strlen(input);

	cout << inputLength << endl;
	// cout << inputLength - 1 << endl;

	return 0;
}