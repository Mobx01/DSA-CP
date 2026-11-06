/*Leetcode ps-2747. Count Zero Request Servers
You are given an integer n denoting the total number of servers and a 2D 0-indexed integer array logs, where logs[i] = [server_id, time] denotes that the server with id server_id received a request at time time.
You are also given an integer x and a 0-indexed integer array queries.
Return a 0-indexed integer array arr of length queries.length where arr[i] represents the number of servers that did not receive any requests during the time interval [queries[i] - x, queries[i]].
Note that the time intervals are inclusive.*/




/* Approach - Transformed Difference Frequency Counting / Index-Value Mapping Pair Enumeration (Time: O(N), Space: O(N))
 * Basically, we completely annihilate brute-force $O(N^2)$ pair checking by aggressively transforming the condition into a frequency-mapping problem using the difference `a[i] - i` in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Index-Shift Invariance Principle (commonly found in problems where pairs satisfy equations like $a_i - a_j = i - j$ or $a_i - i = a_j - j$)! By rearranging the equation to $a_i - i = a_j - j$, we can track how many times each transformed key has appeared previously using an `unordered_map`. Every time we encounter the same key `k = a[i] - i`, all previous occurrences can form valid pairs with the current element.
 * - (Map Frequency Accumulation): As we iterate through the array, we add `freq[k]` to our running answer `ans` and then increment `freq[k]++`, ensuring that each valid pair is counted exactly once without redundant nested loops.
 * - (Optimal Complexity): A single linear pass through the array with average $O(1)$ hash map operations keeps time complexity at $O(N)$ and auxiliary space at $O(N)$ for the frequency map.
 * * How it runs:
 * First, we read test parameter `n` and populate vector `a`.
 * We initialize our frequency map `freq` and our pair count `ans = 0`.
 * We iterate through each element, compute its transformed key `k = a[i] - i`, accumulate prior frequencies into `ans`, and update the map.
 * Finally, we flush the total valid pair count to the output stream with absolute mathematical precision at raw silicon speed!
 */




class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(),logs.end(),[](vector<int>& a,vector<int>& b){
            return a[1] < b[1]; //sorting based on time.(1th index )
        });
        vector<pair<int,int>> qur;
        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            qur.push_back({queries[i],i});
        }
        sort(qur.begin(),qur.end(),[](pair<int,int>& a , pair<int,int>& b){
            return a.first < b.first; //sort on basis of actual value (ignore index {second})
        });
        unordered_map<int,int> freq; //server -> no of logs
        int i=0,j=0,m=logs.size();
        for(auto q : qur){
            int end = q.first ;
            int start = end-x;

            //sliding window expansion
            while(j<m && logs[j][1] <= end){
                freq[logs[j][0]]++;
                j++;
            }
            //shrinking of window
            while(i < m && logs[i][1] < start){
                freq[logs[i][0]]--;
                if(freq[logs[i][0]] == 0) freq.erase(logs[i][0]);
                i++;
            }

            int notcalled = n - freq.size();
            ans[q.second] = notcalled;
        }
        return ans;
    }
};
