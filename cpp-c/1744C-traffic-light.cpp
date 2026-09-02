/*
Codeforces - 1744C. Traffic Light
Time limit per test: 1 second
Memory limit per test: 256 megabytes

You find yourself on an unusual crossroad with a weird traffic light. That traffic light has three possible colors: red (r), yellow (y), green (g). It is known that the traffic light repeats its colors every n seconds and at the i-th second the color s_i is on.

That way, the order of the colors is described by a string. For example, if s = "rggry", then the traffic light works as the following: red-green-green-red-yellow-red-green-green-red-yellow- ... and so on.

More formally, you are given a string s_1, s_2, ..., s_n of length n. At the first second the color s_1 is on, at the second — s_2, ..., at the n-th second the color s_n is on, at the n+1-st second the color s_1 is on and so on.

You need to cross the road and that can only be done when the green color is on.

You know which color is on the traffic light at the moment, but you don't know the current moment of time. You need to find the minimum amount of time in which you are guaranteed to cross the road.
You can assume that you cross the road immediately.

For example, with s = "rggry" and the current color r there are two options: either the green color will be on after 1 second, or after 3. That way, the answer is equal to 3 — that is the number of seconds that we are guaranteed to cross the road, if the current color is r.

Input
The first line contains a single integer t (1 <= t <= 10^4) — the number of test cases.
Then the description of the test cases follows.
The first line of each test case contains an integer n and a symbol c (1 <= n <= 2 * 10^5, c is one of allowed traffic light colors r, y or g) — the length of the string s and the current color of the traffic light.
The second line of each test case contains a string s of the length n, consisting of the letters r, y and g.
It is guaranteed that the symbol g is in the string s and the symbol c is in the string s.
It is guaranteed, that the sum of n over all test cases does not exceed 2 * 10^5.

Output
For each test case output the minimal number of second in which you are guaranteed to cross the road.
*/



/* Approach - Reverse Temporal Sweep / Virtual State Tracking (Time: O(N), Space: O(1) auxiliary)
 * Basically, we completely annihilate the O(N log N) binary search and the massive heap allocations by aggressively deploying a reverse linear sweep, mathematically carrying the position of the nearest 'g' backward through time!
 * * Observation: 
 * - The absolute core of this architecture is the Right-to-Left State Carry! Because you only ever care about the NEXT 'g' to your right, if you sweep the timeline backwards, the exact millisecond you hit a 'g', you become the beacon! As you continue moving left, every single 'c' you collide with instantly knows EXACTLY how far away the beacon is—no searching required!
 * - (The O(N log N) Binary Search Trap): Your logic flawlessly handles the circular nature, but deploying `lower_bound` inside the main loop is a catastrophic CPU bottleneck! You are forcing the hardware to dynamically search a binary tree for EVERY single 'c' character. This violently degrades a purely linear O(N) problem down to a sluggish O(N log N)! 
 * - (The Heap Allocation Bomb): `string doubled = s + s;` and `vector<int> green;`. You are aggressively allocating TWO completely separate massive chunks of dynamic memory! For a string of 10^5 characters, you violently burn heap space and completely thrash the L1 cache. 
 * - (Optimization Alert / The Virtual Modulo Nuke): You can completely vaporize BOTH the `doubled` string and the `green` vector! You do NOT need physical memory to simulate a circular array! You can just run a virtual loop from `2*n - 1` down to `0`, and read the character using pure modulo arithmetic: `s[i % n]`. This instantly shreds your auxiliary space complexity down to absolute peak O(1)!
 * * How it runs (The O(1) Optimized Vision):
 * First, we safely intercept the string and instantly lock a `last_seen_g` register to `-1`. 
 * We ignite a high-speed REVERSE linear sweep, launching our iterator from `2*n - 1` and violently counting backward down to `0`. 
 * At every step, we dynamically extract the current character using our modulo engine `s[i % n]`. 
 * The exact millisecond our radar detects a 'g', we aggressively overwrite `last_seen_g = i`, locking in our new spatial beacon.
 * If our radar detects the target character `c`, AND we are currently operating within the original first-half timeline (`i < n`), we instantly calculate the kinetic distance: `last_seen_g - i`, and ruthlessly smash it against our global `ans` maximum!
 * Finally, we confidently output the absolute highest wait time, flawlessly crushing the simulation in a single, blazing-fast O(N) hardware sweep with strictly zero heap allocations!
 */


#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    char c;
    cin >> c;

    string s;
    cin >> s;

    // If already green, distance is always 0
    if (c == 'g') {
        cout << 0 << '\n';
        return;
    }

    // Duplicate string to handle circular nature
    string doubled = s + s;

    vector<int> green;

    // Store positions of 'g'
    for (int i = 0; i < 2 * n; i++) {
        if (doubled[i] == 'g') {
            green.push_back(i);
        }
    }

    int ans = 0;

    // For every occurrence of c in the original string
    for (int i = 0; i < n; i++) {
        if (doubled[i] == c) {

            // Find first 'g' index >= i
            auto it = lower_bound(green.begin(), green.end(), i);

            ans = max(ans, *it - i);
        }
    }

    cout << ans << '\n';
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
