/*Leetcode ps- 1002. Find Common Characters
Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.*/

class Solution {
public:
    string intersection(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        
        int i = 0, j = 0;
        string res = "";
        
        while(i < s1.size() && j < s2.size()) {
            if(s1[i] == s2[j]) {
                res.push_back(s1[i]);
                i++;
                j++;
            }
            else if(s1[i] < s2[j]) i++;
            else j++;
        }
        return res;
    }

    vector<string> commonChars(vector<string>& words) {
        string res = words[0];
        
        // Intersect current result with the next word
        for(int i = 1; i < words.size(); i++) {
            res = intersection(res, words[i]);
        }
        
        // Convert final string "ell" -> ["e", "l", "l"]
        vector<string> final_res;
        for(char c : res) {
            final_res.push_back(string(1, c));
        }
        
        return final_res;
    }
};
