/*
Codeforces - 1490E. Accidental Victory
Time limit per test: 2 seconds
Memory limit per test: 256 megabytes

A championship is held in Berland, in which n players participate. The player with the number i has a_i (a_i >= 1) tokens.

The championship consists of n - 1 games, which are played according to the following rules:
in each game, two random players with non-zero tokens are selected;
the player with more tokens is considered the winner of the game (in case of a tie, the winner is chosen randomly);
the winning player takes all of the loser's tokens;
The last player with non-zero tokens is the winner of the championship.

All random decisions that are made during the championship are made equally probable and independently.

Championship winners will receive personalized prizes. Therefore, the judges want to know in advance which players have a chance of winning, i.e have a non-zero probability of winning the championship. You have been asked to find all such players.

Input
The first line contains one integer t (1 <= t <= 10^4) — the number of test cases. Then t test cases follow.
The first line of each test case consists of one positive integer n (1 <= n <= 2 * 10^5) — the number of players in the championship.
The second line of each test case contains n positive integers a_1, a_2, ..., a_n (1 <= a_i <= 10^9) — the number of tokens the players have.
It is guaranteed that the sum of n over all test cases does not exceed 2 * 10^5.

Output
For each test case, print the number of players who have a nonzero probability of winning the championship. On the next line print the numbers of these players in increasing order. Players are numbered starting from one in the order in which they appear in the input.
*/



/* Approach - Sorting with Backward Prefix Sum Chain Reaction / Winner Identification (Time: O(N log N), Space: O(N))
 * Basically, we completely annihilate O(N^2) simulation of element absorption rounds by aggressively sorting the array and working backwards with cumulative prefix sums to identify the unbroken winning threshold in pristine log-linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Backward Growth Invariant! In problems where elements can absorb smaller elements to grow larger (e.g., standard competitive programming monster/element merging games), sorting the elements in non-descending order allows us to evaluate a cumulative prefix sum from left to right. By scanning *backwards* from the second-to-last element down to the beginning, we can verify if a contiguous chain of elements can successfully absorb the next larger element (`pref[i] >= a[i+1].first`). The moment this chain breaks, no element to the left can ever accumulate enough mass to win, giving us an exact cutoff index (`win_start`)!
 * - (Original Index Preservation Strategy): Your code pairs each value with its 1-based original index (`a[i].second = i + 1`) before sorting. This is a brilliant maneuver because sorting alters the physical positions; storing the original indices ensures that after filtering the winners, you can sort them back into their original spatial order before printing.
 * - (Efficient Vector Collection and Sorting): Collecting the surviving original indices into `ans`, sorting them, and printing them ensures the output strictly matches required formatting constraints with minimal performance overhead.
 * * How it runs:
 * First, we safely intercept array size `n` and read elements while attaching their 1-based original indices.
 * We invoke the sorting engine to arrange the elements in ascending order.
 * We build a prefix sum array to track cumulative mass efficiently.
 * We sweep backwards from `n - 2` down to `0`, dynamically updating our `win_start` cutoff pointer as long as the cumulative prefix sum can absorb the next element.
 * We extract all winning original indices from `win_start` to `n - 1`, sort them by their original positions, and flush the total count followed by the space-separated index list to the output stream at raw silicon speed!
 */



#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    vector<pair<long long, long long>> a(n);
    for(long long i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(a.begin(), a.end());
    
    // Calculate prefix sums
    vector<long long> pref(n);
    pref[0] = a[0].first;
    for(int i = 1; i < n; i++) {
        pref[i] = pref[i-1] + a[i].first;
    }

    // The largest element can always win. Work backwards to find the cutoff.
    int win_start = n - 1; 
    for(int i = n - 2; i >= 0; i--) {
        // If the current element's max potential (prefix sum) can beat the next element
        if(pref[i] >= a[i+1].first) {
            win_start = i;
        } else {
            // As soon as a chain is broken, no smaller elements can win
            break;
        }
    }

    // Collect all winners
    vector<long long> ans;
    for(int i = win_start; i < n; i++) {
        ans.push_back(a[i].second);
    }

    // Sort by original 1-based index and print
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(long long i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
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
