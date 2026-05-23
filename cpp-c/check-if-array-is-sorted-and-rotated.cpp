/*Leetcode ps - 1752. Check if Array Is Sorted and Rotated
Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.
There may be duplicates in the original array.
Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.*/


/*
APPROACH: 
If a sorted array is rotated, it will have AT MOST ONE "drop" 
(where a number is bigger than the next one).

1. Loop through the array.
2. Compare the current number to the next number.
3. Use (i + 1) % n to connect the last number back to the first.
4. If you see a drop, count it.
5. If you count more than 1 drop, it's not sorted/rotated. Return false.
*/



class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int drops=0;
        for(int i = 0 ;i<n;i++){
            if(nums[i]>nums[(i+1)%n]){
                drops++;
            }
            if(drops>1) return false;
            
        }
        return true;;
    }
};
