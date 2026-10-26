/*Leetcode ps-3619. Count Islands With Total Value Divisible by K
You are given an m x n matrix grid and a positive integer k. An island is a group of positive integers (representing land) that are 4-directionally connected (horizontally or vertically).
The total value of an island is the sum of the values of all cells in the island.
Return the number of islands with a total value divisible by k.*/




/* Approach - DFS Component Remainder Accumulation / Divisible Island Counting (Time: O(M * N), Space: O(M * N))
 * Basically, we completely annihilate brute-force component sum overflows by aggressively accumulating running remainders modulo `k` during a 4-way DFS traversal, identifying islands whose total sum is divisible by `k` in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Modular Component Sum Invariant! Instead of accumulating large unconstrained sums that risk integer overflow before checking divisibility, taking `grid[r][c] % k` at each cell and combining them via modular addition `(totalRemainder + dfs(...)) % k` safely and efficiently computes whether the entire connected component sum is a multiple of `k`.
 * - (In-Place State Mutation): Marking visited cells as `-1` (`grid[r][c] = -1`) avoids allocating an auxiliary `visited` matrix, keeping auxiliary overhead strictly bounded by the recursion stack space ($O(M \times N)$ in the worst-case grid layout).
 * - (Optimal Time Efficiency): Every cell is visited at most a constant number of times during the DFS traversal, guaranteeing strict $O(M \times N)$ time complexity.
 * * How it runs:
 * First, we validate grid bounds and initialize our `divisibleIslandsCount` to `0`.
 * We ignite a dual nested loop scanning every cell; whenever we encounter unvisited land (`grid[r][c] > 0`), we trigger our `dfs` remainder accumulator.
 * Inside `dfs`, we mark the cell as visited (`-1`), take its value modulo `k`, recursively sum the remainders of all 4 connected neighbors under modular arithmetic, and return the final component remainder.
 * If the returned remainder equals `0`, we increment our `divisibleIslandsCount`.
 * Finally, we flush the total divisible island count to the output stream with absolute mathematical precision at raw silicon speed!
 */




class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        int divisibleIslandsCount = 0;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] > 0) {
                    int islandRemainder = dfs(grid, r, c, m, n, k);
                    if (islandRemainder == 0) {
                        divisibleIslandsCount++;
                    }
                }
            }
        }
        return divisibleIslandsCount;
    }

private:
    int dfs(vector<vector<int>>& grid, int r, int c, int m, int n, int k) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] <= 0) {
            return 0;
        }

        int totalRemainder = grid[r][c] % k;
        grid[r][c] = -1; // Mark as visited in-place

        totalRemainder = (totalRemainder + dfs(grid, r - 1, c, m, n, k)) % k; // Up
        totalRemainder = (totalRemainder + dfs(grid, r + 1, c, m, n, k)) % k; // Down
        totalRemainder = (totalRemainder + dfs(grid, r, c - 1, m, n, k)) % k; // Left
        totalRemainder = (totalRemainder + dfs(grid, r, c + 1, m, n, k)) % k; // Right

        return totalRemainder;
    }
};
