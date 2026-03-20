/*Leetcode ps:- 697. Degree of an Array
Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.
Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.*/

/*
 * APPROACH: Two-Pass Sliding Window
 * 1. Calculate the 'degree' (max frequency) of the array using a hash map.
 * 2. Use a sliding window (right pointer) to find subarrays containing the degree.
 * 3. Shrink the window from the left while the degree condition is maintained.
 * 4. Track the minimum window length (right - left + 1) encountered.
 * Complexity: Time O(n), Space O(n).
 */

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> count;
        int degree = 0;
        for (int i : nums) degree = max(degree, ++count[i]);

        // Reset for the sliding window
        count.clear();
        int left = 0, min_len = nums.size();
        int current_max_freq = 0;

        for (int right = 0; right < nums.size(); right++) {
            count[nums[right]]++;
            
            while (count[nums[right]] == degree) {
                min_len = min(min_len, right - left + 1);
                count[nums[left]]--;
                left++;
            }
        }
        return min_len;
    }
};
