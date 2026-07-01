/*Codeforces PS - 1881A. Don't Try to Count
Given a string x of length n and a string s of length m (n⋅m ≤ 25), consisting of lowercase Latin letters, you can apply any number of operations to the string x.

In one operation, you append the current value of x to the end of the string x. Note that the value of x will change after this.
For example, if x = "aba", then after applying operations, x will change as follows: "aba" → "abaaba" → "abaabaabaaba".

After what minimum number of operations s will appear in x as a substring? A substring of a string is defined as a contiguous segment of it.

Input
The first line of the input contains a single integer t (1 ≤ t ≤ 10^4) — the number of test cases.
The first line of each test case contains two numbers n and m (1 ≤ n⋅m ≤ 25) — the lengths of strings x and s, respectively.
The second line of each test case contains the string x of length n.
The third line of each test case contains the string s of length m.

Output
For each test case, output a single number — the minimum number of operations after which s will appear in x as a substring. If this is not possible, output -1.
*/



/* Approach - String Doubling & Substring Search
 * Basically, we repeatedly double the starting string 'x' until it is large enough to potentially contain 's', checking for a match at each step.
 * Observation: 
 * - If 's' can be formed by repeating 'x', it will appear as a substring as soon as 'x' reaches or slightly exceeds the length of 's'. 
 * - Specifically, 's' might span across the exact boundary where two copies of 'x' join together. Therefore, once the length of 'x' is comfortably larger than 's' (like twice its length), any further doublings are pointless because no new unique character boundaries will be created.
 *
 * How it runs:
 * First, we enter a while loop that keeps checking if 's' exists inside 'x' using the built-in 'find' function.
 * If we find it, we immediately return our current operation 'count'. If not, we double 'x' by concatenating it to itself (x += x), increment our 'count', and try again. 
 * We keep this loop running as long as the size of 'x' is less than or equal to twice the size of 's'.
 * Once the loop finishes, we perform two final manual checks (and possible doublings). This acts as a foolproof buffer to catch any extreme edge cases where 's' requires one last boundary connection to fully materialize.
 * Finally, if 's' still hasn't been found after reaching these maximum reasonable bounds, we know it's completely impossible to form, so we return -1!
 */

#include<iostream>
#include<string>

using namespace std;

int solve(){
    int n ,m;
    cin >> n >> m;
    string x ,s;
    cin >> x >> s;

    int count = 0;
    while(x.size()<=2*s.size()){
        if(x.find(s) != string::npos){
            return count;
        }
        x += x;
        count++;
    }
    if(x.find(s) != string::npos){
            return count;
        }
    x += x;
    count++;
    if(x.find(s) != string::npos){
            return count;
        }


    return -1;
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
