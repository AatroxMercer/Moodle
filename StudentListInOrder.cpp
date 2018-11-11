#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

void output30spaces() {
	for (int i = 0; i < 30; ++i)
	{
		cout << " ";
	}
}

struct Student
{
	int id;
	float math, physics, english;
	float grades, aver_grades;
} stu[3];

bool cmp(Student l, Student r) {
	return l.grades < r.grades;
}

int main(int argc, char const *argv[])
{
	
	char order;

	output30spaces();
	cout << "1.Input" << endl;
	output30spaces();
	cout << "2.Output" << endl;
	output30spaces();
	cout << "3.Order" << endl;
	output30spaces();
	cout << "4.Quit" << endl;

	cin >> order;

	if (order == 'i')
	{
		// cout << "You are trying to Input info";
		cout << "Please input info of the three students:" << endl;

		for (int i = 0; i < 3; ++i)
		{
			cin >> stu[i].id >> stu[i].math >> stu[i].physics >> stu[i].english;
			stu[i].grades = stu[i].math + stu[i].physics + stu[i].english;
			stu[i].aver_grades = stu[i].grades / 3.0;
		}

		sort(stu, stu + 3, cmp);

		for (int i = 0; i < 3; ++i)
		{
			printf("%d,%.1f,%.1f\n", stu[i].id, stu[i].grades, stu[i].aver_grades);
		}
	}
	/*else if (order == 'o')
	{
		cout << "You are trying to Output info";
	}*/
	else if (order == 'm')
	{
		cout << "You are trying to Make things ordered" << endl;
	}
	else if (order == 'q')
	{
		cout << "You are about to Quit" << endl;
	}
	else
	{
		cout << "Wrong input" << endl;
	}

	return 0;
}