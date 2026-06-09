/*Leetcode ps- 3689. Maximum Total Subarray Value I
You are given an integer array nums of length n and an integer k.
You need to choose exactly k non-empty subarrays nums[l..r] of nums. Subarrays may overlap, and the exact same subarray (same l and r) can be chosen more than once.
The value of a subarray nums[l..r] is defined as: max(nums[l..r]) - min(nums[l..r]).
The total value is the sum of the values of all chosen subarrays.
Return the maximum possible total value you can achieve.*/

/*
APPROACH: 
1. Setup: Start `maxn` at the lowest possible number (INT_MIN) and 
   `minn` at the highest (INT_MAX) so they update properly.
2. Single Pass: Loop through the array exactly once. Update `maxn` 
   if you find a bigger number, and `minn` if you find a smaller one.
3. Math & Safety: Subtract the min from the max, and multiply by 'k'. 
   Multiply by `1LL` first to force 64-bit math—this prevents the 
   final huge number from crashing the standard 32-bit integer limit!
*/


class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxn = INT_MIN;
        long long minn = INT_MAX; 
        
        for(long long i : nums){
            maxn = max(maxn, i);
            minn = min(minn, i);
        }
        
        return 1LL * k * (maxn - minn);
    }
};
