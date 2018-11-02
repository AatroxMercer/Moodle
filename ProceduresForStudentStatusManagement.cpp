#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

const int _MAX_ = 100000;

struct Student
{
  public:
    Student() {}
    void init(string id, string classId, string name, double s1, double s2, double s3) {
      _id = id;
      _class = classId;
      _name = name;
      _s1 = s1;
      _s2 = s2;
      _s3 = s3;
    }

    bool check(string feature) {
      if (feature == _id || feature == _class || feature == _name)
      {
        return true;
      }
      return false;
    }

    double total() {
      return _s1 + _s2 + _s3;
    }

    static int count;

    string _id, _class;
    string _name;
    double _s1, _s2, _s3;

} stu[_MAX_];
int Student::count = 0;

void outMenu() {
  cout << "1.input" << endl;
  cout << "2.delete" << endl;
  cout << "3.select" << endl;
  cout << "4.order" << endl;
  cout << "5.output" << endl;
  cout << "6.quit" << endl;
  cout << "please input your option" << endl;
}

void _input() {
  string id, classId;
  string name;
  double s1, s2, s3;

  cout << "Id ", cin >> id;
  cout << "class ", cin >> classId;
  cout << "name ", cin >> name;
  cout << "score1 ", cin >> s1;
  cout << "score2 ", cin >> s2;
  cout << "score3 ", cin >> s3;


  bool isNotFound = true;
  for (int i = 0; i < Student::count; ++i)
  {
    if (stu[i].check(id))
    {
      isNotFound = false;
      stu[i].init(id, classId, name, s1, s2, s3);
      break;
    }
  }
  if (isNotFound)
  {
    stu[Student::count++].init(id, classId, name, s1, s2, s3);
  }

  string order;
  cout << "continue?" << endl, cin >> order;
  if (order == "yes")
  {
    _input();
  } else {
    if (order == "no")
    {
      return ;
    }
  }
}

void _delete() {
  void _output();

  string feature;
  cin >> feature;
  
  for (int i = 0; i < Student::count && Student::count > 1; ++i)
  {
    if (stu[i].check(feature))
    {
      stu[i] = stu[--Student::count];
      break;
    }
  }

  _output();

  string order;
  cout << "continue?" << endl, cin >> order;
  if (order == "yes")
  {
    _delete();
  } else {
    if (order == "no")
    {
      return ;
    }
  }
}

bool cmp(Student sl, Student sr) {
  if (sl._class == sr._class)
   {
    return sl.total() > sr.total();
   } else {
    return sl._class < sr._class;
   }
}

void _select() {
  void output(Student);
  void _output();

  string feature;
  cin >> feature;

  bool isNotFound = true;

  _output();
  for (int i = 0; i < Student::count; ++i)
  {
    if (stu[i].check(feature))
    {
      isNotFound = false;
      output(stu[i]);
    }
  }

  if (isNotFound)
  {
    cout << "there is no eligible student" << endl;
  }
}

void _order() {
  void _output();

  sort(stu, stu+Student::count, cmp);

  _output();
}

void output(Student s) {
  cout << s._id << ",";
  cout << s._class << ",";
  cout << s._name << ",";
  cout << s._s1 << ",";
  cout << s._s2 << ",";
  cout << s._s3 << ",";
  cout << s.total() << endl;
}

void _output() {
  for (int i = 0; i < Student::count; ++i)
  {
    output(stu[i]);
  }
}

void pfssm() {
  int order;
  while (true) {
    outMenu();

    cin >> order;
    // cout << order;

    switch (order) {
      case 1:
        _input();
        break;
      case 2:
        _delete();
        break;
      case 3:
        _select();
        break;
      case 4:
        _order();
        break;
      case 5:
        _output();
        break;
      case 6:
        return;
        break;
      case 0:
        return;
        break;

      default:
        break;
    }
  }
}

int main(int argc, char const *argv[])
{
  cout << setiosflags(ios::fixed) << setprecision(1);

  stu[Student::count++].init("1001", "11", "zhang", 99.5, 88.5, 89.5);
  stu[Student::count++].init("1002", "12", "tang", 77.9, 56.5, 87.5);
  stu[Student::count++].init("1003", "11", "liang", 92.5, 99.0, 60.5);

  pfssm();

  return 0;
}