/*Leetcode ps-231. Power of Two
Given an integer n, return true if it is a power of two. Otherwise, return false.
An integer n is a power of two, if there exists an integer x such that n == 2x.

*/


/* Approach - Pure Bitwise Manipulation / Brian Kernighan's Logic (Time: O(1), Space: O(1))
 * Basically, we completely annihilate the need for loops or recursion by violently exploiting the fundamental binary architecture of integers, mathematically proving a power of two in a single, blistering CPU cycle!
 * * Observation: 
 * - The absolute unbreakable law of binary states that any mathematical power of two (2, 4, 8, 16...) possesses EXACTLY ONE set bit (`1`) in its entire binary representation! (e.g., 8 is `1000`, 16 is `10000`).
 * - (The Absolute Game-Breaker): The operation `n - 1` mathematically flips all the bits starting from the rightmost set bit. For a perfect power of two, this means its single solitary `1` violently flips to `0`, and every single trailing `0` flips to a `1`! (e.g., `8 - 1 = 7`, which is `1000 -> 0111`).
 * - When we aggressively apply a bitwise AND (`&`) between `n` and `n-1`, it ruthlessly smashes the two binary strings together. Because every single bit is perfectly inverted, the result will mathematically collapse to exactly `0` if and ONLY if it was a true power of two!
 * - (The Edge Case Masterstroke): The number `0`, as well as negative numbers (due to two's complement architecture), mathematically break this logic. Your code brilliantly deploys an immediate `n <= 0` guard, violently terminating these anomalies before they can even touch the bitwise engine!
 * * How it runs:
 * First, we safely intercept the integer `n`. The exact millisecond we detect `n <= 0`, we ruthlessly reject it and return `false`, completely securing the mathematical timeline.
 * Next, we trigger the absolute peak of constant-time computation: `n & (n - 1)`. We aggressively subtract 1 to forcefully invert the trailing bits, and violently smash the result against the original number using the bitwise AND operator.
 * Finally, we deploy the logical NOT `!` to flawlessly invert the output! If the bitwise collision produced exactly `0` (proving it is a flawless power of two), the `!` aggressively flips it to `true`, effortlessly crushing the problem in absolute peak O(1) time without simulating a single loop!
 */


class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return 0;
        return !(n&(n-1));
    }
};
