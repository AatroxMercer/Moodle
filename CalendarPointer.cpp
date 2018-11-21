#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  string months[] = {"Kidding?", "January", "February", "March", "April", "May", "June", "July", "August", "September", "Octorber", "November", "December"};
  int in;
  cin >> in;

  cout << *(months + in);

  return 0;
}