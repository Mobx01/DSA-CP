/*Leetcode ps - 2574. Left and Right Sum Differences
You are given a 0-indexed integer array nums of size n.
Define two arrays leftSum and rightSum where:

leftSum[i] is the sum of elements to the left of the index i in the array nums. If there is no such element, leftSum[i] = 0.
rightSum[i] is the sum of elements to the right of the index i in the array nums. If there is no such element, rightSum[i] = 0.
Return an integer array answer of size n where answer[i] = |leftSum[i] - rightSum[i]|*/

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n,0);
        vector<int> post(n,0);
        for(int i = 1; i< n;i++){
            pref[i] = pref[i-1]+nums[i-1];
        }
        for(int i = n-2; i>=0; i--){
            post[i] = post[i+1] + nums[i+1];
        }
        vector<int> res(n);
        for(int i=0;i<n;i++){
            res[i] = abs(pref[i]-post[i]);
        }
        return res;
    }
};
