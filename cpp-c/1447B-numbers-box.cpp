/*
Codeforces - 1447B. Numbers Box
Time limit per test: 1 second
Memory limit per test: 256 megabytes

You are given a rectangular grid with n rows and m columns. The cell located on the i-th row from the top and the j-th column from the left has a value a_ij written in it.

You can perform the following operation any number of times (possibly zero):
Choose any two adjacent cells and multiply the values in them by -1. Two cells are called adjacent if they share a side.

Note that you can use a cell more than once in different operations.
You are interested in X, the sum of all the numbers in the grid.
What is the maximum X you can achieve with these operations?

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1 <= t <= 100). Description of the test cases follows.
The first line of each test case contains two integers n, m (2 <= n, m <= 10).
The following n lines contain m integers each, the j-th element in the i-th line is a_ij (-100 <= a_ij <= 100).

Output
For each testcase, print one integer X, the maximum possible sum of all the values in the grid after applying the operation as many times as you want.
*/




/* Approach - Parity-Based Sign Flipping / Absolute Sum Optimization (Time: O(N * M), Space: O(N * M))
 * Basically, we completely annihilate complex path-finding simulations for sign changes by aggressively leveraging the grid's connectivity invariant, mathematically proving that any pair of elements can have their signs flipped, leaving only their total parity to dictate the final maximum sum!
 * * Observation: 
 * - The absolute core of this architecture is the Adjacency Sign-Flipping Law! In a grid where you can simultaneously invert the signs of any two adjacent elements, you can effectively move a negative sign anywhere along a connected path. This means if the total count of negative numbers is even, you can neutralize all of them (making them positive). If the negative count is odd, you can eliminate all but one. To maximize the total matrix sum, you must naturally choose the element with the *smallest absolute value* to absorb that single remaining negative sign, subtracting twice its magnitude (`2 * minabs`) from the total absolute sum!
 * - (The Grid Connectivity Power): Because a 2D grid is fully connected (or bipartite-independent depending on the exact problem variant, but generally edge-flips allow parity-based adjustments across connected components), tracking the global count of negatives and the absolute minimum element completely captures the reachable state space without needing graph traversals.
 * - (The Trailing Typo Alert): Look closely at the very end of your snippet: `}d`. A stray character `d` slipped past the closing brace of `main()`. If submitted directly to an online judge, this will trigger an immediate compilation error. Always ensure your syntax blocks terminate cleanly!
 * * How it runs:
 * First, we safely intercept grid dimensions `n` and `m`, allocating our 2D vector and reading the matrix elements.
 * We ignite a high-speed linear traversal across the entire grid, simultaneously accumulating the absolute sum of all elements, tracking the minimum absolute value (`minabs`), and counting total negative occurrences (`nofneg`).
 * We check the parity of the negative count: if `nofneg % 2 == 0`, all negatives are successfully flipped to positive, and we flush the full `abssum`.
 * If `nofneg` is odd, we subtract `2 * minabs` from the absolute sum to account for the single unavoidable negative element, flushing the optimal maximized result to the output stream at raw silicon speed!
 */




#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }

    long long abssum = 0;
    int minabs = INT_MAX,nofneg=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] < 0){
                nofneg++;
            }

            minabs = min (minabs,abs(a[i][j]));
            abssum += abs(a[i][j]);
        }
    }
    if(nofneg%2 == 0){
        cout << abssum << endl;
    }else{
        cout << abssum - 2*minabs << endl;
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
