/*Codeforces PS - 1829B. Blank Space

You are given a binary array a of n elements, a binary array is an array consisting only of 0s and 1s.
A blank space is a segment of consecutive elements consisting of only 0s.
Your task is to find the length of the longest blank space.

Input
The first line contains a single integer t (1 ≤ t ≤ 1000) — the number of test cases.
The first line of each test case contains a single integer n (1 ≤ n ≤ 100) — the length of the array.
The second line of each test case contains n space-separated integers ai (0 ≤ ai ≤ 1) — the elements of the array.

Output
For each test case, output a single integer — the length of the longest blank space.
*/

/* Approach - Array Traversal & Streak Counting (Time: O(N), Space: O(N))
 * Basically, we sweep through the array to find the length of the longest contiguous subarray (or "streak") of elements that are strictly NOT equal to 1.
 * * Observation: 
 * - The number 1 acts as a strict barrier. Every time we encounter it, our current valid streak is instantly broken, forcing us to start counting from zero again.
 * - Any other number is perfectly valid and simply adds to our ongoing streak. 
 * - (Note on Space: You are currently storing the entire array in memory using a vector, making it O(N) space. Since you only need to look at elements one by one to count the streak, you could actually optimize this to O(1) space by just reading the inputs into a single temporary variable on the fly and dropping the vector entirely!)
 * * How it runs:
 * First, we read the array size 'n', load the elements into vector 'a', and initialize our current streak tracker 'cons' and our all-time record tracker 'max_cons' both to 0.
 * Then, we loop through the array sequentially. If the current number 'a[i]' is exactly 1, the streak is completely dead, so we immediately reset 'cons' to 0.
 * Finally, if the number is NOT 1, it's a valid element! We increment our 'cons' streak by 1 and immediately update 'max_cons' using the `max()` function to ensure we lock in the highest streak achieved so far. Once the loop finishes, we print 'max_cons'!
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
    int max_cons = 0 ,cons=0;
    for(int i =0;i<n;i++){
        if(a[i] == 1)cons=0;
        else{
            cons++;
            max_cons = max(max_cons,cons);
        }
    }
    cout<< max_cons << "\n";
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
