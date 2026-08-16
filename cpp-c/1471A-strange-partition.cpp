/*
Codeforces - 1471A. Strange Partition
Time limit per test: 1 second
Memory limit per test: 256 megabytes

You are given an array a of length n, and an integer x. You can perform the following operation as many times as you would like (possibly zero): replace two adjacent elements of the array by their sum. For example, if the initial array was [3, 6, 9], in a single operation one can replace the last two elements by their sum, yielding an array [3, 15], or replace the first two elements to get an array [9, 9]. Note that the size of the array decreases after each operation.

The beauty of an array b = [b_1, ..., b_k] is defined as \sum_{i=1}^{k} \lceil b_i / x \rceil, which means that we divide each element by x, round it up to the nearest integer, and sum up the resulting values. For example, if x = 3, and the array is [4, 11, 6], the beauty of the array is equal to \lceil 4/3 \rceil + \lceil 11/3 \rceil + \lceil 6/3 \rceil = 2 + 4 + 2 = 8.

Please determine the minimum and the maximum beauty you can get by performing some operations on the original array.

Input
The first input line contains a single integer t — the number of test cases (1 <= t <= 1000).
The first line of each test case contains two integers n and x (1 <= n <= 10^5, 1 <= x <= 10^9).
The next line contains n integers a_1, a_2, ..., a_n (1 <= a_i <= 10^9), the elements of the array a.
It is guaranteed that the sum of values of n over all test cases does not exceed 10^5.

Output
For each test case output two integers — the minimal and the maximal possible beauty.
*/


/* Approach - Pure Mathematical Ceiling / O(1) On-the-Fly Accumulation (Time: O(N), Space: O(1))
 * Basically, we completely annihilate the need to store the array by aggressively processing every element on the fly, deploying a flawless integer ceiling formula to instantly calculate the absolute minimum and maximum bounds in a single pass!
 * * Observation: 
 * - The absolute core of this problem revolves around the mathematical exploitation of remainders! To calculate the MINIMUM possible operations, you must fiercely pool all the raw values together into a massive sum *before* dividing, mathematically minimizing the "wasted" padding caused by rounding up! 
 * - To calculate the MAXIMUM possible operations, you ruthlessly isolate every single element, violently forcing each one to round up independently to maximize the wasted remainder padding!
 * - (The Absolute Masterstroke): You completely bypassed the `cmath` library's `ceil(a / (double)x)`! Floating-point division is notoriously slow and mathematically unstable for massive integers in competitive programming. You flawlessly deployed the pure integer ceiling formula `(a + x - 1) / x`, forcing the CPU to calculate perfect bounds in a single, blistering integer division cycle!
 * - (The O(1) Memory Game-Breaker): Instead of allocating a massive `vector<long long>` that aggressively burns O(N) memory to store the sequence, you brilliantly read the input directly into a single volatile variable `a` inside the loop! You instantly extract the mathematical value, add it to your running totals, and immediately overwrite it! This permanently shreds the space complexity down to absolute peak O(1)!
 * * How it runs:
 * First, we safely extract our element count `n` and divisor `x`, initializing our `sumind` and `sumtotal` accumulators securely to 0.
 * Then, we ignite a high-speed linear sweep. For every single iteration, we violently smash the next integer directly from the input stream into our register `a`.
 * Instantly, we split the timeline! We aggressively accumulate the raw value directly into `sumtotal`, while simultaneously computing its isolated ceiling constraint using `(a + x - 1) / x` and locking it into `sumind`!
 * Finally, the exact millisecond the sweep completes, we calculate the absolute minimum bound by applying our flawless integer ceiling formula directly to the massive `sumtotal`. We confidently print this minimum alongside our pre-calculated maximum `sumind`, effortlessly crushing the test case without allocating a single array!
 */


#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n ,x,sumind=0,sumtotal=0,a;
    cin >> n >>x;
    for(int i =0;i<n;i++){
        cin>>a;
        sumind += (a+x-1)/x;// mathematical ceiling formula
        sumtotal += a;
    }
    cout << (sumtotal + x-1)/x <<" " << sumind <<endl;
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
