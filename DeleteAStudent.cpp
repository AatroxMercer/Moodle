#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstring>
using namespace std;

const int ARRAY_MAX = 3;
const int STRING_MAX = 100;
char name[ARRAY_MAX][STRING_MAX];
char id[ARRAY_MAX][STRING_MAX];

struct Student
{
	int _class;
	double math, physics, english;
	double total;
	bool isExisting;
} stu[ARRAY_MAX];

void output() {
	for (int i = 0; i < ARRAY_MAX; ++i)
	{	
		if (stu[i].isExisting)
		{
			printf("%s %d %s ", id[i], stu[i]._class, name[i]);
			cout << fixed << setprecision(1) << stu[i].math << " " << stu[i].physics << " " << stu[i].english;
			cout << endl;
		}
	}
}

void deleteStudent() {
	int index;
	char input[STRING_MAX];
	char finalOrder;

	index = -1;
	scanf("%s", input);
	// puts(input);

	for (int i = 0; i < ARRAY_MAX; ++i)
	{
		if (!strcmp(input, id[i]) || !strcmp(input, name[i]))
		{
			index = i;
			stu[index].isExisting = false;
		}
	}
	output();

	if (index >= 0)
	{
		cout << "Are you sure(yes/no)?" << endl;
		cin >> finalOrder;		
		// cout << finalOrder;
		if (finalOrder == 'y')
		{
			return ;
		} else 
		if (finalOrder == 'n') {
			stu[index].isExisting = true;
			output();
		}
	}

}

int main(int argc, char const *argv[])
{	
	memset(stu, 0, sizeof(stu));

	stu[0] = {11, 99.5, 88.5, 89.5, 277.5, true};
	strcpy(id[0], "10001");
	strcpy(name[0], "Zhang");
	stu[1] = {11, 92.5, 99.0, 60.5, 252.0, true};
	strcpy(id[1], "10003");
	strcpy(name[1], "Liang");
	stu[2] = {12, 77.9, 56.5, 87.5, 221.9, true};
	strcpy(id[2], "10002");
	strcpy(name[2], "Yang");

	deleteStudent();

	return 0;
}