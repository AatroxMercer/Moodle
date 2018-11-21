
#include <iostream>
#include <string>
using namespace std;

void zuHe(string out, int num, int left) {
  if (!left)
  {
    cout << out << endl;
  } else {
    for (int i = num; i >= left; --i)
    {
      zuHe(out + (char)('0' + i), i-1, left-1);
    }
  }
}

int main(int argc, char const *argv[])
{
  int n, r;

  cin >> n >> r;

  zuHe("", n, r);

  return 0;
}