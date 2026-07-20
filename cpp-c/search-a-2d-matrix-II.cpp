/*Leetcode ps-240. Search a 2D Matrix II
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.*/

/* Approach - Staircase Search / Top-Right Pointer (Time: O(M + N), Space: O(1))
 * Basically, we use the top-right corner as a strategic starting point to continuously eliminate an entire row or column based on a single comparison, navigating through the matrix like a staircase!
 * * Observation:
 * - The matrix is sorted both left-to-right and top-to-bottom. This makes the top-right element uniquely powerful: everything to its left is strictly smaller, and everything below it is strictly larger!
 * - By standing at this specific corner, we can make decisions similar to a Binary Search Tree. If the target is smaller than our current value, we can safely chop off the entire current column and move left. If the target is larger, we can chop off the entire current row and move down.
 * * How it runs:
 * First, we handle the empty matrix edge case, grab our dimensions 'm' and 'n', and plant our pointer precisely at the top-right corner (`row = 0`, `col = n - 1`).
 * Then, we enter a while loop that continues as long as our pointer remains within the strict physical bounds of the grid (`row < m` and `col >= 0`).
 * Next, we evaluate our current cell. If it matches the target, we immediately return true! If the current cell is strictly greater than the target, the target cannot possibly be in this column (since everything below is even larger), so we step left (`col--`). If the current cell is smaller, the target cannot be in this row, so we step down (`row++`).
 * Finally, if our pointer steps completely off the left or bottom edge of the matrix without finding a match, we have mathematically exhausted all possibilities and safely return false!
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Start at the top-right corner
        int row = 0;
        int col = n - 1;
        
        while (row < m && col >= 0) {
            if (matrix[row][col] == target) {
                return true; 
            } 
            else if (matrix[row][col] > target) {
                // Target is smaller, so it can't be in this column. Move left.
                col--;
            } 
            else {
                // Target is larger, so it can't be in this row. Move down.
                row++;
            }
        }
        
        // Target was not found
        return false;
    }
};
