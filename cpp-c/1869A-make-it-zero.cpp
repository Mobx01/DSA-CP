/*
Codeforces PS - 1869A. Make It Zero
time limit per test: 1 second
memory limit per test: 256 megabytes

During Zhongkao examination, Reycloer met an interesting problem, but he cannot come up with a solution immediately. Time is running out! Please help him.
Initially, you are given an array a consisting of n ≥ 2 integers, and you want to change all elements in it to 0.

In one operation, you select two indices l and r (1 ≤ l ≤ r ≤ n) and do the following:
Let s = al ⊕ al+1 ⊕ … ⊕ ar, where ⊕ denotes the bitwise XOR operation;
Then, for all l ≤ i ≤ r, replace ai with s.

You can use the operation above in any order at most 8 times in total.
Find a sequence of operations, such that after performing the operations in order, all elements in a are equal to 0. It can be proven that the solution always exists.

Input
The first line of input contains a single integer t (1 ≤ t ≤ 500) — the number of test cases. The description of test cases follows.
The first line of each test case contains a single integer n (2 ≤ n ≤ 100) — the length of the array a.
The second line of each test case contains n integers a1, a2, …, an (0 ≤ ai ≤ 100) — the elements of the array a.

Output
For each test case, in the first line output a single integer k (0 ≤ k ≤ 8) — the number of operations you use.
Then print k lines, in the i-th line output two integers li and ri (1 ≤ li ≤ ri ≤ n) representing that you select li and ri in the i-th operation.
Note that you do not have to minimize k. If there are multiple solutions, you may output any of them.
*/


/* Approach - Parity Checking & Subarray XOR Cancellation (Time: O(N), Space: O(N))
 * Basically, we completely ignore the actual values of the array and mathematically exploit the property of XOR sums on even-length subarrays to systematically nuke every single element down to exactly zero in just 2 or 4 fixed moves!
 * * Observation: 
 * - When you replace a subarray with its total XOR sum, all elements in that range instantly become identical. If that subarray has an *even* number of elements, taking the XOR sum of it *again* will XOR an even number of identical values, which mathematically guarantees a perfect 0! (e.g., X ^ X ^ X ^ X = 0).
 * - If our total array length `n` is perfectly even, the solution is beautifully simple: we effortlessly blast the entire array `[1, n]` twice. The first move makes them all identical, and the second move instantly annihilates them all to 0!
 * - If `n` is awkwardly odd, we cannot do the whole array at once (an odd number of identical elements XORs to the element itself, not 0). Instead, we brilliantly target just the first `n-1` elements (which is now an even length!) and double-blast them to 0. 
 * - Then, we take the leftover last element at index `n` and group it with the freshly zeroed `n-1` element. This forms a new even-length subarray `[n-1, n]` of size 2, which we simply double-blast again to wipe the rest of the board!
 * - (Optimization Note: The code aggressively allocates memory for `vector<int> x` and stores every single element, but physically never uses them! We could elegantly drop the vector entirely and just read the inputs into a temporary dummy variable, instantly slashing our auxiliary space down to a flawless O(1)!)
 * * How it runs:
 * First, we safely extract the array size `n` and trigger a quick loop just to consume the `n` integer inputs from the stream, tossing them into `x` but completely ignoring them for the actual logic.
 * Then, we mathematically evaluate the parity of `n`. If it is perfectly even (`n % 2 == 0`), we aggressively print `2` operations and command the system to double-blast the entire `[1, n]` range.
 * If `n` is odd, we seamlessly pivot our strategy. We confidently print `4` operations. We first double-blast the even-length prefix `[1, n-1]` to safely zero out the vast majority of the array.
 * Finally, we group the untouched `n`-th element with the newly zeroed `(n-1)`-th element, and double-blast that strict `[n-1, n]` pair, confidently leaving the entire array completely zeroed out!
 */

#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<int> x(n);
    for(int i = 0;i<n;i++){
        cin >> x[i];
    }
    if(n%2 ==0){//even n
        cout << 2 <<"\n";
        cout << 1 << " " << n << "\n";    
        cout << 1 << " " << n << "\n";    
    }else{
        cout << 4 <<"\n";
        cout << 1 << " " << n-1 << "\n";    
        cout << 1 << " " << n-1 << "\n";    
        cout << n-1 << " " << n << "\n";    
        cout << n-1 << " " << n << "\n";    
    }

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
