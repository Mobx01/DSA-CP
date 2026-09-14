/*
Codeforces - 1567B. MEXor Mixup
Time limit per test: 2 seconds
Memory limit per test: 256 megabytes

Alice gave Bob two integers a and b (a > 0 and b >= 0). Being a curious boy, Bob wrote down an array of non-negative integers with MEX value of all elements equal to a and XOR value of all elements equal to b.

What is the shortest possible length of the array Bob wrote?

Recall that the MEX (Minimum EXcluded) of an array is the minimum non-negative integer that does not belong to the array and the XOR of an array is the bitwise XOR of all the elements of the array.

Input
The input consists of multiple test cases. The first line contains an integer t (1 <= t <= 5 * 10^4) — the number of test cases. The description of the test cases follows.
The only line of each test case contains two integers a and b (1 <= a <= 3 * 10^5; 0 <= b <= 3 * 10^5) — the MEX and XOR of the array, respectively.

Output
For each test case, output one (positive) integer — the length of the shortest array with MEX a and XOR b. We can show that such an array always exists.
*/


/* Approach - O(1) Prefix XOR Pattern & Mathematical Parity Derivation (Time: O(1), Space: O(1))
 * Basically, we completely annihilate O(N) prefix XOR loops by aggressively leveraging the O(1) modulo-4 cumulative XOR identity, determining the minimum extra elements needed to match target b in pristine constant time!
 * * Observation: 
 * - The absolute core of this architecture is the Modulo-4 Cumulative XOR Cycle! Computing the XOR sum from 1 to n normally takes O(N) time, which would instantly TLE for large constraints. By implementing `xor_till`, you exploit the mathematical property that cumulative XORs repeat every 4 numbers ($n \pmod 4$), reducing the operation to a lightning-fast O(1) branch evaluation.
 * - (The Duplicate Code Paste): Your snippet was accidentally pasted twice consecutively in the prompt text. While it has no impact on execution if submitted as a single block, keeping your workspace clean avoids potential copy-paste errors or compiler confusion.
 * - (Bitwise Algebra Precision): Your conditional branches evaluating `arr_x == b`, `(arr_x ^ b) != a`, and falling back to `a + 2` brilliantly map out the exact number of trailing elements (1, 2, or 3 numbers) required to force the total XOR sum to equal target `b`, leveraging the self-inverse property of the XOR operator ($X \oplus Y = Z \implies X \oplus Z = Y$).
 * * How it runs:
 * First, we safely intercept inputs `a` and `b` across multiple test cases.
 * We compute the cumulative XOR sum from `1` up to `a - 1` in absolute O(1) time using our modulo-4 pattern helper function.
 * We evaluate the bitwise relationship between our prefix XOR (`arr_x`) and the target `b` to determine whether adding 1, 2, or 3 elements is required.
 * Finally, we flush the optimal answer to the output stream with absolute mathematical precision at raw silicon speed!
 */


#include <bits/stdc++.h>
using namespace std;

long long xor_till(long long n){
    // Determine the remainder of n when divided by 4
    long long a = n % 4;
    // Depending on the remainder, return the appropriate XOR value
    if (a == 0)
        return n;
    else if (a == 1)
        return 1;
    else if (a == 2)
        return n + 1;
    else
        return 0;
}

void solve() {
    long long a,b;
    cin >> a >> b;

    long long arr_x = xor_till(a-1);

    if(arr_x == b){
        cout << a << endl;
    }else if((arr_x^b)  != a){
        cout << a+1 << endl;
    }else{
        cout << a+2 << endl;
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
}#include <bits/stdc++.h>
using namespace std;

long long xor_till(long long n){
    // Determine the remainder of n when divided by 4
    long long a = n % 4;
    // Depending on the remainder, return the appropriate XOR value
    if (a == 0)
        return n;
    else if (a == 1)
        return 1;
    else if (a == 2)
        return n + 1;
    else
        return 0;
}

void solve() {
    long long a,b;
    cin >> a >> b;

    long long arr_x = xor_till(a-1);

    if(arr_x == b){
        cout << a << endl;
    }else if((arr_x^b)  != a){
        cout << a+1 << endl;
    }else{
        cout << a+2 << endl;
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

