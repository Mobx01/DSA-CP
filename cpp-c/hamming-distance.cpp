/*Leetcode ps-461. Hamming Distance
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Given two integers x and y, return the Hamming distance between them.*/



/* Approach - Bitwise Modulo Extraction / Positional Bit Difference Counting (Time: O(log(max(X, Y))), Space: O(1))
 * Basically, we completely annihilate complex bit manipulation overhead by aggressively extracting least-significant bits via modulo division, counting positional bit mismatches in pristine logarithmic time and constant space!
 * * Observation: 
 * - The absolute core of this architecture is the Bitwise XOR / Parity Mismatch Invariant (LeetCode 461 - Hamming Distance)! The Hamming distance between two integers `x` and `y` represents the number of positions at which the corresponding bits differ, which is mathematically identical to counting the number of set bits (1s) in `x ^ y`. Your division-and-modulo approach (`x % 2 != y % 2` with `x /= 2` and `y /= 2`) directly simulates this bit-by-bit comparison loop.
 * - (Loop Termination Safety): Continuing the loop while `x > 0 || y > 0` ensures that all active bits up to the highest set bit of whichever number is larger are fully evaluated before termination.
 * - (Idiomatic Hardware Optimization): While this iterative modulo approach is clear and correct for non-negative integers, leveraging native bitwise instructions like `__builtin_popcount(x ^ y)` or Brian Kernighan's algorithm (`n & (n - 1)`) provides even faster hardware-level execution.
 * * How it runs:
 * First, we initialize our mismatch `count` register to `0`.
 * We ignite a high-speed while loop that runs as long as either `x` or `y` is greater than `0`.
 * At each iteration, we compare the least significant bits via `x % 2 != y % 2`, incrementing `count` if a mismatch is detected.
 * We divide both numbers by `2` to shift to the next bit position.
 * Finally, we flush the accumulated Hamming distance count to the output stream with absolute mathematical precision at raw silicon speed!
 */



class Solution {
public:
    int hammingDistance(int x, int y) {
        int count=0;
        while(x >0 || y >0){
            if(x%2 != y%2) count++;

            x /= 2;
            y /= 2;
        }
        return count;
    }
};
