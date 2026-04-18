/*Leetcode ps- 1684. Count the Number of Consistent Strings
You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.
Return the number of consistent strings in the array words.*/

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count =0 ;
        unordered_set<char> st(allowed.begin(), allowed.end());
        int n = words.size();
        for(int i =0 ;i<n ;i++){
            bool isvalid = true;
            for(char w : words[i]){
            if(!st.count(w)){
                isvalid = false;
                break;
            }
            } 
            if(isvalid) count++;
        }
        return count;
    }
};d
