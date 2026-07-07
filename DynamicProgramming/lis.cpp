#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int lishelper(vector<int> a, vector<int> b)
{
    int n = a.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}
int lis(vector<int> a)
{
    vector<int> b = a;
    ;
    sort(b.begin(), b.end());
    return lishelper(a, b);
}
int main()
{
    vector<int> a = {50, 3, 10, 7, 40, 80};
    cout << lis(a);
}