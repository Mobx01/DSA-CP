/*Leetcode ps-1190. Reverse Substrings Between Each Pair of Parentheses
You are given a string s that consists of lower case English letters and brackets.
Reverse the strings in each pair of matching parentheses, starting from the innermost one.
Your result should not contain any brackets.*/




/* Approach - Stack-Based State Preservation / Parentheses Reversal Engine (Time: O(N^2), Space: O(N))
 * Basically, we completely annihilate complex recursive string parsing by aggressively deploying a state-saving stack, reversing and merging nested substrings dynamically in pristine time!
 * * Observation: 
 * - The absolute core of this architecture is the Nested State Stack Invariant (LeetCode 1190 - Reverse Substrings Between Each Pair of Parentheses)! Instead of struggling with recursive tree structures or multi-pass index tracking, you maintain a working string buffer `curr`. The moment you hit an opening parenthesis `'('`, you push your current context onto the stack (`stk.push(curr)`) and reset. When you hit a closing parenthesis `')'`, you reverse the accumulated inner string, prepend the parent context from `stk.top()`, pop the stack, and continue. This handles arbitrary nesting depth with supreme elegance.
 * - (Complexity & String Operation Trade-off): While repeated string reversals and concatenations can theoretically scale up to $O(N^2)$ in deep nesting worst-cases, LeetCode constraints for this problem ($N \le 2000$) make this stack approach run comfortably within time limits while maintaining maximum code readability. (An advanced $O(N)$ "wormhole" approach using two passes with bracket index matching exists, but your stack solution is far more intuitive to write and reason about!)
 * - (Zero-Overhead Parsing): The single-pass loop over characters keeps overhead minimal, utilizing standard C++ string and stack operations cleanly.
 * * How it runs:
 * First, we initialize our string stack `stk` and our working buffer `curr`.
 * We ignite a high-speed linear sweep across each character `c` in the input string `s`.
 * If `c` is an opening parenthesis, we save our current outer state to the stack and fresh-start the buffer; if it's a closing parenthesis, we reverse the inner buffer, stitch it back onto the parent state from the stack, and pop.
 * For any regular character, we simply append it to our active working buffer `curr`.
 * Finally, we flush the fully evaluated and reversed string to the output stream with absolute mathematical precision at raw silicon speed!
 */



class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> stk;
        string curr = "";

        for (char c : s) {
            if (c == '(') {
                stk.push(curr);
                curr = "";
            } 
            else if (c == ')') {
                reverse(curr.begin(), curr.end());
                curr = stk.top() + curr;
                stk.pop();
            } 
            else {
                curr += c;
            }
        }
        
        return curr;
    }
};
