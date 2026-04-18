/*Leetcode ps- 3653. XOR After Range Multiplication Queries I
You are given an integer array nums of length n and a 2D integer array queries of size q, where queries[i] = [li, ri, ki, vi].

For each query, you must apply the following operations in order:

Set idx = li.
While idx <= ri:
Update: nums[idx] = (nums[idx] * vi) % (109 + 7)
Set idx += ki.
Return the bitwise XOR of all elements in nums after processing all queries*/

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        int idx;
        for(int i = 0;i<n;i++){
            int li = queries[i][0];
            int ri = queries[i][1];
            int ki = queries[i][2];
            int vi = queries[i][3];

            int idx = li;
            while(idx <= ri){
                nums[idx] = (1LL * nums[idx] * vi) % 1000000007;
                idx += ki;
            }
        }

        int ret = 0;
        for(int i : nums){
            ret = ret^i;
        }
        return ret;
    }
};
