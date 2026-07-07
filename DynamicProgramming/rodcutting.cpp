#include <iostream>
#include <vector>
using namespace std;
int rodcutting(vector<int> price, vector<int> size, int W, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            int itemsize = size[i - 1];
            int itemprice = price[i - 1];
            if (itemsize <= j)
            {
                dp[i][j] = max(itemprice + dp[i][j - itemsize], dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][W];
}
int main()
{
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    vector<int> size = {1, 2, 3, 4, 5, 6, 7, 8};
    int w = 8;
    int n = 8;
    cout << rodcutting(price, size, w, n);
}