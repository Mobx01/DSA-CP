/*Leetcode ps -76. Minimum Window Substring
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.*/



/* Approach - Variable-Size Sliding Window with Deficit Tracking (Time: O(N + M), Space: O(Σ))
 * Basically, we completely annihilate the O(N^2) brute-force substring search by aggressively deploying a sliding window with a deficit counter (`reqc`), expanding the right flank until all required characters are captured, then contracting the left flank to find the absolute minimum valid span!
 * * Observation: 
 * - The absolute core of this architecture is the Deficit-Driven Expansion & Contraction! You brilliantly track the remaining characters needed via `reqc`. As the right pointer `j` sweeps across, matching a needed character decrements the deficit. The exact millisecond `reqc == 0`, a valid window is locked, triggering the inner contraction loop where the left pointer `i` advances to strip away redundant characters while recording the absolute minimum window size!
 * - (The `unordered_map` Heap Penalty Trap): Your algorithmic logic is absolute textbook perfection, but your data structure choice introduces silent hardware overhead! `unordered_map` forces heap node allocations, hash-function evaluations, and pointer chasing. Because the character set is strictly bounded (standard ASCII or 128/256 characters), you can completely vaporize the `unordered_map`! Replace it with a flat, stack-allocated `vector<int> freq(128, 0);` to reduce all frequency lookups to blazing-fast array indexing with zero heap pollution.
 * - (The Substring Extraction Win): `s.substr(start_ind, winsize)`. While `substr` creates a new string object and allocates memory for the final return, it executes exactly once at the very end of the algorithm, making its O(winsize) footprint completely negligible compared to the overall runtime efficiency!
 * * How it runs:
 * First, we safely intercept the strings and check edge cases (e.g., if target `t` is longer than source `s`, instantly return an empty string).
 * We populate our frequency map with all required characters from `t` and initialize our sliding window pointers (`i = 0`, `j = 0`), alongside our minimum window size tracker.
 * We ignite the high-speed linear traversal engine, sweeping our right pointer `j` across the timeline and reducing our character deficit as matching elements roll in.
 * The exact millisecond our deficit drops to zero (`reqc == 0`), the contraction phase triggers! We evaluate our minimum window size, record the starting index, and march our left pointer `i` forward, restoring character frequencies until the window breaks validity.
 * Finally, we flush the optimal minimum window substring to the output stream with absolute mathematical precision at raw silicon speed!
 */



class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        if(t.length() > s.length())return "";
        unordered_map<char,int> freq;
        for(char ch : t){//get all element of t in map
            freq[ch]++;
        }

        int reqc = t.length();
        int i =0 ,j=0;
        int winsize = INT_MAX , start_ind = 0;

        while(j < n){
            char ch = s[j];

            if(freq[ch] > 0){
                reqc--;
            }
            freq[ch]--;

            //shrink untill required count is 0
            while(reqc ==0){
                int curs = j-i+1;
                if(winsize > curs){
                    winsize = curs;
                    start_ind = i;
                }
                freq[s[i]]++;
                if(freq[s[i]] > 0){
                    reqc++;
                }

                i++;
            }
            j++;
        }

        return (winsize == INT_MAX) ? "" : s.substr(start_ind,winsize);
        
    }
};
