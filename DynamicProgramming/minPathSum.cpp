#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX)); // we have to take min(down,right) so initializing them with INT_MAX padding is perfect - but it can cause overflow because some grid value + int max = overflow
    // but the constraints of the problems define grid values are smaller so its fine here, we can use long long to fix otherwise
    dp[m - 1][n - 1] = grid[m - 1][n - 1];
    // dp[i][j]=min cost to reach the destination using the current cell
    //  starting at destination (cost = grid destination) and ending at 0,0
    //  dp[0][0] = ans

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == m - 1 && j == n - 1)
            {
                continue;
            }
            dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
        }
    }
    return dp[0][0];
}