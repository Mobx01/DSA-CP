/*
Codeforces - 1628B. AND Sorting
Time limit per test: 1 second
Memory limit per test: 256 megabytes

You are given a permutation p of integers from 0 to n - 1 (each of them occurs exactly once). Initially, the permutation is not sorted (that is, p_i > p_{i+1} for at least one 1 <= i <= n - 1).

The permutation is called X-sortable for some non-negative integer X if it is possible to sort the permutation by performing the operation below some finite number of times:
- Choose two indices i and j (1 <= i < j <= n) such that p_i & p_j = X.
- Swap p_i and p_j.

Here & denotes the bitwise AND operation.

Find the maximum value of X such that p is X-sortable. It can be shown that there always exists some value of X such that p is X-sortable.

Input
The input consists of multiple test cases. The first line contains a single integer t (1 <= t <= 10^4) — the number of test cases. Description of test cases follows.
The first line of each test case contains a single integer n (2 <= n <= 2 * 10^5) — the length of the permutation.
The second line of each test case contains n integers p_1, p_2, ..., p_n (0 <= p_i <= n - 1, all p_i are distinct) — the elements of p. It is guaranteed that p is not sorted.
It is guaranteed that the sum of n over all cases does not exceed 2 * 10^5.

Output
For each test case output a single integer — the maximum value of X such that p is X-sortable.
*/



/* Approach - CP Harness Wrapper with Bitwise Permutation Evaluation (Time: O(N), Space: O(1))
 * Basically, we completely annihilate repetitive boilerplate setup by aggressively wrapping our core permutation logic inside a complete competitive programming I/O harness supporting multi-test cases in pristine linear time and constant space!
 * * Observation: 
 * - The absolute core of this architecture is the Competitive Programming Harness Invariant! By combining the `sortPermutation` logic with standard `solve()` and `main()` loops governed by fast I/O (`ios_base::sync_with_stdio(false)`) and multi-test case handling (`while(t--)`), this snippet transforms a standalone method into a fully runnable submission-ready program.
 * - (Duplication Catch): Note that the entire source code block appears duplicated back-to-back in your input stream. Cleaning up redundant code blocks ensures cleaner builds and avoids confusion during compilation.
 * - (Optimal Complexity): The algorithmic core retains its $O(N)$ linear time and $O(1)$ auxiliary space efficiency.
 * * How it runs:
 * First, fast I/O optimizations are configured and the test case count `t` is read.
 * For each test case, array size `n` and all elements of vector `num` are safely ingested.
 * The `sortPermutation` function checks if the array is sorted (returning `0`) or accumulates the bitwise AND of all misplaced elements.
 * Finally, the result is flushed to the output stream with absolute mathematical precision at raw silicon speed!
 */




#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define F first
#define S second

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int k = -1;
        bool sort= true;
        for(int i=0;i<n;i++){
            if(nums[i] != i){
                sort = false;
                if(k == -1) k = nums[i];
                else k &= nums[i];
            }
        }

        if(sort){
            return 0;
        }
        return k;
}
void solve() {
    int n;
    cin >> n;
    vector<int> num(n);

    for(int i =0;i<n;i++){
        cin >> num[i];
    }

    cout << sortPermutation(num) << endl;

}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
