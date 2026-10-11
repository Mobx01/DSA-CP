/*Leetcode ps-344. Reverse String
Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.

*/



/* Approach - Two-Pointer Mirror Swap / Symmetric Vector Inversion (Time: O(N), Space: O(1))
 * Basically, we completely annihilate extra memory allocation overhead by aggressively swapping symmetric elements from the outer boundaries toward the center, reversing the character vector in-place in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Symmetric Mirror Invariant (LeetCode 344 - Reverse String)! By iterating up to the midpoint (`n / 2`) and swapping each element at index `i` with its mirror counterpart at `n - 1 - i`, you achieve a complete array reversal with the absolute minimum number of operations.
 * - (Constant Auxiliary Space Footprint): Operating entirely in-place without allocating any auxiliary data structures keeps the auxiliary space complexity at an absolute $O(1)$.
 * - (Standard Library Swap Efficiency): Leveraging `std::swap` compiles down to optimal machine instructions, ensuring maximum execution speed.
 * * How it runs:
 * First, we safely intercept vector size `n`.
 * We ignite a high-speed linear sweep from `0` up to `n / 2`.
 * At each step, we swap the character at index `i` with its corresponding mirror position `n - 1 - i`.
 * Finally, the modified vector is fully reversed in-place with absolute mathematical precision at raw silicon speed!
 */




class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();

        for(int i =0;i<n/2;i++){
            swap(s[i],s[n-i-1]);
        }
    }
};
