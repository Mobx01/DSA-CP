/*Leetcode ps - 18. 4Sum
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.*/




// Approach:
// 1. Sort the array so that we can use two pointer technique easily.
// 2. Fix the first element using loop 'i'.
// 3. Fix the second element using loop 'j'.
// 4. Use two pointers:
//      left  -> starts from j+1
//      right -> starts from end of array
// 5. Calculate sum of four elements:
//      nums[i] + nums[j] + nums[left] + nums[right]
// 6. If sum is greater than target:
//      move right pointer backward.
// 7. If sum is smaller than target:
//      move left pointer forward.
// 8. If sum becomes equal to target:
//      store the quadruplet in result.
//      then move both pointers and skip duplicate values.
// 9. Also skip duplicate values for i and j
//    to avoid repeated quadruplets.
// 10. Finally return the result vector.

// Time Complexity: O(n^3)
// Space Complexity: O(1) (excluding answer vector)




class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        int n = nums.size();

        for (int i = 0; i < n - 3; i++) {

            // Skip duplicate 
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n - 2; j++) {

                // Skip duplicate 
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {

                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum > target) {
                        right--;
                    }
                    else if (sum < target) {
                        left++;
                    }
                    else {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});

                        left++;
                        right--;

                        // Skip duplicates for left
                        while (left < right && nums[left] == nums[left - 1])
                            left++;

                        // Skip duplicates for right
                        while (left < right && nums[right] == nums[right + 1])
                            right--;
                    }
                }
            }
        }

        return res;
    }
};
