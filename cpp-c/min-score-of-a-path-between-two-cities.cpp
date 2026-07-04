/*Leetcode ps - 2492. Minimum Score of a Path Between Two Cities
You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road between cities ai and bi with a distance equal to distancei. The cities graph is not necessarily connected.
The score of a path between two cities is defined as the minimum distance of a road in this path.
Return the minimum possible score of a path between cities 1 and n.
Note:
A path is a sequence of roads between two cities.
It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path.
The test cases are generated such that there is at least one path between 1 and n.*/


/* Approach - Breadth-First Search (BFS) Traversal
 * Basically, we explore the entire connected network of roads starting from city 1. Because the problem allows us to travel back and forth across any roads as many times as we want, the minimum score of a path is simply the absolute lowest-scoring road anywhere within this connected component!
 * We keep a few main variables/structures to track this:
 * - 'adj' is our adjacency list that builds the graph from the given roads.
 * - 'visited' is an array to ensure we don't get stuck in infinite loops.
 * - 'q' is our queue driving the level-by-level traversal (Note: your inline comment says 'dfs', but using a queue actually makes this a standard Breadth-First Search!).
 * - 'ans' keeps a running tally of the absolute lowest road distance we've encountered.
 *
 * How it runs:
 * First, we construct our undirected graph 'adj' using the given roads, storing both the destination node and the distance for each connection.
 * Then, we initialize our BFS by pushing node 1 into our queue and marking it as visited.
 * While our queue is not empty, we pop the front node and iterate through all of its connected neighbors.
 * For EVERY connected road we look at, we instantly update our 'ans' with the minimum distance. We update this regardless of whether the neighbor has been visited or not, guaranteeing we evaluate every single road in the network!
 * Finally, if the neighbor hasn't been visited yet, we mark it as visited and push it into the queue to explore its connections next. Once the queue is completely empty, we return our lowest recorded 'ans'!
 */

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);//adjency list for the graph
        for(auto& road : roads){
            int u = road[0],v=road[1],dis=road[2];
            adj[u].push_back({v,dis});
            adj[v].push_back({u,dis});
        }
        int ans =INT_MAX;
        //dfs
        vector<int> visited(n+1,0);

        queue<int> q;
        q.push(1);
        visited[1] = 1;

        while(!q.empty()){
            int curnode = q.front();
            q.pop();
            
            for(auto& i : adj[curnode]){
                ans = min(ans,i.second);
                if(visited[i.first] == 0){
                    visited[i.first] = 1;
                    q.push(i.first);
                }
            }
        }
        return ans;
    }
};
