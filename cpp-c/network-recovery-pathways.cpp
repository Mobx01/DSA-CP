/*Leetcode ps - 3620. Network Recovery Pathways
You are given a directed acyclic graph of n nodes numbered from 0 to n − 1. This is represented by a 2D array edges of length m, where edges[i] = [ui, vi, costi] indicates a one‑way communication from node ui to node vi with a recovery cost of costi.
Some nodes may be offline. You are given a boolean array online where online[i] = true means node i is online. Nodes 0 and n − 1 are always online.
A path from 0 to n − 1 is valid if:
All intermediate nodes on the path are online.
The total recovery cost of all edges on the path does not exceed k.
For each valid path, define its score as the minimum edge‑cost along that path.
Return the maximum path score (i.e., the largest minimum-edge cost) among all valid paths. If no valid path exists, return -1.*/


/* Approach - Binary Search on Answer + Dijkstra's Algorithm
 * Basically, we want to maximize the minimum edge weight (the "score") of a path from start to finish, without exceeding a total distance limit 'k' and strictly using "online" nodes. We achieve this by guessing the answer with Binary Search and verifying it with a heavily filtered Dijkstra's algorithm!
 * We keep a few main structures to track our state:
 * - 'adj' is our graph adjacency list, built exclusively with nodes that are currently online.
 * - 'l' and 'r' establish the boundaries for our binary search, derived from the smallest and largest edge weights in the graph.
 * - 'pq' (min-heap) and 'result' (distance array) drive our Dijkstra shortest-path check.
 *
 * How it runs:
 * First, we build our graph from the 'edges' list, completely ignoring any edge connected to an offline node. Simultaneously, we find the absolute minimum and maximum edge costs to set our 'l' and 'r' binary search bounds.
 * Then, we start binary searching for the maximum possible path score ('mid'). For each guess, we call our 'check' function to see if a valid path exists.
 * Inside 'check', we run a modified Dijkstra's algorithm starting from node 0. The magic happens in the filters: we strictly ignore any connected edge where the cost is less than our 'mid' guess. Furthermore, if our running path distance 'd' ever exceeds our max allowed distance 'k', we immediately kill that path to save time.
 * If Dijkstra successfully lands on the target node 'n-1' under these strict conditions, our guess was valid! We record it and push 'l' up to hunt for an even higher score. If it fails, our threshold was too greedy, so we pull 'r' down.
 * Finally, the loop narrows in on the absolute highest valid score, which we then return!
 */

class Solution {
public:
    typedef long long ll;
    typedef pair<ll,int> P;
    bool check(int mid , int n ,long long k, unordered_map<int,vector<vector<int>>> &adj){
        //result[i] = min cost path from 0 to i;
        vector<ll> result(n,LLONG_MAX);
        priority_queue<P , vector<P> , greater<P>> pq;

        result[0] =0;
        pq.push({0,0});
        while(!pq.empty()){
            ll d = pq.top().first;
            int node =pq.top().second;
            pq.pop();

            if(d > k){
                return false;
            }

            if(node == n-1){
                return true;
            }

            //total cost reaching from 0 to i is d;
            if(result[node] < d)continue;

            for(auto &vec : adj[node]){
                int ngbr = vec[0];
                int cost = vec[1];
                if(cost < mid) continue;

                if(d+cost < result[ngbr]){
                    result[ngbr] = d+ cost;
                    pq.push({d+cost,ngbr});
                }
            }
        }

        return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        //adjacency list
        int l = INT_MAX , r = INT_MIN,n=online.size();
        unordered_map<int,vector<vector<int>>> adj;
        for(auto &edge :edges){
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];
            if(!online[u] || !online[v]) continue;

            adj[u].push_back({v,cost});
            l = min(l,cost);
            r= max(r,cost);
        }
        int ans = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(check(mid,n,k,adj)){
                ans = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return ans;
    }
};
