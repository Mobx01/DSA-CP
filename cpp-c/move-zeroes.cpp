/*Leetcode ps- 283. Move Zeroes
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.*/


// approach- not optimal

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> res;
        for(int i : nums){
            if(i != 0) res.push_back(i);
        }
        int n = nums.size(),m=res.size();
        for(int i = m;i<n;i++)res.push_back(0);
        nums = res; 
    }
};

