/*Codeforces PS - 1859A. United We Stand

Given an array a of length n, containing integers. And there are two initially empty arrays b and c. You need to add each element of array a to exactly one of the arrays b or c, in order to satisfy the following conditions:
Both arrays b and c are non-empty. More formally, let lb be the length of array b, and lc be the length of array c. Then lb, lc ≥ 1.
For any two indices i and j (1 ≤ i ≤ lb, 1 ≤ j ≤ lc), cj is not a divisor of bi.
Output the arrays b and c that can be obtained, or output -1 if they do not exist.

Input
Each test consists of multiple test cases. The first line contains a single integer t (1 ≤ t ≤ 500) — the number of test cases. The description of the test cases follows.
The first line of each test case contains a single integer n (2 ≤ n ≤ 100) — the length of array a.
The second line of each test case contains n integers a1, a2, …, an (1 ≤ ai ≤ 10^9) — the elements of array a.

Output
For each test case, output a single integer -1 if a solution does not exist.
Otherwise, in the first line, output two integers lb and lc — the lengths of arrays b and c respectively.
In the second line, output lb integers b1, b2, …, blb — the elements of array b.
In the third line, output lc integers c1, c2, …, clc — the elements of array c.
If there are multiple solutions, output any of them. You can output the elements of the arrays in any order.
*/

/* Approach - Sorting & Greedy Partitioning
 * Basically, we split the given array into two non-empty subarrays 'b' and 'c' such that every element in 'b' is strictly smaller than every element in 'c'. We achieve this by collecting all copies of the absolute smallest number into 'b' and putting everything else into 'c'!
 * Observation: 
 * - In order for every element in 'b' to be strictly less than every element in 'c', the safest and easiest strategy is to make 'b' contain only the minimum value(s) of the entire array.
 * - If all elements in the array are exactly identical, this partition is mathematically impossible. Sorting the array lets us check this instantly: if the first element equals the last element, the array is completely uniform!
 *
 * How it runs:
 * First, we read the sequence into our array 'a' and sort it in ascending order.
 * Then, we check our impossible edge case: if the smallest element ('a[0]') is exactly equal to the largest element ('a[n-1]'), we know there are no distinct elements. We simply print -1 and move to the next test case.
 * If they don't match, a valid partition is guaranteed to exist! We lock in our minimum element by storing 'a[0]' into the 'least' variable.
 * Next, we sweep through the array one by one. If the current number perfectly matches 'least', we push it into array 'b'. If it's anything else, it is mathematically guaranteed to be strictly greater, so we push it into array 'c'.
 * Finally, we output the sizes of our two newly formed arrays, followed by printing out all the elements inside 'b' and then 'c'!
 */


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; // Number of test cases
    cin >> t;
    while (t--)
    {
        long long n; // Length of sequence b
        cin >> n;
        vector<long long> a(n), b,c; 
        for (int i = 0; i < n; i++) // Loop to read the sequence a
            cin >> a[i];
        
        sort(a.begin(),a.end());
        if(a[0] == a[n-1]){
                cout << -1 << endl;
                continue;
        }
        int least = a[0];
        for(int i=0;i<n;i++){
            if(a[i] == least) b.push_back(a[i]);
            else c.push_back(a[i]);
        }
        cout << b.size()<< " " << c.size() << endl;
        for(int i : b){
            cout << i << " ";
        }
        cout << endl;
        for(int i : c){
            cout << i << " ";
        }
        cout << endl; 
    }
    return 0;
}
