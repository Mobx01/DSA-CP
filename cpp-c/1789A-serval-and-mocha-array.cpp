#include <iostream>
/*
Codeforces PS - 1789A. Serval and Mocha's Array

Mocha likes arrays, and Serval gave her an array consisting of positive integers as a gift.
Mocha thinks that for an array of positive integers a, it is good iff the greatest common divisor of all the elements in a is no more than its length. And for an array of at least 2 positive integers, it is beautiful iff all of its prefixes whose length is no less than 2 are good.

For example:
[3, 6] is not good, because gcd(3, 6) = 3 is greater than its length 2.
[1, 2, 4] is both good and beautiful, because all of its prefixes whose length is no less than 2, which are [1, 2] and [1, 2, 4], are both good.
[3, 6, 1] is good but not beautiful, because [3, 6] is not good.

Now Mocha gives you the gift array a of n positive integers, and she wants to know whether array a could become beautiful by reordering the elements in a. It is allowed to keep the array a unchanged.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1 ≤ t ≤ 500). The description of the test cases follows.
The first line of each test case contains a single integer n (2 ≤ n ≤ 100) — the length of array a.
The second line of each test case contains n integers a1, a2, …, an (1 ≤ a1, a2, …, an ≤ 10^6) — the elements of array a.

Output
For each test case, print Yes if it is possible to reorder the elements in a to make it beautiful, and print No if not.
You can output Yes and No in any case (for example, strings yEs, yes, Yes and YES will be recognized as a positive response).

Time Complexity: O()
Space Complexity: O()
*/


/* Approach - Brute Force / Pairwise GCD Check (Time: O(N^2), Space: O(N))
 * Basically, we use a brute-force nested loop to exhaustively check every single possible pair of numbers in the array to see if any two elements share a Greatest Common Divisor (GCD) of 2 or less!
 * * Observation: 
 * - The problem simply asks for the existence of at least one valid pair.
 * - By using an outer loop for the first element and an inner loop that starts strictly ahead of it (`j = i + 1`), we mathematically guarantee that we evaluate every unique pair exactly once without any redundant reverse checks.
 * - (Optimization Note: Since we only need to find a single valid pair, you could drastically speed up execution by immediately printing "YES" and returning from the function the exact moment the condition is met, completely bypassing the rest of the O(N^2) loop!)
 * * How it runs:
 * First, we read the array size 'n', load all the elements into our vector 'a', and initialize our tracker flag 'fl' to 0.
 * Then, we trigger our double nested loops. The outer loop anchors our first element `a[i]`, and the inner loop iterates through every subsequent element `a[j]`.
 * Next, we compute the GCD of each pair using C++'s built-in `gcd()` function from the `<numeric>` library. If the result evaluates to 2 or less, we successfully trip our 'fl' flag to 1!
 * Finally, after the loops finish sweeping the array, we evaluate 'fl'. If it was tripped to 1, we confidently print "YES". If it remained 0, it means absolutely no valid pair exists, so we print "NO"!
 */

#include <vector>
#include <numeric>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int fl =0;
    for(int i = 0; i < n ; i++) {
        for(int j =i+1;j<n;j++){
            if(gcd(a[i],a[j]) <= 2) fl=1;
        }
    }
    if(fl == 1) cout<<"YES\n";
    else cout << "NO\n";
    
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve() ;  
    }

    return 0;
}
