
/*
Codeforces - 1374B. Multiply by 2, divide by 6
Time limit per test: 1 second
Memory limit per test: 256 megabytes

You are given an integer n. In one move, you can either multiply n by two or divide n by 6 (if it is divisible by 6 without the remainder).

Your task is to find the minimum number of moves needed to obtain 1 from n or determine if it's impossible to do that.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1 <= t <= 2 * 10^4) — the number of test cases. Then t test cases follow.
The only line of the test case contains one integer n (1 <= n <= 10^9).

Output
For each test case, print the answer — the minimum number of moves needed to obtain 1 from n if it's possible to do that or -1 if it's impossible to obtain 1 from n.
*/

/* Approach - Prime Factorization / Pure State Space Collapse (Time: O(log N), Space: O(1))
 * Basically, we completely annihilate the infinite recursive state space of multiplying and dividing by violently collapsing the integer into its pure prime factors, mathematically calculating the exact operation count in absolute peak O(log N) hardware speed!
 * * Observation: 
 * - The absolute core of this puzzle is prime manipulation! The operation `/6` violently destroys exactly one power of 3 and one power of 2. The operation `*2` artificially injects exactly one power of 2. Notice the asymmetry: you have absolute control over generating 2s, but you mathematically CANNOT create 3s!
 * - (The Absolute Game-Breaker 1 / The Contamination Check): `if(n > 1)`. This is a flawless structural radar! If the number contains ANY prime factors other than 2 or 3 (like a rogue 5, 7, or 11), they physically cannot be destroyed by `/6`! By violently stripping out all the 2s and 3s, if the remaining core is greater than 1, the timeline is mathematically contaminated and you instantly abort with `-1`!
 * - (The Absolute Game-Breaker 2 / The Deficit Trap): `(count2 > count3)`. Because you can never generate new 3s, every single 2 MUST eventually be paired with a 3 to be annihilated by `/6`. If your starting number is structurally bottom-heavy with more 2s than 3s, the puzzle is a mathematical trap! You flawlessly catch this deficit and ruthlessly shut it down with `-1`!
 * - (The Master Equation): `count3 + (count3 - count2)`. Absolute algebraic perfection! You completely bypassed simulating the moves! You mathematically proved that you MUST perform exactly `count3` divisions to completely shred the 3s. To fuel those divisions, you require an identical number of 2s. If you are short on 2s, you must manually forge them using exactly `(count3 - count2)` multiplication operations!
 * - (The 64-Bit Shield): You brilliantly ingested `n` into a massive `long long` register. Even though the constraints might fit in 32-bit, shielding division engines with 64-bit architecture guarantees zero precision loss or truncation during the high-speed prime extraction!
 * * How it runs:
 * First, we safely intercept `n` using our fast I/O stream, instantly locking it into a 64-bit engine.
 * We ignite the high-speed prime extraction loops! We aggressively modulo and divide, violently stripping out every single structural 3 and recording the timeline in `count3`.
 * We repeat the assault for the 2s, ruthlessly amputating them and logging the total in `count2`.
 * We trigger the dual-radar check: if the remaining husk is contaminated (`n > 1`) or structurally doomed from an overabundance of 2s (`count2 > count3`), we forcefully reject the sequence and print `-1`.
 * Otherwise, the math is pristine! We violently smash the two counters into our master equation and confidently output the exact minimum operations required, flawlessly crushing the problem without allocating a single BFS queue!
 */


#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;

    int count3 =0 ,count2=0;
    while(n>0 && n%3 ==0){
        count3++;
        n /= 3;
    }
    while(n>0 && n%2 ==0){
        count2++;
        n /= 2;
    }

    if(n>1 || (count2 > count3)){
        cout << -1 << endl;
    }else{
        cout << count3 + (count3-count2) << endl;
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();  
    }
    return 0;
}
