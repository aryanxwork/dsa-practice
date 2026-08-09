#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        int hash[101]={0};
        int minArr=INT_MAX;
        int maxArr=INT_MIN;
        vector<int>ans;

        //hash computed , max and min range found
        for (int i = 0; i < n; i++)
        {
            hash[nums[i]]++;
            if(nums[i]>maxArr) maxArr=nums[i];
            if(nums[i]<minArr) minArr=nums[i];
        }
        for (int i = minArr+1; i < maxArr; i++)
        {
            if(hash[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};