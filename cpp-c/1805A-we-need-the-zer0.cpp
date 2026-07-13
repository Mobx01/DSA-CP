/*Codeforces PS - 1805A. We Need the Zero
time limit per test: 1 second
memory limit per test: 256 megabytes

There is an array a consisting of non-negative integers. You can choose an integer x and denote bi = ai ⊕ x for all 1 ≤ i ≤ n, where ⊕ denotes the bitwise XOR operation. Is it possible to choose such a number x that the value of the expression b1 ⊕ b2 ⊕ … ⊕ bn equals 0?
It can be shown that if a valid number x exists, then there also exists x such that (0 ≤ x < 2^8).

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1 ≤ t ≤ 1000). The description of the test cases follows.
The first line of the test case contains one integer n (1 ≤ n ≤ 10^3) — the length of the array a.
The second line of the test case contains n integers — array a (0 ≤ ai < 2^8).
It is guaranteed that the sum of n over all test cases does not exceed 10^3.

Output
For each set test case, print the integer x (0 ≤ x < 2^8) if it exists, or -1 otherwise.
*/


/* Approach - Bitwise Math & Parity Analysis (Time: O(N), Space: O(N))
 * Basically, we determine a single value 'X' that, when XORed with every element, makes the entire array's XOR sum equal to 0, completely depending on whether the array length is even or odd!
 * * Observation: 
 * - Let the initial XOR sum of the array be 'total_xor'. If we XOR every single element by our unknown target 'X', the new total XOR mathematically becomes `total_xor ^ (X ^ X ^ ... n times)`.
 * - If the array length 'n' is odd, XORing 'X' an odd number of times leaves exactly one 'X' remaining. To make the final sum 0, our equation becomes `total_xor ^ X = 0`. This mathematically guarantees that 'X' MUST be exactly equal to 'total_xor'!
 * - If 'n' is even, XORing 'X' an even number of times completely cancels it out to 0. Our equation becomes `total_xor ^ 0 = 0`. This means 'X' has absolutely no effect on the final sum! Therefore, it is only possible if 'total_xor' was ALREADY 0 (in which case 'X' = 0 works perfectly). If 'total_xor' is anything else, it's permanently impossible.
 * - (Note on Space: You are currently allocating a Variable-Length Array `a[n]` to store the inputs. Since you only ever need the running `total_xor`, you could actually just read the inputs into a single temporary variable on the fly and completely drop the array to achieve true O(1) space!)
 * * How it runs:
 * First, we read the array and calculate the combined `total_xor` of all elements using a single sweep.
 * Then, we evaluate the parity of the array's length (`n % 2 == 1`).
 * Next, if 'n' is odd, we confidently print `total_xor` because it perfectly balances the array to 0!
 * Finally, if 'n' is even, we verify our base sum. If `total_xor` is already 0, we output 0. If there are any uncancelled bits left over, we output -1 since no amount of operations can fix it!
 */


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; // Number of test cases
    cin >> t;
    while (t--)
    {
        long long n; // Length of the array
        cin >> n;
        long long a[n]; // Array to store the elements
        for (int i = 0; i < n; i++) // Loop to input array elements
            cin >> a[i];
        // Inputs are read into the array

        long long total_xor = 0; // Variable to store the XOR of all elements
        for (int i = 0; i < n; i++) // Loop to calculate XOR of all elements
            total_xor ^= a[i]; // XOR operation
        // XOR of all elements in the array is calculated

        if (n % 2 == 1) // Check if the number of elements is odd
        {
            cout << total_xor << endl; // Output the XOR if n is odd
        }
        else // If the number of elements is even
        {
            if (total_xor == 0) // Check if the total XOR is zero
                cout << total_xor << endl; // Output zero if total XOR is zero
            else
                cout << -1 << endl; // Output -1 if total XOR is not zero
        }
    }
    return 0;
}
