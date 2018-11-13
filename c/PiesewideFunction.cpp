#include <iostream>
using namespace std;

int f(int x) {
  if (x)
  {
    return x  > 0 ? 3 * x + 1 : x * x  - 1;
  } else {
    return x;
  }
}

int main(int argc, char const *argv[])
{
  int x, y;

  cin >> x;

  y = f(x);

  cout << y << endl;

  return 0;
}