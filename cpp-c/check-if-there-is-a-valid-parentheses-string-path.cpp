/*Leetcode ps-2267. Check if There Is a Valid Parentheses String Path
A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:

It is ().
It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
It can be written as (A), where A is a valid parentheses string.
You are given an m x n matrix of parentheses grid. A valid parentheses string path in the grid is a path satisfying all of the following conditions:

The path starts from the upper left cell (0, 0).
The path ends at the bottom-right cell (m - 1, n - 1).
The path only ever moves down or right.
The resulting parentheses string formed by the path is valid.
Return true if there exists a valid parentheses string path in the grid. Otherwise, return false.*/




/* Approach - Top-Down Memoized 3D Dynamic Programming with Parenthesis Balance Tracking (Time: O(M * N * (M + N)), Space: O(M * N * (M + N)))
 * Basically, we completely annihilate exponential recursive search tree explosion by aggressively deploying a 3D memoization table tracking grid coordinates and parenthesis balance states in pristine pseudo-polynomial time!
 * * Observation: 
 * - The absolute core of this architecture is the Parenthesis Balance Invariant (LeetCode 2513/2261/etc. - Check if There is a Valid Path in a Grid II / Valid Parentheses Grid Path)! For a grid path from the top-left `(0, 0)` to the bottom-right `(m - 1, n - 1)` to form a valid balanced parenthesis sequence, two essential conditions must hold:
 *   1. Total path length (`m + n - 1`) must be even, since odd-length paths can never form fully balanced pairs.
 *   2. The running balance (`par`) must never drop below `0` (enforced by your early pruning check `if (par < 0) return false`), and must land precisely at `0` upon reaching the destination.
 * - (Sizing the 3D Memo Table): The maximum possible path length in a $100 \times 100$ grid is $199$. Sizing the third dimension to `205` (`int t[105][105][205]`) perfectly covers all possible parenthesis balance offsets without risking out-of-bounds corruption.
 * - (Fast Pruning Checks): Guarding the entry with checks for grid dimensions parity, start cell (`'('`), and end cell (`')'`) instantly cuts off impossible test cases before recursion even begins.
 * * How it runs:
 * First, we validate early structural constraints (path length parity, starting and ending character validity) and initialize our 3D memoization table `t` with `-1` via `memset`.
 * We ignite our recursive DFS solver starting from `(0, 0)` with an initial parenthesis balance offset.
 * At each cell, we update the balance `par` (`+1` for `'('`, `-1` for `')'`), prune immediately if the balance drops below zero, and check memoized results.
 * We branch into moving either down (`i + 1, j`) or right (`i + 1`), memoizing the boolean success state.
 * Finally, we flush the final boolean path validity result to the output stream with absolute mathematical precision at raw silicon speed!
 */



class Solution {
public:
    int t[105][105][205];
    bool solve(vector<vector<char>>& grid,int i,int j,int par){
        int m = grid.size(),n=grid[0].size();
        if(i >= m || j >= n)return false; //invalid path
        par += (grid[i][j] == '(') ? 1 : -1;
        if(i == m-1 && j == n-1){
            if(par == 0)return true; //valid path 
            else return false;
        }
        if(par < 0) return false;//encounters ) but not ( for balacing it sos not valid
        if(t[i][j][par] != -1)return t[i][j][par];
        
        if(solve(grid,i+1,j,par)){
            return t[i][j][par] = true;
        }
        
        if(solve(grid,i,j+1,par)){
            return t[i][j][par]=true;
        }
        return t[i][j][par] = false;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if((m + n - 1) % 2 == 1) return false; // Path length must be even
        if(grid[0][0] == ')') return false;    // Can't start with closing
        if(grid[m-1][n-1] == '(') return false; // Can't end with opening

        // Much faster way to initialize the 3D array with -1
        memset(t, -1, sizeof(t));
        return solve(grid,0,0,0);
    }
};
