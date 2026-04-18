/*Leetcode PS:-2976. Minimum Cost to Convert String I
You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English letters. You are also given two 0-indexed character arrays original and changed,
and an integer array cost, where cost[i] represents the cost of changing the character original[i] to the character changed[i].
You start with the string source. In one operation, you can pick a character x from the string and change it to the character y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x,
and changed[j] == y.
Return the minimum cost to convert the string source to the string target using any number of operations. If it is impossible to convert source to target, return -1.
Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].*/


// Intuition:
// Each lowercase character ('a' to 'z') is treated as a node in a graph (26 nodes total).
// Every allowed character conversion represents a directed edge with a given cost.
// Since a character may require multiple intermediate conversions to reach another character
// at the minimum cost, we need to know the cheapest conversion path between all pairs of characters.
// Because the number of nodes is small and fixed (26), Floyd–Warshall is an efficient choice.

// Approach:
// 1. Create a 26x26 matrix where dist[i][j] stores the minimum cost to convert character
//    ('a' + i) to ('a' + j).
// 2. Initialize all values to infinity and set dist[i][i] = 0 for all characters.
// 3. Fill direct conversion costs using the given original, changed, and cost arrays,
//    keeping the minimum cost when duplicate conversions exist.
// 4. Apply the Floyd–Warshall algorithm to compute the minimum conversion cost between
//    every pair of characters, allowing indirect conversions.
// 5. Traverse the source string character by character:
//    - If source[i] == target[i], no cost is added.
//    - Otherwise, add dist[source[i]][target[i]] to the answer.
//    - If at any point the cost is infinity, return -1 as conversion is impossible.
// 6. Return the total accumulated cost.

// Complexity:
// Time Complexity:
// - Floyd–Warshall runs in O(26^3)
// - Traversing the string takes O(n)
// - Overall complexity: O(n + 26^3), which effectively behaves like O(n)
//
// Space Complexity:
// - Uses a 26x26 matrix for storing conversion costs
// - Space complexity: O(26^2), which is constant




class Solution {
public:
    long long minimumCost(
        string source,
        string target,
        vector<char>& original,
        vector<char>& changed,
        vector<int>& cost
    ) {
        const long long INF = 1e18;
        vector<vector<long long>> dist(26, vector<long long>(26, INF));

        // cost to convert a character to itself
        for (int i = 0; i < 26; i++) {
            dist[i][i] = 0;
        }

        // direct conversions
        for (int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // Floyd–Warshall
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // calculate result
        long long ans = 0;
        for (int i = 0; i < source.size(); i++) {
            int s = source[i] - 'a';
            int t = target[i] - 'a';

            if (dist[s][t] == INF) {
                return -1;
            }
            ans += dist[s][t];
        }

        return ans;
    }
};
