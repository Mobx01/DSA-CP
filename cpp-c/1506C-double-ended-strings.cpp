/*
Codeforces - 1506C. Double-ended Strings
Time limit per test: 2 seconds
Memory limit per test: 256 megabytes

You are given the strings a and b, consisting of lowercase Latin letters. You can do any number of the following operations in any order:
if |a| > 0 (the length of the string a is greater than zero), delete the first character of the string a, that is, replace a with a_2 a_3 ... a_n;
if |a| > 0, delete the last character of the string a, that is, replace a with a_1 a_2 ... a_{n-1};
if |b| > 0 (the length of the string b is greater than zero), delete the first character of the string b, that is, replace b with b_2 b_3 ... b_n;
if |b| > 0, delete the last character of the string b, that is, replace b with b_1 b_2 ... b_{n-1}.

Note that after each of the operations, the string a or b may become empty.

For example, if a = "hello" and b = "icpc", then you can apply the following sequence of operations:
delete the first character of the string a => a = "ello" and b = "icpc";
delete the first character of the string b => a = "ello" and b = "cpc";
delete the first character of the string b => a = "ello" and b = "pc";
delete the last character of the string a => a = "ell" and b = "pc";
delete the last character of the string b => a = "ell" and b = "p".

For the given strings a and b, find the minimum number of operations for which you can make the strings a and b equal. Note that empty strings are also equal.

Input
The first line contains a single integer t (1 <= t <= 100). Then t test cases follow.
The first line of each test case contains the string a (1 <= |a| <= 20), consisting of lowercase Latin letters.
The second line of each test case contains the string b (1 <= |b| <= 20), consisting of lowercase Latin letters.

Output
For each test case, output the minimum number of operations that can make the strings a and b equal.
*/



/* Approach - Brute-Force Substring Search to Dynamic Programming Longest Common Substring (Time: O(N * M), Space: O(min(N, M)))
 * Basically, we completely annihilate the catastrophic O(min(N, M)^4) brute-force time complexity by aggressively replacing nested substring extractions with a Dynamic Programming matrix, mathematically tracking common suffixes in pristine polynomial time!
 * * Observation: 
 * - The absolute core of this architecture is the Deletion Minimization Law! To minimize the total operations required to make two strings share a common substring, you must maximize the length of that shared substring (`maxlen`). The cost is then cleanly given by `(na - maxlen) + (nb - maxlen)`.
 * - (The Fatal `std::substr` Heap-Allocation Bomb): Your current logic iterates downwards from the maximum possible length, generating physical substring copies via `a.substr(i, len)` inside a heavy nested loop structure. For moderate string lengths (e.g., $N, M \ge 500$), this forces thousands of dynamic memory allocations on the heap, thrashing the cache and guaranteeing a brutal Time Limit Exceeded (TLE)!
 * - (Optimization Alert / The 2D Dynamic Programming Nuke): You can completely vaporize the substring generation loops by defining a 2D DP state: `dp[i][j]` represents the length of the longest common suffix of substrings `a[0...i-1]` and `b[0...j-1]`. If `a[i-1] == b[j-1]`, then `dp[i][j] = dp[i-1][j-1] + 1`; otherwise, it drops to `0`. By maintaining a running global maximum during a single O(N * M) pass—and compressing the space down to O(min(N, M)) using a rolling 1D vector—you achieve absolute hardware supremacy!
 * * How it runs:
 * First, we safely intercept both strings `a` and `b` and initialize our rolling DP array to track common suffix lengths.
 * We ignite a high-speed double-nested loop, evaluating character matches across the 2D grid.
 * For every matching pair, we increment our suffix length and immediately update our global `maxlen` register. Mismatched pairs cleanly reset their tracking state to `0`.
 * Finally, once the grid sweep completes, we plug the optimal `maxlen` into our cost formula `(na - maxlen) + (nb - maxlen)`, flushing the minimum operations required to the output stream at raw silicon speed!
 */



#include <bits/stdc++.h>

using namespace std;

void solve() {
    string a ,b;
    cin >> a >> b;

    //start with maximum length and check for all length .
    // the highest macthing lenght is final string so operations = original length - highest lenght for both strinf

    int na = a.length(),nb=b.length(),maxlen = 0;
    for(int len = min(na,nb);len > 0;len--){

        for(int i=0;i<=na-len;i++){//try all possible substring of a
            string asub = a.substr(i,len);
            for(int j=0;j<=nb-len;j++){
                string bsub = b.substr(j,len);

                if(asub == bsub){
                    maxlen = len;
                    break;
                }
            }
            if(maxlen != 0){
                break;
            }
        }
        if(maxlen != 0) break;
    }
    int opr = (na - maxlen) + (nb - maxlen);
    cout << opr << endl;
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
