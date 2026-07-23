/*Leetcode ps-1021. Remove Outermost Parentheses
A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.
For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.
Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.
Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.*/


/* Approach - Stack / Depth Tracking (Time: O(N), Space: O(N))
 * Basically, we use a stack to track the nesting depth of our parentheses, systematically filtering out the outermost layers by completely ignoring them when our depth hits the absolute boundaries!
 * * Observation: 
 * - Every valid primitive string of parentheses is strictly encapsulated by an outermost '(' and its matching outermost ')'.
 * - When we encounter an opening bracket '(' and our stack is entirely empty, we have officially hit the start of an outermost layer. We push to the stack to register the new depth, but intentionally skip adding it to our result!
 * - Similarly, when our stack size is exactly 1 and we encounter a closing bracket ')', we know we are perfectly closing that outermost layer. We pop the stack and, again, discard the character.
 * - Any parenthesis encountered outside of these two specific boundary conditions is safely considered an "inner" parenthesis and gets completely preserved!
 * * How it runs:
 * First, we initialize our empty result string 'ans' and a stack 'stk' to mathematically track our nesting level.
 * Then, we use a range-based for loop to sweep through every single character 'c' in the string 's'.
 * Next, we evaluate our boundaries. If 'stk' is empty and 'c' is '(', we push 1 to the stack. If 'stk.size()' is 1 and 'c' is ')', we pop the stack. In both boundary cases, we bypass adding anything to 'ans'.
 * Finally, if the character is an inner bracket, we confidently append it to 'ans' and update our stack (pushing for '(' and popping for ')'). Once the sweep finishes, we return the fully stripped 'ans' string!
 */


class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        stack<int> stk;
        for(char c : s){
            if(stk.empty() && c == '(' ){
                stk.push(1);
            }else if(stk.size() == 1 && c == ')'){
                stk.pop();
            }
            else{
                ans.push_back(c);
                if(c == '(') stk.push(1);
                else stk.pop();
            }
        }
        return ans;
    }
};
