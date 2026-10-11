/*Leetcode ps- 2778. Sum of Squares of Special Elements 
You are given a 1-indexed integer array nums of length n.
An element nums[i] of nums is called special if i divides n, i.e. n % i == 0.
Return the sum of the squares of all special elements of nums.*/



/* Approach - Divisible Index Square Accumulation / Factorial Index Filtering (Time: O(N), Space: O(1))
 * Basically, we completely annihilate complex multi-pass divisor searches by aggressively filtering array elements whose 1-based index evenly divides the total array length, accumulating their squared values in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Divisible Index Factor Invariant (LeetCode 2778 - Sum of Squares of Special Elements)! An element at 0-based index `i` is designated as "special" if its 1-based position (`i + 1`) is a direct factor of the total array size `n` (`n % (i + 1) == 0`). By scanning the array once and checking this modulo condition, we capture all valid special indices instantly.
 * - (Type Safety & Return Casting): While the internal `sum` accumulator is maintained as a `long long` to prevent potential integer overflow during squaring operations, the function returns an `int` to match LeetCode's expected method signature.
 * - (Zero Auxiliary Space Footprint): The traversal requires no auxiliary data structures, running in absolute $O(1)$ auxiliary space.
 * * How it runs:
 * First, we safely intercept array size `n` and initialize our running `sum` accumulator.
 * We ignite a high-speed linear sweep from index `0` to `n - 1`.
 * At each position, we check whether `n` is divisible by the 1-based index `i + 1`. If it is, we square `nums[i]` and add it to our running `sum`.
 * Finally, we flush the accumulated sum to the output stream with absolute mathematical precision at raw silicon speed!
 */



class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        long long sum =0;
        int n =nums.size();
        for(int i =0;i<n;i++){
            if(n%(i+1) == 0){
                sum += nums[i]*nums[i];
            }
        }
        return sum;
    }
};
