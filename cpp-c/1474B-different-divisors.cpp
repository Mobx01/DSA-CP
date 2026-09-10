/*
Codeforces - 1474B. Different Divisors
Time limit per test: 1 second
Memory limit per test: 256 megabytes

Positive integer x is called divisor of positive integer y, if y is divisible by x without remainder. For example, 1 is a divisor of 7 and 3 is not divisor of 8.

We gave you an integer d and asked you to find the smallest positive integer a, such that
a has at least 4 divisors;
difference between any two divisors of a is at least d.

Input
The first line contains a single integer t (1 <= t <= 3000) — the number of test cases.
The first line of each test case contains a single integer d (1 <= d <= 10000).

Output
For each test case print one integer a — the answer for this test case.
*/



/* Approach - Prime Sieve & Binary Search Lower-Bound Lookups / Divisor Constraint Annihilation (Time: O(Limit log(log Limit) + T log P), Space: O(Limit))
 * Basically, we completely annihilate complex divisor verification by aggressively leveraging prime spacing constraints, mathematically selecting the optimal prime candidates $p$ and $q$ to form the smallest valid number with constrained gaps!
 * * Observation: 
 * - The absolute core of this architecture is the Minimum Prime Gap Selection! To ensure all divisors are spaced by at least `d`, you must find the smallest prime $p \ge 1 + d$ and the smallest subsequent prime $q \ge p + d$. The answer is then cleanly derived from the minimum of two structural candidates: $p^3$ (divisors $1, p, p^2, p^3$) and $pq$ (divisors $1, p, q, pq$). Your code brilliantly captures this exact mathematical invariant!
 * - (The Linear Search Bottleneck): Your prime lookup strategy uses a linear scan (`for(long long i=0; i<primes.size(); i++)`). Because the `primes` vector is already strictly sorted in ascending order, scanning linearly per test case introduces unnecessary CPU overhead. You can completely replace the manual loop with `std::lower_bound(primes.begin(), primes.end(), target)` to instantly drop lookup time down to O(log P) via binary search!
 * - (The Trial-Division Sieve Inefficiency): Your prime generation loop uses nested trial division ($O(\text{limit} \sqrt{\text{limit}})$). While an upper limit of 100,000 is small enough to pass within time limits, replacing it with the classic Sieve of Eratosthenes completely strips away division hardware overhead, generating the prime table at blistering raw silicon speed.
 * - (The Global Pre-computation Win): Instantiating the `primes` vector globally and populating it once inside `main` before processing test cases is pristine engineering. It ensures zero redundant work across multiple test cases, keeping runtime optimal.
 * * How it runs:
 * First, the program ignites its prime generation phase, populating our global `primes` registry up to the safe constraint threshold.
 * When `solve()` is invoked, we intercept the gap requirement `d`.
 * We search our prime registry for the smallest prime $p$ satisfying $p \ge 1 + d$, followed by the smallest prime $q$ satisfying $q \ge p + d$. (Optimizable to O(log P) via binary search).
 * We evaluate our two structural candidates via `min(p^3, pq)` using safe 64-bit casting to prevent overflow.
 * Finally, we flush the optimal minimum integer to the output stream with absolute mathematical precision at raw silicon speed!
 */



#include <bits/stdc++.h>
using namespace std;

vector<int> primes;

void solve() {
    long long d;
    cin >> d;

    long long p = -1;
    for(long long i=0;i<primes.size();i++){
        if(primes[i] >= (1+d)){
            p = primes[i];
            break;
        }
    }
    long long q = -1; 
    for(long long i=0;i<primes.size();i++){
        if(primes[i] >= (p+d)){
            q = primes[i];
            break;
        }
    }

    long long a = min(1LL * p * p * p, 1LL * p * q);
	cout << a << endl;
}



int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(long long i = 2 ;i <= 100000;i++){
        bool is_prime = true;
        for(long long j= 2;j*j <= i;j++){
            if(i%j == 0){
                is_prime = false;
                break;
            }
        }
        if(is_prime){
            primes.push_back(i);
        }
    }
    
    int t;
    cin >> t;
    while(t--) {
        solve();  
    }

    return 0;
}
