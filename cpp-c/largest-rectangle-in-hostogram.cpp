/*Leetcode ps- 84. Largest Rectangle in Histogram
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.*/


/* Approach - Multi-Pass Monotonic Stack / Spatial Dominion Mapping (Time: O(N), Space: O(N))
 * Basically, we completely annihilate the O(N^2) brute force boundary expansion by aggressively deploying dual monotonic stacks, violently mapping the absolute left and right territorial limits of every single histogram bar to mathematically calculate its maximum area!
 * * Observation: 
 * - The absolute core of this architecture is the Territorial Width Equation! You brilliantly realized that the maximum rectangle a bar can support is strictly bottlenecked by the nearest smaller bars on its flanks! The equation `nsr[i] - nsl[i] - 1` flawlessly extracts the exact contiguous spatial block where `heights[i]` reigns supreme!
 * - (The Modular Code Reuse): It is incredibly obvious that you violently ripped your `getnsl` and `getnsr` functions directly from your previous "Sum of Subarray Mins" architecture! While modularity is fantastic for rapid prototyping, using a 3-pass decoupled engine here leaves massive hardware performance on the table!
 * - (The Catastrophic Memory Burn / 3-Pass CPU Thrashing): You are aggressively allocating TWO completely separate O(N) `vector<int>` memory blocks (`nsl` and `nsr`) and forcefully marching the CPU across the timeline EXACTLY THREE TIMES! For a massive array, this violently fragments the heap and completely thrashes the L1 cache!
 * - (Optimization Alert 1 / The 1-Pass Stack Annihilation): You can completely destroy both `vector<int>` allocations and fuse all three passes into a single, blistering O(N) sweep! Think about the kinetic energy of the stack: when an incoming bar `heights[i]` is SMALLER than the stack's top, it mathematically triggers a pop. At that EXACT millisecond, `heights[i]` is strictly proven to be the popped element's NSR! And the element sitting right below it on the stack is its NSL! You can violently calculate `width * height` and update `maxarea` ON THE FLY during the pop, completely vaporizing the need for auxiliary arrays!
 * - (Optimization Alert 2 / The Sentinel Node Nuke): To avoid a messy cleanup `while` loop at the end of the 1-pass algorithm, aggressively inject a dummy `0` into the absolute end of the `heights` array! This massive gravitational anomaly will violently force every single remaining element to pop and resolve its area before the simulation terminates!
 * * How it runs (Current State):
 * First, we safely intercept the histogram and ignite the left-facing radar engine. We sweep the array, aggressively popping larger elements to mathematically lock the Nearest Smaller to Left boundary for every single bar.
 * We instantly ignite the right-facing radar, sweeping in reverse to ruthlessly secure the Nearest Smaller to Right boundaries.
 * We trigger the final collision sweep! For every single histogram bar, we violently extract its left and right boundaries, mathematically forge its maximum width, and smash it against its height to calculate the localized area.
 * We aggressively update our global `maxarea` register.
 * Finally, we confidently output the absolute largest continuous block of space, flawlessly crushing the problem!
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
};
