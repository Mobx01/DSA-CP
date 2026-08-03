/*
Codeforces PS - 1828B. Permutation Swap
time limit per test: 1 second
memory limit per test: 256 megabytes

You are given an unsorted permutation p1, p2, …, pn. To sort the permutation, you choose a constant k (k ≥ 1) and do some operations on the permutation. In one operation, you can choose two integers i, j (1 ≤ j < i ≤ n) such that i − j = k, then swap pi and pj.

What is the maximum value of k that you can choose to sort the given permutation?

A permutation is an array consisting of n distinct integers from 1 to n in arbitrary order. For example, [2, 3, 1, 5, 4] is a permutation, but [1, 2, 2] is not a permutation (2 appears twice in the array) and [1, 3, 4] is also not a permutation (n = 3 but there is 4 in the array).

An unsorted permutation p is a permutation such that there is at least one position i that satisfies pi ≠ i.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1 ≤ t ≤ 10^4). The description of the test cases follows.
The first line of each test case contains a single integer n (2 ≤ n ≤ 10^5) — the length of the permutation p.
The second line of each test case contains n distinct integers p1, p2, …, pn (1 ≤ pi ≤ n) — the permutation p. It is guaranteed that the given numbers form a permutation of length n and the given permutation is unsorted.
It is guaranteed that the sum of n over all test cases does not exceed 2⋅10^5.

Output
For each test case, output the maximum value of k that you can choose to sort the given permutation.
We can show that an answer always exists.
*/


/* Approach - Greatest Common Divisor (GCD) / Permutation Displacement (Time: O(N), Space: O(N))
 * Basically, we mathematically calculate the exact distance every single element needs to travel to reach its perfectly sorted position, and aggressively compute the Greatest Common Divisor (GCD) of all those distances to find the absolute maximum allowable jump size!
 * * Observation: 
 * - In a standard 1-based permutation, every single element value `p[i]` inherently belongs at that exact physical index `p[i]`.
 * - If an element is currently sitting at index `i+1`, the absolute total distance it MUST physically travel to get back home is strictly `abs((i+1) - p[i])`.
 * - If we are strictly restricted to swapping elements that are exactly `k` positions apart, an element can mathematically only ever move in perfect multiples of `k`. Therefore, for EVERY single misplaced element to successfully reach its destination, our jump size `k` MUST be a perfect divisor of every single element's required travel distance!
 * - To find the absolute maximum possible `k` that brilliantly satisfies this strict condition for the entire array, we simply compute the Greatest Common Divisor (GCD) of all those individual absolute displacements!
 * - (Optimization Note: The code dynamically allocates a full `vector<int> p(n)`, burning O(N) auxiliary space. Since we only ever need the current index and the current input value to calculate the displacement, we could elegantly compute the GCD completely on the fly as we read the stream, instantly dropping the space complexity down to a flawless, guaranteed O(1)!)
 * * How it runs:
 * First, we safely extract the permutation size `n` and sweep through to fully populate our `vector p`.
 * Then, we securely anchor our running `res` tracker with the absolute displacement of the very first element (at 1-based index 1): `abs(p[0] - 1)`.
 * Next, we trigger a high-speed linear sweep through the rest of the array. At every single step, we fiercely calculate the exact required travel distance for the current element `abs((i+1) - p[i])`.
 * We instantly fold that new distance into our running result by aggressively applying C++'s built-in `gcd()` function, mathematically squeezing `res` down to the absolute largest common jump size that still perfectly divides all paths seen so far.
 * Finally, once the sweep finishes and all distances are flawlessly factored in, our `res` holds the absolute maximum valid swap distance `k`, and we confidently print it out!
 */

#include <bits/stdc++.h>
using namespace std;


void solve() {
    int  n;
    cin >> n;
    vector<int> p(n);
    for(int i =0;i<n;i++){
        cin >> p[i];
    }
    int res = abs(p[0] - 1);
    for(int i = 1;i<n;i++){
        res = gcd(res,abs((i+1) - p[i]));
    }
    cout << res <<"\n";
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
