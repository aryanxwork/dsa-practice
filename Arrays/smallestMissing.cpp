#include <bits/stdc++.h>
using namespace std;

int missingInteger(vector<int> &nums)
{
    int hash[51] = {0};
    int currSum = 0;
    int n = nums.size();
    bool propertySatisfied = true;
    for (int i = 0; i < n; i++)
    {
        hash[nums[i]]++;
        if (i == n - 1 && propertySatisfied)
        {
            currSum += nums[i];
        }
        else if (nums[i + 1] == nums[i] + 1 && propertySatisfied)
        {
            currSum += nums[i];
        }
        else
        {
            propertySatisfied = false;
        }
    }
    for (int i = currSum;; i++)
    {
        if (hash[i] == 0)
        {
            return i;
        }
    }
}