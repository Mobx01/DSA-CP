/*Leetcode ps- 81. Search in Rotated Sorted Array II
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).
Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].
Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.
You must decrease the overall operation steps as much as possible.*/


/* Approach - Modified Binary Search (Rotated Array with Duplicates) 
 * Basically, we use binary search to find the target, but we add a special condition to handle duplicates that can temporarily blind our ability to figure out which half of the array is properly sorted.
 * Observation: 
 * - In any standard rotated sorted array, splitting it at the middle guarantees that at least one half is perfectly sorted. We can use that sorted half to easily check if our target belongs inside it.
 * - The edge case: If the numbers at our left boundary, right boundary, and middle are all exactly the same, we have no idea which side is properly sorted and which side contains the rotation pivot! The only safe move is to incrementally shrink our boundaries inward (l++ and r--) until the duplicates clear up.
 *
 * How it runs:
 * First, we initialize our 'l' and 'r' pointers to the absolute ends of the array and enter our standard binary search loop.
 * At each step, we calculate 'mid'. If the number at 'mid' perfectly matches our target, we found it and return true!
 * Next, we check for our duplicate trap. If nums[l], nums[mid], and nums[r] are all identical, we safely shrink our window by stepping 'l' forward and 'r' backward, skipping the rest of the checks for this specific iteration.
 * If we aren't trapped, we figure out which half is sorted. If nums[l] <= nums[mid], the left half is perfectly sorted! We then check if our target mathematically falls within this clean left half. If it does, we narrow our search to the left (r = mid - 1). If not, we know for a fact it must be on the right (l = mid + 1).
 * Conversely, if the left half isn't sorted, the right half MUST be. We perform the exact same logical check for the right side: if the target falls within the clean right half, we search right; otherwise, we search left.
 * Finally, if the loop completely exhausts and we never hit a match, we return false!
 */

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        
        while(l <= r)
        {
            int mid = l + (r-l) / 2;
            if (nums[mid] == target)
                return true;
			// with duplicates we can have this contdition, just update left & right
            if((nums[l] == nums[mid]) && (nums[r] == nums[mid]))
            {
                l++;
                r--;
            }
			// first half
			// first half is in order
            else if(nums[l] <= nums[mid])
            {
				// target is in first  half
                if((nums[l] <= target) && (nums[mid] > target))
                    r = mid - 1;
                else
                    l = mid + 1;
            }
			// second half
			// second half is order
			// target is in second half
            else
            {
                if((nums[mid] < target) && (nums[r]>= target))
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return false;
    }
};
