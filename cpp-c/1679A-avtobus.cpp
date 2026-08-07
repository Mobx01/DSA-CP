/*Codeforces PS - 1679A. AvtoBus
time limit per test: 1 second
memory limit per test: 256 megabytes

Spring has come, and the management of the AvtoBus bus fleet has given the order to replace winter tires with summer tires on all buses.
You own a small bus service business and you have just received an order to replace n tires. You know that the bus fleet owns two types of buses: with two axles (these buses have 4 wheels) and with three axles (these buses have 6 wheels).
You don't know how many buses of which type the AvtoBus bus fleet owns, so you wonder how many buses the fleet might have. You have to determine the minimum and the maximum number of buses that can be in the fleet if you know that the total number of wheels for all buses is n.

Input
The first line contains an integer t (1 ≤ t ≤ 1000) — the number of test cases. The following lines contain description of test cases.
The only line of each test case contains one integer n (1 ≤ n ≤ 10^18) — the total number of wheels for all buses.

Output
For each test case print the answer in a single line using the following format.
Print two integers x and y (1 ≤ x ≤ y) — the minimum and the maximum possible number of buses that can be in the bus fleet.
If there is no suitable number of buses for the given n, print the number -1 as the answer.

Time Complexity: O(1)
Space Complexity: O(1)
*/

#include <iostream>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    
    // A valid number of wheels must be even and at least 4
    if (n % 2 != 0 || n < 4) {
        cout << -1 << "\n";
        return;
    }
    
    // To find the minimum number of buses, maximize the number of 6-wheel buses.
    long long min_buses = n / 6 + (n % 6 != 0 ? 1 : 0);
    
    // To find the maximum number of buses, maximize the number of 4-wheel buses.
    long long max_buses = n / 4;
    
    cout << min_buses << " " << max_buses << "\n";
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}

/* Approach - Greedy Arithmetic / Parity Logic (Time: O(1), Space: O(1))
 * Basically, we completely bypass all loops and simulations by aggressively deploying pure O(1) math to instantly calculate the absolute minimum and maximum number of vehicles, perfectly exploiting the structural properties of 4 and 6!
 * * Observation: 
 * - The problem dictates that every single vehicle has exactly 4 or exactly 6 wheels. Because both of these numbers are even, it is mathematically impossible to ever have an odd number of total wheels! If `n` is odd, or strictly less than 4, the configuration is permanently invalid, and we instantly reject it!
 * - To strictly MAXIMIZE the total number of vehicles, we must greedily pack the fleet with the absolute smallest vehicles possible. We simply divide `n` by 4 (`n / 4`), violently maximizing our count! (Any remainder of 2 is flawlessly resolved by swapping exactly one 4-wheeler into a 6-wheeler, which doesn't change the integer division result!)
 * - To strictly MINIMIZE the fleet, we must ruthlessly prioritize the massive 6-wheelers. Dividing `n` by 6 gets us the base minimum. But if there is ANY remainder (which can mathematically only ever be 2 or 4), we can brilliantly resolve it by swapping some 6-wheelers into 4-wheelers. This structural shift always results in exactly 1 additional vehicle being added to our count, flawlessly mirroring a ceiling function!
 * * How it runs:
 * First, we safely extract our massive integer `n`. We instantly trigger our strict boundary checks (`n % 2 != 0 || n < 4`). If the mathematical structure is broken, we violently terminate the case and print `-1`.
 * Then, we securely anchor our absolute maximum bound `maxn` by seamlessly performing integer division of `n` directly by 4.
 * Next, we fiercely compute our absolute minimum bound `minn` by dividing `n` by 6, aggressively deploying a ternary operator `(n % 6 != 0 ? 1 : 0)` to brilliantly act as an O(1) ceiling function for any leftover wheels!
 * Finally, without burning a single CPU cycle on a loop or array, we confidently print both our flawless `minn` and `maxn` side-by-side!
 */


#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;


    if (n % 2 != 0 || n < 4) {
        cout << -1 << "\n";
        return;
    }


    long long maxn = n / 4;

    long long minn = n / 6 + (n % 6 != 0 ? 1 : 0); 
    
    cout << minn << " " << maxn << "\n";
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
