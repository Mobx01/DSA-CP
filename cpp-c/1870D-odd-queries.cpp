/*
Codeforces PS - 1870D. Odd Queries
time limit per test: 2 seconds
memory limit per test: 256 megabytes

You have an array a1, a2, …, an. Answer q queries of the following form:
If we change all elements in the range al, al+1, …, ar of the array to k, will the sum of the entire array be odd?
Note that queries are independent and do not affect future queries.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1 ≤ t ≤ 10^4). The description of the test cases follows.
The first line of each test case consists of 2 integers n and q (1 ≤ n ≤ 2⋅10^5; 1 ≤ q ≤ 2⋅10^5) — the length of the array and the number of queries.
The second line of each test case consists of n integers ai (1 ≤ ai ≤ 10^9) — the array a.
The next q lines of each test case consists of 3 integers l, r, k (1 ≤ l ≤ r ≤ n; 1 ≤ k ≤ 10^9) — the queries.
It is guaranteed that the sum of n over all test cases doesn't exceed 2⋅10^5, and the sum of q doesn't exceed 2⋅10^5.

Output
For each query, output "YES" if the sum of the entire array becomes odd, and "NO" otherwise.
You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.
*/

/* Approach - Prefix Sum & Parity Arithmetic (Time: O(N + Q), Space: O(N + Q))
 * Basically, we mathematically precompute the running total of the array using a Prefix Sum, allowing us to flawlessly swap out massive subarrays and instantly check the final parity in strict O(1) time per query!
 * * Observation: 
 * - Simulating the array replacement and recalculating the total sum for every single query would catastrophically burn O(N * Q) time and result in a massive Time Limit Exceeded (TLE) crash.
 * - By utilizing a 1-based Prefix Sum array, we can brilliantly extract the exact sum of ANY arbitrary `[l, r]` subarray in guaranteed O(1) constant time!
 * - To mathematically find the new total sum for a query, we don't need to rebuild the array. We simply take the original global sum, brutally subtract the isolated `[l, r]` sum, and seamlessly inject the new hypothetical sum: `k` multiplied by the exact physical length of the range `(r - l + 1)`.
 * - (Optimization Note: The code aggressively allocates a massive 2D `vector<vector<long long>> qr` to securely store all `q` queries in memory before processing them! This needlessly burns O(Q) auxiliary memory. We could elegantly process each `l, r, k` completely on the fly as we read them from the input stream, instantly slashing the query space complexity down to a perfect, guaranteed O(1)!)
 * * How it runs:
 * First, we safely extract our array size `n` and query count `q`, and perfectly populate our 1-based `vector a` to flawlessly protect against any dreaded boundary segmentation faults.
 * Then, we trigger a high-speed linear sweep to construct our `pref` array, relentlessly accumulating the running sum at every single index, and securely lock in our absolute `totalsum` directly from the final element `pref[n]`.
 * Next, we fiercely iterate through every single query. We instantly extract our target boundaries `l` and `r`, and our replacement value `k`.
 * We mathematically calculate the old subarray sum using our prefix array (`pref[r] - pref[l-1]`) and confidently compute our hypothetical `temp_total` by perfectly swapping the old weight for the new mass `k * (r - l + 1)`.
 * Finally, we evaluate the strict parity of our new total. If it is mathematically even (`% 2 == 0`), the condition fails and we aggressively print "NO". Otherwise, we confidently print "YES", flawlessly solving the query without ever physically modifying the original array!
 */


#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, q;
    cin >> n >> q;
    
    // We make the arrays 1-based by size n+1 to avoid Segmentation Faults
    vector<long long> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    vector<vector<long long>> qr(q, vector<long long>(3));
    for(int i = 0; i < q; i++){
        cin >> qr[i][0] >> qr[i][1] >> qr[i][2];
    }

    // 1-based prefix sum calculation
    vector<long long> pref(n + 1, 0);
    for(int i = 1; i <= n; i++){
        pref[i] = pref[i-1] + a[i];
    }
    
    long long totalsum = pref[n]; // Original total sum of the array
    
    // Process each query
    for(auto vec : qr){
        long long l = vec[0];
        long long r = vec[1];
        long long k = vec[2];
        
        // 1. Calculate the sum of the original range
        long long orig_range_sum = pref[r] - pref[l-1];
        
        // 2. Calculate the temporary new total sum for THIS query
        // We do NOT modify 'totalsum' directly using -=
        long long temp_total = totalsum - orig_range_sum + (k * (r - l + 1));
        
        // 3. Print YES/NO INSIDE the loop for every query
        if(temp_total % 2 == 0) cout << "NO\n";
        else cout << "YES\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        solve();  

    return 0;
}
