#include <iostream>
namespace asm2n8
{
  std::istream& cin = std::cin;
  namespace _Private
  {
    static long double const two = 2;
  }
}

using namespace asm2n8;
using namespace _Private;

int main()
{
  std::cout << two;
}

