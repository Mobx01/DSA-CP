/*Leetcode ps - 2906. Construct Product Matrix
Given a 0-indexed 2D integer matrix grid of size n * m, we define a 0-indexed 2D matrix p of size n * m as the product matrix of grid if the following condition is met:
Each element p[i][j] is calculated as the product of all elements in grid except for the element grid[i][j]. This product is then taken modulo 12345.
Return the product matrix of grid.*/

/*
Approach:
We need the product of all elements except the current cell.

1. Traverse the matrix in row-major order and store the prefix product
   (product of all previous elements) in prefix[i][j].

2. Traverse the matrix in reverse row-major order and store the postfix
   product (product of all elements after it) in postfix[i][j].

3. For each cell:
   res[i][j] = (prefix[i][j] * postfix[i][j]) % mod

This gives the product of all elements except grid[i][j].

Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int mod = 12345;
        int m = grid.size(),n= grid[0].size();
        vector<vector<int>> res(m,vector<int>(n));
        vector<vector<int>> postfix(m, vector<int>(n));
        vector<vector<int>> prefix(m, vector<int>(n));

    long long prod = 1;

    // prefix product
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            prefix[i][j] = prod;
            prod = (prod * grid[i][j]) % mod;
        }
    }
    prod = 1;
    // postfix product
    for(int i = m-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            postfix[i][j] = prod;
            prod =(prod * grid[i][j]) % mod;
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            res[i][j]= (prefix[i][j]*postfix[i][j]) % mod;
        }
    }
    return res;

    }
};


 /*
        Optimized Approach:

        1. Traverse the matrix in row-major order and store prefix products
           directly in the result matrix.

        2. Traverse the matrix in reverse order while maintaining a postfix
           product and multiply it with the stored prefix.

        This avoids using separate prefix and postfix matrices.

        Time Complexity: O(m * n)
        Space Complexity: O(1) extra (excluding result matrix)
        */
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {

        int mod = 12345;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n));

        long long prod = 1;

        // store prefix in result
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res[i][j] = prod;
                prod = (prod * grid[i][j]) % mod;
            }
        }

        prod = 1;

        // multiply postfix
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                res[i][j] = (res[i][j] * prod) % mod;
                prod = (prod * grid[i][j]) % mod;
            }
        }

        return res;
    }
};
