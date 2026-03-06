/*Leetcode ps:- 169. Majority Element
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        int n = nums.size();
        for(int i:nums){
            freq[i]++;
            if(freq[i] > n/2) return i;
        }
        return nums[0];
    }
};
