/*
Codeforces - 1827A. Counting Orders
Time limit per test: 1 second
Memory limit per test: 256 megabytes

You are given two arrays a and b each consisting of n integers. All elements of a are pairwise distinct.

Find the number of ways to reorder a such that a_i > b_i for all 1 <= i <= n, modulo 10^9 + 7.
Two ways of reordering are considered different if the resulting arrays are different.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1 <= t <= 10^4). The description of the test cases follows.
The first line of each test case contains a single integer n (1 <= n <= 2 * 10^5) — the length of the array a and b.
The second line of each test case contains n distinct integers a_1, a_2, ..., a_n (1 <= a_i <= 10^9) — the array a. It is guaranteed that all elements of a are pairwise distinct.
The second line of each test case contains n integers b_1, b_2, ..., b_n (1 <= b_i <= 10^9) — the array b.
It is guaranteed that the sum of n over all test cases does not exceed 2 * 10^5.

Output
For each test case, output the number of ways to reorder array a such that a_i > b_i for all 1 <= i <= n, modulo 10^9 + 7.
*/



 /* Approach - Sorting with Upper Bound Binary Search and Modular Combinatorics (Time: O(N log N), Space: O(N))
 * Basically, we completely annihilate brute-force pairing permutations by aggressively sorting arrays and leveraging upper-bound binary search with modular arithmetic in pristine log-linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Monotonic Permutation Matching Invariant! By sorting array `a` in ascending order and array `b` in descending order, we can efficiently determine how many valid elements in `a` are strictly greater than each element in `b` using `std::upper_bound`. As we iterate through `b`, subtracting our current loop index `i` accounts for elements from `a` that have already been paired up with larger elements, ensuring correct combinatorial counting without overcounting.
 * - (Modular Arithmetic Safety): Multiplying the running product `res` by each choice count modulo `10^9 + 7` (`MOD`) at every step prevents integer overflow while correctly preserving product properties required by combinatorics problems.
 * - (Safe Non-Negative Bounds): Using `max(count - i, 0LL)` guarantees that if the available valid elements drop to zero, we multiply by `0` instead of a negative offset, gracefully handling edge cases where no choices remain.
 * * How it runs:
 * First, we safely intercept array size `n` and read elements into vectors `a` and `b`.
 * We sort `a` ascending and `b` descending to establish optimal monotonic matching properties.
 * We ignite a linear scan across `b`, using binary search (`upper_bound`) to find how many elements in `a` exceed `b[i]`.
 * We calculate available choices by subtracting index `i`, accumulating the total ways modulo `10^9 + 7`.
 * Finally, we flush the final permutation product to the output stream with absolute mathematical precision at raw silicon speed!
 */


#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define F first
#define MOD (ll)(1e9+7)
#define S second

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve() {
    ll n;
    cin >> n;
    vll a(n),b(n);
    for(ll i=0;i<n;i++)cin >> a[i];
    for(ll i=0;i<n;i++)cin >> b[i];

    sort(a.begin(),a.end());
    sort(b.rbegin(),b.rend());

    ll res = 1;

    for(ll i=0;i<n;i++){
        ll temp = upper_bound(a.begin(),a.end(),b[i])-a.begin();
        ll count = a.size() - temp;

        res = res*max(count -i,0LL)%MOD;
    }

    cout << res << endl;
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
