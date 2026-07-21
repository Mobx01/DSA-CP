/*Codeforces PS - 1783A. Make it Beautiful

An array a is called ugly if it contains at least one element which is equal to the sum of all elements before it. If the array is not ugly, it is beautiful.

For example:
the array [6, 3, 9, 6] is ugly: the element 9 is equal to 6 + 3;
the array [5, 5, 7] is ugly: the element 5 (the second one) is equal to 5;
the array [8, 4, 10, 14] is beautiful: 8 ≠ 0, 4 ≠ 8, 10 ≠ 8 + 4, 14 ≠ 8 + 4 + 10, so there is no element which is equal to the sum of all elements before it.

You are given an array a such that 1 ≤ a1 ≤ a2 ≤ ⋯ ≤ an ≤ 100. You have to reorder the elements of a in such a way that the resulting array is beautiful. Note that you are not allowed to insert new elements or erase existing ones, you can only change the order of elements of a. You are allowed to keep the array a unchanged, if it is beautiful.

Input
The first line contains one integer t (1 ≤ t ≤ 2000) — the number of test cases.
Each test case consists of two lines. The first line contains one integer n (2 ≤ n ≤ 50). The second line contains n integers a1, a2, …, an (1 ≤ a1 ≤ a2 ≤ ⋯ ≤ an ≤ 100).

Output
For each test case, print the answer as follows:
if it is impossible to reorder the elements of a in such a way that it becomes beautiful, print NO;
otherwise, in the first line, print YES. In the second line, print n integers — any beautiful array which can be obtained from a by reordering its elements. If there are multiple such arrays, print any of them.
*/


/* Approach - Sorting & Targeted Swapping (Time: O(N log N), Space: O(N))
 * Basically, we sort the array in descending order to make the prefix sum grow as fast as possible, and use a clever single swap to completely prevent the only possible failure point!
 * * Observation: 
 * - If every single element in the array is identical (easily checked by seeing if the absolute largest element equals the absolute smallest: `a[0] == a[n - 1]`), it is mathematically impossible to avoid the prefix sum eventually matching an element.
 * - By sorting in strict descending order, the prefix sum accumulates the largest numbers first. This mathematically guarantees that for all elements from index 2 onwards, the running prefix sum will always be strictly greater than the current element itself!
 * - The ONLY potential risk in a descending array is exactly at index 1, where `a[1]` might happen to equal `a[0]` (if the two largest numbers are duplicates). To brilliantly bypass this, we instantly swap `a[1]` with the absolute smallest element in the array, `a[n - 1]`. Since we already know the array isn't fully uniform, `a[0]` can never equal this newly placed smallest element!
 * * How it runs:
 * First, we read the array size 'n', load all the elements into our vector 'a', and immediately sort it in descending order using C++'s built-in `greater<>()` comparator.
 * Then, we evaluate our impossible base case. If `a[0] == a[n - 1]`, all numbers in the array are exact duplicates, making it permanently ugly, so we print "NO".
 * Next, if the array is valid, we confidently print "YES" and execute our strategic `swap(a[1], a[n - 1])` to safeguard the second position from matching the first.
 * Finally, we loop through and print our completely rearranged, perfectly beautiful array!
 */

// beautiful if prefixsum != element
//sort(descending) and then check for every element if ugly then cant be made beaultiful
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Sort in descending order
    sort(a.begin(), a.end(), greater<>());
    
    // If the largest and smallest elements are the same, all elements are identical.
    if (a[0] == a[n - 1]) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        // Swap the second element with the smallest element
        swap(a[1], a[n - 1]);
        
        for(int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
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
