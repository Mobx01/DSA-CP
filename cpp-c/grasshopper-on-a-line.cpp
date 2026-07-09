/*Codeforces PS - 1837A. Grasshopper on a Line
You are given two integers x and k. Grasshopper starts in a point 0 on an OX axis. In one move, it can jump some integer distance, that is not divisible by k, to the left or to the right.

What's the smallest number of moves it takes the grasshopper to reach point x? What are these moves? If there are multiple answers, print any of them.

Input
The first line contains a single integer t (1 ≤ t ≤ 1000) — the number of testcases.
The only line of each testcase contains two integers x and k (1 ≤ x ≤ 100; 2 ≤ k ≤ 100) — the endpoint and the constraint on the jumps, respectively.

Output
For each testcase, in the first line, print a single integer n — the smallest number of moves it takes the grasshopper to reach point x.
In the second line, print n integers, each of them not divisible by k. A positive integer would mean jumping to the right, a negative integer would mean jumping to the left. The endpoint after the jumps should be exactly x.
Each jump distance should be from -10^9 to 10^9. In can be shown that, for any solution with the smallest number of jumps, there exists a solution with the same number of jumps such that each jump is from -10^9 to 10^9.
It can be shown that the answer always exists under the given constraints. If there are multiple answers, print any of them.
*/


/* Approach - Math & Case Analysis (Time: O(1), Space: O(1))
 * Basically, we want to reach a target distance 'x' using the absolute minimum number of jumps, while ensuring no individual jump distance is a multiple of 'k'.
 * * Observation: 
 * - The absolute best-case scenario is reaching the target in exactly 1 jump. We can only do this if the target 'x' itself is not perfectly divisible by 'k'.
 * - If 'x' is a multiple of 'k', a single direct jump is illegal. We are forced to split the journey into exactly 2 jumps. The smartest and easiest split is 'x - 1' and '1'. Because 'x' is a multiple of 'k' (and assuming k >= 2 based on typical problem constraints), it is mathematically guaranteed that neither 'x - 1' nor '1' will be divisible by 'k'!
 * * How it runs:
 * First, we read in our target distance 'x' and our forbidden multiple 'k'.
 * Then, we check the remainder using modulo. If 'x % k == 0', our direct path is blocked! We output 2 (for the number of jumps required), followed by our safely split jump sequence: "x - 1" and "1".
 * Finally, if 'x % k != 0', the direct path is wide open! We simply output 1 (since we only need one jump), followed by the full jump distance "x".
 */

#include <iostream>
using namespace std;

void solve() {
    int  k, x;
    cin >> x >> k;

    if(x%k == 0){
        cout << 2 << "\n";
        cout<< x-1 <<" " << 1 <<"\n";
    }else{
         cout << 1 << "\n";
        cout<< x <<"\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
       solve(); 
    }

    return 0;
}
