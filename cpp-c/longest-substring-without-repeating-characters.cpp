/*Leetcode ps-3. Longest Substring Without Repeating Characters
Given a string s, find the length of the longest substring without duplicate characters.*/

/* Approach - Sliding Window / Dynamic Hash Set Contraction (Time: O(N) amortized, Space: O(min(N, Σ)))
 * Basically, we completely annihilate the O(N^2) brute force substring search by aggressively deploying a sliding window and an active hash state, dynamically expanding the right flank while forcefully contracting the left flank the exact millisecond a duplicate character collides!
 * * Observation: 
 * - The absolute core of this architecture is the Non-Repeating Boundary Window! You brilliantly realized that when a duplicate character is encountered at `s[j]`, you don't need to restart your search from scratch; you simply slide your left boundary `i` forward, systematically erasing characters from your memory state until the collision is resolved!
 * - (The `unordered_set` Cache Penalty Trap): Your algorithmic logic is absolute textbook perfection, but your data structure choice is a silent hardware assassin! `unordered_set` relies on hash tables with dynamic node allocations on the heap. Every single `insert` and `erase` operation forces pointer dereferences, causing massive L1 cache misses and cache-line thrashing! 
 * - (Optimization Alert 1 / The Fixed-Size Frequency Array Nuke): Since the character set is strictly bounded (e.g., standard ASCII or 128/256 characters), you can completely vaporize the `unordered_set`! Replace it with a static fixed-size array or a direct index tracker `vector<int> char_index(128, -1);`! Instead of erasing elements one by one with a `while` loop, you can instantly teleport your left pointer `i` directly past the previous occurrence of the duplicate character in O(1) time: `i = max(i, char_index[s[j]] + 1);`! This completely flattens the inner contraction phase!
 * - (Optimization Alert 2 / The Branch-Free Max Calculation): `maxlen = max(maxlen, j - i);`. Because your `j` advances strictly after a successful insertion, the window length is always precisely `j - i + 1`. Maintaining this cleanly ensures maximum register throughput without redundant branching.
 * * How it runs:
 * First, we safely intercept the string and initialize our sliding window boundaries (`i = 0`, `j = 0`) alongside our state-tracking set.
 * We ignite the high-speed linear traversal engine! 
 * For every incoming character at `s[j]`, we check our memory set. If the character is absent, we violently insert it, expand our right boundary (`j++`), and aggressively update our global `maxlen` register.
 * The exact millisecond a duplicate character collides, the radar triggers our contraction phase! We ruthlessly erase the character at `s[i]` from our set and advance our left boundary (`i++`) until the duplicate is completely purged.
 * Finally, we confidently output the absolute longest valid non-repeating substring length, flawlessly crushing the simulation!
 */



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen =0 , i=0,j=0,n=s.length();
        unordered_set<char> pref;
        while(j < n){
            if(pref.find(s[j]) == pref.end()){//this char is not present there
                pref.insert(s[j]);
                j++;
                maxlen = max(maxlen, j-i);
            }else{//s[j] already present so remove from back 
                pref.erase(s[i]);
                i++;
            }
        }
        return maxlen;
    }
};
