/*Leetcode ps-37. Sudoku Solver
Write a program to solve a Sudoku puzzle by filling the empty cells.
A sudoku solution must satisfy all of the following rules:
Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

*/


/* Approach - DFS Backtracking / Real-Time Grid Validation (Time: O(9^K) where K is empty cells, Space: O(1) Call Stack)
 * Basically, we aggressively sweep the 9x9 grid hunting for empty cells, violently dropping digits 1 through 9 into the void, and meticulously backtracking the exact millisecond a timeline mathematically collapses to flawlessly crack the Sudoku!
 * * Observation: 
 * - The absolute core of solving Sudoku computationally is the Backtracking decision tree. We don't just blindly generate boards; we mathematically enforce the strict rules of Sudoku at every single insertion to brutally prune dead branches!
 * - (The Subgrid Masterstroke): Isolating which 3x3 box a coordinate belongs to is usually a nightmare of index manipulation. You brilliantly bypassed this by deploying pure integer division: `row / 3 * 3` and `col / 3 * 3`! This mathematically snaps any arbitrary coordinate directly to the absolute top-left anchor of its specific 3x3 sector, flawlessly defining the exact search bounds!
 * - (The Cascade of Failure): The exact millisecond we try all 9 digits in an empty cell and absolutely none of them are valid, the current timeline is structurally doomed. The code aggressively returns `false` outside the digit loop, ruthlessly severing the branch and forcing the previous cell to try a brand new number!
 * - (Optimization Alert): While your `isvalid` sweep is incredibly clean, it burns operations iterating through rows and columns for every single placement attempt. You could completely annihilate this loop by deploying three 2D frequency arrays (or bitmasks) to track the state of rows, cols, and boxes, skyrocketing your validation speed to a blistering O(1)!
 * * How it runs:
 * First, we safely launch our recursive `solve` engine directly from the main function, passing the massive 9x9 board strictly by reference.
 * Inside the engine, we trigger a fierce double `for` loop to scan every single coordinate on the board. The exact millisecond we crash into a `.` (empty cell), the scan completely pauses, and we instantly loop through the characters `'1'` to `'9'`.
 * For every digit candidate, we forcefully fire our `isvalid` radar. If the number violates the row, column, or local 3x3 sector, we instantly reject it. If it is mathematically perfectly safe, we aggressively lock it into the grid (`board[i][j] = d`)!
 * We then violently dive deeper into the timeline by recursively calling `solve(board)`. If that deep dive eventually hits total victory, the short-circuit `if` statement instantly catches it and propagates the `true` signal all the way up the call stack!
 * If the timeline mathematically collapses and returns `false`, we meticulously execute our Backtracking step! We ruthlessly rip the digit off the board, perfectly overwriting it back to a `.`, and seamlessly continue testing the next available digit!
 * Finally, if the massive double loop completes without ever hitting a single `.`, it means the board is flawlessly full, and we confidently return `true` to declare absolute victory!
 */



class Solution {
public:
    bool isvalid(vector<vector<char>>& board,int row,int col,char d){
        for(int i =0;i<9;i++){
            if(board[i][col] == d) return false;
            if(board[row][i] == d) return false;
        }

        int start_i = row/3 * 3;
        int start_j = col/3 * 3;

        for(int k =0;k<3;k++){
            for(int l =0;l<3;l++){
                if(board[start_i + k][start_j +l] == d) {
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.'){
                    for(char d = '1';d <= '9';d++){
                        if(isvalid(board,i,j,d)){
                            board[i][j] = d;
                            if(solve(board)) return true;
                            board[i][j] ='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
