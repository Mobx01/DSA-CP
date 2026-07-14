/*Leetcode ps-3336. Find the Number of Subsequences With Equal GCD
You are given an integer array nums.
Your task is to find the number of pairs of non-empty subsequences (seq1, seq2) of nums that satisfy the following conditions:
The subsequences seq1 and seq2 are disjoint, meaning no index of nums is common between them.
The GCD of the elements of seq1 is equal to the GCD of the elements of seq2.
Return the total number of such pairs.

Since the answer may be very large, return it modulo 109 + 7.*/


/* Approach - 3D Dynamic Programming / Memoization (Time: O(N * M^2), Space: O(N * M^2)) where M is max(nums)
 * Basically, we use recursion with memoization to explore every possible assignment for each element—ignoring it, adding it to subsequence 1, or adding it to subsequence 2—tracking only the running GCDs of the two groups!
 * * Observation:
 * - Every element in the array presents exactly three mutually exclusive choices: skip it, put it in `seq1`, or put it in `seq2`.
 * - We do not need to remember the actual elements chosen. The problem only asks for matching GCDs, so our DP state perfectly reduces to just the current index and the running GCD of each subsequence `(i, first, second)`.
 * - A brilliant math trick used here is that `__gcd(0, x)` naturally returns `x`. This safely and correctly initializes the GCD of a previously empty subsequence the moment its first element is added!
 * - Because the numbers (and their GCDs) are bounded by 200, the 3D state space `[201][201][201]` is small enough to fit completely in memory and compute well within time limits.
 * * How it runs:
 * First, we initialize our 3D memoization array `t` to -1 to mark all states as uncalculated, and launch our `solve` function from index 0 with both GCDs starting at 0.
 * Then, for every recursive call, we check our base case: if we have processed all elements (`i == nums.size()`), we verify that both subsequences are strictly non-empty (GCD != 0) and that their GCDs perfectly match. If true, it counts as 1 valid pair; otherwise, 0.
 * Next, if the current state hasn't been cached, we compute the three branches: `skip` (advancing the index without touching the GCDs), `take1` (updating the first GCD with `nums[i]`), and `take2` (updating the second GCD with `nums[i]`). 
 * Finally, we add all three branching paths together, apply modulo 1e9+7 to prevent astronomical overflow, save the sum in our memoization table `t`, and return it!
 */



class Solution {
    int MOD = 1e9 + 7;
    int t[201][201][201];
public:
    int solve(vector<int> &nums,int i, int first, int second){
        if (i == nums.size()) {
            bool bothNonEmpty = (first != 0 && second != 0);
            bool gcdsMatch    = (first == second);
            return (bothNonEmpty && gcdsMatch) ? 1 : 0;
        }
        
        if(t[i][first][second] != -1) 
            return t[i][first][second];
        
        // Skip this index entirely
        int skip = solve(nums, i + 1, first, second);

        // Include this index in seq1
        int take1 = solve(nums, i + 1, __gcd(first, nums[i]), second);

        // Include this index in seq2
        int take2 = solve(nums, i + 1, first, __gcd(second, nums[i]));
        
        // Summing up all the possibilites
        return t[i][first][second] = (0LL + skip + take1 + take2) % MOD;
    }
    
    int subsequencePairCount(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        return solve(nums, 0, 0, 0);
    }
};
