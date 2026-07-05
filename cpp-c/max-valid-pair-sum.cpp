/*Leetcode ps- 3979. Maximum Valid Pair Sum
You are given an integer array nums of length n and an integer k.
A pair of indices (i, j) is called valid if:
0 <= i < j < n
j - i >= k
Return the maximum value of nums[i] + nums[j] among all valid pairs.*/

/* Approach - Running Maximum / Sliding Window (space complexity O(1))
 * Basically, we find the maximum sum of two elements separated by a distance of at least 'k' in a single pass by constantly tracking the largest valid left-side element available to us.
 * Observation: 
 * - To maximize the sum for any given right-side element at index 'i', we want to pair it with the absolute largest element that exists anywhere in the valid window from index 0 up to 'i - k'.
 * - Instead of looking back and re-scanning that entire valid window every time, we can just maintain a running maximum of those valid elements as we step forward!
 *
 * We keep 2 main variables to track this:
 * - 'max_left' remembers the absolute largest element we've seen that is safely at least 'k' steps behind our current index.
 * - 'max_sum' keeps a running tally of the highest valid pair sum we've successfully formed.
 *
 * How it runs:
 * First, we do a quick bounds check: if the array size 'n' is less than or equal to 'k', it's mathematically impossible to form a pair separated by 'k' indices, so we immediately return 0.
 * Then, we initialize 'max_left' to the very first element, and 'max_sum' to the sum of our first legally distant pair (nums[0] + nums[k]).
 * Next, we start a loop traversing the array from index 'k' to the end. At each step 'i', a brand new element becomes legally distant enough to use (nums[i - k]). We compare it to our existing 'max_left' and keep the bigger one.
 * Right after securing our best possible left half, we mathematically pair it with our current right half (nums[i]) and update 'max_sum' if this new combo beats our previous record!
 * Finally, once we've swept through the entire array, we return our optimal 'max_sum'!
 */

class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        
        if (n <= k) return 0; 
        
        int max_left = nums[0];
        int max_sum = nums[0] + nums[k];
        
        for (int i = k; i < n; i++) {
            max_left = max(max_left, nums[i - k]);
            
            max_sum = max(max_sum, max_left + nums[i]);
        }
        
        return max_sum;
    }
};
