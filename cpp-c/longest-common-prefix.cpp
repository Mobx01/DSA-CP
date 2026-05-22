/*Leetcode ps- 14. Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".  */

/*
APPROACH: (not optimised)
1. SORT THE ARRAY:
   - `sort(strs.begin(), strs.end());`
   - Sorting the array alphabetically is a clever trick. It naturally 
     groups words with similar starting letters together. 
     (e.g., ["flower", "flow", "flight"] becomes ["flight", "flow", "flower"]).

2. INITIALIZE THE PREFIX:
   - `string compref = strs[0];`
   - We take the very first string in our sorted list and assume, for now, 
     that this entire word is the common prefix.

3. COMPARE WITH EVERY OTHER STRING:
   - `for(string s : strs)`
   - We loop through every string in the array (including the first one).
   - For each string, we call our helper function `findcompref`.

4. THE HELPER FUNCTION (`findcompref`):
   - This function takes two strings (our current prefix and the new word).
   - It figures out which string is shorter to avoid checking past the end.
   - It uses a `for` loop to check letter by letter.
   - As soon as the letters don't match (`s1[i] != s2[i]`), it `break`s 
     the loop because the common prefix ends right there.
   - It returns the matched portion.

5. SHRINK AND CHECK (EARLY EXIT):
   - Back in the main function, `compref` gets updated to the newly 
     returned, potentially shorter prefix.
   - `if(compref == "") return "";`
   - If at any point the common prefix becomes empty, it means there is 
     no common starting letter across all words. We stop immediately and 
     return "" to save time.

6. FINAL RESULT:
   - Once the loop finishes checking all words, whatever is left in 
     `compref` is our longest common prefix across the whole array!

*/

class Solution {
public:
    string findcompref(string s1 , string s2){
        if(s1.length()==0 || s2.length()==0)return "";
        int n = min(s1.length(),s2.length());
        string res = "";
        for(int i = 0 ; i < n ;i++){
            if(s1[i] != s2[i]) break;
            res.push_back(s1[i]);
        }
        return res;
    }
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin() , strs.end());
        string compref = strs[0];
        for(string s : strs){
            compref = findcompref(compref,s);
            if(compref == "") return "";
        }
        return compref;
    }
};

/*
APPROACH: (Optimized)
1. SORT THE ARRAY ALPHABETICALLY:
   - `sort(strs.begin(), strs.end());`
   - When you sort strings alphabetically, the words that are the most 
     different from each other end up at the very beginning and the 
     very end of the list.
   - For example: ["flower", "flow", "flight"] sorts into 
     ["flight", "flow", "flower"].

2. THE "FIRST AND LAST" TRICK:
   - `string compref = findcompref(strs[0], strs[strs.size() - 1]);`
   - Because the array is sorted, the first word (`strs[0]`) and the 
     last word (`strs[strs.size() - 1]`) have the biggest differences.
   - The magic logic: If these two most-different words share a common 
     prefix, then every word squeezed between them in the sorted list 
     MUST also share that exact same prefix!
   - This saves us from having to run a loop to check the middle words.

3. THE HELPER FUNCTION (`findcompref`):
   - We pass our first and last words into this helper function.
   - It figures out which string is shorter to avoid checking past the end.
   - It checks them letter by letter in a `for` loop.
   - As soon as a letter doesn't match (`s1[i] != s2[i]`), it breaks 
     the loop because the common prefix ends right there.
   - It returns the matched portion.

4. FINAL RESULT:
   - Whatever the helper function finds as the common prefix between 
     the first and last words is mathematically guaranteed to be the 
     longest common prefix for the entire array!
=======================================================================
*/

class Solution {
public:
    string findcompref(string s1 , string s2){
        if(s1.length()==0 || s2.length()==0)return "";
        int n = min(s1.length(),s2.length());
        string res = "";
        for(int i = 0 ; i < n ;i++){
            if(s1[i] != s2[i]) break;
            res.push_back(s1[i]);
        }
        return res;
    }
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin() , strs.end());
        string compref = findcompref(strs[0],strs[strs.size() - 1]);
        return compref;
    }
};
