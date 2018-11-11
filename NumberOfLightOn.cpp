#include <iostream>
using namespace std;

bool lights[1000 + 1];

int main(int argc, char const *argv[])
{
	int n, k;

	cin >> n >> k;

	for (int i = 1; i <= k; ++i)
	{
		for (int j = i; j <= n; j += i)
		{
			lights[j] = !lights[j];
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		if (lights[i])
		{
			cout << i << " ";
		}
	}
	cout << endl;
	
	return 0;
}