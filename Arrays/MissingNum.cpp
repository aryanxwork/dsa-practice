#include<iostream>
#include<vector>
using namespace std;
   int missingNumber(vector<int>& nums) {
        int size=nums.size();
        int totalsum=(size*(size+1))/2;
        int currsum=0;
        for(int i=0;i<size;i++){
            currsum+=nums[i];
        }
        return totalsum-currsum;
    }