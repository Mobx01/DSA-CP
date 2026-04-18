/*Leetcode PS:- 3719. Longest Balanced Subarray I.
You are given an integer array nums.
A subarray is called balanced if the number of distinct even numbers in the subarray is equal to the number of distinct odd numbers.
Return the length of the longest balanced subarray.*/


class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int len = n;

        while (len > 0) {
            unordered_map<int, int> freq;
            int evenCnt = 0, oddCnt = 0;

            // first window of size len
            for (int i = 0; i < len; i++) {
                if (freq[nums[i]] == 0) {
                    if (nums[i] % 2 == 0) evenCnt++;
                    else oddCnt++;
                }
                freq[nums[i]]++;
            }

            if (evenCnt == oddCnt)
                return len;

            // sliding window
            for (int i = len; i < n; i++) {
                int add = nums[i];
                int rem = nums[i - len];

                // add new element
                if (freq[add] == 0) {
                    if (add % 2 == 0) evenCnt++;
                    else oddCnt++;
                }
                freq[add]++;

                // remove old element
                freq[rem]--;
                if (freq[rem] == 0) {
                    if (rem % 2 == 0) evenCnt--;
                    else oddCnt--;
                }

                if (evenCnt == oddCnt)
                    return len;
            }

            len--;  
        }

        return 0;
    }
};
