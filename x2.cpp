#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
	double a, b, c;
	double delta, ans;

	cin >> a >> b >> c;

	delta = b * b - 4 * a * c;
	ans = -b / (2 * a);

	if (delta < 0)
	{
		cout << "no root" << endl;
	}
	else if (!delta)
	{
		if (ans == -0)
		{
			ans = 0;
		}
		cout << ans << endl;
	}
	else {
		delta = sqrt(delta);
		cout << ans - delta / (2 * a) << " ";
		cout << ans + delta / (2 * a) << " ";
	}

	return 0;
}