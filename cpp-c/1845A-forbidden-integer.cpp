/*Codeforces PS - 1845A. Forbidden Integer

You are given an integer n, which you want to obtain. You have an unlimited supply of every integer from 1 to k, except integer x (there are no integer x at all).

You are allowed to take an arbitrary amount of each of these integers (possibly, zero). Can you make the sum of taken integers equal to n?
If there are multiple answers, print any of them.

Input
The first line contains a single integer t (1 ≤ t ≤ 100) — the number of testcases.
The only line of each testcase contains three integers n, k and x (1 ≤ x ≤ k ≤ n ≤ 100).

Output
For each test case, in the first line, print "YES" or "NO" — whether you can take an arbitrary amount of each integer from 1 to k, except integer x, so that their sum is equal to n.
If you can, the second line should contain a single integer m — the total amount of taken integers. The third line should contain m integers — each of them from 1 to k, not equal to x, and their sum is n.
If there are multiple answers, print any of them.
*/

/* Approach - Constructive Algorithm & Parity Case Analysis (Time: O(N), Space: O(1))
 * Basically, we use a greedy case-by-case strategy to construct the sum 'n' using the smallest possible allowed numbers.
 * * Observation: 
 * - The easiest and most flexible way to build any sum is by repeatedly adding 1. If our forbidden number 'x' is NOT 1, we can just blindly use 'n' copies of 1 to reach our target sum!
 * - If 'x' is exactly 1, we are forced to use larger numbers. If our maximum allowed number 'k' is also 1, we have zero valid numbers to use, making it impossible.
 * - If 'k' is 2 (and 1 is forbidden), our ONLY valid building block is 2. Therefore, we can only successfully construct 'n' if it is an even number.
 * - If 'k' is 3 or greater, we have access to both 2 and 3. Mathematically, any integer >= 2 can be formed using a combination of 2s and at most a single 3 (even numbers use all 2s, odd numbers use one 3 and the rest 2s).
 * * How it runs:
 * First, we check if 'x' is not 1. If true, we immediately print "YES", the size 'n', and a loop of 'n' 1s, then return early.
 * Then, knowing 'x' is 1, we check our 'k' limits. If 'k == 1', we print "NO".
 * Next, if 'k == 2', we check if 'n' is even ('n % 2 == 0'). If it is, we print 'n / 2' copies of 2. If it's odd, we print "NO".
 * Finally, for all 'k >= 3', we know it's always possible. We check 'n's parity: if it's even, we print 'n / 2' copies of 2. If it's odd, we print a single 3 followed by '(n - 3) / 2' copies of 2!
 */

#include <iostream>
using namespace std;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;

    if (x != 1) {
        cout << "YES\n";
        cout << n << "\n";
        for (int i = 0; i < n; i++) cout << 1 << " ";
        cout << "\n";
        return; 
    }
    

    if (k == 1) {
        cout << "NO\n";
    } else if (k == 2) {
        // We can only use 2 if n is even.
        if (n % 2 == 0) {
            cout << "YES\n";
            cout << n / 2 << "\n";
            for (int i = 0; i < n / 2; i++) cout << 2 << " ";
            cout << "\n";
        } else {
            cout << "NO\n";
        }
    } else {
        // We can use 2 and 3 to form any integer n >= 2.
        cout << "YES\n";
        cout << n / 2 << "\n"; // The number of elements will always be n/2
        
        if (n % 2 == 0) {
            for (int i = 0; i < n / 2; i++) cout << 2 << " ";
        } else {
            cout << 3 << " ";
            for (int i = 0; i < (n - 3) / 2; i++) cout << 2 << " ";
        }
        cout << "\n";
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
