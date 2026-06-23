/*Leetcode ps- 53. Maximum Subarray
Given an integer array nums, find the subarray with the largest sum, and return its sum.*/

/* Approach - Kadane's Algorithm (space complexity O(1))
 * Basically just scanning through the array to find the maximum contiguous sum, deciding at each step whether to extend the previous subarray or start a brand new one.
 * We keep 2 main variables to track the sums: 
 * - 'maxsum' tracks the absolute largest subarray sum we've found so far.
 * - 'cursum' tracks the best possible sum of a subarray that ends exactly at the current number we're looking at.
 *
 * How it runs:
 * First, we initialize both 'maxsum' and 'cursum' with the very first number in the array.
 * Then we loop through the rest of the numbers starting from index 1:
 * We update 'cursum' by comparing the current number by itself vs. adding the current number to our running 'cursum'. Whichever is bigger becomes our new 'cursum' (if the previous running total was dragging us down, we ditch it and start fresh!).
 * Right after that, if our new 'cursum' beats the all-time high 'maxsum', we update 'maxsum'!
 */


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = nums[0],cursum =nums[0],n = nums.size();
        for(int i = 1;i < n;i++){
            cursum = max(nums[i],cursum + nums[i]); // kaden's algorithm
            maxsum = max(cursum,maxsum);
        }
        return maxsum;
    }
};
