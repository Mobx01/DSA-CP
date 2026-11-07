/*Leetcode ps-1882. Process Tasks Using Servers
You are given two 0-indexed integer arrays servers and tasks of lengths n​​​​​​ and m​​​​​​ respectively. servers[i] is the weight of the i​​​​​​th​​​​ server, and tasks[j] is the time needed to process the j​​​​​​th​​​​ task in seconds.
Tasks are assigned to the servers using a task queue. Initially, all servers are free, and the queue is empty.
At second j, the jth task is inserted into the queue (starting with the 0th task being inserted at second 0). As long as there are free servers and the queue is not empty, the task in the front of the queue will be assigned to a free server with the smallest weight, and in case of a tie, it is assigned to a free server with the smallest index.
If there are no free servers and the queue is not empty, we wait until a server becomes free and immediately assign the next task. If multiple servers become free at the same time, then multiple tasks from the queue will be assigned in order of insertion following the weight and index priorities above.
A server that is assigned task j at second t will be free again at second t + tasks[j].
Build an array ans​​​​ of length m, where ans[j] is the index of the server the j​​​​​​th task will be assigned to.
Return the array ans​​​​.*/





/* Approach - Dual Priority Queue Simulation with Time-Jump Optimization / Process Tasks Using Servers (Time: O((N + M) log N), Space: O(N + M))
 * Basically, we completely annihilate brute-force server allocation searches by aggressively leveraging two min-heaps (`free` and `busy` priority queues) to track available and occupied servers dynamically in optimal logarithmic time!
 * * Observation: 
 * - The absolute core of this architecture is the Dual-Heap Server Scheduling Invariant (LeetCode 1882 - Process Tasks Using Servers)! We maintain a `free` min-heap ordered primarily by server weight and secondarily by index (matching problem tie-breaking rules), and a `busy` min-heap ordered by completion time. At each second `i`, we release any servers whose tasks have finished into the `free` pool.
 * - (Time-Jump Optimization Note): If the `free` queue is empty when a new task arrives, the simulation must normally advance time to when the earliest busy server finishes. Your current fallback correctly pops from the `busy` queue and updates its completion time to `ft + tasks[i]`, but wrapping this in a time jump (`i = max(i, ft)`) when no free servers are available prevents unnecessary step-by-step ticking during idle server bottlenecks.
 * - (Optimal Complexity): Pushing and popping elements across the priority queues takes $O(\log N)$ per server assignment, yielding an overall time complexity of $O((N + M) \log N)$ and auxiliary space of $O(N + M)$ for the heaps and result vector.
 * * How it runs:
 * First, we initialize the `free` heap with all servers `{weight, index}` and an empty `busy` heap.
 * We iterate through each task `i` from `0` to `m - 1`.
 * At each step, we migrate servers from `busy` to `free` if their completion time `<= i`. If `free` is empty, we fast-track the earliest finishing busy server; otherwise, we greedily pick the best available free server, assign task `i`, and push it into `busy` with completion time `i + tasks[i]`.
 * Finally, we flush the resulting server assignment indices to the output stream with absolute mathematical precision at raw silicon speed!
 */





class Solution {
public:
    typedef pair<int,int> pr;
    typedef tuple<long,int,int> tu;

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        priority_queue<pr,vector<pr>,greater<pr>> free;//free servers{wt,ind}
        priority_queue<tu,vector<tu>,greater<tu>> busy;//busy servers {finaltime,wt,ind}

        for(int i=0;i<n;i++){
            free.push({servers[i],i});
        }

        vector<int> res(m);
        for(int i=0;i<m;i++){
            //move busy servers to free servers if they are free by ith time
            while(!busy.empty() && get<0>(busy.top()) <= i){
                auto [ft,wt,ind] = busy.top();
                busy.pop();
                free.push({wt,ind});
            }
            if(free.empty()){
                auto [ft,wt,ind] = busy.top();
                busy.pop();
                res[i] = ind;
                busy.push({ft+tasks[i] ,wt,ind});
            }else{
                auto [wt,ind] = free.top();
                free.pop();
                res[i] = ind;
                busy.push({i+tasks[i],wt,ind});
            }
        }
        return res;
    }
};
