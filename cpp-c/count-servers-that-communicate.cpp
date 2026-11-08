/*Leetcode ps-1267. Count Servers that Communicate
You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.
Return the number of servers that communicate with any other server.*/




/* Approach - Row and Column Precomputation Frequency Arrays / Count Servers that Communicate (Time: O(M * N), Space: O(M + N))
 * Basically, we completely annihilate brute-force pairwise distance checks by aggressively precomputing the total count of servers in each row and column, determining connectivity in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Row-Column Sum Invariant (LeetCode 1267 - Count Servers that Communicate)! A server at coordinate `(i, j)` can communicate with another server if and only if there is at least one other server in its row (`rows[i] > 1`) or in its column (`cols[j] > 1`). 
 * - (Clever Sum Condition): Notice that since the server at `(i, j)` contributes `1` to both `rows[i]` and `cols[j]`, the total sum `rows[i] + cols[j]` will be equal to `2` if it is isolated (1 from its row, 1 from its column). Thus, checking `rows[i] + cols[j] > 2` perfectly and concisely captures whether it shares its row or column with at least one other server!
 * - (Optimal Complexity): Two passes over the $M \times N$ grid take $O(M \times N)$ time, and auxiliary space is strictly $O(M + N)$ for the row and column frequency vectors.
 * * How it runs:
 * First, we determine grid dimensions `m` and `n`, and initialize frequency vectors `rows` and `cols`.
 * We run a double loop to accumulate the number of servers present in each row and column.
 * We run a second double loop inspecting each cell: if `grid[i][j]` is active and `rows[i] + cols[j] > 2`, we increment our communicating server counter.
 * Finally, we flush the total communicating server count to the output stream with absolute mathematical precision at raw silicon speed!
 */



class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size(),count=0;
        vector<int> rows(m), cols(n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                rows[i] += grid[i][j];
                cols[j] += grid[i][j];
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] && rows[i] + cols[j] > 2)count++;
            }
        }

    
        return count;
    }
};
