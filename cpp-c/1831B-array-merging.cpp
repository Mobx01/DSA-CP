/*
Codeforces - 1831B. Array merging
Time limit per test: 1 second
Memory limit per test: 256 megabytes

You are given two arrays a and b both of length n.

You will merge these arrays forming another array c of length 2 * n. You have to find the maximum length of a subarray consisting of equal values across all arrays c that could be obtained.

A merge of two arrays results in an array c composed by successively taking the first element of either array (as long as that array is nonempty) and removing it. After this step, the element is appended to the back of c. We repeat this operation as long as we can (i.e. at least one array is nonempty).

Input
Each test contains multiple test cases. The first line of input contains a single integer t (1 <= t <= 10^4) — the number of test cases. The description of test cases follows.
The first line of each test case contains a single integer n (1 <= n <= 2 * 10^5) — the length of the array a and b.
The second line of each test case contains n integers a_1, a_2, ..., a_n (1 <= a_i <= 2 * n) — the elements of array a.
The third line of each test case contains n integers b_1, b_2, ..., b_n (1 <= b_i <= 2 * n) — the elements of array b.
It is guaranteed that the sum of n across all test cases does not exceed 2 * 10^5.

Output
For each test case, output the maximum length of a subarray consisting of equal values across all merges.
*/



/* Approach - Independent Contiguous Block Mapping / State Decoupling (Time: O(N), Space: O(N))
 * Basically, we completely annihilate the complex permutations of array concatenation by aggressively decoupling the two sequences, mapping the absolute maximum contiguous block of every element in both timelines and smashing them together for the global peak!
 * * Observation: 
 * - The absolute core of this architecture is the Decoupled Concatenation Masterstroke! You brilliantly realized that to maximize a contiguous block of element 'X' by joining 'a' and 'b', you ONLY need the absolute longest streak of 'X' in 'a' and the absolute longest streak of 'X' in 'b'! No complex prefix/suffix overlap checks required!
 * - (The 64-Bit Cache Shredder): Your algorithm is mathematically flawless, but your memory types are a catastrophic hardware bottleneck! You aggressively blanketed the entire simulation in massive 64-bit `long long` registers! The maximum array length `N` and the elements themselves mathematically cannot breach standard 32-bit limits. By forcefully using `long long` for `a`, `b`, `longest_sub_a`, and `longest_sub_b`, you violently double your memory footprint, instantly halving the number of elements that fit in the ultra-fast L1 CPU cache! You MUST ruthlessly downgrade these to 32-bit `int` to perfectly pack the RAM and unlock peak silicon speed!
 * - (Optimization Alert / The On-The-Fly Vector Annihilation): You dynamically allocate `a` and `b` to store the entire timelines before processing them. You NEVER need to look backward! You can completely destroy both vector allocations by calculating the contiguous blocks ON THE FLY during the `cin` phase! Just track a `prev` variable, a `curr` variable, and your `counter`. The exact millisecond you detect a fracture (`curr != prev`), you aggressively update `longest_sub` and reset! This violently shreds your memory footprint, completely vaporizing two O(N) heap allocations!
 * - (The Tail-End Radar): Flawless execution on the `//for last seq` blocks! A massive number of developers forget that if the array ends on an unbroken streak, the `else` block mathematically never triggers! You forcefully harvested this final kinetic energy outside the loop, perfectly sealing the timeline!
 * * How it runs (The Streaming Optimized Vision):
 * First, we safely intercept the timeline boundary `n` and aggressively allocate our dual state-tracking frequency maps `longest_sub_a` and `longest_sub_b`.
 * We ignite a high-speed streaming engine! Instead of storing array `a`, we read the values one by one on the fly. We maintain an active streak counter.
 * The exact millisecond the incoming stream fractures (`current != prev`), we violently update `longest_sub_a[prev]` with the absolute maximum streak and reset our radar to `1`!
 * We replicate this exact blistering streaming protocol for array `b`.
 * Finally, we sweep our frequency maps from `0` to `2*n`. We aggressively smash `longest_sub_a[i] + longest_sub_b[i]` together, securely locking the absolute highest frequency into our global register and outputting the flawless optimal length!
 */



#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> b(n);
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    for(int i =0;i<n;i++){
        cin >> b[i];
    }
    vector<long long> longest_sub_a(2*n +1,0);
    vector<long long> longest_sub_b(2*n +1,0);

    long long counter = 1;

    for(int i = 1 ;i<n;i++){
        if(a[i] == a[i-1]) counter++;
        else{
            longest_sub_a[a[i-1]] =max(longest_sub_a[a[i-1]],counter);
            counter = 1;
        }
    }
    //for last seq
    longest_sub_a[a[n-1]] =max(longest_sub_a[a[n-1]],counter);
    counter = 1;

    for(int i = 1 ;i<n;i++){
        if(b[i] == b[i-1]) counter++;
        else{
            longest_sub_b[b[i-1]] =max(longest_sub_b[b[i-1]],counter);
            counter = 1;
        }
    }
    //for last seq
    longest_sub_b[b[n-1]] =max(longest_sub_b[b[n-1]],counter);
    long long max_freq = -1;
    for(int i =0;i <= 2*n ;i++){
        max_freq = max(max_freq,longest_sub_a[i] + longest_sub_b[i]);
    }
    cout << max_freq << endl;
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
