/*
Codeforces PS - 1837B. Comparison String
time limit per test: 2 seconds
memory limit per test: 512 megabytes

You are given a string s of length n, where each character is either < or >.
An array a consisting of n+1 elements is compatible with the string s if, for every i from 1 to n, the character si represents the result of comparing ai and ai+1, i.e.:
si is < if and only if ai < ai+1;
si is > if and only if ai > ai+1.

For example, the array [1, 2, 5, 4, 2] is compatible with the string <<>>. There are other arrays which are compatible with that string, for example, [13, 37, 42, 37, 13].
The cost of the array is the number of different elements in it. For example, the cost of [1, 2, 5, 4, 2] is 4; the cost of [13, 37, 42, 37, 13] is 3.
You have to calculate the minimum cost among all arrays which are compatible with the given string s.

Input
The first line contains one integer t (1 ≤ t ≤ 500) — the number of test cases.
Each test case consists of two lines:
the first line contains one integer n (1 ≤ n ≤ 100);
the second line contains the string s, consisting of n characters. Each character of s is either < or >.

Output
For each test case, print one integer — the minimum cost among all arrays which are compatible with the given string s.
*/


/* Approach - Longest Contiguous Subsegment / Greedy (Time: O(N), Space: O(N))
 * Basically, we mathematically prove that the absolute minimum number of distinct elements required to build the array perfectly matches the longest unbroken chain of identical inequalities, plus exactly one!
 * * Observation: 
 * - If you encounter an unbroken chain of `<` characters (e.g., `<<<<`), the numbers MUST strictly increase every single time. Because they must constantly grow without ever dropping, you are mathematically forced to introduce a brand new, distinct number for every single step of that specific chain!
 * - The exact same logic applies to an unbroken chain of `>`! However, the absolute millisecond the inequality flips direction (e.g., from `<` to `>`), you can brilliantly reuse numbers you already have (like `1 < 2 > 1`) to effortlessly avoid increasing your overall cost!
 * - Therefore, the absolute bottleneck of the entire array is strictly dictated by the single longest continuous streak of the exact same character. The minimum cost is flawlessly guaranteed to be the length of that maximum streak, plus 1 (to account for the starting element of that sequence)!
 * - (Optimization Note: The code manually loops `n` times to read characters one by one using `s.push_back()`. This is completely unnecessary! You can instantly read the entire string in one fell swoop with a simple `cin >> s`, or even better, process the characters completely on the fly as they are typed, instantly dropping your auxiliary space down to a perfect, guaranteed O(1)!)
 * * How it runs:
 * First, we safely extract the total length `n` and dynamically build our string `s` by reading in the characters.
 * Then, we securely initialize our `curseq` and `maxseq` trackers perfectly at 1, because even a single character inherently forces 2 distinct numbers (e.g., `a < b`).
 * Next, we trigger a high-speed linear sweep starting directly from index 1. We fiercely compare the current character `s[i]` with the preceding one `s[i-1]`.
 * If they perfectly match, the streak continues, and we aggressively increment `curseq`. If the direction violently flips, the chain is permanently broken, and we instantly reset `curseq` back to 1.
 * Finally, we continuously lock the absolute maximum chain length into `maxseq` at every step, confidently add exactly 1 to our ultimate longest streak, and print our absolute minimum possible cost!
 */


#include <bits/stdc++.h>
using namespace std;


void solve() {
    int  n;
    cin >> n;
    string s;
    for(int i =0;i<n;i++){
        char temp;
        cin >> temp;
        s.push_back(temp);
    }
    int curseq = 1 , maxseq = 1;
    for(int i = 1;i<n;i++){
        if(s[i] == s[i-1]) curseq++;
        else curseq =1;
        maxseq = max(curseq , maxseq);
    }
    maxseq = max(curseq , maxseq);
    cout << maxseq +1 << endl;
}

int main() {
    // Fast I/O
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--)
        solve();  

    return 0;
}#include <bits/stdc++.h>
using namespace std;


void solve() {
    int  n;
    cin >> n;
    string s;
    for(int i =0;i<n;i++){
        char temp;
        cin >> temp;
        s.push_back(temp);
    }
    int curseq = 1 , maxseq = 1;
    for(int i = 1;i<n;i++){
        if(s[i] == s[i-1]) curseq++;
        else curseq =1;
        maxseq = max(curseq , maxseq);
    }
    maxseq = max(curseq , maxseq);
    cout << maxseq +1 << endl;
}

int main() {
    // Fast I/O
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--)
        solve();  

    return 0;
}
