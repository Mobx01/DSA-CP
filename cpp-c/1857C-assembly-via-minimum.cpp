/*
Codeforces - 1857C. Assembly via Minimums
Time limit per test: 2 seconds
Memory limit per test: 256 megabytes

Sasha has an array a of n integers. He got bored and for all i, j (i < j), he wrote down the minimum value of a_i and a_j. He obtained a new array b of size (n * (n - 1)) / 2.
For example, if a = [2, 3, 5, 1], he would write [min(2, 3), min(2, 5), min(2, 1), min(3, 5), min(3, 1), min(5, 1)] = [2, 2, 1, 3, 1, 1].

Then, he randomly shuffled all the elements of the array b.
Unfortunately, he forgot the array a, and your task is to restore any possible array a from which the array b could have been obtained.

The elements of array a should be in the range [-10^9, 10^9].

Input
The first line contains a single integer t (1 <= t <= 200) — the number of test cases.
The first line of each test case contains a single integer n (2 <= n <= 10^3) — the length of array a.
The second line of each test case contains (n * (n - 1)) / 2 integers b_1, b_2, ..., b_{n*(n-1)/2} (-10^9 <= b_i <= 10^9) — the elements of array b.
It is guaranteed that the sum of n over all tests does not exceed 10^3 and for each array b in the test, there exists an original array.

Output
For each test case, output any possible array a of length n.
*/



/* Approach - Sorted Pairwise Sums Extraction with Index Jumps / Array Reconstruction from Pair Sums (Time: O(N^2 log N), Space: O(N^2))
 * Basically, we completely annihilate brute-force subset searches by aggressively sorting the pairwise sums and leveraging triangular index jump patterns to extract adjacent element sums in pseudo-polynomial time!
 * * Observation: 
 * - The absolute core of this architecture is the Sorted Pairwise Sum Block Invariant! When all $\frac{N(N-1)}{2}$ pairwise sums of a sorted array $a$ are sorted in non-decreasing order, the first elements of each contiguous block corresponding to fixed elements $a_1, a_2, \dots$ appear at indices with decreasing step sizes ($n-1, n-2, n-3, \dots$).
 * - (Logical Flaw / Reconstruction Bug): Notice that `b[cur]` extracts the adjacent sums ($a_1+a_2, a_2+a_3, \dots, a_{n-1}+a_n$). Pushing these directly into `a` and printing them outputs the *pairwise sums* rather than the original array elements $a_1, a_2, \dots, a_n$. Recovering the actual original array requires utilizing the total sum or an additional equation (such as $a_1 + a_3$ from the second element of `b`) to solve for individual elements.
 * - (Optimal Complexity): Sorting the $O(N^2)$ pairwise sum vector takes $O(N^2 \log(N^2)) = O(N^2 \log N)$ time, and the extraction loop runs in linear $O(N)$ time, with $O(N^2)$ auxiliary space required to store vector `b`.
 * * How it runs:
 * First, we read test parameter `n` and compute the total number of pairs `nb = n * (n - 1) / 2`.
 * We populate vector `b` with all pairwise sums and sort them in ascending order.
 * We initialize `cur = 0` and iterate through `n - 1` steps, jumping indices by `n - i - 1` to extract the baseline sums of adjacent elements.
 * Finally, we output vector `a` to the output stream with absolute mathematical precision at raw silicon speed!
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
    ll nb = n*(n-1)/2;
    vll b(nb);

    for(int i=0;i<nb;i++){
        cin >> b[i];
    }
    sort(b.begin(),b.end());
    vll a;
    ll cur = 0;
    for(int i=0;i<n-1;++i){
        a.push_back(b[cur]);
        cur += (n-i-1);
    }
    a.push_back(a.back());

    for(int i =0;i<n;i++){
        cout << a[i] << " ";
    }
    cout<<endl;

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
