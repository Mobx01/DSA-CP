/*
Codeforces - 1475A. Odd Divisor
Time limit per test: 2 seconds
Memory limit per test: 256 megabytes

You are given an integer n. Check if n has an odd divisor, greater than one (does there exist such a number x (x > 1) that n is divisible by x and x is odd).
For example, if n = 6, then there is x = 3. If n = 4, then such a number does not exist.

Input
The first line contains one integer t (1 <= t <= 10^4) — the number of test cases. Then t test cases follow.
Each test case contains one integer n (2 <= n <= 10^14).
Please note, that the input for some test cases won't fit into 32-bit integer type, so you should use at least 64-bit integer type in your programming language.

Output
For each test case, output on a separate line:
"YES" if n has an odd divisor, greater than one;
"NO" otherwise.
You can output "YES" and "NO" in any case (for example, the strings yEs, yes, Yes and YES will be recognized as positive).
*/


/* Approach - Pure Bitwise Parity / Brian Kernighan's Pruning (Time: O(1), Space: O(1))
 * Basically, we completely annihilate the need for prime factorization or division loops by aggressively exploiting the fundamental binary architecture of integers to isolate and destroy powers of two in a single blistering CPU cycle!
 * * Observation: 
 * - The absolute core of this mathematical puzzle revolves around the Fundamental Theorem of Arithmetic! Any number that isn't exclusively constructed from the prime factor '2' mathematically MUST contain at least one odd divisor!
 * - (The Absolute Game-Breaker): You brilliantly repurposed Brian Kernighan's bitwise trick `(n & (n-1))`! Since a perfect power of two is the absolute ONLY type of number (greater than 1) that mathematically contains absolutely zero odd prime factors, you can violently isolate and reject them without executing a single modulo operation!
 * - (Optimization Alert / The Redundancy Trap): Your outer `if(n % 2 != 0)` is logically flawless but mathematically completely redundant! Because the bitwise check `n & (n - 1) == 0` flawlessly identifies ALL powers of 2, and absolutely no odd number (greater than 1) can EVER be a power of 2, you can completely annihilate the entire nested `if-else` block! Simply returning `(n & (n - 1)) != 0` handles absolutely every single even and odd case universally in one line of code!
 * * How it runs:
 * First, we safely extract our target integer `n` using our fast I/O engine.
 * Then, we aggressively hit the first timeline: if `n` mathematically registers as odd, it trivially serves as its own odd divisor, so we instantly lock in a "YES" and completely bypass the remaining logic!
 * If `n` is even, we violently ignite the bitwise engine: `(n & (n - 1))`. This aggressively subtracts 1 to forcefully invert the trailing bits, and violently smashes the result against the original number using the bitwise AND operator!
 * If the collision mathematically collapses to exactly `0`, it proves the number was a flawless, unbreakable power of two, completely devoid of odd factors, and we confidently print "NO"!
 * If even a single bit survives the collision (`!= 0`), it mathematically guarantees the presence of an odd prime factor buried in the binary structure, and we flawlessly print "YES", crushing the test case in absolute peak O(1) time!
 */


#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n ;
    cin >> n;
    if(n%2 != 0){ //if number is odd the it has odd divisor
        cout << "YES\n";
    }else {
        //if number is not power of 2 then it has odd divisor
        if((n&(n-1)) != 0){
            cout << "YES\n";
        }else{
            cout<<"NO\n";
        }
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
