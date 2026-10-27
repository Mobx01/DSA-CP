/*
Codeforces - 1511C. Yet Another Card Deck
Time limit per test: 2 seconds
Memory limit per test: 256 megabytes

You have a card deck of n cards, numbered from top to bottom, i. e. the top card has index 1 and bottom card — index n. Each card has its color: the i-th card has color a_i.

You should process q queries. The j-th query is described by integer t_j. For each query you should:
- find the highest card in the deck with color t_j, i. e. the card with minimum index;
- print the position of the card you found;
- take the card and place it on top of the deck.

Input
The first line contains two integers n and q (2 <= n <= 3 * 10^5; 1 <= q <= 3 * 10^5) — the number of cards in the deck and the number of queries.
The second line contains n integers a_1, a_2, ..., a_n (1 <= a_i <= 50) — the colors of cards.
The third line contains q integers t_1, t_2, ..., t_q (1 <= t_j <= 50) — the query colors. It's guaranteed that queries ask only colors that are present in the deck.

Output
Print q integers — the answers for each query.
*/





/* Approach - Bounded Value Front-Shifting Simulation / Index Tracking with Range Updates (Time: O(N + Q * K), Space: O(K))
 * Basically, we completely annihilate brute-force list rotations by aggressively leveraging the small value constraint ($A_i \le 50$) to maintain a fixed-size index tracking array, updating preceding elements in constant-factor time per query!
 * * Observation: 
 * - The absolute core of this architecture is the Small-Domain Position Invariant! Because element values are bounded (up to 50), we can maintain an `in` lookup table storing the 1-based index of each distinct value. When a query accesses an element `qu`, any element whose current position was strictly ahead of `qu` (`in[i] < in[qu]`) shifts back by one position (`in[i]++`), and `qu` moves directly to the front (`in[qu] = 1`).
 * - (Efficiency via Bounded Alphabet): Iterating 51 times per query (`for(int i=0; i<51; i++)`) takes negligible time ($O(50 \cdot Q)$ total operations), making this approach exceptionally optimal for small-domain frequency or positioning problems.
 * - (Optimal Auxiliary Memory): Using a fixed-size vector of size 51 keeps auxiliary memory consumption strictly at $O(1)$ constant space.
 * * How it runs:
 * First, we read array size `n`, query count `q`, and populate array `a` and queries `t`.
 * We initialize our position lookup table `in` of size 51 with `-1` and record the first 1-based occurrence of each distinct value from `a`.
 * For each query `qu`, we output its current position, increment the positions of all elements that were ahead of it, and reposition `qu` to index `1`.
 * Finally, we flush the results to the output stream with absolute mathematical precision at raw silicon speed!
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
    ll n ,q;
    cin >> n >> q;

    vi a(n) , t(q);
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    for(int i =0;i<q;i++){
        cin >> t[i];
    }

    vll in(51,-1);
    for(int i=0;i<n;i++){
        if(in[a[i]] == -1){
            in[a[i]] = i+1;
        }
    }

    for(ll qu : t){
        cout << in[qu] << " ";
        for(int i=0;i<51;i++){
            if(in[i] != -1 && in[i] < in[qu]){
                in[i]++;
            }
        }
        in[qu] = 1;
    }
}

int main() {
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
