/*leetcode ps - 62. Unique Paths
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The test cases are generated so that the answer will be less than or equal to 2 * 109.

*/




/* Approach - Memoized 2D Dynamic Programming / Grid Unique Path Enumeration (Time: O(M * N), Space: O(M * N))
 * Basically, we completely annihilate brute-force exponential path exploration by aggressively memoizing subproblem solutions across grid coordinates, computing total unique paths in pristine linear/pseudo-polynomial time!
 * * Observation: 
 * - The absolute core of this architecture is the Unique Paths Invariant (LeetCode 62 - Unique Paths)! The number of ways to reach destination `(m - 1, n - 1)` from `(i, j)` is strictly the sum of paths coming from moving down `solve(i + 1, j)` and moving right `solve(i, j + 1)`. 
 * - (Static Buffer Safety): Utilizing a fixed-size memoization array `t[101][101]` with `memset` is clean and efficient given standard constraint limits ($m, n \le 100$). For larger or dynamic constraints, a dynamically allocated 2D vector or an iterative bottom-up table would be preferred.
 * - (Alternative Mathematical Insight): This can also be solved in $O(1)$ auxiliary space and $O(\min(m, n))$ time using combinations: $\binom{m + n - 2}{m - 1}$, but the DP approach elegantly demonstrates optimal state transition caching.
 * * How it runs:
 * First, we initialize our memoization table `t` using `memset` to `-1`.
 * We launch our recursive DFS from `(0, 0)` toward `(m - 1, n - 1)`.
 * At each step, we check boundaries (returning `0` if out of bounds), check memoized results, and return the sum of right and down recursive calls.
 * Finally, we flush the total unique path count to the output stream with absolute mathematical precision at raw silicon speed!
 */




class Solution {
public:
    int t[101][101];
    int solve(int i,int j ,int m ,int n){
        if(i >= m || j >= n) return 0;//cant procced with this 

        if(i == m-1 && j == n-1) return 1;//one path is completed

        if(t[i][j] != -1) return t[i][j];

        return t[i][j] = solve(i+1,j,m,n) + solve(i,j+1,m,n);// take both way to find all the ways
    }
    int uniquePaths(int m, int n) {
        memset(t,-1,sizeof(t));
        return solve(0,0,m,n);
    }
};
