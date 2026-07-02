/*Leetcode ps - 704. Binary Search
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
You must write an algorithm with O(log n) runtime complexity*/


/* Approach - Standard Binary Search
 * Basically, we efficiently find a target number in a sorted array by repeatedly dividing the search interval in half. Instead of checking every single element, we use the sorted nature of the array to instantly eliminate half of the remaining possibilities at each step.
 * We keep 3 main variables to track our search window:
 * - 'low' points to the start of our current search range.
 * - 'high' points to the end of our current search range.
 * - 'mid' is dynamically calculated as the exact middle index between 'low' and 'high'.
 *
 * How it runs:
 * First, we initialize 'low' to the very beginning of the array (index 0) and 'high' to the very end (nums.size() - 1).
 * Then, we enter a loop that continues as long as 'low' is less than or equal to 'high' (meaning we still have a valid window to search).
 * At each step, we calculate the 'mid' index. If the number at 'mid' is exactly our 'target', we've found it and instantly return the 'mid' index!
 * If the number at 'mid' is strictly less than our target, we know the target must be somewhere to the right. Therefore, we eliminate the entire left half by sliding our 'low' pointer up to 'mid + 1'.
 * If the number at 'mid' is strictly greater than our target (the 'else' condition), the target must be to the left. We eliminate the right half by pulling our 'high' pointer down to 'mid - 1'.
 * Finally, if the loop finishes completely and we never returned a match, it means the target simply doesn't exist in the array, so we return -1!
 */


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0,high=nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target) return mid;
            
            if(nums[mid] < target) low=mid+1;
            else high = mid-1;
        }
        return -1;
    }
};
