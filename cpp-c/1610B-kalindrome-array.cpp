/*
Codeforces - 1610B. Kalindrome Array
Time limit per test: 1 second
Memory limit per test: 256 megabytes

An array [b_1, b_2, ..., b_m] is a palindrome, if b_i = b_{m+1-i} for each i from 1 to m. Empty array is also a palindrome.
An array is called kalindrome, if the following condition holds:
- It's possible to select some integer x and delete some of the elements of the array equal to x, so that the remaining array (after gluing together the remaining parts) is a palindrome.
Note that you don't have to delete all elements equal to x, and you don't have to delete at least one element equal to x.

For example:
- [1, 2, 1] is kalindrome because you can simply not delete a single element.
- [3, 1, 2, 3, 1] is kalindrome because you can choose x = 3 and delete both elements equal to 3, obtaining array [1, 2, 1], which is a palindrome.
- [1, 2, 3] is not kalindrome.

You are given an array [a_1, a_2, ..., a_n]. Determine if a is kalindrome or not.

Input
The first line contains a single integer t (1 <= t <= 10^4) — the number of test cases. The description of the test cases follows.
The first line of each test case contains a single integer n (1 <= n <= 2 * 10^5) — the length of the array.
The second line of each test case contains n integers a_1, a_2, ..., a_n (1 <= a_i <= n) — elements of the array.
It's guaranteed that the sum of n over all test cases won't exceed 2 * 10^5.

Output
For each test case, print YES if a is kalindrome and NO otherwise. You can print each letter in any case.
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

bool check(vll &a,ll x){
    int n = a.size();
    int i=0,j=n-1;

    while(i<j){
        if(a[i] == x)i++;//skip the x (simulating its deletion)
        else if(a[j] == x)j--; // "(Same)
        else if(a[i] != a[j])return false;
        else {
            i++,j--;
        }
    }
    return true;
}

void solve() {
    ll n;
    cin >> n;
    vll a(n);

    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    bool test = true;
    for(int i=0;i<(int)n/2;i++){
        if(a[i] != a[n-i-1]){
            test =  (check(a,a[i]) || check(a,a[n-i-1])); 
            break;
        }
    }

    if(test){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
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
