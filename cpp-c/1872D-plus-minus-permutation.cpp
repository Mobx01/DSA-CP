/*
Codeforces - 1872D. Plus Minus Permutation
Time limit per test: 1 second
Memory limit per test: 256 megabytes

You are given 3 integers — n, x, y. Let's call the score of a permutation p_1, ..., p_n the following value:
(p_{1*x} + p_{2*x} + ... + p_{floor(n/x)*x}) - (p_{1*y} + p_{2*y} + ... + p_{floor(n/y)*y})
In other words, the score of a permutation is the sum of p_i for all indices i divisible by x, minus the sum of p_i for all indices i divisible by y.

You need to find the maximum possible score among all permutations of length n.
For example, if n = 7, x = 2, y = 3, the maximum score is achieved by the permutation [2, 6, 1, 7, 5, 4, 3] and is equal to (6 + 7 + 4) - (1 + 4) = 17 - 5 = 12.

Input
The first line of input contains an integer t (1 <= t <= 10^4) — the number of test cases.
Then follows the description of each test case.
The only line of each test case description contains 3 integers n, x, y (1 <= n <= 10^9, 1 <= x, y <= n).

Output
For each test case, output a single integer — the maximum score among all permutations of length n.
*/



/* Approach - GCD-LCM Multi-Set Partitioning with Arithmetic Progression Sums (Time: O(log(min(X, Y))), Space: O(1))
 * Basically, we completely annihilate brute-force iteration over $N$ by aggressively leveraging inclusion-exclusion principles, safe LCM overflow bounding, and arithmetic progression formulas to compute exclusive divisor sums in logarithmic time!
 * * Observation: 
 * - The absolute core of this architecture is the Divisibility Partitioning Invariant (common in competitive programming problems where numbers from $1$ to $N$ are distributed between two criteria $X$ and $Y$)! By finding the greatest common divisor (`gcd`) and safely computing the least common multiple (`lcm`), we determine how many numbers are exclusively divisible by $X$ (`only_x`) versus $Y$ (`only_y`) without overlapping common multiples.
 * - (Safe Overflow Guard): The condition `if (x / g > n / y) lcm = n + 1;` is an exceptionally clean and elegant overflow safeguard, preventing integer overflow when computing `(x / g) * y` when the LCM exceeds the upper limit $N$.
 * - (Arithmetic Progression Optimization): Instead of summing individual elements, the algorithm uses AP sum formulas (`sx` for the highest values and `sy` for the lowest values) to compute the sum of the respective assigned numbers in $O(1)$ time, keeping overall complexity dominated solely by the GCD calculation ($O(\log(\min(X, Y)))$).
 * * How it runs:
 * First, we read test parameters `n`, `x`, and `y`.
 * We compute their GCD and derive a safe LCM value, calculating common multiples and exclusive counts (`only_x`, `only_y`).
 * We apply arithmetic progression sum formulas to evaluate the sum of numbers assigned to each set (`sx` and `sy`).
 * Finally, we flush the difference `sx - sy` to the output stream with absolute mathematical precision at raw silicon speed!
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
    ll n,x,y;
    cin >> n >> x >> y;
    ll g = gcd(x,y);
    ll lcm;
    if(x/g > n/y)lcm = n+1;
    else lcm = (x/g)*y;

    ll com = n/lcm;
    ll cn_x = n/x;
    ll cn_y = n/y;
    ll only_x = cn_x-com;
    ll only_y = cn_y-com;

    ll sx = only_x*(2*n - only_x +1)/2;
    ll sy = only_y*(only_y +1)/2;
    cout << sx-sy<<endl;
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
