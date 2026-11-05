/*
Codeforces - 1520D. Same Differences
Time limit per test: 2 seconds
Memory limit per test: 256 megabytes

You are given an array a of n integers. Count the number of pairs of indices (i, j) such that i < j and a_j - a_i = j - i.

Input
The first line contains one integer t (1 <= t <= 10^4). Then t test cases follow.
The first line of each test case contains one integer n (1 <= n <= 2 * 10^5).
The second line of each test case contains n integers a_1, a_2, ..., a_n (1 <= a_i <= n) — array a.
It is guaranteed that the sum of n over all test cases does not exceed 2 * 10^5.

Output
For each test case output the number of pairs of indices (i, j) such that i < j and a_j - a_i = j - i.
*/




/* Approach - Transformed Difference Frequency Counting / Index-Value Mapping Pair Enumeration (Time: O(N), Space: O(N))
 * Basically, we completely annihilate brute-force $O(N^2)$ pair checking by aggressively transforming the condition into a frequency-mapping problem using the difference `a[i] - i` in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Index-Shift Invariance Principle (commonly found in problems where pairs satisfy equations like $a_i - a_j = i - j$ or $a_i - i = a_j - j$)! By rearranging the equation to $a_i - i = a_j - j$, we can track how many times each transformed key has appeared previously using an `unordered_map`. Every time we encounter the same key `k = a[i] - i`, all previous occurrences can form valid pairs with the current element.
 * - (Map Frequency Accumulation): As we iterate through the array, we add `freq[k]` to our running answer `ans` and then increment `freq[k]++`, ensuring that each valid pair is counted exactly once without redundant nested loops.
 * - (Optimal Complexity): A single linear pass through the array with average $O(1)$ hash map operations keeps time complexity at $O(N)$ and auxiliary space at $O(N)$ for the frequency map.
 * * How it runs:
 * First, we read test parameter `n` and populate vector `a`.
 * We initialize our frequency map `freq` and our pair count `ans = 0`.
 * We iterate through each element, compute its transformed key `k = a[i] - i`, accumulate prior frequencies into `ans`, and update the map.
 * Finally, we flush the total valid pair count to the output stream with absolute mathematical precision at raw silicon speed!
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
    ll n;
    cin >> n;
    vll a(n);
    for(ll i =0;i<n;i++){
        cin >>a[i];
    }
    unordered_map<ll ,ll> freq;
    ll ans=0;
    for(ll i=0; i< n;i++){
        int k = a[i]-i;
        ans += freq[k];
        freq[k]++;
    }
    cout << ans << endl;
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
