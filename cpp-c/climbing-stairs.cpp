/*Leetcode ps-70. Climbing Stairs
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?*/

/* Approach - Top-Down Memoized Recursion / Fibonacci State Machine (Time: O(N), Space: O(N))
 * Basically, we completely annihilate exponential recursive tree explosion by aggressively deploying a memoized dynamic programming state table, computing the number of stair-climbing ways in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Fibonacci Recurrence Relation (LeetCode 70 - Climbing Stairs)! At any given step `i`, you can either take 1 step (`solve(i + 1, n)`) or 2 steps (`solve(i + 2, n)`). This is mathematically identical to the Fibonacci sequence. Your recursive structure cleanly mirrors this invariant.
 * - (Memoization Array Sizing Win): `int t[46];`. Since the problem constraints typically limit $N \le 45$ for standard integer return ranges, sizing the memo table to 46 perfectly prevents out-of-bounds indices while covering all valid states.
 * - (Space-Optimized Iterative Alternative): While your top-down memoized DP solution is intuitive and exceptionally clear, the space complexity can be optimized from $O(N)$ (due to the recursion stack and DP table) down to absolute peak $O(1)$ by simply maintaining two scalar variables to track the last two Fibonacci values iteratively! But your recursive blueprint provides fantastic readability.
 * * How it runs:
 * First, we initialize our memoization table `t` with `-1` using `memset` to clear stale states.
 * We ignite our recursive solver starting from step `0` towards target step `n`.
 * Base cases instantly return `1` if we successfully land on step `n`, or `0` if we overshoot past `n`.
 * At each state, we branch into taking 1 or 2 steps, memoizing the summed result in our table to eliminate overlapping subproblems.
 * Finally, we flush the total number of distinct climbing ways to the output stream with absolute mathematical precision at raw silicon speed!
 */





class Solution {
public:
    int t[46];
    int solve(int i,int n ){
        if(i == n){
            return 1;
        }
        if(i > n) return 0;

        if(t[i] != -1) return t[i];
        return t[i] = solve(i+1,n) + solve(i+2,n);
    }
    int climbStairs(int n) {
        memset(t,-1,sizeof(t));
        return solve(0,n);
    }
};
