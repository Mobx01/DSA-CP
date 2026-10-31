/*Leetcode ps-3665. Twisted Mirror Path Count
Given an m x n binary grid grid where:

grid[i][j] == 0 represents an empty cell, and
grid[i][j] == 1 represents a mirror.
A robot starts at the top-left corner of the grid (0, 0) and wants to reach the bottom-right corner (m - 1, n - 1). It can move only right or down. If the robot attempts to move into a mirror cell, it is reflected before entering that cell:

If it tries to move right into a mirror, it is turned down and moved into the cell directly below the mirror.
If it tries to move down into a mirror, it is turned right and moved into the cell directly to the right of the mirror.
If this reflection would cause the robot to move outside the grid boundaries, the path is considered invalid and should not be counted.

Return the number of unique valid paths from (0, 0) to (m - 1, n - 1).

Since the answer may be very large, return it modulo 109 + 7.

Note: If a reflection moves the robot into a mirror cell, the robot is immediately reflected again based on the direction it used to enter that mirror: if it entered while moving right, it will be turned down; if it entered while moving down, it will be turned right. This process will continue until either the last cell is reached, the robot moves out of bounds or the robot moves to a non-mirror cell.*/




/* Approach - Memoized 3D Dynamic Programming with Direction-State Mirror Reflection / Directed Unique Paths with Mirrors (Time: O(M * N), Space: O(M * N))
 * Basically, we completely annihilate brute-force path tracing by aggressively tracking directional state and mirror reflections across grid coordinates, computing directed unique paths in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Directional Reflection Invariant! In grid problems where certain cells contain mirrors (`grid[i][j] == 1`) that force a 90-degree turn, the path outcome depends not just on coordinates `(i, j)` but also on the direction of entry / last move (`d`). Using a 3D memoization table `t[i][j][d]` (where `d` distinguishes whether the previous move was right or down) perfectly captures this state dependency.
 * - (Modulo Arithmetic & Safety): Applying `MOD = 1e9 + 7` at each addition step prevents integer overflow while handling large path counts.
 * - (Initial Direction Nuance): Ensure that the initial direction parameter `d = 0` passed from `uniquePaths` correctly aligns with how the entry into the top-left cell `(0, 0)` is defined by the problem statement (especially if `(0, 0)` itself can contain a mirror).
 * * How it runs:
 * First, we initialize our 3D memoization table `t` of size $M \times N \times 2$ with `-1`.
 * We launch our recursive DFS from `(0, 0)` with initial direction state `0`.
 * At each step, we check base cases (reaching destination returns `1`, out of bounds returns `0`), check memoized results, evaluate whether the cell is a mirror (forcing a turn) or a free cell (branching both ways under modular arithmetic), and cache the result.
 * Finally, we flush the optimal valid path count modulo `1e9 + 7` to the output stream with absolute mathematical precision at raw silicon speed!
 */




class Solution {
public:
    vector<vector<vector<long long>>> t;
    int MOD = 1e9 + 7; 

    long long solve(int i, int j, vector<vector<int>>& grid, int d){
        int m = grid.size(), n = grid[0].size();

        if(i == m-1 && j == n-1) return 1; //pne valid path founded
        if(i >= m || j >= n) return 0;//invalid path

        if(t[i][j][d] != -1) return t[i][j][d];//memo
        
        long long ans = 0;
        if(grid[i][j] == 1){ // mirror
            if(d == 0){ // last move was right
                ans = solve(i+1, j, grid, 1);
            } else { // last move was down
                ans = solve(i, j+1, grid, 0);
            }
        } else {// if not a mirror procced with both moves
            ans = (solve(i+1, j, grid, 1) + solve(i, j+1, grid, 0)) % MOD;
        }
        
        return t[i][j][d] = ans;
    }
    
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        t.assign(m, vector<vector<long long>>(n, vector<long long>(2, -1)));
        
        return solve(0, 0, grid, 0) % MOD;
    }
};
