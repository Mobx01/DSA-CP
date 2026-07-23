/*Codeforces PS 1761 - A. Two Permutations

You are given three integers n, a, and b. Determine if there exist two permutations p and q of length n, for which the following conditions hold:
The length of the longest common prefix of p and q is a.
The length of the longest common suffix of p and q is b.

A permutation of length n is an array containing each integer from 1 to n exactly once. For example, [2, 3, 1, 5, 4] is a permutation, but [1, 2, 2] is not a permutation (2 appears twice in the array), and [1, 3, 4] is also not a permutation (n=3 but there is 4 in the array).

Input
Each test contains multiple test cases. The first line contains a single integer t (1 ≤ t ≤ 10^4) — the number of test cases. The description of test cases follows.
The only line of each test case contains three integers n, a, and b (1 ≤ a, b ≤ n ≤ 100).

Output
For each test case, if such a pair of permutations exists, output "Yes"; otherwise, output "No". You can output each letter in any case (upper or lower).
*/

/* Approach - Math / Logical Deduction (Time: O(1), Space: O(1))
 * Basically, we mathematically determine if two permutations of length 'n' can legally share a prefix of length 'a' and a suffix of length 'b' by checking if they are either completely identical or have enough room for a valid mismatch!
 * * Observation: 
 * - The problem inherently asks if we can construct two valid permutations of length 'n' that match exactly on their first 'a' elements and their last 'b' elements.
 * - If the two permutations are absolutely identical, their common prefix and suffix will naturally both be exactly 'n'. This perfectly satisfies our `a == b && a == n` edge case!
 * - If they are NOT identical, they must differ in at least two positions (since you mathematically cannot have two valid permutations that differ by only a single element—swapping requires at least two elements!). 
 * - This means the matching prefix and matching suffix cannot overlap, AND there must be a gap of at least 2 unconstrained elements between them in the middle to allow for this mandatory mismatch! This strictly reduces to the formula `a + b + 2 <= n`.
 * * How it runs:
 * First, we read the total length 'n', the prefix length 'a', and the suffix length 'b'.
 * Then, we evaluate our identical twin base case: if 'a' and 'b' are both exactly equal to 'n', we instantly print "YES" because the permutations can just be exact copies of each other.
 * Next, if they aren't exact copies, we verify if there is enough physical space for a valid mismatch in the middle by checking `a + b + 2 <= n`. If there is, we confidently print "YES".
 * Finally, if neither of these strict mathematical conditions is met, it is permanently impossible to construct the permutations, so we output "NO"!
 */


#include <iostream>
using namespace std;

void solve() {
    int n,a,b;
    cin >> n >> a >> b;

    
    if( a == b && a== n) cout << "YES\n";
    else if(a+b+2 <= n) cout << "YES\n";
    else cout << "NO\n";
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
