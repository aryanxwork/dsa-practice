#include<iostream>
#include<vector>
using namespace std;
int findMaxConsecutiveOnes(vector<int>& nums) {
        int currcount=0;
        int max=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                currcount++;
                if(currcount>max){
                    max=currcount;
                }
            }
            else currcount=0;
        }
        return max;
    }