/*Leetcode ps-57. Insert Interval
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
Two intervals are considered overlapping if they share at least one point.
Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
Return intervals after the insertion.
Note that you don't need to modify intervals in-place. You can make a new array and return it.*/




/* Approach - Sequential Interval Insertion & Global Merge / Re-Sorting Strategy (Time: O(N log N), Space: O(log N) auxiliary)
 * Basically, we completely annihilate complex manual placement logic by aggressively reusing our `merge` utility, appending the new interval and triggering a full global sort to unify overlapping spans in clean, modular code!
 * * Observation: 
 * - The absolute core of this architecture is the Modular Code Reuse Pattern! Instead of writing a separate, branch-heavy insertion algorithm, you brilliantly realized that LeetCode's "Insert Interval" can be solved simply by pushing the new interval onto the list and passing it straight to your existing `merge` engine.
 * - (The $O(N \log N)$ Sorting Bottleneck): While your code reuse is elegant, it introduces a hidden performance tax! The problem statement guarantees that the input `intervals` vector is *already sorted*. By pushing the new interval and calling `sort(intervals.begin(), intervals.end())`, you discard this sorted property and force a full $O(N \log N)$ sorting pass. An optimal Insert Interval solution can achieve true $O(N)$ time by iterating through and placing the interval in a single pass without re-sorting!
 * - (The `i = 0` Self-Comparison Nuance): In your `merge` function, you initialize `prev = intervals[0]` and then loop `for(int i = 0; i < n; i++)`. This means the very first iteration compares `intervals[0]` against itself (`prev[1] = max(prev[1], intervals[0][1])`). While completely harmless and mathematically safe, starting the loop at `i = 1` avoids redundant self-comparisons.
 * * How it runs:
 * First, we inject the `newInterval` directly into the back of our intervals vector.
 * We invoke the global sorting engine to re-align the entire sequence in ascending order of start coordinates.
 * We initialize a tracking window (`prev`) with the first interval and sweep across the array, merging any overlapping or touching bounds by maximizing end points.
 * Finally, we flush the accumulated merged intervals into our answer vector and return it at raw silicon speed!
 */




class Solution {
public:
   vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end()); //now intervals next is actullay aliged correctly

        vector<int> prev = intervals[0];
        for(int i= 0;i<n;i++){
            if(prev[1] >= intervals[i][0]){//ending of last interval is greater than or starting of current so merge both
                prev[1] = max(prev[1],intervals[i][1]);
            }else{//store the interval in answer
                ans.push_back(prev);
                prev = intervals[i];
            }
        } 
        //store the last interval
        ans.push_back(prev);
        return ans;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
};
