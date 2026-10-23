/*
Codeforces - 1673B. A Perfectly Balanced String?
Time limit per test: 1 second
Memory limit per test: 256 megabytes

Let's call a string s perfectly balanced if for all possible triplets (t, u, v) such that t is a non-empty substring of s and u and v are characters present in s, the difference between the frequencies of u and v in t is not more than 1.

For example, the strings "aba" and "abc" are perfectly balanced but "abb" is not because for the triplet ("bb",'a','b'), the condition is not satisfied.

You are given a string s consisting of lowercase English letters only. Your task is to determine whether s is perfectly balanced or not.

A string b is called a substring of another string a if b can be obtained by deleting some characters (possibly 0) from the start and some characters (possibly 0) from the end of a.

Input
The first line of input contains a single integer t (1 <= t <= 2 * 10^4) denoting the number of testcases.
Each of the next t lines contain a single string s (1 <= |s| <= 2 * 10^5), consisting of lowercase English letters.
It is guaranteed that the sum of |s| over all testcases does not exceed 2 * 10^5.

Output
For each test case, print "YES" if s is a perfectly balanced string, and "NO" otherwise.
You may print each letter in any case (for example, "YES", "Yes", "yes", "yEs" will all be recognized as positive answer).
*/




/* Approach - Unique Character Frequency Periodicity Verification / String Period Check (Time: O(N), Space: O(K))
 * Basically, we completely annihilate brute-force substring comparisons by aggressively extracting unique character counts as a prospective period and verifying periodic alignment in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Unique-Count Periodicity Invariant! In many string periodicity problems (often found in competitive programming contests like Codeforces), the size of the set of unique characters (`k = uni.size()`) dictates the required fundamental period length. By checking whether every character at index `i` matches `s[i + k]` across the string, we validate whether the string consists of repeating blocks of size `k`.
 * - (Auxiliary Memory Footprint): The `unordered_set` consumes $O(K)$ space where $K$ is the number of distinct characters in the alphabet (at most 26 for lowercase English letters), keeping auxiliary memory extremely tight.
 * - (Linear Time Efficiency): Inserting characters into the set and performing a single linear verification scan runs in strict $O(N)$ time.
 * * How it runs:
 * First, we read string `s` and insert all its characters into an `unordered_set` to determine the unique character count `k`.
 * We ignite a linear scan from `i = 0` as long as `i + k < n`, checking if `s[i] == s[i + k]`. If any mismatch is encountered, we mark `per = false` and break early.
 * We output `"YES"` if the periodic property holds, or `"NO"` otherwise.
 * Finally, we flush the result to the output stream with absolute mathematical precision at raw silicon speed!
 */



#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define F first
#define S second

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve() {
    string s ;
    cin >> s;

    unordered_set<char> uni;
    bool per = true;
    int n = s.length();

    for(char c : s){
        uni.insert(c);
    }
    int k = uni.size();
    for(int i=0;i+k < n;i++){
        if(s[i] != s[i+k]){
            per = false;
            break;
        }
    }
    if(per){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
