/*Leetcode ps-3310. Remove Methods From Project
You are maintaining a project that has n methods numbered from 0 to n - 1.
You are given two integers n and k, and a 2D integer array invocations, where invocations[i] = [ai, bi] indicates that method ai invokes method bi.
There is a known bug in method k. Method k, along with any method invoked by it, either directly or indirectly, are considered suspicious and we aim to remove them.
A group of methods can only be removed if no method outside the group invokes any methods within it.
Return an array containing all the remaining methods after removing all the suspicious methods. You may return the answer in any order. If it is not possible to remove all the suspicious methods, none should be removed.
*/


/* Approach - Graph Traversal (BFS) & In-Degree Isolation (Time: O(N + E), Space: O(N + E))
 * Basically, we aggressively map out the entire network of method calls, simulate a viral spread starting from our known bugged method to flag everything it touches, and beautifully use in-degrees to mathematically prove if the quarantine zone is safe to delete!
 * * Observation: 
 * - The core rule of the problem is strict: if a known suspicious method calls another method, the target instantly becomes suspicious. We can flawlessly track this entire cascade using a standard Breadth-First Search (BFS)!
 * - The absolute critical catch is that we CANNOT safely remove the suspicious group if even a single strictly non-suspicious method relies on one of them!
 * - (The Absolute Masterstroke): Instead of building a complex reversed graph to check for outside callers, this code brilliantly utilizes an `indeg` (in-degree) array! Initially, it tracks the total number of callers for every method. During the BFS, when a suspicious method calls another node, we actively decrement that target's `indeg`. 
 * - By the time the BFS completely finishes, the remaining `indeg` mathematically represents ONLY the incoming calls from the non-suspicious, unvisited methods! If any suspicious method has an `indeg > 0` at the end, the quarantine has absolutely failed!
 * * How it runs:
 * First, we safely extract all `invocations` to fully construct our directed graph (`adj`), while simultaneously tallying up the absolute total `indeg` for every single node.
 * Then, we securely anchor our BFS perfectly at method `k`. We mark it `suspicious` and dive into the queue.
 * Next, as the BFS sweeps through the graph, for every single neighbor reached by a suspicious node, we aggressively decrement its `indeg`. If the neighbor wasn't flagged yet, we mark it and throw it directly into the queue to continue the spread.
 * Once the simulation finishes, we trigger a high-speed linear sweep from `0` to `n-1`. We fiercely check for the failure condition: if a node is `suspicious` AND its `indeg > 0`, an outside safe node is calling it, instantly tripping our `cannotrem` flag!
 * Finally, if the removal is blocked (`cannotrem`), we confidently return an array of all methods `0` to `n-1`. Otherwise, we beautifully extract and return the strictly isolated safe methods!
 */


class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // adj list
        vector<vector<int>> adj(n); //u ->{nb1 ,nb2,..}
        vector<int> indeg(n,0);
        vector<bool> suspicious(n,false);

        for(auto &edge : invocations){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indeg[v]++;
        }

        //BFS
        queue<int> que;
        que.push(k);
        suspicious[k] = true;

        while(!que.empty()){
            int curr = que.front();
            que.pop();
            for(int &ng : adj[curr]){
                indeg[ng]--;
                if(!suspicious[ng]){
                     que.push(ng);
                     suspicious[ng] = true;
                }
            }
        }
        vector<int>  result;
        bool cannotrem = false;
        for(int i =0;i<n;i++){
            if(suspicious[i] && indeg[i]>0){
                cannotrem = true;
                break;
            }
            if(!suspicious[i]){
                result.push_back(i);
            }
        }
        if(cannotrem){
            vector<int> vec(n);
            for(int i=0;i<n;i++){
                vec[i]=i;
            }
            return vec;
        }
        return result;

    }
};
