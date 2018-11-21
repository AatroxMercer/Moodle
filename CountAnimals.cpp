#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

const int _MAX_ = 100;

struct animal
{
  string type;
  int count = 0;
} animals[_MAX_];

void countAnimal(string in) {
  for (int i = 0; i < _MAX_; ++i)
  {
    if (!animals[i].count)
    {
       animals[i].count++;
       animals[i].type = in;
       break;        
    } else {
      if (animals[i].type == in)
      {
        animals[i].count++;
        continue;
      }
    }
  }
}

bool cmp(animal la, animal ra) {
  return la.count > ra.count;
}

int main(int argc, char const *argv[])
{
  string in;
  while (cin >> in) {
    countAnimal(in);
  }
  sort(animals, animals + _MAX_, cmp);

  cout << animals[0].type << " " << animals[0].count << endl;
}