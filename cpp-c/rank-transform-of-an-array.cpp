/*Leetcode ps-1331. Rank Transform of an Array
Given an array of integers arr, replace each element with its rank.
The rank represents how large the element is. The rank has the following rules:
Rank is an integer starting from 1.
The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
Rank should be as small as possible.*/

/* Approach - Sorting & Index Mapping (Time: O(N log N), Space: O(N))
 * Basically, we determine the relative rank of each element by sorting them while holding onto their original positions, ensuring identical numbers receive the exact same rank!
 * * Observation: 
 * - To find an element's rank, we must know its sorted order among all unique elements.
 * - However, we need to return the ranks in the exact same order as the original array. If we just sort the raw array, we completely lose track of where each number came from! Pairing each value with its original index `(value, original_index)` before sorting solves this perfectly.
 * - Because ties must share the exact same rank, we only increment our rank counter when we step up to a strictly larger value.
 * * How it runs:
 * First, we handle the empty array edge case. Then, we construct a vector of pairs, binding every array element to its original index, and sort it. (C++ pairs automatically sort by the first element, which is our value).
 * Then, we initialize our `res` array and safely assign the absolute smallest element (at index 0 of our sorted pairs) a starting rank of 1.
 * Finally, we sweep through the rest of the sorted pairs. If the current value is strictly greater than the previous one, we increment our running `rank` counter. We then slot this rank into the exact correct position in our `res` array by reading the saved `original_index` (`valIdx[i].second`).
 */


class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {}; 

        //Store elements with their original indices
        vector<pair<int, int>> valIdx(n);
        for (int i = 0; i < n; i++) {
            valIdx[i] = {arr[i], i};
        }

        //sort(sorts by the first element)
        sort(valIdx.begin(), valIdx.end());

        //assign ranks using the sorted array
        vector<int> res(n);
        int rank = 1;
        
        // smallest->1
        res[valIdx[0].second] = rank; 

        for (int i = 1; i < n; i++) {
            // If current value is greater than the previous, rank++
            if (valIdx[i].first > valIdx[i - 1].first) {
                rank++;
            }
            res[valIdx[i].second] = rank;
        }

        return res;
    }
};
