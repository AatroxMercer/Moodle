#include <iostream>
#include <cmath>
using namespace std;

int f(int n, int p) {
  int sum = 0;
  for (int i = 0; i < n; ++i)
  {
    sum += pow(i + 1, p);
    // cout << sum << endl;
  }
  return sum;
}

int main(int argc, char const *argv[])
{
  int n, p;
  cin >> n >> p;

  cout << f(n, p);

  return 0;
}