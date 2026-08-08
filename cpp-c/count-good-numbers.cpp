/*Leetcode ps-1922. Count Good Numbers
A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

*/


/* Approach - Combinatorics & Binary Exponentiation (Time: O(log N), Space: O(1))
 * Basically, we mathematically derive the exact number of choices for every single position based on index parity, and aggressively deploy Binary Exponentiation to calculate the astronomical result in lightning-fast logarithmic time!
 * * Observation: 
 * - The rules of a "good" number are perfectly rigid: even indices (0, 2, 4...) MUST be filled with even digits (0, 2, 4, 6, 8) giving us exactly 5 choices. Odd indices (1, 3, 5...) MUST be filled with prime digits (2, 3, 5, 7) giving us exactly 4 choices!
 * - For a string of length 'n', the mathematical distribution of these indices is flawlessly consistent: there will always be exactly `(n + 1) / 2` even indices and `n / 2` odd indices.
 * - (The Absolute Game-Breaker): The total length 'n' can be up to a massive 10^15! If we ran a standard O(N) loop to multiply the choices together, it would catastrophically crash with a Time Limit Exceeded (TLE). We brilliantly bypass this by deploying Binary Exponentiation (Fast Powering), structurally shredding the O(N) linear multiplication directly down to a blistering O(log N) runtime!
 * * How it runs:
 * First, we fiercely compute the exact exponents using our O(1) integer division logic (`(n+1)/2` for the 5s, and `n/2` for the 4s).
 * Then, we aggressively throw these massive numbers directly into our highly optimized `power` function.
 * Inside `power`, we mathematically shred the exponent bit by bit (`exp /= 2`). Instead of multiplying one by one, we aggressively square the base at every single step, allowing us to leapfrog through the calculation while safely wrapping every single operation inside our `1e9+7` modulo to completely eliminate any risk of 64-bit integer overflow.
 * Finally, we flawlessly multiply the final results of the 5s and 4s together, hit it with one last protective modulo, and confidently return the absolute total number of perfectly valid strings!
 */


class Solution {
public:
    long long MOD = 1e9+7;
    long long power(long long base, long long exp) { //binary exponent
        long long res = 1;
        base = base % MOD;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        return (power(1LL*5,(n+1)/2)*power(1LL*4,(n/2)))%MOD;
    }
};


// formula i derived is 5^number of even indices * 4 ^number of odd indices.
// 5^(n+1)/2 * 4^(n/2);
