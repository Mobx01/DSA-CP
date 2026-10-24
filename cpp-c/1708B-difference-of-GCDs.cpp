/*
Codeforces - 1708B. Difference of GCDs
Time limit per test: 1 second
Memory limit per test: 256 megabytes

You are given three integers n, l, and r. You need to construct an array a_1, a_2, ..., a_n (l <= a_i <= r) such that gcd(i, a_i) are all distinct or report there's no solution.

Here gcd(x, y) denotes the greatest common divisor (GCD) of integers x and y.

Input
The input consists of multiple test cases. The first line contains a single integer t (1 <= t <= 10^4) — the number of test cases. The description of the test cases follows.
The first line contains three integers n, l, r (1 <= n <= 10^5, 1 <= l <= r <= 10^9).
It is guaranteed that the sum of n over all test cases does not exceed 10^5.

Output
For each test case, if there is no solution, print "NO" (without quotes). You can print letters in any case (upper or lower).
Otherwise, print "YES" (without quotes). In the next line, print n integers a_1, a_2, ..., a_n — the array you construct.
If there are multiple solutions, you may output any.
*/




/* Approach - Greedy Largest Multiple Range Validation / Bounded Divisor Multiple Construction (Time: O(N), Space: O(N))
 * Basically, we completely annihilate brute-force search trees by aggressively computing the largest valid multiple for each index via integer division, verifying range inclusion in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Bounded Divisor Multiple Invariant (common in competitive programming range-construction problems)! For each position `i` from $1$ to $N$, we need to find a multiple of `i` that lies inclusively within the range $[L, R]$. The largest possible multiple of `i` that does not exceed $R$ is given by `(r / i) * i`. If this maximum candidate falls below $L$ (`mul < l`), then *all* multiples of `i` up to $R$ must also be less than $L$, proving that no valid choice exists for index `i` and triggering an immediate `"NO"`.
 * - (Greedy Optimality): Because any valid multiple must be $\le R$, checking the largest multiple $\le R$ is both necessary and sufficient to determine if a valid element exists in $[L, R]$ for a given index `i`.
 * - (Linear Time Efficiency): Iterating from $1$ to $N$ executes in strict $O(N)$ time with $O(N)$ auxiliary space for the result vector.
 * * How it runs:
 * First, we read test parameters `n`, `l`, and `r` and initialize vector `a` of size `n + 1`.
 * We ignite a linear sweep from `i = 1` to `n`, computing the largest multiple of `i` $\le r$ via `(r / i) * i`.
 * We check if `mul >= l`; if so, we assign `a[i] = mul`, otherwise we immediately print `"NO"` and return.
 * Finally, if all positions pass validation, we output `"YES"` followed by the constructed sequence with absolute mathematical precision at raw silicon speed!
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
    ll n ,l,r;
    cin >> n >> l >> r;

    vll a(n+1);

    for(int i =1;i<=n;i++){
        ll mul = (r/i)*i;

        if(mul >= l){
            a[i] = mul;
        }else{
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    for(int i=1;i<=n;i++){
        cout << a[i] << " ";
    }
    cout << "\n";
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
