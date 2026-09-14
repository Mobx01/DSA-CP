/*
Codeforces - 1312B. Bogosort
Time limit per test: 2 seconds
Memory limit per test: 256 megabytes

You are given an array a_1, a_2, ..., a_n. Array is good if for each pair of indexes i < j the condition j - a_j != i - a_i holds. Can you shuffle this array so that it becomes good? To shuffle an array means to reorder its elements arbitrarily (leaving the initial order is also an option).

For example, if a = [1, 1, 3, 5], then shuffled arrays [1, 3, 5, 1], [3, 5, 1, 1] and [5, 3, 1, 1] are good, but shuffled arrays [3, 1, 5, 1], [1, 1, 3, 5] and [1, 1, 5, 3] aren't.

It's guaranteed that it's always possible to shuffle an array to meet this condition.

Input
The first line contains one integer t (1 <= t <= 100) — the number of test cases.
The first line of each test case contains one integer n (1 <= n <= 100) — the length of array a.
The second line of each test case contains n integers a_1, a_2, ..., a_n (1 <= a_i <= 100).

Output
For each test case print the shuffled version of the array a which is good.
*/



/* Approach - Descending Order Sorting / Reverse-Magnitude Arrangement (Time: O(N log N), Space: O(1) auxiliary)
 * Basically, we completely annihilate manual array reversal loops by aggressively leveraging reverse iterators, sorting the sequence in descending order in pristine logarithmic time!
 * * Observation: 
 * - The absolute core of this architecture is the Reverse Iterator Sorting Invariant! Using `a.rbegin()` and `a.rend()` with `std::sort` is an idiomatically pristine C++ shortcut. It directs the comparison and placement logic to arrange elements from largest to smallest directly in-place, completely eliminating the need for a secondary reversal pass.
 * - (Logarithmic Sorting Bottleneck): For general unordered input data, comparison-based sorting (`std::sort`) inherently operates in $O(N \log N)$ time. Unless the input guarantees specific structural constraints (like counting sort domains), this is mathematically optimal.
 * - (Fast I/O and Stream Flushing): Retaining `ios_base::sync_with_stdio(false); cin.tie(NULL);` alongside explicit newline flushing (`"\n"`) ensures that large I/O batches breeze through without stuttering on competitive programming judges.
 * * How it runs:
 * First, we safely intercept the array size `n` and read all elements into our vector.
 * We invoke the sorting engine with reverse iterators (`a.rbegin()`, `a.rend()`), establishing a strict descending numerical sequence.
 * We ignite a high-speed linear traversal, printing each element separated by a space.
 * Finally, we flush a trailing newline to the output stream with absolute mathematical precision at raw silicon speed!
 */



#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n ;
    cin >> n;

    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    
    sort(a.rbegin(),a.rend());
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << "\n";
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
