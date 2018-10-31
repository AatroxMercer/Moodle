#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
using namespace std;

const int _MAX_LENGTH_ = 50;
char input[_MAX_LENGTH_];

void count(char *input, int length) {
  int s, c, l, n;
  s = c = l = n = 0;

  for (int i = 0; i < length; ++i)
  {
      char* temp = input+i;
      if (islower(*temp))
      {
        l++;
        continue;
      } else if (isupper(*temp))
      {
        c++;
        continue;
      } else if (isspace(*temp))
      {
        s++;
        continue;
      } else if (isdigit(*temp))
      {
        n++;
        continue;
      }
  }
  cout << "space: " << s-1 << endl;
  cout << "capital: " << c << endl;
  cout << "lowercase: " << l << endl;
  cout << "number: " << n << endl;
}

int main(int argc, char const *argv[])
{
  gets(input);
  // puts(input);

  count(input, strlen(input));

  return 0;
}