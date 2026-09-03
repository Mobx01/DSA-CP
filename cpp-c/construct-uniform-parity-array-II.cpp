/*Leetcode ps-3876. Construct Uniform Parity Array II
You are given an array nums1 of n distinct integers.
You want to construct another array nums2 of length n such that the elements in nums2 are either all odd or all even.
For each index i, you must choose exactly one of the following (in any order):

nums2[i] = nums1[i]​​​​​​​
nums2[i] = nums1[i] - nums1[j], for an index j != i, such that nums1[i] - nums1[j] >= 1
Return true if it is possible to construct such an array, otherwise return false.*/



/* Approach - Parity Invariant Exploitation / 1-Pass State Fusion (Time: O(N), Space: O(1))
 * Basically, we completely annihilate the complex simulation logic by aggressively isolating the absolute minimum element, using pure mathematical parity laws to instantly prove if universal uniformity is physically possible!
 * * Observation: 
 * - The absolute core of this architecture is the Minimum Parity Law! You brilliantly realized that an odd number can violently mutate any larger even number into an odd (Even - Odd = Odd). BUT, an even number is mathematically powerless to change an odd number into an even! Therefore, if the absolute smallest element in the entire universe is odd, victory is 100% guaranteed! If it's even, the timeline MUST already be perfectly even, or it's a structural failure!
 * - (The 2-Pass Cache Thrashing Trap): Your mathematical deduction is pristine, but your execution forces the hardware to work overtime! You violently execute `*min_element` to sweep the entire array (Pass 1). Then, if it happens to be even, you ignite a SECOND O(N) `for` loop to scan for rogue odd numbers (Pass 2)! For a massive dataset, this violently pulls the data from RAM into the L1 cache TWICE, wasting precious CPU cycles!
 * - (Optimization Alert / The 1-Pass Fusion Nuke): You can completely vaporize the second loop! You never need to traverse the timeline twice. Ignite a single, high-speed linear sweep. Track the absolute `min_val` AND a boolean flag `has_odd` simultaneously in the exact same O(N) hardware cycle!
 * - (The Modulo Bitwise Shredder): `if(i % 2 == 1)`. While modern compilers optimize this, you can aggressively enforce hardware-level speed by swapping the modulo for a raw Bitwise AND: `if(i & 1)`. This violently strips the division hardware out of the equation and checks the absolute lowest bit in a single CPU clock cycle!
 * * How it runs (The 1-Pass Optimized Vision):
 * First, we safely intercept the array and instantly lock two O(1) registers: `min_val = INT_MAX` and `has_odd = false`.
 * We ignite a single, blistering high-speed linear sweep across the timeline.
 * For every element, we aggressively smash it against `min_val` to track the absolute floor. Simultaneously, we ping our bitwise radar `(x & 1)`—if it's odd, we violently lock `has_odd = true`.
 * The exact millisecond the single loop terminates, we evaluate our O(1) state registers! 
 * If `min_val & 1`, the smallest element is odd, so we mathematically guarantee victory (`return true`)! 
 * If the minimum is even, we simply check our `has_odd` flag. If it triggered, the timeline is permanently corrupted (`return false`); otherwise, the entire universe is perfectly even (`return true`)!
 * Zero redundant loops, peak L1 cache locality, raw silicon speed!
 */



class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minnum = *min_element(nums1.begin(),nums1.end());
        // if the smallest number is odd then its always possible to convert all nunber to odd number
        if(minnum %2 == 1) return true;

        //smallest number is even
        for(int i : nums1){//if all number are even then its good 
            if(i%2 == 1) return false;//odd detected
        }

        // all number are even 
        return true;
    }
};
