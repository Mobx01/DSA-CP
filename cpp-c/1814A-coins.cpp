/*Codeforces PS - 1814A. Coins
In Berland, there are two types of coins, having denominations of 2 and k burles.
Your task is to determine whether it is possible to represent n burles in coins, i.e. whether there exist non-negative integers x and y such that 2⋅x + k⋅y = n.

Input
The first line contains a single integer t (1 ≤ t ≤ 10^4) — the number of test cases.
The only line of each test case contains two integers n and k (1 ≤ k ≤ n ≤ 10^18; k ≠ 2).

Output
For each test case, print YES if it is possible to represent n burles in coins; otherwise, print NO. You may print each letter in any case (YES, yes, Yes will all be recognized as positive answer, NO, no and nO will all be recognized as negative answer).
*/

/* Approach - Math & Parity Case Analysis (Time: O(1), Space: O(1))
 * Basically, we determine if a target condition can be met by analyzing the even/odd parity of the numbers 'n' and 'k'.
 * * Observation: 
 * - The number 1 acts as a universal building block, so if 'k' is 1, the answer is always guaranteed to be yes.
 * - If 'n' is even, it naturally satisfies the condition (likely because it can be cleanly formed purely by 2s).
 * - If 'n' is odd, it fundamentally requires an odd component to reach. An even 'k' will absolutely never be able to bridge the gap to an odd 'n' (since even + even = even). Therefore, an odd 'n' strictly demands an odd 'k'!
 * * How it runs:
 * First, we read in our long integers 'n' and 'k'. We immediately check our ultimate base case: if 'k == 1', we print "YES" and return early.
 * Then, we evaluate the parity of 'n'. If 'n' is evenly divisible by 2 ('n % 2 == 0'), we confidently print "YES".
 * Finally, if 'n' is odd, we fall back to checking 'k'. If 'k' is also odd ('k % 2 == 1'), the parities allow a valid combination, so we print "YES". If 'k' is even, it's mathematically impossible, so we print "NO"!
 */


#include <iostream>
using namespace std;

void solve() {
    long long n,k;
    cin >> n >> k;
   
   if(k == 1){
    cout << "YES\n";
    return;
   }
   if(n%2==0){
    cout<<"YES\n";
   }else{
    if(k%2 == 1)cout<<"YES\n";
    else cout<<"NO\n";
   }
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
