#include <iostream>
#include <string>
using namespace std;

struct Student
{
  public:
    Student(int id, int classId, string name, double s1, double s2, double s3) :
        _id(id),
        _class(classId),
        _name(name),
        _s1(s1),
        _s2(s2),
        _s3(s3)
    {
    } 

    int _id, _class;
    string _name;
    double _s1, _s2, _s3;

};

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
  cout << "Id ";
  cin >> 
}

void _delete() {
  
}

void _select() {
  
}

void _order() {
  
}

void _output() {
  
}

void _quit() {

}

void pfssm() {
  int order;
  while (true) {
    outMenu();

    cin >> order;

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
        // _quit();
        return;

      default:
        break;
    }
  }
}

int main(int argc, char const *argv[])
{
  pfssm();

  return 0;
}