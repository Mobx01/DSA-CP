/*Leetcode ps- 152. Maximum Product Subarray
Given an integer array nums, find a subarray that has the largest product, and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer.
Note that the product of an array with a single element is the value of that element.*/


/* Approach - Prefix and Suffix Products
 * Basically, we track the running product from both the left side and the right side simultaneously, because the maximum product subarray will always touch either the start or the end of a non-zero segment.
 * We keep 3 main variables to track this:
 * - 'pref' tracks the running product moving from left to right.
 * - 'sufix' tracks the running product moving from right to left.
 * - 'ans' keeps a running tally of the absolute largest product we've seen from either direction.
 *
 * How it runs:
 * First, we start a single loop to sweep through the array, calculating our 'pref' moving forward and our 'sufix' moving backward at the exact same time.
 * At each step, if our 'pref' or 'sufix' is currently 0, we immediately reset it back to 1. A zero completely breaks a contiguous subarray chain, so resetting to 1 effectively starts a brand new subarray calculation from the next number.
 * Then, we multiply our running 'pref' by the current element from the front, and our 'sufix' by the current element from the back. (This neat trick handles negative numbers perfectly: if there is an odd number of negatives, one directional sweep will naturally drop the worst negative and yield the maximum product!).
 * Finally, we update 'ans' with the maximum value between our current 'ans', 'pref', and 'sufix' before moving to the next step!
 */


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pref=1,sufix=1,ans=INT_MIN,n=nums.size();
        for(int i =0 ;i <n;i++){
            if(pref ==0 ) pref=1;
            if(sufix == 0) sufix=1;
            pref = pref*nums[i];
            sufix = sufix*nums[n-i-1];
            ans = max({ans,pref,sufix});
        }
        return ans;
    }
};
