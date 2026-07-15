/*Codeforces PS -1788A. One and Two

You are given a sequence a1, a2, …, an. Each element of a is 1 or 2.
Find out if an integer k exists so that the following conditions are met.
1 ≤ k ≤ n−1, and
a1 ⋅ a2 ⋅ … ⋅ ak = ak+1 ⋅ ak+2 ⋅ … ⋅ an.
If there exist multiple k that satisfy the given condition, print the smallest.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1 ≤ t ≤ 100). Description of the test cases follows.
The first line of each test case contains one integer n (2 ≤ n ≤ 1000).
The second line of each test case contains n integers a1, a2, …, an (1 ≤ ai ≤ 2).

Output
For each test case, if there is no such k, print -1.
Otherwise, print the smallest possible k.

Time Complexity: O()
Space Complexity: O()
*/

/* Approach - Prefix Counting & Math (Time: O(N), Space: O(N))
 * Basically, we find a valid split point by purely counting the number of '2's, because the product of any subarray consisting only of 1s and 2s is entirely determined by how many 2s it contains!
 * * Observation: 
 * - Multiplying a number by 1 does absolutely nothing. Therefore, for the left subarray product to perfectly equal the right subarray product, both sides MUST contain the exact same number of 2s.
 * - This completely removes the need to actually multiply anything (which would cause massive integer overflow). We just turn it into a simple counting problem!
 * - If the total number of 2s in the entire array is an odd number, it is mathematically impossible to divide them equally, and our logic will naturally return -1.
 * - (Note on Space: You are currently storing the array in a vector taking O(N) space. You could technically achieve O(1) space if you read the inputs twice or tracked things slightly differently, but O(N) is standard and perfectly fine here!)
 * * How it runs:
 * First, we read the array and do a full sweep to count the absolute `total_twos` present in the sequence.
 * Then, we sweep through the array a second time (stopping at `n - 1` to ensure the right side always has at least one element). As we step through, we keep a running tally of `left_twos`.
 * Next, at every single index, we check if our `left_twos` is exactly equal to the remaining 2s on the right (`total_twos - left_twos`). If it is, we found our perfect split! We return the 1-based index `i + 1`.
 * Finally, if the loop finishes and no perfect split was ever found, we return -1.
 */

#include <iostream>
#include <vector>

using namespace std;

int solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    int total_twos = 0;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 2) {//get total number of 2s
            total_twos++;
        }
    }
    
    int left_twos = 0;
    for(int i = 0; i < n - 1; i++) {
        if (a[i] == 2) {
            left_twos++;
        }
        
        // The remaining 2s on the right is (total_twos - left_twos)
        if (left_twos == total_twos - left_twos) {
            return i + 1; // k is 1 indexed.
        }
    }
    
    return -1;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
       cout << solve() << "\n";   
    }

    return 0;
}
