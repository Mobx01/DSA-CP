/*Leetcode ps-2220. Minimum Bit Flips to Convert Number
A bit flip of a number x is choosing a bit in the binary representation of x and flipping it from either 0 to 1 or 1 to 0.
For example, for x = 7, the binary representation is 111 and we may choose any bit (including any leading zeros not shown) and flip it. We can flip the first bit from the right to get 110, flip the second bit from the right to get 101, flip the fifth bit from the right (a leading zero) to get 10111, etc.
Given two integers start and goal, return the minimum number of bit flips to convert start to goal.

*/


/* Approach - Pure Bitwise XOR / Modulo Bit Extraction (Time: O(log N), Space: O(1))
 * Basically, we completely annihilate the need to compare the two numbers bit by bit by aggressively smashing them together using a mathematical XOR collision, violently illuminating every single mismatched bit!
 * * Observation: 
 * - The absolute core of this algorithm is the XOR operator (`^`). It acts as a flawless, mathematical difference detector! Identical bits brutally cancel each other out to `0`, while mismatched bits instantly flare up as `1`!
 * - Once we capture the mathematical differences in `dif`, the problem structurally collapses into simply counting the number of set bits (1s) in the new variable!
 * - (Optimization Alert / The Bitwise Upgrade): You brilliantly captured the XOR difference, but then you deployed integer arithmetic (`% 2` and `/ 2`) to process a purely binary structure! You can instantly upgrade this by swapping to pure bitwise operators: `if (dif & 1)` and `dif >>= 1`! This completely bypasses the CPU's clunky division engine, executing the shifts directly in the hardware registers for a blistering performance boost!
 * - (The Ultimate O(1) Hardware Nuke): You can actually completely annihilate the entire `while` loop! C++ compilers possess a built-in intrinsic function `__builtin_popcount(start ^ goal)` which mathematically counts set bits by mapping directly to a single, flawless hardware-level instruction! It crushes the entire problem into one absolute peak O(1) line of code!
 * * How it runs:
 * First, we violently collide `start` and `goal` using `start ^ goal`, securely locking the exact mismatch map into our `dif` variable, and anchoring our `count` to 0.
 * Then, we ignite the extraction loop! While `dif` still contains active bits (`dif > 0`), we mathematically inspect the absolute least significant bit.
 * If `dif % 2 == 1`, we have detected a mandatory bit flip, and we aggressively increment our `count`!
 * Next, we forcefully divide `dif` by 2, which mathematically right-shifts the entire binary structure, violently ejecting the processed bit and perfectly pulling the next one into the crosshairs!
 * Finally, the exact millisecond `dif` collapses to completely 0, we confidently return the absolute minimum number of flips required, flawlessly completing the timeline without allocating a single array!
 */



class Solution {
public:
    int minBitFlips(int start, int goal) {
        int dif  = start^goal,count=0;
        while(dif >0){
            if(dif%2 == 1) count++;
            dif /= 2;
        }
        return count;
    }
};
