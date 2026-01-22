/*Leetcode ps :- 3507 Minimum Pair Removal to Sort Array I

Given an array nums, you can perform the following operation any number of times:
Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
Replace the pair with their sum.
Return the minimum number of operations needed to make the array non-decreasing.
An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).*/



class Solution {
public:
    bool issorted(const vector<int>& nums){
        for(int k = 0 ; k < nums.size() - 1 ; k++){
            if(nums[k] > nums[k+1]){
                return false; 
            }
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int rem = 0;

        while(!issorted(nums)){
            rem++;
            int minsum = INT_MAX, x = 0;

            for(int i = 0 ; i < nums.size() - 1; i++){
                int sum = nums[i] + nums[i+1];
                if(sum < minsum){
                    minsum = sum;
                    x = i;
                }
            }

            // Merge pair
            nums[x] = minsum;
            nums.erase(nums.begin() + x + 1);
        }
        return rem;
    }
};
