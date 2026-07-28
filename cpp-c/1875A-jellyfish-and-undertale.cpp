/*
Codeforces PS - 1875A. Jellyfish and Undertale

Flowey has planted a bomb in Snowdin!
The bomb has a timer that is initially set to b. Every second, the timer will decrease by 1. When the timer reaches 0, the bomb will explode! To give the residents of Snowdin enough time to evacuate, you will need to delay the bomb from exploding for as long as possible.

You have n tools. Each tool can only be used at most once. If you use the i-th tool, the timer will increase by xi. However, if the timer is changed to an integer larger than a, the timer will be set to a due to a bug.

More specifically, the following events will happen every second in the following order:
You will choose some (possibly none) of your tools that have not been used before. If you choose the i-th tool, and the bomb's timer is currently set to c, the timer will be changed to min(c + xi, a).
The timer decreases by 1.
If the timer reaches 0, the bomb explodes.

Jellyfish now wants to know the maximum time in seconds until the bomb explodes if the tools are used optimally.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1 ≤ t ≤ 2000). The description of the test cases follows.
The first line of each test case contains three integers a, b and n (1 ≤ b ≤ a ≤ 10^9, 1 ≤ n ≤ 100) — the maximum value of the bomb's timer, the initial value of the timer of the bomb and the number of tools.
The second line of each test contains n integers x1, x2, …, xn (1 ≤ xi ≤ 10^9) — the number the timer can increase by using the i-th tool.
Note that the sum of n over all test cases is not bounded.

Output
For each test case, output a single integer — the maximum time in seconds until the bomb explodes.
*/

/* Approach - Greedy Accumulation / Capacity Capping (Time: O(N), Space: O(N))
 * Basically, we mathematically determine the absolute maximum effective gain each tool can provide without hitting the hard ceiling, and greedily sum them all up with our starting value!
 * * Observation: 
 * - To squeeze out the absolute maximum total time, we mathematically MUST wait to use a tool until our current timer drops down to exactly 1.
 * - If we trigger a tool at 1, the new value becomes `1 + temp`. Since the timer is strictly capped at `a`, the maximum value it can reach is `min(1 + temp, a)`. Therefore, the absolute maximum net gain we can physically extract from any single tool is flawlessly clamped to `a - 1`!
 * - Because the order of operations doesn't matter as long as we optimally wait for 1, we can just independently sum the maximum potential gain of every single element!
 * - (Optimization/Bug Alert: The code dynamically allocates a Variable Length Array `int inp[n]`, which is a GCC compiler extension and absolutely NOT standard C++! Furthermore, storing the values in an array is completely unnecessary. We can brilliantly add the clamped value directly to `res` on the fly as we read it, instantly dropping our auxiliary space down to a perfect, guaranteed O(1)!)
 * * How it runs:
 * First, we safely extract our maximum capacity `a`, initial timer `b`, and total number of elements `n`.
 * Then, we trigger a loop to read exactly `n` elements. For every single incoming value `temp`, we aggressively clamp it against `a - 1` to find its true maximum contribution and store it inside our array.
 * Next, we securely anchor our running total `res` perfectly to our initial starting time `b`.
 * Finally, we physically sweep through our populated array, continuously add every single mathematically capped value directly to `res`, and confidently print our absolute maximum possible duration!
 */


#include <bits/stdc++.h>
using namespace std;

void solve() {
   long long a,b,n;
   cin >> a >> b >> n;
   int inp[n];
   for(int i =0;i<n;i++){
    long long temp ;
    cin >> temp;
    inp[i] = min(temp,a-1);
   }
   long long res = b;
   for(int i : inp) res+= i;

   cout<< res << endl;
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
