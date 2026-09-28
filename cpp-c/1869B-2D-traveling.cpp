/*
Codeforces - 1869B. 2D Traveling
Time limit per test: 1 second
Memory limit per test: 256 megabytes

Piggy lives on an infinite plane with the Cartesian coordinate system on it.
There are n cities on the plane, numbered from 1 to n, and the first k cities are defined as major cities. The coordinates of the i-th city are (x_i, y_i).

Piggy, as a well-experienced traveller, wants to have a relaxing trip after Zhongkao examination. Currently, he is in city a, and he wants to travel to city b by air. You can fly between any two cities, and you can visit several cities in any order while travelling, but the final destination must be city b.

Because of active trade between major cities, it's possible to travel by plane between them for free. Formally, the price of an air ticket f(i, j) between two cities i and j is defined as follows:
0, if cities i and j are both major cities
|x_i - x_j| + |y_i - y_j|, otherwise

Piggy doesn't want to save time, but he wants to save money. So you need to tell him the minimum value of the total cost of all air tickets if he can take any number of flights.

Input
The first line of input contains a single integer t (1 <= t <= 10^4) — the number of test cases. The description of test cases follows.
The first line of each test case contains four integers n, k, a, and b (2 <= n <= 2 * 10^5, 0 <= k <= n, 1 <= a, b <= n, a != b) — the number of cities, the number of major cities and the numbers of the starting and the ending cities.
Then n lines follow, the i-th line contains two integers x_i and y_i (-10^9 <= x_i, y_i <= 10^9) — the coordinates of the i-th city. The first k lines describe major cities. It is guaranteed that all coordinates are pairwise distinct.
It is guaranteed that the sum of n over all test cases does not exceed 2 * 10^5.

Output
For each test case, print a single integer — the minimum value of the total price of all air tickets.
*/



/* Approach - Manhattan Distance Minimization via Special/Major City Portals (Time: O(K), Space: O(N))
 * Basically, we completely annihilate brute-force graph pathfinding by aggressively evaluating direct travel versus portal-hopping through the first `k` special cities, computing the minimum Manhattan distance in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Portal Shortcut Invariant! When traveling from start city `a` to destination city `b`, you have two primary options: 
 *   1. Direct travel: Walking straight from `a` to `b` using pure Manhattan distance (`abs(xA - xB) + abs(yA - yB)`).
 *   2. Portal-hopping: Walking from `a` to *any* of the first `k` special/major cities (say, city `i`), teleporting instantly (costing `0` extra travel between special cities), and then walking from that special city to `b`. 
 * By pre-calculating the minimum distance from `a` to any special city (`min_a`) and from any special city to `b` (`min_b`), the optimal portal route cost simplifies cleanly to `min_a + min_b`!
 * - (Safe Overflow-Guarded Initializers): Initializing minimum distance trackers to `LLONG_MAX / 2` prevents potential overflow issues when adding distances together later in calculations.
 * - (Macro Cleanliness): Leveraging competitive programming macros (`fast_io`, `ll`, `pb`, `all`, `F`, `S`) keeps the boilerplate tight, readable, and lightning-fast.
 * * How it runs:
 * First, we safely intercept total cities `n`, special portal count `k`, start city `a`, destination city `b`, and read all coordinate pairs into vector `cord` (using 1-based indexing adjusted via `a-1` and `b-1`).
 * We scan the first `k` special cities to find the minimum Manhattan distance from start city `a` to any portal.
 * We repeat the scan to find the minimum Manhattan distance from any portal to destination city `b`.
 * We take the minimum between the direct path and the optimal portal-hopping path (`min_a + min_b`).
 * Finally, we flush the minimum total distance to the output stream with absolute mathematical precision at raw silicon speed!
 */


#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define F first
#define S second

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve() {
    ll n,k,a,b,t1,t2;
    cin >> n >>k>>a>>b;
    vector<pll> cord;//{x,y}
    for(ll i=0;i<n;i++){
        cin >> t1 >> t2;
        cord.pb({t1,t2});
    }

    //check distance of startong from all major city for min dis
    ll min_a = LLONG_MAX/2,min_b=LLONG_MAX/2;
    for(ll i=0;i<k;i++){
        min_a = min(min_a , abs(cord[a-1].F - cord[i].F)+abs(cord[a-1].S - cord[i].S));
    }
    // same for destn
    for(ll i=0;i<k;i++){
        min_b = min(min_b , abs(cord[b-1].F - cord[i].F)+abs(cord[b-1].S - cord[i].S));
    }
    
    ll ans = min(abs(cord[a-1].F - cord[b-1].F) + abs(cord[a-1].S - cord[b-1].S) , min_a + min_b);

    cout << ans << endl;
 
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
