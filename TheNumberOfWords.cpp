#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int _max = 100;
char input[_max];

int main(int argc, char const *argv[])
{
	int count = 0;

	memset(input, 0, sizeof(input));
	while (scanf("%s", input) != EOF) {
		if (!strcmp(input, "done"))
		{
			break;
		}
		count++;
	}

	cout << "You entered a total of " << count << " words." << endl;

	return 0;
};