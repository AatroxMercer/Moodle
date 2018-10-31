#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  // freopen("./_AscII.txt", "w", stdout);
  for (int i = 0; i < 138; ++i)
  {
    cout << i << ": " << (char)i << endl;
  }
  return 0;
}