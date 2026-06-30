/*Codeforces PS - 1890A. Doremy's Paint 3

An array b1, b2, …, bn of positive integers is good if all the sums of two adjacent elements are equal to the same value. More formally, the array is good if there exists a k such that b1 + b2 = b2 + b3 = … = bn−1 + bn = k.

Doremy has an array a of length n. Now Doremy can permute its elements (change their order) however she wants. Determine if she can make the array good.

Input
The input consists of multiple test cases. The first line contains a single integer t (1 ≤ t ≤ 100) — the number of test cases. The description of the test cases follows.
The first line of each test case contains a single integer n (2 ≤ n ≤ 100) — the length of the array a.
The second line of each test case contains n integers a1, a2, …, an (1 ≤ ai ≤ 10^5).
There are no constraints on the sum of n over all test cases.

Output
For each test case, print "Yes" (without quotes), if it is possible to make the array good, and "No" (without quotes) otherwise.
You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.
*/

/* Approach - Frequency Map & Observation
 * Basically, we use a map to count the occurrences of each number to check if the array consists of at most two distinct elements that are perfectly balanced in frequency.
 * Observation: 
 * - The problem restricts us to having at most 2 unique numbers in the entire array. If there are 3 or more, it's instantly invalid (output NO).
 * - To be valid, these two numbers must be distributed as evenly as possible. If the total array length 'n' is even, they must appear an exact equal number of times. If 'n' is odd, their frequencies must differ by exactly 1.
 * - (If there is only 1 unique number in the array, the first and last elements of the map point to the same thing, meaning 'freq1' and 'freq2' will be perfectly equal, safely passing the check!)
 *
 * How it runs:
 * First, we loop through the input and tally up the frequencies of every number using a standard map.
 * Then, we check the size of our map. If we recorded more than 2 unique elements, we immediately print "NO".
 * Finally, if we have 2 or fewer unique elements, we extract the frequencies of the first and last elements stored in the map. If these two frequencies are exactly equal, or if 'n' is odd and their absolute difference is exactly 1, we print "YES"! Otherwise, we print "NO".
 */


#include<iostream>
#include<map>

using namespace std;

void solve(){
    int n,t;
    cin >> n;
    map<int,int> freq;
    for(int i =0;i<n;i++){
        cin >> t;
        freq[t]++;
    }
    if(freq.size() > 2){
        cout<<"NO"<<endl;
    }else{
        int freq1 = freq.begin() -> second;
        int freq2 = freq.rbegin() -> second;

        if(freq1 == freq2) 
            cout<<"YES"<<endl;
        else if( n%2 == 1 && abs(freq1-freq2) == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
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
