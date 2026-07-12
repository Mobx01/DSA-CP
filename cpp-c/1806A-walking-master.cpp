/*Codeforces PS - 1806A. Walking Master

YunQian is standing on an infinite plane with the Cartesian coordinate system on it. In one move, she can move to the diagonally adjacent point on the top right or the adjacent point on the left.
That is, if she is standing on point (x, y), she can either move to point (x+1, y+1) or point (x−1, y).
YunQian initially stands at point (a, b) and wants to move to point (c, d). Find the minimum number of moves she needs to make or declare that it is impossible.

Input
The first line contains a single integer t (1 ≤ t ≤ 10^4) — the number of test cases. The description of test cases follows.
The first line and only line of each test case contain four integers a, b, c, d (−10^8 ≤ a, b, c, d ≤ 10^8).

Output
For each test case, if it is possible to move from point (a, b) to point (c, d), output the minimum number of moves. Otherwise, output -1.
*/


/* Approach - Math & Coordinate Geometry (Time: O(1), Space: O(1))
 * Basically, we mathematically calculate the exact number of diagonal and horizontal moves required to reach the target, returning -1 if the target's coordinates violate the strict directional constraints of our allowed operations.
 * * Observation: 
 * - We can only increase the y-coordinate (via a move that increases both x and y). We can NEVER decrease y. Therefore, if the target y ('d') is strictly less than the starting y ('b'), it is mathematically impossible to reach.
 * - The exact number of diagonal moves required to align the y-coordinates is absolutely fixed at 'd - b'.
 * - We can only independently DECREASE the x-coordinate. Therefore, after making all required diagonal moves, if our newly updated x-coordinate is STILL less than the target x ('c'), we are permanently stranded. We cannot increase x without also increasing y and ruining our alignment!
 * * How it runs:
 * First, we evaluate the y-coordinates. If 'd < b', we immediately return -1. Otherwise, we calculate the required diagonal moves ('d - b') and record them in our 'moves' counter.
 * Then, we simulate the effect of these diagonal moves on our x-coordinate by adding 'd - b' to 'a'. 
 * Finally, we check our newly updated x position. If 'a < c', we return -1 since we can't push x forward anymore. If it is valid, we simply add the remaining necessary backward horizontal moves ('a - c') to our counter and return the total!
 */


#include <iostream>
using namespace std;

int solve() {
    long long a,b,c,d;
    cin >> a >> b >> c >> d;
   
   if(d < b) return -1;
   long long moves = d-b;
   a = a+(d-b);
   if(a<c) return -1;
   moves += (a-c);
   return moves;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        cout << solve() <<"\n";   
    }

    return 0;
}
