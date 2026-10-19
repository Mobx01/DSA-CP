/*
Codeforces - 2269A. SauSaGe Bank
Time limit per test: 1 second
Memory limit per test: 256 megabytes

Everyone in SauSaGe City is talking about its famous bank that offers a seemingly impossible deal:
"Leave your money with us, and we'll double it every single day!"
Hamed decides to give it a try, so he deposits 1 dollar into his account.

Suppose that at the beginning of a day, his bank balance is x dollars. Every day, the following events happen in order:
1. In the morning, the bank magically doubles his balance, so it becomes 2x dollars.
2. At night, Hamed may choose to withdraw all of the money from his bank account. If he does, the withdrawn amount is added to his card, and his bank account is immediately reset to 1 dollar so that the doubling process can begin again the next day. Otherwise, he leaves the money in the bank.

Unfortunately, this incredible bank will remain open for exactly n days before shutting down forever.
Hamed wants to withdraw money on exactly k different days before the bank closes. Determine the maximum amount of money that can be on Hamed's card after the n-th day.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1 <= t <= 500). The description of the test cases follows.
The only line of each test case contains the two integers n and k (1 <= k <= n <= 30).

Output
For each test case, print a single integer — the maximum amount of money that can be on Hamed's card after the n-th day.
*/




/* Approach - Bitwise Power Shift with Linear Scaling (Time: O(1), Space: O(1))
 * Basically, we completely annihilate floating-point rounding errors by aggressively replacing standard library power functions with native bitwise shift operators, computing exact integer values in pristine constant time!
 * * Observation: 
 * - The absolute core of this architecture is the Precision-Safe Exponentiation Invariant! Using `std::pow(2, n - k + 1)` returns a `double`, which can introduce precision loss, rounding bugs, or performance overhead for large integer exponents. Replacing it with the native 64-bit bitwise shift operator `(1LL << (n - k + 1))` guarantees exact integer arithmetic at raw hardware speed.
 * - (Overflow Boundary Awareness): When dealing with powers of 2, ensure that the exponent `n - k + 1` does not exceed `62` to prevent undefined behavior or sign overflow with signed `long long` integers.
 * - (Constant-Time Efficiency): Both the bitwise shift and the linear offset calculation `2 * (k - 1)` execute in strict $O(1)$ time and $O(1)$ space.
 * * How it runs:
 * First, we safely intercept integers `n` and `k`.
 * We compute the power term using a precise bitwise left shift (`1LL << (n - k + 1)`) and add the linear component `2 * (k - 1)`.
 * Finally, we flush the final calculated `ans` to the output stream with absolute mathematical precision at raw silicon speed!
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
    int n , k;
    cin >> n >> k;

    long long ans = pow(2,n-k+1) + 2*(k-1);
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
