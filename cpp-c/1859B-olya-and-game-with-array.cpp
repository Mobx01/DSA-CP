/*
Codeforces - 1859B. Olya and Game with Arrays
Time limit per test: 1 second
Memory limit per test: 256 megabytes

Artem suggested a game to the girl Olya. There is a list of n arrays, where the i-th array contains m_i >= 2 positive integers a_{i,1}, a_{i,2}, ..., a_{i,m_i}.

Olya can move at most one (possibly 0) integer from each array to another array. Note that integers can be moved from one array only once, but integers can be added to one array multiple times, and all the movements are done at the same time.

The beauty of the list of arrays is defined as the sum \sum_{i=1}^{n} \min_{j=1}^{m_i} a_{i,j}. In other words, for each array, we find the minimum value in it and then sum up these values.

The goal of the game is to maximize the beauty of the list of arrays. Help Olya win this challenging game!

Input
Each test consists of multiple test cases. The first line contains a single integer t (1 <= t <= 25000) — the number of test cases. The description of test cases follows.
The first line of each test case contains a single integer n (1 <= n <= 25000) — the number of arrays in the list.
This is followed by descriptions of the arrays. Each array description consists of two lines.
The first line contains a single integer m_i (2 <= m_i <= 50000) — the number of elements in the i-th array.
The next line contains m_i integers a_{i,1}, a_{i,2}, ..., a_{i,m_i} (1 <= a_{i,j} <= 10^9) — the elements of the i-th array.
It is guaranteed that the sum of m_i over all test cases does not exceed 50000.

Output
For each test case, output a single line containing a single integer — the maximum beauty of the list of arrays that Olya can achieve.
*/

/* Approach - Greedy State Extraction / Mathematical Swap (Time: O(ΣM log M) worst-case, Space: O(ΣM))
 * Basically, we completely annihilate the infinite permutation tree of moving elements between arrays by violently collapsing the problem into a pure mathematical trade: sacrifice the absolute smallest 2nd-minimum in the entire universe to securely lock in the absolute smallest 1st-minimum across all timelines!
 * * Observation: 
 * - The absolute core of this puzzle is the cross-array swapping mechanic! Because you can shift elements anywhere, every single array will eventually contribute its 2nd smallest element to the final beauty score, EXCEPT for one! You strategically sacrifice the array that has the mathematically weakest (smallest) 2nd-minimum, and replace its contribution with the absolute lowest global minimum available!
 * - (The Fatal Mismatch Trap / The 32-Bit Ceiling): `long long min2nd = INT_MAX`. You did it again! You structurally requested a massive 64-bit `long long` register, but violently artificially capped it with a strict 32-bit `INT_MAX` (~2.1e9)! If a competitive programming test case injects elements sized at 10^12, your radar will mathematically fail to detect them, causing a catastrophic Wrong Answer! Always deploy `LLONG_MAX` or `1e18` to perfectly seal the 64-bit dimension!
 * - (Optimization Alert 1 / The Sorting Annihilation): You are aggressively burning CPU cycles by calling `sort(ai.begin(), ai.end());` on EVERY single subarray! If an array contains 10^5 elements, you violently waste O(M log M) operations just to look at the first two numbers! You can completely destroy this bottleneck by running two O(1) tracker variables (`local_min1`, `local_min2`) in a single blistering O(M) linear sweep, instantly shredding the time complexity down to pure O(ΣM)!
 * - (Optimization Alert 2 / The Memory Nuke & 1-Pass Collapse): You aggressively allocate a massive 2D vector `a` to store the entire dataset, and then run a second loop to calculate the sum. You NEVER need to look backward! You can process the arrays on the fly! Just keep a running `total_sum_of_min2s`. As each array comes in, find its `min1` and `min2`, instantly add `min2` to the `total_sum`, and aggressively update your `global_min1` and `global_min2`. At the absolute end, the answer is just `total_sum - global_min2 + global_min1`! This completely vaporizes the 2D vector, dropping auxiliary space complexity to absolute peak O(1)!
 * * How it runs (Current State):
 * First, we safely intercept `n` and forcefully allocate a massive 2D memory grid, violently ingesting the sizes and raw elements of every single subarray.
 * We ignite the high-speed sorting engine! For every subarray, we aggressively force a strict ascending order to instantly expose the 1st and 2nd minimums.
 * We sweep across the newly sorted grid! We deploy our dual-radar to violently track the absolute lowest global 1st-minimum (`min1st`) and completely lock onto the specific array index that holds the weakest 2nd-minimum (`min_ind`).
 * We trigger a second linear sweep! We aggressively accumulate the 2nd-minimum of every single array into our `beauty` register.
 * The exact millisecond our sweep collides with the `min_ind` target, we ruthlessly bypass its 2nd-minimum!
 * Finally, we inject the absolute global 1st-minimum into the empty slot and confidently output the maxed-out beauty score!
 */



#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    vector<int> siz(n);
    vector<vector<long long>> a; 
    for(int i =0;i<n;i++){
        cin >> siz[i];
        vector<long long> ai(siz[i]);
        for(int j=0;j<siz[i];j++){
            cin >> ai[j];
        }   
        a.push_back(ai);
    }
    long long  min2nd = INT_MAX,min_ind = -1,i=0;
    long long min1st=INT_MAX;
    for(vector<long long> &ai : a){
        sort(ai.begin(),ai.end());
        if(ai[1] < min2nd){
            min2nd = ai[1];
            min_ind = i;
        }
        min1st = min(min1st,ai[0]);
        i++;
    }
    i=0;
    long long beauty = min1st;
    for(vector<long long> &ai : a){
        if(i != min_ind){
        beauty += ai[1];
        }
        i++;
    }
    cout << beauty << endl;
    

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
