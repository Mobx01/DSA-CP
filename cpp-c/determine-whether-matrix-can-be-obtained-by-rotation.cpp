/*Leetcode ps:- 1886. Determine Whether Matrix Can Be Obtained By Rotation
Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.*/


/* approach- check all possible rotation(brute force)
            - for 90 degree rotation-transpose+reverse each row.

*/ 
class Solution {
public:
    void rotate90(vector<vector<int>>& mat){
        int n = mat.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j< n/2 ;j++){
                swap(mat[i][j],mat[i][n-j-1]);
            }
        }

    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i = 0 ; i < 5 ;i++){
            if(mat==target) return true;
            rotate90(mat);
        }
        return false;
    }
};


