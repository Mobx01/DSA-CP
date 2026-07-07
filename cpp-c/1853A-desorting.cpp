/*Codeforces PS - 1853A. Desorting

Call an array a of length n sorted if a1 ≤ a2 ≤ … ≤ an−1 ≤ an.
Ntarsis has an array a of length n. He is allowed to perform one type of operation on it (zero or more times):
Choose an index i (1 ≤ i ≤ n−1).
Add 1 to a1, a2, …, ai.
Subtract 1 from ai+1, ai+2, …, an.
The values of a can be negative after an operation.

Determine the minimum operations needed to make a not sorted.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1 ≤ t ≤ 100). The description of the test cases follows.
The first line of each test case contains a single integer n (2 ≤ n ≤ 500) — the length of the array a.
The next line contains n integers a1, a2, …, an (1 ≤ ai ≤ 10^9) — the values of array a.
It is guaranteed that the sum of n across all test cases does not exceed 500.

Output
Output the minimum number of operations needed to make the array not sorted.
*/


/* Approach - Greedy & Math (Minimum Differences) (Time: O(N), Space: O(N))
 * Basically, we find the minimum operations required to make the array "unsorted" by targeting the adjacent pair of elements that are already closest to being out of order, and calculating how many operations it takes to push their difference below zero.
 * * Observation: 
 * - An array is considered "unsorted" the exact moment any adjacent pair satisfies nums[i-1] > nums[i] (meaning their difference is less than 0).
 * - The allowed operation (adding 1 to a prefix and subtracting 1 from the remaining suffix) effectively decreases the difference between the split boundary elements by exactly 2.
 * - To minimize our total operations, we should always target the adjacent pair that has the absolute smallest difference (`mindiff`).
 * - If `mindiff` is already less than 0, the array is already unsorted, so it takes 0 operations! Otherwise, since every operation reduces the gap by 2, it will mathematically take floor(mindiff / 2) + 1 operations to force the difference into the negatives.
 * * How it runs:
 * First, we read the array and loop through it once to find the absolute smallest difference between any two adjacent elements, saving it in `mindiff`.
 * Then, we check our base case: if `mindiff < 0`, the array is already unsorted, so we immediately return 0.
 * Finally, we apply our math: if the difference is even, it takes exactly `mindiff / 2 + 1` operations to cross zero. If it's odd, integer division handles it cleanly as `(mindiff + 1) / 2` operations!
 */


// mindifference between n+1 , n
// if difference  < 0 alsready unsorted so 0 operation
// if difference is even then operations = difference/2 + 1;
//                  odd then operations = (difference+1)/2;
#include<iostream>
#include<vector>
using namespace std;

int solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i =0;i<n;i++){
        cin >> nums[i];
    }
    int mindiff = 1e9;
    for(int i =1;i<n;i++){
        mindiff = min(mindiff,nums[i]-nums[i-1]);
    }
    if(mindiff < 0) return 0;
    else if(mindiff % 2 ==0 ) return mindiff/2 +1;
    else return (mindiff + 1)/2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
       cout << solve() << "\n";   
    }

    return 0;
}
