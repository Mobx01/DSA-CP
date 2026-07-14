/*Codeforces PS - 1791C. Prepend and Append
Timur initially had a binary string † s (possibly of length 0). He performed the following operation several (possibly zero) times:
Add 0 to one end of the string and 1 to the other end of the string. For example, starting from the string 1011, you can obtain either 010111 or 110110.
You are given Timur's final string. What is the length of the shortest possible string he could have started with?
† A binary string is a string (possibly the empty string) whose characters are either 0 or 1.

Input
The first line of the input contains an integer t (1 ≤ t ≤ 100) — the number of testcases.
The first line of each test case contains an integer n (1 ≤ n ≤ 2000) — the length of Timur's final string.
The second line of each test case contains a string s of length n consisting of characters 0 or 1, denoting the final string.

Output
For each test case, output a single nonnegative integer — the shortest possible length of Timur's original string. Note that Timur's original string could have been empty, in which case you should output 0.

Time Complexity: O()
Space Complexity: O()
*/

/* Approach - Two Pointers / String Trimming (Time: O(N), Space: O(1))
 * Basically, we use a two-pointer approach to progressively peel away opposite characters from both ends of the binary string until we hit a pair of identical characters, revealing the shortest possible length of the original string!
 * * Observation: 
 * - The problem implies the string was built by repeatedly adding different characters (0 and 1, or 1 and 0) to both ends.
 * - Therefore, as long as the leftmost character and the rightmost character are strictly different, they must have been added during that building process, meaning we can safely discard them.
 * - The exact moment we find two endpoints that are the SAME, we know we've hit the unpeelable core of the original string. 
 * - Your condition `(bin[i] - bin[j]) == 0` is a fun and clever ASCII math trick! Since characters are stored as ASCII values, subtracting them yields 0 only if they are the exact same character.
 * * How it runs:
 * First, we read the length 'n' and the binary string 'bin', and plant our two pointers: 'i' at the extreme left (0) and 'j' at the extreme right (n - 1).
 * Then, we enter a while loop that continues as long as our pointers haven't crossed ('i <= j'). We evaluate our endpoints. If they are identical (`bin[i] == bin[j]`), we immediately stop and return the length of this remaining core, which is mathematically calculated as 'j - i + 1'.
 * Next, if they are different, we successfully peel them away by taking a step inward from both sides ('i++' and 'j--').
 * Finally, if the string completely collapses on itself and the loop finishes naturally (which happens if the original string was completely empty and every single paired layer was opposite), we return 0!
 */

#include <bits/stdc++.h>
using namespace std;

int solve(){
    int n;
    cin >> n;
    string bin;
    cin >> bin;
    int i =0,j=n-1;

    while(i<=j){
        if((bin[i]-bin[j]) == 0){
            return j-i+1;
        }else{
            i++;
            j--;
        }
    }
    return 0;
}

int main()
{
    int t; // Number of test cases
    cin >> t;
    while (t--)
    {
        cout << solve() << "\n";    }
    return 0;
}
