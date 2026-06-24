/*Leetcode ps- 3699. Number of ZigZag Arrays I
You are given three integers n, l, and r.
A ZigZag array of length n is defined as follows:
Each element lies in the range [l, r].
No two adjacent elements are equal.
No three consecutive elements form a strictly increasing or strictly decreasing sequence.
Return the total number of valid ZigZag arrays.

Since the answer may be large, return it modulo 109 + 7.
A sequence is said to be strictly increasing if each element is strictly greater than its previous one (if exists).
A sequence is said to be strictly decreasing if each element is strictly smaller than its previous one (if exists).*/



/* Approach - Dynamic Programming with Prefix Sum Optimization (space complexity O(N * M))
 * Basically, we build the zigzag sequence element by element, using DP to track the number of valid sequences based on the previous number and the required direction (up or down). To prevent nested loops from making it too slow, we use prefix sums to grab the total valid next steps in O(1) time.
 * We keep a few main structures to track the counts: 
 * - 't' (DP table) tracks the number of valid ways to finish the array from index 'i', given the 'prevVal' and the required 'dir' (0 for down, 1 for up).
 * - 'prefDir0' and 'prefDir1' are prefix sum arrays that accumulate the valid sequence counts for the next index (i+1), split by direction.
 *
 * How it runs:
 * First, we normalize the range [l, r] into a size 'M' (from 1 to M) because only relative differences matter. We set up the base cases at the very end of the array (index N), marking them as 1 valid way.
 * Then we loop backwards through the array from N-1 down to 0:
 * At each step, we first compute the prefix sums of the (i+1) layer. This allows us to quickly sum up ranges.
 * Next, we update our current DP layer. If we need to go UP (1), we use our prefix sums to instantly add up all valid paths that pick a number strictly greater than 'prevVal'. If we need to go DOWN (0), we grab the sum of all paths using numbers strictly less than 'prevVal'.
 * Finally, we tally the total valid arrays by trying every possible starting number (1 to M) at the first position, adding up the counts for both starting with an 'UP' move and starting with a 'DOWN' move.
 */



class Solution {
public:
    int MOD = 1e9+7;
    typedef long long ll;

    int zigZagArrays(int n, int l, int r) {
        int N = n;
        int M = r-l+1;

        ll t[2001][2001][2];

        //Base Case
        for(int prevVal = 1; prevVal <= M; prevVal++) {
            t[N][prevVal][0] = 1;
            t[N][prevVal][1] = 1;
        }

        for(int i = N-1; i >= 0; i--) {

            vector<ll> prefDir0(M+1, 0);
            vector<ll> prefDir1(M+1, 0);

            for(int prevVal = 1; prevVal <= M; prevVal++) {
                
                prefDir0[prevVal] = (prefDir0[prevVal-1] + t[i+1][prevVal][0]) % MOD;

                prefDir1[prevVal] = (prefDir1[prevVal-1] + t[i+1][prevVal][1]) % MOD;

            }

            for(int prevVal = 1; prevVal <= M; prevVal++) {
                
                t[i][prevVal][1] = (prefDir0[M] - prefDir0[prevVal] + MOD) % MOD;

                t[i][prevVal][0] = prefDir1[prevVal-1];

            }
        }

        ll result = 0;

        for(int startVal = 1; startVal <= M; startVal++) {
            //a < b > c < d ...
            result = (result + t[1][startVal][1]) % MOD;

            //a > b < c > d...
            result = (result + t[1][startVal][0]) % MOD;
        }

        return result;
        
    }
};
