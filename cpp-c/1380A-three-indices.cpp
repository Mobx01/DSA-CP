/*
Codeforces - 1380A. Three Indices
Time limit per test: 2 seconds
Memory limit per test: 256 megabytes

You are given a permutation p_1, p_2, ..., p_n. Recall that sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.

Find three indices i, j and k such that:
1 <= i < j < k <= n;
p_i < p_j and p_j > p_k.

Or say that there are no such indices.

Input
The first line contains a single integer T (1 <= T <= 200) — the number of test cases.
Next 2T lines contain test cases — two lines per test case. The first line of each test case contains the single integer n (3 <= n <= 1000) — the length of the permutation p.
The second line contains n integers p_1, p_2, ..., p_n (1 <= p_i <= n; p_i != p_j if i != j) — the permutation p.

Output
For each test case:
if there are such indices i, j and k, print YES (case insensitive) and the indices themselves;
if there are no such indices, print NO (case insensitive).
If there are multiple valid triples of indices, print any of them.
*/


/* Approach - Brute Force Peak Search / Bidirectional Radar (Time: O(N^2), Space: O(N))
 * Basically, we violently force a quadratic simulation, aggressively radiating outward from every single element to blindly hunt for any mathematically smaller value on both sides!
 * * Observation: 
 * - The absolute core of this problem is finding a mathematical "peak"—a structural high ground (`v[i]`) that completely dominates at least one element in its past (`v[left]`) and one element in its future (`v[right]`).
 * - (The Fatal O(N^2) TLE Trap): Your inner loops aggressively burn CPU cycles scanning the entire left and right partitions for EVERY single element! On massive datasets shaped like a 'V' (strictly decreasing then strictly increasing), your code violently spirals into a Time Limit Exceeded (TLE) catastrophe because it checks every single combination and fails!
 * - (Optimization Alert 1 / The Left-Side Cache): You NEVER need to loop backward to find a smaller element! Just mathematically track the absolute `global_min_index` as you sweep forward! If your current `v[i]` is strictly greater than `v[global_min_index]`, you have instantly secured your left anchor in a blistering O(1) CPU cycle!
 * - (The Absolute Game-Breaker / The Adjacent Drop Nuke): What about the right side? If `v[i] > v[global_min_index]`, you ONLY need to check the exact next element: `if (v[i] > v[i+1])`! Why? Because if `v[i] <= v[i+1]`, then `v[i+1]` is mathematically an even BIGGER and better peak candidate for that exact same minimum! You simply ignore `i` and let `i+1` take the shot! This completely annihilates the nested loops, crushing the entire algorithm down to a single flawless O(N) linear sweep!
 * * How it runs (Current State):
 * First, we safely intercept the array size `n` and ingest the dataset into memory using our fast I/O engine.
 * We ignite a high-speed outer sweep, treating every single index `i` (from 1 to n-2) as a potential peak candidate.
 * We instantly trigger two inner radars: one aggressively scanning the past (`0` to `i-1`), and one violently scanning the future (`i+1` to `n-1`), locking onto the first strictly smaller element they mathematically detect.
 * The exact millisecond both a left and right anchor are securely locked (`!= -1`), we aggressively short-circuit the entire simulation! We confidently print "YES" and flawlessly map the 0-based variables to 1-based indices, instantly terminating the timeline!
 * If the outer sweep completely collapses without finding a valid peak, we mathematically concede and print "NO", flawlessly resetting for the next test case!
 */


#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n;i++){
        cin >> v[i];
    }

    for(int i =1;i<n-1;i++){//middle element
        int left = -1,right = -1;

        for(int j =0;j<i;j++){
            if(v[i] > v[j]){
                left = j;
                break; 
            }
        }
        for(int j =i+1;j<n;j++){
            if(v[i] > v[j]){
                right = j;
                break; 
            }
        }
        if(right != -1 && left != -1){
            cout << "YES" << endl;
            cout << left+1 <<" "<< i +1<< " " <<right+1 << endl;
            return;
        }
    }
    cout << "NO" << endl;
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
