/*
Codeforces PS - 1726A. Mainak and Array
time limit per test: 1 second
memory limit per test: 256 megabytes

Mainak has an array a1, a2, …, an of n positive integers. He will do the following operation to this array exactly once:
Pick a subsegment of this array and cyclically rotate it by any amount.

Formally, he can do the following exactly once:
Pick two integers l and r, such that 1 ≤ l ≤ r ≤ n, and any positive integer k.
Repeat this k times: set al = al+1, al+1 = al+2, …, ar−1 = ar, ar = al (all changes happen at the same time).
Mainak wants to maximize the value of (an − a1) after exactly one such operation. Determine the maximum value of (an − a1) that he can obtain.

Input
Each test contains multiple test cases. The first line contains a single integer t (1 ≤ t ≤ 50) — the number of test cases. Description of the test cases follows.
The first line of each test case contains a single integer n (1 ≤ n ≤ 2000).
The second line of each test case contains n integers a1, a2, …, an (1 ≤ ai ≤ 999).
It is guaranteed that the sum of n over all test cases does not exceed 2000.

Output
For each test case, output a single integer — the maximum value of (an − a1) that Mainak can obtain by doing the operation exactly once.

Time Complexity: O()
Space Complexity: O()
*/


/* Approach - Greedy Case Analysis / Cyclic Shift Permutations (Time: O(N), Space: O(N))
 * Basically, we aggressively evaluate the only three mathematically possible ways to isolate the absolute maximum difference between the first and last elements using cyclic shifts, and simply take the best one!
 * * Observation: 
 * - The core objective is to maximize the value of `a[n-1] - a[0]`. You are allowed to cyclically shift any continuous subarray. 
 * - When you break down the cyclic shift operations, there are only three distinct strategic moves that actually matter:
 *   1. (Prefix Shift): Securely anchor the last element in place, and rotate a prefix of the array to drag any element `a[i]` directly to the front `a[0]`. Potential gain = `last - a[i]`.
 *   2. (Suffix Shift): Safely lock the first element in place, and rotate a suffix of the array to drag any massive element `a[i]` directly to the back `a[n-1]`. Potential gain = `a[i] - first`.
 *   3. (Full Array Shift): Grab the entire array and rotate it as a single massive block! This brutally splits any adjacent pair `a[i]` and `a[i+1]`, wrapping `a[i+1]` to the front and pushing `a[i]` to the absolute back. Potential gain = `a[i] - a[i+1]`.
 * - By checking these three strict conditions for every single element, we mathematically guarantee we will find the absolute most optimal move without ever actually simulating a single shift!
 * * How it runs:
 * First, we safely extract the array size `n` and trigger a quick sweep to fully populate our `vector a`.
 * Then, we securely isolate our absolute `last` element `a[n-1]` and `first` element `a[0]`, anchoring our `maxdiff` baseline directly to the array's current, unshifted state (`a[n-1] - a[0]`).
 * Next, we trigger a high-speed linear sweep from `0` to `n-2`. At every single step, we fiercely pit our running `maxdiff` against the absolute best outcomes from all three mathematical scenarios simultaneously using C++'s initializer list `max({ ... })`!
 * Finally, once the sweep seamlessly exhausts all possible permutations, our `maxdiff` has successfully trapped the absolute highest possible difference, and we confidently print the result!
 */


#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    

    vector<int> a(n);
    for(int i = 0; i <n; i++){
        cin >> a[i];
    }
    int last = a[n-1];
    int first = a[0];
    int maxdiff = a[n-1]-a[0];
    for(int i =0;i<n-1;i++){
        maxdiff = max({maxdiff, (last - a[i]),(a[i]-first),(a[i] - a[i+1])});
    }
    cout << maxdiff <<"\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        solve();  

    return 0;
}
