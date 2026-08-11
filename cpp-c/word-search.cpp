/*Leetcode ps-79. Word Search
Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.*/


/* Approach - DFS Backtracking / In-Place Board Mutation (Time: O(N * M * 4^L), Space: O(L) Call Stack)
 * Basically, we aggressively sweep the entire grid hunting for the first letter, and instantly launch a deep-dive recursive search that violently mutates the board in real-time to prevent infinite loops, perfectly backtracking the exact millisecond a path fails!
 * * Observation: 
 * - The absolute nightmare of pathfinding algorithms is revisiting the exact same cell and getting trapped in an infinite loop. Instead of allocating a massive boolean `visited` matrix which aggressively burns O(N*M) auxiliary space, you brilliantly overwrite the active cell directly with a `#` marker! This flawlessly acts as an impenetrable wall for future recursive calls, crushing the space complexity down to strictly the O(L) call stack!
 * - (The Absolute Game-Breaker): The short-circuit OR operator `||` is the ultimate optimizer here. The exact millisecond a directional `solve` returns `true`, the remaining directions are brutally skipped! It completely bypasses thousands of useless recursive calls, instantly collapsing the entire search tree and propagating the victory signal straight to the top!
 * - (Complexity Note): Because we can branch in exactly 3 valid directions (since the cell we came from is blocked off) at every step for a maximum depth of `L` (the word length), the worst-case recursive explosion is mathematically bounded by O(3^L) per valid starting cell!
 * * How it runs:
 * First, we safely trigger a massive double `for` loop to scan the entire `n x m` board. The exact millisecond we crash into a character that flawlessly matches `word[0]`, we ignite the recursive `solve` engine!
 * Inside the engine, we fiercely deploy strict boundary and mismatch checks. If we step off the map, or hit a wrong (or `#` marked) character, we instantly terminate the dead branch. If `k` successfully reaches the absolute end of the word, we have achieved total victory and instantly return `true`!
 * Next, we securely lock our current character into a `temp` variable and brutally overwrite the board space with `#`, mathematically completely sealing it off from being reused in this specific timeline!
 * Then, we aggressively trigger 4 exploratory branches (Down, Left, Right, Up) linked by short-circuit ORs.
 * Finally, the exact millisecond that exploration finishes, we meticulously perform our Backtracking step! We violently pull `temp` and overwrite the `#`, flawlessly resetting the grid state so completely independent future timelines can safely traverse this exact cell!
 */


class Solution {
public:
    bool solve(int i, int j, int k, vector<vector<char>>& board, const string& word) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
        if (board[i][j] != word[k]) return false;
        if (k == word.size() - 1) return true;

        char temp = board[i][j];//mark  visited
        board[i][j] = '#'; 
        bool found = solve(i + 1, j, k + 1, board, word) ||
                     solve(i, j - 1, k + 1, board, word) ||
                     solve(i, j + 1, k + 1, board, word) ||
                     solve(i - 1, j, k + 1, board, word);
                     
        board[i][j] = temp;// can be resued for further opertaions
        return found;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (solve(i, j, 0, board, word)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};


