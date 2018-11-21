#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;

bool check(char in) {
  return in == '<' || in == '[' || in == '(' || in == '{';
}

bool cmp(char a, char b) {
  // static map<char, char> mcc = {
  //   {'(', ')'}, {'<', '>'}, {'[', ']'}, {'{', '}'}
  // };
  // return mcc.find(a) != mcc.end() && mcc[a] == b;
  if (a == '<')
  {
    return b == '>';
  }
  if (a == '[')
  {
    return b == ']';
  }
  if (a == '{')
  {
    return b == '}';
  }
  if (a == '(')
  {
    return b == ')';
  }
  return false;
}

int main(int argc, char const *argv[])
{
  stack<char> sc;
  char in;
  while (cin.get(in)) {
    if (in == '\r')
    {
      continue;
    }
    if (in == '\n')
    {
      break;
    }
    // cout << in;

    // cout << check(in);
    if (check(in))
    {
      sc.push(in);
    }
    else {
      if (sc.empty())
      {
        cout << (int)in << endl;
        cout << "No" << endl;
        return 0;
      }
      else {
        if (cmp(sc.top(), in))
        {
          sc.pop();
        } else {
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  if (!sc.empty())
  {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  return 0;
}