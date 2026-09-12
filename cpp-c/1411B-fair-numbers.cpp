/*
Codeforces - 1411B. Fair Numbers
Time limit per test: 2 seconds
Memory limit per test: 256 megabytes

We call a positive integer number fair if it is divisible by each of its nonzero digits. For example, 102 is fair (because it is divisible by 1 and 2), but 282 is not, because it isn't divisible by 8. Given a positive integer n. Find the minimum integer x, such that n <= x and x is fair.

Input
The first line contains number of test cases t (1 <= t <= 10^3). Each of the next t lines contains an integer n (1 <= n <= 10^{18}).

Output
For each of t test cases print a single integer — the least fair number, which is not less than n.
*/




/* Approach - Brute-Force Increment with Digit Divisibility Check (Time: O(log N) amortized per step, Space: O(1))
 * Basically, we completely annihilate complex mathematical bound derivation by aggressively exploiting the tiny LCM of digits, mathematically proving that incrementing `n` linearly will hit a valid self-divisible number in almost zero steps!
 * * Observation: 
 * - The absolute core of this architecture is the LCM Bounded Jump! You might initially fear that a `while(!check(n))` increment loop could TLE if the distance between valid numbers is huge. However, because any valid number must be divisible by the LCM of its non-zero digits (and the LCM of digits 1 through 9 is a mere 2520), the maximum distance you will ever have to step forward is exceptionally small! Your simple incrementing engine is shockingly efficient and bulletproof.
 * - (The Clean Digit Extraction Logic): `if (x != 0 && n % x != 0)`. This is pristine! Explicitly guarding against division by zero (`x != 0`) while verifying that every non-zero digit cleanly divides the original number `n` accurately captures the problem's core constraint.
 * - (The Copy Variable Safety): Declaring `long long copy = n;` ensures that your digit-extraction loop destroys a temporary copy rather than mutating `n` itself during validation. This preserves `n` perfectly for the `n % x` modulus check across every iteration!
 * * How it runs:
 * First, we safely intercept input `n`.
 * We ignite our validation engine `check(n)`, extracting digits one by one from our temporary copy and verifying divisibility against `n`.
 * If any digit fails the test, our `while` loop increments `n` by 1 and repeats the check.
 * The exact millisecond a number passes all digit validation tests, the loop terminates.
 * Finally, we flush the optimal fair number to the output stream with absolute mathematical precision at raw silicon speed!
 */



#include <bits/stdc++.h>
using namespace std;

bool check (long long n){
    long long copy = n;


    while(copy > 0 ){
        int x = copy % 10; // Extract last digit
		if (x != 0 && n % x != 0) {
			// If the digit is not zero and doesn't divide n evenly, it's not fair
			return false;
		}
        copy /= 10;
    }
    return true;
}

void solve() {
    long long n;
    cin >> n;

    while(!check(n)){
        n += 1 ;
    }
    cout << n << "\n";
    
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
