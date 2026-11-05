/*
Codeforces - 1832C. Contrast Value
Time limit per test: 2 seconds
Memory limit per test: 256 megabytes

For an array of integers [a_1, a_2, ..., a_n], let's call the value |a_1 - a_2| + |a_2 - a_3| + ... + |a_{n-1} - a_n| the contrast of the array. Note that the contrast of an array of size 1 is equal to 0.

You are given an array of integers a. Your task is to build an array of b in such a way that all the following conditions are met:
- b is not empty, i.e there is at least one element;
- b is a subsequence of a, i.e b can be produced by deleting some elements from a (maybe zero);
- the contrast of b is equal to the contrast of a.

What is the minimum possible size of the array b?

Input
The first line contains a single integer t (1 <= t <= 10^4) — the number of test cases.
The first line of each test case contains a single integer n (1 <= n <= 3 * 10^5) — the size of the array a.
The second line contains n integers a_1, a_2, ..., a_n (0 <= a_i <= 10^9) — elements of the array itself.
The sum of n over all test cases doesn't exceed 3 * 10^5.

Output
For each test case, print a single integer — the minimum possible size of the array b.
*/




/* Approach - Adjacent De-duplication and Alternating Extrema Counting / Maximum Alternating Subsequence Length (Time: O(N), Space: O(N))
 * Basically, we completely annihilate brute-force subsequence searches by aggressively collapsing consecutive duplicate elements and counting local extrema (peaks and valleys) in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Alternating Extrema Invariant! First, identical adjacent elements are filtered out into vector `b` because consecutive equal values do not change the direction of an alternating sequence. Then, every strict local peak (`b[i] > b[i-1] && b[i] > b[i+1]`) or local valley (`b[i] < b[i-1] && b[i] < b[i+1]`) marks a directional turning point that must be included to maximize the alternating subsequence length.
 * - (Base Case Handling): If the deduplicated size `m` is less than or equal to 2, the maximum alternating subsequence length is simply `m`. For larger sequences, we start with a base length of 2 and increment `ans` for each valid local extremum found.
 * - (Optimal Complexity): Constructing vector `b` and performing the single linear scan both take $O(N)$ time, with $O(N)$ auxiliary space for the deduplicated storage.
 * * How it runs:
 * First, we read array size `n` and populate vector `a`.
 * We construct vector `b` by discarding consecutive duplicate values from `a`.
 * If `m <= 2`, we output `m`. Otherwise, we initialize `ans = 2` and iterate from `i = 1` to `m - 2`, incrementing `ans` whenever `b[i]` forms a local peak or valley.
 * Finally, we flush the optimal count to the output stream with absolute mathematical precision at raw silicon speed!
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
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }

    vll b;
    for(ll i=0;i<n;i++){
        if(b.empty() || b.back() != a[i]){
            b.push_back(a[i]);
        }
    }

    ll m = b.size();

    if(m <= 2){
        cout << m << endl;
        return;
    }

    ll ans =2;
    for(ll i= 1;i<m-1;i++){
        if((b[i] > b[i-1] && b[i] > b[i+1]) || (b[i] < b[i-1] && b[i] < b[i+1])){
            ans++;
        }
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
