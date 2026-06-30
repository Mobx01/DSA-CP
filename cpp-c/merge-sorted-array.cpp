/*Leetcode ps -88. Merge Sorted Array
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

*/

/* Approach - Two Pointers (Backward Merge) (space complexity O(1))
 * Basically, we merge the two sorted arrays by starting from the largest elements at the back and moving backwards to fill 'nums1'. This clever trick prevents us from accidentally overwriting the existing elements in 'nums1' before we've had a chance to compare them!
 * We keep 3 main variables (pointers) to track our positions:
 * - 'i' points to the last actual valid element in 'nums1'.
 * - 'j' points to the last element in 'nums2'.
 * - 'k' points to the very end of the total available space in 'nums1', which is exactly where the next largest number should go.
 *
 * How it runs:
 * First, we initialize our three pointers 'i', 'j', and 'k' to the extreme ends of their respective sections.
 * Then, we enter a loop that runs as long as we still have elements to look at in both arrays (i >= 0 and j >= 0). We compare the numbers at 'i' and 'j'. Whichever number is strictly larger gets placed exactly at index 'k'. After placing it, we step pointer 'k' backwards, along with whichever pointer ('i' or 'j') provided the winning number.
 * Finally, if we happen to exhaust all valid numbers in 'nums1' but still have some left in 'nums2', we run a small cleanup loop to copy the remaining 'nums2' numbers directly into the front of 'nums1'. (Note: If 'nums1' had leftovers instead, we wouldn't need a loop because they are already sitting right where they belong!)
 */


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;        
        int j = n - 1;        
        int k = m + n - 1;    
    
        
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    
        
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
        }
};
