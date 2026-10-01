/*
Codeforces - 1821B. Sort the Subarray
Time limit per test: 2 seconds
Memory limit per test: 512 megabytes

Monocarp had an array a consisting of n integers. He has decided to choose two integers l and r such that 1 <= l <= r <= n, and then sort the subarray a[l..r] (the subarray a[l..r] is the part of the array a containing the elements a_l, a_{l+1}, a_{l+2}, ..., a_{r-1}, a_r) in non-descending order. After sorting the subarray, Monocarp has obtained a new array, which we denote as a'.

For example, if a = [6, 7, 3, 4, 4, 6, 5], and Monocarp has chosen l = 2, r = 5, then a' = [6, 3, 4, 4, 7, 6, 5].

You are given the arrays a and a'. Find the integers l and r that Monocarp could have chosen. If there are multiple pairs of values (l, r), find the one which corresponds to the longest subarray.

Input
The first line contains one integer t (1 <= t <= 10^4) — the number of test cases.
Each test case consists of three lines:
the first line contains one integer n (2 <= n <= 2 * 10^5);
the second line contains n integers a_1, a_2, ..., a_n (1 <= a_i <= n);
the third line contains n integers a'_1, a'_2, ..., a'_n (1 <= a'_i <= n).

Additional constraints on the input:
the sum of n over all test cases does not exceed 2 * 10^5;
it is possible to obtain the array a' by sorting one subarray of a;
a' != a (there exists at least one position in which these two arrays are different).

Output
For each test case, print two integers — the values of l and r (1 <= l <= r <= n). If there are multiple answers, print the values that correspond to the longest subarray. If there are still multiple answers, print any of them.
*/




/* Approach - Two-Pointer Mismatch Expansion / Subsegment Sorting Window (Time: O(N), Space: O(N))
 * Basically, we completely annihilate brute-force subarray testing by aggressively locating the first and last mismatch indices and expanding outward over non-decreasing boundaries, isolating the exact sorting window in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Subsegment Sorting Invariant (e.g., Codeforces problems requiring finding the minimal subsegment to sort so that an array matches a target or becomes sorted)! When comparing the original array `a` and the target/modified array `a1`, any required modification window must at minimum span from the first mismatch index `l` to the last mismatch index `r`. However, because elements can be equal or allow safe expansion over plateau regions without altering sort order or values, we can greedily expand `l` to the left and `r` to the right as long as the adjacent elements in `a1` remain non-decreasing (`a1[l - 1] <= a1[l]` and `a1[r] <= a1[r + 1]`). This captures the maximal valid bounds for the operation.
 * - (1-Based Output Indexing): Converting the final 0-based pointers (`l`, `r`) to 1-based indices via `l + 1` and `r + 1` matches standard competitive programming output conventions.
 * - (Linear Efficiency): A single mismatch scan followed by two bounded expansion while-loops ensures strict $O(N)$ runtime with minimal vector storage overhead.
 * * How it runs:
 * First, we safely intercept array size `n` and read both vectors `a` and `a1`.
 * We scan from left to right to find the initial mismatch boundaries `l` (first mismatch) and `r` (last mismatch). If no mismatches exist, `l` and `r` remain `-1` (though typical problem constraints guarantee a valid subsegment).
 * We expand `l` leftward while the adjacent elements in `a1` maintain non-decreasing order.
 * We similarly expand `r` rightward while adjacent elements remain non-decreasing.
 * Finally, we flush the optimal 1-based start and end indices to the output stream with absolute mathematical precision at raw silicon speed!
 */



#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define vll vector<ll>

void solve() {
    ll n;
    cin >> n;

    vll a(n), a1(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++) cin >> a1[i];

    ll l = -1, r = -1;

    for(ll i = 0; i < n; i++) {
        if(a[i] != a1[i]) {
            if(l == -1) l = i;
            r = i;
        }
    }

    
    while(l > 0 && a1[l - 1] <= a1[l]) {
        l--;
    }

    
    while(r < n - 1 && a1[r] <= a1[r + 1]) {
        r++;
    }

    cout << l + 1 << " " << r + 1 << "\n";
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
