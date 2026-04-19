''' Leetcode ps - 1855. Maximum Distance Between a Pair of Values
You are given two non-increasing 0-indexed integer arrays nums1​​​​​​ and nums2​​​​​​.
A pair of indices (i, j), where 0 <= i < nums1.length and 0 <= j < nums2.length, is valid if both i <= j and nums1[i] <= nums2[j]. The distance of the pair is j - i​​​​.
Return the maximum distance of any valid pair (i, j). If there are no valid pairs, return 0.
An array arr is non-increasing if arr[i-1] >= arr[i] for every 1 <= i < arr.length. '''

class Solution:
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        i =0
        j=0
        n = len(nums1)
        m = len(nums2)
        maxdis = 0
        
        while(i < n and j < m):
            if(nums1[i] <= nums2[j]):
                maxdis = max(maxdis,j-i)
                j+=1
            else :
                i += 1

        return maxdis    
