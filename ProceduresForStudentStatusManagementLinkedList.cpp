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
    static Student* head;
    static Student* tail;
    Student* next;
    Student* last;

    bool operator==(const Student& that) {
        return this->name == that.name || this->id == that.id || this->classNum == that.classNum;
    }
    bool operator<(const Student& that) {
        if (this->getClassNum() == that.getClassNum())
        {
            return this->score() > that.score();
        } else {
            return this->getClassNum() < that.getClassNum();
        }
    }
    bool operator>(const Student& that) {
        if (this->getClassNum() == that.getClassNum())
        {
            return this->score() < that.score();
        } else {
            return this->getClassNum() > that.getClassNum();
        }
    }

    bool check(string feature) const {
        return feature == id || feature == classNum || feature == name;
    }

    string getClassNum() const {
        return this->classNum;
    }
    double score() const {
        return this->score1 + this->score2 + this->score3;
    }

    //更新学生信息
    void init() {
        this->next = nullptr;
        this->last = nullptr;
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
        this->last = nullptr;
    }

    //格式化输出学生信息
    void output() const {
        cout << this->id << ",";
        cout << this->classNum << ",";
        cout << this->name << ",";
        cout << this->score1 << ",";
        cout << this->score2 << ",";
        cout << this->score3 << ",";
        cout << this->score() << endl;
    }

};
int Student::number = 0;
int & number = Student::number;
Student* Student::head = nullptr;
Student* & head = Student::head;
Student* Student::tail = nullptr;
Student* & tail = Student::tail;

//创建新的元素
Student* create() {
    Student* newOne = new Student;
    return newOne;
}
Student* create(
        string id,
        string classId,
        string name,
        double s1,
        double s2,
        double s3
    ) {
    Student* newOne = new Student;
    newOne->init(id, classId, name, s1, s2, s3);
    return newOne;
}

//加入到链表的尾部
void add(Student* stu) {
    if (head == nullptr)
    {
        head = stu;
        tail = stu;
    } else {
        tail->next = stu;
        stu->last = tail;
        tail = stu;
    }
    number++;
}
//判断是否存在，加到尾部或者替换已有
void add(
    string id,
    string classId,
    string name,
    double s1,
    double s2,
    double s3
    ) {
    Student* temp = head;
    Student* newOne = create(id, classId, name, s1, s2, s3);
    bool isExist = false;

    while (temp != nullptr) {
        if (&temp == &newOne)
        {
            isExist = true;
            temp->init(id, classId, name, s1, s2, s3);
            delete newOne;
            break;
        } else {
            temp = temp->next;
        }
    }

    if (!isExist)
    {
        add(newOne);
    }
}

int main(int argc, char const*argv[])
{

    void pfssm();

    //修改cout格式
    cout << setiosflags(ios::fixed) << setprecision(1);

    //添加初值
    add(create("1002", "12", "tang", 77.9, 56.5, 87.5));
    add(create("1003", "11", "liang", 92.5, 99.0, 60.5));
    add(create("1001", "11", "zhang", 99.5, 88.5, 89.5));

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
    Student* temp = head;
    while(temp != nullptr) {
        temp->output();
        temp = temp->next;
    }
}

//添加学生信息
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

    add(id, classId, name, s1, s2, s3);

    string mission;
    cout << "continue?" << endl, cin >> mission;
    if (mission == "yes")
    {
        input();
    } else {
        if (mission == "no")
        {
            return ;
        }
    }
}

//删除学生信息
void remove() {
    string feature;
    cin >> feature;

    if (number > 1)
    {
        Student* temp = head;
        while (temp != nullptr) {
            if (temp->check(feature))
            {
                if (temp == head)
                {
                    head = temp->next;
                } else {
                    Student* last = temp->last;
                    last->next = temp->next;
                }
                delete temp;
                number--;
            }
            temp = temp->next;
        }
    }

    output();

    string mission;
    cout << "continue?" << endl, cin >> mission;
    if (mission == "yes")
    {
        remove();
    } else {
        if (mission == "no")
        {
            return ;
        }
    }
}


//筛选学生信息
void select() {
    string feature;
    cin >> feature;

    Student* temp = head;
    while (temp != nullptr) {
        if (temp->check(feature))
        {
            temp->output();
        }
        temp = temp->next;
    }

    string mission;
    cout << "continue?" << endl, cin >> mission;
    if (mission == "yes")
    {
        select();
    } else {
        if (mission == "no")
        {
            return ;
        }
    }
}

void swap(Student* now, Student* next) {
    if (now == head)
    {
        head = next;
        next->last = nullptr;
    } else {
        Student* nowLast = now->last;
        nowLast->next = next;
        next->last = nowLast;
    }

    if (next == tail)
    {
        tail = now;
        now->next = nullptr;
    } else {
        Student* nextNext = next->next;
        now->next = nextNext;
        nextNext->last = now;
    }

    next->next = now;
    now->last = next;
}

//给学生信息排序
void order() {
    Student* end = tail;
    while (head != end) {
        Student* temp = head;
        while (temp != end) {

        }
    }

    output();
}
