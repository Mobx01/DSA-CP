/*Leetcode ps -678. Valid Parenthesis String
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
The following rules define a valid string:
Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".*/



/* Approach - Top-Down Memoized Recursion with State Tracking / Bracket Validation (Time: O(N^2), Space: O(N^2))
 * Basically, we completely annihilate brute-force exponential subset generation by aggressively deploying a memoized dynamic programming state table, tracking string indices and open bracket counts in pristine polynomial time!
 * * Observation: 
 * - The absolute core of this architecture is the Wildcard Expansion State Machine (LeetCode 678 - Valid Parenthesis String)! When encountering an asterisk `'*'`, it can act as three different characters: an open bracket `'('`, an empty string `""`, or a closing bracket `')'`. Your recursive function cleanly branches into all three possibilities (`open + 1`, `open`, and `open - 1` if `open > 0`), while handling regular opening and closing brackets deterministically.
 * - (The Memoization Matrix Safety): `int t[101][101];` combined with `memset(t, -1, sizeof(t))` handles overlapping subproblems effectively. However, the constraints on LeetCode for this problem allow string lengths up to $N = 100$. Your fixed 101x101 memoization table matches this perfectly, preventing state-index out-of-bounds errors. (Note: Since `open` can scale up to $N$ in the worst case, keeping the table sized at least $101 \times 101$ is mandatory).
 * - (Alternative Linear Greedy Optimization Nuke): While your memoized DP solution is exceptionally readable and runs well within limits, this specific problem can actually be solved in $O(N)$ time and $O(1)$ space by tracking the *minimum* and *maximum* possible count of open brackets! Whenever the minimum drops below zero, we clamp it to zero; whenever the maximum drops below zero, we instantly know the string is invalid. But your DP solution provides a fantastic top-down structural blueprint!
 * * How it runs:
 * First, we initialize our memoization table `t` with `-1` to clear any stale states, and intercept the string length `n`.
 * We ignite our recursive solver starting from index `0` with an initial bracket balance (`open`) of `0`.
 * If we reach the end of the string (`ind == n`), we return `true` if all open brackets are balanced (`open == 0`), and `false` otherwise.
 * For each character, we branch based on whether it is an asterisk, an opening bracket, or a closing bracket, memoizing the boolean result in our table to avoid redundant paths.
 * Finally, we flush the final boolean validation status to the output stream with absolute mathematical precision at raw silicon speed!
 */



class Solution {
public:
    int t[101][101];
    bool solve(int ind,int open,string &s,int n){
        if(ind == n){
            return open == 0;
        }

        if(t[ind][open] != -1) return t[ind][open];

        bool isval = false;
        if(s[ind] == '*'){
            isval |= solve(ind+1,open+1,s,n);
            isval |= solve(ind+1, open,s,n);
            if(open >0){
                isval |= solve(ind+1,open-1,s,n);
            }
        }else if(s[ind] == '('){
            isval |= solve(ind+1,open+1,s,n);
        }else if(open >0){
            isval |= solve(ind+1,open-1,s,n);
        }
        return t[ind][open] = isval;
    }
    bool checkValidString(string s) {
        int n = s.length();
        memset(t,-1,sizeof(t));
        return solve(0,0,s,n);
    }
};
