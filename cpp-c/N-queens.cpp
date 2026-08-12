/*Leatcode ps-51. N-Queens
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.*/


/* Approach - DFS Backtracking / Row-by-Row Placement (Time: O(N!), Space: O(N^2))
 * Basically, we aggressively drop queens onto the board row by row, violently pruning dead timelines the exact millisecond a queen is threatened, and meticulously backtracking to flawlessly capture every single valid N-Queens configuration!
 * * Observation: 
 * - By strictly advancing our recursion row by row (`row + 1`), we mathematically guarantee that no two queens will EVER share the same row! This completely annihilates the need to ever check for horizontal threats!
 * - (The Absolute Masterstroke): Look closely at your `safe` function! It ONLY looks UP! Because the bottom rows are a completely empty void (we haven't placed anything there yet), checking downwards is mathematically useless! It ruthlessly sweeps strictly the vertical column, upper-left diagonal, and upper-right diagonal, instantly slashing the verification overhead in half!
 * - (Optimization Alert / The O(1) Upgrade): While your `safe` loop works flawlessly, it burns O(N) time for every single placement attempt. You could instantly upgrade this to a blistering O(1) by completely completely dropping the loop and deploying three O(N) frequency arrays (or bitmasks)! By mathematically tracking `col`, `row + col` (anti-diagonals), and `row - col` (main diagonals), you can definitively prove safety in constant time and skyrocket your runtime to absolute peak efficiency!
 * * How it runs:
 * First, we safely initialize our massive `ans` matrix and forge our `temp` board as a pristine `n x n` grid of `.` void characters. We then ignite our recursive `solve` engine starting exactly at `row = 0`.
 * Inside the engine, we fiercely check our absolute base case: if `row == n`, we have successfully navigated the entire minefield! We aggressively push the perfectly completed `temp` board directly into `ans` and instantly return!
 * If we are still in the trenches, we trigger a high-speed horizontal sweep across every single `col` in the current row. For every slot, we forcefully deploy our `safe` radar.
 * If the slot is mathematically perfectly safe, we aggressively drop a `'Q'` into the void, securely lock it in, and violently dive deeper into the timeline by advancing strictly to `solve(row + 1)`.
 * The exact millisecond that timeline collapses (whether by reaching a dead end or achieving victory), we meticulously execute our Backtracking step! We ruthlessly rip the `'Q'` off the board, completely overwrite it with a `.`, and flawlessly reset the grid state so completely independent future timelines can safely test the next available column!
 */


class Solution {
public:
  bool safe(int row,int col, vector<string>& temp,int n){
      //vertical check
      for(int i = 0 ; i<row;i++){
        if(temp[i][col] == 'Q')return false;
      }
      //upper left diag
      for(int r = row-1,c=col-1;r >= 0 && c >= 0;r--,c--){
        if(temp[r][c] == 'Q')return false;
      }
      //upper right
      for(int r = row -1,c = col+1;r >= 0 && c <n;r--,c++){
        if(temp[r][c] == 'Q')return false;
      }
      return true;
  }
   void solve(int row,vector<vector<string>>& ans, vector<string>& temp,int n){
       if(row == n){//all placed safely
          ans.push_back(temp);
          return;
       }

       //place on each col if safe
       for(int col =0;col < n;col++){
          if(safe(row,col,temp,n)){
              temp[row][col] = 'Q';//place the queen if safe
              solve(row+1,ans,temp,n);//recr
              temp[row][col] = '.';//backtrack
          }
       }
   }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n, string(n, '.'));
        solve(0,ans,temp,n);
        return ans;
    }
};
