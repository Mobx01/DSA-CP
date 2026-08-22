/*
Codeforces - 1373B. 01 Game
Time limit per test: 1 second
Memory limit per test: 256 megabytes

Alica and Bob are playing a game.
Initially they have a binary string s consisting of only characters 0 and 1.

Alice and Bob make alternating moves: Alice makes the first move, Bob makes the second move, Alice makes the third one, and so on. During each move, the current player must choose two different adjacent characters of string s and delete them. For example, if s = 1011001 then the following moves are possible:
delete s_1 and s_2: 1011001 -> 11001;
delete s_2 and s_3: 1011001 -> 11001;
delete s_4 and s_5: 1011001 -> 10101;
delete s_6 and s_7: 1011001 -> 10110.

If a player can't make any move, they lose. Both players play optimally. You have to determine if Alice can win.

Input
First line contains one integer t (1 <= t <= 1000) — the number of test cases.
Only line of each test case contains one string s (1 <= |s| <= 100), consisting of only characters 0 and 1.

Output
For each test case print answer in the single line.
If Alice can win print DA (YES in Russian) in any register. Otherwise print NET (NO in Russian) in any register.
*/


/* Approach - Pure Game Theory / Parity Collapse (Time: O(N), Space: O(N) for string)
 * Basically, we completely annihilate the catastrophic O(N^2) string simulation by violently collapsing the entire game into a pure mathematical parity check, perfectly predicting the winner in a single blistering O(N) sweep!
 * * Observation: 
 * - The absolute core of this game theory puzzle is the deletion mechanic! Every single valid move mathematically REQUIRES exactly one '0' and exactly one '1'. This structurally guarantees that the absolute maximum number of moves the universe will allow is strictly bottle-necked by the rarer character!
 * - (The Absolute Game-Breaker / Timeline Bypass): You brilliantly bypassed the physical simulation! You didn't waste CPU cycles frantically searching for adjacent "01" or "10" substrings to erase and shift the array. You mathematically proved that the physical order of the string is completely irrelevant! As long as a '0' and a '1' exist anywhere, they will eventually collapse against each other. Thus, the total possible moves is flawlessly locked to `min(count0, count1)`!
 * - (The Parity Math): Since the first player (Alice) always strikes first, she wins if and only if the total timeline of valid moves is an odd number! An even timeline mathematically forces the second player (Bob) to land the final devastating blow!
 * - (Optimization Alert 1 / The Redundant Counter Nuke): You deployed a manual `if-else` block to track both zeros and ones. You can completely annihilate `count1`! Since the string ONLY contains binary characters, `count1` is mathematically bound to `s.length() - count0`! You only need to count one dimension to instantly deduce the other!
 * - (Optimization Alert 2 / The STL & Bitwise Upgrade): You can completely shred the `for` loop by deploying the C++ standard library: `int count0 = count(s.begin(), s.end(), '0');`. Then, instantly upgrade your final conditional from the clunky modulo `op % 2 == 1` to the raw hardware bitwise mask `if (op & 1)` to execute the parity check in a blistering O(1) CPU cycle!
 * * How it runs:
 * First, we safely intercept the binary string `s` using our high-speed I/O engine.
 * We instantly ignite a linear sweep across the string, aggressively categorizing every single character to lock in the total mass of '0's and '1's.
 * We trigger a violent collision between the two counters using the `min()` function, mathematically isolating the absolute bottleneck of the timeline (the maximum possible turns).
 * Finally, we forcefully smash the bottleneck against the parity engine! If the exact number of operations is odd, Alice's dominance is mathematically secured, and we violently print "DA"! Otherwise, the timeline completely collapses in Bob's favor, and we confidently output "NET"!
 */


#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int count0=0,count1=0;
    for(char  c : s){
        if(c =='0') count0 ++;
        else count1++;
    }
    int op = min(count0,count1);
    

    if(op % 2 == 1) cout<< "DA\n";
    else cout << "NET\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();  
    }
    return 0;
}
