#include <iostream>
#include <vector>
using namespace std;
bool wildcard(string t, string p)
{
    int n = t.size();
    int m = p.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;
    for (int i = 1; i < m + 1; i++)
    {
        if (p[i - 1] == '*')
        {
            dp[0][i] = dp[0][i - 1];
        }
        else
            dp[0][i] = false;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (p[j - 1] == t[i - 1] || p[j - 1] == '?') // char true/false  ? true/false
            {
                dp[i][j] = dp[i - 1][j - 1]; // true then check remaining
            }
            else if (p[j - 1] == '*')
            {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
            else
                dp[i][j] = false;
        }
    }
    return dp[n][m];
}