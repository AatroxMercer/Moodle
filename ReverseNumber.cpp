#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
  string input;
  cin >> input;
  bool isHead = true;
  for (int i = input.length() - 1; i >= 0; --i)
  {
    if (input.length() == 1)
    {
      cout << input[i] << endl;
      return 0;
    }
    if (isHead && input[i] == '0')
    {
      continue;
    } else {
      isHead = false;
    }
    // cout << isHead;
    cout << input[i];
  }
  cout << endl;

  return 0;
}     