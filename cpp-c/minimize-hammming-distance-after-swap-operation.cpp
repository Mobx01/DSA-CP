/*Leetcode ps-1722. Minimize Hamming Distance After Swap Operations
You are given two integer arrays, source and target, both of length n. You are also given an array allowedSwaps where each allowedSwaps[i] = [ai, bi] indicates that you are allowed to swap the elements at index ai and index bi (0-indexed) of array source. Note that you can swap elements at a specific pair of indices multiple times and in any order.
The Hamming distance of two arrays of the same length, source and target, is the number of positions where the elements are different. Formally, it is the number of indices i for 0 <= i <= n-1 where source[i] != target[i] (0-indexed).
Return the minimum Hamming distance of source and target after performing any amount of swap operations on array source.

*/

class Solution {
public:
  //DSU using rank and path compression
    vector<int> rank;
    vector<int> parent;

    // Find with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void Union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return;

        // Union by rank
        if (rank[rootX] < rank[rootY]) {
            swap(rootX, rootY);
        }

        parent[rootY] = rootX;

        if (rank[rootX] == rank[rootY]) {
            rank[rootX]++;
        }
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();

        parent.resize(n);
        rank.resize(n);
        for(int i =0;i<n;i++){
            parent[i]=i;
        }

        for(auto &ve : allowedSwaps){
            Union(ve[0],ve[1]);
        }
        unordered_map<int,unordered_map<int,int>> groupfreq;

        for(int i =0 ;i<n;i++){
            int curr = source[i];
            int parent = find(i);
            groupfreq[parent][curr]++;
        }

        int hdis =0;
        for(int i =0;i< n;i++){
            int parent = find(i);
            if(groupfreq[parent][target[i]] > 0){
                groupfreq[parent][target[i]] --;
            }
            else{
                hdis++;
            }
        }

        return hdis;
    }
};
