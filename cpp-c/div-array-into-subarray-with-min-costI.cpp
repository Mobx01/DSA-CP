/*Leetcode PS - 3010. Divide an Array Into Subarrays With Minimum Cost I
You are given an array of integers nums of length n.
The cost of an array is the value of its first element. For example, the cost of [1,2,3] is 1 while the cost of [3,4,1] is 3.
You need to divide nums into 3 disjoint contiguous subarrays.
Return the minimum possible sum of the cost of these subarrays.*/

/*Its is not the opttimal solution . its has a very bad time complexity of O(n^2).Will try to go for better solutions .*/
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        if(nums.empty()) return 0 ;
        int res=  nums[0]+nums[1]+nums[2] ; 
        for(int i = 1 ; i < nums.size()-1 ;i++){
            for(int j = i+1 ; j<nums.size() ; j++){
                res = min(res , nums[0]+nums[i]+nums[j]);
            }
        }
        return res ;
        
    }
};
