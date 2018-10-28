#include <iostream>
#include <cstdio>
using namespace std;

double toFahrenheit(double c) {
  return 1.8 * c + 32;
}

int main(int argc, char const *argv[])
{
  double input;

  cin >> input;

  cout << "Fahrenheit temperature is " << toFahrenheit(input) << " degree" << endl;

  return 0;
}