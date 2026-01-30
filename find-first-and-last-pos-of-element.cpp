/*Leetcode PS- 34. Find First and Last Position of Element in Sorted Array
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.


APPROACH:

1. Since the array is sorted, we can use Binary Search to find
   the first and last occurrence of the target efficiently.
2. We perform two separate binary searches:
   - findFirst(): to find the leftmost (first) index of the target
   - findLast():  to find the rightmost (last) index of the target
3. In findFirst():
   - When nums[mid] == target, we store mid as a possible answer.
   - We continue searching on the left side (high = mid - 1)
     to ensure we get the earliest occurrence.
4. In findLast():
   - When nums[mid] == target, we store mid as a possible answer.
   - We continue searching on the right side (low = mid + 1)
     to ensure we get the last occurrence.
5. If the target is not present, both functions return -1.
6. The final answer is a vector containing:
   { first occurrence index, last occurrence index }
Time Complexity:
- O(log n) because binary search is used twice.
Space Complexity:
- O(1) as only constant extra space is used.
*/



class Solution {
public:
    int findFirst(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                ans = mid;
                high = mid - 1;   
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    int findLast(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                ans = mid;
                low = mid + 1;   
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        return { findFirst(nums, target), findLast(nums, target) };
    }
};
