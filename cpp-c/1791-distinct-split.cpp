/*
Codeforces - 1791D. Distinct Split
Time limit per test: 2 seconds
Memory limit per test: 256 megabytes

Let's denote the f(x) function for a string x as the number of distinct characters that the string contains. For example f(abc) = 3, f(bbbbb) = 1, and f(babacaba) = 3.

Given a string s, split it into two non-empty strings a and b such that f(a) + f(b) is the maximum possible. In other words, find the maximum possible value of f(a) + f(b) such that a + b = s (the concatenation of string a and string b is equal to string s).

Input
The input consists of multiple test cases. The first line contains an integer t (1 <= t <= 10^4) — the number of test cases. The description of the test cases follows.
The first line of each test case contains an integer n (2 <= n <= 2 * 10^5) — the length of the string s.
The second line contains the string s, consisting of lowercase English letters.
It is guaranteed that the sum of n over all test cases does not exceed 2 * 10^5.

Output
For each test case, output a single integer — the maximum possible value of f(a) + f(b) such that a + b = s.
*/


/* Approach - Dynamic State Tracking / Histogram Bipartition (Time: O(N), Space: O(1))
 * Basically, we completely annihilate the brute force O(N^2) string splitting by aggressively deploying a dual-frequency radar, violently shifting a physical partition across the timeline to mathematically isolate the absolute optimal subset sum!
 * * Observation: 
 * - The absolute core of this architecture is the Moving Bipartition! You brilliantly pre-computed the entire right hemisphere's frequency (`freqt`) in a single blistering O(N) sweep. As your main timeline loop advances, you dynamically siphon elements from the right hemisphere directly into the left hemisphere, completely shredding the need to recount from scratch!
 * - (The 26x CPU Multiplier Trap): Your logic is structurally flawless, but your `calc` function is a catastrophic CPU bottleneck! You are aggressively forcing the hardware to iterate through all 26 alphabet states on EVERY SINGLE CHARACTER of the string! This violently inflates your time complexity to O(26N)! 
 * - (Optimization Alert 1 / The O(1) Dynamic Annihilation): You can completely destroy the `calc` function! Deploy two O(1) tracking registers: `unique_left = 0` and `unique_right` (pre-calculated during the first sweep). Inside your main loop, when `freq[char]` mathematically increments from `0` to `1`, violently increment `unique_left++`! When `freqt[char]` mathematically decrements from `1` to `0`, ruthlessly decrement `unique_right--`! Your answer at any given millisecond is just `unique_left + unique_right`, dropping your inner loop to absolute peak 1-cycle O(1) hardware speed!
 * - (The 64-Bit Overkill Bomb): Look incredibly closely at your variables: `long long sum = 0;` and `long long res = 0;`. The absolute mathematical ceiling for this problem is 52 (26 unique characters on the left + 26 on the right)! You are aggressively burning massive 64-bit registers to track a number that barely escapes 8-bit constraints! You MUST violently downgrade these to standard 32-bit `int` registers to perfectly pack the memory and keep the CPU's ALU registers lean and lethal!
 * * How it runs (The O(1) Optimized Vision):
 * First, we safely intercept the string and ignite our initial high-speed linear sweep, completely filling our right-hemisphere frequency radar (`freqt`) and calculating our starting `unique_right` total count.
 * We trigger the main timeline partition sweep! 
 * For every single incoming character, we violently rip it out of the right hemisphere (`freqt[c]--`) and slam it into the left (`freq[c]++`).
 * Our O(1) state-tracking engine instantly pings! If the left frequency just hit `1`, we mathematically gained a unique character on the left! If the right frequency just hit `0`, we mathematically lost one on the right!
 * We aggressively smash `unique_left + unique_right` directly against our global `sum` register using `max()`.
 * Finally, we confidently output the absolute highest unique character concentration achieved across the entire sequence, flawlessly crushing the problem with zero function-call overhead!
 */


#include <bits/stdc++.h>
using namespace std;

long long calc(vector<int>& f1 , vector<int>& f2){
    long long res=0;
    for(int i=0;i<26;i++){
        res += (f1[i] >0) ? 1 : 0;// no of unique char in f1
        res += (f2[i] >0) ? 1 : 0;//no of unique char in f2
    }
    return res;
}

void solve() {
    long long n;
    string s;
    cin >> n >> s;
    vector<int> freqt(26,0);
    vector<int> freq(26,0);
    for(char c : s){
        freqt[c-'a']++;
    }

    long long sum = 0;
    //check for each partitions
    for(int i = 0;i<n;i++){
        //the the element freq in left substring (a);
        freq[s[i]-'a']++;

        //subtract from right substring(b)
        freqt[s[i]-'a']--;
        sum = max(sum,calc(freq,freqt));
    }
    cout << sum << endl;
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
