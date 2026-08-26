/*
Codeforces - 1883C. Raspberries
Time limit per test: 2 seconds
Memory limit per test: 256 megabytes

You are given an array of integers a_1, a_2, ..., a_n and a number k (2 <= k <= 5). In one operation, you can do the following:
Choose an index 1 <= i <= n,
Set a_i = a_i + 1.

Find the minimum number of operations needed to make the product of all the numbers in the array a_1 * a_2 * ... * a_n divisible by k.

Input
Each test consists of multiple test cases. The first line contains a single integer t (1 <= t <= 10^4) — the number of test cases. Then follows the description of the test cases.
The first line of each test case contains two integers n and k (2 <= n <= 10^5, 2 <= k <= 5) — the size of the array a and the number k.
The second line of each test case contains n integers a_1, a_2, ..., a_n (1 <= a_i <= 10).
It is guaranteed that the sum of n over all test cases does not exceed 2 * 10^5.

Output
For each test case, output the minimum number of operations needed to make the product of all the numbers in the array divisible by k.
*/

/* Approach - Greedy Modulo Targeting / Parity Case Collapse (Time: O(N), Space: O(N))
 * Basically, we completely annihilate the need to simulate actual addition operations by violently projecting every number onto a modulo field, locking in the absolute minimum distance to the next multiple, while aggressively deploying a specialized parity interceptor for the notorious k=4 trap!
 * * Observation: 
 * - The absolute core of this architecture is the `k = 4` override! You brilliantly realized that to make the total product divisible by 4, you don't physically need to forge a pure multiple of 4! You can mathematically combine TWO multiples of 2! You flawlessly mapped the state space: 0 evens cost 2 moves, 1 even costs 1 move, and 2 evens cost absolutely zero!
 * - (The Fatal Mismatch Trap): Look incredibly closely at your initialization: `long long ans = INT_MAX;`. You structurally requested a massive 64-bit register, but you loaded it with a strict 32-bit ceiling (`~2.1e9`)! While it mathematically survives the constraints of this specific problem, in high-stakes competitive programming, a type-mismatch like this can violently collapse into a Wrong Answer! Always deploy `LLONG_MAX` (or `1e18`) to completely seal the 64-bit dimension!
 * - (Optimization Alert 1 / The Modulo Wrap-Around): You wrote an explicit `if (a[i] % k == 0) ans = 0;`. You can completely shred this `if` statement by deploying a flawless mathematical wrap-around: `ans = min(ans, (k - (a[i] % k)) % k);`. If it's perfectly divisible, `k - 0` yields `k`, and `% k` instantly violently snaps it back to `0`! 
 * - (Optimization Alert 2 / The O(1) Space Annihilation): Your logic is mathematically pristine, but you aggressively burn O(N) memory allocating `vector<long long> a(n)`! You NEVER look backward! You only care about the *current* element's modulo distance and its parity! You can completely destroy the vector and process `cin >> current_val` on the fly inside a single O(N) loop! This ruthlessly shreds your auxiliary space complexity down to absolute peak O(1)!
 * * How it runs:
 * First, we safely intercept the boundaries `n` and `k` using our fast I/O engine, and instantly ignite a high-speed linear sweep.
 * For every single incoming element, our dual-radar triggers! If the element is purely even, we aggressively increment our `even_count` ammo reserve.
 * We violently calculate the exact mathematical distance to the next multiple using `k - (a[i] % k)` and continuously lock the absolute minimum distance into our `ans` register.
 * The exact millisecond the sweep completely collapses, we deploy the `k == 4` interceptor! We forcefully pit our single-element modulo distance directly against the dual-even strategy.
 * We aggressively smash the timelines together using `min()`, securely lock in the absolute lowest operational cost, and confidently output the payload!
 */



#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, k;
		cin >> n >> k; 
		vector<long long> a(n);
		for (long long i = 0; i < n; i++) 
			cin >> a[i];

		long long ans = INT_MAX; // 
		long long even_count = 0; //count of even number
		for (long long i = 0; i < n; i++)
		{
			if (a[i] % 2 == 0)
				even_count++; 
			if (a[i] % k == 0)
				ans = 0; // If a element is divisible by k, no operations are needed
			ans = min(ans, (k - a[i] % k)); 
		}
		if (k == 4)
		{
			if (even_count >= 2)
				ans = min(ans, 0LL); //if there are at least two even numbers, no operations are needed
			else if (even_count == 1)
				ans = min(ans, 1LL); //if there is one even number, one operation is needed
			else if (even_count == 0)
				ans = min(ans, 2LL); //if there are no even numbers, two operations are needed
		}
		cout << ans << endl;

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
