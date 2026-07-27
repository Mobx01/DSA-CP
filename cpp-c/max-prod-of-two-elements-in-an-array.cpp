/*Leetcode ps-1464. Maximum Product of Two Elements in an Array
Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).
 */


/* Approach - Sorting / Greedy (Time: O(N log N), Space: O(log N))
 * Basically, we sort the entire array to effortlessly push the largest numbers to the very end, allowing us to instantly grab the top two elements and calculate their maximum product!
 * * Observation: 
 * - Since we are dealing with positive integers, the absolute maximum product of any two elements will mathematically always come from the two strictly largest elements available in the array.
 * - Sorting the array in ascending order flawlessly guarantees that these two largest elements will always sit directly at the absolute back of the vector.
 * - (Optimization Note: While sorting works beautifully, it technically takes O(N log N) time! You can brilliantly optimize this down to a lightning-fast O(N) time and strict O(1) space by simply doing a single linear sweep to manually track just the largest and second largest elements without physically rearranging the array at all!)
 * - (Bug : The code completely assumes the array has at least 2 elements! If `nums` is ever smaller than that, accessing `nums.size() - 2` will cause a catastrophic out-of-bounds memory crash!)
 * * How it runs:
 * First, we trigger C++'s highly optimized built-in `sort()` function to sweep through and perfectly order the entire `nums` vector from smallest to largest.
 * Then, we blindly reach into the absolute back of the array to extract the maximum element (at index `nums.size() - 1`) and the second maximum element (at index `nums.size() - 2`).
 * Finally, we mathematically subtract 1 from both of them exactly as the problem dictates, instantly multiply those two reduced values together, and confidently return our absolute maximum product!
 */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return (nums[nums.size()-1] - 1)*(nums[nums.size()-2] - 1);
    }
};

