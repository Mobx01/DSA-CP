/*
Codeforces - 1607B. Odd Grasshopper
Time limit per test: 1 second
Memory limit per test: 256 megabytes

The grasshopper is located on the numeric axis at the point with coordinate x_0.
Having nothing else to do he starts jumping between integer points on the axis. Making a jump from a point with coordinate x with a distance d to the left moves the grasshopper to a point with a coordinate x - d, while jumping to the right moves him to a point with a coordinate x + d.

The grasshopper is very fond of positive integers, so for each integer i starting with 1 the following holds: exactly i minutes after the start he makes a jump with a distance of exactly i. So, in the first minutes he jumps by 1, then by 2, and so on.

The direction of a jump is determined as follows: if the point where the grasshopper was before the jump has an even coordinate, the grasshopper jumps to the left, otherwise he jumps to the right.

For example, if after 18 consecutive jumps he arrives at the point with a coordinate 7, he will jump by a distance of 19 to the right, since 7 is an odd number, and will end up at a point 7 + 19 = 26. Since 26 is an even number, the next jump the grasshopper will make to the left by a distance of 20, and it will move him to the point 26 - 20 = 6.

Find exactly which point the grasshopper will be at after exactly n jumps.

Input
The first line of input contains an integer t (1 <= t <= 10^4) — the number of test cases.
Each of the following t lines contains two integers x_0 (-10^14 <= x_0 <= 10^14) and n (0 <= n <= 10^14) — the coordinate of the grasshopper's initial position and the number of jumps.

Output
Print exactly t lines. On the i-th line print one integer — the answer to the i-th test case — the coordinate of the point the grasshopper will be at after making n jumps from the point x_0.
*/


/* Approach - Pure Mathematical Cycle / O(1) Parity Grouping (Time: O(1), Space: O(1))
 * Basically, we completely annihilate the need for a massive simulation loop by aggressively exploiting a perfect 4-step mathematical cycle, calculating the absolute final position in blistering O(1) time!
 * * Observation: 
 * - The absolute nightmare of this problem is the sheer scale of 'n'. If you tried to physically simulate every single jump one by one, a massive input would violently crash into a Time Limit Exceeded (TLE) error!
 * - (The Absolute Game-Breaker): If you manually trace the grasshopper's jumps, you will instantly discover a flawless, unbreakable mathematical cycle every exactly 4 steps! 
 * - Assuming an even starting position, the sequence of jumps over 4 minutes will ALWAYS follow the exact same directional pattern (e.g., Left, Right, Right, Left). The mathematical net displacement of any 4 consecutive jumps in this pattern is perfectly, unequivocally 0!
 * - This brutally shreds the timeline down to a maximum of 3 meaningful jumps. We just aggressively calculate the remainder (`n % 4`) to find exactly where the grasshopper is stranded inside the current incomplete cycle!
 * - (Parity Masterstroke): If the starting position 'x' is ODD, the exact same cycle occurs, but the physical directions are flawlessly and permanently inverted! We brilliantly handle this by simply subtracting our calculated net displacement instead of adding it!
 * * How it runs:
 * First, we safely extract our starting coordinate `x` and the massive total jumps `n`.
 * Then, we violently snap 'n' down to its core remainder using `n % 4`. 
 * We aggressively lock in the base net displacement (`final_pos`): If remainder is 0, net is 0. If 1, net is `-n`. If 2, the math resolves to exactly `1`. If 3, it violently rebounds to `n + 1`!
 * Next, we trigger a strict parity check on our original coordinate `x`. If `x` was even, we fiercely add our displacement directly to `x`. If `x` was odd, we mathematically invert the timeline and aggressively subtract the displacement!
 * Finally, we confidently print the absolute final coordinate, completely bypassing millions of recursive operations to deliver the answer in a flawless fraction of a millisecond!
 */


#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long x,n;

    cin >> x >> n ;
    long long final_pos ;

    if(n%4==0)final_pos = 0;
    else if(n%4 == 1) final_pos = -n;
    else if(n%4 == 2) final_pos = 1;
    else final_pos = n+1;

    if(x%2 ==0 ) final_pos = x+final_pos;
    else final_pos = x - final_pos;
    
    cout << final_pos <<"\n";
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
