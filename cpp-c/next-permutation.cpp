/*Leetcode ps- 31. Next Permutation
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).
For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory*/


/* Approach - Lexicographical Next Permutation 
 * Basically, we find the next lexicographically greater sequence by identifying the rightmost "dip" in the array, swapping it with the next slightly larger number to its right, and then minimizing the remaining suffix.
 * We keep 2 main variables to track our pivot points: 
 * - 'indx_chng' tracks the index of the first element from the right that breaks the descending order (the "dip").
 * - 'swap_ind' tracks the index of the number in the right-side suffix that is just barely larger than the number at 'indx_chng'.
 *
 * How it runs:
 * First, we scan the array from right to left to find 'indx_chng'. If the entire array is in strictly descending order (meaning it's the highest possible permutation), 'indx_chng' stays -1.
 * Then, if we found a valid 'indx_chng', we scan from right to left one more time to find 'swap_ind', which is the first number strictly greater than the number at 'indx_chng'. We swap the elements at these two indices.
 * Finally, we reverse the entire suffix of the array starting immediately after 'indx_chng'. Because the suffix was in descending order, reversing it perfectly sorts it into ascending order, giving us the smallest possible arrangement for the remaining digits!
 */


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int indx_chng = -1;
        
        //Find the first decreasing element from the right
        for(int i = n - 1; i > 0; i--) {
            if(nums[i] > nums[i-1]) {
                indx_chng = i - 1;
                break;
            }
        }
        
        //If such an element was found, find the next strictly greater element to its right
        if(indx_chng != -1) {
            int swap_ind = indx_chng;
            for(int i = n - 1; i > indx_chng; i--) {
                 if(nums[i] > nums[indx_chng]) {
                    swap_ind = i;
                    break;
                 }
            }
            // Swap them
            swap(nums[indx_chng], nums[swap_ind]);
        }
        
        // Reverse the suffix starting right after indx_chng
        // If indx_chng is -1, this reverses the entire array.
        reverse(nums.begin() + indx_chng + 1, nums.end());
    }
};
