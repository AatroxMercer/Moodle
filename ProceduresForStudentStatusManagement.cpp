#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

const int _MAX_ = 100;

struct  Student
{
public:
    static int _count;
    string _id, _class, _name;
    double _score1, _score2, _score3;
    double _total;

    static void bye() {
        Student::_count--;
    }

    void init(
        string id,
        string classId,
        string name,
        double s1,
        double s2,
        double s3
    ) {
        _id = id;
        _class = classId;
        _name = name;
        _score1 = s1;
        _score2 = s2;
        _score3 = s3;
        _total = s3 + s2 + s1;
    }

    bool check(string _feature) {
        return _feature == _id || _feature == _class || _feature == _name;
    }

    void output() {
        cout << _id << ",";
        cout << _class << ",";
        cout << _name << ",";
        cout << _score1 << ",";
        cout << _score2 << ",";
        cout << _score3 << ",";
        cout << _total << endl;
    }
} stdnt[_MAX_];
int Student::_count = 0;
int & _count = Student::_count;

int main(int argc, char const *argv[])
{
    void pfssm();
    cout << setiosflags(ios::fixed) << setprecision(1);

    stdnt[_count++].init("1001", "11", "zhang", 99.5, 88.5, 89.5);
    stdnt[_count++].init("1002", "12", "tang", 77.9, 56.5, 87.5);
    stdnt[_count++].init("1003", "11", "liang", 92.5, 99.0, 60.5);

    pfssm();
    return 0;
}

void outMenu() {
    cout << "1.input" << endl;
    cout << "2.delete" << endl;
    cout << "3.select" << endl;
    cout << "4.order" << endl;
    cout << "5.output" << endl;
    cout << "6.quit" << endl;
    cout << "please input your option" << endl;
}

void pfssm() {
    void input();
    void remove();
    void select();
    void order();
    void output();

    int _mission;

    while (true) {
        outMenu();
        cin >> _mission;

        switch (_mission) {
        case 1:
            input();
            break;
        case 2:
            remove();
            break;
        case 3:
            select();
            break;
        case 4:
            order();
            break;
        case 5:
            output();
            break;

        default:
            return;
            break;
        }
    }
}

void output() {
    for (int i = 0; i < _count; ++i)
    {
        stdnt[i].output();
    }
}

void input() {
    string id, classId;
    string name;
    double s1, s2, s3;

    cout << "Id ", cin >> id;
    cout << "class ", cin >> classId;
    cout << "name ", cin >> name;
    cout << "score1 ", cin >> s1;
    cout << "score2 ", cin >> s2;
    cout << "score3 ", cin >> s3;

    bool isExist = false;
    for (int i = 0; i < _count; ++i)
    {
        if (stdnt[i].check(id))
        {
            isExist = true;
            stdnt[i].init(id, classId, name, s1, s2, s3);
        }
    }

    if (!isExist)
    {
        stdnt[_count++].init(id, classId, name, s1, s2, s3);
    }

    string _mission;
    cout << "continue?" << endl, cin >> _mission;
    if (_mission == "yes")
    {
        input();
    } else {
        // if (_mission == "no")
        // {
        return ;
        // }
    }
}

void _delete(int index) {
    for (int i = index; i < _count; ++i)
    {
        stdnt[i]  = stdnt[i + 1];
    }
    Student::bye();
}

void remove() {
    string _feature;
    cin >> _feature;

    if (_count > 1)
    {
        for (int i = 0; i < _count; ++i)
        {
            if (stdnt[i].check(_feature))
            {
                _delete(i);
                break;
            }
        }
    }
    output();

    string _mission;
    cout << "continue?" << endl, cin >> _mission;
    if (_mission == "yes")
    {
        remove();
    } else {
        // if (_mission == "no")
        // {
        return ;
        // }
    }
}

void select() {
    string _feature;
    cin >> _feature;

    for (int i = 0; i < _count; ++i)
    {
        if (stdnt[i].check(_feature))
        {
            stdnt[i].output();
        }
    }

    string _mission;
    cout << "continue?" << endl, cin >> _mission;
    if (_mission == "yes")
    {
        select();
    } else {
        // if (_mission == "no")
        // {
        return ;
        // }
    }
}

bool orderCmp(Student sl, Student sr) {
    if (sl._class == sr._class)
    {
        return sl._class < sr._class;
    } else {
        return sl._total > sr._total;
    }
}

void order() {
    sort(stdnt, stdnt + _count, orderCmp);

    output();
}
