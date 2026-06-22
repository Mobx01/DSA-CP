/*Leetcode ps- 189. Rotate Array
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.*/


// approach (not optimal -> take O(n) space complexity.
// 1. We make a temporary array of the same size to hold the result.
// 2. We loop through the original array. For every number at index 'i', 
//    it needs to move 'k' steps to the right.
// 3. Its new spot will be (i + k). But if that goes past the end of 
//    the array, we use modulo 'n' ((i + k) % n) to wrap it back around 
//    to the beginning.
// 4. We place the number into the temporary array at that new spot.
// 5. Finally, we just copy our temporary array back into 'nums'.

// Time: O(n)
// Space: O(n) because we created an extra array.


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n);

        for(int i =0 ; i< n;i++){
            res[(i+k)%n] = nums[i];
        }
        nums = res;
    }
};


// optimal approach

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; 

        //Reverse the whole array
        reverse(nums.begin(), nums.end());

        //Reverse just the first 'k' elements
        reverse(nums.begin(), nums.begin() + k);

        //Reverse the rest of the elements
        reverse(nums.begin() + k, nums.end());
    }
};

