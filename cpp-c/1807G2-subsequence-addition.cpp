/*
Codeforces - 1807G2. Subsequence Addition (Hard Version)
Time limit per test: 2 seconds
Memory limit per test: 256 megabytes

The only difference between the two versions is that in this version, the constraints are higher.
Initially, array a contains just the number 1. You can perform several operations in order to change the array. In an operation, you can select some subsequence of a and add into a an element equal to the sum of all elements of the subsequence.

You are given a final array c. Check if c can be obtained from the initial array a by performing some number (possibly 0) of operations on the initial array.

Input
The first line of the input contains an integer t (1 <= t <= 1000) — the number of test cases. The description of the test cases follows.
The first line of each test case contains n (1 <= n <= 2 * 10^5) — the number of elements the final array c should have.
The second line of each test case contains n space-separated integers c_i (1 <= c_i <= 2 * 10^5) — the elements of the final array c that should be obtained from the initial array a.
It is guaranteed that the sum of n over all test cases does not exceed 2 * 10^5.

Output
For each test case, output "YES" (without quotes) if such a sequence of operations exists, and "NO" (without quotes) otherwise.
You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive answer).
*/



/* Approach - Greedy Prefix Sum Coverage / Subset Sum Reachability Invariant (Time: O(N log N), Space: O(N))
 * Basically, we completely annihilate brute-force subset enumeration by aggressively sorting element values and verifying cumulative prefix reachability bounds in pristine log-linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Cumulative Prefix Reachability Invariant (e.g., standard competitive programming problems verifying if a set of weights or coin denominations can continuously cover all values up to a target sum without gaps)! When elements are sorted in non-decreasing order, to ensure that every intermediate value or prefix sum can be formed or extended smoothly, each subsequent element `c[i]` must not exceed the running sum of all preceding elements plus the element itself.
 * - (Mandatory Base Unit Check): Verifying that `c[0] == 1` at the very beginning is critical. Without a starting unit of `1`, it is impossible to form the initial integer step, forcing an immediate `"NO"` classification.
 * - (Greedy Prefix Expansion): Maintaining a running `sum` and enforcing the condition `c[i] > sum` guarantees that no unreachable numeric gaps exist in the cumulative subset combinations as we scale up.
 * * How it runs:
 * First, we safely intercept array size `n` and read all element values into vector `c`.
 * We sort vector `c` in ascending order to establish proper monotonic prefix evaluation properties.
 * We validate the base constraint (`c[0] == 1`), returning `"NO"` if the smallest element fails to provide the foundational unit.
 * We ignite a linear scan from index `1` onward, ensuring each element `c[i]` is less than or equal to the current accumulated `sum`, updating `sum += c[i]` dynamically.
 * Finally, if all elements satisfy the prefix coverage invariant, we flush `"YES"` (or `"NO"` otherwise) to the output stream with absolute mathematical precision at raw silicon speed!
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
    vll c(n);

    for(int i=0;i<n;i++){
        cin >> c[i];
    }
    sort(c.begin(),c.end());

    if(c[0] != 1){
        cout << "NO\n";
        return;
    }
    ll sum = 1;
    for(int i=1;i<n;i++){
        if(c[i] > sum){
            cout << "NO\n";
            return;
        }
        sum += c[i];
    }
    cout << "YES\n";
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
