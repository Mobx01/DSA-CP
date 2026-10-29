/*tuf ps- 125. Ninja's training
A ninja has planned a n-day training schedule. Each day he has to perform one of three activities - running, stealth training, or fighting practice. The same activity cannot be done on two consecutive days and the ninja earns a specific number of merit points, based on the activity and the given day.
Given a n x 3-sized matrix, where matrix[i][0], matrix[i][1], and matrix[i][2], represent the merit points associated with running, stealth and fighting practice, on the (i+1)th day respectively. Return the maximum possible merit points that the ninja can earn.*/




/* Approach - Memoized Top-Down Dynamic Programming / Ninja Training Maximum Merit (Time: O(N), Space: O(N))
 * Basically, we completely annihilate brute-force exponential subset exploration by aggressively memoizing day-by-day task choices with state constraints, computing the maximum merit points in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Non-Consecutive Task Invariant (Coding Ninjas / Standard DP problem: Ninja's Training)! Since you cannot perform the same task on consecutive days, the state at any day `i` depends entirely on which task (`prev`) was chosen on the previous day. Representing the state as `t[i][prev]` where `prev` ranges from `0` to `2` (plus `3` as a dummy state for day 0) bounds the state space to $N \times 4$.
 * - (Elegant Dummy State Trick): Passing `3` as the initial `prev` parameter in `solve(0, 3, matrix)` is a brilliant touch—it cleanly bypasses the restriction on day 0, allowing all three task choices without requiring separate base cases or conditional logic.
 * - (Optimal Complexity): With $N$ days and 4 possible previous states, each computed in $O(1)$ constant transitions, time complexity is strictly $O(N)$ and auxiliary space for the memo table and recursion stack is $O(N)$.
 * * How it runs:
 * First, we determine matrix dimensions, initialize our memoization table `t` of size $N \times 4$ with `-1`, and launch the recursive DFS starting at day `0` with dummy previous state `3`.
 * Inside `solve`, we check memoization, loop through all 3 available tasks for the current day (skipping the task matching `prev`), and recursively accumulate the maximum merit points.
 * We memoize and return the optimal subproblem result.
 * Finally, we flush the maximum total merit points to the output stream with absolute mathematical precision at raw silicon speed!
 */




class Solution {
public:
    vector<vector<int>> t;
    int solve(int i,int prev,vector<vector<int>>& matrix){
        int n = matrix.size();
        if(i >= n)return 0;

        if(t[i][prev] != -1) return t[i][prev];

        int maxv = 0;
        //cant perform the operation performed on last op 
        for(int j=0;j<3;j++){
            if(j != prev){
                maxv = max(maxv,solve(i+1,j,matrix) + matrix[i][j]);
            }
        }
        return  t[i][prev] = maxv;
    }
    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();
        t = vector<vector<int>> (n,vector<int>(4,-1));
        return solve(0,3,matrix);//passed 3 as prev so that in first index all possible ways are considered
    }
};
