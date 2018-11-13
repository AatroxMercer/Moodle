#include <iostream>
using namespace std;

unsigned long long Hanoi(int l, int c, int r, unsigned long long m) {
  if (m == 1)
  {
    cout << m << ": " << l << ">-" << c << "->" << r << endl;
    return 1;
  } else {
    return Hanoi(1, 3, 2, m-1) + Hanoi(1, 2, 3, 1) + Hanoi(2, 1, 3, m-1);
  }
}

unsigned long long power(unsigned long long basic, unsigned long long pointer) {
  if (!pointer)
  {
    return 1;
  } else {
    // return basic * power(basic, pointer - 1);
    return (basic * power(basic , pointer - 1)) % 1000000;
  }

}

unsigned long long Hanoi(unsigned long long m) {
  return (power(2, m) - 1) % 1000000;
}

int main(int argc, char const *argv[])
{ 
  // freopen("./freopen/output.out", "w", stdout);

  unsigned long long m;
  cin >> m;

  unsigned long long ans;
  // ans = Hanoi(1, 2, 3, m);
  ans = Hanoi(m);

  cout << ans << endl;

  return 0;
}