/*Leetcode Ps-761. Special Binary String
Special binary strings are binary strings with the following two properties:

The number of 0's is equal to the number of 1's.
Every prefix of the binary string has at least as many 1's as 0's.
You are given a special binary string s.

A move consists of choosing two consecutive, non-empty, special substrings of s, and swapping them. Two strings are consecutive if the last character of the first string is exactly one index before the first character of the second string.

Return the lexicographically largest resulting string possible after applying the mentioned operations on the string.*/
class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> specials;

        int start = 0;
        int sum = 0;

        for(int i = 0; i < s.length(); i++) {
            sum += s[i] == '1' ? 1 : -1;

            if(sum == 0) {
                string inner = s.substr(start+1, i-start-1);
                specials.push_back("1" + makeLargestSpecial(inner) + "0");
                start = i+1;
            }
        }


        sort(begin(specials), end(specials), greater<string>());

        string result;
        for(string &str : specials) {
            result += str;
        }

        return result;    
    }
};
