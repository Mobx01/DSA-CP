/*Leetcode ps-2089. Find Target Indices After Sorting Array
You are given a 0-indexed integer array nums and a target element target.
A target index is an index i such that nums[i] == target.
Return a list of the target indices of nums after sorting nums in non-decreasing order. If there are no target indices, return an empty list. The returned list must be sorted in increasing order.*/



/* Approach - Sorting with Linear Index Collection / Contiguous Rank Grouping (Time: O(N log N), Space: O(log N))
 * Basically, we completely annihilate complex hash mapping by aggressively sorting the array to group identical target values contiguously, collecting their 0-based indices in pristine log-linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Sorted Rank Invariant (LeetCode 2089 - Find Target Indices After Sorting Array)! Once the array is sorted in ascending order, all occurrences of `target` naturally form a contiguous subsegment. While sorting takes $O(N \log N)$ time, an even faster $O(N)$ optimization exists: by simply counting how many elements are strictly smaller than `target` and how many equal `target`, you can generate all indices mathematically via a simple loop without sorting at all!
 * - (Linear Index Extraction): Scanning the sorted array from left to right and pushing index `i` whenever `nums[i] == target` guarantees that all matching positions are gathered in correct ascending order.
 * - (Auxiliary Space Footprint): The sorting operation requires $O(\log N)$ stack space, while the output vector stores the resulting indices.
 * * How it runs:
 * First, we initialize our result vector `ans` and sort vector `nums` in ascending order.
 * We ignite a linear scan from index `0` to `n - 1`.
 * At each position, we check if `nums[i] == target`, pushing the current index `i` into `ans` if it matches.
 * Finally, we flush the collected index vector to the output stream with absolute mathematical precision at raw silicon speed!
 */



class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] == target)ans.push_back(i);
        }
        return ans;
    }
};
