/*Codeforces PS - 1878A. How Much Does Daytona Cost?
We define an integer to be the most common on a subsegment, if its number of occurrences on that subsegment is larger than the number of occurrences of any other integer in that subsegment. A subsegment of an array is a consecutive segment of elements in the array a.
Given an array a of size n, and an integer k, determine if there exists a non-empty subsegment of a where k is the most common element.
Input
Each test consists of multiple test cases. The first line contains a single integer t (1 ≤ t ≤ 1000) — the number of test cases. The description of test cases follows.
The first line of each test case contains two integers n and k (1 ≤ n ≤ 100, 1 ≤ k ≤ 100) — the number of elements in array and the element which must be the most common.
The second line of each test case contains n integers a1, a2, a3, …, an (1 ≤ ai ≤ 100) — elements of the array.
Output
For each test case output "YES" if there exists a subsegment in which k is the most common element, and "NO" otherwise.
You can output the answer in any case (for example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as a positive answer).
*/

/* Approach - Linear Search
 * Basically, we perform a straightforward scan of the array to check if our target number 'k' exists anywhere within it.
 * Observation: 
 * - The problem simply asks if 'k' is present. The moment we find even a single occurrence of 'k', we know the answer is YES and can stop searching.
 * - If we check every single number and still haven't found 'k', then it is completely absent and the answer must be NO.
 *
 * How it runs:
 * First, we read the array size 'n' and our target number 'k', and then store all the sequence elements into our 'nums' vector.
 * Then, we use a simple range-based for loop to look at every single number 'i' inside 'nums' one by one.
 * At each step, we compare the current number 'i' to our target 'k'. If they are exactly equal, we immediately print "YES" and return out of the function early since we found what we were looking for!
 * Finally, if the loop completely finishes and we never hit that return statement, it guarantees 'k' is nowhere to be found in the entire array, so we simply print "NO"!
 */

#include<iostream>
#include<vector>
using namespace std;

void solve(){
    int n ,k;
    cin >> n >>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin >> nums[i];

    for(int i : nums){
        if(i == k){
            cout << "YES\n";
            return;
        }
    }
    cout <<"NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
