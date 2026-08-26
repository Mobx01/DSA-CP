/*Leetcode ps-2904. Shortest and Lexicographically Smallest Beautiful String
You are given a binary string s and a positive integer k.
A substring of s is beautiful if the number of 1's in it is exactly k.
Let len be the length of the shortest beautiful substring.
Return the lexicographically smallest beautiful substring of string s with length equal to len. If s doesn't contain a beautiful substring, return an empty string.
A string a is lexicographically larger than a string b (of the same length) if in the first position where a and b differ, a has a character strictly larger than the corresponding character in b.
For example, "abcd" is lexicographically larger than "abcc" because the first position they differ is at the fourth character, and d is greater than c.*/



/* Approach - Dynamic Sliding Window / Elastic Lexicographical Bounds (Time: O(N^2) worst-case due to substr, Space: O(N))
 * Basically, we completely annihilate the brute force O(N^3) substring generation by aggressively deploying a two-pointer caterpillar method, violently expanding to capture '1's and ruthlessly amputating garbage '0's to mathematically forge the tightest possible bounds!
 * * Observation: 
 * - The absolute core of this architecture is the secondary condition inside your contraction loop: `s[i] == '0'`! This is an absolute masterstroke! Because leading '0's contribute absolutely NOTHING to the '1' count but bloat the length and ruin the lexicographical rank, you aggressively sheer them off the exact millisecond they enter the left side of the window, structurally forcing the window to always anchor perfectly on a '1'!
 * - (The Fatal Heap Allocation Trap): Your sliding window logic is O(N) and mathematically flawless, but your string extraction is a catastrophic ticking time bomb! Calling `s.substr(i, j - i + 1)` *every single time* `count1 == k` violently allocates brand new dynamic memory on the heap! If you have a massive string full of '1's, you trigger an O(N) string copy inside an O(N) loop, aggressively degrading your blistering O(N) algorithm down to a sluggish O(N^2) CPU nightmare!
 * - (Optimization Alert / The Zero-Allocation Nuke): You can completely destroy this memory leak by refusing to build the string until the absolute end! Instead of storing `ans`, track exactly two O(1) integer variables: `best_start` and `best_length` (initialize length to `INT_MAX`). When `count1 == k`, just compare `(j - i + 1)` against `best_length`. If it's strictly smaller, update your indices! If it's a tie, you only need to run a high-speed pointer comparison (or use C++ `std::string_view`) to check the lexicographical order without allocating a single byte! Finally, call `substr` exactly ONCE right before the return statement!
 * * How it runs:
 * First, we safely intercept the string and ignite our two-pointer engine, securely anchoring `i` and `j` to the absolute start of the timeline.
 * The right pointer `j` aggressively sweeps forward, absorbing characters and violently incrementing our `count1` radar every time it detects a '1'.
 * The exact millisecond the capacity breaches `k`, OR a useless '0' pollutes the left boundary, the inner loop triggers! It ruthlessly amputates the left side, advancing `i` and dumping excess '1's to mathematically stabilize the sequence!
 * When the radar perfectly locks onto exactly `k` ones, we trigger a high-speed collision check against the global best `ans`. We prioritize the absolute shortest length, and in the event of a structural tie, we mathematically deploy `min()` to secure the lexicographically superior timeline!
 * Finally, the engine sweeps to the end and confidently returns the optimally forged substring in absolute peak theoretical accuracy!
 */


class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i = 0, j = 0, n = s.length();
        int count1 = 0;
        string ans = "";

        while (j < n) {
            if (s[j] == '1') {
                count1++;
            }

            //shrink the window 
            while (i <= j && (count1 > k || s[i] == '0')) {
                if (s[i] == '1') {
                    count1--;
                }
                i++;
            }

            // Iif no of 1s is k
            if (count1 == k) {
                string temp = s.substr(i, j - i + 1);
                
                if (ans == "") {
                    ans = temp;
                } else if (temp.length() < ans.length()) {
                    ans = temp; //shorter
                } else if (temp.length() == ans.length()) {
                    ans = min(ans, temp); //same length-> choose lexicographically smaller
                }
            }
            j++;
        }
        
        return ans;
    }
};
