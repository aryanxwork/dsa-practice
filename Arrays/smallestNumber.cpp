#include <bits/stdc++.h>
using namespace std; //   greater than equal to n whose product of
int smallestNumber(int n, int t)
{ //                digits is divisible by t

    // n=16 t=3  6+1%3!=0 check 17 8%3!=0 check 18 9%3==0 got it
    // at max t times we need to wait to get the divisible number
    int product = 1;
    int givenNum = n;
    for (int i = 0; i < t; i++)
    {
        int currNum = givenNum;
        while (currNum > 0)
        {
            int remainder = currNum % 10;
            product *= remainder;
            currNum /= 10;
        }
        if ((product % t) == 0)
        {
            return givenNum;
        }
        givenNum++;
    }
    return -1;
}
int main()
{
    int n = 10, t = 2;
    cout << smallestNumber(n, t);
}