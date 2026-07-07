#include <iostream>
#include <vector>
using namespace std;
int fibo(int n) // basic recursion O(2^n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else
        return fibo(n - 1) + fibo(n - 2);
}
int fibodp(int n, vector<int> &dp) // dp O(n)
{
    if (n == 0 || n == 1) // base case
    {
        return n;
    }
    if (dp[n] != -1) // if solution of this call is already stored, use it
    {
        return dp[n];
    }
    else
        dp[n] = fibodp(n - 1, dp) + fibodp(n - 2, dp); // if new solution found, store it
    return dp[n];
}
int main()
{
    int n = 7;
    vector<int> dp(n + 1, -1); // store recursive values
    cout << fibodp(n, dp);
}