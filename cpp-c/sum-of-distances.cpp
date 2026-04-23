/*Leetcode ps - 2615. Sum of Distances
You are given a 0-indexed integer array nums. There exists an array arr of length nums.length, where arr[i] is the sum of |i - j| over all j such that nums[j] == nums[i] and j != i. If there is no such j, set arr[i] to be 0.
Return the array arr.*/

class Solution {
public:
    typedef long long ll;

    vector<ll> distance(vector<int>& nums) {
        int n = nums.size();

        vector<ll> arr(n, 0);

        unordered_map<int, ll> indexSum;   //nums[i] -> sum of i's
        unordered_map<int, ll> indexCount; //nums[i] -> frequency

        //Left to Right
        for(int i = 0; i < n; i++) {
            ll freq = indexCount[nums[i]];
            ll sum  = indexSum[nums[i]];

            arr[i] += freq*i - sum;

            indexCount[nums[i]] += 1;
            indexSum[nums[i]]   += i;
        }

        indexSum.clear();
        indexCount.clear();

        //Right to Left
        for(int i = n-1; i >= 0; i--) {
            ll freq = indexCount[nums[i]];
            ll sum  = indexSum[nums[i]];

            arr[i] += sum - freq*i;

            indexCount[nums[i]] += 1;
            indexSum[nums[i]]   += i;
        }

        return arr;
    }
};
