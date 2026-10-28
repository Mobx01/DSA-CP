/*
Codeforces - 1914D. Three Activities
Time limit per test: 2 seconds
Memory limit per test: 256 megabytes

Winter holidays are coming up. They are going to last for n days.
During the holidays, Monocarp wants to try all of these activities exactly once with his friends:
- go skiing;
- watch a movie in a cinema;
- play board games.

Monocarp knows that, on the i-th day, exactly a_i friends will join him for skiing, b_i friends will join him for a movie and c_i friends will join him for board games.
Monocarp also knows that he can't try more than one activity in a single day.
Thus, he asks you to help him choose three distinct days x, y, z in such a way that the total number of friends to join him for the activities (a_x + b_y + c_z) is maximized.

Input
The first line contains a single integer t (1 <= t <= 10^4) — the number of testcases.
The first line of each testcase contains a single integer n (3 <= n <= 10^5) — the duration of the winter holidays in days.
The second line contains n integers a_1, a_2, ..., a_n (1 <= a_i <= 10^8) — the number of friends that will join Monocarp for skiing on the i-th day.
The third line contains n integers b_1, b_2, ..., b_n (1 <= b_i <= 10^8) — the number of friends that will join Monocarp for a movie on the i-th day.
The fourth line contains n integers c_1, c_2, ..., c_n (1 <= c_i <= 10^8) — the number of friends that will join Monocarp for board games on the i-th day.
The sum of n over all testcases doesn't exceed 10^5.

Output
For each testcase, print a single integer — the maximum total number of friends that can join Monocarp for the activities on three distinct days.
*/




/* Approach - Top-3 Candidates Brute-Force Intersection / Maximum Triplet Sum with Distinct Indices (Time: O(N log N), Space: O(N))
 * Basically, we completely annihilate brute-force $O(N^3)$ global search by aggressively sorting each array in descending order and checking combinations among the top 3 elements in pristine $O(N \log N)$ time!
 * * Observation: 
 * - The absolute core of this architecture is the Top-K Candidate Invariant (common in competitive programming problems requiring a sum of 3 elements from 3 arrays with distinct original indices)! Since we want to maximize the sum `a[i] + b[j] + c[k]` such that no two elements share the same original index, the optimal choice for each array must come from among its absolute largest values. Because we need at most 3 distinct indices, checking all triplets within the top 3 elements of each sorted array (`min(n, 3)`) is both necessary and sufficient to guarantee finding a valid combination with distinct indices.
 * - (Index Tracking via Pairs): Storing original indices using `vector<pll>` (`{value, original_index}`) before sorting descending allows us to easily enforce the distinct-index constraint (`a[i].second != b[j].second && ...`).
 * - (Optimal Complexity): Sorting the three arrays takes $O(N \log N)$ time, and the nested loops run in a bounded $O(3^3) = O(1)$ constant number of operations, keeping overall time complexity optimal at $O(N \log N)$ and auxiliary space at $O(N)$.
 * * How it runs:
 * First, we read test parameter `n` and populate vectors `a`, `b`, and `c` as pairs storing the element value and its original 0-based index.
 * We sort each vector in descending order (`rbegin()` to `rend()`).
 * We ignite a triple nested loop iterating through the top 3 elements (`min(n, (ll)3)`) of each sorted array, verifying that all three chosen elements have mutually distinct original indices.
 * We track and update `maxsum` with the maximum valid sum found.
 * Finally, we flush `maxsum` to the output stream with absolute mathematical precision at raw silicon speed!
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
    ll n;
    cin >> n;

    vector<pll> a(n),b(n),c(n);
    for(ll i =0;i<n;i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    for(ll i =0;i<n;i++){
        cin >> b[i].first;
        b[i].second = i;
    }
    for(ll i =0;i<n;i++){
        cin >> c[i].first;
        c[i].second = i;
    }

    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
    sort(c.rbegin(),c.rend());

    ll maxsum = 0;

    for(int i=0;i< min(n,(ll)3);i++){
        for(int j=0;j< min(n,(ll)3);j++){
            for(int k=0;k<min(n,(ll)3);k++){
                if(a[i].second != b[j].second && 
                    b[j].second != c[k].second && 
                    a[i].second != c[k].second){
                        ll cursum = (ll)(a[i].first + b[j].first + c[k].first);
                        maxsum = max(cursum,maxsum);
                    }
            }
        }
    }

    cout << maxsum << endl;
    
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
