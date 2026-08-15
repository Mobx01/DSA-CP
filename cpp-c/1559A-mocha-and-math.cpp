/*
Codeforces - 1559A. Mocha and Math
Time limit per test: 1 second
Memory limit per test: 256 megabytes

Mocha is a young girl from high school. She has learned so much interesting knowledge from her teachers, especially her math teacher. Recently, Mocha is learning about binary system and very interested in bitwise operation.

This day, Mocha got a sequence a of length n. In each operation, she can select an arbitrary interval [l, r] and for all values i (0 <= i <= r - l), replace a_{l+i} with a_{l+i} & a_{r-i} at the same time, where & denotes the bitwise AND operation. This operation can be performed any number of times.

For example, if n = 5, the array is [a_1, a_2, a_3, a_4, a_5], and Mocha selects the interval [2, 5], then the new array is [a_1, a_2 & a_5, a_3 & a_4, a_4 & a_3, a_5 & a_2].

Now Mocha wants to minimize the maximum value in the sequence. As her best friend, can you help her to get the answer?

Input
Each test contains multiple test cases.
The first line contains a single integer t (1 <= t <= 100) — the number of test cases. Each test case consists of two lines.
The first line of each test case contains a single integer n (1 <= n <= 100) — the length of the sequence.
The second line of each test case contains n integers a_1, a_2, ..., a_n (0 <= a_i <= 10^9).

Output
For each test case, print one integer — the minimal value of the maximum value in the sequence.
*/

/* Approach - Pure Bitwise Accumulation / Global AND Reduction (Time: O(N), Space: O(N))
 * Basically, we aggressively sweep the array, relentlessly smashing every single element together using the bitwise AND operator to violently strip away any unshared bits, isolating the absolute mathematical intersection of the entire sequence!
 * * Observation: 
 * - The absolute core property of the bitwise AND (`&`) is that it is mathematically strictly non-increasing! Every time you introduce a new number to the running total, bits can ONLY turn from `1` to `0`. 
 * - A set bit (`1`) will ONLY survive this absolute gauntlet if it physically exists as a `1` in every single element across the entire array! The global AND perfectly isolates the core bits unconditionally shared by the entire sequence.
 * - (Optimization Alert / The O(1) Memory Upgrade): Just like in previous array sweeps, you allocated a massive `vector<long long>` that aggressively burns O(N) memory just to hold the data for a single mathematical reduction! You can instantly annihilate the space complexity down to absolute peak O(1) by completely deleting the vector! Simply run `cin >> total_and` for the first element, then loop `n-1` times, reading into a temporary variable `cin >> temp` and immediately executing `total_and &= temp` on the fly!
 * * How it runs:
 * First, we safely extract our array size `n` and trigger our fast I/O engine to ingest the entire sequence into our memory vector.
 * Then, we securely anchor our baseline `total_and` exactly to the very first element `a[0]`.
 * Next, we ignite a high-speed linear sweep across the array. For every single element, we violently smash it against our running `total_and` using the bitwise AND assignment (`&=`)! This ruthlessly and permanently zeroes out any bit that dares to be a `0` in the current number!
 * Finally, the exact millisecond the sweep finishes, every single unshared bit has been structurally eradicated. We confidently print the surviving `total_and` value, flawlessly delivering the absolute global intersection in a single blistering O(N) pass!
 */


#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    long long total_and= a[0];
    for(long long i : a){
        total_and &= i;
    }
    cout << total_and << endl;
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
