#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

class Student
{

private:
    string name, id, classNum;
    double score1, score2, score3;

public:
    static int number;
    static Student * head;
    static Student * foot;
    Student * next;

    double score() {
        return this->score1 + this->score2 + this->score3;
    }

    //更新学生信息
    void init() {
        this->next = nullptr;
    }
    void init(
        string id,
        string classId,
        string name,
        double s1,
        double s2,
        double s3
    ) {
        this->id = id;
        this->classNum = classId;
        this->name = name;
        this->score1 = s1;
        this->score2 = s2;
        this->score3 = s3;
        this->next = nullptr;
    }

    //格式化输出学生信息
    void output() {
        cout << id << ",";
        cout << classNum << ",";
        cout << name << ",";
        cout << score1 << ",";
        cout << score2 << ",";
        cout << score3 << ",";
        cout << this->score() << endl;
    }

};
int Student::number = 0;
int & number = Student::number;
Student * Student::head = nullptr;
Student * & head = Student::head;
Student * Student::foot = nullptr;
Student * & foot = Student::foot;

//创建新的元素
Student * create() {
}
Student * create(
        string id,
        string classId,
        string name,
        double s1,
        double s2,
        double s3
    ) {
}

//加入到链表的尾部
void add(Student * stu) {
}
void add(
        string id,
        string classId,
        string name,
        double s1,
        double s2,
        double s3
        ) {

}

int main(int argc, char const *argv[])
{

    void pfssm();

    //修改cout格式
    cout << setiosflags(ios::fixed) << setprecision(1);

    //添加初值
    // Student temp, tmp, t;
    // temp.init();
    // tmp.init("1002", "12", "tang", 77.9, 56.5, 87.5);
    // t.init("1003", "11", "liang", 92.5, 99.0, 60.5);
    // add(create("1001", "11", "zhang", 99.5, 88.5, 89.5));
    // add(&tmp);
    // add(&t);

    //启动主体程序
    pfssm();
    return 0;

}

//输出菜单
void outMenu() {
    cout << "1.input" << endl;
    cout << "2.delete" << endl;
    cout << "3.select" << endl;
    cout << "4.order" << endl;
    cout << "5.output" << endl;
    cout << "6.quit" << endl;
    cout << "please input your option" << endl;
    output();
}

//管理系统
void pfssm() {
    void input();
    void remove();
    void select();
    void order();
    void output();

    int mission;

    while (true) {
        outMenu();
        cin >> mission;

        switch (mission) {
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

//输出当前所有学生信息
void output() {
}

//添加学生信息
void input() {
}


//删除学生信息
void remove() {
}


//筛选学生信息
void select() {
}

//给学生信息排序
void order() {
}
