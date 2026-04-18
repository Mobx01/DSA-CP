/*Leetcode ps:- 2540. Minimum Common Value
Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays.
If there is no common integer amongst nums1 and nums2, return -1.
Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.*/

/**
 * Approach: Two-Pointer Greedy Search
 * ----------------------------------
 * 1. Pointers: Initialize i and j to 0 for nums1 and nums2.
 * 2. Greedy Scan: Since arrays are sorted, the first match we encounter 
 * MUST be the minimum common value.
 * 3. Logic:
 * - nums1[i] == nums2[j]: Smallest common found. Return immediately.
 * - nums1[i] < nums2[j]: Increment i to reach a value that could potentially match.
 * - nums1[i] > nums2[j]: Increment j for the same reason.
 * 4. Return: If the loop finishes without a match, return -1.
 * * Complexity: Time O(n + m) | Space O(1)
 */

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i =0 , j =0 ;
        int mincommon = -1;
        while(i != nums1.size() && j != nums2.size()){
            if(nums1[i] == nums2[j]){ 
                mincommon = nums1[i];
                break;
            }
            else if(nums1[i]<nums2[j]) i++;
            else j++;
        }
        return mincommon;
    }
};
