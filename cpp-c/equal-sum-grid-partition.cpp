/*Leetcode ps - 3546. Equal Sum Grid Partition 
You are given an m x n matrix grid of positive integers. Your task is to determine if it is possible to make either one horizontal or one vertical cut on the grid such that:
Each of the two resulting sections formed by the cut is non-empty.
The sum of the elements in both sections is equal.
Return true if such a partition exists; otherwise return false*/

/*
 * APPROACH: Prefix/Suffix Sums
 * Simplifies the 2D grid by treating it as 1D arrays to find a clean split.
 * * 1. Test Horizontal Cuts (Rows):
 * - Compress each row into a single number (its total sum).
 * - Compare running totals from the top-down (prefix) against bottom-up (suffix).
 * - If they match at any point, the top half equals the bottom half -> return true.
 * * 2. Test Vertical Cuts (Columns):
 * - If rows fail, compress each column into a single number (its total sum).
 * - Compare running totals from left-to-right (prefix) against right-to-left (suffix).
 * - If they match at any point, the left half equals the right half -> return true.
 * * 3. Default:
 * - If neither rows nor columns yield a match, return false.
 */

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return false;
        int m = grid[0].size();
        
        vector<long long> rowsum(n, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                rowsum[i] += grid[i][j];
            }
        }
        
        vector<long long> presum(n, 0);
        vector<long long> postsum(n, 0);
        
        presum[0] = rowsum[0];
        for(int i = 1; i < n; i++) {
            presum[i] = presum[i-1] + rowsum[i]; 
        }
        
        for(int i = n - 2; i >= 0; i--) {
            postsum[i] = postsum[i+1] + rowsum[i+1]; 
        }
        
        for(int i = 0; i < n - 1; i++) {
            if(postsum[i] == presum[i]) return true;
        }

        vector<long long> colsum(m, 0);
        for(int j = 0; j < m; j++) {
            for(int i = 0; i < n; i++) {
                colsum[j] += grid[i][j];
            }
        }
        
        presum.assign(m, 0);
        postsum.assign(m, 0);
        
        presum[0] = colsum[0];
        for(int j = 1; j < m; j++) {
            presum[j] = presum[j-1] + colsum[j];
        }
        
        for(int j = m - 2; j >= 0; j--) {
            postsum[j] = postsum[j+1] + colsum[j+1];
        }
        
        for(int j = 0; j < m - 1; j++) {
            if(postsum[j] == presum[j]) return true;
        }
        
        return false;
    }
};
