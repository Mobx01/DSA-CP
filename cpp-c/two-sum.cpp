/*Leetcode ps- 1. Two Sum
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.*/

/*
Approach: Single-Pass Hash Map

Instead of using a slow nested loop to check every pair, we can solve this in a single pass using a hash map. 

1. Create a map to store the numbers we've seen so far and their indices.
2. Loop through the array. For each number, calculate its "complement" (which is just: target - current number).
3. Check if this complement is already in our map:
   - If it is: We've found our pair! Return the complement's index and the current index.
   - If it isn't: Add the current number and its index to the map, then keep going.

Time Complexity: O(n) - We only walk through the array once.
Space Complexity: O(n) - In the worst case, we store every number in the map.
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> ind;
        int n = nums.size();

        for(int i = 0 ; i < n ;i++){
            int compliment = target - nums[i];
            if(ind.count(compliment)){
                return {ind[compliment],i};
            }
            ind[nums[i]] = i;
        }
        return {};
    }
};
