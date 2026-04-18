/*3714. Longest Balanced Substring II
You are given a string s consisting only of the characters 'a', 'b', and 'c'.
A substring of s is called balanced if all distinct characters in the substring appear the same number of times.
Return the length of the longest balanced substring of s.*/

/* APPROACH:
1. checkl1: Linear scan. If s[i] == s[i-1], increment count; else reset.
2. checkl2: Prefix Sum Difference. Map stores first index of (countA - countB). 
   If difference repeats at index j, substring (map[diff]...j] is balanced.
3. checkl3: Similar to checkl2, but map key is pair: (countA - countB, countA - countC).

COMPLEXITY:
Time: O(N) for all checks (linear scan).
Space: O(N) for hashmaps in checkl2/checkl3.
*/

class Solution {
public:
    // Strategy 1: Longest substring of identical characters
    int checkl1(string s) {
        if (s.empty()) return 0;
        int res = 0, count = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                res = max(res, count);
                count = 1; // Reset to 1 for the new character
            }
        }
        res = max(res, count); // Check last segment
        return res;
    }

    // Strategy 2: Longest substring with equal counts of two specific chars
    int checkl2(string s, char o1, char o2) {
        int n = s.length();
        int res = 0;
        unordered_map<int, int> diffmap;
        int c1 = 0;
        int c2 = 0;
        
        // Initialize for the case where the balanced string starts at the beginning
        // mapping difference 0 to index -1
        diffmap[0] = -1; 

        for (int i = 0; i < n; i++) {
            // If current char is neither o1 nor o2, reset the tracking
            if (s[i] != o1 && s[i] != o2) {
                diffmap.clear();
                diffmap[0] = i; // The "start" is now effectively index i
                c1 = 0;
                c2 = 0;
                continue;
            }

            if (s[i] == o1) c1++;
            if (s[i] == o2) c2++;

            int diff = c1 - c2;
            if (diffmap.count(diff)) {
                res = max(res, i - diffmap[diff]);
            } else {
                diffmap[diff] = i;
            }
        }
        return res;
    }

    // Strategy 3: Longest substring with equal counts of 'a', 'b', and 'c'
    int checkl3(string s) {
        int cA = 0, cB = 0, cC = 0;
        int res = 0;
        unordered_map<string, int> diffmap;
        diffmap["0_0"] = -1;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a') cA++;
            else if (s[i] == 'b') cB++;
            else if (s[i] == 'c') cC++;

            int diffAB = cA - cB;
            int diffAC = cA - cC;

            string key = to_string(diffAB) + "_" + to_string(diffAC);
            
            if (diffmap.count(key)) {
                res = max(res, i - diffmap[key]);
            } else {
                diffmap[key] = i;
            }
        }
        return res;
    }

    int longestBalanced(string s) {
        int maxl1 = checkl1(s);
        
        int maxl2 = max({checkl2(s, 'a', 'b'), checkl2(s, 'a', 'c'), checkl2(s, 'b', 'c')});
        int maxl3 = checkl3(s);

        return max({maxl1, maxl2, maxl3});
    }
};
