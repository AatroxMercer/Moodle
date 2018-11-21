#include <cstdio>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

const int STUDENT_MAX = 3;
const int NAME_MAX = 15;
char name[STUDENT_MAX][NAME_MAX];

struct Student
{
	int id, _class;
	int nameIndex;
	double g1, g2, g3, grade;
	bool isModified;
} stu[STUDENT_MAX];

void setStudent() {
	int newId;

	cin >> newId;

	for (int i = 0; i < STUDENT_MAX; ++i)
	{
		if (stu[i].id == newId)
		{
			cin >> stu[i]._class;
			scanf("%s", name[stu[i].nameIndex]);
			cin >> stu[i].g1 >> stu[i].g2 >> stu[i].g3;
			stu[i].grade = stu[i].g1 + stu[i].g2 + stu[i].g3;
			stu[i].isModified = true;
		}
	}
}

bool cmp(Student left, Student right) {
	if (left._class - right._class)
	{
		return left._class < right._class;
	}
	else {
		return left.grade > right.grade;
	}
}

int main(int argc, char const *argv[])
{
	memset(stu, 0, sizeof(stu));
	memset(name, 0, sizeof(name));

	int nowClass = -1;

	stu[0] = {10001, 11, 0, 99.5, 88.5, 89.5, 277.5};
	strcpy(name[0], "Zhang");
	stu[1] = {10002, 12, 1, 77.9, 56.5, 87.5, 221.9};
	strcpy(name[1], "Yang");
	stu[2] = {10003, 11, 2, 92.5, 99.0, 60.5, 252.0};
	strcpy(name[2], "Liang");

	sort(stu, stu + STUDENT_MAX, cmp);
	setStudent();
	sort(stu, stu + STUDENT_MAX, cmp);

	for (int i = 0; i < STUDENT_MAX; ++i)
	{
		if (nowClass - stu[i]._class)
		{
			nowClass = stu[i]._class;
			cout << stu[i]._class << " " << stu[i].id;
		} else
		{
			cout << "   " << stu[i].id;
		}

		printf(" %s ", name[stu[i].nameIndex]);
		cout << fixed << setprecision(1) << stu[i].g1 << " " << stu[i].g2 << " " << stu[i].g3;
		
		if (stu[i].isModified)
		{
			cout << " modified";
		}

		cout << endl;
	}

	return 0;
}