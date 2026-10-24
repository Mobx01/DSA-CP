/*
Codeforces - 1669F. Eating Candies
Time limit per test: 1 second
Memory limit per test: 256 megabytes

There are n candies put from left to right on a table. The candies are numbered from left to right. The i-th candy has weight w_i. Alice and Bob eat candies.
Alice can eat any number of candies from the left (she can't skip candies, she eats them in a row).
Bob can eat any number of candies from the right (he can't skip candies, he eats them in a row).
Of course, if Alice ate a candy, Bob can't eat it (and vice versa).

They want to be fair. Their goal is to eat the same total weight of candies. What is the most number of candies they can eat in total?

Input
The first line contains an integer t (1 <= t <= 10^4) — the number of test cases.
The first line of each test case contains an integer n (1 <= n <= 2 * 10^5) — the number of candies on the table.
The second line of each test case contains n integers w_1, w_2, ..., w_n (1 <= w_i <= 10^4) — the weights of candies from left to right.
It is guaranteed that the sum of n over all test cases does not exceed 2 * 10^5.

Output
For each test case, print a single integer — the maximum number of candies Alice and Bob can eat in total while satisfying the condition.
*/




/* Approach - Converging Two-Pointer Sum Balancing / Greedy Segment Equalization (Time: O(N), Space: O(N))
 * Basically, we completely annihilate brute-force subset checks by aggressively employing converging two-pointer sum accumulators to balance prefix and suffix weights in pristine linear time and constant auxiliary space!
 * * Observation: 
 * - The absolute core of this architecture is the Two-Pointer Balance Invariant (commonly found in competitive programming array-balancing problems)! By maintaining running sums from both extremes (`ls` and `rs`), we can greedily equalize the weight of the left and right segments. Whenever `ls == rs`, we capture the total count of elements consumed from both ends (`(l + 1) + (n - r)`) as a valid segment configuration.
 * - (Pointer Convergence Strategy): Incrementing `l` when `ls < rs` or decrementing `r` when `ls > rs` ensures that the smaller sum catches up to the larger side, exploring all balanced partition boundaries efficiently in a single linear pass.
 * - (Linear Time Efficiency): Each element is visited at most once as `l` and `r` converge towards the center, guaranteeing strict $O(N)$ time complexity.
 * * How it runs:
 * First, we read vector `a` of size `n` and initialize our pointers `l = 0` and `r = n - 1` along with initial sum registers `ls = a[0]` and `rs = a[n - 1]`.
 * We ignite a converging `while(l < r)` loop: checking if `ls == rs` to update our candidate count `c` and advance both pointers; otherwise, shrinking the side with the smaller sum to rebalance.
 * Finally, we flush the resulting count `c` to the output stream with absolute mathematical precision at raw silicon speed!
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
    vll a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    ll l = 0, r = n - 1, c = 0;
    ll ls = a[l], rs = a[r];
    
    while(l < r){
        if(ls == rs){
            // (left side + right side)
            c = (l + 1) + (n - r);
            
            l++;
            r--;
            if(l < r) {
                ls += a[l];
                rs += a[r];
            }
        } else if(ls > rs){
            r--;
            if(l < r) {
                rs += a[r];
            }
        } else {
            l++;
            if(l < r) {
                ls += a[l];
            }
        }
    }
    cout << c << "\n";
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
