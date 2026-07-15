/*Leetcode ps-3658. GCD of Odd and Even Sums
You are given an integer n. Your task is to compute the GCD (greatest common divisor) of two values:
sumOdd: the sum of the smallest n positive odd numbers.
sumEven: the sum of the smallest n positive even numbers.
Return the GCD of sumOdd and sumEven.
*/

/* Approach - Mathematical Series & GCD (Time: O(log N), Space: O(1))
 * Basically, we use standard arithmetic progression formulas to find the total sum of the first 'n' odd and even numbers, and directly compute their Greatest Common Divisor.
 * * Observation: 
 * - The sum of the first 'n' positive odd integers (1, 3, 5...) is mathematically proven to always evaluate to exactly n^2.
 * - The sum of the first 'n' positive even integers (2, 4, 6...) is mathematically proven to always evaluate to exactly n(n+1).
 * - (Fun Math Fact: If you factor out 'n' from gcd(n^2, n(n+1)), you get n * gcd(n, n+1). Since consecutive numbers never share common factors other than 1, gcd(n, n+1) is always 1. This means the GCD of these two sums will mathematically always just be 'n'! However, calculating it explicitly like this perfectly mirrors the problem statement.)
 * * How it runs:
 * First, we calculate the sum of the odds inline using 'n * n'.
 * Then, we calculate the sum of the evens inline using 'n * (n + 1)'.
 * Finally, we pass both of these mathematical sums directly into C++'s built-in 'gcd' function and return the final answer!
 */

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return gcd(n*n,n*(n+1));
    }
};
