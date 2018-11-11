#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct Student
{
	int id, class_;
	float grade1, grade2, grade3;
	float total;
}	stu[3];

bool cmp(Student left, Student right) {
	if (left.class_ - right.class_)
	{
		return left.class_ > right.class_;
	}
	else
	{
		return left.total < right.total;
	}
}

int main(int argc, char const *argv[])
{	
	int lastClass = 0;

	for (int i = 0; i < 3; ++i)
	{
		cin >> stu[i].id >> stu[i].class_ >> stu[i].grade1 >> stu[i].grade2 >> stu[i].grade3;
		stu[i].total = stu[i].grade1 + stu[i].grade2 + stu[i].grade3;
	}

	sort(stu, stu + 3, cmp);

	for (int i = 0; i < 3; ++i)
	{
		if (stu[i].class_ - lastClass)
		{
			if (lastClass)
			{
				cout << endl;
			}
			lastClass = stu[i].class_;
			cout << lastClass << ',';
		}
		else {
			cout << ';';
		}
		cout << stu[i].id << ',';
		printf("%.1f", stu[i].total);
	}

	return 0;
}