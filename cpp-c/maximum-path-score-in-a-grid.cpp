/*Leetcode ps - 3742. Maximum Path Score in a Grid
You are given an m x n grid where each cell contains one of the values 0, 1, or 2. You are also given an integer k.
You start from the top-left corner (0, 0) and want to reach the bottom-right corner (m - 1, n - 1) by moving only right or down.
Each cell contributes a specific score and incurs an associated cost, according to their cell values:

0: adds 0 to your score and costs 0.
1: adds 1 to your score and costs 1.
2: adds 2 to your score and costs 1. ​​​​​​​
Return the maximum score achievable without exceeding a total cost of k, or -1 if no valid path exists.

Note: If you reach the last cell but the total cost exceeds k, the path is invalid.*/


/* 
 * How this works:
 * We're using top-down DP with memoization. 
 * The state is just tracking where we are in the grid (i, j) and how much "cost" we've spent so far (c).
 * 
 * - Figuring out the cost: '0' cells are free, but '1' and '2' cells cost 1. We figure out the 
 *   cost of the current cell and add it to our running total.
 * - Bailing out: If we step off the grid entirely or if our cost blows past 'k', we return a 
 *   massive negative number (-1e9) to flag that this path is a dead end.
 * - The finish line: If we successfully make it to the bottom-right corner, we just return 
 *   the value of that cell.
 * - Exploring: From any valid spot, we try going Right and Down. We recursively check both 
 *   options and pick whichever path gives us the bigger score.
 * - Saving time (Memoization): We use a 3D array 't' to cache our answers. If we end up at 
 *   the same cell with the same accumulated cost later on, we just grab the saved answer 
 *   instead of recalculating the whole branch.
 */


class Solution {
public:
    vector<vector<vector<int>>> t;

    int solve(int i, int j, int c, vector<vector<int>>& grid, int k) {
        //Out of bounds 
        if (i >= grid.size() || j >= grid[0].size()) return -1e9; 
        
        //new cost
        int cc = (grid[i][j] == 0) ? 0 : 1; 
        int nc = c + cc;

        //Exceeded k
        if (nc > k) return -1e9;

        //Reached destination 
        if (i == grid.size() - 1 && j == grid[0].size() - 1) return grid[i][j];
        
        //if already stored
        if (t[i][j][c] != -2) return t[i][j][c];

        //explore
        int r = solve(i + 1, j, nc, grid, k);//right
        int d = solve(i, j + 1, nc, grid, k);//down

        int val = max(r, d);//choosing path giving maximum val

        //invalid paths
        if (val <= -1e8) return t[i][j][c] = -1e9;

        return t[i][j][c] = grid[i][j] + val;//store in memo
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        
        //initialize
        t.assign(n, vector<vector<int>>(m, vector<int>(k + 1, -2)));

        int ans = solve(0, 0, 0, grid, k);
        
        //no valid path 
        return (ans <= -1e8) ? -1 : ans;
    }
};
