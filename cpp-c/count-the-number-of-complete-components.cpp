/*Leetcode ps -2685. Count the Number of Complete Components
You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.
Return the number of complete connected components of the graph.
A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.
A connected component is said to be complete if there exists an edge between every pair of its vertices. */

/* Approach - Depth-First Search & Graph Theory (Time: O(V + E), Space: O(V + E))
 * Basically, we traverse the graph to isolate each connected component, counting its vertices and total edges to verify if it forms a mathematically complete subgraph.
 * * Observation:
 * - A complete graph dictates that every single node is directly connected to every other node. Mathematically, a complete graph with 'v' vertices has exactly v * (v - 1) / 2 undirected edges.
 * - Since we are using an adjacency list where every undirected edge is stored twice (once for u->v and once for v->u), the sum of the sizes of the adjacency lists for all nodes in a component will be exactly double the true edge count. Thus, our completeness check brilliantly simplifies by just dropping the division by 2: `v * (v - 1) == e`!
 * * How it runs:
 * First, we build our undirected adjacency list from the given edges and initialize a 'visited' array to prevent processing nodes multiple times.
 * Then, we loop through every possible node from 0 to n-1. If a node hasn't been visited, it acts as the starting point for a brand new, undiscovered component! We launch a DFS, passing our vertex counter 'v' and edge counter 'e' by reference to accumulate their totals.
 * Finally, after the DFS completely maps out that specific isolated component, we check our formula `v * (v - 1) == e`. If it matches, we increment our `res` counter. We return the final count once all nodes are processed!
 */


class Solution {
public:
    void dfs(int i , unordered_map<int,vector<int>> &adj ,vector<bool>& visited,int& v , int& e ){
        visited[i] = true;
        v++;
        e += adj[i].size();

        for(int &ngbr : adj[i]) {
            if(!visited[ngbr]) {
                dfs(ngbr, adj, visited, v, e);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        int res =0;
        //build the adj list(represents graph)
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n,false);
        for(int i = 0 ;i<n;i++){
            if(visited[i] == true) continue;

            int v= 0,e=0;
            dfs(i,adj,visited,v,e);
            if(v*(v-1) == e) res++;
        }
        return res;
    }
};
