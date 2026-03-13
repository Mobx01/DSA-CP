/*Leetcode ps:- 347. Top K Frequent Elements
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.*/
/**
 * Approach: Frequency Mapping and Custom Sorting
 * --------------------------------------------
 * 1. Count Frequencies: Use a map to store the count of each number in the input.
 * - Key: The element from 'nums'
 * - Value: Its frequency (how many times it appears)
 * * 2. Vector Conversion: Transfer the map's key-value pairs into a vector of pairs.
 * - This is necessary because standard maps are sorted by 'Key', but we 
 * need to sort by 'Value' (frequency).
 * * 3. Custom Sort: Sort the vector in descending order based on the frequency 
 * (the second element of the pair).
 * * 4. Extract Top K: Iterate through the first 'k' elements of the sorted vector 
 * and collect the original numbers (the first element of the pair) into the result.
 * * Time Complexity: O(N log N) - Primarily due to the sorting of the frequency vector.
 * Space Complexity: O(N) - To store frequencies in the map and the vector.
 */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> freq;
        int n = nums.size();
        for(int i : nums)freq[i]++;
        vector<pair<int, int>> v(freq.begin(), freq.end());
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
          return a.second > b.second; 
    });
    vector<int> out(k);
    for(int i = 0 ; i < k ;i++){
        out[i] = v[i].first;
    }

        return out;
    }
};
