/*
Codeforces - 1659A. Red Versus Blue
Time limit per test: 1 second
Memory limit per test: 256 megabytes

Team Red and Team Blue competed in a competitive FPS. Their match was streamed around the world. They played a series of n matches.

In the end, it turned out Team Red won r times and Team Blue won b times. Team Blue was less skilled than Team Red, so b was strictly less than r.

You missed the stream since you overslept, but you think that the match must have been neck and neck since so many people watched it. So you imagine a string of length n where the i-th character denotes who won the i-th match — it is R if Team Red won or B if Team Blue won. You imagine the string was such that the maximum number of times a team won in a row was as small as possible. For example, in the series of matches RBBRRRB, Team Red won 3 times in a row, which is the maximum.

You must find a string satisfying the above conditions. If there are multiple answers, print any.

Input
The first line contains a single integer t (1 <= t <= 1000) — the number of test cases.
Each test case has a single line containing three integers n, r, and b (3 <= n <= 100; 1 <= b < r <= n, r + b = n).

Output
For each test case, output a single line containing a string satisfying the given conditions. If there are multiple answers, print any.
*/



/* Approach - Pigeonhole Uniform Distribution / Block-Level String Construction (Time: O(N), Space: O(N) allocation)
 * Basically, we completely annihilate the combinatorial search space by aggressively applying the Pigeonhole Principle, mathematically distributing 'R's evenly across 'b + 1' structural cavities to strictly minimize the maximum contiguous block!
 * * Observation: 
 * - The absolute core of this architecture is the Balanced Gap Partition! When you place `b` blue items down, they naturally carve out exactly `b + 1` independent slots for red items. To minimize the maximum size of any red block, you must distribute the `r` items as evenly as possible using integer division (`r / (b + 1)`) and spread the remainder (`r % (b + 1)`) one by one into the earliest slots!
 * - (The Fatal String Reallocation Bomb): Your mathematical logic is absolute textbook perfection, but your string construction is a silent performance assassin! You initialize `string s = ""` and aggressively append characters using `.push_back()`. As the string grows beyond its small buffer optimization (SBO) threshold, the heap violently reallocates memory, copying the entire buffer over and over again! For large `n`, this burns massive CPU cycles. You MUST instantly pre-allocate the exact memory footprint using `s.reserve(n);` or `string s(n, ' ');` to lock in a single contiguous RAM block!
 * - (Optimization Alert / The Block-Writer Nuke): Instead of running a nested loop to append individual `'R'` characters one by one, you can completely vaporize the inner loops by leveraging `string::append(count, 'R')` or direct constructor fills! This allows the compiler and standard library to invoke high-speed, vectorized block-memory operations rather than iterative scalar pushes, blazing through string construction at raw silicon speed!
 * * How it runs:
 * First, we safely intercept the counts and calculate our structural cavities (`groups = b + 1`), instantly deriving the `base_r` uniform weight and `extra_r` remainder.
 * We (ideally) pre-allocate our string capacity to shield the heap from fragmentation.
 * We ignite a high-speed linear loop, iterating `b` times. For each cavity, we dynamically calculate the exact red count, inject the block into the string, and lay down a structural `'B'` separator.
 * Finally, we append the remaining trailing red block, and output the fully forged string with absolute mathematical precision!
 */



#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n, r, b;
    cin >> n >> r >> b;
    
    int groups = b + 1;
    int base_r = r / groups;
    int extra_r = r % groups;
    
    string s = "";
    
    for (int i = 0; i < b; i++) {
        // Add red characters for this group (distribute extra_r one by one)
        int count = base_r + (i < extra_r ? 1 : 0);
        for (int j = 0; j < count; j++) {
            s.push_back('R');
        }
        s.push_back('B');
    }
    
    // Add the final group of red characters
    int final_count = base_r + (b < extra_r ? 1 : 0);
    for (int j = 0; j < final_count; j++) {
        s.push_back('R');
    }
    
    cout << s << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t ;
    cin >> t; 
    while(t--) {
        solve();  
    }
    return 0;
}
