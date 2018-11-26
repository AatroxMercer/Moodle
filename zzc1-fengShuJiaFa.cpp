#include <iostream>
using namespace std;

int divisorEuclid(int min, int max) {
    return max % min ? divisorEuclid(max % min, min) : min;
}

int multipleEiclid(int min, int max) {
    return max * min / divisorEuclid(min, max);
}

int main(int argc, char const *argv[])
{
    int num;
    cin >> num;

    int numerator, denominator;
    double temp, sum;
    int multiple;
    sum = 0;
    multiple = 1;
    for (int i = 0; i < num; ++i)
    {
        cin >> numerator;
        getchar();
        cin >> denominator;

        sum += temp = (double)numerator / (double)denominator;
        multiple = multiple > denominator ? multipleEiclid(denominator, multiple) : multipleEiclid(multiple, denominator);
    }


    cout << (temp = (int) sum) << " ";
    sum -= temp, sum *= multiple;
    int divisor = divisorEuclid(sum, multiple);
    sum /= divisor, multiple /= divisor;
    cout << sum << "/" << multiple;

    return 0;
}