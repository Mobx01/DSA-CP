/*
Codeforces - 1606A. AB Balance
Time limit per test: 2 seconds
Memory limit per test: 256 megabytes

You are given a string s of length n consisting of characters a and/or b.
Let AB(s) be the number of occurrences of string ab in s as a substring. Analogically, BA(s) is the number of occurrences of ba in s as a substring.

In one step, you can choose any index i and replace s_i with character a or b.
What is the minimum number of steps you need to make to achieve AB(s) = BA(s)?

Reminder:
The number of occurrences of string d in s as substring is the number of indices i (1 <= i <= |s| - |d| + 1) such that substring s_i s_{i+1} ... s_{i+|d|-1} is equal to d. For example, AB(aabbbabaa) = 2 since there are two indices i: i=2 where aabbbabaa and i=6 where aabbbabaa.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1 <= t <= 1000). Description of the test cases follows.
The first and only line of each test case contains a single string s (1 <= |s| <= 100, where |s| is the length of the string s), consisting only of characters a and/or b.

Output
For each test case, print the resulting string s with AB(s) = BA(s) you'll get making the minimum number of steps.
If there are multiple answers, print any of them.
*/


/* Approach - Greedy Boundary Mutation / O(1) Endpoint Toggling (Time: O(N), Space: O(1))
 * Basically, we aggressively lock onto the absolute extreme boundaries of the string, and the exact millisecond they fail to match, we violently force a structural mutation on the very first character!
 * * Observation: 
 * - The absolute core of this logic is the hyper-fixation on `s[0]` and `s[n-1]`. By completely ignoring the entire internal body of the string, the algorithm mathematically guarantees a blistering O(1) operation time (excluding the initial O(N) string read)!
 * - (The Absolute Assumption): This code violently operates under the strict assumption that it is dealing with a binary character set (like exclusively 'a' and 'b'). Instead of mathematically copying `s[n-1]` into `s[0]` to guarantee a match, it blindly toggles `s[0]` between 'a' and 'b'!
 * - (Bug Alert / Optimization Masterstroke): Because it blindly hardcodes the toggle, if `s[n-1]` happens to be 'c', flipping `s[0]` from 'a' to 'b' completely fails to mathematically bridge the gap! To flawlessly guarantee a structural match regardless of the character set, you could instantly upgrade this by completely deleting the `if-else` block and simply executing `s[0] = s[n-1];`!
 * * How it runs:
 * First, we safely extract our raw string `s` and instantly calculate its absolute length `n`.
 * Then, we fiercely deploy our boundary radar, directly pitting the very first character `s[0]` against the very last character `s[n-1]`.
 * If they perfectly mirror each other, we completely bypass the mutation phase. But the exact millisecond a mismatch is detected, we aggressively dive into the toggle block!
 * We ruthlessly check if `s[0]` is currently 'a'. If it is, we violently overwrite it with 'b'. If it is literally anything else, we aggressively crush it into an 'a'!
 * Finally, we confidently print the newly forged string, completing the entire operation without simulating a single loop!
 */


#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    if(s[0] != s[n-1]){
        if(s[0] == 'a') s[0] = 'b';
        else s[0] = 'a';
    }
    cout << s << endl; 
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
