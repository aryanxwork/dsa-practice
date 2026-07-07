#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
{
    vector<pair<int, int>> nums;
    int maxProfit = 0;
    int n = profits.size();
    for (int i = 0; i < n; i++)
    {
        nums.push_back({capital[i], profits[i]});
    }

    sort(nums.begin(), nums.end(), [](auto &a, auto &b)
         { return a.first < b.first; });

    for (int i = 0; i < k; i++)
    {
        if (nums[i].first <= w)
        {
            // do this project
            w -= nums[i].first;
            w += nums[i].second;
            maxProfit += nums[i].second;
        }
    }
    return maxProfit;
}
int main()
{
    vector<int> cap = {0, 1, 1};
    vector<int> pro = {1, 2, 3};
    cout << findMaximizedCapital(2, 0, pro, cap);
}