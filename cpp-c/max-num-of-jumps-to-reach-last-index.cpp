/*Leetcode ps - 2770. Maximum Number of Jumps to Reach the Last Index
You are given a 0-indexed array nums of n integers and an integer target.
You are initially positioned at index 0. In one step, you can jump from index i to any index j such that:
0 <= i < j < n
-target <= nums[j] - nums[i] <= target
Return the maximum number of jumps you can make to reach index n - 1.
If there is no way to reach index n - 1, return -1.*/


/*
APPROACH:
1. State Definition:
   Let dp[i] represent the maximum number of jumps required to reach index i. 
   We initialize the whole dp array with INT_MIN. This acts as a flag to tell us if an index is completely unreachable. 
   Since we are already at index 0 at the start, it takes 0 jumps to get there, so dp[0] = 0.

2. Building the DP array:
   We use a nested loop. 
   - Outer loop 'j' iterates through the array. Think of 'j' as our target destination for a jump.
   - Inner loop 'i' goes from 0 up to j-1. Think of 'i' as all the possible stepping stones we could jump from to reach 'j'.

3. The Transition (When to jump):
   For every possible jump from 'i' to 'j', we need to check two things:
   - First, is index 'i' even reachable? We check this by making sure dp[i] != INT_MIN.
   - Second, is the jump valid according to the problem? We check if the absolute difference between nums[i] and nums[j] is <= target.
   
   If both conditions are met, we can make the jump. We then update dp[j] to be the maximum between its current value and (dp[i] + 1). The "+ 1" represents the new jump we just made from i to j.

4. Final Answer:
   Once the loops are done, we check the last index: dp[n-1]. 
   If it's still negative, it means our loops never found a valid path to update it, so it's unreachable (return -1). 
   Otherwise, we just return whatever value is stored in dp[n-1].
*/


class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN); //dp array
        
        dp[0] = 0; // first index needes 0 step.

        for (int j = 1; j < n; j++) {
            for (int i = 0; i < j; i++) {
                //jump from i to j if:
                // a) i was actually reachable (dp[i] != INT_MIN)
                // b) |nums[i] - nums[j]| <= target 
                if (dp[i] != INT_MIN && abs(nums[i] - nums[j]) <= target) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        // if dp[n-1] didn't changed means we didn't reach there to return -1
        return (dp[n - 1] < 0) ? -1 : dp[n - 1];
    }
};
