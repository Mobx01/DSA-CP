/*Lettcode ps-3904. Smallest Stable Index II
You are given an integer array nums of length n and an integer k.
For each index i, define its instability score as max(nums[0..i]) - min(nums[i..n - 1]).
In other words:
max(nums[0..i]) is the largest value among the elements from index 0 to index i.
min(nums[i..n - 1]) is the smallest value among the elements from index i to index n - 1.
An index i is called stable if its instability score is less than or equal to k.
Return the smallest stable index. If no such index exists, return -1.*/



/* Approach - Dual-Prefix/Suffix Extremum Mapping / Boundary State Decoupling (Time: O(N), Space: O(N))
 * Basically, we completely annihilate the O(N^2) brute force lookback/lookahead by aggressively pre-computing the running maximums and minimums from both flanks, locking in the absolute spatial bounds to evaluate stability in a single linear pass!
 * * Observation: 
 * - The absolute core of this architecture is the Independent Extremum Partition! You brilliantly realized that determining if an index is stable requires knowing the maximum value to its left (`premax`) and the minimum value to its right (`postmin`). By decoupling these calculations into independent linear sweeps, you instantly transform a quadratic search into a pristine linear validation!
 * - (The Triple-Pass Memory Burn): Your logic is mathematically absolute, but your memory profile is a heavy performance tax! You are aggressively allocating TWO separate O(N) vectors (`premax` and `postmin`) and forcing the CPU through a massive 3-pass sequence (Forward Max Sweep, Backward Min Sweep, Final Validation Scan)! This severely fragments the heap and thrashes the L1 cache!
 * - (Optimization Alert / The Suffix-Array Annihilation): You can completely vaporize the `postmin` vector! Think about the direction of the final validation loop: you are scanning from left to right (`i = 0` to `n-1`). If you pre-calculate the `premax` array, you can maintain the `postmin` values *on the fly* with a simple trailing scalar variable! Start your loop with `postmin` already fully accumulated, or build `postmin` on a single forward pass by keeping a running tracker. Even better, you can completely eliminate auxiliary storage for `postmin` by scanning backwards or rolling the state!
 * - (The Immediate Short-Circuit): Look closely at your final evaluation loop: `if (premax[i] - postmin[i] <= k) return i;`. Because you are iterating sequentially from index `0` upward, the very first index that satisfies the condition is mathematically guaranteed to be the *first* stable index! Your `return i` statement correctly exploits this, immediately short-circuiting out of the loop the exact millisecond victory is achieved!
 * * How it runs:
 * First, we safely intercept the array bounds and allocate our `premax` vector, executing a high-speed forward sweep to track the running maximum from the left flank.
 * We allocate our `postmin` vector and execute a high-speed reverse sweep to track the running minimum from the right flank.
 * We trigger the final validation scan! We march linearly from left to right across the timeline.
 * For every index `i`, we violently subtract our pre-computed `postmin[i]` from `premax[i]` and smash it against our threshold `k`.
 * The exact millisecond the condition holds true, we instantly short-circuit and return `i`. If the entire timeline collapses without a single match, we safely return `-1`!
 */



class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> premax(n);
        premax[0] = nums[0];
        for(int i=1;i<n;i++){
            premax[i] = max(premax[i-1],nums[i]);
        }
        vector<int> postmin(n);
        postmin[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            postmin[i] = min(postmin[i+1],nums[i]);
        }

        for(int i=0;i<n;i++){
            if(premax[i] - postmin[i] <= k){
                return i;
            }
        }
        return -1;
    }
};
