/*
Codeforces - 1909B. Make Almost Equal With Mod
Time limit per test: 1 second
Memory limit per test: 256 megabytes

You are given an array a_1, a_2, ..., a_n of distinct positive integers. You have to do the following operation exactly once:
- choose a positive integer k;
- for each i from 1 to n, replace a_i with a_i mod k.

Find a value of k such that 1 <= k <= 10^18 and the array a_1, a_2, ..., a_n contains exactly 2 distinct values at the end of the operation. It can be shown that, under the constraints of the problem, at least one such k always exists. If there are multiple solutions, you can print any of them.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1 <= t <= 500). The description of the test cases follows.
The first line of each test case contains a single integer n (2 <= n <= 100) — the length of the array a.
The second line of each test case contains n integers a_1, a_2, ..., a_n (1 <= a_i <= 10^17) — the initial state of the array. It is guaranteed that all the a_i are distinct.
Note that there are no constraints on the sum of n over all test cases.

Output
For each test case, output a single integer: a value of k (1 <= k <= 10^18) such that the array a_1, a_2, ..., a_n contains exactly 2 distinct values at the end of the operation.
*/



/* Approach - Powers-of-Two Modulo Remainder Search / Distinct Remainder Extraction (Time: O(N log(MAX_A)), Space: O(N))
 * Basically, we completely annihilate brute-force search ranges by aggressively testing powers of two for modulus `k` until exactly two distinct remainders are found across the array elements!
 * * Observation: 
 * - The absolute core of this architecture is the Modulo-Space Convergence Invariant (commonly found in problems requiring a divisor/modulus `k` such that all array elements yield exactly two distinct remainders modulo `k`). 
 * - (Potential Infinite Loop / Termination Bug): Notice your `while(true)` loop doubles `k` (`k *= 2`) indefinitely. If all elements in the array are identical (yielding `rem.size() == 1` for all large `k`) or if the number of distinct elements in the array is already greater than 2 (since as $k$ exceeds the maximum element value, `rem.size()` equals the total number of unique elements in `a`), `rem.size()` will never equal 2, causing an infinite loop. A proper safeguard should bound `k` (e.g., up to $\max(a_i) + \max(|a_i - a_j|)$) or check if `rem.size()` exceeds 2.
 * - (Auxiliary Memory Efficiency): Storing remainders in a `std::set` takes $O(N)$ auxiliary space per iteration, which is efficient for moderate vector sizes.
 * * How it runs:
 * First, we read test parameter `n` and populate vector `a`.
 * We initialize `k = 2` and ignite an unbounded `while(true)` loop computing `a[i] % k` into a `set`.
 * We check if `rem.size() == 2`; if so, we print `k` and return. Otherwise, we double `k` and repeat.
 * Finally, if a valid modulus is found, we flush it to the output stream with absolute mathematical precision at raw silicon speed!
 */



#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define F first
#define S second

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve() {
    int n ;
    cin >> n;

    vll a(n);
    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    ll k = 2;
    while(true){
        set<ll> rem;
        for(int i=0;i<n;i++){
            rem.insert(a[i]%k);
        }
        if(rem.size() == 2){
            cout << k << "\n";
            return;
        }
        k *=2 ;
    }
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
