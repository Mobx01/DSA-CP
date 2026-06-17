/*Leetcode ps - 3614. Process String with Special Operations II
You are given a string s consisting of lowercase English letters and the special characters: '*', '#', and '%'.
You are also given an integer k.
Build a new string result by processing s according to the following rules from left to right:
If the letter is a lowercase English letter append it to result.
A '*' removes the last character from result, if it exists.
A '#' duplicates the current result and appends it to itself.
A '%' reverses the current result.
Return the kth character of the final string result. If k is out of the bounds of result, return '.'.*/


class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();
        long long L = 0;
        for(char c : s) {
            if (c == '*' && L>0) {
                L--;
            } 
            else if (c == '#') {
                L *=2;
            } 
            else if (c == '%') {
                //no change in length(reversal )
            } 
            else if (c != '*') { 
                //a to z so increase length
                L++;
            }
        }

        if(k >= L){
            return '.';//out of bound
        }
        // we will track the character assumning the result word is already consructed
        for(int i = n-1;i>=0;i--){//traversing from back
           if(s[i] == '*'){
               L++; //no change in k and reverse operation on L
           }else if(s[i] == '%'){
               //no change in L(reversal) but k will shift
               k = L-k-1;
           } else if(s[i] == '#'){
               //reverse the concatination
               L = L/2; //length goes half
               k = (k >= L) ? k-L : k;
           } else{// normal character a to z
               L--; //reverse process of construction
           }

           if(k == L) return s[i];
        }

        return '.';
    }
};
