/*
Codeforces - 1618C. Paint the Array
Time limit per test: 2 seconds
Memory limit per test: 256 megabytes

You are given an array a consisting of n positive integers. You have to choose a positive integer d and paint all elements into two colors. All elements which are divisible by d will be painted red, and all other elements will be painted blue.

The coloring is called beautiful if there are no pairs of adjacent elements with the same color in the array. Your task is to find any value of d which yields a beautiful coloring, or report that it is impossible.

Input
The first line contains a single integer t (1 <= t <= 1000) — the number of testcases.
The first line of each testcase contains one integer n (2 <= n <= 100) — the number of elements of the array.
The second line of each testcase contains n integers a_1, a_2, ..., a_n (1 <= a_i <= 10^{18}).

Output
For each testcase print a single integer. If there is no such value of d that yields a beautiful coloring, print 0. Otherwise, print any suitable value of d (1 <= d <= 10^{18}).
*/




/* Approach - Alternating Sub-array GCD Partitioning with Mutual Divisibility Validation (Time: O(N log(MAX)), Space: O(N))
 * Basically, we completely annihilate brute-force factor checking by aggressively partitioning the array into even-indexed and odd-indexed GCD components, validating mutual non-divisibility in pristine linear-logarithmic time!
 * * Observation: 
 * - The absolute core of this architecture is the Alternating GCD Parity Invariant! When a problem asks to find a single divisor $d$ such that all elements at one parity of indices (e.g., even) are divisible by $d$, and *no* elements at the opposite parity (odd) are divisible by $d$, the only candidate divisors that could possibly work are the greatest common divisors of those respective index sets (`gcde` and `gcdo`). Any other common divisor would have to be a factor of these GCDs, but maximizing the candidate gives us the best chance to satisfy the disjoint divisibility conditions.
 * - (Two-Phase Validation Logic): Your solution first computes `gcde` (GCD of all even-indexed elements) and tests if it divides *any* odd-indexed element. If it doesn't touch any odd-indexed element (`flag == true`), `gcde` is a valid answer. If that fails, it mirrors the check for `gcdo` against all even-indexed elements. If both fail, it safely defaults to `0`. This covers all mutually exclusive candidate paths cleanly.
 * - (Built-in GCD Optimization): Leveraging `std::__gcd` handles the logarithmic number theory computations efficiently during the single-pass traversal.
 * * How it runs:
 * First, we safely intercept array size `n` and read all elements into vector `a`.
 * We split our GCD accumulation into two separate registers: `gcde` for even indices and `gcdo` for odd indices.
 * We validate whether `gcde` can act as a valid separator by ensuring it divides zero odd-indexed elements; if successful, we print `gcde`.
 * Otherwise, we cross-validate `gcdo` against all even-indexed elements; if successful, we print `gcdo`.
 * If neither condition holds, we flush `0` to the output stream with absolute mathematical precision at raw silicon speed!
 */




#include <bits/stdc++.h>
using namespace std;


void solve() {
    long long n;
    cin >> n;
    vector<long long > a(n);

    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    long long gcde = 0,gcdo=0;
    for(int i =0;i<n;i++){
        if(i%2 == 1){//odd index
            gcdo = __gcd(gcdo,a[i]);
        }else{
            gcde = __gcd(gcde,a[i]);
        }
    }

    //check if any odd index element is dicisible by gcde or not
    bool flag = true;
    for(int i=1;i<n;i+=2){
        if(a[i]%gcde == 0){
            flag = false;
            break;
        }
    }

    if(flag){
        cout << gcde << endl;
        return;
    }

    //check if any even index element is dicisible by gcdo or not
    flag = true;
    for(int i=0;i<n;i+=2){
        if(a[i]%gcdo == 0){
            flag = false;
            break;
        }
    }

    if(flag){
        cout << gcdo << endl;
    }else{
        cout << 0 << endl ;
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();  
    }

    return 0;
}
