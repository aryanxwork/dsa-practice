#include <bits\stdc++.h>
using namespace std;
int jump(vector<int> &nums)
{
    int n = nums.size();
    int l = 0;
    int r = 0;
    int minJumps = 0;
    for (int i = 0; i < n; i++)
    {
        if (r >= n - 1)
        {
            return minJumps;
        }
        else
        {
            l = r + 1;
            r = l + nums[i];
            minJumps++;
        }
    }
    return minJumps;
}