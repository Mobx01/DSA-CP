/*
Codeforces - 1631B. Fun with Even Subarrays
Time limit per test: 1 second
Memory limit per test: 256 megabytes

You are given an array a of n elements. You can apply the following operation to it any number of times:
- Select some subarray from a of even size 2k that begins at position l (1 <= l <= l + 2 * k - 1 <= n, k >= 1) and for each i between 0 and k - 1 (inclusive), assign the value a_{l+k+i} to a_{l+i}.

For example, if a = [2, 1, 3, 4, 5, 3], then choose l = 1 and k = 2, applying this operation the array will become a = [3, 4, 3, 4, 5, 3].

Find the minimum number of operations (possibly zero) needed to make all the elements of the array equal.

Input
The input consists of multiple test cases. The first line contains a single integer t (1 <= t <= 2 * 10^4) — the number of test cases. Description of the test cases follows.
The first line of each test case contains an integer n (1 <= n <= 2 * 10^5) — the length of the array.
The second line of each test case consists of n integers a_1, a_2, ..., a_n (1 <= a_i <= n) — the elements of the array a.
It is guaranteed that the sum of n over all test cases does not exceed 2 * 10^5.

Output
Print t lines, each line containing the answer to the corresponding test case — the minimum number of operations needed to make equal all the elements of the array with the given operation.
*/




/* Approach - Greedy Suffix Doubling / Uniform Block Expansion (Time: O(N), Space: O(N))
 * Basically, we completely annihilate brute-force simulation by aggressively tracking uniform suffix lengths and doubling matched blocks via greedy operation counts in pristine sub-linear/linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Suffix Expansion Invariant! The algorithm targets the end of the array (`a[n - 1]`), checking whether preceding elements match the target value. When the adjacent element matches (`a[n - 1 - len] == a[n - 1]`), it increments `len++`. When it doesn't, it incurs an operation (`ops++`) and doubles the matched block length (`len *= 2`), assuming the current uniform segment can be replicated.
 * - (Block Uniformity & Doubling Validation): Note that doubling `len` via `len *= 2` relies on the invariant that the current suffix of length `len` consists entirely of valid replicable elements. Ensuring that boundary conditions (such as `n - 1 - len` remaining within valid vector bounds during multiplication jumps) are safely guarded prevents out-of-bounds access.
 * - (Optimal Time Efficiency): Because `len` grows either additively (by 1) or multiplicatively (doubling), the loop terminates efficiently in $O(N)$ time (or logarithmic steps for pure doubling), with $O(N)$ space to store the array.
 * * How it runs:
 * First, we read vector size `n` and populate array `a`.
 * We initialize our operation counter `ops = 0` and our initial matched suffix length `len = 1`.
 * We ignite a `while (len < n)` loop: if the preceding element matches the target value at `a[n - 1]`, we expand `len++`; otherwise, we increment `ops` and double `len`.
 * Finally, we flush the total operation count to the output stream with absolute mathematical precision at raw silicon speed!
 */



#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int ops = 0;
    int len = 1;
    
    
    while (len < n) {
        if (a[n - 1 - len] == a[n - 1]) {
            len++;
        } else {
            ops++;
            len *= 2;
        }
    }

    cout << ops << "\n";
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
