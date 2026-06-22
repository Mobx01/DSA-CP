/*Leetcode ps- 136. Single Number
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.

 */
// approach - xor
// a^0 = a. , a^a = 0
// so duplicates goes to 0 and unique remains as it is

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xr=0;
        // a^0 = a. , a^a = 0
        // so duplicates goes to 0 and unique remains as it is
        for(int i  : nums){
            xr ^= i;
        }
        return xr;
    }
};
