
/*
Codeforces PS - 1666D. Deletive Editing
time limit per test: 3 seconds
memory limit per test: 512 megabytes

Daisy loves playing games with words. Recently, she has been playing the following Deletive Editing word game with Daniel.
Daisy picks a word, for example, "DETERMINED". On each game turn, Daniel calls out a letter, for example, 'E', and Daisy removes the first occurrence of this letter from the word, getting "DTERMINED". On the next turn, Daniel calls out a letter again, for example, 'D', and Daisy removes its first occurrence, getting "TERMINED". They continue with 'I', getting "TERMNED", with 'N', getting "TERMED", and with 'D', getting "TERME". Now, if Daniel calls out the letter 'E', Daisy gets "TRME", but there is no way she can get the word "TERM" if they start playing with the word "DETERMINED".
Daisy is curious if she can get the final word of her choice, starting from the given initial word, by playing this game for zero or more turns. Your task it help her to figure this out.

Input
The first line of the input contains an integer n — the number of test cases (1 ≤ n ≤ 10000). The following n lines contain test cases.
Each test case consists of two words s and t separated by a space. Each word consists of at least one and at most 30 uppercase English letters; s is the Daisy's initial word for the game; t is the final word that Daisy would like to get at the end of the game.

Output
Output n lines to the output — a single line for each test case. Output "YES" if it is possible for Daisy to get from the initial word s to the final word t by playing the Deletive Editing game. Output "NO" otherwise.

Time Complexity: O(|S|) per test case
Space Complexity: O(1)
*/


/* Approach - Right-to-Left Frequency Extraction / Greedy String Reconstruction (Time: O(N + M), Space: O(N))
 * Basically, we aggressively tally up the exact character frequencies desperately needed by our target string, and violently sweep the original string completely backwards to extract the absolute rightmost matching characters to see if they flawlessly reconstruct the target!
 * * Observation: 
 * - If we were strictly doing a standard subsequence check, a simple left-to-right two-pointer approach would instantly solve it. But by deploying a strict frequency array and sweeping right-to-left, this algorithm mathematically forces the selection of the absolute latest possible occurrences of the required characters!
 * - (The Absolute Game-Breaker): By aggressively mutating the unused and excess characters directly into a dead `.` placeholder, we completely bypass the nightmare of index shifting or complex pointer management! We physically carve the exact structural shape of the required characters directly into the original string!
 * - (Optimization Note: Because `final_string` dynamically concatenates characters one by one in a loop, it burns an extra O(N) auxiliary space. We could elegantly optimize this by modifying the original string strictly in-place using a fast and slow pointer, instantly slashing the memory footprint down to a flawless O(1)!)
 * * How it runs:
 * First, we safely extract the sizes `n` and `m`, and fiercely populate a 26-slot `frequency_in_t` array by scanning through every single character in the target `t` to build our exact requirements pool.
 * Then, we trigger a high-speed reverse linear sweep starting directly from the end of `s`. For every single character, if our pool desperately needs it (`frequency_in_t > 0`), we aggressively lock it in by decrementing the count.
 * The exact millisecond we encounter a character we don't need (or have already completely fulfilled the quota for), we ruthlessly overwrite it with a `.` marker, permanently flagging it for deletion!
 * Next, we trigger a second forward sweep, flawlessly assembling our brand new `final_string` by actively skipping over every single dead `.` placeholder.
 * Finally, we fiercely pit our forged string directly against `t`. If they perfectly mirror each other, we confidently print "YES", otherwise we aggressively print "NO" and terminate the case!
 */



#include <bits/stdc++.h>
using namespace std;

void solve() {
		string s, t;
		cin >> s >> t;

		// Get the lengths of the initial word s and the target word t
		int n = s.size();
		int m = t.size();

		// Create a frequency vector to count occurrences of each letter in t
		vector<int> frequency_in_t(26, 0);
		for (int i = 0; i < m; i++) // Iterate over each character in t
			frequency_in_t[t[i] - 'A']++;

		// Traverse the initial word s from the end to the beginning
		for (int i = n - 1; i >= 0; i--) // Iterate over each character in s
		{
			// If the character in s is needed in t, decrement its count
			if (frequency_in_t[s[i] - 'A'] > 0)
				frequency_in_t[s[i] - 'A']--;
			else
				// Otherwise, mark it as removed by setting it to '.'
				s[i] = '.';
		}

		// Construct the final string by excluding marked characters
		string final_string = "";
		for (int i = 0; i < n; i++) // Iterate over each character in s
		{
			if (s[i] != '.')
				final_string += s[i];
		}

		// Check if the constructed final string matches the target word t
		if (final_string == t) // Compare the final string with t
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}


int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        solve();  

    return 0;
}
