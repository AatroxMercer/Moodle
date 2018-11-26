#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

void comeOn(string & input, int index) {
    int length = input.size();
    for (int i = index; i < length; ++i)
    {
        input[i] = input[i+1];
    }
}

void parseStrintToNumber(string & input) {
    int length = input.size();
    // cout << length;

    bool head = true;
    for (int i = 0; i < length; ++i)
    {
        if (head)
        {
            if ((input[i] == '0' && input[i+1] != ' ') || (input[i] == ' ' && input[i-1] == ' '))
            {
                comeOn(input, i--);
            } else {
                head = false;
            }
        }
        if (input[i] == ' ')
        {
            head = true;
        }
    }
}

int main(int argc, char const *argv[])
{
    string input;
    getline(cin, input);

    for (unsigned int i = 0; i < input.size(); ++i)
    {
        if (input[i] == '5')
        {
            input[i] = ' ';
        }
    }

    parseStrintToNumber(input);

    cout << input << endl;

    return 0;
}