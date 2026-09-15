/*Leetcode ps-2472. Maximum Number of Non-overlapping Palindrome Substrings
You are given a string s and a positive integer k.
Select a set of non-overlapping substrings from the string s that satisfy the following conditions:
The length of each substring is at least k.
Each substring is a palindrome.
Return the maximum number of substrings in an optimal selection.

A substring is a contiguous sequence of characters within a string.*/



/* Approach - Memoized Dynamic Programming with Window Expansion / Palindromic Substring Optimization (Time: O(N^3) current, optimizable to O(N^2); Space: O(N^2))
 * Basically, we completely annihilate brute-force subset searches by aggressively deploying a memoized state machine that evaluates valid palindromes of length $\ge k$, deciding dynamically whether to claim a match and jump forward or slide the window!
 * * Observation: 
 * - The absolute core of this architecture is the Choice-Based Palindromic State Machine! At any window defined by bounds `[i, j]`, if the substring is a valid palindrome of length $\ge k$, you have two optimal paths: `take` it (claiming 1 palindrome and jumping your start index to `j + 1` with a fresh window of size $k$) or `grow` it (expanding the right boundary `j++`). If it's not a valid palindrome, you slide or grow the window to search for valid configurations.
 * - (The `ispal` Substring Re-Evaluation Bottleneck): Your recursive function invokes `ispal(i, j, s)` dynamically inside the transition branches. Even with memoization on the DP state `t[i][j]`, `ispal` runs a linear scan of up to $O(N)$ characters every time it's called. Combined with an $O(N^2)$ state space, this can push runtime overhead up. You can completely vaporize this bottleneck by precomputing a 2D boolean DP table `bool isPalindrome[N][N]` in $O(N^2)$ time upfront, reducing all palindrome checks to an instant $O(1)$ lookup!
 * - (Edge Case Shortcut Win): `if (k == 1) return n;`. This is a pristine optimization! If the minimum palindrome length required is 1, every single individual character is trivially a palindrome of length 1, meaning you can instantly extract all $n$ characters without any complex search.
 * * How it runs:
 * First, we intercept the string length and instantly return `n` if $k = 1$.
 * We initialize our memoization grid `t` of size $(n+1) \times (n+1)$ with `-1` to cache overlapping subproblems.
 * We ignite our recursive solver starting from index `0` with an initial window length of `k - 1` (`j = k - 1`).
 * For each window, we check validity: if it forms a palindrome of length $\ge k$, we branch into taking the match (adding 1 and jumping ahead) or growing the window; otherwise, we adjust boundaries to keep scanning.
 * Finally, we cache the optimal state and flush the maximum palindrome count to the output stream at raw silicon speed!
 */




class Solution {
public:
    bool ispal(int l, int r, const string& s) {
        for (; l < r; l++, r--) {
            if (s[l] != s[r]) return false;
        }
        return true;
    }

    int solve(const string& s, int k, int i, int j, vector<vector<int>>& t) {
        if (j >= s.length()) return 0;
        if (t[i][j] != -1) return t[i][j];

        int ans = 0;
        if ((j - i + 1) >= k && ispal(i, j, s)) {
            int take = 1 + solve(s, k, j + 1, j + k, t);
            int grow = solve(s, k, i, j + 1, t);
            ans = max(take, grow);
        } else {
            int grow = solve(s, k, i, j + 1, t);
            int slide = solve(s, k, i+1, j+1, t);
            ans = max(grow, slide);
        }
        return t[i][j] = ans;
    }

    int maxPalindromes(string s, int k) {
        int n = s.length();
        if (k == 1) return n;
        vector<vector<int>> t(n + 1, vector<int>(n + 1, -1));
        return solve(s, k, 0, k - 1, t);
    }
};
