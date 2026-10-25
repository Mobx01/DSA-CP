/*Leetcode ps- 1254. Number of Closed Islands
Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.
Return the number of closed islands.

*/




/* Approach - Recursive Boundary-Propagation DFS / Closed Island Component Validation (Time: O(M * N), Space: O(M * N))
 * Basically, we completely annihilate complex border-sinking preprocessing steps by aggressively propagating out-of-bound failure signals through a 4-way DFS recursion tree, identifying strictly enclosed islands in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Boundary-Enclosure Propagation Invariant (LeetCode 1254 - Number of Closed Islands)! A land component (`0`) is a closed island if and only if **every** cell in that connected component is completely surrounded by water (`1`) and never touches the grid boundary. By returning `false` upon hitting an out-of-bound condition and combining recursive results via logical conjunction (`left && right && up && down`), any boundary contact immediately invalidates the entire component all the way back to the root call.
 * - (Alternative Pattern Comparison): While this inline DFS correctly propagates failure from edge-touching cells, a classic alternative approach is "border-sinking" (iterating over all 4 matrix borders to flood-fill and eliminate any 0s touching the edge first, then counting remaining 0-components). Both run in $O(M \times N)$ time, but border-sinking avoids managing boolean return values across deep recursion trees.
 * - (Auxiliary Stack Efficiency): The recursion stack consumes up to $O(M \times N)$ space in the worst-case scenario for dense grid traversals.
 * * How it runs:
 * First, we initialize grid dimensions `m` and `n` along with our closed island `count = 0`.
 * We ignite a dual nested loop scanning every cell; whenever we encounter unvisited land (`grid[i][j] == 0`), we trigger our `dfs` validator.
 * Inside `dfs`, we mark the current cell as visited (`1`), recursively explore all 4 directions, and return `true` only if all directions are safely enclosed (returning `false` if any branch crosses the boundary). If `dfs` returns `true`, we increment `count`.
 * Finally, we flush the total closed island count to the output stream with absolute mathematical precision at raw silicon speed!
 */




class Solution {
public:
    int m,n;

    bool dfs(vector<vector<int>>& grid , int r ,int c){
        if(r >=m || r<0 || c >= n || c< 0){
            return false; //out of bound
        }

        if(grid[r][c] == 1) return true; //closed from this side

        grid[r][c] = 1; //mark it visited

        bool left = dfs(grid,r,c-1);
        bool right = dfs(grid,r,c+1);
        bool up = dfs(grid,r+1,c);
        bool down = dfs(grid,r-1,c);

        return (left && right && up && down);//if closed from all directino or not;

    }
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int count =0;

        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    if(dfs(grid,i,j) == true){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
