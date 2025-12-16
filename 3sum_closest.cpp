//Leetcode ps-16 
//Given an integer array nums of length n and an integer target,
//find three integers in nums such that the sum is closest to target.
//Return the sum of the three integers.
//You may assume that each input would have exactly one solution.


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int closest = nums[0]+nums[1]+nums[2];
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < n ; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int j = i+1 ;
            int k = n-1 ;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum==target) { closest = sum ;
                return closest ;}

                    if(abs(sum - target) < abs(closest - target)  ) closest = sum ;
                    
                    if (sum == target)
                    return target;
                else if (sum < target)
                    j++;
                else
                    k--;
                
            }
        }   
        return closest;     
    }
};
