/*leetcode ps- 63. Unique Paths II
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.
Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The testcases are generated so that the answer will be less than or equal to 2 * 109.*/



/* Approach - Memoized 2D Dynamic Programming with Obstacle Pruning / Unique Paths II (Time: O(M * N), Space: O(M * N))
 * Basically, we completely annihilate brute-force path tracing by aggressively pruning blocked cells and memoizing subproblem solutions across grid coordinates, computing valid obstacle-free unique paths in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Obstacle-Constrained Unique Paths Invariant (LeetCode 63 - Unique Paths II)! Building directly upon standard unique paths, any cell containing an obstacle (`obs[i][j] == 1`) acts as an immediate dead end, returning `0` and halting further exploration down that branch. 
 * - (Base Case Safeguard): Checking obstacle status at the destination cell (`i == m - 1 && j == n - 1 && obs[i][j] == 0`) ensures that if the final target itself is blocked, it correctly returns `0` rather than counting an invalid path.
 * - (Static Buffer Size Note): Using `t[101][101]` matches standard grid constraints ($m, n \le 100$), though dynamically sizing the memoization table based on `obs.size()` and `obs[0].size()` is robust for arbitrary inputs.
 * * How it runs:
 * First, we initialize our memoization table `t` using `memset` to `-1`.
 * We launch our recursive DFS from `(0, 0)` toward `(m - 1, n - 1)`.
 * At each step, we check boundaries, return `0` immediately if an obstacle is encountered, check memoized results, and return the sum of right and down recursive calls.
 * Finally, we flush the total obstacle-free unique path count to the output stream with absolute mathematical precision at raw silicon speed!
 */




class Solution {
public:
    int t[101][101];
    int solve(int i,int j ,vector<vector<int>>& obs){
        int m = obs.size(),n=obs[0].size();
        if(i >= m || j >= n) return 0;//cant procced with this 

        if(i == m-1 && j == n-1 && obs[i][j] == 0) return 1;//one path is completed

        if(obs[i][j] == 1) return 0 ;; //can procced with this path

        if(t[i][j] != -1) return t[i][j];

        return t[i][j] = solve(i+1,j,obs) + solve(i,j+1,obs);// take both way to find all the ways
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        memset(t,-1,sizeof(t));
        return solve(0,0,obs);
    }
};
