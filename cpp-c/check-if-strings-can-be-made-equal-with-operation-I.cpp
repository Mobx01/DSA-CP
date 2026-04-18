/*Leetcode ps- 2839. Check if Strings Can be Made Equal With Operations I
You are given two strings s1 and s2, both of length 4, consisting of lowercase English letters.
You can apply the following operation on any of the two strings any number of times:
Choose any two indices i and j such that j - i = 2, then swap the two characters at those indices in the string.
Return true if you can make the strings s1 and s2 equal, and false otherwise.*/

/*
 * Approach:
 * 1. The setup: Because the string is exactly 4 characters long, index 0 can 
 * ONLY swap with index 2, and index 1 can ONLY swap with index 3.
 * 2. The check: We only need to loop through the first two characters of s1.
 * 3. The forced swap: If the character at index 0 or 1 in s1 doesn't match s2, 
 * force a swap with its only available partner (i + 2).
 * 4. The final verdict: After making those necessary swaps, check if s1 now 
 * matches s2. If they do, return true. Otherwise, it's impossible.
 */
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        for(int i =0;i<2;i++){
            if(s1[i] != s2[i]){
                swap(s1[i],s1[i+2]);
            }
        }
        return s1==s2;
    }
};
