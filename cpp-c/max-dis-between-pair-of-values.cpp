/*Leetcode ps- 1855. Maximum Distance Between a Pair of Values
You are given two non-increasing 0-indexed integer arrays nums1​​​​​​ and nums2​​​​​​.
A pair of indices (i, j), where 0 <= i < nums1.length and 0 <= j < nums2.length, is valid if both i <= j and nums1[i] <= nums2[j]. The distance of the pair is j - i​​​​.
Return the maximum distance of any valid pair (i, j). If there are no valid pairs, return 0.
An array arr is non-increasing if arr[i-1] >= arr[i] for every 1 <= i < arr.length.*/

/*
Approach: Two Pointer (Greedy)

- Given two non-increasing arrays nums1 and nums2
- We need to find max (j - i) such that:
    i <= j AND nums1[i] <= nums2[j]
- Arrays are sorted in non-increasing order → helps greedy movement

Steps:
i = 0 (for nums1) ->  both are pointer for both of given array
j = 0 (for nums2)   _|

    while (i < n && j < m):

        Case 1: nums1[i] <= nums2[j]
            -> Valid pair
            -> Update max distance: maxdis = max(maxdis, j - i)
            -> Move j forward to try increasing distance

        Case 2: nums1[i] > nums2[j]
            -> Invalid pair
            -> Move i forward to find a smaller value in nums1
 Return maxdis

- No need to check i <= j explicitly:
    If i > j, (j - i) becomes negative and is ignored

Time Complexity: O(n + m)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i =0 , j=0,n=nums1.size(),m =nums2.size();
        int maxdis = 0;

        while(i < n && j < m){
               if(nums1[i] <= nums2[j]){
                 maxdis=max(maxdis,j-i);
                 j++; //check next element in nums2
                 
               }
               else{
                i++; //next elment i+1 is smaller than i
               }
            
        }
        return maxdis;
    }
};
