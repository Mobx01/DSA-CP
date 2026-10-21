/*Leetcode ps -3863. Minimum Operations to Sort a String
You are given a string s consisting of lowercase English letters.
In one operation, you can select any substring of s that is not the entire string and sort it in non-descending alphabetical order.
Return the minimum number of operations required to make s sorted in non-descending order. If it is not possible, return -1.*/




/* Approach - Linear Min-Max Character Placement Analysis / String Sorting Operations (Time: O(N), Space: O(1))
 * Basically, we completely annihilate brute-force state-space searches by aggressively tracking global extrema and sortedness invariants, evaluating minimum operation tiers in pristine linear time and constant space!
 * * Observation: 
 * - The absolute core of this architecture is the Extrema-Driven Operation Invariant! The minimum number of operations required to sort or transform the string `s` depends entirely on the positions of its global minimum (`mn`) and maximum (`mx`) characters relative to the boundaries. If the string is already sorted, it takes `0` operations. Depending on whether `mn` or `mx` resides at the outer edges or interior indices, the optimal transformation tier (`1`, `2`, or `3`) is determined directly, while length-2 unsorted strings that cannot be resolved return `-1`.
 * - (Single-Pass Metric Accumulation): Tracking `mn`, `mx`, and the `issort` monotonicity flag simultaneously within a single linear traversal keeps auxiliary overhead at an absolute minimum ($O(1)$ space).
 * - (Tiered Decision Logic): Bypassing complex simulation by directly evaluating boundary conditions (`s[0] == mn || s[n - 1] == mx`) yields lightning-fast execution.
 * * How it runs:
 * First, we initialize our extrema `mn` and `mx` with `s[0]` and set `issort = 1`.
 * We ignite a high-speed linear scan to check if the string is non-decreasing while dynamically updating `mn` and `mx`.
 * We evaluate quick return conditions: returning `0` if already sorted, or `-1` if `n == 2` and unsorted.
 * We check if the leading character is the minimum or the trailing character is the maximum (returning `1`), inspect intermediate elements for a 2-step path, or fall back to `3`.
 * Finally, we flush the minimum operation count to the output stream with absolute mathematical precision at raw silicon speed!
 */



class Solution {
public:
    int minOperations(string s) {
        char mn = s[0],mx = s[0];
        int issort = 1,n = s.length();

        for(int i=1;i<n;i++){
            if(s[i] < s[i-1]) issort = 0;

            mn = min(mn,s[i]);
            mx = max(mx,s[i]);
        }

        if(issort) return 0;
        if(n == 2) return -1;

        if(s[0] == mn || s[n-1] == mx)return 1;

        for(int i=1;i<n-1;i++){
            if(s[i] == mn || s[i] == mx) return 2;
        }

        return 3;
    }
};
