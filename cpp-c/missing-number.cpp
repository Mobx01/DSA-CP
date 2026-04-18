/*Leetcode ps*;- 268. Missing Number
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array. */

/*approach:-
sort the vector and find the upper limit of range using vec.back() function (returns lasts element of vector). iterate from o to n(upper limit) 
if any index doesnt matches with its corresponding value return it. o(nlogn)/
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.back();
        for(int i = 0 ; i <n;i++){
            if(nums[i] != i) return i;
        }
        return nums.size();
    }
};

/*optimised approach (sum approach) o(n)*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(); //upperlimit
        int expected =  n*(n+1)/2;
        int actual = 0;
        for(int i: nums) actual += i;
        return expected - actual;
    }
};
