/*Leetcode ps:- 229. Majority Element II
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        unordered_map<int , int> freq;
        for(int i : nums) freq[i]++;
        for(auto it = freq.begin(); it != freq.end() ; it++){
            if(it -> second > n/3) res.push_back(it->first);
        }
        return res;
    }
};
