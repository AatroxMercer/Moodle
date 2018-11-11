#include <iostream>
using namespace std;

const int _max = 100;
int s[_max][_max];
void drawSnake(int n) {
	int count = 1;
	int h = 0, l = n - 1;
	s[h][l] = count;

	while (count < n*n) {
		while (h+1 < n && !s[h+1][l]) {
			s[++h][l] = ++count;
			// cout << "+h" << endl;
		}
		while (l-1 >= 0 && !s[h][l-1]) {
			s[h][--l] = ++count;
			// cout << "-l" << endl;
		}
		while (h-1 >= 0 && !s[h-1][l]) {
			s[--h][l] = ++count;
			// cout << "-h" << endl;
		}
		while (l+1 < n && !s[h][l+1]) {
			s[h][++l] = ++count;
			// cout << "+l" << endl;
		}
		// cout << count << endl;
	}
}

int main(int argc, char const *argv[])
{
	int n;

	cin >> n;

	drawSnake(n);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << s[i][j];
			if (j != n-1)
			{
				cout << " ";
			}
		}
		cout << endl;
	}

	return 0;
}