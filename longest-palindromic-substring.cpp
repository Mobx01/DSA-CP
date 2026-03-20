/*Leetcode ps- 5. Longest Palindromic Substring
Given a string s, return the longest palindromic substring in s.

*/
// Approach: Expand Around Center
        // A palindrome mirrors around its center.
        // For every index, consider it as the center and expand outward.
        // Two cases are checked:
        // 1. Odd length palindrome (center at i)
        // 2. Even length palindrome (center between i and i+1)
        // Expand while characters on both sides are equal.
        // Track and update the longest palindrome found.


class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int n = s.length();

        for(int i = 0; i < n; i++){
            // odd length
            int st = i, end=i;
            while(st>=0 && end <n && s[st]==s[end]){
                end++;
                st--;
            }
            string temp = s.substr(st+1,end-st-1);
            if(temp.length()>res.length()) res = temp;

            //even length
            st= i;
            end=i+1;
            while(st>=0 && end <n && s[st]==s[end]){
                end++;
                st--;
            }
            temp = s.substr(st+1,end-st-1);
            if(temp.length()>res.length()) res = temp;

        }
        return res;
    }
};
