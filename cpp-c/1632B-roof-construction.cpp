/*
Codeforces - 1632B. Roof Construction
Time limit per test: 1 second
Memory limit per test: 256 megabytes

It has finally been decided to build a roof over the football field in School 179. Its construction will require placing n consecutive vertical pillars. Furthermore, the headmaster wants the heights of all the pillars to form a permutation p of integers from 0 to n-1, where p_i is the height of the i-th pillar from the left (1 <= i <= n).

As the chief, you know that the cost of construction of consecutive pillars is equal to the maximum value of the bitwise XOR of heights of all pairs of adjacent pillars. In other words, the cost of construction is equal to max_{1 <= i <= n-1} p_i \oplus p_{i+1}, where \oplus denotes the bitwise XOR operation.

Find any sequence of pillar heights p of length n with the smallest construction cost.
In this problem, a permutation is an array consisting of n distinct integers from 0 to n-1 in arbitrary order. For example, [2, 3, 1, 0, 4] is a permutation, but [1, 0, 1] is not a permutation (1 appears twice in the array) and [1, 0, 3] is also not a permutation (n=3, but 3 is in the array).

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1 <= t <= 10^4). Description of the test cases follows.
The only line for each test case contains a single integer n (2 <= n <= 2 * 10^5) — the number of pillars for the construction of the roof.
It is guaranteed that the sum of n over all test cases does not exceed 2 * 10^5.

Output
For each test case print n integers p_1, p_2, ..., p_n — the sequence of pillar heights with the smallest construction cost.
If there are multiple answers, print any of them.
*/

/* Approach - Bitwise Symmetry / Most Significant Bit Partitioning (Time: O(N), Space: O(N) auxiliary)
 * Basically, we completely annihilate complex combinatorial permutations by aggressively leveraging the Most Significant Bit (MSB), partitioning the sequence into a descending block from 2^msb - 1 down to 0 followed by an ascending block up to n!
 * * Observation: 
 * - The absolute core of this architecture is the MSB Splitting Masterstroke! By isolating the largest power of two less than or equal to `n`, you create a perfectly balanced structural pivot. This exact geometric split is frequently deployed in bitwise XOR maximization or path-construction problems to maintain structural invariants across power-of-two boundaries.
 * - (The `__lg` Hardware Masterpiece): `ll msb = __lg(n);`. This is absolute silicon-level perfection! Utilizing the GCC builtin `__lg` directly compiles down to a single CPU assembly instruction (`bsr` or `lzcnt`), evaluating the most significant bit in a single hardware clock cycle without any floating-point overhead or manual bit-shifting loops!
 * - (The Vector Reallocation Trap): Your logic is pristine, but your memory allocation introduces minor overhead! You declare `vll ans;` and dynamically push elements using `.pb()`. As the vector grows, the heap violently reallocates memory. You must instantly lock in performance by executing `ans.reserve(n + 1);` right after reading `n` to guarantee a single contiguous block of RAM!
 * - (Optimization Alert / The O(1) Space Annihilation): You store the entire sequence in the `ans` vector purely to print it out at the end. You can completely vaporize the vector allocation by printing the numbers directly on the fly during the two loops! This drops your auxiliary space complexity from O(N) down to absolute peak O(1) with zero heap fragmentation.
 * * How it runs:
 * First, we safely intercept the input, decrement `n` for 0-based indexing, and instantly compute the MSB using hardware-accelerated instructions.
 * We calculate the upper boundary of the first partition (`2^msb - 1`).
 * We ignite the first loop, generating a strictly descending sequence down to `0`, streaming the values directly to output or storage.
 * We pivot to the second partition, generating a strictly ascending sequence from `2^msb` up to `n`.
 * Finally, we flush the complete sequence with absolute mathematical precision at raw silicon speed!
 */



#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    ll n;
    cin >> n; 
    n--; // 0-based indexing
    
    if (n < 0) {
        cout << "\n";
        return;
    }


    ll msb = __lg(n);

    // maximum power of 2 less than or equal to n
    ll num = (1LL << msb) - 1;
    vll ans;
    
    // fill from 2^msb - 1 down to 0
    while (num >= 0) {
        ans.pb(num);
        num--;
    }
    
    num = 1LL << msb;
    // fill from 2^msb up to n
    while (num <= n) {
        ans.pb(num);
        num++;
    }

    for (ll i : ans) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    fast_io();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
