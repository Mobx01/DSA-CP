/*Leetcode ps- 3567. Minimum Absolute Difference in Sliding Submatrix
You are given an m x n integer matrix grid and an integer k.
For every contiguous k x k submatrix of grid, compute the minimum absolute difference between any two distinct values within that submatrix.
Return a 2D array ans of size (m - k + 1) x (n - k + 1), where ans[i][j] is the minimum absolute difference in the submatrix whose top-left corner is (i, j) in grid.
Note: If all elements in the submatrix have the same value, the answer will be 0.
A submatrix (x1, y1, x2, y2) is a matrix that is formed by choosing all cells matrix[x][y] where x1 <= x <= x2 and y1 <= y <= y2.*/


/* Approach:
1. Iterate over every possible k × k subgrid in the matrix.
2. For each subgrid, collect all k*k elements into a temporary vector.
3. Sort the vector so that minimum differences can be checked between adjacent elements.
4. Traverse the sorted vector and find the minimum difference between distinct elements.
5. Store the minimum difference in the answer matrix (store 0 if all elements are equal).

Time Complexity: O((m*n) * k^2 log(k^2))*/
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m-k+1, vector<int>(n-k+1,0));

        for(int i = 0; i <= m-k; i++){
            for(int j = 0; j <= n-k; j++){
                vector<int> sub;
                for(int r = i; r < i+k; r++){
                    for(int c = j; c < j+k; c++){
                        sub.push_back(grid[r][c]);
                    }
                }
                sort(sub.begin(), sub.end());
                int mindiff = INT_MAX;
                for(int t = 0; t < sub.size()-1; t++){
                    if(sub[t+1]!=sub[t])
                    mindiff = min(mindiff, sub[t+1] - sub[t]);
                }
                ans[i][j] = mindiff != INT_MAX ? mindiff : 0;
            }
        }

        return ans;
    }
};
