/*Leetcode ps-1614. Maximum Nesting Depth of the Parentheses
Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.*/

/* Approach - Stack / Depth Tracking (Time: O(N), Space: O(N))
 * Basically, we simulate the nesting of parentheses using a stack to dynamically track our current depth and continuously record the absolute maximum depth we reach!
 * * Observation: 
 * - Every valid opening parenthesis strictly increases our nesting depth, and every valid closing parenthesis strictly decreases it. Any other characters (like numbers or letters) naturally do nothing to the depth.
 * - A stack perfectly visualizes this structure: its physical size at any given moment mathematically represents exactly how deep we are currently nested!
 * - Placing the `max()` check at the absolute beginning of the loop is a very clever trick! When we hit a closing bracket `)`, the stack size accurately reflects the total depth of the block we are currently inside, allowing us to capture the peak depth right before we pop and decrease our level.
 * - (Optimization Note: While the stack conceptually works perfectly, we never actually use the values pushed inside it! We only ever care about `stk.size()`. You could brilliantly optimize the space complexity down to O(1) by simply replacing the stack with a single integer counter that increments on '(' and decrements on ')'!)
 * * How it runs:
 * First, we initialize an empty stack 'stk' and our global 'maxdepth' tracker set to 0.
 * Then, we use a range-based for loop to sweep through every single character 'c' in the string 's'.
 * Next, at the very beginning of every iteration, we instantly evaluate the current size of the stack and update 'maxdepth' using the `max()` function to lock in the absolute highest depth seen so far.
 * Finally, we adjust our current depth by pushing a dummy value (1) onto the stack if we encounter an opening bracket '(', or safely popping the top value if we encounter a closing bracket ')'. After completely traversing the string, we return our recorded 'maxdepth'!
 */


class Solution {
public:
    int maxDepth(string s) {
        stack<int> stk;
        int maxdepth =0;
        for(char c : s){
            maxdepth = max(maxdepth,(int)stk.size());
            if(c == '(')stk.push(1);
            else if(c == ')')stk.pop();
        }
        return maxdepth;
    }
};
