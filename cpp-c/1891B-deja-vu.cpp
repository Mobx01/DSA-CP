/*
Codeforces - 1891B. Deja Vu
Time limit per test: 2 seconds
Memory limit per test: 256 megabytes

You are given an array a of length n, consisting of positive integers, and an array x of length q, also consisting of positive integers.

There are q modification. On the i-th modification (1 <= i <= q), for each j (1 <= j <= n), such that a_j is divisible by 2^{x_i}, you add 2^{x_i - 1} to a_j. Note that x_i (1 <= x_i <= 30) is a positive integer not exceeding 30.

After all modification queries, you need to output the final array.

Input
The first line contains a single integer t (1 <= t <= 10^4) — the number of test cases. The description of the test cases follows.
The first line of each test case contains two integers n and q (1 <= n, q <= 10^5) —the length of the array a and the number of queries respectively.
The second line of each test case contains n integers a_1, a_2, a_3, ..., a_n — the elements of the array a (1 <= a_i <= 10^9).
The third line of each test case contains q integers x_1, x_2, x_3, ..., x_q — the elements of the array x (1 <= x_i <= 30), which are the modification queries.
It is guaranteed that the sum of n and the sum of q across all test cases does not exceed 2 * 10^5.

Output
For each test case, output the array after all of the modification queries.
*/




/* Approach - Filtered Query Optimization with Power-of-2 Divisibility Mutation (Time: O(Q * N) worst-case with pruning, Space: O(N + Q))
 * Basically, we completely annihilate redundant query overhead by aggressively tracking a decreasing threshold (`prev`), skipping larger or duplicate power-of-2 query steps that are already subsumed by finer operations!
 * * Observation: 
 * - The absolute core of this architecture is the Monotonic Query Filtering Invariant! In problems where operations involve dividing by powers of 2 (`val = 2^x`), processing larger query exponents after smaller ones can be redundant because smaller exponents (stricter divisibility) already alter the low-order bit structure. By maintaining `prev = 31` and skipping any query where `prev <= x[i]`, you ensure that you only process strictly decreasing query values, slashing unnecessary array scans.
 * - (Precision Warning on `pow()`): Look closely at `long long val = pow(2, x[i]);`. The standard library `pow` function operates on `double` floating-point types. For large exponents, this can introduce subtle floating-point inaccuracy or rounding drift. Replacing it with a lightning-fast integer bit-shift (`long long val = 1LL * (1 << x[i]);` or `1LL << x[i]`) completely eliminates floating-point overhead and guarantees absolute bitwise precision!
 * - (Efficient Array Mutation): Modifying elements in-place when `a[j] % val == 0` by adding `val / 2` correctly simulates the progressive bit-carry mechanics common in these Codeforces math rounds.
 * * How it runs:
 * First, we safely intercept array size `n` and query count `q`, followed by reading arrays `a` and `x`.
 * We initialize our `prev` threshold tracker to `31`.
 * We ignite our query processing loop: if the current query `x[i]` is greater than or equal to `prev`, we instantly skip it. Otherwise, we update `prev = x[i]`.
 * For each valid query, we compute the power-of-2 value and sweep through array `a`, updating elements that satisfy the divisibility condition.
 * Finally, we flush the mutated array elements to the output stream with absolute mathematical precision at raw silicon speed!
 */




#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n,q;
    cin >> n >> q;
    vector<long long> a(n),x(q);
    for(long long i=0;i<n;i++){
        cin >> a[i];
    }
    for(long long i=0;i<q;i++){
        cin >> x[i];
    }

    int prev = 31;
    for(long long i=0;i<q;i++){
        if(prev <= x[i]) continue;

        long long val=pow(2,x[i]);

        for(long long j = 0;j<n;j++){
            if(a[j]%val == 0){
                a[j] += (val/2);
            }
        }
        prev = x[i];
    }
    for(long long i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << "\n";
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
