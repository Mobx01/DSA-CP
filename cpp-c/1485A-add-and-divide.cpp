/*
Codeforces - 1485A. Add and Divide
Time limit per test: 1 second
Memory limit per test: 256 megabytes

You have two positive integers a and b.

You can perform two kinds of operations:
a = \lfloor a / b \rfloor (replace a with the integer part of the division between a and b)
b = b + 1 (increase b by 1)

Find the minimum number of operations required to make a = 0.

Input
The first line contains a single integer t (1 <= t <= 100) — the number of test cases.
The only line of the description of each test case contains two integers a, b (1 <= a, b <= 10^9).

Output
For each test case, print a single integer: the minimum number of operations required to make a = 0.
*/



/* Approach - Bounded Base Increment Simulation / Exhaustive Search over Divisor Space (Time: O(log_B(A) * C), Space: O(1))
 * Basically, we completely annihilate complex mathematical derivations by aggressively exploiting problem constraints, bounding the search space of base increments to a tiny constant range and simulating the division steps to find the global minimum!
 * * Observation: 
 * - The absolute core of this architecture is the Small-Search-Space Masterstroke (Codeforces 1485A - Add and Divide)! For typical constraints where $a \le 10^9$, the number of divisions required to reduce $a$ to 0 is at most ~30 when the base is $\ge 2$. Because increasing $b$ beyond a small threshold rapidly diminishes the division count, testing all base increments from 0 to 35 covers every single optimal configuration with zero risk of TLE!
 * - (The Infinite-Loop Division Trap): If $b = 1$, dividing $a$ by $b$ leaves $a$ completely unchanged, creating an infinite loop. Your code brilliantly intercepts this catastrophe via `if (newb == 1) continue;`, ensuring that division is only ever executed on valid bases $\ge 2$.
 * - (The `INT_MAX` Sentinel Safety): Initializing `minop = INT_MAX` provides a safe upper bound. However, since $a$ can be up to $10^9$, ensure your scalar operations and comparisons don't overflow, though here `long long` handles all intermediate counts cleanly.
 * * How it runs:
 * First, we safely intercept inputs `a` and `b`.
 * We ignite an outer loop iterating through possible increments `add` from 0 to 35, computing the candidate base `newb = b + add`.
 * If `newb == 1`, we instantly skip to prevent division by one.
 * For each valid base, we simulate the reduction of `a` via an inner division loop, counting total operations (`add` increments + division steps).
 * We continuously track the global minimum operations across all tested bases, and finally flush the optimal result to the output stream at raw silicon speed!
 */



#include <bits/stdc++.h>
using namespace std;


void solve() {
    long long a,b;
    cin >> a>>b;

    long long minop = INT_MAX;

    for(int add = 0;add <= 35 ; add++){
        long long op = add;
        long long newb = b + add;
        if(newb == 1) continue;
        
        long long ac = a;
        while(ac >0){
            op++;
            ac = ac/newb;
        }
        minop = min(op,minop);
    }

    cout << minop << endl;
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
