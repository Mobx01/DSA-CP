/*
Codeforces - 1842B. Tenzing and Books
Time limit per test: 1 second
Memory limit per test: 256 megabytes

Tenzing received 3n books from his fans. The books are arranged in 3 stacks with n books in each stack. Each book has a non-negative integer difficulty rating.
Tenzing wants to read some (possibly zero) books. At first, his knowledge is 0.

To read the books, Tenzing will choose a non-empty stack, read the book on the top of the stack, and then discard the book. If Tenzing's knowledge is currently u, then his knowledge will become u | v after reading a book with difficulty rating v. Here | denotes the bitwise OR operation. Note that Tenzing can stop reading books whenever he wants.

Tenzing's favourite number is x. Can you help Tenzing check if it is possible for his knowledge to become x?

Input
Each test contains multiple test cases. The first line of input contains a single integer t (1 <= t <= 10^4) — the number of test cases. The description of test cases follows.
The first line of each test case contains two integers n and x (1 <= n <= 10^5, 0 <= x <= 10^9) — the number of books in each stack and Tenzing's favourite number.
The second line of each test case contains n integers a_1, a_2, ..., a_n (0 <= a_i <= 10^9) — the difficulty rating of the books in the first stack, from top to bottom.
The third line of each test case contains n integers b_1, b_2, ..., b_n (0 <= b_i <= 10^9) — the difficulty rating of the books in the second stack, from top to bottom.
The fourth line of each test case contains n integers c_1, c_2, ..., c_n (0 <= c_i <= 10^9) — the difficulty rating of the books in the third stack, from top to bottom.
It is guaranteed that the sum of n does not exceed 10^5.

Output
For each test case, output "Yes" (without quotes) if Tenzing can make his knowledge equal to x, and "No" (without quotes) otherwise.
You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.
*/



/* Approach - Bitwise Submask Validation with Cumulative OR Accumulation (Time: O(N), Space: O(N))
 * Basically, we completely annihilate brute-force subset combinations by aggressively filtering submask elements and accumulating valid bitwise OR contributions in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Bitwise Submask Invariant! To form a target OR sum `x`, any selected element `val` must satisfy `(val | x) == x` because bitwise OR operations can only turn bits on, never clear them. 
 * - (Logic Flaw / Premature Break): Notice that your loops use `break` when `(a[i] | x) != x`. If the problem allows picking *any* subset of elements across the arrays, breaking early causes you to skip valid elements that appear later in the array. Since bitwise OR is commutative and associative, you should instead use `continue` (or skip invalid elements) to evaluate *all* elements in the arrays rather than terminating on the first invalid match.
 * - (Linear Time Efficiency): Inspecting each element across the three arrays runs in strict $O(N)$ time with $O(N)$ auxiliary space for vector storage.
 * * How it runs:
 * First, we read test parameters `n` and `x`, along with vectors `a`, `b`, and `c`.
 * We iterate through each array, checking if each element is a valid submask of `x`. If valid, we accumulate it into `curor`; otherwise, the current logic breaks early.
 * Finally, we verify whether `curor == x` and flush `"YES"` or `"NO"` to the output stream with absolute mathematical precision at raw silicon speed!
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
    ll n,x;
    cin >> n >>x;

    vll a(n),b(n),c(n);

    for(ll i =0;i<n;i++){
        cin >> a[i];
    }
    for(ll i =0;i<n;i++){
        cin >> b[i];
    }
    for(ll i =0;i<n;i++){
        cin >> c[i];
    }

    ll curor = 0;

    for(ll i=0;i<n;i++){
        if((a[i] | x ) == x){
            curor |= a[i];
        }else break;
    }
    for(ll i=0;i<n;i++){
        if((b[i] | x ) == x){
            curor |= b[i];
        }else break;
    }
    for(ll i=0;i<n;i++){
        if((c[i] | x ) == x){
            curor |= c[i];
        }else break;
    }

    if(curor == x){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
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
