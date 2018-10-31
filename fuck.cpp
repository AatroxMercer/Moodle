//
//  main.cpp
//  moodle test 030_prime number sum
//
//  Created by RenD on 2018/10/15.
//  Copyright © 2018年 Daithy. All rights reserved.
//

#include <iostream>
#include <math.h>

long double ceil(long double x);
int main(int argc, const char * argv[])
{
    using namespace std;
    int arr[1000];
    int n;
    int sum;
    int i , j;
    sum = 0 ;
    cin >> n;
    for ( i = 0 ; i <= ( n - 1 ) ; i ++ )
    {
        cin >> arr[i];
        int b = sqrt(arr[i]) ;
        bool is = true;
        for ( j = 2 ; j <= b ; j ++ )
        {
            if (arr[i] % j == 0 ){
                is = false;
                break;
            }
        }
        if (arr[i] <= 1)
        {
            is = false;
        }
        if (is)
            sum = sum + arr[i];
    }

    cout << sum << endl;
    return 0;
}



