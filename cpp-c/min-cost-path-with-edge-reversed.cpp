/*Leetcode ps:- 3650. Minimum Cost Path with Edge Reversals
You are given a directed, weighted graph with n nodes labeled from 0 to n - 1, and an array edges where edges[i] = [ui, vi, wi] represents a directed edge from node ui to node vi with cost wi.
Each node ui has a switch that can be used at most once: when you arrive at ui and have not yet used its switch, you may activate it on one of its incoming edges vi → ui reverse that edge to ui → vi and
immediately traverse it.
The reversal is only valid for that single move, and using a reversed edge costs 2 * wi.
Return the minimum total cost to travel from node 0 to node n - 1. If it is not possible, return -1.
*/
// Intuition:
// The problem can be treated as a shortest-path problem on a directed, weighted graph.
// Each directed edge u -> v with cost w can also be traversed in reverse as v -> u
// with an additional cost of 2 * w. By adding these reverse edges, the problem
// reduces to finding the minimum-cost path from node 0 to node n - 1.
// Since all edge weights are non-negative, Dijkstra’s algorithm can be used.

// Approach:
// 1. For every directed edge u -> v with cost w, add:
//    - the original edge u -> v with cost w
//    - a reverse edge v -> u with cost 2 * w
// 2. Build an adjacency list using these edges.
// 3. Run standard Dijkstra’s algorithm from node 0:
//    - Maintain a distance array dist[] where dist[i] is the minimum cost to reach node i.
//    - Use a min-priority queue to always expand the node with the smallest current cost.
//    - Relax edges and update distances whenever a cheaper path is found.
// 4. If node n - 1 is unreachable, return -1; otherwise return dist[n - 1].

// Complexity:
// Time complexity: O((n + m) log n),
// where n is the number of nodes and m is the number of edges after adding reverse edges.
// Space complexity: O(n + m) for the adjacency list, distance array, and priority queue.


class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        using ll = long long;
        const ll INF = 1e18;

        // Append reverse edges with cost = 2*w
        int m = edges.size();
        for (int i = 0; i < m; i++) {
            edges.push_back({
                edges[i][1],
                edges[i][0],
                2 * edges[i][2]
            });
        }

        // Build adjacency list
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        // Standard Dijkstra
        vector<ll> dist(n, INF);
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();

            if (cost > dist[u]) continue;

            for (auto &[v, w] : adj[u]) {
                if (dist[v] > cost + w) {
                    dist[v] = cost + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n - 1] == INF ? -1 : (int)dist[n - 1];
    }
};
