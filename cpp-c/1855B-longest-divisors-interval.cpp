/*
Codeforces PS - 1855B. Longest Divisors Interval

Given a positive integer n, find the maximum size of an interval [l, r] of positive integers such that, for every i in the interval (i.e., l ≤ i ≤ r), n is a multiple of i.
Given two integers l ≤ r, the size of the interval [l, r] is r - l + 1 (i.e., it coincides with the number of integers belonging to the interval).

Input
The first line contains a single integer t (1 ≤ t ≤ 10^4) — the number of test cases.
The only line of the description of each test case contains one integer n (1 ≤ n ≤ 10^18).

Output
For each test case, print a single integer: the maximum size of a valid interval.
*/


/* Approach - Consecutive Divisor Prefix / LCM Constraint (Time: O(1) [Effectively], Space: O(1))
 * Basically, we aggressively increment a counter starting from 1 to find the absolute longest continuous chain of integers that flawlessly divide our massive target number 'n'!
 * * Observation: 
 * - You might intuitively think the longest interval of consecutive divisors could start anywhere (e.g., 10, 11, 12). But mathematically, if a number is divisible by ANY continuous sequence of length L, it MUST be divisible by all integers from 1 to L! This beautifully guarantees that the absolute longest valid sequence of divisors will ALWAYS simply start directly at 1.
 * - (The Absolute Game-Breaker): What looks like a dangerous O(N) while loop that could cause a catastrophic Time Limit Exceeded (TLE) error is actually a brilliant O(1) constant-time operation! The Least Common Multiple (LCM) of the first ~43 integers astronomically explodes past the maximum mathematical limit of a 64-bit `long long` (10^18). Therefore, it is strictly physically impossible for this loop to execute more than ~43 times before failing! 
 * * How it runs:
 * First, we safely extract our massive incoming integer `n` and securely anchor our testing counter `i` perfectly at 1.
 * Then, we trigger our high-speed while loop, fiercely checking if `n` modulo `i` is exactly 0. As long as the number perfectly divides, we aggressively step `i` forward to test the next consecutive integer.
 * The exact millisecond the modulo check fails, the continuous structural chain is permanently broken, and we instantly crash out of the loop!
 * Finally, because our pointer `i` is currently sitting exactly on the first integer that completely failed the division test, we mathematically step backwards by confidently printing `i - 1`, seamlessly outputting the absolute maximum length of our divisor interval!
 */


#include <bits/stdc++.h>
using namespace std;


void solve() {
    long long n;
    cin >> n;
    int i =1 ;
    while(n%i == 0){
        i++;
    }
    cout << i-1 << endl;

}

int main() {
    // Fast I/O
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--)
        solve();  

    return 0;
}
