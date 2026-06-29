/*Leetcode ps- 1967. Number of Strings That Appear as Substrings in Word
Given an array of strings patterns and a string word, return the number of strings in patterns that exist as a substring in word.
A substring is a contiguous sequence of characters within a string.
*/

/* Approach - Brute Force Substring Check
 * Basically, we check every single pattern one by one to see if it exists inside the main word by manually extracting and comparing chunks of the exact same length.
 * We keep 2 main variables to track our progress:
 * - 'ans' keeps a running tally of how many patterns successfully appeared as substrings.
 * - 'temp' temporarily holds the extracted chunk from the main word so we can compare it against our current pattern.
 *
 * How it runs:
 * First, we loop through each individual string 's' inside our given list of 'patterns'.
 * Then, for each pattern, we use an inner loop to slide a viewing window across the main 'word'. We ensure the window size strictly matches the length of the pattern 'n', and we only slide as far as 'm - n' so we don't go out of bounds.
 * At each step, we extract the current chunk from the main 'word' using 'substr' and store it in 'temp'.
 * If 'temp' perfectly matches our current pattern 's', we instantly increment our 'ans' counter, break out of the inner loop (since we only need to know it appears at least once), and move on to test the very next pattern!
 */

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans =0,n,m=word.length();
        string temp;
        for(string s : patterns){
            n = s.length();
            for(int i =0 ;i<=m-n;i++){
                temp = word.substr(i,n);
                if(temp == s){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
