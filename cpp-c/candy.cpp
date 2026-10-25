/*Leeetcode ps - 135. Candy
There are n children standing in a line.
Each child is assigned a rating value given in the integer array ratings.
You are giving candies to these children subjected to the following requirements:
Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.*/




/* Approach - Slope-Based Single-Pass Greedy Distribution / Candy Allocation (Time: O(N), Space: O(1))
 * Basically, we completely annihilate brute-force multi-pass array allocations by aggressively tracking monotonic increasing and decreasing slopes in real-time, adjusting peak overlaps in pristine linear time and constant space!
 * * Observation: 
 * - The absolute core of this architecture is the Slope-Counting Invariant (LeetCode 135 - Candy)! Instead of maintaining two separate left-to-right and right-to-left auxiliary arrays ($O(N)$ space), this advanced single-pass algorithm decomposes the ratings vector into flat regions, increasing slopes, and decreasing slopes. By tracking the length of the `peak` and the `val` (decreasing slope) and subtracting `min(peak, val)` at the intersection, it achieves absolute optimal $O(N)$ time and strict $O(1)$ auxiliary space.
 * - (Flat Rating Handling): Gracefully bypassing flat segments where `ratings[i] == ratings[i-1]` via `i++; continue;` prevents incorrect slope inflation.
 * - (Optimal Space Efficiency): Operating entirely with scalar accumulator registers keeps memory overhead at zero beyond input storage.
 * * How it runs:
 * First, we initialize our candy counter starting with `n` (giving every child at least 1 candy) and index pointer `i = 1`.
 * We ignite a high-speed while loop scanning the vector: skipping flat ratings, climbing increasing slopes while accumulating `peak` increments, and sliding down decreasing slopes while accumulating `val` increments.
 * We subtract `min(peak, val)` from the total candy sum to correct the double-counted peak element.
 * Finally, we flush the optimal minimum candy count to the output stream with absolute mathematical precision at raw silicon speed!
 */




class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        long long candy = n,i=1;

        while(i < n){
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }

            // for increasing slope
            long long peak = 0;
            while(ratings[i] > ratings[i-1]){
                peak++;
                candy += peak;
                i++;
                if(i == n) return candy;
            }

            //for decreasing
            long long val =0;
            while(i < n && ratings[i] < ratings[i-1]){
                val++;
                candy += val;
                i++;
            }
            candy -= min(peak,val);
        }
        return candy;
    }
};
