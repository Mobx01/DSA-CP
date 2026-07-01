/*Leetcode ps - 2812. Find the Safest Path in a Grid
You are given a 0-indexed 2D matrix grid of size n x n, where (r, c) represents:
A cell containing a thief if grid[r][c] = 1
An empty cell if grid[r][c] = 0
You are initially positioned at cell (0, 0). In one move, you can move to any adjacent cell in the grid, including cells containing thieves.
The safeness factor of a path on the grid is defined as the minimum manhattan distance from any cell in the path to any thief in the grid.
Return the maximum safeness factor of all paths leading to cell (n - 1, n - 1).
An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) and (r - 1, c) if it exists.
The Manhattan distance between two cells (a, b) and (x, y) is equal to |a - x| + |b - y|, where |val| denotes the absolute value of val.*/


/* Approach - 2-Pass DP with Binary Search & DFS (space complexity O(N^2))
 * Basically, we split the problem into two parts: first finding out exactly how safe every single cell is, and then systematically guessing the best possible route safety using binary search!
 * We keep 3 main variables/structures to track our state:
 * - 'dist' is a 2D matrix that stores the absolute minimum Manhattan distance from any given cell to the nearest thief (1).
 * - 'low' and 'high' set the boundaries for our binary search to guess the maximum safeness factor.
 * - 'visited' is a 2D boolean matrix used during our recursive DFS to make sure we don't walk in circles.
 *
 * How it runs:
 * First, we immediately check if the start or end point is a thief (1); if so, we can't be safe, so we return 0.
 * Then, we calculate the nearest thief for every cell without using a slow BFS! Instead, we use a clever 2-pass DP trick. The forward pass (top-left to bottom-right) checks distances coming from the top and left. The backward pass (bottom-right to top-left) checks distances coming from the bottom and right. Combined, they perfectly find the minimum distance to any thief!
 * Next, we start our binary search. We know the absolute maximum possible safety can't exceed the safety of our starting or ending cell, so we set 'high' to that minimum bottleneck.
 * For each guess ('mid'), we launch our recursive DFS ('solve') from the top-left corner. The golden rule of our DFS: it is ONLY allowed to step on cells where the 'dist' is greater than or equal to our 'mid' guess!
 * If the DFS reaches the bottom-right corner, our guess was valid! We record it and push 'low' up to try and find an even safer path. If the DFS gets stuck, our guess was too ambitious, so we pull 'high' down!
 */

class Solution {
public:
    int n;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    bool solve(int r, int c, int limit, vector<vector<int>>& dist, vector<vector<bool>>& visited) {
        // If we reached the end, a valid path exists!
        if (r == n - 1 && c == n - 1) return true;
        
        visited[r][c] = true;

        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            
            // traverse valid, unvisited cells
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc] && dist[nr][nc] >= limit) {
                if (solve(nr, nc, limit, dist, visited)) return true;
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return 0;

        // Initialize distances with a very large number
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        // DP TO FIND DISTANCE
        // Forward Pass (Top-Left to Bottom-Right)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                } else {
                    if (i > 0) dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                    if (j > 0) dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
                }
            }
        }

        // Backward Pass (Bottom-Right to Top-Left)
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i < n - 1) dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                if (j < n - 1) dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
            }
        }

        //  BINARY SEARCH & RECURSION 
        // The safest path cannot exceed the safety of the start or end points
        int low = 0;
        int high = min(dist[0][0], dist[n - 1][n - 1]);
        int best_safeness = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2; // guess for the safeness factor
            
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            
            if (dist[0][0] >= mid && solve(0, 0, mid, dist, visited)) {
                best_safeness = mid; // found a path! 
                low = mid + 1;       // Try to find an even safer one
            } else {
                high = mid - 1;      // Path is too no good
            }
        }

        return best_safeness;
    }
};
