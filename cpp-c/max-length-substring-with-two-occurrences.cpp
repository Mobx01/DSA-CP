/*Leetcode ps-3090. Maximum Length Substring With Two Occurrences
Given a string s, return the maximum length of a substring such that it contains at most two occurrences of each character.*/


/* Approach - Sliding Window / Dynamic Frequency Map (Time: O(N), Space: O(1) / O(Σ))
 * Basically, we aggressively expand a sliding window to gobble up characters, and the exact millisecond any character's frequency violently breaches our strict limit of 2, we ruthlessly shrink the left boundary until mathematical equilibrium is restored!
 * * Observation: 
 * - The sliding window technique completely annihilates the need for a catastrophic O(N^2) brute force! Because the left pointer 'i' ONLY ever moves forward, every single character in the string is processed a maximum of exactly two times. This mathematically guarantees a blistering O(N) total runtime!
 * - (The Absolute Game-Breaker): We don't need to waste CPU cycles scanning the entire frequency map to verify if the window is valid! Because the window was flawlessly valid *before* we expanded 'j', the ONLY element that could possibly break the structural integrity is the exact character we just pulled in: `s[j]`! Therefore, our inner `while` loop hyper-fixates strictly on fixing `s[j]`!
 * - (Optimization Alert / The Raw Array Upgrade): You deployed an `unordered_map`, which aggressively burns CPU cycles on hash calculations and dynamic memory allocation! Since we are dealing with strings (likely ASCII or lowercase English letters), you could instantly upgrade this to absolute peak performance by completely dropping the map and swapping to a raw `int freq[128] = {0}` or `vector<int> freq(26, 0)`! This shreds the hashing overhead, dropping lookup times to a blistering, guaranteed true O(1)!
 * - (Redundancy Note): Just like in standard sliding windows, the `i < j` boundary check in the inner loop is mathematically redundant! Because `s[j]` is the exact character causing the overflow, the left pointer `i` is guaranteed to eventually hit an instance of `s[j]` and violently decrement it long before it could ever physically cross `j`!
 * * How it runs:
 * First, we safely deploy our `freq` map to track real-time character counts, securely anchor both our fast pointer `j` and slow pointer `i` exactly at index 0, and set our absolute maximum `result` tracker to 0.
 * Then, we trigger a high-speed forward sweep with `j`. At every single step, we aggressively absorb `s[j]` into our active window and instantly bump its frequency count!
 * Next, we hit our strict validity check! If the newly added `s[j]` violently overflows our strict limit of 2, we instantly ignite the inner recovery loop!
 * We ruthlessly evict characters from the extreme left of our window (`freq[s[i]]--`) and violently snap our left boundary forward (`i++`) step-by-step until the overflowing `s[j]` is forced perfectly back into compliance!
 * Finally, with the window mathematically verified as completely valid, we aggressively calculate the current window size (`j - i + 1`), relentlessly lock the highest value into our `result` tracker, and confidently advance `j` until the entire string is conquered!
 */



class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        unordered_map<char,int> freq;
        int i =0,j=0,result=0;
        while(j < n){
            freq[s[j]]++;

            while(i < j && freq[s[j]] > 2){
                freq[s[i]]--;
                i++;
            }
            result = max(result , j-i+1);
            j++;
        }
        return result;
    }
};
