/*Leetocode ps:- 3713. Longest Balanced Substring I
You are given a string s consisting of lowercase English letters.
A substring of s is called balanced if all distinct characters in the substring appear the same number of times.
Return the length of the longest balanced substring of s.*/

/* APPROACH:
    ---------
    1. Start checking from the maximum possible substring length (n = s.length()).
    2. For each length 'len', check all substrings of size 'len' using sliding window.
    3. Maintain a hashmap to store frequency of characters in the current window.
    4. For the first window:
            - Insert first 'len' characters into the hashmap.
            - Check if all characters have equal frequency.
    5. Slide the window:
            - Add the new entering character.
            - Remove the leaving character.
            - If frequency becomes zero, erase it from the hashmap.
            - After every slide, check if all characters have equal frequency.
    6. If a balanced substring is found, return its length immediately.
    7. If no balanced substring is found after checking all lengths, return 0.

    TIME COMPLEXITY:
    ----------------
    Outer loop runs for n lengths → O(n)
    For each length, sliding window runs up to n times → O(n)
    Checking if all frequencies are equal takes at most O(26) 
    (since only lowercase English letters)

    Worst Case Time Complexity: O(n^2)

    SPACE COMPLEXITY:
    -----------------
    Hashmap stores at most 26 characters → O(1)
    */


class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();

        // Try from largest length to smallest
        for (int len = n; len >= 1; len--) {

            unordered_map<char, int> freq;

            // First window of size len
            for (int i = 0; i < len; i++) {
                freq[s[i]]++;
            }

            if (isBalanced(freq)) return len;

            // Sliding window
            for (int i = len; i < n; i++) {
                // Add new character
                freq[s[i]]++;

                // Remove old character
                freq[s[i - len]]--;
                if (freq[s[i - len]] == 0)
                    freq.erase(s[i - len]);

                if (isBalanced(freq))
                    return len;
            }
        }

        return 0;
    }

private:
    bool isBalanced(unordered_map<char,int>& freq) {
        if (freq.empty()) return false;

        int val = freq.begin()->second;

        for (auto &p : freq) {
            if (p.second != val)
                return false;
        }

        return true;
    }
};
