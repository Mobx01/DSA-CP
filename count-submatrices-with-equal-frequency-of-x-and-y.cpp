/* Leetcode ps:- 3212. Count Submatrices With Equal Frequency of X and Y
Given a 2D character matrix grid, where grid[i][j] is either 'X', 'Y', or '.', return the number of submatrices that contain:
grid[0][0]
an equal frequency of 'X' and 'Y'.
at least one 'X'.
*/
/*
Approach: prefix sum
1. Convert the grid into numeric values:
   - 'X' -> +1
   - 'Y' -> -1
   - '.' -> 0
   This helps in checking if a submatrix has equal number of X and Y.

2. Build a 2D prefix sum matrix `num` to store the cumulative sum of
   these values from (0,0) to (i,j). If the prefix sum at (i,j) is 0,
   it means the number of X and Y in that submatrix are equal.

3. Maintain another prefix sum matrix `xfound` which stores the count
   of 'X' characters from (0,0) to (i,j). This ensures that the submatrix
   contains at least one 'X'.

4. For every cell (i,j), check:
   - num[i][j] == 0  → equal number of X and Y
   - xfound[i][j] > 0 → at least one X exists

5. Count all such valid top-left anchored submatrices.
*/


class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> num(n, vector<int>(m,0));
        vector<vector<int>> xfound(n, vector<int>(m,0));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0; j< m ;j++){

                num[i][j] = grid[i][j] == 'X' ? 1 : (grid[i][j] == 'Y' ? -1 : 0); // assign 1 to x and -1 to y and 0 to . then do prefix sum
                xfound[i][j] = grid[i][j] == 'X' ? 1 : 0;

                if(i==0 && j>0){
                    num[i][j] += num[i][j-1];
                    xfound[i][j] += xfound[i][j-1]; 
                }

                if(j==0 && i>0){
                    num[i][j] += num[i-1][j];
                    xfound[i][j] += xfound[i-1][j]; 
                }

                if(i >0  && j > 0){
                    num[i][j] += (num[i][j-1] + num[i-1][j] - num[i-1][j-1]);
                    xfound[i][j] += (xfound[i][j-1] + xfound[i-1][j] - xfound[i-1][j-1]); 
                }
            }
        }

        int count = 0;
        for(int i = 0 ;i < n;i++){
            for(int j= 0; j<m;j++){
                if(num[i][j] == 0 && xfound[i][j] > 0) count++; // if prefeix sum==0 then it has equal number of X and Y.
            }
        }

        return count;
    }
};
