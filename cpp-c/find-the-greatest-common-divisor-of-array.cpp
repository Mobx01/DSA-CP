/*Leetcode ps-1979. Find Greatest Common Divisor of Array
Given an integer array nums, return the greatest common divisor of the smallest number and largest number in nums.
The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.*/

/* Approach - Single Pass Min/Max & Math (Time: O(N), Space: O(1))
 * Basically, we find the absolute smallest and largest elements in the array in a single sweep and directly compute their Greatest Common Divisor!
 * * Observation: 
 * - Sorting the entire array just to find the smallest and largest elements would cost O(N log N) time, which is doing unnecessary extra work. We can easily grab both extremes simultaneously in a single O(N) linear pass.
 * - Initializing 'sm' to 1001 works perfectly because typical problem constraints state that array values will not exceed 1000. This guarantees 'sm' will be successfully overwritten on the very first iteration!
 * * How it runs:
 * First, we initialize our smallest tracker 'sm' to a safe upper bound (1001) and our highest tracker 'he' to a safe lower bound (0).
 * Then, we use a range-based for loop to sweep through every single number in 'nums'. At each step, we update 'sm' using the min() function and 'he' using the max() function to lock in our extremes.
 * Finally, once the loop completely finishes, we simply pass our two targeted values into C++'s built-in 'gcd()' function and return the final mathematical result!
 */

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int sm=1001,he = 0;
        for(int i : nums){
            sm = min(sm,i);
            he = max(he,i);
        }
        return gcd(sm,he);
    }
};
