#include <iostream>
#include <cmath>
using namespace std;

bool check(int num) {
	for (int i = 2; i <= sqrt(num); ++i)
	{
		if (num % i == 0)
		{
			return false;
		}
	}

	if (num <= 1)
	{
		return false;
	}
	
	return true;
}

int main(int argc, char const *argv[])
{
	int N, temp;
	int ans;
	
	cin >> N;
	ans = 0;

	while (N--) {
		cin >> temp;
		if (check(temp))
		{
			ans += temp;
		}
	}

	cout << ans << endl;

	return 0;
}