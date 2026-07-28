/*
Codeforces PS -1883B. Chemistry

You are given a string s of length n, consisting of lowercase Latin letters, and an integer k.
You need to check if it is possible to remove exactly k characters from the string s in such a way that the remaining characters can be rearranged to form a palindrome. Note that you can reorder the remaining characters in any way.

A palindrome is a string that reads the same forwards and backwards. For example, the strings "z", "aaa", "aba", "abccba" are palindromes, while the strings "codeforces", "reality", "ab" are not.

Input
Each test consists of multiple test cases. The first line contains a single integer t (1 ≤ t ≤ 10^4) — the number of the test cases. This is followed by their description.
The first line of each test case contains two integers n and k (0 ≤ k < n ≤ 10^5) — the length of the string s and the number of characters to be deleted.
The second line of each test case contains a string s of length n, consisting of lowercase Latin letters.
It is guaranteed that the sum of n over all test cases does not exceed 2⋅10^5.

Output
For each test case, output "YES" if it is possible to remove exactly k characters from the string s in such a way that the remaining characters can be rearranged to form a palindrome, and "NO" otherwise.
You can output the answer in any case (uppercase or lowercase). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive answers.
*/

/* Approach - Parity Counting & Greedy Deletion (Time: O(N), Space: O(1))
 * Basically, we tally up the frequencies of every single character, count exactly how many appear an odd number of times, and mathematically verify if our allowed 'k' operations are enough to perfectly fix the imbalance!
 * * Observation: 
 * - A valid palindrome can mathematically only ever have a maximum of ONE character with an odd frequency (which perfectly anchors the absolute center of the string). Every single other character MUST appear an even number of times!
 * - This means if we have `oddcount` characters with odd frequencies, we are absolutely forced to remove at least one instance from `oddcount - 1` of those character groups to successfully round them down to even numbers.
 * - If our mathematically required number of fixes (`oddcount - 1`) strictly exceeds our allowed operation budget `k`, forming a palindrome is a structural impossibility!
 * - (Optimization Note: While `unordered_map` easily gets the job done, it carries heavy memory and hashing overhead! Since the string likely only contains 26 standard lowercase English letters, physically swapping the map for a simple, fixed-size `vector<int> freq(26, 0)` would brilliantly optimize the auxiliary space down to a strict, guaranteed O(1) and run significantly faster!)
 * * How it runs:
 * First, we extract our total string length `n` and operation budget `k`, and sweep through the entire string to aggressively tally up the exact frequency of every single character inside our `freq` map.
 * Then, we initialize our `oddcount` tracker and iterate directly through the fully populated map. We check the exact parity of every character's frequency, and if it is odd (`v.second % 2 == 1`), we instantly increment our tracker.
 * Finally, we evaluate our absolute mathematical constraint: if `oddcount - 1 > k`, we lack the budget to balance the string and aggressively print "NO". Otherwise, we confidently print "YES" because a palindrome is guaranteed!
 */


#include <bits/stdc++.h>
using namespace std;

void solve() {
   long long n ,k;
   cin >> n >>k;
   string s;
   cin >> s;

   unordered_map<char,int> freq;

   for(char c : s)freq[c]++;
   int oddcount=0;
   for(auto& v : freq){
      if(v.second % 2 == 1 ) oddcount++;
   }
   //we can have maximum 1 charcter with odd frequecy else no palindrome will be there
   if(oddcount - 1 > k) cout << "NO\n";
   else cout << "YES\n";
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
