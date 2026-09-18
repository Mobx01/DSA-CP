/*
Codeforces - 1221C. Perfect Team
Time limit per test: 2 seconds
Memory limit per test: 256 megabytes

You may have already known that a standard ICPC team consists of exactly three members. The perfect team however has more restrictions. A student can have some specialization: coder or mathematician. She/he can have no specialization, but can't have both at the same time.

So the team is considered perfect if it includes at least one coder, at least one mathematician and it consists of exactly three members.

You are a coach at a very large university and you know that c of your students are coders, m are mathematicians and x have no specialization.
What is the maximum number of full perfect teams you can distribute them into?

Note that some students can be left without a team and each student can be a part of no more than one team.
You are also asked to answer q independent queries.

Input
The first line contains a single integer q (1 <= q <= 10^4) — the number of queries.
Each of the next q lines contains three integers c, m, and x (0 <= c, m, x <= 10^8) — the number of coders, mathematicians and students without any specialization in the university, respectively.
Note that the no student is both coder and mathematician at the same time.

Output
Print q integers — the i-th of them should be the answer to the i query in the order they are given in the input. The answer is the maximum number of full perfect teams you can distribute your students into.
*/




/* Approach - Binary Search on Answer / Resource Allocation Optimization (Time: O(log(MAX)), Space: O(1))
 * Basically, we completely annihilate brute-force linear iteration by aggressively applying binary search on the answer space, determining the maximum craftable items under dual resource constraints in pristine logarithmic time!
 * * Observation: 
 * - The absolute core of this architecture is the Monotonic Feasibility Invariant! If you can successfully craft `mid` items using available resources `c` (crafting material 1), `m` (crafting material 2), and `x` (universal/extra resources), you can naturally craft any smaller amount. Conversely, if `mid` is impossible, any higher target is also impossible. This strict monotonicity allows us to binary search for the maximum possible answer across a bounded range (`0` to `1e8`).
 * - (The `ans = INT_MAX` Bug/Nuance Watch): Look closely at your initial answer variable: `long long ans = INT_MAX;`. If the inputs yield an answer of `0` (or if the binary search never successfully triggers `ans = mid` because even `mid = 0` fails, though `0` is always possible if `i = 0`), `ans` would remain `INT_MAX`. However, since `mid = 0` requires 0 items and `ispossible(0, c, m, x)` will return `true` for any non-negative `c, m, x`, `ans` will always be updated at least once. Initializing `ans = 0` is still cleaner practice to avoid exposing raw sentinel bounds!
 * - (Binary Search Bounds): Setting `j = 1e8` covers typical competitive programming constraints for such resource problems (since resources can scale up to $10^9$, though the square root or standard limits dictate the search space). 
 * * How it runs:
 * First, we safely intercept inputs `c`, `m`, and `x`.
 * We initialize our binary search boundaries (`i = 0`, `j = 1e8`) and ignite the search loop.
 * Inside `ispossible`, we verify if we have enough individual stock to satisfy `mid` items for both resources, and whether the combined leftover resources plus extra `x` meet the total requirement.
 * If possible, we greedily store `ans = mid` and search higher (`i = mid + 1`); otherwise, we restrict our search space lower (`j = mid - 1`).
 * Finally, we flush the optimal maximum craftable items to the output stream with absolute mathematical precision at raw silicon speed!
 */


#include <bits/stdc++.h>
using namespace std;

bool ispossible(long long mid, long long c, long long m, long long x) {
    // if we need 'mid' items and don't even have enough of c or m individually
    if (min(c, m) < mid) return false;

    long long leftc = c - mid;
    long long leftm = m - mid;
    
    //  check if the total leftover resources plus extra 'x' 
    // meet a secondary constraint or total requirement (e.g., >= mid or another threshold)
    return (leftc + leftm + x) >= mid; 
}

void solve() {
    long long c,m,x;
    cin >> c >> m >> x;

    long long ans = INT_MAX;
    long long i = 0 , j = 1e8;
    while(i <= j){
        long long mid = i + (j-i)/2;
        if(ispossible(mid,c,m,x)){
            ans = mid;
            i = mid+1;
        }else{
            j = mid-1;
        }
    }
    cout << ans << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();  
    }

    return 0;
}
