/* Leetcode PS :- 1895  Largest Magic Square
  A k x k magic square is a k x k grid filled with integers such that every row sum, every column sum, and both diagonal sums are all equal
  .The integers in the magic square do not have to be distinct. Every 1 x 1 grid is trivially a magic square.
  Given an m x n integer grid, return the size (i.e., the side length k) of the largest magic square that can be found within this grid.
*/

// Intuition:
// A magic square requires all rows, columns, and both diagonals
// to have the same sum. Checking these sums directly for every
// possible square would be expensive. Using prefix sums allows
// row and column sums to be computed in constant time, making
// it efficient to validate each candidate square.

// Approach:
// 1. Build row-wise prefix sums to get the sum of any row segment in O(1).
// 2. Build column-wise prefix sums to get the sum of any column segment in O(1).
// 3. Iterate over all possible square sizes from largest to smallest.
// 4. For each possible top-left corner of a square:
//    - Check that all rows have the same sum using row prefix sums.
//    - Check that all columns have the same sum using column prefix sums.
//    - Compute both diagonals directly and compare them with the target sum.
// 5. Return the size of the first (largest) square that satisfies all conditions.

// Complexity:
// Time Complexity: O(min(m, n)^3)
// Space Complexity: O(m * n)

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Row prefix sum
        vector<vector<int>> row(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            row[i][0] = grid[i][0];
            for (int j = 1; j < n; j++)
                row[i][j] = row[i][j - 1] + grid[i][j];
        }

        // Column prefix sum
        vector<vector<int>> col(m, vector<int>(n));
        for (int j = 0; j < n; j++) {
            col[0][j] = grid[0][j];
            for (int i = 1; i < m; i++)
                col[i][j] = col[i - 1][j] + grid[i][j];
        }

    
        for (int side = min(m, n); side >= 1; side--) {
            for (int i = 0; i + side <= m; i++) {
                for (int j = 0; j + side <= n; j++) {

                    bool allsame = true;

                    int target = row[i][j + side - 1] - (j > 0 ? row[i][j - 1] : 0);

                    // Checking rows
                    for (int r = i; r < i + side; r++) {
                        int sum = row[r][j + side - 1] - (j > 0 ? row[r][j - 1] : 0);
                        if (sum != target) {
                            allsame = false;
                            break;
                        }
                    }
                    if (!allsame) continue;

                    // Checking columns
                    for (int c = j; c < j + side; c++) {
                        int sum = col[i + side - 1][c] - (i > 0 ? col[i - 1][c] : 0);
                        if (sum != target) {
                            allsame = false;
                            break;
                        }
                    }
                    if (!allsame) continue;

                    // Checking diagonals
                    int diag = 0, antidiag = 0;
                    for (int k = 0; k < side; k++) {
                        diag += grid[i + k][j + k];
                        antidiag += grid[i + k][j + side - k - 1];
                    }

                    if (diag == target && antidiag == target)
                        return side;
                }
            }
        }

        return 1;
    }
};

