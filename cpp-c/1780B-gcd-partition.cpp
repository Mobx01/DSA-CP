/*
Codeforces - 1780B. GCD Partition
Time limit per test: 1 second
Memory limit per test: 256 megabytes

While at Kira's house, Josuke saw a piece of paper on the table with a task written on it.
The task sounded as follows. There is an array a of length n. On this array, do the following:
select an integer k > 1;
split the array into k subsegments;
calculate the sum in each of k subsegments and write these sums to another array b (where the sum of the subsegment (l, r) is the sum of a_j from j=l to r);
the final score of such a split will be gcd(b_1, b_2, ..., b_k).
The task is to find such a partition that the score is maximum possible. Josuke is interested in this task but is not strong in computer science. Help him to find the maximum possible score.

Input
The first line contains a single number t (1 <= t <= 10^4) — the number of test cases.
For each test case, the first line contains one integer n (2 <= n <= 2 * 10^5) — the length of the array a.
The second line contains n integers a_1, a_2, a_3, ..., a_n (1 <= a_i <= 10^9) — the array a itself.
It is guaranteed that the sum of n over all test cases does not exceed 2 * 10^5.

Output
For each test case print a single integer — the maximum score for the optimal partition.
*/




/* Approach - Prefix-Suffix Partition GCD Optimization (Time: O(N log(MAX)), Space: O(N))
 * Basically, we completely annihilate brute-force subarray partition checks by aggressively tracking running prefix sums and evaluating the greatest common divisor against complementary suffix sums across all valid split points in pristine log-linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Binary Partition GCD Invariant! When a problem asks to divide an array into two non-empty contiguous parts (a prefix and a suffix) and maximize the GCD of their sums, every possible split point divides the array into a prefix sum (`sum`) and its corresponding suffix sum (`total_sum - sum`). By testing all $N - 1$ possible split positions in a single linear pass, we guarantee that the optimal partition is captured.
 * - (Safe Overflow-Guarded Accumulation): Using `std::accumulate(a.begin(), a.end(), 0LL)` with `0LL` ensures that the total sum accumulator is treated as a `64-bit long long`, completely preventing integer overflow when dealing with large array elements.
 * - (Logarithmic GCD Efficiency): Leveraging `std::gcd` natively inside the loop efficiently computes the greatest common divisor for each partition option with minimal overhead.
 * * How it runs:
 * First, we safely intercept array size `n` and read all elements into vector `a`.
 * We compute the global `total_sum` of the entire array using `std::accumulate`.
 * We ignite a linear scan from index `0` to `n - 2`, accumulating the running prefix `sum` and updating our max `ans` with `__gcd(sum, total_sum - sum)`.
 * Finally, we flush the maximum partition GCD result to the output stream with absolute mathematical precision at raw silicon speed!
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

    ll sum =0,ans=0;
    ll total_sum = accumulate(a.begin(),a.end(),0LL);
    
    for(ll i=0;i<n-1;i++){
        sum += a[i];
        ans = max(ans,__gcd(sum,total_sum-sum));
    }
    cout << ans <<"\n";
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
