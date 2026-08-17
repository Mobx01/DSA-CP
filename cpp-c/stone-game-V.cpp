/*Leetcode ps-1563. Stone Game V
There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.
In each round of the game, Alice divides the row into two non-empty rows (i.e. left row and right row), then Bob calculates the value of each row which is the sum of the values of all the stones in this row. Bob throws away the row which has the maximum value, and Alice's score increases by the value of the remaining row. If the value of the two rows are equal, Bob lets Alice decide which row will be thrown away. The next round starts with the remaining row.
The game ends when there is only one stone remaining. Alice's score is initially zero.
Return the maximum score that Alice can obtain.*/



/* Approach - Top-Down Dynamic Programming / O(1) Prefix Sum Partitioning (Time: O(N^3), Space: O(N^2))
 * Basically, we aggressively slice the array into every conceivable two-part combination, mathematically evaluating the optimal split while permanently caching the timelines in a massive 2D matrix to prevent a catastrophic explosion of overlapping subproblems!
 * * Observation: 
 * - The absolute core of this game theory problem is the ruthless evaluation of all possible splits. Since Alice is mathematically forced (most of the time) to take the smaller sum by Bob, we must simulate every single branching future to find the one path that yields the absolute maximum score!
 * - (The Absolute Game-Breaker): The Prefix Sum Array! If you ran a standard `for` loop to calculate the sum of the left and right partitions at every single split, your complexity would violently spiral into a TLE-inducing O(N^4)! By precalculating the running totals in a single O(N) pass, you flawlessly crush every single range sum query (`sum1` and `sum2`) down to a blistering O(1) CPU cycle!
 * - (The Equality Timeline Split): When `sum1 == sum2`, the rules uniquely grant Alice the ultimate choice! Your code brilliantly handles this by aggressively branching the universe into BOTH possible futures, recursively solving them, and ruthlessly locking in the `max()` of the two parallel dimensions!
 * - (Optimization Alert / The N^2 Evolution): Your O(N^3) logic is structurally flawless and easily passes the N=500 constraint. However, if N was pushed to 5000, this would crash! You could mathematically evolve this to absolute peak O(N^2) by caching the maximum possible returns for intervals as you build them (similar to Knuth Optimization), completely annihilating the inner `for` loop, but for the given constraints, this DP memoization is beautifully robust!
 * * How it runs:
 * First, we safely allocate our massive 2D memoization matrix `t`, aggressively wiping it to `-1` using a lightning-fast `memset` operation, and forcefully construct our prefix sum vector.
 * We then ignite the recursive `solve` engine, feeding it the absolute boundaries of the array (`0` to `n-1`).
 * Inside the engine, we hit our radar: if the `left` and `right` pointers physically collide, the game mathematically ends, and we instantly return 0!
 * We fiercely check our memo matrix: if `t[left][right] != -1`, we instantly abort the expensive simulation, bypassing thousands of recursive calls, and return the pre-calculated future!
 * If the state is unexplored, we trigger a high-speed sweep, slicing the array at every single possible pivot `i`. We extract `sum1` and `sum2` instantly using our prefix sums.
 * Depending on the strict laws of the game (Bob forcing the smaller half, or Alice choosing on equality), we dive deeper into the valid timeline, accumulating the score.
 * Finally, the exact millisecond the sweep finishes, we permanently lock the absolute `maxscore` into our `t` matrix `t[left][right] = maxscore`, completely securing this timeline before returning to the surface!
 */


class Solution {
    int t[505][505]; 
public:
    int solve(vector<int>& nums, int left, int right, vector<int>& pref) {
        if (left == right) {
            return 0;
        }
        
        if (t[left][right] != -1) return t[left][right];//memoization
        
        int maxscore = 0; 
        
        for (int i = left; i < right; i++) { 
            //current partitions sums
            int sum1 = (left == 0) ? pref[i] : pref[i] - pref[left - 1];
            int sum2 = pref[right] - pref[i];

            if (sum1 == sum2) { //select the one which gives max ouput
                maxscore = max(maxscore, sum1 + max(solve(nums, left, i, pref), solve(nums, i + 1, right, pref)));
            } else if (sum1 > sum2) {//we hzve to select the 2nd partition
                maxscore = max(maxscore, sum2 + solve(nums, i + 1, right, pref));
            } else {//sum1 is minimum
                maxscore = max(maxscore, sum1 + solve(nums, left, i, pref));
            }
        }
        return t[left][right] = maxscore;//store memo
    }
    
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size(); 
        
        memset(t, -1, sizeof(t));
        
        vector<int> pref(n);
        pref[0] = stoneValue[0]; 
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + stoneValue[i]; 
        }
        
        return solve(stoneValue, 0, n - 1, pref);
    }
};
