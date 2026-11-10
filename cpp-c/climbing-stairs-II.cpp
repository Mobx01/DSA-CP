/*Leetcode ps-3693. Climbing Stairs II
You are climbing a staircase with n + 1 steps, numbered from 0 to n.
You are also given a 1-indexed integer array costs of length n, where costs[i] is the cost of step i.
From step i, you can jump only to step i + 1, i + 2, or i + 3. The cost of jumping from step i to step j is defined as: costs[j] + (j - i)2
You start from step 0 with cost = 0.
Return the minimum total cost to reach step n.*/




/* Approach - Memoized Top-Down Dynamic Programming with Multi-Step Branching (Time: O(N), Space: O(N))
 * Basically, we completely annihilate brute-force exponential stair traversal by aggressively memoizing subproblem solutions across stair indices, computing the minimum cost climbing path in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Multi-Step Stair Cost Invariant! From any stair index `i`, you can jump up to 3 steps forward (`j = i + 1` to `i + 3`). The transition cost includes the base travel penalty represented by the squared distance `(j - i) * (j - i)` plus the landing stair cost `costs[j - 1]`.
 * - (Function Signature Return Type Mismatch): Notice that your recursive helper and memo table return `long long`, but your top-level `climbStairs` function returns `int`. If the optimal path cost exceeds `INT_MAX`, an implicit narrowing conversion will trigger integer overflow or truncation. Changing `int climbStairs` to return `long long` fully resolves this and matches your internal types.
 * - (Optimal Complexity): With $N+1$ unique states each evaluating up to 3 transitions in $O(1)$ constant time, the time complexity is strictly $O(N)$ and auxiliary space for the memo table and recursion stack is $O(N)$.
 * * How it runs:
 * First, we initialize our memoization table `t` of size $N + 1$ filled with `-1`.
 * We launch our recursive DFS from stair `0` toward stair `n`.
 * At each step, we check base cases (reaching stair `n` returns `0`, overshooting returns `1e15`), check memoized results, and iterate through valid forward jumps (up to 3 steps) to find the minimum transition cost.
 * Finally, we flush the optimal minimum cost to the output stream with absolute mathematical precision at raw silicon speed!
 */




class Solution {
public:
    vector<long long> t; 
    
    long long solve(int i, int n, vector<int>& costs) {
        if (i == n) return 0; // Reached nth stair
        if (i > n) return 1e15;

        // Check memoization table
        if (t[i] != -1) return t[i];
        
        long long minc = 1e15;
        for (int j = i + 1; j <= min(n, i + 3); j++) {
            minc = min(minc, solve(j, n, costs) + (long long)(j - i) * (j - i) + costs[j - 1]);
        }
        
        return t[i] = minc;
    }
    
    int climbStairs(int n, vector<int>& costs) {
        t.assign(n + 1, -1); // Size must be n + 1 since i ranges from 0 to n
        return solve(0, n, costs);
    }
};
