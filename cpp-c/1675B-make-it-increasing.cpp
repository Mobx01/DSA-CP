/*
Codeforces PS - 1675B. Make It Increasing
time limit per test: 2 seconds
memory limit per test: 256 megabytes

Given n integers a1, a2, …, an. You can perform the following operation on them:
select any element ai (1 ≤ i ≤ n) and divide it by 2 (round down). In other words, you can replace any selected element ai with the value ⌊ai / 2⌋ (where ⌊x⌋ is – round down the real number x).

Output the minimum number of operations that must be done for a sequence of integers to become strictly increasing (that is, for the condition a1 < a2 < ⋯ < an to be satisfied). Or determine that it is impossible to obtain such a sequence. Note that elements cannot be swapped. The only possible operation is described above.

For example, let n = 3 and a sequence of numbers [3, 6, 5] be given. Then it is enough to perform two operations on it:
Write the number ⌊6 / 2⌋ = 3 instead of the number a2 = 6 and get the sequence [3, 3, 5];
Then replace a1 = 3 with ⌊3 / 2⌋ = 1 and get the sequence [1, 3, 5].
The resulting sequence is strictly increasing because 1 < 3 < 5.

Input
The first line of the input contains an integer t (1 ≤ t ≤ 10^4) — the number of test cases in the input.
The descriptions of the test cases follow.
The first line of each test case contains a single integer n (1 ≤ n ≤ 30).
The second line of each test case contains exactly n integers a1, a2, …, an (0 ≤ ai ≤ 2⋅10^9).

Output
For each test case, print a single number on a separate line — the minimum number of operations to perform on the sequence to make it strictly increasing. If a strictly increasing sequence cannot be obtained, print "-1".

Time Complexity: O(n log(max(ai)))
Space Complexity: O(n)
*/



/* Approach - Greedy Right-to-Left / Floor Division (Time: O(N log(MAX_A)), Space: O(N))
 * Basically, we aggressively sweep the array backwards from right to left, ruthlessly halving the current element until it is strictly smaller than the one to its right, instantly catching impossible cases where it bottoms out at zero!
 * * Observation: 
 * - To mathematically guarantee the array is strictly increasing, every element MUST be strictly less than the one after it (`a[i] < a[i+1]`).
 * - Why sweep right-to-left? If we went left-to-right, shrinking `a[i+1]` later would violently destroy the `a[i] < a[i+1]` condition we just established! By working strictly backwards, we lock in the right side permanently and force the left side to gracefully adapt, mathematically guaranteeing we NEVER have to revisit a solved index!
 * - (The Absolute Constraint): Our operation is strictly integer division by 2, meaning the absolute lowest value a number can reach is 0. If `a[i+1]` is ever 0, it is physically impossible for `a[i]` to be strictly less than 0! The exact millisecond `a[i]` bottoms out at 0 and is still `>= a[i+1]`, the array is permanently unfixable!
 * - (Optimization Note: Because a number halves every single time, even a massive number like 10^9 will be completely reduced to 0 in under 30 operations! The `while` loop runs in a blistering O(log A) time, making the total complexity effectively a lightning-fast O(N)!)
 * * How it runs:
 * First, we safely extract the array size `n` and trigger a quick sweep to fully populate our `vector a`.
 * Then, we securely anchor our `oper` counter at 0, and trigger a high-speed reverse loop starting exactly at the second-to-last element (`n - 2`).
 * Next, for every single element, we aggressively evaluate it against its already-locked right neighbor. As long as `a[i] >= a[i+1]` and we haven't hit zero (`a[i] > 0`), we fiercely dive into the `while` loop, brutally dividing `a[i]` by 2 and racking up our operation count!
 * The exact millisecond the loop breaks, we deploy a strict safety check: if `a[i]` is STILL `>= a[i+1]`, it means we violently crashed into the 0-floor and failed. We instantly print `-1` and permanently terminate the case!
 * Finally, once the reverse sweep flawlessly reaches the very first element, our array is completely validated, and we confidently print our absolute minimum required operations!
 */


#include <bits/stdc++.h>
using namespace std;

void solve() {
    int  n;
    cin >> n;
    vector<long long> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int oper = 0;
    for(int i = n - 2; i >= 0; i--) {
    while(a[i] >= a[i+1] && a[i] > 0) {
        a[i] /= 2;
        oper++;
    }

    if(a[i] >= a[i+1]) {
        cout << "-1\n";
        return;
    }
}
    cout << oper <<"\n";
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
