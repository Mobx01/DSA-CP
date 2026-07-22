/*Codeforces PS - 1777A. Everybody Likes Good Arrays!
An array a is good if for all pairs of adjacent elements, ai and ai+1 (1 ≤ i < n) are of different parity. Note that an array of size 1 is trivially good.
You are given an array of size n.
In one operation you can select any pair of adjacent elements in which both elements are of the same parity, delete them, and insert their product in the same position.
Find the minimum number of operations to form a good array.
Input
Each test contains multiple test cases. The first line contains the number of test cases t (1 ≤ t ≤ 500). The description of the test cases follows.
The first line of each test case contains an integer n (1 ≤ n ≤ 100).
The second line of each test case contains n integers a1, a2, …, an (1 ≤ ai ≤ 10^9).
Output
For each test case print an integer, the minimum number of operations required to form a good array.
*/


/* Approach - Greedy Parity Checking / Array Simulation (Time: O(N), Space: O(N))
 * Basically, we greedily sweep through the array and count how many times we are forced to merge adjacent elements of the same parity, using a clever dummy value to simulate the mathematical outcome!
 * * Observation: 
 * - The goal is to make all adjacent elements have strictly alternating parities (even-odd-even-odd).
 * - If two adjacent numbers share the exact same parity, they violate the rule, meaning we absolutely MUST perform a merge operation.
 * - Mathematically, the product of two even numbers is always even, and the product of two odd numbers is always odd. Therefore, merging two elements of the same parity NEVER actually changes the parity of the resulting combined block!
 * - Instead of doing the actual multiplication (which could cause massive integer overflow), we brilliantly bypass the math by just overwriting the rightmost element with a safe dummy value ('2' for even, '1' for odd). This perfectly carries the correct parity forward for the next comparison!
 * * How it runs:
 * First, we read the array size 'n', load our elements into vector 'a', and initialize our operation counter 'opr' to 0.
 * Then, we sweep through the array from index 0 up to 'n - 2'. At each step, we compare the current element with the next one using `abs(a[i]) % 2 == abs(a[i+1]) % 2`. (Using `abs()` is a great trick here because C++ modulo on negative numbers can return negative results!).
 * Next, if the parities match, we trigger our merge. We increment 'opr', and instantly overwrite `a[i+1]` with either 2 or 1 to preserve the parity state for the next check.
 * Finally, after safely sweeping the entire array, we print out the total accumulated 'opr' count!
 */


#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int opr =0;
    for(int i =0;i<n-1;i++){
        if(abs(a[i])%2 == abs(a[i+1])%2){
            opr++;
            a[i+1] = a[i] %2 == 0 ? 2 : 1;// product of even is even and odds are odd
        }
    }
    cout<< opr <<"\n";
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
