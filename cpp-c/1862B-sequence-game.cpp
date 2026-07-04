/*Codeforces PS - 1862B. Sequence Game
Tema and Vika are playing the following game. First, Vika comes up with a sequence of positive integers a of length m and writes it down on a piece of paper. Then she takes a new piece of paper and writes down the sequence b according to the following rule: First, she writes down a1. Then, she writes down only those ai (2 ≤ i ≤ m) such that ai−1 ≤ ai. Let the length of this sequence be denoted as n.
For example, from the sequence a = [4, 3, 2, 6, 3, 3], Vika will obtain the sequence b = [4, 6, 3].
She then gives the piece of paper with the sequence b to Tema. He, in turn, tries to guess the sequence a. Tema considers winning in such a game highly unlikely, but still wants to find at least one sequence a that could have been originally chosen by Vika. Help him and output any such sequence. Note that the length of the sequence you output should not exceed the input sequence length by more than two times.
Input
Each test consists of multiple test cases. The first line of input data contains a single integer t (1 ≤ t ≤ 10^4) — the number of test cases. This is followed by a description of the test cases.
The first line of each test case contains a single integer n (1 ≤ n ≤ 2⋅10^5) — the length of the sequence b.
The second line of each test case contains n integers b1, b2, b3, …, bn (1 ≤ bi ≤ 10^9) — the elements of the sequence.
The sum of the values of n over all test cases does not exceed 2⋅10^5.
Output
For each test case, output two lines. In the first line, output a single integer m — the length of the sequence (n ≤ m ≤ 2⋅n). In the second line, output m integers a1, a2, a3, …, am (1 ≤ ai ≤ 10^9) — the assumed sequence that Vika could have written on the first piece of paper.
If there are multiple suitable sequences, you can output any of them.
*/

/* Approach - Constructive Algorithm / Greedy Array Reconstruction (space complexity O(N))
 * Basically, we reconstruct the original array 'a' by figuring out exactly where the sequence extraction rule was broken and forcefully injecting "dummy" values to bridge the gaps.
 * Observation: 
 * - The sequence 'b' is formed by always taking the first element of 'a', and then taking any subsequent element that is greater than or equal to the previously taken one.
 * - If b[i] >= b[i-1], it perfectly follows the non-decreasing rule. We can simply drop b[i] right into our answer array without any issues.
 * - The catch: If b[i] < b[i-1], the sequence dropped. If we just placed b[i] directly after b[i-1] in array 'a', it would be smaller than the threshold and get completely ignored during extraction! To fix this, we insert an extra b[i] right before it. The first b[i] fails the check and gets skipped, but it secretly resets the comparison threshold, allowing the second b[i] to successfully pass the check and become part of sequence 'b'!
 *
 * How it runs:
 * First, we initialize our answer array 'a' and immediately push the very first element of 'b' into it, because the first element is always extracted by default.
 * Then, we loop through the rest of the 'b' array starting from index 1. At each step, we compare the current element 'b[i]' to the previous element 'b[i-1]'.
 * If 'b[i]' is greater than or equal to 'b[i-1]', we confidently push a single copy of 'b[i]' into 'a'. If it is strictly smaller, we push two copies of 'b[i]' into 'a' to execute our clever reset trick.
 * Finally, once the loop finishes constructing the valid sequence, we output the total size of our newly built array 'a', followed by printing out all of its elements!
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
        vector<long long> b(n), a; // Vector b to store input sequence, vector a to store the reconstructed sequence
        for (int i = 0; i < n; i++) // Loop to read the sequence b
            cin >> b[i];
        // Initial input of sequence b is completed

        a.push_back(b[0]); // Always add the first element of b to a
        for (int i = 1; i < n; i++) // Loop through the rest of the sequence b
        {
            if (b[i] >= b[i - 1])
                a.push_back(b[i]); // If current element is greater than or equal to the previous, add it to a
            else
            {
                a.push_back(b[i]); // Add the current element to a
                a.push_back(b[i]); // Add the current element again to a to ensure a[i-1] <= a[i]
            }
        }
        cout << a.size() << endl; // Output the size of the reconstructed sequence a
        for (auto it : a) // Output each element of the sequence a
            cout << it << " ";
        cout << endl; // New line after each test case
    }
    return 0;
}

// Time Complexity (TC): O(n) = O(2*10^5)
// Space Complexity (SC): O(n) = O(2*10^5)
