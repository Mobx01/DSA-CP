/*Leetcode ps- 2124. Check if All A's Appears Before All B's
Given a string s consisting of only the characters 'a' and 'b', return true if every 'a' appears before every 'b' in the string. Otherwise, return false.*/



/* Approach - Single-Pass State Flag Ordering Check / Check if All A's Appears Before All B's (Time: O(N), Space: O(1))
 * Basically, we completely annihilate brute-force substring scanning or string sorting by aggressively tracking whether a `'b'` has already been seen and immediately rejecting any subsequent `'a'` in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Monotonic Character Order Invariant (LeetCode 2124 - Check if All A's Appears Before All B's)! A string satisfies "all `'a'`s appear before all `'b'`s" if and only if no `'a'` occurs anywhere after the first `'b'`. Using a single state flag `b_in` (set to `1` once `'b'` is encountered) cleanly enforces this ordering without extra memory or sorting overhead.
 * - (Concise Equivalent Condition): Since the string only contains `'a'` and `'b'`, an even shorter equivalent way to express the same invariant is checking `!is_sorted(s.begin(), s.end())` (as `'a' < 'b'` in ASCII), though your explicit single-pass state flag makes the control flow immediately obvious and avoids any library overhead.
 * - (Optimal Complexity): A single linear scan through `s` of length $N$ runs in $O(N)$ time with strict $O(1)$ auxiliary space.
 * * How it runs:
 * First, we initialize `b_in = 0` to track whether `'b'` has appeared yet.
 * We iterate through each character `c` in `s`: if `c == 'b'`, we set `b_in = 1`; if `b_in == 1` and `c == 'a'`, we immediately return `false`.
 * Finally, if the loop finishes without violations, we return `true` with absolute mathematical precision at raw silicon speed!
 */




class Solution {
public:
    bool checkString(string s) {
        int b_in = 0;
        for(char c : s){
            if(c == 'b'){
                b_in = 1;
            }
            if(b_in == 1 && c == 'a'){
                return false;
            }
        }
        return true;
    }
};
