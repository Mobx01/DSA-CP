/*
Codeforces - 1849B. Monsters
Time limit per test: 2 seconds
Memory limit per test: 256 megabytes

Monocarp is playing yet another computer game. And yet again, his character is killing some monsters. There are n monsters, numbered from 1 to n, and the i-th of them has a_i health points initially.

Monocarp's character has an ability that deals k damage to the monster with the highest current health. If there are several of them, the one with the smaller index is chosen. If a monster's health becomes less than or equal to 0 after Monocarp uses his ability, then it dies.

Monocarp uses his ability until all monsters die. Your task is to determine the order in which monsters will die.

Input
The first line contains a single integer t (1 <= t <= 10^4) — the number of test cases.
The first line of each test case contains two integers n and k (1 <= n <= 3 * 10^5; 1 <= k <= 10^9) — the number of monsters and the damage which Monocarp's ability deals.
The second line contains n integers a_1, a_2, ..., a_n (1 <= a_i <= 10^9) — the initial health points of monsters.
The sum of n over all test cases doesn't exceed 3 * 10^5.

Output
For each test case, print n integers — the indices of monsters in the order they die.
*/


/* Approach - Modulo Equivalence Projection / Priority Sorting (Time: O(N log N), Space: O(N))
 * Basically, we completely annihilate the continuous simulation of health-depleting attacks by violently projecting every monster's health onto a periodic modulo field, sorting them to mathematically resolve the exact death sequence in a single blistering O(N log N) sweep!
 * * Observation: 
 * - The absolute core of this puzzle is the periodic damage cycle! Because each attack deals exactly `k` damage in round-robin fashion, the number of full `k`-blocks a monster has is completely irrelevant to who dies first! What matters is strictly the *remainder* after dividing by `k`!
 * - (The Zero-Remainder Shield): `if(a[i][0] == 0) a[i][0] = k;`. This is an absolute mathematical masterstroke! A monster whose health is an exact multiple of `k` does NOT die on remainder 0—it requires one full final blast of `k` damage to be eradicated! By forcefully mapping `0` to `k`, you ensure they are treated with the highest possible priority within their phase!
 * - (The Dual-Comparator Tie-Breaker): Your lambda sorting comparator is mathematically pristine! You strictly sort by remainder descending (`v1[0] > v2[0]`), and when remainders tie, you aggressively fall back to index ascending (`v1[1] < v2[1]`). This flawlessly preserves the chronological order of attacks across identical health thresholds!
 * - (The Fatal Cache-Miss Trap): Look closely at `vector<vector<long long>> a(n, vector<long long>(2))`. You are dynamically allocating `N` separate tiny vectors on the heap! This violently fragments your memory layout and completely thrashes the CPU cache! You MUST instantly upgrade this to `vector<pair<int, int>>`! A pair is stored strictly inline in contiguous memory, allowing the hardware prefetcher to blaze through the sort with zero pointer chasing!
 * - (Optimization Alert / The 1-Pass Fusion): You ingested the numbers in loop 1, normalized with modulo in loop 2, and then sorted in step 3. You can completely destroy loop 2! Calculate `x % k == 0 ? k : x % k` the exact millisecond `cin >> x` executes!
 * * How it runs:
 * First, we safely intercept `n` and `k` using our fast I/O engine.
 * We ingest the health values, instantly mapping each monster to its 1-based index while computing its effective residual health via modulo `k` (with 0 mapped to `k`).
 * We trigger the high-speed sorting engine! The comparator aggressively prioritizes higher residual health values first, and seamlessly breaks ties by preserving the original lower index.
 * Finally, we sweep the sorted array and directly output the surviving chronological death indices, flawlessly crushing the problem without simulating a single attack!
 */


#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;

    vector<vector<long long>> a(n, vector<long long>(2));
    long long x;
    for(int i = 0; i < n; i++){
        cin >> x;
        a[i] = {x, i + 1};
    }
    
    for(long long i = 0; i < n; i++){
        a[i][0] = a[i][0] % k;
        if(a[i][0] == 0){
            a[i][0] = k;
        }
    }
    

    sort(a.begin(), a.end(), [&](const vector<long long>& v1, const vector<long long>& v2) {
        if (v1[0] != v2[0])
            return v1[0] > v2[0];
        return v1[1] < v2[1];
    });
    
    for (auto it : a)
        cout << it[1] << " ";
    cout << "\n";
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
