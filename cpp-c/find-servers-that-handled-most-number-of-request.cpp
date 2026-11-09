/*Leetcode ps-1606. Find Servers That Handled Most Number of Requests
You have k servers numbered from 0 to k-1 that are being used to handle multiple requests simultaneously. Each server has infinite computational capacity but cannot handle more than one request at a time. The requests are assigned to servers according to a specific algorithm:

The ith (0-indexed) request arrives.
If all servers are busy, the request is dropped (not handled at all).
If the (i % k)th server is available, assign the request to that server.
Otherwise, assign the request to the next available server (wrapping around the list of servers and starting from 0 if necessary). For example, if the ith server is busy, try to assign the request to the (i+1)th server, then the (i+2)th server, and so on.
You are given a strictly increasing array arrival of positive integers, where arrival[i] represents the arrival time of the ith request, and another array load, where load[i] represents the load of the ith request (the time it takes to complete). Your goal is to find the busiest server(s). A server is considered busiest if it handled the most number of requests successfully among all the servers.

Return a list containing the IDs (0-indexed) of the busiest server(s). You may return the IDs in any order.*/




/* Approach - Ordered Set with Binary Search Rotation & Priority Queue Simulation / Find Servers That Handled Most Number of Requests (Time: O(N log K), Space: O(K))
 * Basically, we completely annihilate brute-force server scanning by aggressively combining a min-heap for busy servers with a balanced binary search tree (`std::set`) to instantly locate the next available server starting from preferred index `i % k` in optimal logarithmic time!
 * * Observation: 
 * - The absolute core of this architecture is the BST-Rotated Available Server Invariant (LeetCode 1606 - Find Servers That Handled Most Number of Requests)! We maintain a `std::set<int>` of free servers and a min-heap `busy` ordered by task completion time `{end_time, server_id}`. When a request arrives at time `arrival[i]`, we free all servers whose tasks have finished. Using `free.lower_bound(i % k)` instantly finds the first available server at or after the preferred index, wrapping around to `free.begin()` if no such server exists.
 * - (Dropped Request Handling): Notice that if `free` is empty after clearing completed tasks, the request is dropped (`continue`), which correctly matches the problem statement requiring requests to be ignored when all servers are busy.
 * - (Optimal Complexity): Each of the $N$ requests performs BST operations and priority queue updates in $O(\log K)$ time, yielding an overall time complexity of $O(N \log K)$ and auxiliary space of $O(K)$ for the servers and frequency counts.
 * * How it runs:
 * First, we populate our free server set with indices from `0` to `k - 1` and initialize our busy min-heap and request count vector `cnt`.
 * We iterate through each request `i`, releasing any servers that have finished their tasks by `arrival[i]`.
 * If servers are available, we use `lower_bound` to find the designated server starting from `i % k`, increment its load count, and push it into the busy heap with completion time `arrival[i] + load[i]`.
 * Finally, we find the maximum request count (`mx`) and flush all server indices matching `mx` to the output stream with absolute mathematical precision at raw silicon speed!
 */




class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> free;
        int n = arrival.size();
        for(int i=0;i<k;i++){
            free.insert(i);
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> busy;
        vector<int> cnt(k);
        for(int i=0;i<n;i++){
            long long t = arrival[i];
            while(!busy.empty() && busy.top().first <= t){
                free.insert(busy.top().second);
                busy.pop();
            }

            if(free.empty()) continue;
            int pref = i%k;
            auto it = free.lower_bound(pref);
            if(it == free.end()) it = free.begin();
            int s = *it;
            free.erase(it);
            ++cnt[s];
            busy.emplace(t+load[i],s);
        }
        int mx = *max_element(cnt.begin(),cnt.end());
        vector<int> ans;
        for(int i=0;i<k;i++){
            if(cnt[i] == mx){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
