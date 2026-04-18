/*Leetcode ps:- 1727. Largest Submatrix With Rearrangements
You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order.
Return the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally.
*/
/* * APPROACH: Histogram Heights with Column Sorting
 * * 1. Preprocess: For each cell, calculate the number of consecutive 1s 
 * ending at that row (height of the vertical bar). 
 * If matrix[i][j] == 1, matrix[i][j] += matrix[i-1][j].
 * * 2. Optimize: For each row, sort the heights in descending order. 
 * Since we can rearrange columns, we group the tallest bars 
 * together to maximize the submatrix area.
 * * 3. Calculate: For each height h at index j in the sorted row, 
 * the maximum area using that height is h * (j + 1).
 * * Time Complexity: O(N * M log M) | Space Complexity: O(1)
 */

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // store number of 1's above a 1 
        for(int i = 1; i<n;i++){
            for(int j = 0 ; j  < m ;j++){
                if(matrix[i][j]==1){
                    matrix[i][j] += matrix[i-1][j];
                }
            }
    }
        int lsubarray = 0;
        for(int i =0;i<n;i++){
            // sort according to number of 1st above a number.
            sort(matrix[i].begin(),matrix[i].end(),greater<int>());
            for(int j= 0;j<m;j++){
                lsubarray = max(lsubarray, matrix[i][j]*(j+1));
            }
        }
        return lsubarray;
    }
};
