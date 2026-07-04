/*Leetcode ps- 540. Single Element in a Sorted Array
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
Return the single element that appears only once.
Your solution must run in O(log n) time and O(1) space.*/


/* Approach - Binary Search on Subarray Lengths (space complexity O(1))
 * Basically, we use binary search to locate the single element by analyzing whether the remaining halves of the array contain an even or odd number of elements after we identify a pair.
 * Observation: 
 * - In an array where every element appears exactly twice except for one, any valid subarray that does NOT contain the single element must have an even length (because it consists entirely of pairs).
 * - If we split the array at 'mid' and check which side has an odd number of elements remaining, we are mathematically guaranteed that the single element exists in that odd-lengthed side!
 *
 * How it runs:
 * First, we set our 'l' and 'r' boundaries to the ends of the array and loop until they converge.
 * At each step, we calculate 'mid' and determine if the right half of the array (from 'mid' to 'r') currently has an even number of elements ('isEven').
 * Next, we check if 'nums[mid]' is paired with the number to its right ('nums[mid+1]'). If it is, one element of the pair spills into the right half. If 'isEven' was true, the right half now has an odd number of available spots left, meaning our target is to the right (l = mid + 2). If false, the target is to the left (r = mid - 1).
 * Conversely, we check if 'nums[mid]' is paired with the number to its left ('nums[mid-1]'). If it is, the right half is untouched by the pair. If 'isEven' was true, the right half is perfectly balanced, so the target must be hiding in the left half (r = mid - 2). If false, the target is in the right half (l = mid + 1).
 * If 'nums[mid]' doesn't match either of its neighbors, we've instantly found the single element and return it!
 * Finally, if the loop narrows down to a single element where 'l == r', we just return 'nums[l]'.
 */

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        int mid;
        
        while(l < r) {
            mid = l + (r-l)/2;
            bool isEven = (r-mid)%2==0;
            
            if(nums[mid] == nums[mid+1]) {
                if(isEven) {
                    l = mid+2;
                } else {
                    r = mid-1;
                }
            } else if(nums[mid] == nums[mid-1]) {
                if(isEven) {
                    r = mid-2;
                } else {
                    l = mid+1;
                }
            } else {
                return nums[mid];
            }
        }
        
        return nums[l]; //or, nums[r]
    }
};
