/*Leetcode ps- 3488. Closest Equal Element Queries
You are given a circular array nums and an array queries.
For each query i, you have to find the following:
The minimum distance between the element at index queries[i] and any other index j in the circular array, where nums[j] == nums[queries[i]]. If no such index exists, the answer for that query should be -1.
Return an array answer of the same size as queries, where answer[i] represents the result for query i.*/


class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> res;
        int n = nums.size(); 
        unordered_map<int, vector<int>> ind;

        // Group indices by value
        for(int i = 0 ; i < n ; i++){
            ind[nums[i]].push_back(i);
        }

        for(int q : queries){
            int cur = nums[q];
            vector<int>& curidx = ind[cur]; 
            int s = curidx.size();

            if(s == 1) {
                res.push_back(-1); // if only 1 index is there then no possible index
            }
            else {
                int  pos = lower_bound(begin(curidx),end(curidx),q) - begin(curidx); // index of current number in curidx array;(binary search )
                // right neighbour
                int rightneb = curidx[(pos+1)%s];
                int d = abs(q-rightneb);

                int cird = n-d;
                int min_dist = min(d,cird);

                //left neighbour
                int leftneb = curidx[(pos-1+s)%s];
                d = abs(q-leftneb);//linear dis 
                cird = n-d; // circular distance
                min_dist = min({d,cird,min_dist});

                
                res.push_back(min_dist);
            }
        }
        return res;
    }
};
