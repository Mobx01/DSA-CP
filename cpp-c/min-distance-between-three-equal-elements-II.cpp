/*Leetcode ps-3741. Minimum Distance Between Three Equal Elements II
You are given an integer array nums.
A tuple (i, j, k) of 3 distinct indices is good if nums[i] == nums[j] == nums[k].
The distance of a good tuple is abs(i - j) + abs(j - k) + abs(k - i), where abs(x) denotes the absolute value of x.
Return an integer denoting the minimum possible distance of a good tuple. If no good tuples exist, return -1.*/

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int ,int> freq;
        unordered_map<int ,vector<int>> indicies;
        int n = nums.size();

        for(int i : nums){
            freq[i]++;
        }

        for(int i=0;i<n;i++){
            int cur = nums[i];
            if(freq[cur] >= 3){
                indicies[cur].push_back(i);
            }
        }
        int  mindis = INT_MAX;
        for (auto &p : indicies) {
            vector<int> v = p.second;
            int m = v.size();
            for(int i = 0 ; i <m-2;i++){
            int dis = abs(v[i]-v[i+1]) + abs(v[i+1]-v[i+2]) +abs(v[i]-v[i+2]);
            mindis = min(dis ,mindis);
            }
        }

        return mindis == INT_MAX ? -1 : mindis;
    }
};
