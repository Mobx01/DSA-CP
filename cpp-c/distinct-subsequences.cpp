/*Leetcode ps-115. Distinct Subsequences
Given two strings s and t, return the number of distinct subsequences of s which equals t.
The test cases are generated so that the answer fits on a 32-bit signed integer.*/


/* Approach - Top-Down Memoized Recursion / Decision-Tree Branching (Time: O(N * M), Space: O(N * M))
 * Basically, we completely annihilate the exponential 2^(N+M) recursive branching explosion by aggressively deploying a memoization table, caching overlapping subproblem states to map the distinct subsequence count in pristine polynomial time!
 * * Observation: 
 * - The absolute core of this architecture is the Dual-Branch Choice Matrix! You brilliantly captured the combinatorial logic: when characters match (`s[i] == t[j]`), you branch into two distinct paths—either consume the character to match `t[j]` and advance both pointers, or skip `s[i]` to look for future matches. If they don't match, you are forced to skip `s[i]`. This exact state transition flawlessly covers every valid combination!
 * - (The Fatal Class-Level Memory Bomb): Your algorithmic state machine is pristine, but your memory architecture contains a silent, catastrophic assassin! You declared `int mem[1001][1001];` directly as a non-static member variable of the class. This means every single time the `Solution` object is instantiated, the compiler aggressively carves out roughly **4 megabytes of RAM** on the heap/stack just for that static array, completely bloating your memory footprint and thrashing the L1/L2 cache!
 * - (The Hardcoded Boundary Trap): Hardcoding dimensions to `1001` creates a ticking time bomb! The exact millisecond LeetCode injects a test case where string lengths breach 1000 characters, your indices will step out of bounds, shattering the memory grid and triggering an instant Segmentation Fault! 
 * - (Optimization Alert / The Bottom-Up 1D Space Compression Nuke): You can completely vaporize the massive 2D memoization matrix and the recursive call stack overhead! By converting this to an iterative bottom-up Dynamic Programming approach, you only ever depend on the previous row of states. This allows you to compress the space complexity from O(N * M) down to absolute peak O(M) using a single 1D rolling array, operating entirely within ultra-fast L1 cache lines!
 * * How it runs:
 * First, we safely intercept the strings and initialize our memoization table with `memset` to clear stale states.
 * We ignite the recursive exploration engine starting from indices `(0, 0)`.
 * For every state, we check our cache. If a subproblem has already been solved, we instantly return the cached result in O(1) time.
 * When characters match, we branch into our dual-addition state transition, accumulating the sum of both paths. When they mismatch, we force a single-path advancement.
 * Finally, we cache the computed state and bubble the final distinct subsequence count up to the root, flawlessly solving the problem with absolute mathematical precision!
 */


class Solution {
public:
    int mem[1001][1001];
    int solve(string& s, string& t, int i, int j) {
       if(j == t.length()) return 1;
       if(i == s.length()) return 0;

       if(mem[i][j] != -1) return mem[i][j];

       if(s[i] == t[j]){
        return mem[i][j] = solve(s,t,i+1,j) + solve(s,t,i+1,j+1);
       }else{
        return mem[i][j] = solve(s,t,i+1,j);
       }
    }

    int numDistinct(string s, string t) {
        memset(mem,-1,sizeof(mem));
       return solve(s,t,0,0);
    }
};
