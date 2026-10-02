/*
Codeforces - 1791G1. Teleporters (Easy Version)
Time limit per test: 1 second
Memory limit per test: 256 megabytes

The only difference between the easy and hard versions are the locations you can teleport to.
Consider the points 0, 1, ..., n on the number line. There is a teleporter located on each of the points 1, 2, ..., n. At point i, you can do the following:
Move left one unit: it costs 1 coin.
Move right one unit: it costs 1 coin.
Use a teleporter at point i, if it exists: it costs a_i coins. As a result, you teleport to point 0. Once you use a teleporter, you can't use it again.

You have c coins, and you start at point 0. What's the most number of teleporters you can use?

Input
The input consists of multiple test cases. The first line contains an integer t (1 <= t <= 1000) — the number of test cases. The descriptions of the test cases follow.
The first line of each test case contains two integers n and c (1 <= n <= 2 * 10^5; 1 <= c <= 10^9) — the length of the array and the number of coins you have respectively.
The following line contains n space-separated integers a_1, a_2, ..., a_n (1 <= a_i <= 10^9) — the costs to use the teleporters.
It is guaranteed that the sum of n over all test cases does not exceed 2 * 10^5.

Output
For each test case, output the maximum number of teleporters you can use.
*/



/* Approach - Greedy Cost Transformation with Sorting and Budget Subtraction (Time: O(N log N), Space: O(N))
 * Basically, we completely annihilate brute-force subset enumeration by aggressively transforming element costs with positional offsets, sorting them in ascending order, and greedily buying as many items as possible within budget `c` in pristine log-linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Greedy Cost Invariant (e.g., standard Codeforces / competitive programming problems where item costs depend on their chosen index or position, such as `cost[i] = base_price[i] + index`). To maximize the total number of items purchased under a strict budget constraint `c`, sorting the transformed costs in non-decreasing order and picking items sequentially from cheapest to most expensive is always optimal.
 * - (Positional Offset Transformation): Transforming `a[i] = tem + i + 1` correctly bakes the position-dependent pricing into each element's effective cost, converting a complex combinatorial selection problem into a straightforward greedy prefix sum problem.
 * - (Linear Sequential Selection): Once sorted, a single linear sweep subtracting each element from the remaining budget `c` until funds run out guarantees the maximum possible count.
 * * How it runs:
 * First, we safely intercept array size `n` and total budget `c`.
 * We read each base element, transform its cost by adding its 1-based index `i + 1`, and store it in vector `a`.
 * We sort vector `a` in ascending order to prioritize cheaper items.
 * We ignite a greedy linear scan, subtracting each item's cost from `c` and incrementing our purchase count `cnt` as long as sufficient funds remain.
 * Finally, we flush the maximum achievable item count to the output stream with absolute mathematical precision at raw silicon speed!
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
    ll n ,c;
    cin >> n >> c;

    vll a(n);
    ll tem;
    for(int i=0;i<n;i++){
        cin >> tem;
        a[i] = tem + i+1;
    }

    sort(a.begin(),a.end());
    ll cnt=0;

    for(int i=0;i<n;i++){
        if(c-a[i] >= 0){
            cnt++;
            c -= a[i];
        }else{
            break;
        }
    }
    cout << cnt << "\n";
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
