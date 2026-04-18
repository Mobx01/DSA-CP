/*Leetcode ps :- 992. Subarrays with K Different Integers
Given an integer array nums and an integer k, return the number of good subarrays of nums.
A good array is an array where the number of different integers in that array is exactly k.
For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.*/

// Non - optimised solution O(n^3).
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
     // use sliding window firm j = k to max lenght for i =   k check each element must have freq == 1. for k = k+i where i starts from 0 , 
     //freq of each element should not ecxed i+1 .
        int n = nums.size();
        int count = 0;

        // "from j = k to max length" (Window Size)
        for (int len = k; len <= n; ++len) {
            
            for (int i = 0; i <= n - len; ++i) {
                
                unordered_map<int, int> freq;
                for (int j = i; j < i + len; ++j) {
                    freq[nums[j]]++;
                }
                if (freq.size() == k) {
                    count++;
                }
            }
        }
        return count;
    }
};
