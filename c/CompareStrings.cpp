#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int _max = 1000;
char sample[_max];

int main(int argc, char const *argv[])
{
	int sampleLength;
	int index;

	index = 0;
	memset(sample, 0, sizeof(sample));
	gets(sample);
	sampleLength = strlen(sample);

	for (int i = 0; i < sampleLength; ++i)
	{
		if (getchar() != sample[i])
		{
			index = ++i;
			break;
		}
	}

	cout << index << endl;
	return 0;
}