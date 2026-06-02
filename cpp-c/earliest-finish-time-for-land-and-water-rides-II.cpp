/*Leetcode ps - 3635. Earliest Finish Time for Land and Water Rides II
You are given two categories of theme park attractions: land rides and water rides.
Land rides
landStartTime[i] – the earliest time the ith land ride can be boarded.
landDuration[i] – how long the ith land ride lasts.
Water rides
waterStartTime[j] – the earliest time the jth water ride can be boarded.
waterDuration[j] – how long the jth water ride lasts.
A tourist must experience exactly one ride from each category, in either order.

A ride may be started at its opening time or any later moment.
If a ride is started at time t, it finishes at time t + duration.
Immediately after finishing one ride the tourist may board the other (if it is already open) or wait until it opens.
Return the earliest possible time at which the tourist can finish both rides.*/


/* APPROACH: The "Fastest First Leg" Strategy
 * 
 * To finish both rides as early as possible, we don't need to test every 
 * single combination of land and water rides (which would be slow). 
 * Instead, we only care about finishing our FIRST ride as early as possible 
 * so we have the most time available for the second ride.
 

 * STEP 1: Find the Best "First" Rides
 * • Loop through all land rides and find the absolute earliest finish time.
 * • Loop through all water rides and find the absolute earliest finish time.
 
 * STEP 2: Test Scenario A (Land ride first -> Water ride second)
 * • Assume we take the fastest possible land ride. 
 * • Now, check every available water ride. We can start a water ride either 
 *   when it opens, OR when our land ride finishes (whichever is later). 
 * • Calculate the final finish time for each and track the minimum.
 
 * STEP 3: Test Scenario B (Water ride first -> Land ride second)
 * • Assume we take the fastest possible water ride.
 * • Check every available land ride using the exact same logic as above.
 
 * STEP 4: Return Result
 * • The answer is the smallest total time found across both scenarios.
 
 * Complexity:
 * • Time: O(N + M) - We only loop through the arrays separately, never nested!
 * • Space: O(1) - We only use a few variables, so memory usage is constant.
 * ============================================================================
 */


class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        //earliest land finish time possible
        int minLandFinish = INT_MAX;
        int n = landStartTime.size();
        for(int i = 0; i < n; i++) {
            minLandFinish = min(minLandFinish, landStartTime[i] + landDuration[i]);
        }
        
        // Earliedt water finish time possible
        int minWaterFinish = INT_MAX;
        int m = waterStartTime.size();
        for(int i = 0; i < m; i++) {
            minWaterFinish = min(minWaterFinish, waterStartTime[i] + waterDuration[i]);
        }
        
        int earliestTotalTime = INT_MAX;
        
        //  Land ride first -> Water ride second
        for(int i = 0; i < m; i++) {
            int finishTime = max(minLandFinish, waterStartTime[i]) + waterDuration[i];
            earliestTotalTime = min(earliestTotalTime, finishTime);
        }
        
        //  Water ride first -> Land ride second
        for(int i = 0; i < n; i++) {
            int finishTime = max(minWaterFinish, landStartTime[i]) + landDuration[i];
            earliestTotalTime = min(earliestTotalTime, finishTime);
        }
        
        return earliestTotalTime;
    }
};
