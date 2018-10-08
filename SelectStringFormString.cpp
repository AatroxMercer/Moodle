#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int _max = 1000;
char sample[_max], dataset[_max];
int datasetLength, sampleLength;

bool match(int index) {
	for (int i = 0; i < sampleLength; ++i)
	{
		if (sample[i] - dataset[index + i])
		{
			// cout << index + i << endl;
			return false;
		}
	}

	return true;
}

int main(int argc, char const *argv[])
{
	memset(dataset, 0, sizeof(dataset));
	memset(sample, 0, sizeof(sample));

	int index = 0;

	gets(dataset);
	gets(sample);
	datasetLength = strlen(dataset);
	sampleLength = strlen(sample);

	for (int i = 0; i < datasetLength - sampleLength; ++i)
	{
		if (dataset[i] == sample[0])
		{
			// cout << i << endl;
			if (match(i))
			{
				index = ++i;
				break;
			}
		}
	}

	cout << index<< endl;

	return 0;
}