/*Leetcode ps- 3644. Maximum K to Sort a Permutation
You are given an integer array nums of length n, where nums is a permutation of the numbers in the range [0..n - 1].
You may swap elements at indices i and j only if nums[i] AND nums[j] == k, where AND denotes the bitwise AND operation and k is a non-negative integer.
Return the maximum value of k such that the array can be sorted in non-decreasing order using any number of such swaps. If nums is already sorted, return 0.

*/



/* Approach - Bitwise AND Accumulation with Permutation Sortedness Verification (Time: O(N), Space: O(1))
 * Basically, we completely annihilate brute-force sorting simulations by aggressively checking 0-indexed permutation alignment and accumulating the bitwise AND of all misplaced elements in pristine linear time and constant space!
 * * Observation: 
 * - The absolute core of this architecture is the Permutation Invariant and Bitwise AND Reduction! For a 0-indexed permutation of `0` to `n - 1`, checking if every element satisfies `nums[i] == i` instantly determines if the array is already sorted (`return 0`). If elements are out of place, accumulating their bitwise AND (`k &= nums[i]`) extracts the shared invariant bitmask across all misplaced values.
 * - (Modern C++ Header Inclusion): Including `#include <bit>` brings in modern C++20 bit manipulation utilities, though the core logic relies on standard bitwise AND operations (`&=`).
 * - (Constant Auxiliary Space Footprint): Operating entirely with scalar registers (`k`, `sort`, `n`) keeps auxiliary space at an absolute $O(1)$ while scanning the vector in a single linear pass ($O(N)$ time).
 * * How it runs:
 * First, we initialize `k = -1` and our `sort` flag to `true`.
 * We ignite a high-speed linear sweep across `nums`. If any element violates `nums[i] == i`, we flip `sort` to `false` and compute the cumulative bitwise AND across all such misplaced values.
 * We return `0` if the permutation is already sorted; otherwise, we return the resulting bitwise AND mask `k` with absolute mathematical precision at raw silicon speed!
 */





#include<bit>
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int k = -1;
        bool sort= true;
        for(int i=0;i<n;i++){
            if(nums[i] != i){
                sort = false;
                if(k == -1) k = nums[i];
                else k &= nums[i];
            }
        }

        if(sort){
            return 0;
        }
        return k;
    }
};
