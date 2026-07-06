/*Leetcode ps - 1288. Remove Covered Intervals
Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.
The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.
Return the number of remaining intervals.*/


/* Approach - Brute Force / Nested Loops (s.c O(N) , T.C O(N^2))
 * Basically, we determine which intervals survive by aggressively checking every single interval against every other interval in the list to see if it gets completely swallowed up!
 * Observation: 
 * - An interval [a, b] is completely "covered" by another interval [c, d] if it starts at the same time or later (c <= a) AND ends at the same time or earlier (b <= d).
 * - Since we aren't sorting the array first, the only way to be absolutely sure an interval isn't covered by anything else is to check it against all N-1 other intervals. (Note: While this O(N^2) approach works, sorting the array first by start times would allow us to solve this much faster in O(N) time!)
 *
 * How it runs:
 * First, we initialize an 'ans' vector to keep track of our surviving intervals.
 * Then, we start our outer loop 'i' to pick a "target" interval [a, b]. We set a flag called 'covered' to 0, assuming it's safe until proven otherwise.
 * Next, we launch our inner loop 'j' to scan all other intervals [c, d]. We immediately skip if 'i == j' because comparing an interval to itself is pointless.
 * Inside the inner loop, we evaluate our strict coverage condition. If the target interval 'i' is entirely engulfed by interval 'j' (c <= a && b <= d), we flip our 'covered' flag to 1! 
 * After the inner loop finishes checking every possibility, we check our flag. If 'covered' is still 0, it means interval 'i' survived the gauntlet, so we confidently push it into our 'ans' list.
 * Finally, once all intervals have been tested, we simply return the size of our 'ans' list, which gives us the exact count of remaining uncovered intervals!
 */

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;

        for(int i =0 ;i < n;i++){
            int covered =0;
            for(int j =0 ;j <n;j++){
                if(i == j) continue;
                int a = intervals[i][0];
                int b = intervals[i][1];
                int c = intervals[j][0];
                int d = intervals[j][1];

                if(c <= a && b <= d) covered = 1;
            }
            if(covered == 0) ans.push_back(intervals[i]);
        }
        return ans.size();
    }
};


/* Approach - Sorting & Single Sweep 
 * Basically, we optimize the brute-force approach by sorting the intervals first! By cleverly ordering them, we guarantee that any interval can only be covered by one that appeared *before* it, allowing us to find the answer in a single, lightning-fast pass.
 *
 * Observation: 
 * - If we sort by starting times in ascending order, we naturally fulfill the first coverage rule (c <= a). Any interval we look at will always start at the same time or later than the ones before it.
 * - The trick is how we handle ties! If two intervals start at the exact same time, we MUST put the longer one first (descending end times). This ensures the larger interval acts as the baseline and immediately engulfs the smaller one right after it.
 *
 * How it runs:
 * First, we define a custom sorting rule using a 'lambda' function: sort by start times low-to-high, and if they tie, sort by end times high-to-low. We apply this to the array.
 * Then, we initialize our 'res' array and push the very first interval into it. This acts as our active, expanding baseline.
 * Next, we loop through the rest of the sorted intervals. Because of our sorting magic, we ALREADY know the current interval starts at or after our baseline's start.
 * Therefore, all we have to check is the ending boundary! If the current interval's end is less than or equal to our baseline's end, it is completely swallowed up. We simply 'continue' and ignore it.
 * If its end reaches further than our baseline, it survived! It is not covered, so we push it into 'res' (and this newly added interval naturally becomes the new baseline for future comparisons).
 * Finally, we just return the size of our 'res' list!
 *
 * Complexity Analysis:
 * - Time Complexity: O(N log N). Sorting the array dominates the time taken. The actual sweeping loop only visits each element exactly once, taking O(N) time. Overall time is bounded by the sort.
 * - Space Complexity: O(N). In the worst-case scenario (where no intervals overlap at all), we will push all N intervals into our 'res' array.
 */

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        auto lambda = [](vector<int> vec1,vector<int> vec2){
            if(vec1[0] == vec2[0]) return vec1[1] > vec2[1];
            return vec1[0]<vec2[0];
        };
        sort(intervals.begin(),intervals.end(),lambda); //tstarting -> asecnding and ending -> descending (in case of same starting)
        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for(int i =1 ;i<n ;i++){
            if(res.back()[0] <= intervals[i][0] && res.back()[1] >= intervals[i][1]) continue;
            res.push_back(intervals[i]);
        }
        return res.size();
    }
};


/* Approach - Space-Optimized Sorting & Single Sweep
 * Basically, we use the exact same brilliant sorting logic as before, but we completely eliminate the extra array! Since we only ever need to check the ending boundary of our active baseline interval to prove coverage, we can just track that single number in a variable to save memory.
 *
 * Observation: 
 * - Because the array is perfectly sorted (start times ascending, tied end times descending), any new interval we look at is mathematically guaranteed to start at or after our active baseline. 
 * - Therefore, all we care about is how far out our active baseline reaches! If the current interval's end time is less than or equal to our running 'lastintervalend', it is entirely swallowed up. If it reaches further, it survives and establishes our new furthest reach.
 *
 * How it runs:
 * First, we sort the array using our custom lambda function to set up our foolproof order.
 * Then, instead of building a whole new array to store survivors, we initialize a 'count' to 1 (accounting for the first interval) and track its ending boundary in the 'lastintervalend' variable.
 * Next, we sweep through the remaining intervals. If the current interval's end time ('intervals[i][1]') is less than or equal to our 'lastintervalend', it's completely covered! We simply 'continue' and skip it.
 * If the current interval ends AFTER our 'lastintervalend', it survived! We increment our survivor 'count' and update 'lastintervalend' to this new, further boundary to test future intervals against.
 * Finally, we return the final 'count'!
 *
 * Complexity Analysis:
 * - Time Complexity: O(N log N). The sorting operation is the bottleneck and dominates the time. The actual loop sweeping through the array is a lightning-fast O(N).
 * - Space Complexity: O(1) auxiliary space! (Technically O(log N) depending on the internal stack space used by C++'s std::sort). By replacing the 'res' vector with two simple integer variables, we optimized our memory usage perfectly!
 */

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        auto lambda = [](vector<int> vec1,vector<int> vec2){
            if(vec1[0] == vec2[0]) return vec1[1] > vec2[1];
            return vec1[0]<vec2[0];
        };
        sort(intervals.begin(),intervals.end(),lambda); //tstarting -> asecnding and ending -> descending (in case of same starting)
        int lastintervalend = intervals[0][1],count=1;

        for(int i =1 ;i<n ;i++){
            if (lastintervalend >= intervals[i][1]) continue;//(res.back()[0] <= intervals[i][0] -> this will be always true because of sorting
            lastintervalend = intervals[i][1];
            count++;
        }
        return count;
    }
};
