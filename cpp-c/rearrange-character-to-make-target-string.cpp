/*Leetcode ps - 2287. Rearrange Characters to Make Target String
You are given two 0-indexed strings s and target. You can take some letters from s and rearrange them to form new strings.
Return the maximum number of copies of target that can be formed by taking letters from s and rearranging them.*/

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int> freqs;
        unordered_map<char,int> freqt;

        for(char c : s) freqs[c]++;
        for(char c : target) freqt[c]++;

        int ans = INT_MAX;
        for(char c : target){
            ans = min(ans,freqs[c]/freqt[c]);
        }
        return ans;

    }
};

