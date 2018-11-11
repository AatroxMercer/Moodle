#include <iostream>
using namespace std;

void output30spaces() {
	for (int i = 0; i < 30; ++i)
	{
		cout << " ";
	}
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
		cout << "You are trying to Input info";
	}
	else if (order == 'o')
	{
		cout << "You are trying to Output info";
	}
	else if (order == 'm')
	{
		cout << "You are trying to Make things ordered";
	}
	else if (order == 'q')
	{
		cout << "You are about to Quit";
	}
	else
	{
		cout << "Wrong input";
	}
	cout << endl;

	return 0;
}