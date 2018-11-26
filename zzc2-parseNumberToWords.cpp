#include <iostream>
#include <string>
using namespace std;

void giveLevel(int level) {
    level /= 3;
    switch(level) {
        case 0:
            return ;
        case 1:
            cout << " thousand";
            return ;
        case 2:
            cout << " million";
            return ;
        case 3:
            cout << " billion";
            return ;
        case 4:
            cout << " trillion";
            return ;
        case 5:
            cout << " jillion";
            return ;
        case 6:
            cout << " zillion";
            return ;

        default:
            return;
    }
}

int main(int argc, char const *argv[])
{
    string in;
    string tens[] = {" zero ", " ten ", " twenty ", " thirty ", " forty ", " fifty ", " sixty ", " seventy ", " eighty ", " ninety "};
    string ones[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    cin >> in;
    int length = in.size();
    for (int i = 0; i < length; ++i)
    {
        int level = length - i;
        int adress = level % 3;
        if (adress == 1)
        {
            cout << ones[in[i] - 48];
            giveLevel(level);
        }
        if (adress == 2)
        {
            cout << tens[in[i] - 48];
        }
        if (adress == 3)
        {
            cout << ones[in[i] - 48];
            cout << " hundred";
        }
    }


    return 0;
}