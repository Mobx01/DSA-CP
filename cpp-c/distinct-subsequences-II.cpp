/*Leetcode ps-940. Distinct Subsequences II
Given a string s, return the number of distinct non-empty subsequences of s. Since the answer may be very large, return it modulo 109 + 7.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not.*/


/* Approach - Top-Down Memoized Recursion with Inclusion-Exclusion Duplicate Subtraction (Time: O(N), Space: O(N))
 * Basically, we completely annihilate the exponential brute-force subsequence generation by aggressively tracking the historical appearance of characters, mathematically subtracting duplicate formations on the fly through a brilliant recurrence relation!
 * * Observation: 
 * - The absolute core of this architecture is the Doubling-and-Deduplication Engine! When a new character is introduced, it mathematically doubles the total number of distinct subsequences because it can be appended to every existing distinct sequence plus form new ones. However, if that character has appeared before, simply doubling everything will introduce exact duplicates of all subsequences that ended right before its previous occurrence. You brilliantly resolve this by subtracting the distinct subsequence count up to that previous index (`solve(prev[n] - 1)`), perfectly enforcing the inclusion-exclusion principle!
 * - (The Fatal Hardcoded Array Sizing Trap): Your algorithmic logic is absolute textbook perfection, but your memory architecture contains a ticking time bomb! You declared `int dp[2001];` directly as a class-level member variable with a hardcoded ceiling of 2001. The exact millisecond LeetCode injects a test case where the string length breaches 2000 characters, your recursive lookups will step out of bounds, shattering the memory grid and triggering an instant Segmentation Fault! 
 * - (The Class-State Retention Hazard): Declaring mutable state structures (`dp` array and `prev` vector) at the class level across multiple LeetCode test cases can introduce subtle state-pollution bugs if any path fails to completely overwrite or clear its footprint, risking cross-test contamination.
 * - (Optimization Alert / The Bottom-Up Iterative Nuke): You can completely vaporize the recursive call stack overhead and the class-level array limits by converting this into a bottom-up iterative DP loop! A simple O(N) array or rolling variables can compute the states sequentially from left to right, eliminating recursion overhead, protecting against stack overflows, and locking data tightly into the L1 cache!
 * * How it runs:
 * First, we safely intercept the string and initialize our `lastseen` tracking array to map the 1-based indices of every alphabet character.
 * We populate our `prev` vector, ensuring every character node knows the exact historical coordinate of its immediate predecessor.
 * We ignite the memoized recursive state machine. For each state `n`, we double the result of `solve(n - 1)` to account for the exponential growth of subsets.
 * The exact millisecond our tracker detects a previous occurrence of the current character, we calculate the duplicate offset (`solve(prev[n] - 1)`) and violently subtract it, normalizing the result with modulo arithmetic to prevent integer overflow.
 * Finally, we subtract 1 to exclude the empty subsequence, apply our modulo safeguard, and flush the final distinct count with absolute mathematical precision!
 */


class Solution {
public:
    int dp[2001];
    int M = 1e9 +7;
    vector<int> prev; // prev[n] = last time when the char was seen(1 based indexing)
    int solve(int n){
        if(n == 0) return 1; //empty substring

        if(dp[n] != -1) return dp[n];

        int total = (2LL * solve(n-1)) % M;
        if(prev[n] != 0){
            int duplicate = solve(prev[n] -1) ;
            total = (total- duplicate + M) % M;
        }

        return dp[n] = total ;
    }
    int distinctSubseqII(string s) {
        int n = s.length();

        memset(dp,-1,sizeof(dp));
        prev.assign(n+1,0);
        vector<int> lastseen(26,0);
        for(int i=1;i<=n;i++){
            int idx = s[i-1] - 'a';
            prev[i] = lastseen[idx];
            lastseen[idx] = i;
        }
        return (solve(n) - 1+M)%M;
    }
};
