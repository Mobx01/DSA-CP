/*Leetcode ps-39. Combination Sum
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.*/



/* Approach - Backtracking / Take or Skip Decision Tree (Time: O(2^(T/M)), Space: O(T/M) Call Stack)
 * Basically, we mathematically traverse a massive decision tree using the classic "Take or Skip" backtracking pattern, aggressively pruning dead branches the exact millisecond they exceed our target to flawlessly capture every single valid combination!
 * * Observation: 
 * - The absolute core mechanic of this problem is that you are allowed to reuse the exact same element an infinite number of times! We brilliantly handle this by NOT incrementing our `ind` when we choose to take the current number. This mathematically forces the recursion to repeatedly test the exact same element until it physically cannot fit anymore!
 * - At every single state, we violently branch the universe into two distinct timelines: one where we aggressively TAKE the current candidate, and one where we completely SKIP it and move on to the next one.
 * - (The Absolute Game-Breaker): The `total > target` base case acts as a ruthless, highly optimized pruning mechanism! The exact millisecond our running sum mathematically exceeds the target limit, it instantly kills that branch, completely bypassing thousands of completely useless recursive calls and saving massive amounts of CPU time!
 * - (Complexity Note: `T` is the target value, and `M` is the absolute minimum value in the candidates array. In the absolute worst-case scenario, the maximum depth of the recursion tree is strictly bounded by `T/M`!)
 * * How it runs:
 * First, we safely initialize our empty `combo` tracking state and our massive `res` matrix, and seamlessly launch our `formcombo` recursive engine starting precisely at index 0 with a baseline `total` of 0.
 * Inside the engine, we fiercely check our absolute base cases. If `total == target`, we have achieved perfect mathematical equilibrium! We aggressively push a deep copy of our `combo` directly into `res` and instantly return! If we overflowed the target or completely ran out of candidates, we instantly terminate the dead branch.
 * Next, we trigger the "Take" branch! We physically push `candidates[ind]` into our `combo` vector, add it to our `total`, and recursively dive deeper while strictly remaining on the exact same `ind`.
 * The exact millisecond that timeline collapses and returns, we meticulously perform our Backtracking step! We violently pop the element back out (`combo.pop_back()`), flawlessly resetting the physical state of our array to exactly how it was before we took the plunge!
 * Finally, with a clean slate, we fiercely trigger the "Skip" branch, completely ignoring the current candidate, leaving the `total` completely untouched, and confidently advancing to `ind + 1` to explore the rest of the array!
 */



class Solution {
public:
    void formcombo(int target,vector<int>& candidates,int ind,vector<int>& combo,vector<vector<int>>& res,int total){
        if(total == target){
            res.push_back(combo);
            return;
        }
        if(total > target || ind >=  candidates.size()){
            return;
        }
        combo.push_back(candidates[ind]);
        formcombo(target,candidates,ind,combo,res,total+candidates[ind]);
        combo.pop_back();
        formcombo(target,candidates,ind+1,combo,res,total);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combo;
        vector<vector<int>> res;
        formcombo(target,candidates,0,combo,res,0);
        return res;
    }
};
