/* Leetcode PS ; 2483  Minimum Penalty for a Shop
You are given the customer visit log of a shop represented by a 0-indexed string customers consisting only of characters 'N' and 'Y':
if the ith character is 'Y', it means that customers come at the ith hour
whereas 'N' indicates that no customers come at the ith hour.
If the shop closes at the jth hour (0 <= j <= n), the penalty is calculated as follows:

For every hour when the shop is open and no customers come, the penalty increases by 1.
For every hour when the shop is closed and customers come, the penalty increases by 1.
Return the earliest hour at which the shop must be closed to incur a minimum penalty.

Note that if a shop closes at the jth hour, it means the shop is closed at the hour j.
*/


// space complexity : o(n) approach
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        vector<int> prefix(n + 1, 0);
        vector<int> suffix(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + (customers[i - 1] == 'N');
        }

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + (customers[i] == 'Y');
        }

        int minPenalty = INT_MAX;
        int ans = 0;

        for (int i = 0; i <= n; i++) {
            int penalty = prefix[i] + suffix[i];
            if (penalty < minPenalty) {
                minPenalty = penalty;
                ans = i;
            }
        }

        return ans;
    }
};
 
