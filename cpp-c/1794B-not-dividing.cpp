/*
Codeforces PS - 1794B. Not Dividing
time limit per test: 2 seconds
memory limit per test: 256 megabytes

You are given an array of n positive integers a1, a2, …, an. In one operation, you can choose any number of the array and add 1 to it.
Make at most 2n operations so that the array satisfies the following property: ai+1 is not divisible by ai, for each i = 1, 2, …, n - 1.
You do not need to minimize the number of operations.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1 ≤ t ≤ 10^4). The description of the test cases follows.
The first line of each test case contains an integer n (1 ≤ n ≤ 10^4) — the length of the given array.
The second line of each test case contains n integers a1, a2, …, an (1 ≤ ai ≤ 10^9) — the given array.
It is guaranteed that the sum of n over all test cases does not exceed 5⋅10^4.

Output
For each test case, print the answer on a separate line.
In the only line, print n integers — the resulting array a after applying at most 2n operations.
We can show that an answer always exists under the given constraints. If there are multiple answers, print any of them.
*/

/* Approach - Greedy Array Modification / Divisibility Elimination (Time: O(N), Space: O(N))
 * Basically, we aggressively hunt down and completely eradicate all 1s from the array because they maliciously divide everything, and then mathematically break any remaining divisibility chains by incrementing the violating element by exactly one!
 * * Observation: 
 * - The number 1 is a universal divisor! If we leave a `1` at `a[i]`, it will flawlessly divide literally any number placed at `a[i+1]`. By aggressively incrementing every single `1` to a `2` the exact millisecond we read it, we permanently destroy this mathematical trap!
 * - Once all 1s are wiped off the board (meaning `a[i] >= 2` for all elements), fixing a divisibility violation is beautifully simple. If `a[i+1] % a[i] == 0`, adding exactly 1 to `a[i+1]` mathematically GUARANTEES it will no longer be divisible! (e.g., if 10 % 5 == 0, 11 % 5 is absolutely not).
 * - Because we process the array strictly left-to-right, fixing `a[i+1]` might change its value, but it mathematically cannot retroactively break the already-secured `a[i] % a[i-1] != 0` condition!
 * - (Optimization/Redundancy Note: In your second loop, you redundantly check `if(a[i] == 1) a[i]++;` again! Since you brilliantly already caught and neutralized every single 1 directly inside the first input loop, this line is completely dead code and can be elegantly deleted to clean up your logic!)
 * * How it runs:
 * First, we safely extract the array size `n` and trigger our first sweep to populate `vector a`. During this exact step, if any incoming element is a `1`, we instantly bump it to `2` to securely shield our array.
 * Then, we trigger a high-speed linear sweep from `0` to `n-2`. At every single step, we fiercely check if the next element `a[i+1]` is perfectly divisible by our current element `a[i]`.
 * The exact millisecond we detect a perfect division, we aggressively increment `a[i+1]` by exactly 1, flawlessly severing the mathematical link in a single, perfectly optimal operation.
 * Finally, once the sweep finishes, our array is completely insulated from any adjacent divisibility, and we confidently print out the strictly valid sequence!
 */


#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    

    vector<long long> a(n);
    for(int i = 0; i <n; i++){
        cin >> a[i];
        if(a[i] == 1) a[i]++;
    }

    for(int i=0;i<n-1;i++){
        if(a[i] == 1) a[i]++;
        if(a[i+1]%a[i] == 0){
            a[i+1]++;
        }
    }
    for(int i =0;i<n;i++){
        cout<< a[i] <<" ";
    }
    cout << "\n";
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
