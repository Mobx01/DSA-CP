/*Leetcode ps - 3418. Maximum Amount of Money Robot Can Earn
You are given an m x n grid. A robot starts at the top-left corner of the grid (0, 0) and wants to reach the bottom-right corner (m - 1, n - 1). The robot can move either right or down at any point in time.
The grid contains a value coins[i][j] in each cell:
If coins[i][j] >= 0, the robot gains that many coins.
If coins[i][j] < 0, the robot encounters a robber, and the robber steals the absolute value of coins[i][j] coins.
The robot has a special ability to neutralize robbers in at most 2 cells on its path, preventing them from stealing coins in those cells.
Note: The robot's total coins can be negative.
Return the maximum profit the robot can gain on the route.*/

// using dp
// if coin is positive simply add and explore . if coin in negative then explore by both skiping it and considering it then choose which gives maximun output

/*
 * Approach: Recursion + Memoization (Top-Down DP)
 * How it works:
 * - State: We keep track of our row (i), col (j), and skips left (neut).
 * - Base Cases: 
 * 1. Step out of bounds? Return a huge negative number (INT_MIN) so we don't take that path.
 * 2. Reached the end? Take the coins (or use a skip if it's a robber and we still have one).
 *
 * The Choices:
 * At any cell, our default move is to just accept the cell's value (whether it's good or a robber) 
 * and see the max profit we'd get going down or right.
 * * BUT, if we land on a robber (< 0) and still have skips left, we check a second option: 
 * What if we use a skip to make the penalty 0, and then go down or right? 
 * We just return whichever option gives us the most money.
 *
 * Saving time:
 * Lots of paths overlap. To avoid doing the same math twice, we save our max profit for each 
 * cell and remaining skips in a 3D array `t`. If we've seen this exact situation before, 
 * just return the saved answer!
 */



class Solution {
public:
    int t[501][501][3]; // memoization;
    int n ,m;
    int solve(vector<vector<int>>& coins , int i , int j, int neut){
            if(i == n-1 && j == m-1) {
                if(coins[i][j] < 0 && neut>0)return 0; // neutralized the robber 

                return coins[i][j]; // return last value 
            }
            if(i>= n || j>=m) return INT_MIN;

            if(t[i][j][neut] != INT_MIN) return t[i][j][neut];

            int noneut = coins[i][j] + max(solve(coins,i+1,j,neut) ,solve(coins,i,j+1,neut)); // no neutrilization is performed

            //check for skip if we can neutrilize
            int skip = INT_MIN; 
            if(coins[i][j] < 0 && neut>0) {
                skip = max(solve(coins,i+1,j,neut-1) ,solve(coins,i,j+1,neut-1));
            }
            return t[i][j][neut] =  max(noneut , skip);
            
    }
    int maximumAmount(vector<vector<int>>& coins) {
        n = coins.size();
        m = coins[0].size();

        for(int i =0 ;i< 501;i++){
            for(int j = 0; j<501 ;j++){
                for(int k = 0 ; k< 3;k++){
                    t[i][j][k] = INT_MIN; 
                }
            }
        }
        return solve(coins,0,0,2);
    }
};
