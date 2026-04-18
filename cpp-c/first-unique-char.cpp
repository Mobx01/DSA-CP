/*Leetcode ps:- 387 First unique character in a string
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
*/
// Intuition:
// To do this efficiently, we first count how many times each character occurs.
// Then, we scan the string again in its original order to find the first
// character whose frequency is exactly 1.

// Approach:
// 1. Use an unordered_map to store the frequency of each character in the string.
// 2. Traverse the string once and update the frequency map.
// 3. Traverse the string again from left to right.
// 4. For each character, check if its frequency is 1.
//    - If yes, return its index in the string.
// 5. If no such character exists, return -1.

// Time Complexity: O(n)
// Space Complexity: O(1) since the map stores at most 26 characters (lowercase letters)

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char , int> freq;

        // Count frequency of each character
        for(char c : s)
            freq[c]++;

        // Find the first character with frequency 1
        for(char c : s){
            if(freq[c] == 1)
                return s.find(c);
        }

        // If no unique character exists
        return -1;
    }
};
