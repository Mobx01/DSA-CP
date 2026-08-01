/*
Codeforces PS - 1117C. Magic Ship
time limit per test: 2 seconds
memory limit per test: 256 megabytes

You a captain of a ship. Initially you are standing in a point (x1, y1) (obviously, all positions in the sea can be described by cartesian plane) and you want to travel to a point (x2, y2).
You know the weather forecast — the string s of length n, consisting only of letters U, D, L and R. The letter corresponds to a direction of wind. Moreover, the forecast is periodic, e.g. the first day wind blows to the side s1, the second day — s2, the n-th day — sn and (n+1)-th day — s1 again and so on.

Ship coordinates change the following way:
if wind blows the direction U, then the ship moves from (x, y) to (x, y+1);
if wind blows the direction D, then the ship moves from (x, y) to (x, y-1);
if wind blows the direction L, then the ship moves from (x, y) to (x-1, y);
if wind blows the direction R, then the ship moves from (x, y) to (x+1, y).

The ship can also either go one of the four directions or stay in place each day. If it goes then it's exactly 1 unit of distance. Transpositions of the ship and the wind add up. If the ship stays in place, then only the direction of wind counts. For example, if wind blows the direction U and the ship moves the direction L, then from point (x, y) it will move to the point (x-1, y+1), and if it goes the direction U, then it will move to the point (x, y+2).

You task is to determine the minimal number of days required for the ship to reach the point (x2, y2).

Input
The first line contains two integers x1, y1 (0 ≤ x1, y1 ≤ 10^9) — the initial coordinates of the ship.
The second line contains two integers x2, y2 (0 ≤ x2, y2 ≤ 10^9) — the coordinates of the destination point.
It is guaranteed that the initial coordinates and destination point coordinates are different.
The third line contains a single integer n (1 ≤ n ≤ 10^5) — the length of the string s.
The fourth line contains the string s itself, consisting only of letters U, D, L and R.

Output
The only line should contain the minimal number of days required for the ship to reach the point (x2, y2).
If it's impossible then print "-1".
*/


/* Approach - Binary Search on Answer & Prefix 2D Sums (Time: O(N + log(MAX_DAYS)), Space: O(N))
 * Basically, we mathematically calculate the exact position the wind will drag the ship to over any massive amount of time in strict O(1) time, and use binary search to hone in on the absolute minimum number of days needed to successfully steer to the target!
 * * Observation: 
 * - If we can reach the target in 'k' days, we mathematically can also reach it in 'k + 1' days (we simply absorb the extra wind push by steering against it or standing perfectly still). This creates a flawless monotonic true/false curve, making Binary Search the absolute perfect algorithm for the job!
 * - Simulating the wind day-by-day for billions of days would instantly cause a catastrophic Time Limit Exceeded (TLE) crash. By elegantly precomputing the wind's net displacement over exactly one full string cycle using Prefix Arrays, we can instantly calculate the total wind displacement for ANY massive number of days using simple division (`k / n`) and modulo (`k % n`) math!
 * - The ship can steer itself a maximum of 1 unit per day. Therefore, if the absolute Manhattan distance from where the wind blindly pushes us to our true target is less than or equal to our available 'k' steering moves, reaching the destination is 100% physically possible!
 * * How it runs:
 * First, we safely extract our starting coordinates, target coordinates, and sweep through the entire `wind` string to construct our `pref_x` and `pref_y` arrays, aggressively tallying the net X and Y directional displacement at every single step of the cycle.
 * Then, we deploy our massive binary search! We set our search space from 0 all the way up to an astronomical `2e15` days to flawlessly cover even the absolute worst-case scenarios where the wind violently opposes us every single day.
 * Next, for every single `mid` day tested, we trigger our `possible()` function. We mathematically calculate the exact number of full wind `cycles` and leftover `rem` days to instantly pinpoint our unsteered `final_x` and `final_y` positions.
 * Inside `possible()`, we measure the strict Manhattan distance (`required_moves`) between that wind-blown position and our final destination. If it requires less than or equal to `mid` moves, we have successfully proven it is reachable!
 * Finally, we securely lock that successful `mid` into `ans` and fiercely pull our `right` bound completely in to search for an even faster time. If it fails, we push our `left` bound up. Once the search space completely collapses, we confidently print our absolute minimum days!
 */


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool possible(ll k, ll x1, ll y1, ll x2, ll y2, ll n, const vector<ll>& pref_x, const vector<ll>& pref_y) {
    // full cycles of the wind string occur in k days
    ll cycles = k / n;
    // leftover days remain after the full cycles
    ll rem = k % n;
    
    //total wind displacement 
    ll wind_dx = cycles * pref_x[n] + pref_x[rem];
    ll wind_dy = cycles * pref_y[n] + pref_y[rem];
    
    // Where does the wind push the ship if  don't steer at all
    ll final_x = x1 + wind_dx;
    ll final_y = y1 + wind_dy;
    
    ll required_moves = abs(final_x - x2) + abs(final_y - y2);

    return required_moves <= k;
}

ll solve() {
    ll x1, y1, x2, y2, n;
    cin >> x1 >> y1 >> x2 >> y2 >> n;
    
    string wind;
    cin >> wind;

    vector<ll> pref_x(n + 1, 0);
    vector<ll> pref_y(n + 1, 0);
    
    for(int i = 0; i < n; i++) {
        pref_x[i+1] = pref_x[i];
        pref_y[i+1] = pref_y[i];
        
        if(wind[i] == 'U') pref_y[i+1]++;
        else if(wind[i] == 'D') pref_y[i+1]--;
        else if(wind[i] == 'L') pref_x[i+1]--;
        else if(wind[i] == 'R') pref_x[i+1]++;
    }

    // Binary Search
    ll left = 0, right = 2e15; 
    ll ans = -1;

    while(left <= right) {
        ll mid = left + (right - left) / 2;

        if(possible(mid, x1, y1, x2, y2, n, pref_x, pref_y)) {
            ans = mid;
            right = mid - 1; // Try  smaller number of days
        } else {
            left = mid + 1;  // need more days
        }
    }

    return ans;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << solve() << "\n";  

    return 0;
}
