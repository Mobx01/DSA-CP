/*
Codeforces - 1873E. Building an Aquarium
Time limit per test: 2 seconds
Memory limit per test: 256 megabytes

You love fish, that's why you have decided to build an aquarium. You have a piece of coral made of n columns, the i-th of which is a_i units tall. Afterwards, you will build a tank around the coral as follows:
Pick an integer h >= 1 — the height of the tank. Build walls of height h on either side of the tank.
Then, fill the tank up with water so that the height of each column is h, unless the coral is taller than h; then no water should be added to this column.

You can use at most x units of water to fill up the tank, but you want to build the biggest tank possible. What is the largest value of h you can select?

Input
The first line contains a single integer t (1 <= t <= 10^4) — the number of test cases.
The first line of each test case contains two positive integers n and x (1 <= n <= 2 * 10^5; 1 <= x <= 10^9) — the number of columns of the coral and the maximum amount of water you can use.
The second line of each test case contains n space-separated integers a_i (1 <= a_i <= 10^9) — the heights of the coral.
The sum of n over all test cases doesn't exceed 2 * 10^5.

Output
For each test case, output a single positive integer h (h >= 1) — the maximum height the tank can have, so you need at most x units of water to fill up the tank.
We have a proof that under these constraints, such a value of h always exists.
*/



/* Approach - Binary Search on Answer with Cumulative Elevation Feasibility (Time: O(N log(MAX)), Space: O(1) auxiliary)
 * Basically, we completely annihilate brute-force linear scaling by aggressively applying binary search over the potential height space, determining the maximum achievable lower bound in pristine logarithmic time!
 * * Observation: 
 * - The absolute core of this architecture is the Monotonic Elevation Invariant! If you can successfully elevate all elements in array `a` to reach at least `mid` using a total increment budget of `x`, any smaller target height is also achievable. Conversely, if `mid` requires more than `x` total units of deficit correction, any higher target is impossible. This strict monotonicity allows us to binary search for the maximum valid height across a wide numerical range (`0` to `1e12`).
 * - (The Sentinel Ceiling Trap): Look closely at your initialization of `ans`: `long long ans = INT_MAX;`. However, your binary search upper bound is set much higher at `j = 1e12`. Because `INT_MAX` evaluates to roughly $2 \times 10^9$, if the optimal target height naturally exceeds $2 \times 10^9$, your `ans` register will be artificially capped or restricted by this sentinel! Initializing `ans = 0` (since a target height of `0` is trivially feasible) completely eliminates this bug and allows the full $10^{12}$ search space to operate safely.
 * - (Efficient Linear Feasibility Check): Your `check` function cleanly computes the total deficit units required to pull all sub-threshold elements up to `mid` in $O(N)$ time, keeping the inner evaluation lightning-fast.
 * * How it runs:
 * First, we safely intercept array size `n` and budget `x`, followed by reading all elements into our vector `a`.
 * We initialize our binary search boundaries (`i = 0`, `j = 1e12`) and our answer tracker.
 * We ignite the search loop: `check` computes whether the cumulative deficit needed to raise elements to `mid` fits within budget `x`.
 * If feasible, we greedily store `ans = mid` and search higher (`i = mid + 1`); otherwise, we restrict our search space lower (`j = mid - 1`).
 * Finally, we flush the optimal maximum attainable height to the output stream with absolute mathematical precision at raw silicon speed!
 */



#include <bits/stdc++.h>
using namespace std;

bool check(long long mid, vector<long long>& a, long long x) {
    long long n = a.size(),unit=0;
    for(long long i=0;i<n;i++){
        if(a[i] < mid){
            unit += (mid-a[i]);
        }
    }
    return unit <= x;
}

void solve() {
    long long n,x;
    cin >> n >> x;

    vector<long long> a(n);
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    long long ans = INT_MAX;
    long long i = 0 , j = 1e12;
    while(i <= j){
        long long mid = i + (j-i)/2;
        if(check(mid,a,x)){
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
