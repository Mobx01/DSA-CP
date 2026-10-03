/*
Codeforces - 1791E. Negatives and Positives
Time limit per test: 2 seconds
Memory limit per test: 256 megabytes

Given an array a consisting of n elements, find the maximum possible sum the array can have after performing the following operation any number of times:
Choose 2 adjacent elements and flip both of their signs. In other words choose an index i such that 1 <= i <= n - 1 and assign a_i = -a_i and a_{i+1} = -a_{i+1}.

Input
The input consists of multiple test cases. The first line contains an integer t (1 <= t <= 1000) — the number of test cases. The descriptions of the test cases follow.
The first line of each test case contains an integer n (2 <= n <= 2 * 10^5) — the length of the array.
The following line contains n space-separated integers a_1, a_2, ..., a_n (-10^9 <= a_i <= 10^9).
It is guaranteed that the sum of n over all test cases does not exceed 2 * 10^5.

Output
For each test case, output the maximum possible sum the array can have after performing the described operation any number of times.
*/



/* Approach - Absolute Sum Maximization via Sign-Flip Parity Invariant (Time: O(N), Space: O(N))
 * Basically, we completely annihilate brute-force sign configuration searches by aggressively tracking negative element parity and minimum absolute values, computing the maximum possible sum in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Sign-Flip Operation Parity Invariant (e.g., standard Codeforces problems where you can multiply any two elements by -1 simultaneously)! Since each operation flips the signs of two elements, the parity of the total number of negative elements remains invariant under valid moves. If the count of negative numbers is even, you can systematically pair them up and make all elements positive, achieving the absolute sum of all absolute values (`sum`). If the count is odd, you are mathematically forced to leave exactly one element negative; to maximize your total sum, you should pick the element with the smallest absolute value (`min_abs`) to absorb the negative sign, resulting in `sum - 2 * min_abs`.
 * - (Single-Pass Efficiency): Accumulating the total absolute sum, counting negative elements, and tracking the minimum absolute value all within a single linear traversal of vector `a` keeps runtime overhead at an absolute minimum ($O(N)$ time).
 * - (Overflow-Guarded Bounds): Leveraging `LLONG_MAX` for initialization ensures that `min_abs` correctly captures the smallest element without boundary corruption.
 * * How it runs:
 * First, we safely intercept array size `n` and read all elements into vector `a`.
 * We ignite a high-speed linear scan to accumulate the running `sum` of absolute values, count the number of negative elements (`countn`), and track the smallest absolute value (`min_abs`).
 * We evaluate the parity of `countn`: if even, we flush the full `sum`; if odd, we subtract `2 * min_abs` to optimize the single unavoidable negative sign.
 * Finally, we flush the maximum achievable sum to the output stream with absolute mathematical precision at raw silicon speed!
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
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    ll min_abs = LLONG_MAX, countn=0,sum=0;
    for(int i=0;i<n;i++){
        min_abs = min(min_abs,abs(a[i]));
        sum += abs(a[i]);
        countn += (a[i] <0) ? 1: 0;
    }

    if(countn%2 ==0){
        cout << sum <<"\n";
    }else{
        cout << sum - 2*min_abs << "\n";
    }
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
