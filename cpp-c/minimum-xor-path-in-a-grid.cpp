/*Leetcode ps-3882. Minimum XOR Path in a Grid
You are given a 2D integer array grid of size m * n.
You start at the top-left cell (0, 0) and want to reach the bottom-right cell (m - 1, n - 1).
At each step, you may move either right or down.
The cost of a path is defined as the bitwise XOR of all the values in the cells along that path, including the start and end cells.
Return the minimum possible XOR value among all valid paths from (0, 0) to (m - 1, n - 1).*/




/* Approach - Memoized 3D Dynamic Programming / Grid Path Bitwise XOR Optimization (Time: O(M * N * MAX_XOR), Space: O(M * N * MAX_XOR))
 * Basically, we completely annihilate brute-force path exploration by aggressively memoizing state transitions across grid coordinates and accumulated XOR sums in pseudo-polynomial time!
 * * Observation: 
 * - The absolute core of this architecture is the Path XOR State Invariant (commonly found in grid problems where values are bounded, such as LeetCode 2435 / similar XOR path minimum/maximum cost problems)! Since the cell values are bounded (implying the accumulated XOR sum `x` stays within a restricted domain like $< 1024$), we can define our DP state as `t[i][j][x]`, representing the minimum cost from cell `(i, j)` given an incoming accumulated XOR of `x`.
 * - (Variable Naming Note): Notice that `m` and `n` are swapped between `minCost` (`n` = rows, `m` = cols) and `solve` (`m` = rows, `n` = cols). While the dimensions match correctly when allocating `t`, keeping variable roles consistent improves readability.
 * - (Space-Time Complexity): With grid dimensions $M \times N$ and a maximum XOR range of 1024, the state space and execution time scale efficiently within standard competitive programming limits.
 * * How is it executed:
 * First, we initialize our 3D memoization table `t` of size $N \times M \times 1024$ with `-1`.
 * We launch our recursive DFS from `(0, 0)` with an initial XOR sum of `0`.
 * At each step, we check boundaries (returning `INT_MAX` if out of bounds), check memoized results, update our accumulated XOR sum with `grid[i][j]`, and recursively compute the minimum cost of moving right or down.
 * Finally, we flush the optimal minimum XOR path cost to the output stream with absolute mathematical precision at raw silicon speed!
 */




class Solution {
public:
    vector<vector<vector<int>>> t;
    
    int solve(vector<vector<int>>& grid, int i, int j, int x) {
        int m = grid.size(), n = grid[0].size();
        
        // out of bounds
        if (i < 0 || i >= m || j < 0 || j >= n) return INT_MAX;

        // memoization 
        if (t[i][j][x] != -1) return t[i][j][x];

        //current XOR sum including this cell
        int cur = x ^ grid[i][j];
        
        //reached the destination
        if (i == m - 1 && j == n - 1) return cur;

        //explore
        return t[i][j][x] = min(solve(grid, i + 1, j, cur), solve(grid, i, j + 1, cur));
    }
    
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        t = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(1024, -1)));
        
        return solve(grid, 0, 0, 0);
    }
};
