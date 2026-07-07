#include <iostream>
#include <vector>
using namespace std;
int firstMissingPositive(vector<int> &nums)
{
    int n = nums.size();
    int hash[10000] = {0};
    hash[0] = 1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] >= 0 && nums[i] < 10000)
        {
            hash[nums[i]]++;
        }
    }
    for (int i = 0; i < 10000; i++)
    {
        if (0 == hash[i])
        {
            return i;
            break;
        }
    }
}
int main()
{
    vector<int> nums = {1, 3, 4, 5};
    cout << firstMissingPositive(nums);
}