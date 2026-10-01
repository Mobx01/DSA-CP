/*
Codeforces - 1826B. Lunatic Never Content
Time limit per test: 2 seconds
Memory limit per test: 256 megabytes

You have an array a of n non-negative integers. Let's define f(a, x) = [a_1 mod x, a_2 mod x, ..., a_n mod x] for some positive integer x. Find the biggest x, such that f(a, x) is a palindrome.

Here, a mod x is the remainder of the integer division of a by x.
An array is a palindrome if it reads the same backward as forward. More formally, an array a of length n is a palindrome if for every i (1 <= i <= n) a_i = a_{n - i + 1}.

Input
The first line contains a single integer t (1 <= t <= 10^5) — the number of test cases.
The first line of each test case contains a single integer n (1 <= n <= 10^5).
The second line of each test case contains n integers a_i (0 <= a_i <= 10^9).
It's guaranteed that the sum of all n does not exceed 10^5.

Output
For each test case output the biggest x, such that f(a, x) is a palindrome. If x can be infinitely large, output 0 instead.
*/



/* Approach - Symmetric Pair Difference GCD Accumulation (Time: O(N log(MAX)), Space: O(N))
 * Basically, we completely annihilate brute-force factor searches by aggressively computing the greatest common divisor of symmetric element differences across the array, identifying the maximum universal step size in pristine log-linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Symmetric Difference GCD Invariant! In problems where elements need to be balanced, transformed, or equalized using a common step size or modulo base $x$, any valid $x$ must divide the absolute difference between symmetric mirror positions (`a[i]` and `a[n - 1 - i]`). By accumulating the running `std::gcd` across all these symmetric pair differences, you isolate the largest possible divisor that governs the entire array's structural symmetry.
 * - (Symmetric Indexing Elegance): Pairing element `a[i]` with its counterpart `a[n - 1 - i]` cleanly covers the entire search space in a single pass without redundant duplicate evaluations.
 * - (Modern C++ GCD Integration): Leveraging `std::gcd` directly handles number theory calculations natively and efficiently alongside `long long` types to prevent any potential overflow during subtraction.
 * * How it runs:
 * First, we safely intercept array size `n` and read all elements into vector `a`.
 * We initialize our `ans` register with the absolute difference between the outermost elements (`abs(a[0] - a[n - 1])`).
 * We ignite a linear scan to compute and accumulate the `std::gcd` across all symmetric pair differences (`abs(a[i] - a[n - 1 - i])`).
 * Finally, we flush the optimal maximum GCD result to the output stream with absolute mathematical precision at raw silicon speed!
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
    for(ll i =0;i<n;i++){
        cin >> a[i];
    }

    ll ans = abs(a[0] - a[n-1]);

    for(ll i=1;i < n;i++){
        ans = gcd(ans , abs(a[i]-a[n-i-1]));
    }

    cout << ans << endl;
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
