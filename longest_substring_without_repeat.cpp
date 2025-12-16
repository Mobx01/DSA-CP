/* leetcode ps-3 Longest Substring Without Repeating Characters
Given a string s, find the length of the longest substring without duplicate characters.
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0, i =0 , j = 0;
        unordered_set<char> pre ;
        while(j < s.length()){
            if(pre.find(s[j]) == pre.end()){
                pre.insert(s[j]);
                maxlen = max(maxlen , j- i +1);
                j++;
            }
            else{
                pre.erase(s[i]);
                i++;
            }
        }

        return maxlen ;
    }
};
