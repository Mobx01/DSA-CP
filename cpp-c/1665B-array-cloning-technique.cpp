/*
Codeforces PS -1665 B. Array Cloning Technique
time limit per test: 1 second
memory limit per test: 256 megabytes

You are given an array a of n integers. Initially there is only one copy of the given array.
You can do operations of two types:
Choose any array and clone it. After that there is one more copy of the chosen array.
Swap two elements from any two copies (maybe in the same copy) on any positions.

You need to find the minimal number of operations needed to obtain a copy where all elements are equal.

Input
The input consists of multiple test cases. The first line contains a single integer t (1 ≤ t ≤ 10^4) — the number of test cases. Description of the test cases follows.
The first line of each test case contains a single integer n (1 ≤ n ≤ 10^5) — the length of the array a.
The second line of each test case contains n integers a1, a2, …, an (-10^9 ≤ ai ≤ 10^9) — the elements of the array a.
It is guaranteed that the sum of n over all test cases does not exceed 10^5.

Output
For each test case output a single integer — the minimal number of operations needed to create at least one copy where all elements are equal.

Time Complexity: O(N log N)
Space Complexity: O(N)
*/


/* Approach - Greedy Exponential Growth / Frequency Maximization (Time: O(N log N), Space: O(N))
 * Basically, we aggressively hunt down the most frequent element in the array to use as our absolute baseline, and violently double its population using a massive clone-and-swap strategy until it completely consumes the entire array!
 * * Observation: 
 * - To mathematically minimize our total operations, we MUST start with the element that already has the highest natural population! Every single instance of that element that already exists perfectly saves us a precious swap operation.
 * - (The Absolute Game-Breaker): We don't just awkwardly swap numbers one by one! The rules allow us to clone the ENTIRE current array for the incredibly cheap cost of exactly 1 operation! This means if we currently have 4 copies of our target, a single clone operation instantly generates 4 MORE copies in the reserve pool! 
 * - Because we can swap all newly cloned copies directly into the original array, our target's population mathematically grows exponentially in massive powers of 2! This structurally shreds the required loop iterations down to a blistering O(log N) runtime!
 * - (Optimization Note: You deployed a `std::map` which aggressively burns O(N log N) time to build the frequencies due to its underlying Red-Black Tree. You could instantly slash the time complexity down to a flawless, guaranteed O(N) by simply swapping to a `std::unordered_map`!)
 * * How it runs:
 * First, we safely extract our array size `n` and trigger a high-speed linear sweep, feeding every single element directly into our `freq` map to securely lock in their exact counts.
 * Then, we fiercely iterate through the frequency map to isolate the absolute highest count, completely anchoring our `maxfreq` baseline!
 * Next, we ignite our hyper-optimized `while` loop that continues to violently execute as long as our `maxfreq` is strictly less than the total array size `n`.
 * Inside the loop, we instantly burn exactly 1 operation (`oper++`) to ruthlessly clone the entire array structure!
 * We then fiercely check our bounds: if perfectly doubling our current targets strictly fits inside the array (`maxfreq * 2 < n`), we aggressively swap all of them in, adding exactly `maxfreq` to our operations and mathematically multiplying our `maxfreq` pool by 2!
 * If doubling would physically overflow the array bounds, we brilliantly calculate the exact remaining deficit (`n - maxfreq`), efficiently swap only the strictly necessary targets to perfectly fill the array, and forcefully snap `maxfreq = n` to permanently terminate the loop!
 * Finally, we confidently print the absolute minimum total operations required to flawlessly unify the array!
 */



#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i =0 ;i < n ;i++){
        cin >> a[i];
    }

    map<long long,int> freq;

    for(long long i : a) freq[i]++;
    int maxfreq=0;
    for(auto& fr : freq){
        maxfreq = max(maxfreq,fr.second);
    }
    int oper =0;
    while(maxfreq < n){
        oper++;//for cloning the array
        if(maxfreq*2 < n){//after cloning if we can fit all copies
            oper += maxfreq;
            maxfreq *= 2;    
        }else{
            //take only neccassary ones
            oper += (n - maxfreq);
            maxfreq = n;
        }
    }

    cout << oper << endl;
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
