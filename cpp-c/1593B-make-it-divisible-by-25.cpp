/*
Codeforces - 1593B. Make it Divisible by 25
Time limit per test: 1 second
Memory limit per test: 256 megabytes

It is given a positive integer n. In 1 move, one can select any single digit and remove it (i.e. one selects some position in the number and removes the digit located at this position). The operation cannot be performed if only one digit remains. If the resulting number contains leading zeroes, they are automatically removed.

E.g. if one removes from the number 32925 the 3-rd digit, the resulting number will be 3225. If one removes from the number 20099050 the first digit, the resulting number will be 99050 (the 2 zeroes going next to the first digit are automatically removed).

What is the minimum number of steps to get a number such that it is divisible by 25 and positive? It is guaranteed that, for each n occurring in the input, the answer exists. It is guaranteed that the number n has no leading zeros.

Input
The first line contains one integer t (1 <= t <= 10^4) — the number of test cases. Then t test cases follow.
Each test case consists of one line containing one integer n (25 <= n <= 10^18). It is guaranteed that, for each n occurring in the input, the answer exists. It is guaranteed that the number n has no leading zeros.

Output
For each test case output on a separate line an integer k (k >= 0) — the minimum number of steps to get a number such that it is divisible by 25 and positive.
*/


/* Approach - Right-to-Left Greedy Parsing / Mathematical Suffix Matching (Time: O(log10 N), Space: O(1))
 * Basically, we mathematically dissect the integer digit by digit from right to left, aggressively splitting the universe into two parallel timelines to hunt down the absolute optimal two-digit suffix required for divisibility by 25!
 * * Observation: 
 * - The absolute unbreakable law of mathematics states that any number is flawlessly divisible by 25 IF AND ONLY IF its final two digits are exactly "00", "50", "25", or "75"! 
 * - By dynamically extracting digits using `% 10` and `/ 10`, we completely bypass the memory overhead of converting the number into a `std::string`, executing the entire search in pure mathematical space!
 * - (The Absolute Game-Breaker): The algorithm brilliantly isolates the search into exactly two independent timelines based on the terminal digit! Timeline 1 hyper-fixates on finding a base '0' and then aggressively hunts for a preceding '0' or '5'. Timeline 2 hyper-fixates on finding a base '5' and ruthlessly hunts for a preceding '2' or '7'!
 * - (Optimization Alert / The String Paradigm): While your pure math approach is blisteringly fast (O(log10 N) is mathematically equivalent to O(1) since a 64-bit integer maxes out at 19 digits), it requires a massive wall of boilerplate `while` loops and flags. You could instantly slash the code footprint by 70% by converting `n` to a `string` and running a fierce double `for` loop to directly calculate the required deletions for the four exact targets ("00", "25", "50", "75"), relentlessly taking the minimum!
 * * How it runs:
 * First, we safely extract our target integer `n`, securely anchor our `min_deletions` ceiling at a theoretically unreachable high value (100), and clone `n` into a volatile `temp` variable.
 * Then, we ignite Timeline 1! We forcefully rip digits off `temp` one by one. The exact millisecond we detect our first '0', we violently flip the `found_zero` flag. We then continue the right-to-left sweep, actively tallying up `deletions` for every useless digit, until we finally crash into a valid '0' or '5'. We instantly lock the required operations into `min_deletions` and aggressively break the loop!
 * Next, we meticulously reset the state! We restore `temp` perfectly back to `n`, cleanly reset our deletion tracker, and ignite Timeline 2!
 * We sweep again, this time aggressively hunting for a base '5'. Once secured, we relentlessly strip away digits until we flawlessly connect with a '2' or '7', updating `min_deletions` if this alternate timeline mathematically beats our previous record.
 * Finally, we confidently print the absolute lowest bound of deletions required to mathematically forge a perfect multiple of 25!
 */


#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;

    int min_deletions = 100; // Start with a large number

    long long temp = n;
    int deletions = 0;
    bool found_zero = false;
    
    while (temp > 0) {
        int d = temp % 10;
        temp /= 10; 
        
        if (!found_zero) {
            if (d == 0) {
                found_zero = true; // Found the last '0'
            } else {
                deletions++; // Skip this digit
            }
        } else {
            if (d == 0 || d == 5) {
                min_deletions = min(min_deletions, deletions);
                break;
            } else {
                deletions++; // Skip this digit
            }
        }
    }

   
    temp = n;
    deletions = 0;
    bool found_five = false;

    while (temp > 0) {
        int d = temp % 10;
        temp /= 10; 
        
        if (!found_five) {
            if (d == 5) {
                found_five = true; // Found the last '5'
            } else {
                deletions++;
            }
        } else {
            if (d == 2 || d == 7) { 
                min_deletions = min(min_deletions, deletions);
                break; 
            } else {
                deletions++;
            }
        }
    }

    cout << min_deletions << "\n";
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
