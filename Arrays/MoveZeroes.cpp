#include<iostream>
#include<vector>
using namespace std;
void MoveZeros(vector<int>&nums){
    int index=0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i]!=0)
        {
            swap(nums[i],nums[index]);
            index++;
        }
        
    }
    
}