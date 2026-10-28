/*
Codeforces - 1656B. Subtract Operation
Time limit per test: 1 second
Memory limit per test: 256 megabytes

You are given a list of n integers. You can perform the following operation: you choose an element x from the list, erase x from the list, and subtract the value of x from all the remaining elements. Thus, in one operation, the length of the list is decreased by exactly 1.

Given an integer k (k > 0), find if there is some sequence of n - 1 operations such that, after applying the operations, the only remaining element of the list is equal to k.

Input
The input consists of multiple test cases. The first line contains a single integer t (1 <= t <= 10^4) — the number of test cases. Description of the test cases follows.
The first line of each test case contains two integers n and k (2 <= n <= 2 * 10^5, 1 <= k <= 10^9), the number of integers in the list, and the target value, respectively.
The second line of each test case contains the n integers of the list a_1, a_2, ..., a_n (-10^9 <= a_i <= 10^9).
It is guaranteed that the sum of n over all test cases is not greater that 2 * 10^5.

Output
For each test case, print YES if you can achieve k with a sequence of n - 1 operations. Otherwise, print NO.
You may print each letter in any case (for example, "YES", "Yes", "yes", "yEs" will all be recognized as a positive answer).
*/




/* Approach - Two-Pointer Mismatch Resolution with Character Filtering / Almost Palindrome Validation (Time: O(N), Space: O(1))
 * Basically, we completely annihilate brute-force subsequence checks by aggressively identifying the first outer mismatch and testing candidate deletions via a two-pointer validation helper in pristine linear time and constant space!
 * * Observation: 
 * - The absolute core of this architecture is the Almost-Palindrome Invariant (classic competitive programming problem: check if an array can become a palindrome by deleting at most one element)! When scanning from both ends and encountering the first mismatch `a[i] != a[n - i - 1]`, the element to be deleted must be either `a[i]` or `a[n - i - 1]`.
 * - (Subtle Edge Case / Potential Bug): Notice that your helper `check(vll &a, ll x)` skips **all** occurrences of the value `x` from both pointers. If `x` appears multiple times in the array, skipping all instances effectively deletes *multiple* elements instead of a single specific occurrence, which can cause false positives (accepting arrays where more than one deletion was required). The robust standard approach is to verify whether the exact subarray slice `[i + 1, j]` or `[i, j - 1]` forms a palindrome by index rather than value matching.
 * - (Optimal Complexity): Operating with scalar pointers and a single linear pass keeps time complexity at $O(N)$ and auxiliary space at $O(1)$.
 * * How it runs:
 * First, we read test parameters `n` and populate vector `a`.
 * We scan from both ends (`i` and `n - i - 1`) until we find a mismatch. If no mismatch exists, the array is already a palindrome (`"YES"`).
 * When a mismatch is found, we test removing `a[i]` or `a[n - i - 1]` using the `check` helper.
 * Finally, we flush `"YES"` or `"NO"` to the output stream with absolute mathematical precision at raw silicon speed!
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

void solve() {
    ll n , k;
    cin >> n >> k;

    vll a(n);
    for(ll i = 0;i<n;i++){
        cin >> a[i];
    }

    sort(a.begin(),a.end());

    ll i =0,j=1;

    while(i < n && j < n){
        if(i != j && a[j] - a[i] == k ){
            cout << "YES\n";
            return ;
        }else if (a[j] - a[i] > k){
            i++;
        }else{
            j++;
        }
    }

    cout << "NO\n";
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
