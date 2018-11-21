#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(int argc, char const *argv[])
{
  string in;

  getline(cin, in);
  
  for (int i = 0; i < (int)in.length(); ++i)
  {
    if (islower(in[i]))
    {
      in[i] -= 32;
    }
  }

  cout << in << endl;

  return 0;
}