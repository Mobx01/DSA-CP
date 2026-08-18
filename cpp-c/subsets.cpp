/*Leetcode ps-78. Subsets
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.*/



/* Approach - DFS Backtracking / Set-Based Deduplication (Time: O(2^N * N log(2^N)), Space: O(2^N * N))
 * Basically, we aggressively split the universe into parallel timelines of "Take" and "Skip", dumping every generated timeline into a massive Red-Black tree to mathematically crush duplicate universes!
 * * Observation: 
 * - The absolute core of this algorithm is the classic Pick/Not-Pick backtracking tree. You brilliantly sort the array right out of the gate, structurally grouping identical elements together to set up the deduplication engine!
 * - (The Fatal Boundary Bug): Look incredibly closely at your duplicate-skipping engine: `while(ind+1 > nums.size() && nums[ind+1] == nums[ind])`! Because `ind` is strictly bounded by the initial `if` check at the top, `ind+1` will mathematically NEVER be greater than `nums.size()`! This brutally short-circuits the loop every single time, meaning your duplicate-skipping logic is completely paralyzed! It MUST be `< nums.size()` to safely peek into the future without shattering the array bounds!
 * - (Insertion Redundancy): Calling `res.insert(combo)` immediately after both `push_back` and `pop_back` violently spams the `set` with massive redundant insertions! A flawless Backtracking engine simply captures the `combo` state exactly once at the absolute top of the `solve` frame, letting the pure recursive tree naturally handle the expansions!
 * - (Optimization Alert / The Set Annihilation): You deployed `set<vector<int>>` to catch duplicates, which aggressively burns CPU cycles performing heavy vector-to-vector comparisons deep inside a Red-Black Tree memory structure! You can completely annihilate the `set`! Since the array is already flawlessly sorted, simply pass a standard `vector<vector<int>>` directly. Capture the subset at the top of the function. On the "Take" branch, you recurse normally. On the "Skip" branch, you trigger the fixed `while` loop to aggressively fast-forward past ALL identical elements *before* you recurse! This mathematically prevents duplicate timelines from even spawning, shredding the time complexity down to a blistering O(2^N)!
 * * How it runs (Current State):
 * First, we safely instantiate our massive `set` and empty `combo` vector, violently sorting `nums` to perfectly align duplicates.
 * We ignite the `solve` engine. If we breach the array boundaries, we instantly abort the timeline!
 * Otherwise, we aggressively take the current element (`push_back`), violently slam it into the `set`, and dive deeper into the "Take" timeline!
 * Once that timeline collapses, we execute the backtrack! We run the (currently bugged) duplicate skip, violently rip the element back out (`pop_back`), spam the `set` again, and dive into the "Skip" timeline!
 * Finally, we painfully iterate through the entire Red-Black Tree, copying the mathematically unique subsets into a standard vector to appease the return type, delivering the result!
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
    vector<vector<int>> subsets(vector<int>& nums) {
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
