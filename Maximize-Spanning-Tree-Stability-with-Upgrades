/*leetcode ps-3600. Maximize Spanning Tree Stability with Upgrades
You are given an integer n, representing n nodes numbered from 0 to n - 1 and a list of edges, where edges[i] = [ui, vi, si, musti]:
ui and vi indicates an undirected edge between nodes ui and vi.
si is the strength of the edge.
musti is an integer (0 or 1). If musti == 1, the edge must be included in the spanning tree. These edges cannot be upgraded.
You are also given an integer k, the maximum number of upgrades you can perform. Each upgrade doubles the strength of an edge, and each eligible edge (with musti == 0) can be upgraded at most once.

The stability of a spanning tree is defined as the minimum strength score among all edges included in it.
Return the maximum possible stability of any valid spanning tree. If it is impossible to connect all nodes, return -1.
Note: A spanning tree of a graph with n nodes is a subset of the edges that connects all nodes together (i.e. the graph is connected) without forming any cycles, and uses exactly n - 1 edges.*/


class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find (int x) {
        if (x == parent[x]) 
            return x;

        return parent[x] = find(parent[x]);
    }

    bool Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) 
            return false;

        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }

        return true;
    }
};

class Solution {
public:

    bool check(int n, vector<vector<int>>& edges, int k, int mid) {
        DSU dsu(n);

        vector<vector<int>> upgradeCandidates;

        for(auto &edge : edges) { //E
            int u = edge[0];
            int v = edge[1];

            int s = edge[2];
            int m = edge[3];

            if(m == 1) {
                if(s < mid) {
                    return false;
                }

                dsu.Union(u, v); //alpa
            } else {
                if(s >= mid) {
                    //no need to upgrade
                    dsu.Union(u, v);
                } else if(2*s >= mid) {
                    upgradeCandidates.push_back({u, v});
                }
            }
        }

        for(auto &edge : upgradeCandidates) { //O(E)
            int u = edge[0];
            int v = edge[1];

            if(dsu.find(u) != dsu.find(v)) {
                if(k <= 0)
                    return false;
                
                dsu.Union(u, v);
                k--; //upgrade
            }
        }


        int root = dsu.find(0);
        for(int node = 1; node <= n-1; node++) { //O(n)
            if(dsu.find(node) != root)
                return false;
        }
        return true;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
         /*
            Input: n = 3, edges = [[0,1,1,1],[1,2,1,1],[2,0,1,1]], k = 0
            0 --- 1 --- 2 , parent = 0
            (2, 0)
            2 ka. parent kaun hai = 0
            0 ka parent kaun hai  = 0

        */

        DSU dsu(n);
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            int s = edge[2];
            int m = edge[3];

            if(m == 1) { //must be included in the spanning tree
                if(dsu.find(u) == dsu.find(v))
                    return -1;
                
                dsu.Union(u, v);
            }
        }


        int result = -1;
        int l = 1;
        int r = 2*1e5;

        //T.C : O(nlogn)
        while(l <= r) {
            int mid = l + (r-l)/2;

            if(check(n, edges, k, mid)) {
                result = mid;
                l = mid+1;
            } else {
                r = mid -1;
            }
        }

        return result;
    }
};

















// does works on some edge case(might fix later) .
class Solution {
    // Helper structure for "check cycle -> no cycle" using Disjoint Set Union (DSU)
    struct DSU {
        vector<int> parent;

        DSU(int n) {
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0); // Fills with 0,1,2...n-1
        }

        int find(int x) {
            if (parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }

        bool unite(int x, int y) {
            int px = find(x), py = find(y);

            if (px == py) return false; // Cycle detected

            parent[px] = py;
            return true; // Successfully united
        }
    };

public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {

        if(n==2 && k == 1) return edges[0][3] == 1? edges[0][2]: 2*edges[0][2];
        if(n==2 && k == 0) return  edges[0][2];
        DSU dsu(n);

        int edgesIncluded = 0;
        int must0Count = 0;
        int maxmin = INT_MAX;

        // 1. "Include all edge[i] with must = 1"
        for (auto &e : edges) {

            int u = e[0], v = e[1], w = e[2], must = e[3];

            if (must == 1) {

                // "check cycle"
                if (!dsu.unite(u, v))
                    return -1;

                edgesIncluded++;
                maxmin = min(maxmin , w);
            }
        }

        // 2. "sort optional edges on EFFECTIVE strength"
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {

            int effA = (a[3] == 0) ? 2 * a[2] : a[2];
            int effB = (b[3] == 0) ? 2 * b[2] : b[2];

            return effA > effB;
        });

        // 3. "Include k no of edge[i] with must = 0 (based on greedy)"
        for (auto &e : edges) {

            int u = e[0], v = e[1], w = e[2], must = e[3];

            if (must == 0 && must0Count < k) {

                if (dsu.unite(u, v)) { // "check cycle"

                    edgesIncluded++;
                    must0Count++;

                    maxmin = min(maxmin , 2*w);
                }
            }

            if (edgesIncluded == n - 1)
                break;
        }

        

        return maxmin;
    }
};
