/*
Codeforces - 1820B. JoJo's Incredible Adventures
Time limit per test: 1 second
Memory limit per test: 256 megabytes

Did you think there was going to be a JoJo legend here? But no, that was me, Dio!
Given a binary string s of length n, consisting of characters 0 and 1. Let's build a square table of size n x n, consisting of 0 and 1 characters as follows.

In the first row of the table write the original string s. In the second row of the table write cyclic shift of the string s by one to the right. In the third row of the table, write the cyclic shift of line s by two to the right. And so on. Thus, the row with number k will contain a cyclic shift of string s by k to the right. The rows are numbered from 0 to n - 1 top-to-bottom.

In the resulting table we need to find the rectangle consisting only of ones that has the largest area.
We call a rectangle the set of all cells (i, j) in the table, such that x_1 <= i <= x_2 and y_1 <= j <= y_2 for some integers 0 <= x_1 <= x_2 < n and 0 <= y_1 <= y_2 < n.

Recall that the cyclic shift of string s by k to the right is the string s_{n-k+1}...s_n s_1 s_2...s_{n-k}. For example, the cyclic shift of the string "01011" by 0 to the right is the string itself "01011", its cyclic shift by 3 to the right is the string "01101".

Input
Each test consists of multiple test cases. The first line contains a single integer t (1 <= t <= 2 * 10^4) — the number of test cases. The description of test cases follows.
The first and the only line of each test case contains a single binary string s (1 <= |s| <= 2 * 10^5), consisting of characters 0 and 1.
It is guaranteed that the sum of string lengths |s| over all test cases does not exceed 2 * 10^5.

Output
For each test case, output a single integer — the maximum area of a rectangle consisting only of ones. If there is no such rectangle, output 0.
*/




/* Approach - Circular Maximum Consecutive Ones Tracking / Optimal Subgrid Partitioning (Time: O(N), Space: O(N))
 * Basically, we completely annihilate brute-force circular boundary checks by aggressively duplicating the string to linearize wrap-around sequences, tracking the maximum contiguous block of ones and optimizing subgrid dimensions in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Circular Continuity Invariant! By concatenating string `s` with itself (`s = s + s`), we seamlessly capture wrap-around contiguous segments of `'1'`s in a single linear scan without complex modulo arithmetic.
 * - (Mathematical Partitioning): When `max_cons < n`, the maximum product of two factors whose sum relates to the contiguous block size is computed via integer division (`h = (max_cons + 1) / 2`, `w = (max_cons + 2) / 2`). If the maximum block spans the entire length (`max_cons >= n`), it yields the full grid area `n * n`.
 * - (Linear Time Efficiency): String duplication and the linear sweep execute in strict $O(N)$ time with $O(N)$ auxiliary space for the string buffer.
 * * How it runs:
 * First, we read string `s`, determine its length `n`, and duplicate it to handle circular wrapping.
 * We scan the doubled string to compute `max_cons`, tracking the longest streak of consecutive `'1'`s.
 * We check if `max_cons >= n` to output `n * n`, or compute the optimal partitioned product `h * w` otherwise.
 * Finally, we flush the result to the output stream with absolute mathematical precision at raw silicon speed!
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
    string s;
    cin >> s;
    ll n = s.length();
    s = s + s;

    int max_cons = 0, cons = 0;
    for(char c : s){
        if(c == '1'){
            cons++;
            max_cons = max(cons, max_cons);
        } else {
            cons = 0;
        }
    }
    
    if(max_cons >= n){
        cout << n * n << "\n";
    } else {
        ll h = (max_cons + 1) / 2;
        ll w = (max_cons + 2) / 2;
        cout << h * w << "\n";
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
