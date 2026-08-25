/*
Codeforces - 1913B. Swap and Delete
Time limit per test: 1 second
Memory limit per test: 256 megabytes

You are given a binary string s (a string consisting only of 0-s and 1-s).

You can perform two types of operations on s:
delete one character from s. This operation costs 1 coin;
swap any pair of characters in s. This operation is free (costs 0 coins).

You can perform these operations any number of times and in any order.
Let's name a string you've got after performing operations above as t. The string t is good if for each i from 1 to |t|, t_i != s_i (|t| is the length of the string t). The empty string is always good. Note that you are comparing the resulting string t with the initial string s.

What is the minimum total cost to make the string t good?

Input
The first line contains a single integer t (1 <= t <= 10^4) — the number of test cases. Then t test cases follow.
The only line of each test case contains a binary string s (1 <= |s| <= 2 * 10^5; s_i \in {0, 1}) — the initial string, consisting of characters 0 and/or 1.
Additional constraint on the input: the total length of all strings s doesn't exceed 2 * 10^5.

Output
For each test case, print one integer — the minimum total cost to make string t good.
*/



/* Approach - Greedy Inverse Matching / State Pool Depletion (Time: O(N), Space: O(N) for string)
 * Basically, we completely annihilate the need for complex substring building by aggressively treating the total counts of 0s and 1s as a global ammo pool, violently depleting the opposite character until the timeline mathematically collapses!
 * * Observation: 
 * - The absolute core of this algorithm is the inverse consumption strategy! To build the optimal matching sequence `t`, every time you encounter a '0' in the original string, you physically MUST spend a '1' from your global inventory, and vice versa!
 * - (The Absolute Game-Breaker / The Structural Collapse): You brilliantly realized that you do not need to physically construct the string `t`! The exact millisecond your global pool runs completely dry of the required opposite character, the sequence mathematically shatters! You violently trigger the `break` command, completely short-circuiting the simulation and saving massive CPU cycles!
 * - (Optimization Alert 1 / The Math Nuke): Look incredibly closely at your variables: `length_of_t` and `i`. Because `length_of_t` strictly increments exactly alongside `i` during every single successful iteration, the moment the loop breaks, `length_of_t` is mathematically IDENTICAL to `i`! You can completely destroy the `length_of_t` variable entirely! When the timeline collapses, just `cout << n - i << endl;`! This instantly shreds redundant memory allocation!
 * - (Optimization Alert 2 / The STL Annihilation): You deployed a manual O(N) `for` loop to tally the zeroes and ones. You can completely bypass this manual iteration by deploying the C++ standard library: `int count_of_0s = count(s.begin(), s.end(), '0');`. Furthermore, you don't even need to count the 1s! Since it's a pure binary string, `int count_of_1s = n - count_of_0s;`. This aggressively compresses the codebase while maintaining absolute peak linear speed!
 * * How it runs:
 * First, we safely intercept the binary string `s` and aggressively sweep the timeline to lock the exact total arsenal of 0s and 1s into our global memory registers.
 * We ignite a high-speed linear sweep across the original string.
 * For every single character `s[i]`, we violently demand the *opposite* character from our global inventory! 
 * If we need a '1' and we have it, we aggressively decrement the pool (`count_of_1s--`) and advance the timeline. If we need a '0', we ruthlessly spend a '0'.
 * The exact millisecond the required ammo hits absolute zero, our structural radar triggers the `break`, completely aborting the sweep!
 * Finally, we confidently output the exact remaining unprocessable length (`n - length_of_t`, or optimally just `n - i`), flawlessly crushing the problem in blistering O(N) time!
 */


#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t; 
	while (t--)
	{
		string s;
		cin >> s; 
		int n = s.size(); 
		int count_of_0s = 0, count_of_1s = 0; 

		for (int i = 0; i < n; i++)
		{
			if (s[i] == '0')
				count_of_0s++;
			else
				count_of_1s++;
		}

		int length_of_t = 0; 

		for (int i = 0; i < n; i++)
		{
			if (s[i] == '0' && count_of_1s > 0)
			{
				count_of_1s--; 
				length_of_t++; 
			}
			else if (s[i] == '1' && count_of_0s > 0)
			{
				count_of_0s--; 
				length_of_t++; 
			}
			else
			{
				break;
			}
		}

		cout << n - length_of_t << endl;
	}
	return 0;
}
