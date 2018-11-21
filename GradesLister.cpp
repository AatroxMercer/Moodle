#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
	int id;
	float math, physics, english, grades;

	for (int i = 0; i < 3; ++i)
	{
		cin >> id >> math >> physics >> english;
		grades = math + physics + english;
		printf("%d  %.1f  %.1f  %.1f  %.1f\n", id, math, physics, english, grades);
	}

	return 0;
}