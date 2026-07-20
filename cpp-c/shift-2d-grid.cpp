/*Leetcode ps-1260. Shift 2D Grid
Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.
In one shift operation:
Element at grid[i][j] moves to grid[i][j + 1].
Element at grid[i][n - 1] moves to grid[i + 1][0].
Element at grid[m - 1][n - 1] moves to grid[0][0].
Return the 2D grid after applying shift operation k times.
*/

/* Approach - Simulation / Step-by-Step Shifting (Time: O(K * M * N), Space: O(M * N))
 * Basically, we manually simulate the grid shifting process exactly one step at a time, looping 'k' times while handling the row-to-row wrap-around logic.
 * * Observation: 
 * - Shifting the entire grid exactly 'M * N' times perfectly returns every element to its original starting position. Therefore, we can safely reduce 'k' using modulo `k = k % (m * n)` to completely bypass unnecessary full-cycle shifts!
 * - When shifting by exactly 1 step, there are only three positional cases for an element:
 *   1. It sits at the very bottom-right corner of the grid -> it wraps around to the absolute top-left `[0][0]`.
 *   2. It sits at the far right edge of a normal row -> it wraps around to the start of the next row down `[i+1][0]`.
 *   3. It sits anywhere else -> it simply slides one column to the right `[i][j+1]`.
 * * How it runs:
 * First, we grab the grid dimensions 'm' and 'n', and optimize our shift count 'k'. If 'k' becomes 0, no shifts are needed, so we immediately return the original grid.
 * Then, we create an auxiliary 'ans' grid of the same dimensions and enter a while loop that runs exactly 'k' times.
 * Inside the loop, we sweep through every single coordinate `[i][j]` in the original grid, applying our three wrap-around conditions to correctly place the shifted element into the 'ans' grid.
 * Finally, at the end of each single shift simulation, we overwrite the main 'grid' with 'ans' so the next iteration builds on the newly shifted state. Once all 'k' shifts are simulated, we return 'ans'!
 */

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(),n=grid[0].size();
        k = k%(m*n);
        if(k == 0) return grid;
        vector<vector<int>> ans(m,vector<int>(n));
        while(k--){
            for(int i =0;i<m;i++){
                for(int j =0;j<n;j++){
                    if(j == n-1 && i != m-1){
                        ans[i+1][0] = grid[i][n-1];
                    }else if( j == n-1 && i == m-1){
                        ans[0][0] = grid[i][j];
                    }else{
                        ans[i][j+1] = grid[i][j];
                    }
                }
            }
            grid = ans;
        }
        return ans;
    }
};


/* Approach - 1D Flattening / Direct Index Mapping (Time: O(M * N), Space: O(M * N))
 * Basically, we mentally unroll the 2D grid into a single flat 1D array, mathematically calculate every element's final position after 'k' shifts instantly, and fold it perfectly back into a 2D grid!
 * * Observation: 
 * - Simulating 'k' shifts step-by-step does a ton of unnecessary redundant work. Instead, we can mathematically pinpoint the exact final location in O(1) time per element.
 * - Any 2D matrix can be mapped to a 1D array. An element at row 'i' and column 'j' sits at 1D index `i * n + j`.
 * - In this flat 1D space, shifting by 'k' is just simple addition! We calculate `(flatid + k)`, and use modulo `(m * n)` to perfectly wrap around the end of the grid if necessary.
 * - To convert this new 1D index back to 2D, we just do the reverse operation: dividing by 'n' gives us the new row (`newi`), and modulo by 'n' gives us the new column (`newj`)!
 * * How it runs:
 * First, we grab the dimensions 'm' and 'n', and optimize 'k' using modulo to strip away full grid cycles. If 'k' is 0, we return the original grid immediately.
 * Then, we initialize our 'ans' grid and sweep through the original grid exactly once.
 * Inside the loop, for every single element, we calculate its current 'flatid', instantly shift it to find its 'newflatid', and decode that back into 'newi' and 'newj' coordinates.
 * Finally, we teleport the element directly to its final destination in the 'ans' grid and return the completed grid!
 */



class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(),n=grid[0].size();
        k = k%(m*n);
        if(k == 0) return grid;
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                int flatid = i*n + j;//assume the grid to be flat then the index of the element will be current roe * (row size) + column;
                int newflatid = (flatid+k)%(m*n);

                int newi = newflatid / n; // on which row it will lie
                int newj = newflatid % n; // on which column it will lie
                ans[newi][newj] = grid[i][j];
            }
        }
        return ans;
    }
};
