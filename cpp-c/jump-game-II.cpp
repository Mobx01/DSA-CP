/*Leetcode ps-45. Jump Game II
You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.
Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at index i, you can jump to any index (i + j) where:
0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1.

*/


/* Approach - Greedy BFS / Spatial Frontier Expansion (Time: O(N), Space: O(1))
 * Basically, we completely annihilate the O(N^2) recursive dynamic programming tree by aggressively deploying a Greedy BFS engine, tracking the maximum possible reach of our kinetic energy and calculating jumps purely through spatial boundaries!
 * * Observation: 
 * - The absolute core of this architecture is the Overlapping Reach Property! If you can jump to index 5, you can mathematically reach index 1, 2, 3, and 4! Therefore, simulating *every single intermediate jump* inside a recursive `for` loop is a catastrophic waste of CPU cycles!
 * - (The Fatal O(N^2) Recursive Trap): Your DP matrix flawlessly prevents redundant subproblems, but the internal loop `for (int j = i + 1; j <= max_jump; j++)` violently throttles your hardware! If `nums[0]` is 10,000, you aggressively execute 10,000 loop iterations on the very first step, brutally degrading your blistering linear timeline down to a sluggish O(N^2) crawl! 
 * - (The Global Array Ceiling Bomb): `int t[10001];` at the class level! While your `memset` successfully clears the data between test cases, you have violently hardcoded a memory ceiling! If LeetCode dynamically injects a test case with 10,005 elements, your radar will shatter the array bounds, triggering a catastrophic Segmentation Fault!
 * - (Optimization Alert / The O(N) Greedy Nuke): You can completely vaporize the DP matrix, the recursion, AND the inner loop! Imagine a radar sweeping forward. You only need to track your current territorial boundary (`current_end`) and the absolute maximum reach you can mathematically achieve from your known territory (`farthest`). Sweep linearly. At every step, violently update `farthest = max(farthest, i + nums[i])`. The exact millisecond your sweep collides with `current_end`, your current jump's kinetic energy is fully exhausted! You mathematically MUST jump again! So, increment your jump counter and aggressively stretch `current_end` to the new `farthest` frontier!
 * * How it runs (The O(N) Optimized Vision):
 * First, we safely intercept the array and instantly lock our three O(1) hardware registers: `jumps = 0`, `current_end = 0`, and `farthest = 0`.
 * We ignite a high-speed linear sweep, deliberately terminating exactly one index BEFORE the end (because if we reach the final index, we are already mathematically victorious and don't need to jump again).
 * For every single element, we violently project its maximum reach and aggressively smash it against our global `farthest` tracker!
 * The exact millisecond our iterator collides with the `current_end` boundary, the timeline forces our hand! We aggressively trigger a jump (`jumps++`) and violently expand our `current_end` to match the `farthest` known coordinate!
 * Finally, we confidently output the absolute minimum jumps required, flawlessly crushing the simulation in pure single-pass O(N) hardware speed!
 */




class Solution {
public:
    int t[10001]; //memoization

    int solve(int i, vector<int>& nums) {
        int n = nums.size();
        if (i >= n - 1) {
            return 0; 
        }
        
        if (t[i] != -1) return t[i];
        
        int ans = 1e9;
        int max_jump = min(n - 1, i + nums[i]);//maximum allowed jump possible
        
        // Try all possible jumps
        for (int j = i + 1; j <= max_jump; j++) {
            ans = min(ans, 1 + solve(j, nums));
        }
        
        return t[i] = ans;
    }
    
    int jump(vector<int>& nums) {
        memset(t, -1, sizeof(t)); 
        return solve(0, nums); 
    }
};
