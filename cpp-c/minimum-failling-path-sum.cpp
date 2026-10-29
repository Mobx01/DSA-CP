/*Leetcode ps-931. Minimum Falling Path Sum
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).*/




/* Approach - Memoized 3-Way Branching Top-Down Dynamic Programming / Minimum Falling Path Sum (Time: O(M * N), Space: O(M * N))
 * Basically, we completely annihilate brute-force exponential tree searches by aggressively memoizing subproblem solutions across grid coordinates, computing the minimum falling path sum in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Falling Path Optimization Invariant (LeetCode 931 - Minimum Falling Path Sum)! From any cell `(i, j)`, the minimum falling path sum is the current cell value `mat[i][j]` plus the minimum of three possible downward moves: diagonally left `(i + 1, j - 1)`, straight down `(i + 1, j)`, and diagonally right `(i + 1, j + 1)`.
 * - (Sentinel & Initialization Polish): Using `LLONG_MIN` as the unvisited memoization marker is clean. However, initializing `mins = 1e9` should ideally be `LLONG_MAX` to prevent any edge cases where valid path sums could exceed `1e9`, fully aligning with your `long long` return type.
 * - (Optimal Complexity): With $M \times N$ unique states each evaluated in $O(1)$ constant time, the time complexity is strictly $O(M \times N)$ and auxiliary space for the memo table and recursion stack is $O(M \times N)$.
 * * How it runs:
 * First, we initialize an $M \times N$ memoization table `t` filled with `LLONG_MIN`.
 * We iterate across each column in the first row (`row 0`), invoking our recursive `solve` function to find the minimum falling path starting from each top-row entry.
 * Inside `solve`, we handle out-of-bound column checks (returning `LLONG_MAX`), check base cases at the last row, utilize memoized cache hits, and compute the recursive minimum across the 3 branching directions.
 * Finally, we flush the optimal minimum falling path sum to the output stream with absolute mathematical precision at raw silicon speed!
 */


class Solution {
public:
    long long solve(int i, int j, vector<vector<int>>& mat, vector<vector<long long>>& t) {
        int m = mat.size(), n = mat[0].size();

        // out of bounds check
        if (j < 0 || j >= n) return LLONG_MAX;

        // Reached the last row
        if (i == m - 1) return mat[i][j];

        // check memoization table
        if (t[i][j] != LLONG_MIN) return t[i][j];

        // dolve and store result
        return t[i][j] = mat[i][j] + min({
            solve(i + 1, j - 1, mat, t), 
            solve(i + 1, j, mat, t), 
            solve(i + 1, j + 1, mat, t)
        });
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        

        vector<vector<long long>> t(m, vector<long long>(n, LLONG_MIN));
        
        long long mins = 1e9;
        for (int i = 0; i < n; i++) {
            mins = min(mins, solve(0, i, matrix, t));
        }
        return mins;
    }
};
