/*Leetcode ps- 1461. Check If a String Contains All Binary Codes of Size K
Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.*/
/**
 * APPROACH: "Discovery-based Sliding Window"
 * * 1. Early Exit: If s is shorter than 2^k + k - 1, it's impossible to 
 * contain all codes. (A De Bruijn sequence is the shortest possible).
 * 2. Sliding Window: Iterate through s using a window of size k.
 * 3. Hash Set: Use an unordered_set to store unique substrings found.
 * 4. Early Stop: If the set size reaches 2^k before the loop ends, 
 * return true immediately (optimization).
 * 5. Result: Return true if set size == 2^k, else false.
 * * COMPLEXITY:
 * - Time: O(N * k) 
 * (N = length of s; we perform N iterations, and s.substr(i, k) 
 * takes O(k) time to copy/hash).
 * - Space: O(2^k * k) 
 * (Storing up to 2^k unique strings, each of length k, in the set).
 */
class Solution {
public:
    bool hasAllCodes(string s, int k) {
    int totalRequired = 1 << k; // 2^k
    if (s.length() < k + totalRequired - 1) return false; // Quick exit

    unordered_set<string> seen;
    for (int i = 0; i <= (int)s.length() - k; ++i) {
        seen.insert(s.substr(i, k));
        if (seen.size() == totalRequired) return true; // Optimization: Stop early
    }
    return false;
}
};
