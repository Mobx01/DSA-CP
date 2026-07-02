/*Leetcode ps - 3286. Find a Safe Walk Through a Grid
You are given an m x n binary matrix grid and an integer health.
You start on the upper-left corner (0, 0) and would like to get to the lower-right corner (m - 1, n - 1).
You can move up, down, left, or right from one cell to another adjacent cell as long as your health remains positive.
Cells (i, j) with grid[i][j] = 1 are considered unsafe and reduce your health by 1.
Return true if you can reach the final cell with a health value of 1 or more, and false otherwise.*/

/* Approach - DFS with State Pruning / Memoization (space complexity O(m * n))
 * Basically, we explore the grid using Depth-First Search, but to avoid infinite loops and redundant work, we remember the absolute maximum health we had whenever we visited a cell. If we ever arrive at a cell again with the same or less health, we immediately abandon that path!
 * We keep 1 main structure to track this:
 * - 'memo' is a 2D array where 'memo[i][j]' stores the highest health we've historically had upon reaching the cell at (i, j).
 *
 * How it runs:
 * First, we initialize our 'memo' table with -1 and launch our recursive 'solve' function from the top-left corner (0, 0).
 * At each recursive step, we verify we haven't stepped out of bounds. If we are standing on a dangerous cell (1), we decrement our 'health'.
 * Next, we check our survival conditions: if our health drops below 1, we die and return false. If we are currently standing on the final bottom-right cell, we survived and immediately return true!
 * Then comes the pruning magic: we compare our current 'health' against 'memo[i][j]'. If our current health is less than or equal to the recorded record, this path is strictly worse than one we've already explored, so we return false. Otherwise, we overwrite the record with our current higher health!
 * Finally, we launch 4 new recursive calls to explore Up, Down, Left, and Right. Because we use the logical OR (||) operator, if even a single path successfully reaches the end, it will short-circuit and return true all the way up the chain!
 */


class Solution {
public:
    bool solve(int i, int j, vector<vector<int>>& grid, int health, vector<vector<int>>& memo) {
        int m = grid.size();
        int n = grid[0].size();
        
        //Boundary check
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return false;
        }
        
        //Reduce health if the current cell is unsafe
        if (grid[i][j] == 1) {
            health--;
        }
        
        //If health drops below 1, this path is invalid
        if (health < 1) {
            return false;
        }
        
        //If we successfully reach the final cell
        if (i == m - 1 && j == n - 1) {
            return true;
        }
        
        // pruning: 
        // If we have already reached this cell with the same or greater health, there is no need to explore further down this path.
        if (memo[i][j] >= health) {
            return false;
        }
        
        //the new highest health for this cell
        memo[i][j] = health;
        
        //Explore all 4 possible directions
        return solve(i - 1, j, grid, health, memo) ||
               solve(i + 1, j, grid, health, memo) ||
               solve(i, j - 1, grid, health, memo) ||
               solve(i, j + 1, grid, health, memo);
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        
        // Start exploring from (0, 0)
        return solve(0, 0, grid, health, memo);
    }
};
