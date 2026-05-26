/*Leetcode ps- 520. Detect Capital
We define the usage of capitals in a word to be right when one of the following cases holds:
All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.*/

/*
 * APPROACH: Counting Uppercase Letters
 * * Instead of checking every letter's position one by one, we can simply 
 * count the total number of uppercase letters in the word and then 
 * verify if that count matches the standard rules of capitalization.
 * * Step 1: Count Capitals
 * Loop through the string and count the uppercase letters. 
 * (ASCII values 65 to 90 represent 'A' to 'Z').
 * * Step 2: Check the 3 Valid Scenarios
 * - Scenario A: All letters are lowercase (capcount == 0). Example: "leetcode"
 * - Scenario B: All letters are uppercase (capcount == length of word). Example: "USA"
 * - Scenario C: Only the first letter is uppercase (capcount == 1 AND the 
 * first letter is between 'A' and 'Z'). Example: "Google"
 * * Step 3: Return Result
 * If the word fits any of those three scenarios, return true. Otherwise, return false.
 */


class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        int capcount=0;
        for(char c : word ){
            if(c >= 65 && c <= 90)capcount++;
        }
        if(capcount == 0) return true;
        if(capcount == n) return true;
        if(capcount == 1) return (word[0] >= 65 && word[0] <= 90) ? true :false;
        return false;
    }
};
