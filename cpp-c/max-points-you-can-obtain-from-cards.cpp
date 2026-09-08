/*Leetcode ps-1423. Maximum Points You Can Obtain from Cards
There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.
In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
Your score is the sum of the points of the cards you have taken.
Given the integer array cardPoints and the integer k, return the maximum score you can obtain.*/



/* Approach - Complementary Sliding Window / Inverse Subarray Minimization (Time: O(N), Space: O(1))
 * Basically, we completely annihilate the O(K) combinatorial branch search by aggressively inverting the problem, mathematically proving that picking `k` cards from the edges is identical to leaving behind a contiguous subarray of size `n - k`!
 * * Observation: 
 * - The absolute core of this architecture is the Inverse Complementary Window! Instead of tracking the shifting left and right edges simultaneously, you brilliantly realize that minimizing the sum of the *unpicked* window of size `n - k` automatically maximizes the sum of the picked outer cards when subtracted from the total sum!
 * - (The Redundant Array Pass Trap): Your algorithmic logic is absolute textbook perfection, but your execution forces a minor hardware inefficiency! You execute a separate, standalone loop (`for(int i : cardPoints)`) at the end just to calculate `fullsum`. While the array data is likely warm in the L1/L2 cache, running a second linear pass over the entire dataset wastes CPU cycles that could be entirely avoided! You can easily accumulate the total sum during the initial window setup or in a single unified pass.
 * - (The Edge-Case Boundary Resilience): Look closely at the mathematical extreme where `k == n`. Your initial window size `n - k` evaluates to `0`. The loop `for(r = 0; r < 0; r++)` naturally skips, `curwindow` starts at `0`, `minsum` starts at `0`, and `fullsum - minsum` correctly returns the sum of all elements. The architecture handles structural boundaries natively with zero branching overhead!
 * * How it runs:
 * First, we safely intercept the array and compute the sum of the initial `n - k` window, establishing our baseline `minsum`.
 * We ignite the high-speed sliding window engine! As our window slides across the timeline from left to right, we drop the outgoing left element and add the incoming right element, dynamically tracking the global `minsum`.
 * Simultaneously (or in a final step), we compute the total sum of all cards in the array.
 * Finally, we subtract the absolute `minsum` of the unpicked window from the `fullsum`, flushing the maximum possible card points to the output stream at raw silicon speed!
 */



class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int curwindow = 0,r=0,l=0,n=cardPoints.size();
        //first window ( size = n-k)
        for(r=0;r<n-k;r++){
            curwindow += cardPoints[r];
        }
        int minsum = curwindow;
        // take the window with minimum sum.(this window will be removed so we need minimum removal from the arraay)
        while(r < n){
            curwindow -= cardPoints[l];
            curwindow += cardPoints[r];
            minsum = min(minsum , curwindow);
            l++;
            r++;
        }
        int fullsum = 0;
        for(int i : cardPoints){
            fullsum += i;
        }
        return fullsum - minsum;
    }
};
