/*Codeforces PS - 1831A. Twin Permutations

You are given a permutation a of length n.
Find any permutation b of length n such that a1 + b1 ≤ a2 + b2 ≤ a3 + b3 ≤ … ≤ an + bn.
It can be proven that a permutation b that satisfies the condition above always exists.

† A permutation of length n is an array consisting of n distinct integers from 1 to n in arbitrary order. For example, [2, 3, 1, 5, 4] is a permutation, but [1, 2, 2] is not a permutation (2 appears twice in the array), and [1, 3, 4] is also not a permutation (n=3 but there is 4 in the array).

Input
Each test contains multiple test cases. The first line of input contains a single integer t (1 ≤ t ≤ 2000) — the number of test cases. The description of test cases follows.
The first line of each test case contains a single integer n (1 ≤ n ≤ 100) — the length of permutations a and b.
The second line of each test case contains n distinct integers a1, a2, …, an (1 ≤ ai ≤ n) — the elements of permutation a. All elements of a are distinct.
Note that there is no bound on the sum of n over all test cases.

Output
For each test case, output any permutation b which satisfies the constraints mentioned in the statement. It can be proven that a permutation b that satisfies the condition above always exists.
*/

/* Approach - Mathematical Complement / Mapping (Time: O(N), Space: O(1) auxiliary)
 * Basically, we transform each element of the array into its exact mathematical opposite relative to the array's size, effectively flipping the magnitudes of the values.
 * * Observation: 
 * - Assuming the array elements are bounded by 1 and 'n' (like a standard permutation), the mathematical complement of any value 'x' in that range is exactly '(n + 1) - x'.
 * - This simple mathematical operation perfectly mirrors the values without needing to sort or swap indices: 1 becomes 'n', 2 becomes 'n-1', and 'n' becomes 1!
 * * How it runs:
 * First, we read the array size 'n' and load all the elements into our vector 'a'.
 * Then, we sweep through the array with a single loop, updating each element in-place by replacing it with the result of 'n + 1 - a[i]'.
 * Finally, we loop through one last time to print out the completely transformed array separated by spaces!
 */

#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0 ;i < n ;i++){
        a[i] = n+1 - a[i];
    }

    for(int i = 0; i < n; i++) {
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
