/*
Codeforces - 1904B. Collecting Game
Time limit per test: 1 second
Memory limit per test: 256 megabytes

You are given an array a of n positive integers and a score. If your score is greater than or equal to a_i, then you can increase your score by a_i and remove a_i from the array.

For each index i, output the maximum number of additional array elements that you can remove if you remove a_i and then set your score to a_i. Note that the removal of a_i should not be counted in the answer.

Input
Each test contains multiple test cases. The first line contains an integer t (1 <= t <= 5000) — the number of test cases. The description of the test cases follows.
The first line of each test case contains a single integer n (1 <= n <= 10^5) — the length of the array.
The second line of each test case contains n integers a_1, a_2, ..., a_n (1 <= a_i <= 10^9) — the elements of the array.
It is guaranteed that the sum of n over all test cases does not exceed 10^5.

Output
For each test case, output n integers, the i-th of which denotes the maximum number of additional array elements that you can remove if you remove a_i from the array and then set your score to a_i.
*/



/* Approach - Two-Pointer Linear Scan with Monotonic Prefix Sum Pooling (Time: O(N log N), Space: O(N))
 * Basically, we completely annihilate redundant nested loops by aggressively leveraging the monotonic property of cumulative prefix sums with a two-pointer sliding window, computing absorption counts for all elements in pristine linear time after sorting!
 * * Observation: 
 * - The absolute core of this architecture is the Monotonic Reachability Invariant! When elements can pool their values together (where the sum of elements from index `0` to `j` can absorb `a[j+1]`), the maximum reachable index `j` is non-decreasing as we move to larger elements `i`. This allows pointer `j` to only ever move forward without ever resetting, turning what could be an $O(N^2)$ brute-force check into a lightning-fast $O(N)$ linear pass.
 * - (Index Preservation Precision): Storing original indices (`a[i].second = i`) before sorting ensures that once we compute the maximum reachable index for each element, we can correctly map the answers back to their original input positions via `ans[a[i].second] = j`.
 * - (Optimal Complexity Trade-off): While sorting takes $O(N \log N)$, the subsequent two-pointer sweep runs in strict $O(N)$ time with minimal auxiliary vector allocations, making this solution exceptionally optimal for competitive programming constraints.
 * * How it runs:
 * First, we safely intercept array size `n` and read elements while tracking their original 0-based indices.
 * We invoke the sorting engine to arrange the elements in ascending order and compute the cumulative prefix sum array `pref`.
 * We initialize our two-pointer tracking (`j = 0`) and sweep index `i` from `0` to `n - 1`, greedily advancing `j` as long as the prefix sum up to `j` can absorb the next element `a[j + 1]`.
 * We record the reachable count `j` back into the original index position.
 * Finally, we flush the final result array to the output stream with absolute mathematical precision at raw silicon speed!
 */



#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<pair<long long, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    // Sort based on element values
    sort(a.begin(), a.end());

    // Compute prefix sums
    vector<long long> pref(n);
    pref[0] = a[0].first;
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + a[i].first;
    }

    vector<int> ans(n);
    int j = 0;
    for (int i = 0; i < n; i++) {
        j = max(j, i);
        // Greedily extend as far as the prefix sum allows
        while (j + 1 < n && pref[j] >= a[j + 1].first) {
            j++;
        }
        ans[a[i].second] = j;
    }

    // Output answers according to original indices
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();  
    }

    return 0;
}
