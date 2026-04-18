/*Leetcode ps- 2840. Check if Strings Can be Made Equal With Operations II
You are given two strings s1 and s2, both of length n, consisting of lowercase English letters.
You can apply the following operation on any of the two strings any number of times:
Choose any two indices i and j such that i < j and the difference j - i is even, then swap the two characters at those indices in the string.
Return true if you can make the strings s1 and s2 equal, and false otherwise.*/


/*
 * Approach: Frequency Counting by Parity
 * 1. Rule: Swaps only occur between indices with an even difference (j - i = 2). 
 * Thus, characters at even indices can only swap with other even indices, 
 * and odd indices can only swap with other odd indices.
 * 2. Strategy: We just need to check if both strings have the exact same 
 * character counts in their even positions, and separately in their odd positions.
 * 3. Implementation: Loop through the strings. Use two arrays ('even' and 'odd') 
 * to keep a running balance of character frequencies. Increment the count 
 * for characters in s1 and decrement for characters in s2.
 * 4. Verdict: If the strings can be made equal, all balances in both arrays 
 * will perfectly cancel out to 0. If any value is non-zero, return false.
 */

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int  n = s1.length();
        int even[26] ={0};
        int odd[26] ={0};

        for(int i =0 ;i<n;i++){
            if(i%2==0){
                even[s1[i]-'a']++;           
                even[s2[i]-'a']--;           
            }
            else{
                odd[s1[i] - 'a']++;
                odd[s2[i] -'a']--;
            }
        }

        for(int i =0 ;i<26;i++){
            if(even[i] !=0 || odd[i] !=0) return false;
        }
        return true;
    }
};
