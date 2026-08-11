/*Leetcode ps-90. Subsets II
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.*/


/* Approach - Sorting & Backtracking / Broken Duplicate Logic (Time: O(N * 2^N) due to Set, Space: O(N * 2^N))
 * Basically, we mathematically traverse a decision tree to generate subsets, but a fatal typo violently breaks the duplicate skipping logic, forcing a massive, highly-inefficient `set` to awkwardly carry the entire operation!
 * * Observation: 
 * - (The Fatal Bug): Your duplicate pruning loop is mathematically broken! You wrote `ind+1 > nums.size()`. This condition is strictly impossible unless you are already completely out of bounds, meaning your `while` loop NEVER physically executes! It was supposed to be `ind+1 < nums.size()`! Because this failed, your code aggressively generated thousands of duplicate branches!
 * - (The Absolute Regression): Because your `while` loop failed to prune the tree in real-time, you were forced to bring back the dreaded `set<vector<int>>` to awkwardly filter out the duplicates at the very end! This absolutely demolishes your time and space complexity, burning massive CPU cycles on deep vector comparisons and Red-Black tree rotations!
 * - (The State Capture Flaw): You are manually calling `res.insert(combo)` multiple times awkwardly between recursive calls! In a flawless subset algorithm, every single node in the decision tree is a valid subset. You simply push `combo` into your result vector at the VERY TOP of the recursive function before you do anything else! This mathematically guarantees every single intermediate state (including the empty subset) is perfectly captured!
 * * How to flawlessly fix it:
 * First, completely annihilate the `set` and swap directly back to your hyper-optimized `vector<vector<int>> res`!
 * Inside `solve`, instantly push `combo` directly into `res` as the absolute first line of the function.
 * Then, instead of manually taking/skipping with `ind`, trigger a high-speed `for` loop starting from `i = ind` up to `nums.size()`.
 * Inside the loop, deploy the ultimate O(1) duplicate check: `if(i > ind && nums[i] == nums[i-1]) continue;`! This elegantly and violently skips any duplicate number on the exact same recursive level before it can even spawn a timeline!
 * Finally, aggressively `push_back(nums[i])`, recurse with `i + 1`, and meticulously `pop_back()`! This mathematically forces a flawless, guaranteed O(2^N) runtime with absolutely zero redundant branches!
 */


class Solution {
public:
    void solve(vector<int>& nums , set<vector<int>>& res ,vector<int>& combo,int ind){
        if(ind >= nums.size() ) return;

        combo.push_back(nums[ind]);
        res.insert(combo);
        solve(nums,res,combo,ind+1);
        while(ind+1 > nums.size() && nums[ind+1] == nums[ind])ind++;
        combo.pop_back();
        res.insert(combo);
        solve(nums,res,combo,ind+1);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> res;
        vector<vector<int>> result;
        vector<int> combo = {};
        sort(nums.begin(),nums.end());
        solve(nums,res,combo,0);
        for(auto v  : res){
            result.push_back(v);
        }
        return result;
    }
};
