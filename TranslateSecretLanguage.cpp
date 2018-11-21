#include <iostream>
#include <string>
using namespace std;

const int _MAX_ = 19;

struct keylock
{
  char lock, key;
} map[] = {
  {'a', 'd'}, {'b', 'w'}, {'c', 'k'}, {'d', ';'}, {'e', 'i'}, {'f', 'h'}, {'g', 'm'}, {'h', 'o'}, {'i', 'a'}, {'j', 'z'}, {'k', 'b'}, {'l', 'n'}, {'m', 'y'}, {';', 'c'}, {'w', 'e'}, {'o', 'f'}, {'y', 'g'}, {'z', 'j'}, {'n', 'l'}
};

int main(int argc, char const *argv[])
{
  string in;
  getline(cin, in);

  for (int i = 0; i < (int)in.length(); ++i)
  {
    for (int j = 0; j < _MAX_; ++j)
    {
      if (in[i] == map[j].key)
      {
        in[i] = map[j].lock;
        break;
      }
    }
  }

  cout << in << endl;

  return 0;
}