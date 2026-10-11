/*Leetcode ps - 367. Valid Perfect Square
Given a positive integer num, return true if num is a perfect square or false otherwise.
A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.
You must not use any built-in library function, such as sqrt.*/



/* Approach - Linear Square Search Optimization (Time: O(sqrt(N)), Space: O(1))
 * Basically, we completely annihilate floating-point math overhead by aggressively testing integer products up to the square root boundary, verifying perfect square validity in pristine sub-linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Bounded Square Root Invariant (LeetCode 367 - Valid Perfect Square)! Instead of relying on floating-point square root functions (`sqrt`) which can introduce precision errors or performance penalties, incrementing a `long long` integer `i` while `i * i <= num` safely sweeps through all possible square roots up to $\sqrt{\text{num}}$. If any product matches `num`, it returns true instantly.
 * - (Overflow Prevention via `long long`): Using `long long i` ensures that the product `i * i` never suffers from standard 32-bit signed integer overflow when approaching higher test limits.
 * - (Alternative Binary Search Scaling): While this linear check runs in $O(\sqrt{N})$ time and easily passes for standard constraints, an $O(\log N)$ binary search between `1` and `num` can provide even faster theoretical scaling for massive inputs!
 * * How it runs:
 * First, we initialize our loop iterator `i = 1`.
 * We ignite a bounded loop running while `i * i <= num`.
 * Inside, we check if `i * i == num`; if true, we return `true`.
 * If the loop terminates without a match, we return `false` with absolute mathematical precision at raw silicon speed!
 */




class Solution {
public:
    bool isPerfectSquare(int num) {
        for(long long i = 1; i*i <= num ;i++){
            if(i*i == num){
                return true;
            }
        }
        return false;
    }
};
