/*Leetcode PS- 26 Remove Duplicates from Sorted Array
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.
Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k.
The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.

Approach:
- Since the array is sorted, all duplicate elements appear consecutively.
- We use the two-pointer technique to remove duplicates in-place.

Steps:
1. Use pointer `i` to track the index of the last unique element.
2. Start pointer `j` from index 1 and iterate through the array.
3. For each element:
   - If nums[j] is different from nums[i], it means we found a new unique element.
   - Increment `i` and copy nums[j] to nums[i].
4. Continue until the end of the array.

Result:
- The first (i + 1) elements of the array will contain all unique values.
- Return (i + 1) as the new length of the array.

Note:
- No extra space is used.
- Elements beyond the returned length are irrelevant.
*/



class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int i = 0; // index of last unique element

        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};
