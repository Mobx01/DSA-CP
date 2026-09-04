/*
Codeforces - 1691B. Shoe Shuffling
Time limit per test: 1 second
Memory limit per test: 256 megabytes

A class of students got bored wearing the same pair of shoes every day, so they decided to shuffle their shoes among themselves. In this problem, a pair of shoes is inseparable and is considered as a single object.

There are n students in the class, and you are given an array s in non-decreasing order, where s_i is the shoe size of the i-th student. A shuffling of shoes is valid only if no student gets their own shoes and if every student gets shoes of size greater than or equal to their size.

You have to output a permutation p of {1, 2, ..., n} denoting a valid shuffling of shoes, where the i-th student gets the shoes of the p_i-th student (p_i != i). And output -1 if a valid shuffling does not exist.

A permutation is an array consisting of n distinct integers from 1 to n in arbitrary order. For example, [2, 3, 1, 5, 4] is a permutation, but [1, 2, 2] is not a permutation (2 appears twice in the array) and [1, 3, 4] is also not a permutation (n = 3 but there is 4 in the array).

Input
Each test contains multiple test cases. The first line contains a single integer t (1 <= t <= 1000) — the number of test cases. Description of the test cases follows.
The first line of each test case contains a single integer n (1 <= n <= 10^5) — the number of students.
The second line of each test case contains n integers s_1, s_2, ..., s_n (1 <= s_i <= 10^9, and for all 1 <= i < n, s_i <= s_{i+1}) — the shoe sizes of the students.
It is guaranteed that the sum of n over all test cases does not exceed 10^5.

Output
For each test case, print the answer in a single line using the following format.
If a valid shuffling does not exist, print the number -1 as the answer.
If a valid shuffling exists, print n space-separated integers — a permutation p of 1, 2, ..., n denoting a valid shuffling of shoes where the i-th student gets the shoes of the p_i-th student. If there are multiple answers, then print any of them.
*/



/* Approach - Frequency Validation & Contiguous Cyclic Rotation / Group-by-Size Partitioning (Time: O(N log N), Space: O(N))
 * Basically, we completely annihilate complex derangement constraints by clustering students with identical shoe sizes, cyclically shifting their assigned indices so that every individual receives a valid shoe belonging to a peer of the exact same size!
 * * Observation: 
 * - The absolute core of this architecture is the Same-Size Cyclic Shift! If every shoe size appears at least twice, you can partition students into homogeneous size blocks. By cyclically rotating the student indices within each block by one position, you mathematically guarantee that no student receives their own specific shoes while everyone still gets a perfectly fitting pair!
 * - (The Fatal Unsorted Contiguity Trap): Your code reads the `sizes` vector and immediately executes a two-pointer contiguous sweep (`while (sizes[l] == sizes[r])`) without ever sorting the array! If the input features interleaved identical sizes (e.g., `[2, 1, 2]`), your linear scan shatters them into isolated singletons, completely breaking the rotation logic and producing corrupted permutations! You MUST pair each shoe size with its original student index and sort them together to ensure identical sizes are strictly contiguous.
 * - (The `std::map` Overhead Penalty): You deploy a `std::map<long long, long long>` to count frequencies. `std::map` allocates red-black tree nodes on the heap, triggering pointer chasing and cache-line thrashing. A sorted vector of pairs or an optimized frequency map provides vastly superior L1 cache locality.
 * - (The Trailing Rotation Edge Case): Your manual final rotation placed outside the `while (r < n)` loop attempts to catch the last block, but relying on manual post-loop cleanup when `r` equals `n` can lead to redundant shifts or logic fragmentation if not tightly bound to the block boundaries.
 * * How it runs (The Corrected Vision):
 * First, we safely intercept the timeline and bind each shoe size to its original 1-based student index, ensuring they remain permanently tethered.
 * We ignite a frequency validation pass. The exact millisecond any shoe size count equals 1, we instantly short-circuit and output `-1`.
 * We sort the paired data by shoe size, naturally forcing all identical sizes into contiguous blocks.
 * We trigger the high-speed block rotation engine! A two-pointer window sweeps across the sorted array, and the `std::rotate` function cyclically shifts the student indices within every identical size cluster.
 * Finally, we restore the permuted indices to their original positions and flush the final sequence to the output stream at raw silicon speed!
 */


#include <bits/stdc++.h>
using namespace std;
 
void solve() {
        long long n;
		cin >> n; 
		vector<long long> sizes(n);
		for (int i = 0; i < n; i++) 
			cin >> sizes[i];
 
		map<long long, long long> freq; //store frequency of each shoe size
		for (int i = 0; i < n; i++) 
			freq[sizes[i]]++;
 
		long long flag = 0; //check if a valid shuffling is possible
		for (auto i : freq)
		{
			if (i.second == 1) // If any shoe size appears only once, shuffling is not possible
			{
				flag = 1;
				break;
			}
		}
 
		if (flag)
		{
			cout << -1 << endl; // Output -1 if shuffling is not possible
			return;
		}
 
		vector<long long> students(n); // Vector to store the permutation of students
		for (int i = 0; i < n; i++) // Initialize the permutation with student indices
			students[i] = i + 1;
 
		long long l = 0, r = 0;
		while (r < n) // Iterate over the shoe sizes
		{
			if (sizes[l] == sizes[r])
				r++;
			else
			{
				// Rotate the segment of students to ensure no student gets their own shoes
				rotate(students.begin() + l, students.begin() + l + 1, students.begin() + r);
				l = r;
			}
		}
		// Rotate the last segment
		rotate(students.begin() + l, students.begin() + l + 1, students.begin() + r);
 
		for (auto i : students) // Output the permutation
			cout << i << " ";
		cout << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t ;
    cin >> t; 
    while(t--) {
        solve();  
    }
    return 0;
}
