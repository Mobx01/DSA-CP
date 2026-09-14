/*Leetcode ps435- Non-overlapping Intervals
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.*/



/* Approach - Greedy Earliest-End-Time Interval Scheduling / Overlap Elimination (Time: O(N log N), Space: O(1) auxiliary)
 * Basically, we completely annihilate brute-force subset combinations by aggressively sorting intervals by their end times and greedily retaining the ones that finish earliest, maximizing available timeline space for all subsequent elements!
 * * Observation: 
 * - The absolute core of this architecture is the Earliest End Time Greedy Choice! When trying to minimize the number of intervals to remove to eliminate overlaps, the optimal strategy is always to pick the interval that ends as early as possible. By sorting the intervals based on `a[1] < b[1]`, your code guarantees that the retained interval leaves the maximum possible room for future non-overlapping intervals.
 * - (Pristine Pointer Management): Your pointer logic (`i` tracking the last valid non-overlapping interval, `j` scanning ahead) is absolute textbook perfection. When an overlap occurs (`intervals[i][1] > intervals[j][0]`), you correctly increment your removal count and leave `i` unchanged to skip the overlapping candidate. When no overlap occurs, you cleanly update your reference pointer (`i = j`).
 * - (Edge Case Safety Win): Explicitly intercepting `if (n == 1) return 0;` upfront prevents out-of-bounds index issues and unnecessary sorting overhead on trivial single-element inputs.
 * * How it runs:
 * First, we safely intercept the intervals vector and handle the trivial single-element edge case.
 * We invoke the sorting engine to order the intervals in ascending sequence based on their end coordinates.
 * We initialize our tracking pointers (`i = 0`, `j = 1`) and our removal counter (`count = 0`).
 * We ignite a high-speed linear scan: if interval `j` starts before interval `i` finishes, an overlap is flagged, forcing us to increment `count`. Otherwise, we advance our reference pointer to `i = j`.
 * Finally, we flush the total number of removed intervals to the output stream with absolute mathematical precision at raw silicon speed!
 */



class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count=0,i=0,j=1,n=intervals.size();
        if(n == 1) return 0;
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });

        while(j < n){
            if(intervals[i][1] > intervals[j][0]){
                count++;
            }else{
                i=j;
            }
            j++;
        }
        return count;
    }
};
//if end of i > start of j - > count++, movej++
// else -> , i=j, j++;
