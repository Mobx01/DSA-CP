/*Codeforces PS - 1766A. Extremely Round

Let's call a positive integer extremely round if it has only one non-zero digit. For example, 5000, 4, 1, 10, 200 are extremely round integers; 42, 13, 666, 77, 101 are not.
You are given an integer n. You have to calculate the number of extremely round integers x such that 1 ≤ x ≤ n.

Input
The first line contains one integer t (1 ≤ t ≤ 10^4) — the number of test cases.
Then, t lines follow. The i-th of them contains one integer n (1 ≤ n ≤ 999999) — the description of the i-th test case.

Output
For each test case, print one integer — the number of extremely round integers x such that 1 ≤ x ≤ n.
*/


/* Approach - Precomputation & Brute-Force Verification (Time: O(MAX) for precomputation, Space: O(R) where R is the number of valid round numbers)
 * Basically, we precalculate a master list of every single valid "round number" up to a fixed limit, so that we can quickly answer multiple test cases by just scanning our saved list!
 * * Observation: 
 * - A "round number" is strictly defined here as a number where every digit is a zero except for exactly one digit (meaning total_zeroes == total_digits - 1).
 * - Because answering this for every test case from scratch would be way too slow, it's a brilliant strategy to completely precompute the answers once globally before reading any queries.
 * - (Optimization Note: While brute-forcing from 1 to 999,999 works for small constraints, if 'n' was much larger (like 10^9), we could mathematically generate these numbers instantly by looping a base digit 1-9 and multiplying by powers of 10 instead of manually checking every single number!)
 * * How it runs:
 * First, we define a helper function 'check' that physically tears a number apart digit by digit using modulo 10 and division by 10, returning true only if exactly one digit is non-zero.
 * Then, in main, we run a massive initialization loop from 1 to 999,999. If a number passes our 'check', we permanently store it inside our 'round_numbers' vector.
 * Next, we read in our test cases. For each given 'n', we sweep through our precomputed 'round_numbers' array.
 * Finally, we count every saved number that is safely less than or equal to 'n'. Because our saved list is naturally sorted, the exact moment we hit a number strictly greater than 'n', we can instantly break out of the loop and print our final answer!
 */


#include <bits/stdc++.h>
using namespace std;

bool check(long long x) 
{
    long long count_of_digits = 0; // total digits in x
    long long count_of_zeroes = 0; // number of zeroes in x
    while (x) 
    {
        if (x % 10 == 0) 
            count_of_zeroes++; 
        count_of_digits++; 
        x /= 10; 
    }

    return count_of_zeroes == count_of_digits - 1;
}

int main()
{
    vector<long long> round_numbers;
    for (long long i = 1; i <= 999999; i++) 
    {
        if (check(i) == true) 
            round_numbers.push_back(i); 
    }

    int t; // Number of test cases
    cin >> t;
    while (t--) 
    {
        long long n; 
        cin >> n;

        long long answer = 0; 
        for (int i = 0; i < round_numbers.size(); i++) 
        {
            if (round_numbers[i] <= n) 
                answer++; 
            else
                break; 
        }
        cout << answer << endl; 
    }
    return 0;
}

