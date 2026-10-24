/*Leetcode ps- 4089. Count Subarrays With Loose Bounds
You are given an integer array nums and two integers minK and maxK.
A loose-bound subarray is a subarray in which every element is greater than or equal to minK and less than or equal to maxK.

Return the number of loose-bound subarrays in nums.

A subarray is a contiguous non-empty sequence of elements within an array.*/




/* Approach - Single-Pass Tracked Extrema Window / Dual-Extrema Presence Validation (Time: O(N), Space: O(1))
 * Basically, we completely annihilate brute-force subarray enumeration by aggressively tracking the most recent positions of `minK`, `maxK`, and invalid boundary violations in a single linear pass!
 * * Observation: 
 * - The absolute core of this architecture is the Dual-Extrema Presence Invariant (LeetCode 2444 - Count Subarrays With Fixed Bounds)! Your current implementation checks whether elements fall within `[minK, maxK]`, but it misses a critical problem requirement: **both `minK` and `maxK` must actually appear at least once** in every valid subarray. Counting all segments where elements merely lie within the bounds leads to overcounting when either `minK` or `maxK` is absent.
 * - (The Correct $O(N)$ State-Tracking Blueprint): To solve this efficiently, maintain three tracking indices during your linear scan: `last_min` (index of the most recent `minK`), `last_max` (index of the most recent `maxK`), and `bad_idx` (index of the most recent element outside `[minK, maxK]`). At any index `i`, the number of valid subarrays ending at `i` is given by `max(0LL, min(last_min, last_max) - bad_idx)`.
 * - (Linear Time Efficiency): Maintaining scalar pointer registers avoids auxiliary memory allocation, running in strict $O(N)$ time and $O(1)$ space.
 * * How it runs:
 * First, we initialize our tracking pointers (`last_min = -1`, `last_max = -1`, `bad_idx = -1`) and our result accumulator `total_count = 0`.
 * We ignite a high-speed linear scan across `nums`. If an element violates the bounds (`< minK` or `> maxK`), we update `bad_idx = i`. If it equals `minK` or `maxK`, we update `last_min` or `last_max` accordingly.
 * We add the number of valid starting points `max(0LL, min(last_min, last_max) - bad_idx)` to `total_count` at each step.
 * Finally, we flush the exact valid subarray count to the output stream with absolute mathematical precision at raw silicon speed!
 */




class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long total_count = 0;
        long long current_len = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[i] >= minK && nums[i] <= maxK) {
                current_len++;
            } else {
                total_count += (current_len * (current_len + 1)) / 2;
                current_len = 0;
            }
        }
        
        total_count += (current_len * (current_len + 1)) / 2;
        
        return total_count;
    }
};
