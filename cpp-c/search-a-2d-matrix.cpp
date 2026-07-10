/*Leetcode ps-74. Search a 2D Matrix
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.*/

/* Approach - Double Binary Search (Time: O(log M + log N), Space: O(1))
 * Basically, we perform two distinct binary searches: one on the rows to find the correct range, and a second one within that specific row to find the exact target.
 * * Observation: 
 * - Because the matrix is sorted such that the last element of a row is strictly smaller than the first element of the next row, every single row represents a distinct, non-overlapping mathematical range.
 * - If the target exists in the matrix, it absolutely MUST be located in the single row where the target is greater than or equal to the row's first element, and less than or equal to the row's last element.
 * * How it runs:
 * First, we establish our vertical binary search boundaries: 'l' is the top row (0) and 'r' is the bottom row (matrix.size() - 1).
 * Then, we guess a middle row ('mid'). We instantly check if the target falls within this row's bounds (`target >= matrix[mid][0] && target <= matrix[mid][n - 1]`). If it does, we trigger our helper `binarySearch` function to sweep just that row and return the final true/false result!
 * Finally, if the target doesn't fit in the current row, we pivot. If the target is strictly smaller than the first element of the 'mid' row, we know the target must be in a higher row, so we pull our bottom boundary up (`r = mid - 1`). If it's larger, we push our top boundary down (`l = mid + 1`).
 */

class Solution {
public:
    bool binarySearch(const vector<int>& row, int n, int x) {
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (row[mid] == x)
                return true;
            else if (row[mid] < x)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int n = matrix[0].size();
        int l = 0;
        int r = matrix.size() - 1; 

        while (l <= r) { 
            int mid = l + (r - l) / 2;
            
            // Check if target is within the current row's range
            if (target >= matrix[mid][0] && target <= matrix[mid][n - 1]) {
                return binarySearch(matrix[mid], n, target);
            }
            // target is smaller than the first element of the row, search upper half
            else if (target < matrix[mid][0]) {
                r = mid - 1;
            } 
            // target is larger than the last element of the row, search lower half
            else {
                l = mid + 1;
            }
        }
        return false;
    }
};
