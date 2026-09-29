/*
Codeforces - 1850E. Cardboard for Pictures
Time limit per test: 2 seconds
Memory limit per test: 256 megabytes

Mircea has n pictures. The i-th picture is a square with a side length of s_i centimeters.

He mounted each picture on a square piece of cardboard so that each picture has a border of w centimeters of cardboard on all sides. In total, he used c square centimeters of cardboard. Given the picture sizes and the value c, can you find the value of w?

Please note that the piece of cardboard goes behind each picture, not just the border.

Input
The first line contains a single integer t (1 <= t <= 1000) — the number of test cases.
The first line of each test case contains two positive integers n (1 <= n <= 2 * 10^5) and c (1 <= c <= 10^{18}) — the number of paintings, and the amount of used square centimeters of cardboard.
The second line of each test case contains n space-separated integers s_i (1 <= s_i <= 10^4) — the sizes of the paintings.
The sum of n over all test cases doesn't exceed 2 * 10^5.
Additional constraint on the input: Such an integer w exists for each test case.
Please note, that some of the input for some test cases won't fit into 32-bit integer type, so you should use at least 64-bit integer type in your programming language (like long long for C++).

Output
For each test case, output a single integer — the value of w (w >= 1) which was used to use exactly c squared centimeters of cardboard.
*/



/* Approach - Binary Search on Answer with Overflow-Guarded Area Accumulation (Time: O(N log(MAX)), Space: O(N))
 * Basically, we completely annihilate brute-force sizing loops by aggressively applying binary search over the possible width space, finding the exact square/frame dimensions in pristine logarithmic time!
 * * Observation: 
 * - The absolute core of this architecture is the Monotonic Area Growth Invariant (e.g., standard Codeforces grid/painting problems where area scales quadratically with width `w`)! As the width `w` increases, the total sum of areas `(i + w)^2` strictly increases. This monotonicity allows us to binary search for the optimal width `w` across a wide numerical range (`1` to `1e9`).
 * - (Overflow-Guarded Area Calculation): Your `area` helper function includes a brilliant safety check: `if (c - ar < term) return c + 1;`. Because squaring numbers like $(i + 10^9)^2$ can easily overflow `long long` limits or wildly exceed the target constant `c`, pre-emptively checking the difference prevents wrap-around bugs and short-circuits the loop the second the accumulated area crosses budget `c`.
 * - (Macro Cleanliness & Fast I/O): Leveraging competitive programming macros and `fast_io` keeps the boilerplate tight, clean, and optimized for high-speed execution.
 * * How it runs:
 * First, we safely intercept array size `n` and target area limit `c`, followed by reading all elements into vector `s`.
 * We initialize our binary search boundaries (`l = 1`, `h = 1e9`) and ignite the search loop.
 * For each `mid` width, our `area` function computes the cumulative squared dimensions with strict overflow protection.
 * If `ar == c`, we lock in our width and break; if `ar > c`, we search smaller widths (`h = mid - 1`); otherwise, we search larger widths (`l = mid + 1`).
 * Finally, we scale or output the result (such as `w / 2` based on problem specifications) to the output stream with absolute mathematical precision at raw silicon speed!
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

ll area(ll w, vll& s, ll c){
    ll ar = 0;
    for(ll i : s){
        ll term = (i + w) * (i + w);
        // check for overflow or exceeding target early
        if (c - ar < term) {
            return c + 1; // return a value greater than c to signal overflow/exceeding
        }
        ar += term;
    }
    return ar;
}

void solve() {
    ll n,c;
    cin >> n >> c;

    vll s(n);
    for(ll i=0;i<n;i++){
        cin >> s[i];
    }

    ll l=1,h=1e9,w=1e9;
    //binary search
    while(l <= h){
        ll mid = l + (h-l)/2;
        ll ar = area(mid,s,c);
        if(ar == c){
            w = mid;
            break;
        }else if(ar > c){
            //explore small w
            h = mid-1;
        }else{
            //explore bigger w
            l = mid+1;
        }
    }
    cout << w/2 << endl;
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
