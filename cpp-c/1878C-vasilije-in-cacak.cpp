/*Codeforces PS - 1878C. Vasilije in Cacak

Aca and Milovan, two fellow competitive programmers, decided to give Vasilije a problem to test his skills.
Vasilije is given three positive integers: n, k, and x, and he has to determine if he can choose k distinct integers between 1 and n, such that their sum is equal to x.
Since Vasilije is now in the weirdest city in Serbia where Aca and Milovan live, Cacak, the problem seems weird to him. So he needs your help with this problem.

Input
The first line contains a single integer t (1 ≤ t ≤ 10^4) — the number of test cases.
The only line of each test case contains three integers n, k and x (1 ≤ n ≤ 2⋅10^5, 1 ≤ k ≤ n, 1 ≤ x ≤ 4⋅10^10) — the maximum element he can choose, the number of elements he can choose and the sum he has to reach.
Note that the sum of n over all test cases may exceed 2⋅10^5.

Output
For each test case output one line: "YES", if it is possible to choose k distinct integers between 1 and n, such that their sum is equal to x, and "NO", if it isn't.
You can output the answer in any case (for example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as a positive answer).
*/

/* Approach - Mathematical Boundaries / Continuous Range Sum (Time: O(1), Space: O(1))
 * Basically, we mathematically calculate the absolute lowest and highest possible sums we can form with 'k' elements, and check if our target 'x' perfectly falls inside that range!
 * * Observation: 
 * - To find if we can form a target sum `x` using exactly `k` distinct integers from 1 to `n`, we absolutely do not need to simulate or test combinations!
 * - We can easily find the absolute minimum possible sum by greedily picking the smallest `k` integers (1, 2, ..., k). 
 * - We can also find the absolute maximum possible sum by greedily picking the strictly largest `k` integers ((n-k+1), ..., n).
 * - Because we are working with a continuous sequence of integers, we can incrementally increase our sum by exactly 1 by simply swapping any chosen number for the next available larger number. This brilliantly guarantees that EVERY single integer strictly between `minsum` and `maxsum` is mathematically reachable! 
 * - This completely reduces a complex combinatorics problem down to a flawless O(1) constant time boundary check!
 * * How it runs:
 * First, we accurately extract our inputs: `n` (our maximum available integer), `k` (the exact number of elements to pick), and `x` (our target sum).
 * Then, we mathematically calculate our absolute `minsum` using the standard arithmetic progression formula `k * (k + 1) / 2`, perfectly representing the sum of the first 'k' numbers.
 * Next, we fiercely calculate our absolute `maxsum`. By taking the total sum of all numbers up to `n` and cleanly subtracting the sum of the unpicked first `n-k` numbers, we flawlessly isolate the exact sum of the top `k` largest integers!
 * Finally, we simply evaluate our target. If `x` falls perfectly within our mathematically proven inclusive boundary (`x >= minsum && x <= maxsum`), we confidently print "YES". Otherwise, it is structurally impossible to reach, and we safely print "NO"!
 */


#include <bits/stdc++.h>
using namespace std;

void solve() {
   long long n ,k,x;
   cin >> n >> k >> x;

  long long minsum = k*(k+1)/2;//sum of first k numbers
  long long maxsum =n*(n+1)/2 - (n-k+1)*(n-k)/2;
  if(x >= minsum && x <= maxsum)cout<<"YES\n";
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
