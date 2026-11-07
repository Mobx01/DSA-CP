/*leetcode ps- 64. Minimum Path Sum
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.*/





/* Approach - Memoized 2D Dynamic Programming / Minimum Path Sum (Time: O(M * N), Space: O(M * N))
 * Basically, we completely annihilate brute-force exponential grid path exploration by aggressively memoizing subproblem solutions across grid coordinates, computing the minimum path sum in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Minimum Path Sum Invariant (LeetCode 64 - Minimum Path Sum)! From any cell `(i, j)`, the minimum path sum to reach the bottom-right corner is the current cell value `grid[i][j]` plus the minimum of moving down `solve(i + 1, j)` or moving right `solve(i, j + 1)`.
 * - (Overflow Safety Note): Returning `INT_MAX` for out-of-bound states is standard, but when you add `grid[i][j]` to `INT_MAX` (`grid[i][j] + min(...)`), it can cause signed integer overflow if `grid[i][j]` is positive. Using a safe sentinel value like `INT_MAX / 2` prevents overflow while still representing an unreachable infinite cost.
 * - (Optimal Complexity): With $M \times N$ unique states each evaluated in $O(1)$ constant time, the time complexity is strictly $O(M \times N)$ and auxiliary space for the memo table and recursion stack is $O(M \times N)$.
 * * How it runs:
 * First, we initialize our static memoization table `t` using `memset` to `-1`.
 * We launch our recursive DFS from `(0, 0)` toward `(n - 1, m - 1)`.
 * At each step, we check boundaries (returning `INT_MAX` if out of bounds), check base cases at the bottom-right destination, utilize memoized cache hits, and compute the recursive minimum across downward and rightward moves.
 * Finally, we flush the optimal minimum path sum to the output stream with absolute mathematical precision at raw silicon speed!
 */




class Solution {
public:
    int t[201][201];
    int solve(int i,int j,vector<vector<int>>& grid){
        int n = grid.size(),m=grid[0].size();
        if(i >=n || j >=m)return INT_MAX;
        if(i == n-1 && j == m-1)return grid[i][j];

        if(t[i][j] != -1)return t[i][j];

        int ans = grid[i][j] + min(solve(i+1,j,grid),solve(i,j+1,grid));
        return t[i][j] = ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(t,-1,sizeof(t));
        return solve(0,0,grid);
    }
};
