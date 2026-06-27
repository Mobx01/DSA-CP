/*Leetcode ps - 73. Set Matrix Zeroes
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.*/


/* Approach - Tracking with Hash Sets (space complexity O(m + n))
 * Basically, we do an initial sweep of the matrix to record exactly which rows and columns contain zeros, and then use that recorded information to overwrite the matrix in a targeted way.
 * We keep 2 main structures to track this: 
 * - 'row' set remembers every unique row index that contains at least one 0.
 * - 'col' set remembers every unique column index that contains at least one 0.
 *
 * How it runs:
 * First, we do a complete scan of the entire matrix. Whenever we encounter a 0, we insert its row index 'i' into our 'row' set and its column index 'j' into our 'col' set. (Since they are sets, they automatically prevent duplicate entries!).
 * Next, we iterate through every row index saved in our 'row' set, and overwrite every single cell in those specific rows to 0.
 * Finally, we iterate through every column index saved in our 'col' set, and overwrite every single cell in those specific columns to 0.
 */

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> row,col;
        int m = matrix.size(),n = matrix[0].size();
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(int i : row){
            for(int j=0;j<n;j++){
                matrix[i][j] =0;
            }
        }
        for(int j : col){
            for(int i=0;i<m;i++){
                matrix[i][j] =0;
            }
        }
    }
};



/* Approach - In-Place Matrix Marking (space complexity O(1))
 * Basically, we achieve constant space by using the matrix's own first row and first column to keep track of which rows and columns need to be zeroed out, instead of creating separate external sets.
 * We keep 2 main boolean variables to track our edge cases:
 * - 'firstRowZero' remembers if the very first row originally had any zeros before we started overwriting it to use as a tracker.
 * - 'firstColZero' remembers if the very first column originally had any zeros.
 *
 * How it runs:
 * First, we scan just the first row and first column to see if they contain any zeros naturally, updating our two boolean flags so we don't forget this information later.
 * Then, we loop through the rest of the inner matrix. Whenever we find a 0 at cell (i, j), we flag the start of its row (matrix[i][0] = 0) and the start of its column (matrix[0][j] = 0).
 * Next, we do a second pass through the inner matrix (starting from index 1). We check our markers: if a cell's row-marker or column-marker is 0, we overwrite that cell to 0!
 * Finally, we look back at our initial boolean flags. If 'firstRowZero' is true, we zero out the entire first row. If 'firstColZero' is true, we zero out the entire first column!
 */


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(),n = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;
        //Check if the first row or column originally had zeroes
        for(int i = 0; i < m; i++) {
            if(matrix[i][0] == 0) firstColZero = true;
        }
        for(int j = 0; j < n; j++) {
            if(matrix[0][j] == 0) firstRowZero = true;
        }

        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    matrix[0][j]=0;//mark starting of the colmn to zeroed
                    matrix[i][0]=0;//mark starting of the row to be zeroed
                }
            }
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if(firstColZero) {
            for(int i = 0; i < m; i++) matrix[i][0] = 0;
        }
        if(firstRowZero) {
            for(int j = 0; j < n; j++) matrix[0][j] = 0;
        }
    }
};
