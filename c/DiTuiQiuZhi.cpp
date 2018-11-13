#include <iostream>
using namespace std;

const int _MAX_ = 1000007;

int main(int argc, char const *argv[])
{
  long left, right, ans;
  long long a, b, c, n;
  cin >> left >> right >> a >> b >> c >> n;

  for (long long i = 3; i <= n; ++i)
  {
    ans = a * left + b * right + c,
    ans %= _MAX_;
    left = right, right = ans;
  }

  if (ans < 0)
  {
    ans += _MAX_;
  }
  cout << ans << endl;

  return 0;
}