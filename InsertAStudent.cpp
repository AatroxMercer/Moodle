#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
using namespace std;

const int _max = 4;

struct Student
{
	int id, _class;
	double math, physics, english;
	double total;
	bool isInserted;
} stu[_max];

bool cmp(Student left, Student right) {
	if (left._class - right._class)
	{
		return left._class < right._class;
	}
	else
	{
		return left.total > right.total;
	}
}

void init() {
	for (int i = 0; i < _max - 1; ++i)
	{
		if (stu[i].id == stu[3].id)
		{
			stu[3].id = 10000;
		}
	}
}

int main(int argc, char const *argv[])
{
	memset(stu, 0, sizeof(stu));
	stu[0] = {10001, 11, 99.5, 88.5, 89.5, 277.5, false};
	stu[1] = {10002, 12, 77.9, 56.5, 87.5, 221.9, false};
	stu[2] = {10003, 11, 92.5, 99.0, 60.5, 252.0, false};
	cin >> stu[3].id >> stu[3]._class >> stu[3].math >> stu[3].physics >> stu[3].english;
	stu[3].isInserted = true;
	stu[3].total = stu[3].math + stu[3].physics +stu[3].english;

	init();
	sort(stu, stu + _max, cmp);

	for (int i = 0; i < _max; ++i)
	{
		cout << stu[i].id << " " << stu[i]._class << " ";
		cout << fixed << setprecision(1) << stu[i].math << " " << stu[i].physics << " " << stu[i].english;
		if (stu[i].isInserted)
		{
			cout << " inserted";
		}
		cout << endl;
	}

	return 0;
}