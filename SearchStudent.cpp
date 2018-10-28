#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <iomanip>
using namespace std;

const int _MAX_ = 7;

struct student
{
  int id, _class;
  string name;
  double g1, g2, g3;
}stu[] ={
  {10001, 11, "Zhang", 99.5, 88.5, 89.5},
  {10002, 12, "Yang", 77.9, 56.5, 87.5},
  {10003, 11, "Liang", 92.5, 99.0, 60.5},
  {10004, 11, "Cai", 89.6, 56.9, 90.5},
  {10005, 14, "Fu", 55.6, 67.9, 98.9},
  {10006, 12, "Mao", 22.1, 45.9, 99.2},
  {10007, 13, "Zhan", 35.6, 67.9, 88.0}
};

void outStu(int i) {
  cout << stu[i].id << " " << stu[i]._class << " " << stu[i].name << " ";
  cout << fixed << setprecision(1) << stu[i].g1 << " " << stu[i].g2 << " " << stu[i].g3 << endl;
}

bool cmp(student l, student r) {
  if (l._class - r._class)
  {
    return l._class < r._class;
  } else {
    double gl = l.g1 + l.g2 + l.g3;
    double gr = r.g1 + r.g2 + r.g3;
    return gl > gr;
  }
}

void translateString(char c, string& content) {
  for (int i = 0; i < (int)content.length(); ++i)
  {
    if (content[i] == c)
    {
      content[i] = ' ';
    }
  }
}

void byClass() {
  string orders;
  getline(cin, orders);
  translateString('-', orders);

  int lclass, rclass;
  //ss : string stream
  istringstream ss(orders);
  ss >> lclass >> rclass;
  // cout << lclass << " " << rclass << endl;

  for (int i = 0; i < _MAX_; ++i)
  {
    if (stu[i]._class >= lclass && stu[i]._class <= rclass)
    {
      outStu(i);
    }
  }
}

void byId() {
  string orders;
  getline(cin, orders);
  translateString('-', orders);

  int lid, rid;
  //ss : string stream
  istringstream ss(orders);
  ss >> lid >> rid;
  // cout << lid << " " << rid << endl;

  for (int i = 0; i < _MAX_; ++i)
  {
    if (stu[i].id >= lid && stu[i].id <= rid)
    {
      outStu(i);
    }
  }
}

bool checkName(int index, string name) {
  for (int i = 0; i < (int)name.length(); ++i)
  {
    if (name[i] == '*')
    {
      return true;
    } else if (name[i] != stu[index].name[i])
    {
      return false;
    }
  }
  return false;
}

void  byName() {
  string name;
  cin >> name;

  for (int i = 0; i < _MAX_; ++i)
  {
    if (checkName(i, name))
    {
      outStu(i);
    }
  }
}

void byGrade() {
  double g;
  cin >> g;
  for (int i = 0; i < _MAX_; ++i)
    {
      double stuG = stu[i].g1 + stu[i].g2 + stu[i].g3;
      if (stuG >= g)
      {
        outStu(i);
      }
    }

}

void byClassAndId() {

  string orders;
  getline(cin, orders);
  translateString('-', orders);
  translateString('.', orders);

  int _class, lid, rid;
  //ss : string stream
  istringstream ss(orders);
  ss >> _class >> lid >> rid;
  // cout << _class << " " << lid << " " << rid << endl;

  for (int i = 0; i < _MAX_; ++i)
  {
    if (stu[i]._class == _class && stu[i].id >= lid && stu[i].id <= rid)
    {
      outStu(i);  
    }
  }
}

void order(int type) {
  switch (type) {
    case 1: 
      byClass();
      break;
    case 2:
      byId(); 
      break;
    case 3:
      byName();
      break;
    case 4:
      byGrade();
      break;
    case 5:
      byClassAndId();
      break;
  }
}

int main(int argc, char const *argv[])
{
  int input;

  cin >> input;
  sort(stu,stu +  _MAX_, cmp);

  order(input);

  return 0;
}