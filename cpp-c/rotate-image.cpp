/*Leetcode ps - 48. Rotate Image
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.*/

//approach - clockwise 90deg rotation  - transpose + (every row reversed)

class Solution {
public:
    vector<vector<int>> transpose(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> transposed(cols, vector<int>(rows));
    
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    transposed[j][i] = matrix[i][j];
                }
            }
            return transposed;
        }
    void rotate(vector<vector<int>>& matrix) {
        matrix = transpose(matrix);
        int n = matrix.size();
        for(int i =0 ;i < n;i++){
            reverse(matrix[i].begin() , matrix[i].end());
        }
    }
};
