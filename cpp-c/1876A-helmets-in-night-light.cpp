/*
Codeforces - 1876A. Helmets in Night Light
Time limit per test: 1 second
Memory limit per test: 256 megabytes

Pak Chanek is the chief of a village named Khuntien. On one night filled with lights, Pak Chanek has a sudden and important announcement that needs to be notified to all of the n residents in Khuntien.

First, Pak Chanek shares the announcement directly to one or more residents with a cost of p for each person. After that, the residents can share the announcement to other residents using a magical helmet-shaped device. However, there is a cost for using the helmet-shaped device. For each i, if the i-th resident has got the announcement at least once (either directly from Pak Chanek or from another resident), he/she can share the announcement to at most a_i other residents with a cost of b_i for each share.

If Pak Chanek can also control how the residents share the announcement to other residents, what is the minimum cost for Pak Chanek to notify all n residents of Khuntien about the announcement?

Input
Each test contains multiple test cases. The first line contains an integer t (1 <= t <= 10^4) — the number of test cases. The following lines contain the description of each test case.
The first line contains two integers n and p (1 <= n <= 10^5; 1 <= p <= 10^5) — the number of residents and the cost for Pak Chanek to share the announcement directly to one resident.
The second line contains n integers a_1, a_2, a_3, ..., a_n (1 <= a_i <= 10^5) — the maximum number of residents that each resident can share the announcement to.
The third line contains n integers b_1, b_2, b_3, ..., b_n (1 <= b_i <= 10^5) — the cost for each resident to share the announcement to one other resident.
It is guaranteed that the sum of n over all test cases does not exceed 10^5.

Output
For each test case, output a line containing an integer representing the minimum cost to notify all n residents of Khuntien about the announcement.
*/


/* Approach - Greedy Fractional Knapsack / Network Cost Collapse (Time: O(N log N), Space: O(N))
 * Basically, we completely annihilate the infinite permutation tree of sharing combinations by aggressively deploying a greedy peer-to-peer network, violently prioritizing the absolute cheapest distributors to mathematically minimize the global transmission cost!
 * * Observation: 
 * - The absolute core of this architecture is the Fractional Knapsack strategy! Since you only need to infect exactly `N` nodes, you must ruthlessly exploit the users who have the absolute lowest sharing cost `b[i]` before their capacity runs dry!
 * - (The Absolute Game-Breaker / The Server Shield): `if(shar_cost >= p) break;`. This is a flawless structural radar! If the peer-to-peer sharing cost mathematically equals or exceeds the direct baseline cost `p`, you aggressively sever the peer network! There is zero reason to pay a peer when you can just violently bypass them and buy directly from the main server!
 * - (The Initial Seed Masterstroke): `long long mincost = p; long long shared = 1;`. You brilliantly recognized that the peer network mathematically CANNOT start itself! You forcefully pay the baseline server cost `p` exactly once to infect the "Patient Zero" node, flawlessly igniting the chain reaction!
 * - (The Fatal Cache-Miss Trap): Your logic is mathematically pristine, but your memory architecture is a catastrophic CPU bottleneck! `vector<vector<long long>> res(n, vector<long long>(2))` dynamically allocates `N` completely separate arrays on the heap! This violently fragments your memory and completely shreds the CPU cache! You MUST instantly upgrade this to `vector<pair<long long, long long>>` (storing `{cost, capacity}`). This locks the entire dataset into a single, perfectly contiguous block of memory, allowing the hardware prefetcher to run at absolute peak theoretical speed!
 * - (Optimization Alert / The Sort Annihilation): If you upgrade to `vector<pair<long long, long long>>` and store it as `{cost, capacity}`, you can completely destroy your custom lambda function! C++ `std::sort` natively sorts pairs by the first element ascending, completely bypassing the lambda overhead! (You can simply negate the capacity during insertion if you want descending capacity on cost-ties, but honestly, since you cap at `N` anyway, the secondary capacity sort barely matters if costs are equal!)
 * * How it runs:
 * First, we safely intercept the dataset and zip the disjoint arrays into a unified 2D coordinate system.
 * We instantly ignite an aggressive O(N log N) `sort`, structurally forcing the entire network timeline into a strict ascending order based purely on the cheapest peer-to-peer transmission cost!
 * We lock in our Initial Seed, forcefully taking `1` node and permanently burning `p` cost.
 * We trigger a high-speed linear sweep! For every potential distributor, if their cost breaches the baseline `p`, we violently abort the loop!
 * Otherwise, we greedily consume their exact transmission capacity. If they can infect the entire remaining network (`shared + can_sh > n`), we ruthlessly cap their spread, calculate the exact required cost, and instantly break the timeline!
 * Finally, if the peer network runs completely dry before everyone is infected, our absolute final mathematical safety net `mincost += (n - shared) * p` violently forces the remaining nodes to buy direct, perfectly crushing the simulation!
 */


#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n , p;
    cin >> n >> p;
    vector<vector<long long>> res(n,vector<long long>(2));
    for(int i=0;i<n;i++){
        cin >> res[i][0];
    }
    for(int i=0;i<n;i++){
        cin >> res[i][1];
    }

    sort(res.begin(), res.end(), [](const vector<long long>& a, const vector<long long>& b){
    if (a[1] != b[1]) {
        return a[1] < b[1]; 
    }
    return a[0] > b[0]; 
});
    long long mincost = p;
    long long shared = 1;

    for(auto it : res){
        long long can_sh = it[0];
        long long shar_cost = it[1];
        if(shar_cost >= p){
            break;
        }

        if(shared + can_sh > n){
            mincost += (n-shared)*shar_cost;
            shared = n;
            break;
        }else{
            mincost += can_sh*shar_cost;
            shared += can_sh;
        }
    }
    mincost += (n-shared)*p;
    cout << mincost << endl;
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
