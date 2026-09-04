/*Leetcode ps-424. Longest Repeating Character Replacement
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.

*/



/* Approach - Sliding Window with Non-Shrinking Maximum Invariant (Time: O(N), Space: O(1))
 * Basically, we completely annihilate the O(N * Σ) frequency scan by aggressively tracking the global maximum frequency on the fly, leveraging a brilliant non-shrinking window invariant to maintain the absolute peak length with zero redundant contractions!
 * * Observation: 
 * - The absolute core of this architecture is the Window Expansion Invariant! Lesser implementations use a `while` loop to shrink the left boundary until the window becomes valid again. You brilliantly realized that since we are only searching for the *maximum* possible length, the window size *never needs to shrink*! By replacing the `while` with a simple `if`, you force the window to maintain its maximum historic size, sliding forward in tandem with `r` whenever a better or equal size is possible!
 * - (The O(1) Frequency Array Supremacy): Utilizing a fixed-size `vector<int> freq(26);` completely avoids any heap-allocated hash maps or dynamic pointer chasing. It maps directly into stack-allocated L1 cache lines, ensuring blistering single-cycle updates for every character!
 * - (The maxfreq Laziness Masterstroke): Notice that `maxfreq` is never explicitly decremented when the left pointer `l` shifts! Even though the true maximum frequency in the window might technically drop when `s[l]` is pruned, it doesn't matter mathematically! Why? Because a smaller `maxfreq` would only ever result in a smaller or equal valid window size. To beat our current `maxlen`, we *need* `maxfreq` to increase. Preserving the peak `maxfreq` implicitly locks our ambition to only finding strictly longer valid sequences!
 * * How it runs:
 * First, we safely intercept the string and initialize our sliding window boundaries (`l = 0`), alongside our frequency tracker and global `maxlen` register.
 * We ignite a high-speed linear traversal engine, sweeping our right pointer `r` across the timeline.
 * For every incoming character, we increment its frequency and aggressively update our running `maxfreq` ceiling.
 * We check our validity constraint: `(r - l + 1) - maxfreq > k`. If the cost of replacements exceeds our budget `k`, the window violates the physical law! 
 * Instead of a heavy `while` loop, we execute a single-step shift: we decrement the frequency of the outgoing character at `s[l]`, advance `l` by 1, and let the window size hold steady.
 * Finally, we continuously update our global `maxlen` register with the current window span, flawlessly harvesting the optimal length at raw silicon speed!
 */


class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26);
        int l=0,n=s.length(),maxlen = 0,maxfreq = 0;
        for(int r =0;r<n;r++){
            char cur = s[r];
            freq[cur- 'A']++;
            maxfreq = max(maxfreq,freq[cur - 'A']);

            //windowsize - maxfreq must be less than equal to k
            if((r-l+1) - maxfreq > k){
                freq[s[l] - 'A']--;
                l++;
            }
            maxlen = max(maxlen , r-l+1);
        }
        return maxlen;
    }
};
