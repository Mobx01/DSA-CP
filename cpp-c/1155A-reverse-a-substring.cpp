/*
Codeforces - 1155A. Reverse a Substring
Time limit per test: 2 seconds
Memory limit per test: 256 megabytes

You are given a string s consisting of n lowercase Latin letters.

Let's define a substring as a contiguous subsegment of a string. For example, "acab" is a substring of "abacaba" (it starts in position 3 and ends in position 6), but "aa" or "d" aren't substrings of this string. So the substring of the string s from position l to position r is s[l;r] = s_l s_{l+1} ... s_r.

You have to choose exactly one of the substrings of the given string and reverse it (i.e. make s[l;r] = s_r s_{r-1} ... s_l) to obtain a string that is less lexicographically. Note that it is not necessary to obtain the minimum possible string.

If it is impossible to reverse some substring of the given string to obtain a string that is less, print "NO". Otherwise print "YES" and any suitable substring.

String x is lexicographically less than string y, if either x is a prefix of y (and x != y), or there exists such i (1 <= i <= min(|x|, |y|)), that x_i < y_i, and for any j (1 <= j < i) x_j = y_j. Here |a| denotes the length of the string a. The lexicographic comparison of strings is implemented by operator < in modern programming languages​​.

Input
The first line of the input contains one integer n (2 <= n <= 3 * 10^5) — the length of s.
The second line of the input contains the string s of length n consisting only of lowercase Latin letters.

Output
If it is impossible to reverse some substring of the given string to obtain a string which is lexicographically less, print "NO". Otherwise print "YES" and two indices l and r (1 <= l < r <= n) denoting the substring you have to reverse. If there are multiple answers, you can print any.
*/


/* Approach - Lexicographical Inversion Scanning / Adjacent Descent Detection (Time: O(N), Space: O(1))
 * Basically, we completely annihilate the O(N^2) substring permutation search by aggressively scanning for a single adjacent inversion point, mathematically proving that any localized descent guarantees a successful two-element rearrangement!
 * * Observation: 
 * - The absolute core of this architecture is the Adjacent Descent Law! To make a string lexicographically smaller by swapping *any* two indices, you simply need to find a place where a larger character precedes a smaller one (`s[i] > s[i+1]`). By swapping these two adjacent elements, the larger character is pushed to the right, immediately reducing the lexicographical value at the earliest possible position. If no such inversion exists anywhere in the string, the sequence is already in strictly non-decreasing sorted order, making it mathematically impossible to reduce!
 * - (The Commented Testcase Multi-Test Trap): Look closely at your `main()` function: `int t = 1; cin >> t; // cin >> t;`. You commented out the testcase extraction! In standard competitive programming problems of this type (e.g., Codeforces "Permutation Minimization" or similar string manipulation challenges), multiple test cases are almost universally guaranteed. Leaving `t = 1` hardcoded means your program will instantly fail online judge verification on multi-test runs. Always ensure `cin >> t` is active!
 * - (The 1-Based Indexing Output Shift): `cout << i+1 << " " << i+2 << endl;`. This is pristine! Because competitive programming problems require 1-based indexing for output positions while your loop uses 0-based indexing, shifting `i` by `+1` and `+2` flawlessly bridges the gap.
 * * How it runs:
 * First, we safely intercept the string length `n` and the target string `s`.
 * We ignite a high-speed linear sweep across the string from index `0` up to `n - 2`.
 * For every position, we check our adjacent inversion condition: `if (s[i] > s[i + 1])`. 
 * The exact millisecond our radar detects a descent, we triumphantly scream `"YES"`, output the 1-based indices of the adjacent pair, and instantly terminate!
 * If the linear sweep completes without triggering a single descent, we safely output `"NO"`, confirming the string is locked in optimal order at raw silicon speed!
 */



#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long  n;
    cin >> n;
    string s;
    cin >> s;

    for(int i=0;i<n-1;i++){
        if(s[i] > s[i+1]){
            cout << "YES\n";
            cout << i+1 << " " << i+2 << endl; 
            return;
        }
    }

    cout << "NO\n";
}


int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t=1;
    // cin >> t;
    while(t--) {
        solve();  
    }

    return 0;
}
