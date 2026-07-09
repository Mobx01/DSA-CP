/*Leetcode ps-3532. Path Existence Queries in a Graph I
You are given an integer n representing the number of nodes in a graph, labeled from 0 to n - 1.
You are also given an integer array nums of length n sorted in non-decreasing order, and an integer maxDiff.
An undirected edge exists between nodes i and j if the absolute difference between nums[i] and nums[j] is at most maxDiff (i.e., |nums[i] - nums[j]| <= maxDiff).
You are also given a 2D integer array queries. For each queries[i] = [ui, vi], determine whether there exists a path between nodes ui and vi.
Return a boolean array answer, where answer[i] is true if there exists a path between ui and vi in the ith query and false otherwise*/

/* Approach - Connected Components / Precomputation (Time: O(N + Q), Space: O(N))
 * Basically, we group adjacent reachable elements into contiguous "islands" (components) in a single pass, allowing us to answer any path existence query instantly in O(1) time!
 * * Observation:
 * - Movement is only allowed between adjacent indices if the difference `nums[i] - nums[i-1]` is less than or equal to `maxDiff`.
 * - This means valid paths form isolated, contiguous segments. If two indices belong to the exact same segment (component), a path naturally exists between them. If they are in different segments, the gap between them is strictly uncrossable.
 * * How it runs:
 * First, we initialize a `component` array of size 'n' to track which island each index belongs to, assigning index 0 to component ID 0.
 * Then, we sweep through the `nums` array from left to right. If the gap between the current element and the previous one strictly exceeds `maxDiff`, the path is broken, so we increment our `compId` to start a brand new island. We assign this active `compId` to the current index.
 * Finally, we process the queries. For each query, we simply check if the starting index and ending index share the exact same component ID. If they do, we push 'true' to our result; otherwise, 'false'!
 */

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> component(n, -1);
        int compId = 0;
        component[0] = compId;
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i-1] > maxDiff) {
                compId++;
            }
            component[i] = compId;
        }


        vector<bool> result;
        for (auto& query : queries) {
            result.push_back(component[query[0]] == component[query[1]]);
        }
        return result;
    }
};
