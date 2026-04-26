/*Leetcode ps - 1559. Detect Cycles in 2D Grid
Given a 2D array of characters grid of size m x n, you need to find if there exists any cycle consisting of the same value in grid.
A cycle is a path of length 4 or more in the grid that starts and ends at the same cell. From a given cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right), if it has the same value of the current cell.
Also, you cannot move to the cell that you visited in your last move. For example, the cycle (1, 1) -> (1, 2) -> (1, 1) is invalid because from (1, 2) we visited (1, 1) which was the last visited cell.
Return true if any cycle of the same value exists in grid, otherwise, return false.*/


/*
 * APPROACH: Depth-First Search (DFS) for Cycle Detection in an Undirected Graph
 * * Core Idea:
 * We can treat the grid as an undirected graph where each cell is a node. 
 * Edges exist between adjacent cells (up, down, left, right) if they share 
 * the same character. To detect a cycle of length 4 or more, we can use DFS.
 * * During DFS, a cycle is found if we visit a node that has already been 
 * visited, BUT we must ensure that this "already visited" node is not the 
 * immediate parent (the cell we just came from in the previous step). If it 
 * is the parent, it's just a 2-step back-and-forth, which is invalid.
 * * Step-by-Step Algorithm:
 * 1. Maintain a 2D boolean `visited` array of the same dimensions as the 
 * grid to keep track of processed cells.
 * 2. Iterate through every cell in the grid. If a cell `grid[i][j]` is 
 * unvisited, initiate a DFS from it.
 * 3. The `cycledfs` function tracks the current cell `(r, c)` and its 
 * immediate parent `(prev_r, prev_c)`.
 * 4. Inside `cycledfs`:
 * - If the current cell `(r, c)` is already marked as `visited`, we have 
 * found a cycle! Return true.
 * - Otherwise, mark the current cell as `visited`.
 * - Iterate through all 4 possible neighbor directions.
 * - For each neighbor `(new_r, new_c)`:
 * a) Check if it is within grid boundaries and matches the character 
 * of the current cell.
 * b) Skip the neighbor if it is the parent cell `(prev_r, prev_c)` 
 * to avoid trivial loops.
 * c) Recursively call `cycledfs` for valid neighbors. If any recursive 
 * call returns true, propagate the true result upwards.
 * 5. If all components are explored and no cycle is detected, return false.
 * * Complexity:
 * - Time Complexity: O(m * n). In the worst case, we visit every cell in 
 * the grid exactly once. 
 * - Space Complexity: O(m * n). This is required for the `visited` array 
 * and the maximum depth of the recursive call stack in the worst-case 
 * scenario (e.g., a snake-like path covering the whole grid).
 */


class Solution {
public:
    int n ,m;
    vector<vector<int>> possibledir {{-1,0},{0,1},{1,0},{0,-1}};
    bool cycledfs(int r , int c ,int prev_r ,int prev_c ,vector<vector<char>>& grid , vector<vector<bool>>& visited){
        if(visited[r][c]) return true;

        visited[r][c] = true;

        for(auto& dir : possibledir ) {
            int new_r = r + dir[0];
            int new_c = c + dir[1];

            if(new_r >= 0 && new_r < n && new_c >= 0 && new_c < m && grid[new_r][new_c] == grid[r][c]){
                if(new_r == prev_r && new_c == prev_c) continue;
                if(cycledfs(new_r , new_c , r, c,grid,visited)) return true;
            }
        }       

        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        n =grid.size();
        m= grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));

        for(int i= 0;i <n;i++){
            for(int j =0;j<m;j++){
                if(!visited[i][j] && cycledfs(i,j,i,j,grid,visited)) return true;
            }
        }
        return false;
    }
};
