/*Leetcode ps- 162. Find Peak Element
A peak element is an element that is strictly greater than its neighbors.
Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
You must write an algorithm that runs in O(log n) time.*/

/* Approach - Binary Search on Slopes 
 * Basically, we use binary search to efficiently climb the "hill" of numbers. By comparing a middle element to its right neighbor, we can figure out the slope of the array and always move towards a peak in O(log N) time!
 * Observation: 
 * - The array is a landscape of rising and falling slopes. If we pick any random point, we can just look at the next step to decide which way is "up".
 * - If 'nums[mid] > nums[mid+1]', we are on a descending slope. This mathematically guarantees that a peak exists somewhere to our left (or the current 'mid' is the peak itself!).
 * - If 'nums[mid] < nums[mid+1]', we are on an ascending slope. This means we are climbing, so a peak is guaranteed to exist somewhere to our right.
 *
 * How it runs:
 * First, we do a quick check: if the array only has 1 element, it is the peak by default, so we return index 0.
 * Then, we initialize our 'i' (left) and 'j' (right) boundaries to the absolute ends of the array and enter a loop that runs until they converge (i < j).
 * At each step, we calculate our 'mid' index and check the slope.
 * If we are on a descending slope (nums[mid] > nums[mid+1]), we pull our right boundary 'j' down to 'mid'. (We don't do 'mid - 1' because 'mid' itself could be the peak we are looking for!).
 * If we are on an ascending slope (the 'else' case), we know for a fact that 'mid' is not a peak because its right neighbor is taller. So, we confidently push our left boundary 'i' up to 'mid + 1'.
 * Finally, when the loop breaks, our pointers will have perfectly converged on the exact index of a peak element. We simply return 'i'!
 */

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i = 0 , j = nums.size()-1,mid;
        if(nums.size() == 1) return 0;
        while(i < j){
            mid = i + (j-i)/2;
            
            if(nums[mid] > nums[mid+1]){
                // we are on descending slope of hill and peak is at left
                j = mid;
            }else{
                 // we are on ascending slope of hill and peak is at right
                i = mid+1;
            }
        }
        return i;
    }
};
