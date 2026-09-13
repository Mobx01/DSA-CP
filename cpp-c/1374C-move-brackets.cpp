/*
Codeforces - 1374C. Move Brackets
Time limit per test: 1 second
Memory limit per test: 256 megabytes

You are given a bracket sequence s of length n, where n is even (divisible by two). The string s consists of n/2 opening brackets '(' and n/2 closing brackets ')'.

In one move, you can choose exactly one bracket and move it to the beginning of the string or to the end of the string (i.e. you choose some index i, remove the i-th character of s and insert it before or after all remaining characters of s).

Your task is to find the minimum number of moves required to obtain regular bracket sequence from s. It can be proved that the answer always exists under the given constraints.

Recall what the regular bracket sequence is:
"()" is regular bracket sequence;
if s is regular bracket sequence then "(" + s + ")" is regular bracket sequence;
if s and t are regular bracket sequences then s + t is regular bracket sequence.

For example, "()()", "(())()", "(())" and "()" are regular bracket sequences, but ")(", "()(" and ")))" are not.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1 <= t <= 2000) — the number of test cases. Then t test cases follow.
The first line of the test case contains one integer n (2 <= n <= 50) — the length of s. It is guaranteed that n is even. The second line of the test case containg the string s consisting of n/2 opening and n/2 closing brackets.

Output
For each test case, print the answer — the minimum number of moves required to obtain regular bracket sequence from s. It can be proved that the answer always exists under the given constraints.
*/



/* Approach - Prefix Balance Tracking & Deficit Correction (Time: O(N), Space: O(1))
 * Basically, we completely annihilate complex stack-based simulations by aggressively tracking the running prefix balance, mathematically capturing bracket deficits in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Running Prefix Invariant! By treating `'('` as `+1` and `')'` as `-1`, you monitor the cumulative balance across the string. The exact moment the balance drops below zero (`sum < 0`), it signals that a closing bracket has appeared without a matching opener. Your code brilliantly intercepts this deficit by resetting the baseline (`sum = 0`) and incrementing the operation counter (`op++`), perfectly counting the structural corrections needed!
 * - (Single-Pass Linear Efficiency): Your traversal sweeps through the string exactly once in $O(N)$ time with O(1) auxiliary space, avoiding any heavy stack allocations or redundant re-scans.
 * * How it runs:
 * First, we safely intercept string length `n` and the target string `s`.
 * We ignite a high-speed linear sweep, accumulating our bracket balance `sum`.
 * Whenever our balance dips below zero, we log an operation and reset our baseline to maintain structural integrity.
 * Finally, we flush the total operation count to the output stream with absolute mathematical precision at raw silicon speed!
 */



#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int sum =0,op=0;

    for(int i=0;i<n;i++){
        if(s[i] == ')'){
            sum--;
        }else{
            sum++;
        }

        if(sum < 0){
            sum=0;
            op++;
        }
    }

    cout << op << "\n";
    
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
