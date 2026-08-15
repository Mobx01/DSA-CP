/*
Codeforces - 1543A. Exciting Bets
Time limit per test: 1 second
Memory limit per test: 256 megabytes

Welcome to Rockport City!
It is time for your first ever race in the game against Ronnie. To make the race interesting, you have bet a dollars and Ronnie has bet b dollars. But the fans seem to be disappointed. The excitement of the fans is given by gcd(a,b), where gcd(x,y) denotes the greatest common divisor (GCD) of integers x and y. To make the race more exciting, you can perform two types of operations:
Increase both a and b by 1.
Decrease both a and b by 1. This operation can only be performed if both a and b are greater than 0.

In one move, you can perform any one of these operations. You can perform arbitrary (possibly zero) number of moves. Determine the maximum excitement the fans can get and the minimum number of moves required to achieve it.
Note that gcd(x,0) = x for any x >= 0.

Input
The first line of input contains a single integer t (1 <= t <= 5 * 10^3) — the number of test cases.
The first and the only line of each test case contains two integers a and b (0 <= a, b <= 10^18).

Output
For each test case, print a single line containing two integers.
If the fans can get infinite excitement, print 0 0.
Otherwise, the first integer must be the maximum excitement the fans can get, and the second integer must be the minimum number of moves required to achieve that excitement.
*/


/* Approach - Pure Euclidean Mathematics / O(1) Modulo Optimization (Time: O(1), Space: O(1))
 * Basically, we completely bypass simulating step-by-step operations by aggressively exploiting the fundamental Euclidean theorem, violently snapping to the absolute maximum possible GCD using pure modulo arithmetic!
 * * Observation: 
 * - The absolute unbreakable law of Euclidean mathematics dictates that the Greatest Common Divisor of any two numbers can NEVER physically exceed their absolute difference! Mathematically: GCD(A, B) <= |A - B|. This instantly locks our maximum possible GCD strictly to `abs(a - b)`!
 * - (The Absolute Game-Breaker): To achieve this maximum GCD, our numbers MUST be shifted to become perfect multiples of `|a - b|`. Instead of violently looping to find the nearest multiple, we deploy the modulo operator `%` to mathematically extract the exact distance in a single blistering CPU cycle!
 * - A number `a` is structurally trapped between two multiples of our target `ans1`. The distance to the lower multiple is exactly `a % ans1` (achieved by subtracting). The distance to the next higher multiple is exactly `ans1 - (a % ans1)` (achieved by adding). To mathematically minimize operations, we ruthlessly pit these two distances against each other and take the absolute minimum!
 * - (The Infinite Anomaly): If `a` and `b` are perfectly identical, their difference is 0, which mathematically grants them an infinite GCD without a single operation! Your code brilliantly intercepts this edge case right out of the gate, preventing a catastrophic divide-by-zero error when the modulo engine fires!
 * * How it runs:
 * First, we safely extract our two targets `a` and `b`. The exact millisecond we detect `a == b`, we aggressively terminate the timeline, printing "0 0" and instantly returning!
 * If they differ, we calculate the absolute difference `ans1 = abs(a - b)`. This violently cements the absolute highest possible GCD we can mathematically forge!
 * Next, we ignite the modulo engine: `ans2 = a % ans1`. This instantly calculates the exact number of subtractions required to hit the lower multiple.
 * We then fiercely deploy the `min()` function, ruthlessly comparing the downward distance (`ans2`) against the upward distance (`ans1 - ans2`), permanently locking in the absolute shortest operational path!
 * Finally, we confidently print the maximum GCD and the exact minimum operations required to achieve it, effortlessly crushing the problem in absolute peak O(1) time without simulating a single loop!
 */


include <bits/stdc++.h>
using namespace std;

void solve() {
    long long a ,b;
    cin >> a >> b;
    if( a == b){
        cout << "0 0" << endl;
        return;
    }
    long long ans1 = abs(a-b);
    long long ans2 = a%ans1;
    ans2  = min (ans2,ans1-ans2);
    cout << ans1 <<" " << ans2 <<endl;
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
