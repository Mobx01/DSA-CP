/*Leetcode ps:- 1582. Special Positions in a Binary Matrix
Given an m x n binary matrix mat, return the number of special positions in mat.
A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).*/

/*you first create two arrays to store the total count of 1s for every row and every column. You scan the matrix once to fill these arrays, essentially "tagging" 
how many 1s live in each row and column. Finally, you scan the matrix a second time; a cell is "special" only if it contains a 1 and its corresponding row and 
column counts are both exactly 1, meaning that specific 1 is the sole occupant of its entire horizontal and vertical line.*/


class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size() ;
        vector<int> trackcol(cols,0);
        vector<int> trackrow(rows, 0);

        for(int i = 0 ; i < rows ;i++){
            for(int j = 0 ; j < cols ;j++){
                if(mat[i][j]==1){
                     trackcol[j]++ ;
                     trackrow[i]++;
                }
            }
        }
        int count =0;
        for(int i = 0 ; i < rows ;i++){
            for(int j = 0 ; j < cols ;j++){
                if(mat[i][j]==1 && trackcol[j] == 1 && trackrow[i]==1){
                    count++;                    
                }
            }
        }
        return count;
    }
};
