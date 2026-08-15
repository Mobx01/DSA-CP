/*Leetcode ps- 3702. Longest Subsequence With Non-Zero Bitwise XOR
You are given an integer array nums.
Return the length of the longest subsequence in nums whose bitwise XOR is non-zero. If no such subsequence exists, return 0.

 */


/* Approach - Pure Mathematical Bitwise Parity / O(N) Greedy Evaluation (Time: O(N), Space: O(1))
 * Basically, we completely annihilate the need for complex subsequence generation by aggressively calculating the global XOR sum, relying on the absolute unbreakable laws of bitwise math to instantly deduce the maximum possible length!
 * * Observation: 
 * - The absolute core of this problem revolves around the mathematical properties of the XOR operation. We are hunting for the longest subsequence that yields a strictly non-zero XOR.
 * - (The Absolute Game-Breaker): If the cumulative XOR of the ENTIRE array is already non-zero, we have achieved instant mathematical victory! We aggressively take the whole array, giving us a maximum length of `N` without dropping a single element!
 * - But what if the global XOR is exactly 0? The laws of bitwise math state that `A ^ B = 0` means `A` and `B` are identical. To break a 0-state XOR, we only ever need to violently evict EXACTLY ONE non-zero element! Why? Because if the total is 0, and we remove `X` (where `X != 0`), the new XOR mathematically becomes `0 ^ X = X`, which is strictly non-zero! This guarantees our answer is instantly `N - 1`!
 * - (The Edge Case Trap): If the array consists entirely of absolute zeroes, no matter how many elements you remove, `0 ^ 0` will forever be 0. Your `nonzero` flag brilliantly catches this mathematical dead-zone, allowing you to flawlessly return a length of 0!
 * * How it runs:
 * First, we safely extract the array size `n`, and initialize our `xorr` accumulator and `nonzero` boolean radar securely to 0/false.
 * Then, we trigger a blistering, single-pass forward sweep. For every single element, we fiercely check if it's not a zero (instantly flipping our radar to `true`), and aggressively smash it into our running `xorr` accumulator!
 * The exact millisecond the sweep finishes, we brutally evaluate the global state. If `xorr` evaluates to completely 0, we hit our fallback logic. 
 * We check the radar: if we found at least one non-zero element anywhere in the array, we ruthlessly sacrifice exactly one of them, instantly returning `n - 1`! If it's a void of pure zeros, we mathematically concede and return `0`.
 * Finally, if the original `xorr` was strictly non-zero right out of the gate, we confidently bypass the fallback and return `n`, effortlessly crushing the problem in absolute peak O(N) time!
 */


class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        bool nonzero = false;
        int xorr = 0;
        for(int i : nums){
            if(i != 0){
                nonzero = true;
            }
            xorr = xorr^i;
        }

        if(xorr == 0){
            if(nonzero) return n-1;
            else return 0;
        }
        return n;
    }
};
