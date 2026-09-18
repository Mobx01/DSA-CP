/*
Codeforces - 1914C. Quests
Time limit per test: 2.5 seconds
Memory limit per test: 256 megabytes

Monocarp is playing a computer game. In order to level up his character, he can complete quests. There are n quests in the game, numbered from 1 to n.

Monocarp can complete quests according to the following rules:
the 1-st quest is always available for completion;
the i-th quest is available for completion if all quests j < i have been completed at least once.

Note that Monocarp can complete the same quest multiple times.

For each completion, the character gets some amount of experience points:
for the first completion of the i-th quest, he gets a_i experience points;
for each subsequent completion of the i-th quest, he gets b_i experience points.

Monocarp is a very busy person, so he has free time to complete no more than k quests. Your task is to calculate the maximum possible total experience Monocarp can get if he can complete no more than k quests.

Input
The first line contains a single integer t (1 <= t <= 10^4) — the number of test cases.
The first line of each test case contains two integers n and k (1 <= n <= 2 * 10^5; 1 <= k <= 2 * 10^5) — the number of quests and the maximum number of quests Monocarp can complete, respectively.
The second line contains n integers a_1, a_2, ..., a_n (1 <= a_i <= 10^3).
The third line contains n integers b_1, b_2, ..., b_n (1 <= b_i <= 10^3).
Additional constraint on the input: the sum of n over all test cases does not exceed 2 * 10^5.

Output
For each test case, print a single integer — the maximum possible total experience Monocarp can get if he can complete no more than k quests.
*/



/* Approach - Greedy Prefix Sum with Running Maximum Multiplier Tracking (Time: O(min(N, K)), Space: O(N))
 * Basically, we completely annihilate brute-force combinatorial search by aggressively combining a running prefix sum of array `a` with a running maximum tracker of array `b`, evaluating the optimal score in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Optimal Remaining-Step Exploitation Invariant! If you choose to traverse up to index `i` (taking `i + 1` elements from array `a`), you spend `i + 1` steps out of your total `k` available moves. For the remaining `k - (i + 1)` steps, you are free to repeatedly pick the element that yields the highest score from array `b` among all elements visited so far. By tracking `maxi = max(maxi, b[i])` on the fly, you instantly know the best possible multiplier to spam for the remainder of your budget!
 * - (The `min(n, k)` Boundary Optimization): Your loop condition `for(int i = 0; i < min(n, k); i++)` is a stroke of defensive programming genius! It guarantees you never exceed the available array bounds while also preventing redundant iterations when your step budget `k` is smaller than the array size `n`.
 * - (Single-Pass Efficiency): Computing the candidate answer `sum + (k - (i + 1)) * maxi` at each step allows you to find the global maximum score across all possible prefix lengths in a single pass with zero auxiliary overhead.
 * * How it runs:
 * First, we safely intercept inputs `n` and `k`, followed by reading arrays `a` and `b`.
 * We initialize our tracking registers (`sum`, `maxi`, and `ans`) to zero.
 * We ignite a high-speed linear sweep up to `min(n, k)`, accumulating the running sum of `a`, updating the peak `b` value, and calculating the maximum possible score configuration at each step.
 * Finally, we flush the optimal maximum score to the output stream with absolute mathematical precision at raw silicon speed!
 */



#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n,k;
    cin >> n >> k;
    
    vector<int> a(n),b(n);

    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }

    int maxi =0;
    long long sum = 0;
    long long ans = 0;

    for(int i=0;i<min(n,k);i++){
        sum += a[i];
        maxi = max(maxi,b[i]);
        ans = max(ans ,sum+ (k-(i+1))*maxi);
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
