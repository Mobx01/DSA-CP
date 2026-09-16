/*Leetcode ps1621. Number of Sets of K Non-Overlapping Line Segments
Given n points on a 1-D plane, where the ith point (from 0 to n-1) is at x = i, find the number of ways we can draw exactly k non-overlapping line segments such that each segment covers two or more points. The endpoints of each segment must have integral coordinates. The k line segments do not have to cover all n points, and they are allowed to share endpoints.
Return the number of ways we can draw k non-overlapping line segments. Since this number can be huge, return it modulo 109 + 7.-*/




/* Approach - Top-Down Dynamic Programming with Segment-Choice Branching (Time: O(N^2 * K), Space: O(N * K))
 * Basically, we completely annihilate brute-force subset enumeration by aggressively deploying a memoized dynamic programming state machine, tracking point indices and remaining segment counts in pristine polynomial time!
 * * Observation: 
 * - The absolute core of this architecture is the Segment Partitioning Transition (LeetCode 1621 - Number of Sets of K Non-Overlapping Line Segments)! At any given point `i` with `k` segments remaining, you have two choices: `skip` (move to the next point without starting a segment) or `take` (start a segment at `i` and end it at some future point `j`, transitioning to `solve(n, k - 1, j)`). Your recursive branching cleanly models this combinatorial choice.
 * - (The O(N) Transition Loop Bottleneck): Your inner loop (`for(int j = i + 1; j < n; j++)`) evaluates all possible endpoints `j` for the current segment. Across $N \times K$ states, this introduces an $O(N^2 * K)$ time complexity. While sufficient for modest constraints (e.g., $N \le 1000$), this transition can be optimized down to pristine $O(N * K)$ time by maintaining a running prefix sum of previous DP states!
 * - (Overflow-Safe Accumulation Win): Declaring `long long take = 0;` and accumulating subproblem results before applying the modulo arithmetic `(take + skip) % M` prevents intermediate integer overflow across the summation loop.
 * * How it runs:
 * First, we initialize our memoization table `t` with `-1` and intercept the grid dimensions and segment requirement.
 * We ignite our recursive solver starting from index `0` with `k` segments to form.
 * Base cases instantly return `1` if all segments are successfully placed (`k == 0`), or `0` if we run out of points (`i >= n`).
 * For each state, we compute the sum of ways by skipping the current point or trying all valid segment endpoints `j`, memoizing the result.
 * Finally, we flush the total valid configurations modulo $10^9 + 7$ to the output stream with absolute mathematical precision at raw silicon speed!
 */




class Solution {
public:
    int  M =1e9 + 7;
    int t[1001][1001];
    int solve(int n ,int k,int i){
        if(k == 0){
            return 1; //1 valid set is formed
        }
        if(i >= n){
            return 0;///cant form a set starting index i is out of bound
        }

        if(t[i][k] != -1) return t[i][k];
        int skip = solve(n,k,i+1);
        long long take=0;
        //take -> startng a segment from i and ending at j
        for(int j =i+1 ;j < n ;j++){
            take += solve(n,k-1,j);
        }

        return t[i][k] =  (take+skip)%M;
    }
    int numberOfSets(int n, int k) {
        memset(t,-1,sizeof(t));
        return solve(n,k,0);
    }
};
