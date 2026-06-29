/*codeforcea ps - 1896A. Jagged Swaps
You are given a permutation † a of size n. You can do the following operation:
Select an index i from 2 to n-1 such that a_{i-1} < a_i and a_i > a_{i+1}. Swap a_i and a_{i+1}.
Determine whether it is possible to sort the permutation after a finite number of operations.
† A permutation is an array consisting of n distinct integers from 1 to n in arbitrary order. For example, [2,3,1,5,4] is a permutation, but [1,2,2] is not a permutation (2 appears twice in the array) and [1,3,4] is also not a permutation (n=3 but there is 4 in the array).
Input
Each test contains multiple test cases. The first line contains the number of test cases t (1 ≤ t ≤ 5000). Description of the test cases follows.
The first line of each test case contains a single integer n (3 ≤ n ≤ 10) — the size of the permutation.
The second line of each test case contains n integers a_1, a_2, …, a_n (1 ≤ a_i ≤ n) — the elements of permutation a.
Output
For each test case, print "YES" if it is possible to sort the permutation, and "NO" otherwise.
You may print each letter in any case (for example, "YES", "Yes", "yes", "yEs" will all be recognized as positive answer).
*/


/* Approach - Logic & Observation
 * Basically, the entire solution boils down to checking if the absolute smallest number in the array is currently sitting at the very first position.
 * Observation: 
 * - The core mechanics of the problem simplify to a single strict requirement: the minimum element must be at index 0. 
 * - If the absolute smallest element is already at the front of the array, we can achieve our goal (output YES). If it is located anywhere else, it's impossible to satisfy the conditions, regardless of what we do (output NO).
 *
 * How it runs:
 * First, we read all the numbers into our array.
 * Then, we use the built-in '*min_element' function to instantly scan the entire array and find the absolute minimum value present.
 * Finally, we simply compare this minimum value to 'nums[0]' (the first element). If they are exactly the same, we print "YES". If they don't match, we print "NO"!
 */


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    int min_val = *min_element(nums.begin(), nums.end());
    
    if(min_val == nums[0]) {
        cout << "YES\n"; 
    } else {
        cout << "NO\n";
    }
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
