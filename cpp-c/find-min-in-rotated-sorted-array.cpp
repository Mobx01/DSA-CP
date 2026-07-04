/*Leetcode ps- 153. Find Minimum in Rotated Sorted Array
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
Given the sorted rotated array nums of unique elements, return the minimum element of this array.
You must write an algorithm that runs in O(log n) time.*/

/* Approach - Binary Search
 * Basically, we use a modified binary search to efficiently locate the pivot point (the minimum element) in a rotated sorted array by constantly comparing our middle element to our right boundary.
 * Observation:
 * - In a rotated sorted array, if the middle element is strictly greater than the rightmost element, the sequence must have "snapped" (rotated) somewhere to the right of the middle.
 * - If the middle element is less than or equal to the rightmost element, the entire right side is perfectly sorted in ascending order, meaning the absolute lowest point must be exactly at the middle or somewhere to its left.
 *
 * How it runs:
 * First, we initialize our 'l' (left) and 'r' (right) pointers to the absolute ends of the array and enter a loop that runs as long as 'l' is strictly less than 'r'.
 * At each step, we calculate the 'mid' index. We then compare the value at 'nums[mid]' with the value at 'nums[r]'.
 * If 'nums[mid]' > 'nums[r]', the minimum element is definitely in the right half, so we confidently push our left boundary up to 'mid + 1'.
 * Otherwise, the minimum element is either at 'mid' itself or in the left half, so we pull our right boundary down to 'mid'. (We don't do 'mid - 1' because 'mid' might actually be our minimum!).
 * Finally, when the loop breaks, 'l' and 'r' will perfectly converge on the exact index of the minimum element. We simply return the array value sitting at that index!
 */

class Solution {
public:
    int find_min(vector<int>& nums, int l, int r) {
        while(l<r) {
            int mid = l + (r-l)/2;
            if(nums[mid] > nums[r])
                l = mid+1;
            else
                r = mid;
        }
        
        return r;
    }
    int findMin(vector<int>& nums) {
        int n = nums.size();
        return nums[find_min(nums,0,n-1)];
    }
};

