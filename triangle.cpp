/*Leetcode ps- 120. Triangle
Given a triangle array, return the minimum path sum from top to bottom.
For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.*/

class Solution {
public:
    // sum minimum cost of each node from bottom adding up curr[i] +min(bottom[i] ,bottom[i+1]) 
    int minimumTotal(vector<vector<int>>& triangle) {
        //using bottom up - dp
        int n = triangle.size();
        for(int i = n-2 ; i>=0 ;i--){
            for(int j = 0 ; j<=i;j++){
                triangle[i][j] += min(triangle[i+1][j],triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};
