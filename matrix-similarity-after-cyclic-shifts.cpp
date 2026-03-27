/*Leetcode ps - 2946. Matrix Similarity After Cyclic Shifts
You are given an m x n integer matrix mat and an integer k. The matrix rows are 0-indexed.
The following proccess happens k times:
Even-indexed rows (0, 2, 4, ...) are cyclically shifted to the left.
Odd-indexed rows (1, 3, 5, ...) are cyclically shifted to the right.
Return true if the final modified matrix after k steps is identical to the original matrix, and false otherwise.*/

/*
Approach:
1. Store the original matrix in another matrix (tempmat) so we can compare later.
2. Each row of the matrix is shifted k times:
   - If the row index is EVEN → perform a LEFT circular shift.
   - If the row index is ODD  → perform a RIGHT circular shift.
3. Since shifting a row m times results in the same row,
   we optimize by taking:
        k = k % m
   where m is the number of columns.
4. For every row i:
      Repeat the shift operation k times.
      - Even row:
            save first element
            shift all elements left
            put saved element at the end
      - Odd row:
            save last element
            shift all elements right
            put saved element at the beginning
5. After performing all shifts, compare the modified matrix with the
   original matrix (tempmat).
6. If both matrices are identical → return true.
   Otherwise → return false.
Time Complexity:  O(n * m * k)
Space Complexity: O(n * m)  (for storing the original matrix)
*/

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m =mat[0].size();
        k = k%m;
        vector<vector<int>> tempmat = mat;
        for(int i = 0 ; i < n;i++){
            for(int l = 0; l<k;l++){
                if(i%2==0){
                    int temp  = mat[i][0];
                    for(int j=0;j<m-1;j++){
                        mat[i][j]=mat[i][j+1];
                    }
                    mat[i][m-1] = temp;
                }
                else{
                    int temp= mat[i][m-1];
                    for(int j = m-1 ;j>0;j--){
                        mat[i][j]=mat[i][j-1];
                    }
                    mat[i][0]=temp;
                }
            }
        }
        return  tempmat==mat;
    }
};
