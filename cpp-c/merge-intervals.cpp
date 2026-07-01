/*Leetcode ps -56. Merge Intervals
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.*/


/* Approach - Sorting & Linear Merging
 * Basically, we sort the intervals by their starting times, which naturally groups potential overlaps together, allowing us to merge them smoothly in a single left-to-right sweep.
 * Observation: 
 * - If the intervals are sorted by their start times, any interval that overlaps with our current running interval *must* have a starting time that is less than or equal to our current ending time.
 * - When an overlap occurs, the merged interval should simply stretch to cover both, meaning its new end time becomes the maximum of the two overlapping end times.
 *
 * How it runs:
 * First, we sort the 'intervals' array. In C++, sorting a 2D vector automatically sorts them by the first element of each sub-array (the start times), lining them up in chronological order.
 * Then, we grab the very first interval and store it in a temporary variable called 'prev'. This will act as our active, expanding interval.
 * Next, we loop through the rest of the intervals. At each step, we compare the start time of the current interval ('intervals[i][0]') to the end time of our active 'prev' interval ('prev[1]').
 * - If it's less than or equal, we found an overlap! We greedily extend 'prev' by updating its end time to the maximum of both ending times.
 * - If it's strictly greater, there is no overlap. Our active 'prev' interval is officially complete! We push it into our 'ans' list, and reset 'prev' to be the current interval to start building the next chain.
 * Finally, after the loop finishes, our very last 'prev' interval will be left hanging, so we make sure to push it into 'ans' before returning the final merged list!
 */


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>  ans;
        sort(intervals.begin(),intervals.end());//will be sorted accooring to start time 
        vector<int> prev = intervals[0];
        int n =intervals.size();
        for(int i=0;i<n;i++){
            if(prev[1] >= intervals[i][0]){//if ending of previsous is bigger than start of current 
                prev[1] = max(prev[1],intervals[i][1]); // prev ending is maximum of its ending and current ones ending
            }else{
                ans.push_back(prev);
                prev = intervals[i];
            }
        }
        ans.push_back(prev);
        return ans;
    }
};
