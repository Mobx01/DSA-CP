/*Leetcode ps-32. Longest Valid Parentheses
Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.*/



/* Approach - Dual-Pass Balance Counter Scanning / Constant-Space Parenthesis Tracking (Time: O(N), Space: O(1))
 * Basically, we completely annihilate heavy stack memory overhead by aggressively deploying a dual-pass balance counter, tracking open and close parenthesis invariants in pristine linear time and constant auxiliary space!
 * * Observation: 
 * - The absolute core of this architecture is the Dual-Directional Balance Invariant (LeetCode 32 - Longest Valid Parentheses)! A single left-to-right pass fails to capture valid sequences if excess opening brackets remain unclosed on the right (e.g., `"(()"`). By combining a left-to-right pass (which resets when closing brackets exceed opening ones: `close > open`) with a symmetric right-to-left pass (which resets when opening brackets exceed closing ones: `open > close`), you guarantee that all valid longest substrings are captured without ever allocating an auxiliary stack.
 * - (Elite Space Optimization): Operating entirely with scalar counters (`open`, `close`, `result`) reduces the space complexity from $O(N)$ (standard stack approach) down to an absolute $O(1)$.
 * - (Linear Time Efficiency): Scanning the string twice sequentially results in strict $O(N)$ time complexity, executing with blistering hardware speed.
 * * How it runs:
 * First, we initialize our counters and sweep from left to right, incrementing `open` or `close`, updating our max `result` when they balance, and resetting both if `close` surpasses `open`.
 * Next, we reset our counters and sweep in reverse from right to left, updating `result` on balance and resetting if `open` surpasses `close`.
 * Finally, we flush the maximum valid parenthesis length to the output stream with absolute mathematical precision at raw silicon speed!
 */



class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();

        int open  = 0;
        int close = 0;

        int result = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == '(') open++;
            else close++;

            if(open == close) {
                result = max(result, open+close);
            } else if(close > open) { //going from left to right, if close is more, it's no more valid
                open  = 0;
                close = 0;
            }
        }

        open  = 0;
        close = 0;
        for(int i = n-1; i >= 0; i--) {
            if(s[i] == '(') open++;
            else close++;

            if(open == close) {
                result = max(result, open+close);
            } else if(open > close) { //going from right to left, if open is more, it's no more valid
                open  = 0;
                close = 0;
            }
        }

        return result;
    }
};
