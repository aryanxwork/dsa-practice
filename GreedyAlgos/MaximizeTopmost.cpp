#include <iostream>
#include <vector>
using namespace std;
int maximumTop(vector<int> &nums, int k)
{
    int max = INT32_MIN;
    int n = nums.size();
    if (k == 0)
    {
        return nums[0];
    }

    if (nums.size() == 1)
    {
        if (k % 2 == 0)
        {
            return nums[0];
        }
        else
            return -1;
    }

    for (int i = 0; i < k - 1; i++)
    {
        if (nums[i] > max)
        {
            max = nums[i];
        }
    }
    return max > nums[k] ? max : nums[k];
}