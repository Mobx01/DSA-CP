/*Leetcode ps- 2540. Minimum Common Value
Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.
Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.*/

/*
Approach: Two-Pointer Technique

1. Initialize Pointers: 
   Create two variables, `i` and `j`, both set to 0. Think of them as fingers pointing to 
   the very first elements of `nums1` and `nums2`.
   
2. Traverse the Arrays:
   Set up a `while` loop that keeps running as long as neither pointer has fallen off the 
   end of its respective array.
   
3. Compare the Elements:
   At each step, look at the numbers your pointers are currently pointing to:
   - If `nums1[i] == nums2[j]`: We found a match! Because we started from the beginning of 
     sorted arrays, this very first match is guaranteed to be the *minimum* common value. 
     We can return it immediately and stop searching.
     
   - If `nums1[i] < nums2[j]`: The number in `nums1` is smaller. Because `nums2` is sorted, 
     every number further down in `nums2` will only be bigger. Therefore, `nums1[i]` has no 
     chance of finding a match. We need a bigger number from `nums1`, so we move pointer `i` 
     forward by 1 (`i++`).
     
   - If `nums1[i] > nums2[j]`: For the exact same reason, the number in `nums2` is too small. 
     We move pointer `j` forward by 1 (`j++`) to check the next bigger number in `nums2`.
     
4. Handle No Matches:
   If the `while` loop finishes entirely, it means we scanned through the arrays and never 
   hit the `==` condition. We simply return `-1` to indicate no common value exists.

Complexity:
- Time Complexity: O(N + M) where N and M are the sizes of the arrays. In the worst case, 
  we look at each element exactly once.
- Space Complexity: O(1) because we only used two extra integer variables (`i` and `j`), 
  regardless of how big the arrays are.
*/

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i =0 , j =0 ;//start 2 pointer one on each of array starting
        while(i != nums1.size() && j != nums2.size()){
            if(nums1[i] == nums2[j]){ 
                return nums1[i];
            }
            else if(nums1[i]<nums2[j]) i++;
            else j++;
        }
        return -1;//if no common find
    }
};
