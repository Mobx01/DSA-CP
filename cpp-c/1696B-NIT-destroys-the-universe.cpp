/*
Codeforces PS - 1696B. NIT Destroys the Universe
time limit per test: 2 seconds
memory limit per test: 512 megabytes

For a collection of integers S, define mex(S) as the smallest non-negative integer that does not appear in S.

NIT, the cleaver, decides to destroy the universe. He is not so powerful as Thanos, so he can only destroy the universe by snapping his fingers several times.
The universe can be represented as a 1-indexed array a of length n. When NIT snaps his fingers, he does the following operation on the array:
He selects positive integers l and r such that 1 ≤ l ≤ r ≤ n. Let w = mex({al, al+1, …, ar}). Then, for all l ≤ i ≤ r, set ai to w.

We say the universe is destroyed if and only if for all 1 ≤ i ≤ n, ai = 0 holds.
Find the minimum number of times NIT needs to snap his fingers to destroy the universe. That is, find the minimum number of operations NIT needs to perform to make all elements in the array equal to 0.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1 ≤ t ≤ 10^4). Description of the test cases follows.
The first line of each test case contains one integer n (1 ≤ n ≤ 10^5).
The second line of each test case contains n integers a1, a2, …, an (0 ≤ ai ≤ 10^9).
It is guaranteed that the sum of n over all test cases does not exceed 2⋅10^5.

Output
For each test case, print one integer — the answer to the problem.

Time Complexity: O()
Space Complexity: O()
*/


/* Approach - Contiguous Block Counting / Mathematical Upper Bound (Time: O(N), Space: O(N))
 * Basically, we aggressively sweep through the array to count isolated islands of non-zero elements, completely bypassing complex simulation because the mathematical maximum number of operations is strictly hardcapped at 2!
 * * Observation: 
 * - The absolute game-breaker of this problem is the realization that you NEVER realistically need more than 2 operations to wipe the entire board!
 * - If the array is already perfectly zeroed out, it mathematically takes 0 operations. If all the non-zero numbers are neatly clustered together into a single, unbroken contiguous island, you can aggressively annihilate them all in exactly 1 targeted operation!
 * - But what if you have multiple fragmented islands of non-zeros violently separated by 0s? Instead of painstakingly destroying them one by one, you can brutally select the ENTIRE array for your first operation, and then effortlessly wipe the resulting uniform block in exactly 1 more move! Therefore, the optimal answer is flawlessly guaranteed to simply be `min(2, blocks)`!
 * - (Optimization Note: The code aggressively allocates a massive `vector<long long> a(n)` to store the entire array in memory! Since you only ever check if the current element is 0 or not to toggle your `prev0` state, you could elegantly process the stream completely on the fly as it is typed, instantly slashing your auxiliary space down to a flawless, guaranteed O(1)!)
 * * How it runs:
 * First, we safely extract our array size `n` and trigger a quick sweep to fully populate our `vector a`.
 * Then, we securely anchor our `blocks` counter perfectly at 0, and set up a `prev0` flag (which acts as an active tracker to tell us if we are currently physically standing inside a non-zero island).
 * Next, we trigger a high-speed linear sweep. If we hit a `0`, we fiercely check if `prev0 == 1` (meaning we just stepped OFF an active non-zero island). If so, we aggressively lock in that completed block by incrementing `blocks`, and reset our flag to 0. If we hit any non-zero number, we simply flip `prev0` to 1 to mark the active sequence!
 * After the sweep crashes into the end of the array, we do one last mathematical check to see if the sequence ended strictly on an uncounted non-zero block. Finally, we confidently print `min(2, blocks)`, delivering the absolute optimal answer without simulating a single physical operation!
 */


#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;

    vector<long long> a(n);
    for(int i =0;i<n;i++) cin >> a[i];
    int blocks = 0;
    int  prev0 = 0;
    for(int i=0;i<n;i++){
        if(a[i] == 0 ){
            if(prev0 == 1){
                blocks++;
            }
            prev0 = 0;
        }else prev0 = 1;
    }
    if(prev0 == 1)blocks++;
    cout<< min(2,blocks) <<"\n";
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
