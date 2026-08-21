#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[m - 1][n - 1] = 1; // destination to destination = one path
    // dp[i][j] represents number of unique paths from that cell to destination

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == m - 1 && j == n - 1)
                continue;
            dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
        }
    }
    return dp[0][0]; // unique paths from start point to destination
}
int main()
{
    cout << uniquePaths(3, 2);
}