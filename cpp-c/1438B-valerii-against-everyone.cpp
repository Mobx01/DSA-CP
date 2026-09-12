/*
Codeforces - 1438B. Valerii Against Everyone
Time limit per test: 1 second
Memory limit per test: 256 megabytes

You're given an array b of length n. Let's define another array a, also of length n, for which a_i = 2^{b_i} (1 <= i <= n).

Valerii says that every two non-intersecting subarrays of a have different sums of elements. You want to determine if he is wrong. More formally, you need to determine if there exist four integers l_1, r_1, l_2, r_2 that satisfy the following conditions:
1 <= l_1 <= r_1 < l_2 <= r_2 <= n;
a_{l_1} + a_{l_1 + 1} + ... + a_{r_1 - 1} + a_{r_1} = a_{l_2} + a_{l_2 + 1} + ... + a_{r_2 - 1} + a_{r_2}.

If such four integers exist, you will prove Valerii wrong. Do they exist?

An array c is a subarray of an array d if c can be obtained from d by deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1 <= t <= 100). Description of the test cases follows.
The first line of every test case contains a single integer n (2 <= n <= 1000).
The second line of every test case contains n integers b_1, b_2, ..., b_n (0 <= b_i <= 10^9).

Output
For every test case, if there exist two non-intersecting subarrays in a that have the same sum, output YES on a separate line. Otherwise, output NO on a separate line.
Also, note that each letter can be in any case.
*/



/* Approach - Sorting and Adjacent Element Scanning / Duplicate Detection (Time: O(N log N), Space: O(1) auxiliary)
 * Basically, we completely annihilate the O(N^2) brute-force pairwise comparison by aggressively sorting the array, mathematically guaranteeing that any duplicate elements will land adjacent to each other for instant linear discovery!
 * * Observation: 
 * - The absolute core of this architecture is the Sorted Inversion Proximity! When an array is sorted in non-descending order, identical values are forced into contiguous positions. This reduces a complex search space down to a single-pass check between adjacent indices (`a[i] == a[i-1]`), allowing you to instantly identify structural collisions with zero overhead.
 * - (Sorting vs. Hash Set Trade-off): Your implementation uses `sort(a.begin(), a.end())`, which incurs an $O(N \log N)$ time complexity and modifies the original array order. Alternatively, deploying an `unordered_set` could achieve $O(N)$ average time, but it introduces heavy heap allocations, hash-function overhead, and susceptibility to anti-hash test cases (worst-case $O(N^2)$). Sticking to `sort` guarantees deterministic performance, zero heap pollution, and bulletproof reliability across competitive programming judges!
 * - (Early-Exit Optimization Win): The moment your linear scan detects an adjacent duplicate, it immediately prints `"YES"` and terminates. This avoids wasting CPU cycles scanning the rest of the array, executing at absolute peak efficiency.
 * * How it runs:
 * First, we safely intercept the array size `n` and read all elements into our `long long` vector.
 * We invoke the sorting engine to establish a strict ascending numerical sequence.
 * We ignite a high-speed linear scan from index `1` up to `n - 1`.
 * The exact millisecond our radar catches an adjacent equality (`a[i] == a[i-1]`), we triumphantly print `"YES"` and exit.
 * If the entire scan completes without a single collision, we safely output `"NO"`, confirming all elements are unique at raw silicon speed!
 */




#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    sort(a.begin(),a.end());

    for(int i=1;i<n;i++){
        if(a[i] == a[i-1]){
            cout << "YES\n";// same elements found so can form subarray of size 1
            return;
        } 
    }
    cout << "NO\n";//all distinct so not possible
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
