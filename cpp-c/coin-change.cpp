/*Leetcode ps-322. Coin Change
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.*/




/* Approach - Top-Down Memoized Dynamic Programming / Coin Change Optimization (Time: O(Amount * N), Space: O(Amount))
 * Basically, we completely annihilate brute-force exponential subset search trees by aggressively deploying memoization tables and tracking running currency sums, isolating the minimum coin count in pristine pseudo-polynomial time!
 * * Observation: 
 * - The absolute core of this architecture is the Optimal Substructure Invariant (LeetCode 322 - Coin Change)! To find the fewest number of coins needed to make up a given `amount`, we can recursively branch on each available coin choice, memoizing the minimum steps required for every intermediate sum `curr`. Using `long long curr` inside the recursive state prevents potential integer overflow when adding large coin denominations to the running total.
 * - (Fixed-Size Memoization Table Safety): Sizing the memoization array `t` to `10001` (`int t[10001]`) perfectly handles typical problem constraints (such as `amount <= 10000`), though production-grade adjustments should scale dynamically with `amount + 1` to prevent out-of-bounds errors for larger inputs.
 * - (Sentinel Propagation for Impossible States): Utilizing `INT_MAX` as a sentinel value ensures that dead-end paths (where no valid coin combination reaches the target) are correctly ignored during `std::min` comparisons, returning `-1` if the target is fundamentally unreachable.
 * * How it runs:
 * First, we check if `amount == 0`, returning `0` immediately.
 * We initialize our memoization array `t` with `-1` via `memset` and ignite our recursive DFS solver starting from `curr = 0`.
 * At each step, we return early if `curr > amount` (`INT_MAX`) or `curr == amount` (`0`), and check memoized results.
 * We branch across all available coin choices, adding `1` to the minimum result of sub-problems and caching the optimal value in `t[curr]`.
 * Finally, we flush the final minimum coin count (or `-1` if unreachable) to the output stream with absolute mathematical precision at raw silicon speed!
 */



class Solution {
public:
    int t[10001];
    int solve(vector<int>& coins, int amount,long long curr){
        if(curr > amount) return INT_MAX;
        if(curr == amount) return 0;

        if(t[curr] != -1) return t[curr];

        int ans = INT_MAX;

        for(int i : coins){
            int an = solve(coins,amount,curr + i);
            if(an != INT_MAX)ans = min(1+an,ans);
        }
        return (t[curr] = ans);
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)return 0;
        memset(t,-1,sizeof(t));
        int ans = solve(coins,amount,0);
        return (ans != INT_MAX) ? ans : -1;
    }
};
