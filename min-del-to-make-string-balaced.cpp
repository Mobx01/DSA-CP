/*Leetcode ps:- 1653. Minimum Deletions to Make String Balanced
You are given a string s consisting only of characters 'a' and 'b'​​​​.
You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.
Return the minimum number of deletions needed to make s balanced.*/

class Solution {
public:
    int minimumDeletions(string s) {
        int count = 0; 
        int answer = 0 ;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == 'b') count++;
            if(s[i] == 'a' && count>0){
                //this only acts when b is before a ;
                count--;
                answer++;
            }
        }
        return answer;
    }
};
