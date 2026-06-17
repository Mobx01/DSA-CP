/*Leetcode ps- 3558. Number of Ways to Assign Edge Weights I
There is an undirected tree with n nodes labeled from 1 to n, rooted at node 1. The tree is represented by a 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi.
Initially, all edges have a weight of 0. You must assign each edge a weight of either 1 or 2.
The cost of a path between any two nodes u and v is the total weight of all edges in the path connecting them.
Select any one node x at the maximum depth. Return the number of ways to assign edge weights in the path from node 1 to x such that its total cost is odd.
Since the answer may be large, return it modulo 109 + 7.
Note: Ignore all edges not in the path from node 1 to x.*/


/*
### Approach: DFS and The "Half-and-Half" Math Trick
This problem looks complicated with trees and edge weights, but it's actually a clever math puzzle disguised as a graph problem. 
The problem tells us to completely ignore every edge except the ones forming a straight path from the root (node 1) down to the deepest node. Once we realize this, we just need to figure out how many edges are in that path, and then apply a simple combinatorics trick.

**1. Build the Tree and Find the Depth**
First, we take the raw `edges` input and build an adjacency list (`adj`) so we can easily navigate the tree. Then, we use a Depth-First Search (the `getMaxDepth` function) starting from node 1. This function travels down the tree to find the maximum depth, which exactly equals the number of edges on our target path. Let's call this number 'D'.

**2. The Math Trick (Why exactly half?)**
We have 'D' edges, and we can assign a weight of either 1 or 2 to each. 
* Total possible ways to assign weights = 2^D.
* How many of these give an *odd* total sum? Exactly half of them!

*Why?* Imagine you arbitrarily assign weights to the first D-1 edges. It doesn't matter what you chose; their running sum is currently either even or odd. Now look at the very last edge. If you want the final sum to be odd, you have exactly ONE valid choice for the last edge:
- If the current sum is Even, you MUST choose 1 (Even + 1 = Odd).
- If the current sum is Odd, you MUST choose 2 (Odd + 2 = Odd).

Since the final choice is locked in based on the previous ones, the number of valid odd combinations is simply the number of ways to arrange the first D-1 edges, which is 2^(D-1).

**3. Fast Exponentiation**
Because 'D' can be a very large number, doing a simple loop to calculate 2^(D-1) would be too slow and would overflow standard integer limits. We use a custom `power` function that calculates this in O(log N) time by repeatedly squaring the base, while making sure to wrap around our huge numbers using modulo 10^9 + 7 at every step to prevent overflow. 
*/


class Solution {
public:
    static constexpr long long MOD = 1e9 + 7;

    long long power(long long base, long long exponent) {
        if (exponent == 0)
            return 1;

        long long half = power(base, exponent / 2);

        long long result = (half * half) % MOD;

        if (exponent % 2 == 1) {
            result = (result * base) % MOD;
        }

        return result;
    }

    int getMaxDepth(unordered_map<int, vector<int>>& adj, int node, int parent) {

        int depth = 0;

        for (int neighbor : adj[node]) {
            if (neighbor == parent)
                continue;

            depth = max(depth, getMaxDepth(adj, neighbor, node) + 1);
        }

        return depth;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> adj;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int maxDepth = getMaxDepth(adj, 1, 0);

        return power(2, maxDepth - 1);
    }
};
