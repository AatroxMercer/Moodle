#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

char input[100];
int digits, letters, blankSpace;

void check(int _char) {
	if (_char >= 48 && _char <= 57)
	{
		digits++;
		// cout << "digit" << endl;
	}
	else if (_char >= 65 && _char <= 90)
	{
		letters++;
		// cout << "letter" << endl;
	} 
	else if (_char >= 97 && _char <= 122)
	{
		letters++;
		// cout << "letter" << endl;
	}
	else if (_char == ' ')
	{
		blankSpace++;
		// cout << "blackSpace" << endl;
	}
}

int main(int argc, char const *argv[])
{	
	int length;

	gets(input);
	length = strlen(input);
	// cout << length << endl;

	for (int i = 0; i < length; ++i)
	{
		check(input[i]);
	}

	cout << digits << " ";
	cout << letters << " ";
	cout << blankSpace << " ";
	cout << endl;
	return 0;
}