/*
Codeforces - 1797B. Li Hua and Pattern
Time limit per test: 1 second
Memory limit per test: 256 megabytes

Li Hua has a pattern of size n x n, each cell is either blue or red. He can perform exactly k operations. In each operation, he chooses a cell and changes its color from red to blue or from blue to red. Each cell can be chosen as many times as he wants. Is it possible to make the pattern, that matches its rotation by 180 degrees?

Suppose you were Li Hua, please solve this problem.

Input
The first line contains the single integer t (1 <= t <= 100) — the number of test cases.
The first line of each test case contains two integers n, k (1 <= n <= 10^3, 0 <= k <= 10^9) — the size of the pattern and the number of operations.
Each of next n lines contains n integers a_{i,j} (a_{i,j} in {0, 1}) — the initial color of the cell, 0 for blue and 1 for red.
It's guaranteed that sum of n over all test cases does not exceed 10^3.

Output
For each set of input, print "YES" if it's possible to make the pattern, that matches its rotation by 180 degrees after applying exactly k of operations, and "NO" otherwise.
You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.
*/



/* Approach - 180-Degree Matrix Symmetry Analysis with Residue Parity Correction (Time: O(N^2), Space: O(N^2))
 * Basically, we completely annihilate complex matrix transformation loops by aggressively counting 180-degree rotational mismatches and evaluating surplus operation parity against matrix dimensions in pristine quadratic time!
 * * Observation: 
 * - The absolute core of this architecture is the 180-Degree Rotational Invariant (e.g., Codeforces matrix palindrome / rotation problems)! For a matrix to be symmetric under a 180-degree rotation, every element at position `(i, j)` must match its rotated counterpart at `(n - 1 - i, n - 1 - j)`. Since checking both directions counts each pair twice, dividing the total mismatch count by 2 (`mis /= 2`) gives the exact number of pairs that need to be synchronized.
 * - (Residue Parity Logic): Once all mismatches are fixed using at least `mis` operations, any leftover operations (`temp = k - mis`) can be used to toggle elements. If `temp` is even, we can toggle any element and its rotated counterpart back and forth without changing the final symmetry. If `temp` is odd, we can only absorb the leftover toggle if the matrix has an odd dimension (`n % 2 == 1`), because an odd-sized matrix possesses a central fixed point `(n/2, n/2)` that can absorb an extra toggle without breaking 180-degree rotational symmetry!
 * - (Quadratic Grid Efficiency): Traversing the $N \times N$ matrix efficiently checks all rotational constraints while respecting fast I/O boundaries.
 * * How it runs:
 * First, we safely intercept matrix dimension `n` and operation budget `k`, followed by reading the $N \times N$ grid elements.
 * We count all rotational mismatches between `(i, j)` and `(n - 1 - i, n - 1 - j)`, halving the sum to get the true pair count `mis`.
 * We check if `mis > k`; if so, we output `"NO"`. Otherwise, we compute leftover budget `temp = k - mis` and evaluate its parity relative to matrix dimension `n` to determine if symmetry can be successfully preserved.
 * Finally, we flush the optimal boolean result (`"YES"` or `"NO"`) to the output stream with absolute mathematical precision at raw silicon speed!
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
    ll n ,k;
    cin >> n >>k;

    vector<vll> a(n,vll(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    ll mis=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j] != a[n-i-1][n-j-1]){
                mis++;
            }
        }
    }

    //every mismatch is count 2 times
    mis /= 2;

    if(mis > k){//we can change every mismatches
        cout << "NO\n";   
    }else{
        ll temp = k - mis;
        if(temp%2 == 0){
            cout << "YES\n";
        }else{
            if(n%2 ==0){
                cout << "NO\n";
            }else{
                cout << "YES\n";
            }
        }
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
