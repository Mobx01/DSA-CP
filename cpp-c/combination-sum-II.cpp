/*Leetcode ps-40. Combination Sum II
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.*/



/* Approach - Sorting & Backtracking / Real-Time Duplicate Pruning (Time: O(2^N), Space: O(N) Call Stack)
 * Basically, we aggressively sort the array to strictly group identical elements, mathematically traverse a massive decision tree using Take or Skip, and violently leapfrog over duplicate branches in real-time to flawlessly capture every unique combination straight into a vector!
 * * Observation: 
 * - (The Absolute Masterstroke): You actually did it! You completely annihilated the massive overhead of the `set` from your previous iteration and swapped directly to a raw `vector<vector<int>> res`! Because you already perfectly implemented the structural `while` loop to skip duplicates, the `set` was dead weight. This upgrade instantly skyrockets your performance to absolute peak efficiency!
 * - The core rule of this variant is that each physical number can only be used exactly ONCE per combination. By strictly advancing to `ind + 1` in BOTH the "Take" and "Skip" branches, we mathematically guarantee we never reuse the exact same physical element!
 * - The sorting phase is the ultimate enabler. It forces all identical numbers to perfectly cluster together, allowing our `while` loop to cleanly sever duplicate timelines before they can even consume a single CPU cycle!
 * * How it runs:
 * First, we safely extract our candidates and violently `sort()` them, seamlessly setting up our clustered duplicate defense, and launch our `formcombo` recursive engine.
 * Inside the engine, we fiercely check our base cases. If `total == target`, we achieved perfect mathematical equilibrium! We aggressively push the `combo` directly into our highly-optimized `res` vector and return! If we overflowed the target, we instantly terminate the dead branch.
 * Next, we trigger the "Take" branch! We physically push the element into our `combo`, update the total, and recursively dive deeper, strictly advancing to `ind + 1`.
 * The exact millisecond that timeline collapses, we meticulously Backtrack by popping the element back out!
 * Now we deploy our flawless duplicate defense: before we trigger the "Skip" branch, we aggressively fire our `while` loop to completely leapfrog over any remaining identical numbers in the current cluster! 
 * Finally, with all duplicate timelines completely destroyed, we confidently advance past the cluster, recursively explore the remaining unique elements, and effortlessly return the absolute fastest, cleanest list of combinations!
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
        formcombo(target,candidates,ind+1,combo,res,total+candidates[ind]);
        combo.pop_back();
        while(ind+1 < candidates.size() && candidates[ind] == candidates[ind+1]) ind++;
        formcombo(target,candidates,ind+1,combo,res,total);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> combo;
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        formcombo(target,candidates,0,combo,res,0);
        return res;
    }
};
