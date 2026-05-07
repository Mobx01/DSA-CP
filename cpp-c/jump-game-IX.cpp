/*Leetcode ps - 3660. Jump Game IX
You are given an integer array nums.
From any index i, you can jump to another index j under the following rules:
Jump to index j where j > i is allowed only if nums[j] < nums[i].
Jump to index j where j < i is allowed only if nums[j] > nums[i].
For each index i, find the maximum value in nums that can be reached by following any sequence of valid jumps starting at i.
Return an array ans where ans[i] is the maximum value reachable starting from index i.
*/


/* 
 * APPROACH:
 * 1. Pre-calculate the 'Prefix Maximum': 
 *    Create an array (preMax) where each index 'i' stores the largest 
 *    value found in nums[0...i]. This tells us the "peak" value from the left.
 *
 * 2. Backward Pass & Suffix Minimum:
 *    Traverse the array from the end to the beginning. While moving, maintain 
 *    'sufMin', which is the smallest value found from the right side (nums[i...n-1]).
 *
 * 3. Result Selection:
 *    For each position 'i', compare the peak from the left (preMax[i]) 
 *    with the smallest value to the right (sufMin):
 *    - If the peak is larger than the smallest value to the right, 
 *      carry over the value from the succeeding index (ans[i+1]).
 *    - If the peak is smaller or equal, use that peak as the current answer.
 *
 * 4. Update Minimum:
 *    Update 'sufMin' at each step to include the current element for the next iteration.
 */




class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);
        vector<int> preMax(n);

        // Prefix maximum
        preMax[0] = nums[0];

        for (int i = 1; i < n; i++) {
            preMax[i] = max(preMax[i - 1], nums[i]);
        }

        int sufMin = INT_MAX;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            if (preMax[i] > sufMin)
                ans[i] = ans[i + 1];
            else
                ans[i] = preMax[i];

            sufMin = min(sufMin, nums[i]);
        }

        return ans;
    }
};
