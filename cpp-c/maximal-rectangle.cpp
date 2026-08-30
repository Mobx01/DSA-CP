/*Leetcode ps-85. Maximal Rectangle
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.*/


/* Approach - 2D-to-1D Histogram Projection / Dynamic State Accumulation (Time: O(R * C), Space: O(R * C) auxiliary)
 * Basically, we completely annihilate the sheer complexity of a 2D variable-sized rectangle search by violently collapsing the matrix into a dynamic physical landscape, structurally projecting consecutive '1's into 1D histograms and feeding them into our maximum-area engine!
 * * Observation: 
 * - The absolute core of this architecture is the Dimensional Reduction Masterstroke! You brilliantly realized that a matrix of 1s resting on any given row is mathematically identical to a solid histogram resting on that exact same baseline! 
 * - (The Fatal 2D Memory Trap): Look incredibly closely at `vector<vector<int>> inp(n, vector<int>(m))`! You are aggressively duplicating the entire matrix footprint into a massive 2D heap allocation! But look at your accumulation logic: `inp[i][j] = inp[i][j] + inp[i-1][j]`. You ONLY ever look at the exact row immediately above! You can completely destroy this O(R * C) memory burn! Deploy a single 1D register: `vector<int> heights(m, 0)`. As you sweep each row, if `matrix[i][j] == '1'`, just aggressively increment `heights[j]++`. If it's `'0'`, ruthlessly reset it: `heights[j] = 0`! This instantly shreds your auxiliary space complexity down to absolute peak O(C)!
 * - (The Cache-Thrashing Multiplier): I see you deployed your exact same 3-pass `largestRectangleArea` engine! While perfectly modular, calling a memory-allocating 3-pass engine for *every single row* acts as a catastrophic multiplier on your CPU overhead! Every row violently allocates two new O(C) vectors (`nsl`, `nsr`), fragmenting the heap and completely thrashing the L1 cache! Upgrading this to the 1-Pass Stack architecture we discussed earlier will violently accelerate your execution speed across the entire grid!
 * - (The Double-Loop Annihilation): You aggressively run a full O(R * C) nested loop *just* to cast the characters to integers, and then you run a *second* nested loop to build the physical heights! You can completely bypass the first loop! Just read the raw `matrix[i][j] == '1'` dynamically during your main DP sweep! This completely shreds redundant CPU cycles!
 * * How it runs (Current State):
 * First, we safely intercept the 2D character grid and forcefully allocate a massive integer matrix, violently sweeping through to convert ASCII '1's and '0's into pure numeric data.
 * We instantly process the absolute top row, pushing it through our histogram engine to lock in the baseline `maxarea`.
 * We trigger the high-speed vertical sweep! For every subsequent row, we check the terrain. If a solid block exists (`inp[i][j] != 0`), we aggressively fuse it with the block directly above it, mathematically stacking the physical height!
 * We violently slam this freshly forged histogram row directly into our 3-pass radar engine, calculate its maximum territorial dominance, and smash it against our global `maxarea` register!
 * Finally, we confidently output the absolute largest contiguous rectangle in the entire 2D universe!
 */


class Solution {
public:
    vector<int> getnsl(vector<int>& arr, int n) {
        vector<int> res(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            res[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return res;
    }

    // Nearest Smaller to Right
    vector<int> getnsr(vector<int>& arr, int n) {
        vector<int> res(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            res[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return res;
    }
    // find the largest area of current row
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsl = getnsl(heights,n);
        vector<int> nsr = getnsr(heights,n);
        int maxarea = 0;
        for(int i= 0 ;i < n;i++){
            int width = nsr[i]-nsl[i] - 1;
            maxarea = max(maxarea,width*heights[i]);
        }
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(),m=matrix[0].size();
        vector<vector<int>> inp(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                inp[i][j] = matrix[i][j] - '0';
            }
        }
        int maxarea = largestRectangleArea(inp[0]);
        for(int i =1;i<n;i++){
            for(int j=0;j<m;j++){
                if(inp[i][j] != 0){
                inp[i][j] = inp[i][j] + inp[i-1][j];
                }
            }
            maxarea = max(maxarea,largestRectangleArea(inp[i]));
        }
        return maxarea;
    }
};
