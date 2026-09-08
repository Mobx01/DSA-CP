/*
Codeforces - 1620B. Triangles on a Rectangle
Time limit per test: 2 seconds
Memory limit per test: 256 megabytes

A rectangle with its opposite corners in (0,0) and (w,h) and sides parallel to the axes is drawn on a plane.
You are given a list of lattice points such that each point lies on a side of a rectangle but not in its corner. Also, there are at least two points on every side of a rectangle.
Your task is to choose three points in such a way that:
exactly two of them belong to the same side of a rectangle;
the area of a triangle formed by them is maximum possible.
Print the doubled area of this triangle. It can be shown that the doubled area of any triangle formed by lattice points is always an integer.

Input
The first line contains a single integer t (1 <= t <= 10^4) — the number of testcases.
The first line of each testcase contains two integers w and h (3 <= w, h <= 10^6) — the coordinates of the corner of a rectangle.
The next two lines contain the description of the points on two horizontal sides. First, an integer k (2 <= k <= 2 * 10^5) — the number of points. Then, k integers x_1 < x_2 < ... < x_k (0 < x_i < w) — the x coordinates of the points in the ascending order. The y coordinate for the first line is 0 and for the second line is h.
The next two lines contain the description of the points on two vertical sides. First, an integer k (2 <= k <= 2 * 10^5) — the number of points. Then, k integers y_1 < y_2 < ... < y_k (0 < y_i < h) — the y coordinates of the points in the ascending order. The x coordinate for the first line is 0 and for the second line is w.
The total number of points on all sides in all testcases doesn't exceed 2 * 10^5.

Output
For each testcase print a single integer — the doubled maximum area of a triangle formed by such three points that exactly two of them belong to the same side.
*/



/* Approach - Maximal Interval Span Extraction / Bounding Box Area Maximization (Time: O(K log K), Space: O(K))
 * Basically, we completely annihilate the O(K^2) combinatorial pair comparison by aggressively sorting each boundary coordinate set, mathematically proving that the maximum possible rectangle area is always formed by the single widest span along one of the four grid walls!
 * * Observation: 
 * - The absolute core of this architecture is the Extreme-Span Boundary Law! When you cut a grid along a horizontal or vertical line, the rectangle with the maximum area is formed by the two furthest coordinates (the absolute minimum and maximum points) along that wall, multiplied by the perpendicular dimension. By sorting the coordinates on each wall, the widest span is trivially found between the last and first elements (`coords.back() - coords.front()`), completely bypassing any need to test intermediate pairs!
 * - (The Fatal Unsorted Vector Trap): Your logic relies heavily on `coords[sz(coords) - 1] - coords[0]`, assuming the input coordinates arrive pre-sorted! However, competitive programming platforms routinely inject unsorted coordinate sequences. If the input vectors are out of order, `coords[0]` and `coords.back()` will point to arbitrary boundary markers instead of the true geometric minimum and maximum, corrupting your span calculation and producing wrong answers! You MUST explicitly sort each vector (`sort(all(x0))`, etc.) immediately after reading them.
 * - (The Heap Allocation Penalty): You declare four separate `vll` vectors (`x0`, `xh`, `y0`, `yh`) and push elements dynamically inside `while` loops. This triggers multiple independent heap allocations. While acceptable for moderate constraints, pre-reserving capacity or sizing the vectors directly (`vector<ll> x0(k);`) avoids reallocation overhead and optimizes cache locality.
 * * How it runs:
 * First, we safely intercept the grid dimensions `w` and `h`.
 * We read the coordinate counts and populate the four boundary vectors for the bottom (`x0`), top (`xh`), left (`y0`), and right (`yh`) walls.
 * We (ideally) sort each vector to establish a strict ascending spatial hierarchy from minimum to maximum.
 * We evaluate the maximum possible area for each wall by multiplying the span between its extreme points (`max_coord - min_coord`) by the corresponding perpendicular dimension (`h` for horizontal walls, `w` for vertical walls).
 * Finally, we track the global maximum area across all four walls and flush the result to the output stream at raw silicon speed!
 */


#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    ll w ,h;
    cin >> w >>h;

    vll x0 ,xh,y0,yh;

    ll k,temp;
    cin >> k;
    while(k--){
        cin >> temp;
        x0.pb(temp);
    }
    cin >> k;
    while(k--){
        cin >> temp;
        xh.pb(temp);
    }
    cin >>k;
    while(k--){
        cin >> temp;
        y0.pb(temp);
    }
    cin >>k;
    while(k--){
        cin >> temp;
        yh.pb(temp);
    }

    ll maxarea =0;
    if(x0.size() > 1){
        maxarea = max(maxarea,(x0[sz(x0)-1]-x0[0])*h); 
    }
    if(xh.size() > 1){
        maxarea = max(maxarea,(xh[sz(xh)-1]-xh[0])*h); 
    }
    if(y0.size() > 1){
        maxarea = max(maxarea,(y0[sz(y0)-1]-y0[0])*w); 
    }
    if(yh.size() > 1){
        maxarea = max(maxarea,(yh[sz(yh)-1]-yh[0])*w); 
    }

    cout << maxarea << endl;

}

int main() {
    fast_io();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
