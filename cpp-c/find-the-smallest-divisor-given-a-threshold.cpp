/*Leetcode ps- 1283. Find the Smallest Divisor Given a Threshold
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.
Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).
The test cases are generated so that there will be an answer.*/


/* Approach - Greedy & Math (Minimum Differences) (Time: O(N), Space: O(N))
 * Basically, we find the minimum operations required to make the array "unsorted" by targeting the adjacent pair of elements that are already closest to being out of order, and calculating how many operations it takes to push their difference below zero.
 * * Observation: 
 * - An array is considered "unsorted" the exact moment any adjacent pair satisfies nums[i-1] > nums[i] (meaning their difference is less than 0).
 * - The allowed operation (adding 1 to a prefix and subtracting 1 from the remaining suffix) effectively decreases the difference between the split boundary elements by exactly 2.
 * - To minimize our total operations, we should always target the adjacent pair that has the absolute smallest difference (`mindiff`).
 * - If `mindiff` is already less than 0, the array is already unsorted, so it takes 0 operations! Otherwise, since every operation reduces the gap by 2, it will mathematically take floor(mindiff / 2) + 1 operations to force the difference into the negatives.
 * * How it runs:
 * First, we read the array and loop through it once to find the absolute smallest difference between any two adjacent elements, saving it in `mindiff`.
 * Then, we check our base case: if `mindiff < 0`, the array is already unsorted, so we immediately return 0.
 * Finally, we apply our math: if the difference is even, it takes exactly `mindiff / 2 + 1` operations to cross zero. If it's odd, integer division handles it cleanly as `(mindiff + 1) / 2` operations!
 */

class Solution {
public:
    int rescal(int div,vector<int> nums){
        int sum =0;
        for(int num : nums){
            sum += num%div != 0 ? num/div + 1 : num/div;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = *max_element(nums.begin(),nums.end());
        int ans;

        while(l<=r){
            int mid = l +(r-l)/2;
            int sum = rescal(mid,nums);
            if(sum > threshold){// not a valid divisior need bigger divisior
                l = mid+1;
            }else{// valid divisor check for lesser one
                r = mid- 1;
                ans = mid;
            }
        }
        return ans;
    }
};
