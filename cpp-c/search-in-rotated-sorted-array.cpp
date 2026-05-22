/*Leetcode ps - 33. Search in Rotated Sorted Array
There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.*/


/*
======================================================
YOUR APPROACH:FIND PIVOT + SEARCH
======================================================

HOW THE LOGIC WORKS:
A rotated sorted array is basically two normal sorted arrays glued together.
For example: [4, 5, 6, 7, 0, 1, 2]
- Left sorted part: [4, 5, 6, 7]
- Right sorted part: [0, 1, 2]

STEP 1: FIND THE "SHIFT VALUE" (THE MINIMUM ELEMENT)
First, you want to find the exact index where the array drops from the 
highest number to the lowest number (the '0' in our example).
- You use a modified binary search (your `find_min` function) to do this.
- You look at the middle number. If it is GREATER than the very last number, 
  that means the drop happens somewhere to its right.
- If it's LESS than the last number, the drop is at the middle or to its left.
- Once the loop finishes, you have the index of the smallest number. This 
  index is your 'shift_val'.

STEP 2: CHOOSE WHICH HALF TO SEARCH
Now that you have the 'shift_val', you know exactly where the two perfectly 
sorted parts are:
- Left part: index 0 up to (shift_val - 1)
- Right part: index 'shift_val' up to the end of the array

Now you just check where your 'target' fits:
- Is the target between the smallest number (nums[shift_val]) and the 
  very last number? If YES, you only care about the RIGHT part.
- If NO, then the target must be in the LEFT part.

STEP 3: NORMAL BINARY SEARCH
Because you narrowed it down to just one part, and that part is perfectly 
sorted without any rotations, you can just use a standard, plain old 
binary search (your `binary_search` function) to find the target!
*/


class Solution {
public:
    int binary_search(vector<int>& nums, int l, int r, int target) {
        while(l<=r) {
            int mid = l + (r-l)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target)
                l = mid+1;
            else
                r = mid-1;
        }
        
        return -1;
    }

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
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int shift_val = find_min(nums,0,n-1);

        if(nums[shift_val] == target) return shift_val;

        int ind = -1;
        ind = binary_search(nums,0,shift_val - 1,target);
        if(ind != -1) return ind;
        ind = binary_search(nums,shift_val + 1,n-1,target);
        return ind;

    }
};
