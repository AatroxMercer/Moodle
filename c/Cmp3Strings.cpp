#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int _MAX_ = 3;
const int _MAX_LENGTH_ = 100;

void compare(string * s[]) {
  string temp[_MAX_];
  for (int i = 0; i < _MAX_; ++i)
  {
    temp[i] = *s[i];
    // cout << temp[i] << endl;
  }

  int _max = 0;
  for (int i = 0; i < _MAX_LENGTH_; ++i)
  {
    if (temp[_max][i] == temp[1][i] && temp[_max][i] == temp[2][i])
    {
      continue;
    }

    for (int j = 0; j < _MAX_; ++j)
    {
      if (temp[_max][i] < temp[j][i])
      {
        _max = j;
      }
    }

    cout << temp[_max] << endl;
    break;
  }
}

int main(int argc, char const *argv[])
{
  string input[_MAX_] ;
  string* pointer[_MAX_];
  for (int i = 0; i < _MAX_; ++i)
  {
    getline(cin, input[i]);
    pointer[i] = &input[i];
  }

  compare(pointer);

  return 0;
}