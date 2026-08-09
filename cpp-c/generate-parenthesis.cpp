/*Leetcode ps-22. Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.*/

/* Approach - Backtracking / State-Space Tree Exploration (Time: O(4^n / sqrt(n)), Space: O(N) Call Stack)
 * Basically, we mathematically prune a massive decision tree of bracket combinations by aggressively enforcing strict validity rules on the fly, guaranteeing we only ever build perfectly balanced parentheses without wasting a single CPU cycle on dead ends!
 * * Observation: 
 * - Generating all combinations of brackets and validating them at the very end would require a catastrophic O(2^(2N)) time, generating thousands of completely useless strings. We completely bypass this nightmare using Backtracking!
 * - At every single step of the string's construction, we have exactly two potential choices: append an open bracket `(` or append a close bracket `)`.
 * - (The Absolute Game-Breaker): We can mathematically guarantee validity in real-time by tracking exactly how many brackets of each type are left in our pool! We can ALWAYS safely place an open bracket as long as our `op` pool is strictly greater than 0.
 * - However, we can ONLY physically place a close bracket if the number of remaining close brackets is strictly greater than the remaining open brackets (`cl > op`). If `cl == op`, it means every open bracket currently in the string has already been closed, and appending a `)` would violently invalidate the entire sequence!
 * - (Complexity Note: The total number of valid parenthesis combinations is mathematically defined by the nth Catalan number, strictly bounding our time and space complexity to O(4^n / sqrt(n))!)
 * * How it runs:
 * First, we safely ignite our recursive `solve` engine directly from `generateParenthesis`, launching it with an empty string and exactly `n` for both our starting `op` and `cl` pools.
 * Inside the recursion, the exact millisecond both `op` and `cl` hit exactly 0, our mathematical structure is flawlessly complete! We aggressively push the perfectly balanced `cur` string into our `ans` array and instantly return.
 * If we still have open brackets available (`op > 0`), we fiercely branch down the first path of the decision tree, appending `(` to our current string and dynamically decrementing `op - 1`.
 * Independently, if our strict balance check safely passes (`cl > op`), we aggressively branch down the second path, perfectly appending `)` and mathematically decrementing `cl - 1`.
 * Finally, as the massive recursive call stack organically explores every valid branch and collapses back up, our `ans` vector is fully populated, and we confidently return the absolute complete list of combinations!
 */

class Solution {
public:
    vector<string> ans;

    void solve(string cur,int op ,int cl){
        if(op == 0 && cl ==0){
            ans.push_back(cur);
            return;
        }
        if(op > 0){
            solve(cur + "(",op-1,cl);
        }
        if(cl > op){//if there are more number of opening used then only go for closing ohterwise it would be invalid parathesis
            solve(cur + ")",op,cl-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        solve("",n,n);
        return ans;
    }
};
