#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> &values, vector<int> &weights, int capacity)
{
    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    // dp[i][j] represents the max amount that can be obtained till using first i items and capacity = j

    // base cases :
    // if w=0 (first column) no item can be picked , therefore column 1 will be complete 0 -> already initialized

    // first row when only first item is being selected , therefore when w>=weight[0] we will fill that cell with val[0] else keeping it 0

    for (int i = 0; i <= capacity; i++)
    {
        if (i >= weights[0])
        {
            dp[0][i] = values[0];
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= capacity; j++)
        {
            int noTake = dp[i - 1][j];
            int take = 0;
            if (weights[i] <= j)
                take += dp[i - 1][j - weights[i]] + values[i];
            dp[i][j] = max(take, noTake);
        }
    }
    return dp[n - 1][capacity];
}

int main()
{
    vector<int> values = {10, 20, 15, 25};
    vector<int> weights = {2, 1, 3, 1};
    int cap = 4;
    cout << knapsack(values, weights, cap);
}