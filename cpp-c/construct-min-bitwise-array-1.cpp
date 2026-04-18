/*Leetcode PS :- 3314 construct the minimum bitwise array 1
You are given an array nums consisting of n prime integers.
You need to construct an array ans of length n, such that, for each index i, the bitwise OR of ans[i] and ans[i] + 1 is equal to nums[i], i.e. ans[i] OR (ans[i] + 1) == nums[i].
Additionally, you must minimize each value of ans[i] in the resulting array.
If it is not possible to find such a value for ans[i] that satisfies the condition, then set ans[i] = -1.
*/



class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        for(int i = 0 ; i < nums.size() ; i++){
            ans[i] = -1;
            for(int j = 0 ; j < 1000 ; j++){
                int posb = j | (j+1) ;
                if( posb  == nums[i]){
                    ans[i] = j ;
                    break ;
                }
            }
        }
        return ans;
    }
};
