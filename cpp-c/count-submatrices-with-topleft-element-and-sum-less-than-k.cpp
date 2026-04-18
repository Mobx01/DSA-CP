/*Leetcode ps- 3070. Count Submatrices with Top-Left Element and Sum Less Than k
You are given a 0-indexed integer matrix grid and an integer k.
Return the number of submatrices that contain the top-left element of the grid, and have a sum less than or equal to k.
*/

// Approach: prefix sum
// 1. Observation:
//    We only need submatrices that include the top-left cell (0,0).
//    So every valid submatrix is of the form (0,0) → (i,j).
//
// 2. Build 2D Prefix Sum in-place:
//    Convert grid[i][j] to store sum of submatrix from (0,0) to (i,j).
//    Transition:
//      - If i == 0 → accumulate from left
//      - If j == 0 → accumulate from top
//      - Else → use formula:
//        grid[i][j] = grid[i][j] 
//                     + grid[i][j-1] 
//                     + grid[i-1][j] 
//                     - grid[i-1][j-1]
//
// 3. Counting valid submatrices:
//    For each cell (i,j), grid[i][j] now represents sum of submatrix (0,0)→(i,j).
//    If this sum ≤ k, it is a valid submatrix.
//
// 4. Optimization (important):
//    Since all values are non-negative (given/assumed in problem),
//    prefix sums increase as we move right in a row.
//    So if grid[i][j] > k, we break the loop for that row
//    because further elements will also be > k.
//
// 5. Time Complexity:
//    O(n * m) for prefix sum + O(n * m) for counting
//    → Overall: O(n * m)
//
// 6. Space Complexity:
//    O(1) extra space (in-place modification of grid)

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0; j< m ;j++){
                if(i==0 && j>0) grid[i][j] += grid[i][j-1];
                if(j==0 && i>0) grid[i][j] += grid[i-1][j];
                if(i >0  && j > 0){
                    grid[i][j] += (grid[i][j-1] + grid[i-1][j] - grid[i-1][j-1]);
                }
            }
        }
        int count = 0;
        for(int i = 0 ;i < n;i++){
            for(int j= 0; j<m;j++){
                if(grid[i][j] <= k) count++;
                else break;
            }
        }
        return count;
    }
};
