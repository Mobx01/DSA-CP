/*Leetcode ps- 75. Sort Colors
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.*/


/* Approch - Dutch National Flag Algorithm
 * Basically just throwing the 0s to the front and the 2s to the back.
 * We keep 3 pointers: 
 * - 'low' tracks where the next 0 should go.
 * - 'high' tracks where the next 2 should go.
 * - 'mid' is our current explorer moving through the array.
 *
 * How it runs:
 * If mid sees a 0 -> swap it with low, move both up.
 * If mid sees a 1 -> leave it alone, just move mid up.
 * If mid sees a 2 -> swap it with high, bring high down. (Important: don't 
 * move mid yet, we gotta check what we just swapped over from the high side!)
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        //low->0,mid->1,high->2
        int low = 0 , mid = 0 , high = nums.size()-1;
        while(mid <= high){
            if(nums[mid] == 0){//send it back ot low 
               swap(nums[low],nums[mid]);
               low++;
               mid++;
            }else if(nums[mid] == 1){// skip (no swapping)
               mid++;
            }else{// send 2 to the back
               swap(nums[mid],nums[high]);
               high--;
            }
        } 
    }
};
