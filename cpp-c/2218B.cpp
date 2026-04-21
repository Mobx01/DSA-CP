/*
 * Codeforces pa - 2218B
 * Task: Negate exactly 6 out of 7 integers to find the maximum possible sum.
 */

/*
 * LOGIC :
 * * 1. Test Case Loop: 
 * The program reads 't' and runs a while loop to handle each individual test case.
 * * 2. Finding the Maximum:
 * We store 7 integers in a vector. As we read them, we track 'maxn', 
 * which is the largest value in the set. To maximize the final sum while 
 * negating 6 numbers, we must identify the single best number to leave positive.
 * * 3. The "Exactly 6" Constraint (maxseen flag):
 * The problem requires negating exactly 6 out of 7 numbers. This is handled 
 * by the 'maxseen' flag. 
 * - The first time we encounter the value 'maxn', we leave it as is and 
 * set maxseen = 1.
 * - This ensures that even if there are multiple identical maximum values 
 * (e.g., 5, 5, 5...), only ONE remains positive, satisfying the rule 
 * to negate exactly 6.
 * * 4. Negation Logic:
 * Any number that is NOT the first instance of 'maxn' is multiplied by -1.
 * This effectively flips its sign:
 * - Positive numbers become negative (decreasing the sum).
 * - Negative numbers become positive (increasing the sum).
 * * 5. Final Calculation:
 * The 'sum' variable accumulates these modified values and outputs the 
 * maximum possible total for that specific test case.
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        vector<int> a(7);
        int maxn = INT_MIN;
      
        for (int j = 0; j < 7; j++) {
            cin >> a[j];
            if (a[j] > maxn) {
                maxn = a[j];
            }
        }

        int sum = 0;
        int maxseen = 0;

        for (int j = 0; j < 7; j++) {
            if (a[j] == maxn && maxseen == 0) {
                maxseen = 1; 
            } else {
                a[j] = -a[j];
            }
            sum += a[j];
        }

        cout << sum << endl;
    }

    return 0;
}
