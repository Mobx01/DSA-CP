/*Codeforces PS - 1834A. Unit Array
Given an array a of length n, which elements are equal to -1 and 1. Let's call the array a good if the following conditions are held at the same time:
a1 + a2 + … + an ≥ 0;
a1 ⋅ a2 ⋅ … ⋅ an = 1.

In one operation, you can select an arbitrary element of the array ai and change its value to the opposite. In other words, if ai = -1, you can assign the value to ai := 1, and if ai = 1, then assign the value to ai := -1.

Determine the minimum number of operations you need to perform to make the array a good. It can be shown that this is always possible.

Input
Each test consists of multiple test cases. The first line contains a single integer t (1 ≤ t ≤ 500) — the number of test cases. The description of the test cases follows.
The first line of each test case contains a single integer n (1 ≤ n ≤ 100) — the length of the array a.
The second line of each test case contains n integers a1, a2, …, an (ai = ±1) — the elements of the array a.

Output
For each test case, output a single integer — the minimum number of operations that need to be done to make the a array good.
*/


/* Approach - Greedy & Math (Time: O(N), Space: O(N))
 * Basically, we greedily flip just enough '-1's to '1's to satisfy the non-negative sum condition, and then perform one final parity check to ensure the product condition is met!
 * * Observation: 
 * - To make the sum >= 0, the count of 1s must be greater than or equal to the count of -1s.
 * - To make the product == 1, the total count of remaining -1s must be an even number.
 * - Every time we flip a -1 to a 1, we fix the sum deficit by 2 (since we lose a -1 and gain a 1) and toggle the parity of the -1 count.
 * * How it runs:
 * First, we read the array and tally up the initial occurrences of 1s and -1s.
 * Then, we address the sum condition: if there are strictly more -1s than 1s, we mathematically calculate how many flips are required to balance them out using ceiling division `(diff + 1) / 2`. We add these to our operation count and update our 1s and -1s trackers accordingly.
 * Finally, we address the product condition: we check if our newly updated count of -1s is odd. If it is, the product is currently -1, so we are forced to spend exactly 1 more operation to flip another -1 into a 1. We then return the total operations used!
 */


// count of 1 >= count of -1
// count of -1 is even
#include<iostream>
#include<vector>
using namespace std;

int solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    int countone = 0, countmin = 0;
    
    for(int i = 0; i < n; i++){
        cin >> nums[i];
        if(nums[i] == -1) countmin++;
        else countone++;
    }
    
    int oper = 0;
    
    if(countone < countmin){
        int diff = countmin - countone;
        // Divide by 2 and round up to get the minimum flips needed
        int flips = (diff + 1) / 2; 
        
        oper += flips;
        countone += flips;
        countmin -= flips;
    }
    
    //  Make product == 1
    if(countmin % 2 != 0) {
        oper += 1;
    }
    
    return oper;
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
