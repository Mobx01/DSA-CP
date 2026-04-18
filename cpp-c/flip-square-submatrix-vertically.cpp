/*Leetcode ps:-3643. Flip Square Submatrix Vertically
You are given an m x n integer matrix grid, and three integers x, y, and k.
The integers x and y represent the row and column indices of the top-left corner of a square submatrix and the integer k represents the size (side length) of the square submatrix.
Your task is to flip the submatrix by reversing the order of its rows vertically.
Return the updated matrix.*/

// Approach:
// 1. The submatrix starts at (x, y) and has size k × k.
// 2. To reverse it vertically, swap the top rows with the corresponding bottom rows.
// 3. Iterate through only the first half of the rows of the submatrix (k/2).
// 4. For each row i and each column j inside the submatrix:
//      swap grid[i][j] with grid[x + k - 1 - (i - x)][j]
//    where:
//      - (i - x) gives the relative row index inside the submatrix
//      - x + k - 1 - (i - x) gives the mirrored row from the bottom.
// 5. Continue this for all columns from y to y + k - 1.
// 6. After all swaps, the rows of the k × k submatrix are reversed.

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int i = x; i < x + k/2; i++){
        for(int j = y; j < y + k; j++){
            swap(grid[i][j], grid[x + k - 1 - (i - x)][j]);
            }
          }
        return grid;
    }
};
