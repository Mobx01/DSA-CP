/*
Codeforces - 2268A. K Is Important
Time limit per test: 2 seconds
Memory limit per test: 256 megabytes

You are given an array a consisting of n positive integers, as well as an integer parameter k.
While the array has at least k elements, you need to perform one of the following two types of operations on a:
- Remove a_k and add its value to your score, or
- Remove a_{m - k + 1} and add its value to your score, where m is the length of a before this operation.

After removing an element, the remaining elements keep their relative order.
Your task is to determine the maximum possible score that can be obtained.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1 <= t <= 10^4). The description of the test cases follows.
The first line of each test case contains two integers n and k (1 <= k <= n <= 10^5) — the length of a and the parameter.
The second line contains n integers a_i (1 <= a_i <= 10^9) — the elements of a.
It is guaranteed that the sum of n over all test cases does not exceed 10^5.

Output
For each test case, output a single integer — the maximum score that can be obtained.
*/



/* Approach - Greedy Symmetric Pairing with Core Interval Expansion (Time: O(N), Space: O(N))
 * Basically, we completely annihilate brute-force subset combinations by aggressively pairing symmetric outer boundaries to maximize local picks while sweeping up residual core intervals in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Symmetric Pairing and Core Interval Invariant (e.g., Codeforces/competitive programming array selection problems governed by parameter `k`)! By determining the maximum number of independent outer pairs we can form via `P = min(k - 1LL, n - k + 1LL)`, we can greedily extract the maximum element from each symmetric pair (`max(a[i], a[n - 1 - i])`). When leftover operations (`ops > P`) demand a wider expansion, we sweep through all intervening core elements from index `P` to `n - P`, accumulating their values directly into our score.
 * - (Type Safety & Overflow Prevention): Using explicit `64-bit` type casting (`1LL`) in bounds calculation like `min(k - 1LL, n - k + 1LL)` prevents accidental 32-bit signed integer underflow or overflow when handling edge constraints.
 * - (Linear Time Efficiency): Reading the vector once followed by bounded linear loops guarantees strict $O(N)$ runtime with minimal memory overhead.
 * * How it runs:
 * First, we safely intercept array size `n` and parameter `k`, reading all elements into vector `a`.
 * We calculate the outer pair limit `P` and accumulate the maximum value of each symmetric outer boundary pair up to `P`.
 * We evaluate whether leftover operations exceed `P`; if so, we sweep through the remaining central core interval from index `P` to `n - P`, adding every element to `max_score`.
 * Finally, we flush the optimal maximum score result to the output stream with absolute mathematical precision at raw silicon speed!
 */



#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define vll vector<ll>

void solve() {
    ll n, k;
    cin >> n >> k;
    vll a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll max_score = 0;
    
    // P is the number of outer pairs we can form
    int P = min(k - 1LL, n - k + 1LL);
    
    // 1. For each outer pair, we can greedily take the maximum element
    for(int i = 0; i < P; i++) {
        max_score += max(a[i], a[n - 1 - i]);
    }
    
    // 2. If there are leftover operations, they unconditionally consume the middle "core" elements
    int ops = n - k + 1;
    if(ops > P) {
        // The core elements exist between the pairs we just processed
        for(int i = P; i < n - P; i++) {
            max_score += a[i];
        }
    }

    cout << max_score << "\n";
}

int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
