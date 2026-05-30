/*Leetcode ps-3161. Block Placement Queries
There exists an infinite number line, with its origin at 0 and extending towards the positive x-axis.
You are given a 2D array queries, which contains two types of queries:
For a query of type 1, queries[i] = [1, x]. Build an obstacle at distance x from the origin. It is guaranteed that there is no obstacle at distance x when the query is asked.
For a query of type 2, queries[i] = [2, x, sz]. Check if it is possible to place a block of size sz anywhere in the range [0, x] on the line, such that the block entirely lies in the range [0, x]. A block cannot be placed if it intersects with any obstacle, but it may touch it. Note that you do not actually place the block. Queries are separate.
Return a boolean array results, where results[i] is true if you can place the block specified in the ith query of type 2, and false otherwise.*/

class Solution {
public:
    vector<int> segmentTree;
    int n = 50000;

    void constructSegmentTree() {
        segmentTree.resize(4*n, 0);
    }

    void updateSegTree(int idx, int val, int i, int l, int r) {
        if(l == r) {
            segmentTree[i] = val;
            return;
        }

        int mid = l + (r-l)/2;

        if(idx <= mid) {
            updateSegTree(idx, val, 2*i+1, l, mid);
        } else {
            updateSegTree(idx, val, 2*i+2, mid+1, r);
        }

        segmentTree[i] = max(segmentTree[2*i+1], segmentTree[2*i+2]);
    }

    int querySegTree(int start, int end, int i, int l, int r) {
        if(l > end || r < start) { //out of range node hai ye, return kar jao
            return 0;
        }

        if(l >= start && r <= end) {
            return segmentTree[i];
        }

        int mid = l + (r-l)/2;

        return max(querySegTree(start, end, 2*i+1, l, mid), querySegTree(start, end, 2*i+2, mid+1, r));
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        constructSegmentTree();

        set<int> st; //obstacles
        st.insert(0);

        vector<bool> result;

        for(auto& query : queries) {
            if(query[0] == 1) {
                int x = query[1];

                auto it = st.upper_bound(x);
                int nxt = (it != st.end()) ? *it : -1;
                int pre = *prev(it);

                updateSegTree(x, x-pre, 0, 0, n-1);
                if(nxt != -1) updateSegTree(nxt, nxt-x, 0, 0, n-1);

                st.insert(x);
            } else {
                int x = query[1];
                int sz = query[2];

                auto it = st.upper_bound(x);
                int pre = *prev(it);

                int maxGap = querySegTree(0, pre, 0, 0, n-1);
                int best = max(maxGap, x-pre);

                result.push_back(best >= sz);
            }
        }

        return result;
    }
};
