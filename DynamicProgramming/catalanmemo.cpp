#include <iostream>
#include <vector>
using namespace std;
int nthcatalan(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    if (dp[n] != 0)
    {
        return dp[n];
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            dp[n] += nthcatalan(i, dp) * nthcatalan(n - i - 1, dp);
        }
    }
    return dp[n];
}
int main()
{
    int n = 5;
    vector<int> dp(n + 1, 0);
    cout << nthcatalan(n, dp);
}