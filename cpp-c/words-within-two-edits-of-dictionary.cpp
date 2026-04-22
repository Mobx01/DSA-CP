/*2452. Words Within Two Edits of Dictionary
You are given two string arrays, queries and dictionary. All words in each array comprise of lowercase English letters and have the same length.
In one edit you can take a word from queries, and change any letter in it to any other letter. Find all words from queries that, after a maximum of two edits, equal some word from dictionary.
Return a list of all words from queries, that match with some word from dictionary after a maximum of two edits. Return the words in the same order they appear in queries.*/


// Approach :- Brute force
// For each query word:
//   Compare it with every dictionary word
//   If lengths are different → skip
//   Count number of character mismatches
//   If mismatches exceed 2 → stop checking this pair
//   If mismatches ≤ 2 → add query word to answer
//   Break since one valid match is enough


class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;

        for(string &s : queries){// s is current string
            int n = s.size();//length of current string
            for(string &d : dictionary){//d is current dictonary word
                if(d.size() != n) continue; // if length of a and d are not equal then s cant be transformed to d.
                int changes = 0;
                for(int i = 0 ;i < n ;i++){
                    if(changes > 2) break; //if more than 2 edits then not suitable d.
                    if(s[i] != d[i]) changes++;//if mismatch consider it a edit
                }
                if(changes <= 2){ // if less than 2 edits then it is a part of answer
                    ans.push_back(s); 
                    break; // not need to check for other words in dictonary
                }
            }
        }
        return ans;
    }
};
