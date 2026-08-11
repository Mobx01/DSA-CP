/*Leetcode ps-216. Combination Sum III
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.*/



/* Approach - Virtual Array Backtracking / Bounded State-Space (Time: O(2^9), Space: O(K) Call Stack)
 * Basically, we mathematically traverse a strictly bounded 1-to-9 decision tree using Take or Skip, completely bypassing the need for a physical array by brilliantly using our active index as the actual number!
 * * Observation: 
 * - Unlike previous Combination Sum problems, you are strictly restricted to the numbers 1 through 9. This mathematically locks your absolute worst-case search space to exactly 2^9 (512) operations! It is blazing fast by default!
 * - (The Absolute Masterstroke): Instead of manually allocating a `vector<int> candidates = {1,2,3,4,5,6,7,8,9}` and iterating over it, you aggressively used the `ind` parameter itself as the physical value! This completely eliminates unnecessary memory allocation and flawlessly tracks both the value and the recursive depth at the exact same time!
 * - (Optimization Alert / Pruning Power): You already intelligently prune when `total > target`, but you can brutally slash the recursive tree even further! The exact millisecond your `combo.size()` strictly exceeds `k`, the branch is permanently dead! By adding `|| combo.size() > k` to your early termination check, you aggressively sever useless timelines that are physically impossible to fix! 
 * * How it runs:
 * First, we safely launch our `formcombo` recursive engine, completely bypassing any array initialization and starting our virtual pointer `ind` exactly at 1.
 * Inside the engine, we fiercely check our base cases. If `total == target` AND we have exactly `k` elements, we achieved perfect mathematical equilibrium! We aggressively push the `combo` directly into `res` and return!
 * If we overflowed the target (or theoretically exceeded our `k` limit), or if our virtual pointer crashed past 9 (`ind > last`), we instantly terminate the dead branch.
 * Next, we trigger the "Take" branch! We physically push our virtual `ind` directly into our `combo`, aggressively add it to our `total`, and recursively dive deeper by advancing strictly to `ind + 1`.
 * The exact millisecond that timeline collapses, we meticulously Backtrack by popping the element back out!
 * Finally, we smoothly trigger the "Skip" branch, completely ignoring the current `ind`, leaving the `total` completely untouched, and confidently advancing to explore the next available number!
 */



class Solution {
public:
    void formcombo(int target,int last,int ind,vector<int>& combo,vector<vector<int>>& res,int total,int k){
        if(total == target && combo.size() == k){
            res.push_back(combo);
            return;
        }
        if(total > target || ind >  last){
            return;
        }
        combo.push_back(ind);
        formcombo(target,last,ind+1,combo,res,total+ind,k);
        combo.pop_back();
        formcombo(target,last,ind+1,combo,res,total,k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> combo;
        vector<vector<int>> res;
        formcombo(n,9,1,combo,res,0,k);
        return res;
    }
};


