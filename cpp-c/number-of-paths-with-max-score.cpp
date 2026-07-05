/*Leetcode ps- 1301. Number of Paths with Max Score
You are given a square board of characters. You can move on the board starting at the bottom right square marked with the character 'S'.
You need to reach the top left square marked with the character 'E'. The rest of the squares are labeled either with a numeric character 1, 2, ..., 9 or with an obstacle 'X'. In one move you can go up, left or up-left (diagonally) only if there is no obstacle there.
Return a list of two integers: the first integer is the maximum sum of numeric characters you can collect, and the second is the number of such paths that you can take to get that maximum sum, taken modulo 10^9 + 7.
In case there is no path, return [0, 0].*/

/* Approach - DFS with Memoization (2D DP) (space complexity O(N^2))
 * Basically, we use recursion with memoization to explore all valid paths from the bottom-right start ('S') to the top-left end ('E'). At every step, we simultaneously track both the absolute maximum score we can get and exactly how many distinct paths achieve that exact score!
 * We keep a few main structures/variables to track this:
 * - 't' is our 2D memoization table. Instead of just a single number, every cell stores a pair: {highest_score, number_of_ways_to_get_it}.
 * - 'up', 'left', and 'diag' variables dynamically track the results of our three legal moves.
 *
 * How it runs:
 * First, we initialize our memoization table 't' with -1s and launch our recursive 'solve' function from the bottom-right corner (n-1, n-1).
 * At each cell, we check our base cases: if we hit an obstacle ('X') or go out of bounds, we return {0, 0} because it's a dead end. If we successfully land on the target ('E'), we return {0, 1} because we scored nothing on this specific square, but we successfully found 1 valid path!
 * Next, if we haven't already solved this cell, we recursively ask our three valid neighbors (Up, Left, Up-Left) for their best score and path counts. Crucially, if a neighbor actually found a valid path to the end (paths > 0), we add our current cell's numeric value to its returned score.
 * Then comes the combination step: we compare the final scores offered by all three directions. We identify the absolute highest score, and we sum up the path counts of EVERY direction that managed to tie for that exact winning score (because multiple routes might yield the same max loot).
 * Finally, we apply our modulo to the combined paths to prevent integer overflow, save this optimal {bestScore, bestPaths} pair into our memo table 't', and return it up the chain!
 */


class Solution {

    int n;
    int MOD = 1e9 + 7;
    vector<vector<pair<int, int>>> t;

    int getIntFromChar(char ch) {
        return ch != 'S' ? ch - '0' : 0;
    }

    bool isValid(int i, int j, vector<string>& board) {
        return i >= 0 && i < n && j >= 0 && j < n && board[i][j] != 'X';
    }

    pair<int, int> solve(int i, int j, vector<string>& board) {
        if (board[i][j] == 'E') 
            return {0, 1};   // reached end - no more coins, but found one path that reaches end - {0, 1}
        if (board[i][j] == 'X') 
            return {0, 0};   // dead end

        if (t[i][j] != make_pair(-1, -1))
            return t[i][j];

        int upScore = 0,   upPaths = 0;
        int leftScore = 0, leftPaths = 0;
        int diagScore = 0, diagPaths = 0;
        char ch = board[i][j];

        if (isValid(i - 1, j, board)) {
            auto [score, paths] = solve(i - 1, j, board);
            upScore = score;
            upPaths = paths;
            if (upPaths > 0)
                upScore += getIntFromChar(ch);
        }
        if (isValid(i, j - 1, board)) {                 // move left
            auto [score, paths] = solve(i, j - 1, board);
            leftScore = score;
            leftPaths = paths;
            if (leftPaths > 0)
                leftScore += getIntFromChar(ch);
        }
        if (isValid(i - 1, j - 1, board)) {             // move up-left (diagonal)
            auto [score, paths] = solve(i - 1, j - 1, board);
            diagScore = score;
            diagPaths = paths;
            if (diagPaths > 0)
                diagScore += getIntFromChar(ch);
        }

        int bestScore, bestPaths;
        if (upScore == leftScore && leftScore == diagScore) {
            bestScore = upScore;
            bestPaths = upPaths + leftPaths + diagPaths;
        } else if (upScore == leftScore) {
            bestScore = upScore;
            bestPaths = upPaths + leftPaths;
            if (diagScore > bestScore || (diagScore == bestScore && diagPaths > bestPaths)) {
                bestScore = diagScore; bestPaths = diagPaths;
            }
        } else if (leftScore == diagScore) {
            bestScore = leftScore;
            bestPaths = leftPaths + diagPaths;
            if (upScore > bestScore || (upScore == bestScore && upPaths > bestPaths)) {
                bestScore = upScore; bestPaths = upPaths;
            }
        } else {
            bestScore = upScore; bestPaths = upPaths;
            if (leftScore > bestScore || (leftScore == bestScore && leftPaths > bestPaths)) {
                bestScore = leftScore; bestPaths = leftPaths;
            }
            if (diagScore > bestScore || (diagScore == bestScore && diagPaths > bestPaths)) {
                bestScore = diagScore; bestPaths = diagPaths;
            }
        }

        t[i][j] = {bestScore, bestPaths % MOD};
        return t[i][j];
    }

public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        
        t.assign(n, vector<pair<int, int>>(n, {-1, -1}));

        auto result = solve(n - 1, n - 1, board);
        return {result.first, result.second};
    }
};
