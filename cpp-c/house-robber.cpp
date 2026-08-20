/*Leetcode ps- 198. House Robber
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.*/



/* Approach - Top-Down Dynamic Programming / State Space Memoization (Time: O(N), Space: O(N))
 * Basically, we aggressively split the universe into parallel timelines of "Rob" and "Skip," mathematically evaluating the optimal heist path while permanently caching the timelines in a dynamic vector to violently prevent a catastrophic explosion of overlapping subproblems!
 * * Observation: 
 * - The absolute core of this is the quintessential Pick/Not-Pick Backtracking tree, fundamentally upgraded with a memory engine! By attempting to rob house `i`, you structurally trigger the alarm for `i+1`, mathematically forcing your next jump to be `i+2`. If you skip `i`, you safely move to `i+1`.
 * - (The Absolute Game-Breaker): Without the `t` array, this algorithm violently spirals into an O(2^N) time limit exceeded catastrophe! Because you aggressively lock the calculated `max` into `t[i]`, the exact millisecond a future recursion hits that same house, it instantly aborts the simulation and returns the pre-calculated future in absolute peak O(1) time!
 * - (Optimization Alert 1 / The Stack Frame Trap): Your top-down recursive approach is logically flawless, but it aggressively burns O(N) memory allocating recursive stack frames deep into the OS! You can instantly upgrade this to a Bottom-Up Tabulation approach (a simple `for` loop from 0 to `N`), completely bypassing the call stack to execute in pure, blistering iterative hardware speed!
 * - (Optimization Alert 2 / The O(1) Space Annihilation): Look incredibly closely at your transition state: `max(nums[i] + solve(i+2), solve(i+1))`. To calculate the current house, you mathematically ONLY care about the results of the two immediately previous steps! You can completely destroy the O(N) `vector<int> t` and replace it with exactly two O(1) integer variables (`prev1` and `prev2`), updating them on the fly! This ruthlessly shreds your space complexity down to absolute zero!
 * * How it runs:
 * First, we safely intercept the array and instantly allocate our memoization vector `t`, aggressively wiping it to `-1` using the `assign` method.
 * We ignite the `solve` engine starting directly at index `0`.
 * If our index structurally breaches the array bounds (`i >= n`), the timeline mathematically collapses, and we return a baseline of `0`.
 * We fiercely check our memory cache: if `t[i]` is already computed, we instantly short-circuit the execution and return the payload!
 * Otherwise, we aggressively split the universe! We compute the "Rob" branch (`nums[i] + solve(i+2)`) and violently pit it against the "Skip" branch (`solve(i+1)`), permanently locking the absolute maximum profit into `t[i]`!
 */


class Solution {
public:
    vector<int> t;//memo
    int solve(vector<int> &nums,int i){
        int n = nums.size();
        if(i >= n){
            return 0;
        }
        if(t[i] != -1) return t[i]; // already calulated

        int sum = nums[i] + solve(nums,i+2);//rob ith house
        sum = max( sum , solve(nums,i+1));//skip ith house

        return t[i] = sum;
    }
    int rob(vector<int>& nums) {
        t.assign(nums.size(), -1);
        return solve(nums,0);
    }
};
