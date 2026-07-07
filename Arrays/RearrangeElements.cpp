#include <iostream>
#include <vector>
using namespace std;
vector<int> rearrangeArray(vector<int> &nums)
{
    vector<int> pnums;
    vector<int> nnums;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            pnums.push_back(nums[i]);
        }
        else
            nnums.push_back(nums[i]);
    }
    for (int i = 0, j = 0; j < (n / 2); i = i + 2, j++)
    {
        nums[i] = pnums[j];
    }
    for (int i = 1, j = 0; j < (n / 2); i = i + 2, j++)
    {
        nums[i] = nnums[j];
    }
    return nums;
}