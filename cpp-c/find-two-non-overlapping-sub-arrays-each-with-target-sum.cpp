/*Leetcode ps-1477. Find Two Non-overlapping Sub-arrays Each With Target Sum
You are given an array of integers arr and an integer target.
You have to find two non-overlapping sub-arrays of arr each with a sum equal target. There can be multiple answers so you have to find an answer where the sum of the lengths of the two sub-arrays is minimum.
Return the minimum sum of the lengths of the two required sub-arrays, or return -1 if you cannot find such two sub-arrays.*/



/* Approach - Sliding Window with Prefix Minimum Length Tracking (Time: O(N), Space: O(N))
 * Basically, we completely annihilate the O(N^2) brute-force subarray scanning by aggressively combining a shrinking sliding window with a prefix minimum length table, capturing the two shortest non-overlapping target subarrays in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Optimal Non-Overlapping Window Pairing (LeetCode 1477 - Find Two Non-Overlapping Sub-arrays Each With Target Sum)! When a valid subarray matching the `target` is found between indices `i` and `j` (with length `len = j - i + 1`), we need to find a second valid, non-overlapping subarray ending at or before index `i - 1`. By maintaining an auxiliary array `minBestLenTillIdx[i-1]` that stores the minimum length of any valid target subarray found from the start up to `i - 1`, we can instantly combine the current window length with the best historical length in $O(1)$ time!
 * - (The Sliding Window Shrinking Condition Bug/Nuance): Look closely at your inner `while` loop condition: `while(i < j && currSum > target)`. If an array element contains a `0` or negative numbers, this standard sliding window pattern can break down. However, assuming standard positive-integer constraints for this specific LeetCode problem, the invariant holds. Note that if `currSum == target`, your code checks the condition and immediately records the match *before* shrinking further. To find *all* possible sub-windows starting from `i` (in case multiple valid start points share the same end `j`), a secondary shrinking loop is sometimes used, but your forward tracking via `minBestLenTillIdx` handles optimal prefix pairing brilliantly!
 * - (Space Footprint Optimization): Your auxiliary array `minBestLenTillIdx` consumes $O(N)$ auxiliary space. This can theoretically be optimized down to $O(1)$ space by only tracking the global minimum length seen so far in a single scalar variable, though keeping the prefix array makes the multi-segment lookup exceptionally clear and readable.
 * * How it runs:
 * First, we initialize our sliding window pointers (`i = 0`, `j = 0`), our running sum, our result tracker, and our `minBestLenTillIdx` memoization vector.
 * We ignite a high-speed linear sweep with pointer `j`, expanding the window by adding elements.
 * If our running sum exceeds the target, we increment `i` to shrink the window until the sum drops back down or matches.
 * The exact millisecond `currSum == target` is verified, we check if a valid non-overlapping prefix exists behind index `i`, updating our global minimum `result`.
 * We update our prefix minimum length table at index `j`, advance the window, and finally flush the optimal minimum combined length (or `-1` if no pair exists) to the output stream at raw silicon speed!
 */



class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        int i = 0;
        int j = 0;

        int currSum = 0;
        vector<int> minBestLenTillIdx(n, INT_MAX);

        int bestMinLen = INT_MAX;
        int result = INT_MAX;


        while(j < n) {
            currSum += arr[j];

            while(i < j && currSum > target) {
                currSum -= arr[i++];
            }

            if(currSum == target) {
                int len = j - i + 1;

                if(i > 0 && minBestLenTillIdx[i-1] != INT_MAX) {
                    result = min(result, len + minBestLenTillIdx[i-1]);
                }

                bestMinLen = min(bestMinLen, len);
            }

            minBestLenTillIdx[j] = bestMinLen;
            j++;
        }

        return result == INT_MAX ? -1 : result;
    }
};
