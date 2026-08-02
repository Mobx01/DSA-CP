/*
Codeforces PS - 1850D. Balanced Round
time limit per test: 2 seconds
memory limit per test: 256 megabytes

You are the author of a Codeforces round and have prepared n problems you are going to set, problem i having difficulty ai. You will do the following process:
remove some (possibly zero) problems from the list;
rearrange the remaining problems in any order you wish.

A round is considered balanced if and only if the absolute difference between the difficulty of any two consecutive problems is at most k (less or equal than k).
What is the minimum number of problems you have to remove so that an arrangement of problems is balanced?

Input
The first line contains a single integer t (1 ≤ t ≤ 1000) — the number of test cases.
The first line of each test case contains two positive integers n (1 ≤ n ≤ 2⋅10^5) and k (1 ≤ k ≤ 10^9) — the number of problems, and the maximum allowed absolute difference between consecutive problems.
The second line of each test case contains n space-separated integers ai (1 ≤ ai ≤ 10^9) — the difficulty of each problem.
Note that the sum of n over all test cases doesn't exceed 2⋅10^5.

Output
For each test case, output a single integer — the minimum number of problems you have to remove so that an arrangement of problems is balanced.
*/


/* Approach - Sorting & Longest Valid Subsequence (Time: O(N log N), Space: O(N))
 * Basically, we completely sort the array to naturally group the closest values together, sweep through to find the absolute longest continuous chain of elements that perfectly satisfy the 'k' gap constraint, and subtract that max chain from the total size to find the exact minimum elements to destroy!
 * * Observation: 
 * - Because the problem asks for the absolute minimum number of elements to remove, we are conversely trying to strictly MAXIMIZE the number of elements we get to keep!
 * - The constraint dictates that *every* pair of adjacent elements in the final sorted sequence must have a difference of at most `k`. This mathematically means our kept elements MUST form one single, unbroken contiguous block inside the fully sorted array! 
 * - Any gap strictly greater than `k` acts as a permanent, impassable wall that violently splits the array into completely isolated blocks. Therefore, the absolute most optimal strategy is to simply identify the longest valid block and ruthlessly delete every single element outside of it!
 * - (Optimization Note: The code was pasted twice in the prompt, but the logic inside is perfectly sound! We only need one copy of the function to execute the logic flawlessly.)
 * * How it runs:
 * First, we safely extract our array size `n` and our maximum allowed gap `k`, populate our `vector a`, and aggressively trigger `sort()` to arrange every single value in strictly ascending order.
 * Then, we securely anchor our absolute longest chain tracker `max_con` and our current running block length `j` perfectly at 1 (since an array of 1 element is always mathematically valid by itself).
 * Next, we trigger a high-speed linear sweep starting directly from index 1. At every single step, we fiercely check the gap between the current element `a[i]` and the previous element `a[i-1]`.
 * If the gap is safely `<= k`, we aggressively increment `j` to expand our current unbroken chain. The exact millisecond the gap exceeds `k`, the chain is permanently broken, and we instantly reset `j = 1` to start tracking a brand new block.
 * Finally, we continuously lock the absolute maximum chain length we've seen into `max_con` using `max()`. Once the sweep finishes, we mathematically subtract our massive surviving block from the total array size `(n - max_con)` and confidently print the absolute minimum number of deletions required!
 */


#include <bits/stdc++.h>
using namespace std;


void solve() {
    long long n,k;
    cin >> n >> k;
    vector<long long> a(n);
    for(int i =0;i<n;i++) cin >> a[i];
    long long max_con = 1,j = 1 ;
    sort(a.begin(),a.end());
    for(int i =1;i<n;i++){
        if(a[i] - a[i-1] <= k){
            j++; ///rest the counter
        }else{
            j = 1; // track continous blocks
        }
        max_con = max(max_con,j);
    }

    cout << (n - max_con) <<"\n" ;//rest of the blocks will be removed

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
