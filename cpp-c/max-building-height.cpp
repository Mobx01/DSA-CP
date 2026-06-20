/*Leetcode ps- 1840. Maximum Building Height
You want to build n new buildings in a city. The new buildings will be built in a line and are labeled from 1 to n.
However, there are city restrictions on the heights of the new buildings:

The height of each building must be a non-negative integer.
The height of the first building must be 0.
The height difference between any two adjacent buildings cannot exceed 1.
Additionally, there are city restrictions on the maximum height of specific buildings. These restrictions are given as a 2D integer array restrictions where restrictions[i] = [idi, maxHeighti] indicates that building idi must have a height less than or equal to maxHeighti.
It is guaranteed that each building will appear at most once in restrictions, and building 1 will not be in restrictions.
Return the maximum possible height of the tallest building.*/

/*
 * Approach: Two-Pass Sweep
 * 
 * Since building heights can only change by 1 per step, a restriction on one 
 * building limits the maximum heights of the buildings around it. We can solve 
 * this by propagating these limits forward, and then backward.
 * 
 * 1. Setup: Add the default rule (building 1 is exactly height 0). Also add a 
 *    dummy restriction at the very end (building n) with the max possible height 
 *    (n-1) to catch edge cases. Sort everything by building ID.
 * 
 * 2. Left-to-Right Pass: Propagate limits forward. A building can't be taller 
 *    than the previous building's height + the distance between them.
 * 
 * 3. Right-to-Left Pass: Propagate limits backward. A building can't be taller 
 *    than the next building's height + the distance between them.
 * 
 * 4. Find the Peak: The absolute tallest building will usually be somewhere 
 *    in between two restrictions. The max height between two points forms a 
 *    peak, which we can calculate using: (h1 + h2 + distance) / 2.
 */


class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});
        
        sort(restrictions.begin(), restrictions.end());
        int m = restrictions.size();
        
        //Move from left to right to update the peaks
        for(int i = 1; i < m; i++){
            restrictions[i][1] = min(restrictions[i][1], restrictions[i-1][1] + (restrictions[i][0] - restrictions[i-1][0]));
        }

        //Move from right to left to update the peaks
        for(int i = m - 2; i >= 0; i--){
            restrictions[i][1] = min(restrictions[i][1], restrictions[i+1][1] + (restrictions[i+1][0] - restrictions[i][0]));
        }
        
        int maxheight = 0;
        
        // max peak BETWEEN adjacent restrictions
        for(int i = 1; i < m; i++){
            // Distance between the two buildings
            int distance = restrictions[i][0] - restrictions[i-1][0];
            // Heights of the two buildings
            int h1 = restrictions[i-1][1];
            int h2 = restrictions[i][1];
            
            // Intersection peak formula
            int local_max = (h1 + h2 + distance) / 2;
            maxheight = max(maxheight, local_max);
        }
        
        return maxheight;
    }
};
