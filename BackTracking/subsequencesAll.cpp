#include <bits/stdc++.h>
using namespace std;

void printAllSubsequences(int index, vector<int> &nums, vector<int> ans)
{
    if (index >= nums.size())
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }
    ans.push_back(nums[index]);
    printAllSubsequences(index + 1, nums, ans);

    ans.pop_back();
    printAllSubsequences(index + 1, nums, ans);
}

int main()
{
    vector<int> nums = {3, 1, 2};
    vector<int> ans;
    printAllSubsequences(0, nums, ans);
}