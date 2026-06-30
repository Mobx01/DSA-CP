/*Leetcode ps- 1358. Number of Substrings Containing All Three Characters
Given a string s consisting only of characters a, b and c.
Return the number of substrings containing at least one occurrence of all these characters a, b and c.*/


/* Approach - Sliding Window (Two Pointers)
 * Basically, we use an expanding and shrinking window to efficiently count valid substrings in O(N) time. The magic trick is realizing that once a window contains all three characters, every longer string extending to its right is also automatically valid!
 * We keep a few main variables/structures to track our window:
 * - 'freq' is a small array that tracks the current counts of 'a', 'b', and 'c' inside our active window.
 * - 'i' and 'j' act as our left and right boundaries (pointers) for the window.
 * - 'count' keeps a running tally of all the valid substrings we've logically found.
 *
 * How it runs:
 * First, we use our right pointer 'j' to loop through the string, expanding our window one character at a time and tallying it in our 'freq' array.
 * As soon as our window becomes valid (it contains at least one 'a', one 'b', and one 'c'), we don't need to manually check the rest of the string! Any substring that starts exactly at 'i' and ends at 'j', or anywhere *after* 'j', is guaranteed to be valid. So, we instantly add the remaining length of the string `(n - j)` to our total 'count'.
 * Right after scoring those substrings, we try to find more by shrinking the window from the left. We subtract the character at our left pointer 'i' from our 'freq' array and step 'i' forward. We keep shrinking (and adding to our count) as long as the window remains valid, moving on to expand 'j' again only when we finally lose one of our required characters!
 */

class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        int i = 0;
        int n = s.length();
    
        // index 0 -> 'a',1 -> 'b',2 -> 'c'
        vector<int> freq(3, 0); // store freq of each char in the current subarray
        
        // j is our right pointer, i is our left pointer
        for (int j = 0; j < n; j++) {
            freq[s[j] - 'a']++; // Include s[j] in our current window
            
            // While window contains at least one of all three characters
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                // If the substring from i to j is valid, then all substrings 
                // starting at i and ending anywhere after j are also valid(because they have the current subarray ).
                count += (n - j);
                
                // Shrink the window from the left to look for the next valid window
                freq[s[i] - 'a']--;
                i++;
            }
        }
        
        return count;
    }
};
