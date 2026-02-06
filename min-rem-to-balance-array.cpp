/*Leetcode Ps:-3634. Minimum Removals to Balance Array
You are given an integer array nums and an integer k.
An array is considered balanced if the value of its maximum element is at most k times the minimum element.
You may remove any number of elements from nums​​​​​​​ without making it empty.
Return the minimum number of elements to remove so that the remaining array is balanced.
Note: An array of size 1 is considered balanced as its maximum and minimum are equal, and the condition always holds true.*/

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int i = 0;
        int maxLen = 0;

        for (int j = 0; j < n; j++) {
            while (nums[j] > (long long)k * nums[i]) {
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
        }

        return n - maxLen;
    }
};
