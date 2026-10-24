/*Leetcode ps-4088. Difference Between Peaks and Valleys
You are given an integer array nums of length n.
An index i is called a peak if all of the following conditions hold:
0 < i < n - 1
nums[i] > nums[i - 1]
nums[i] > nums[i + 1]
An index i is called a valley if all of the following conditions hold:

0 < i < n - 1
nums[i] < nums[i - 1]
nums[i] < nums[i + 1]
Return an integer denoting the difference between the sum of all peak values and the sum of all valley values.*/



/* Approach - Linear Peak-Valley Sum Accumulation / Local Extrema Difference (Time: O(N), Space: O(1))
 * Basically, we completely annihilate brute-force subsequence searches by aggressively inspecting interior neighborhood constraints, accumulating local peaks and valleys in a single linear pass and constant space!
 * * Observation: 
 * - The absolute core of this architecture is the Local Extrema Invariant! An element `nums[i]` qualifies as a peak if it is strictly greater than both its adjacent neighbors (`nums[i] > nums[i - 1] && nums[i] > nums[i + 1]`), and as a valley if it is strictly smaller than both (`nums[i] < nums[i - 1] && nums[i] < nums[i + 1]`). Accumulating these values into separate sums allows us to compute the net peak-valley difference in $O(N)$ time.
 * - (Boundary Safety & Edge Cases): Restricting the loop strictly from `i = 1` to `n - 2` completely prevents out-of-bounds index errors. If the array size `n < 3`, the loop is bypassed entirely, returning `0` naturally since interior extrema cannot exist.
 * - (Optimal Auxiliary Memory): Operating purely with scalar accumulator registers (`psum`, `vsum`) keeps auxiliary memory footprint at strict $O(1)$ space.
 * * How it runs:
 * First, we initialize our peak sum `psum` and valley sum `vsum` registers to `0`.
 * We ignite a high-speed linear sweep from index `1` to `n - 2`, checking strict neighborhood inequalities at each step to categorize interior elements as peaks or valleys.
 * We accumulate their values into their respective sums.
 * Finally, we flush the resulting difference (`psum - vsum`) to the output stream with absolute mathematical precision at raw silicon speed!
 */



class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int psum=0,vsum=0,n=nums.size();
        for(int i = 1;i<n-1;i++){
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1])psum += nums[i];
            if(nums[i] < nums[i-1] && nums[i] < nums[i+1])vsum += nums[i];
        }
        return psum - vsum;
    }
};
