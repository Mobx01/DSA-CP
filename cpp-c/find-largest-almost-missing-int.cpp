/*Leetcode ps:- 3471. Find the Largest Almost Missing Integer
You are given an integer array nums and an integer k.
An integer x is almost missing from nums if x appears in exactly one subarray of size k within nums.
Return the largest almost missing integer from nums. If no such integer exists, return -1.
A subarray is a contiguous sequence of elements within an array.*/

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int ret = -1;
        if(k == n) {
            for(int i =0 ;i<n;i++){
                ret = max(ret,nums[i]);
            }
            return ret;
        }
        unordered_map<int,int> freq;
        for(int i = 0 ; i <= n -k ; i++){
            for(int j =i ; j< k+i ;j++){
                freq[nums[j]]++;
            }
        }
        for(auto it = freq.begin();it != freq.end();it++){
            if(it->second == 1) ret = max(ret,it->first);
        }
        return ret;
    }
};
