/*Leetcode ps :- 3315  Construct the Minimum Bitwise Array II*/
/*You are given an array nums consisting of n prime integers.
You need to construct an array ans of length n, such that, for each index i, the bitwise OR of ans[i] and ans[i] + 1 is 
equal to nums[i], i.e. ans[i] OR (ans[i] + 1) == nums[i].
Additionally, you must minimize each value of ans[i] in the resulting array.
If it is not possible to find such a value for ans[i] that satisfies the condition, then set ans[i] = -1.*/

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> result;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 2){
                result.push_back(-1);
                continue;
            }
            bool found = false;
            for(int j = 1 ; j < 32 ; j++){
                if((nums[i] & (1 << j)) > 0){ //jth bit is set
                    continue;
                }
                int prev = (j-1);
                int x = (nums[i] ^ (1 << (j-1))) ;
                result.push_back(x);
                found = true ;
                break ;
            }
            if(found == false ){
                result.push_back(-1);
            }
        }
        return result;
    }
};
