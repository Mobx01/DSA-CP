/*Leetcode ps-205. Isomorphic Strings
Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.*/

/* Approach - ASCII Hashing / Index Mapping (Time: O(N), Space: O(1))
 * Basically, instead of explicitly mapping characters to each other, we independently track the last seen position of every character in both strings to ensure their structural patterns match perfectly!
 * * Observation: 
 * - A standard two-way hash map (mapping 's' to 't' and 't' to 's') works, but it takes extra logic to prevent multiple characters from mapping to the same target.
 * - By simply recording the exact index where we last saw each character, we can just compare their history! If `s[i]` and `t[i]` were last seen at different indices, their parallel structure is instantly broken.
 * - Using two arrays of size 256 perfectly covers the entire extended ASCII character set, dropping our space complexity to a strict, guaranteed O(1).
 * - Storing `i + 1` instead of just `i` is a brilliant, absolutely crucial trick! Because the arrays are initialized to 0, if we stored the raw index 0 for the very first characters, the code would be completely unable to distinguish them from characters that haven't been seen yet!
 * * How it runs:
 * First, we extract the string length 'n' and initialize our two mapping arrays, `mp1` and `mp2`, strictly sized to 256 and filled with 0s.
 * Then, we sweep through both strings simultaneously using a single linear loop.
 * Next, at every single step, we instantly check our maps. If the previously recorded position for `s[i]` does not exactly match the recorded position for `t[i]`, the isomorphism is violated, and we immediately return false.
 * Finally, if their histories match, we confidently update both maps with our current 1-based index `i + 1` and continue. If the loop completely finishes without any mismatches, the strings are structurally identical, and we safely return true!
 */

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        vector<int> mp1(256,0),mp2(256,0);
        for(int i =0; i <n;i++){
            if(mp1[s[i]] != mp2[t[i]]) return false;
            mp1[s[i]] = i+1;
            mp2[t[i]] = i+1;
        }        
        return true;
    }
};
