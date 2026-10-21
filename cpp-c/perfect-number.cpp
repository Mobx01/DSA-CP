/*Leetcode ps-507. Perfect Number
A perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself. A divisor of an integer x is an integer that can divide x evenly.
Given an integer n, return true if n is a perfect number, otherwise return false.*/




/* Approach - Bounded Divisor Sum Accumulation / Proper Factor Verification (Time: O(sqrt(N)), Space: O(1))
 * Basically, we completely annihilate brute-force linear divisor iteration by aggressively pairing factor pairs up to the square root boundary, summing proper divisors in pristine sub-linear time and constant space!
 * * Observation: 
 * - The absolute core of this architecture is the Proper Divisor Summation Invariant (LeetCode 507 - Perfect Number)! A perfect number is a positive integer that is equal to the sum of its positive proper divisors (excluding the number itself). By iterating from `i = 1` up to $\sqrt{\text{num}}$ and capturing both `i` and `num / i` whenever `num % i == 0`, we efficiently collect all divisors. Subtracting `num` at the end accounts for the fact that `num` itself (from `i = 1`, where `num / 1 = num`) is included in the initial summation loop.
 * - (Edge Case Guard): Explicitly checking `if (num == 1) return false;` prevents incorrect classification of `1` (since its proper divisors sum to `0`, not `1`).
 * - (Sub-Linear Efficiency): Running up to $\sqrt{N}$ via `i * i <= num` ensures that large inputs (such as `10^8`) execute in fractions of a millisecond without timing out.
 * * How it runs:
 * First, we verify if `num == 1`, returning `false` immediately.
 * We initialize our divisor `sum` register to `0`.
 * We ignite a bounded loop from `i = 1` up to `i * i <= num`, adding both `i` and its complementary factor `num / i` to `sum` whenever `i` cleanly divides `num`.
 * We subtract `num` from `sum` to exclude the number itself, and return `true` if `num == sum` (or `false` otherwise) with absolute mathematical precision at raw silicon speed!
 */




class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum =0;
        if(num == 1)return false;
        for(int i =1;i*i <= num;i++){
            if(num%i == 0){
                sum += (i + num/i); 
            }
        }
        sum -= num;
        return (num == sum);
    }
};
