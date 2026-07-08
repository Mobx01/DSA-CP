/*Leetcode ps- 1011. Capacity To Ship Packages Within D Days
A conveyor belt has packages that must be shipped from one port to another within days days.
The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.
Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.*/

/* Approach - Binary Search on Answer (Time: O(N log S), Space: O(1)) where S is the sum of all weights
 * Basically, we find the perfectly optimized ship capacity by guessing the answer using Binary Search, as the relationship between capacity and days required is strictly monotonic (bigger ship = fewer days).
 * * Observation: 
 * - The absolute minimum capacity we could ever realistically use must be at least the size of the single heaviest package (otherwise that specific package can never be shipped).
 * - The absolute maximum capacity we would ever practically need is the sum of every package combined (which allows us to ship everything on day 1).
 * - Since higher capacities mathematically guarantee equal or fewer days, we can binary search the optimal capacity between these two logical extremes.
 * * How it runs:
 * First, we sweep through the array exactly once to establish our search boundaries: 'l' becomes the maximum individual weight, and 'r' becomes the total sum of all weights.
 * Then, we enter our binary search loop. We guess a middle capacity ('mid') and pass it to our 'noofday' helper function. This function greedily packs weights onto the ship day by day, ticking up the 'days_needed' counter every time adding the next package would overflow the current 'mid' capacity.
 * Finally, we evaluate the simulation. If the simulated days strictly exceed our target 'days', our ship is too small, so we push our lower bound up ('l = mid + 1'). If we successfully ship within the target limit, we record 'mid' as a valid answer and pull our upper bound down ('r = mid - 1') to hunt for an even tighter, more efficient capacity!
 */


class Solution {
public:
    int noofday(vector<int>& weights, int capacity) {
        int current_weight = 0;
        int days_needed = 1; 
        
        for(int i = 0; i < weights.size(); i++) {
            if(current_weight + weights[i] <= capacity) {
                current_weight += weights[i];
            } else {
                current_weight = weights[i];
                days_needed++;
            }
        }
        return days_needed;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0;
        int r = 0;
        
        for(int w : weights) {
            l = max(l, w); // Minimum capacity needed
            r += w;        
        }
        
        int ans = r; 
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            int d = noofday(weights, mid);

            if(d > days) { 
                // We need more capacity to reduce the days
                l = mid + 1;
            } else { 
                // We can do it in time, but try a tighter capacity
                ans = mid;
                r = mid - 1;
            }
        }
        return ans;
    }
};
