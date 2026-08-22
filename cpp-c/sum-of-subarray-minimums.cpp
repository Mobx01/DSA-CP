/*Leetcode ps-907. Sum of Subarray Minimums
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.*/


/* Approach - Monotonic Stack / Combinatorial Contribution Math (Time: O(N), Space: O(N))
 * Basically, we completely annihilate the catastrophic O(N^2) subarray generation by violently flipping the perspective: instead of finding the minimum of every subarray, we mathematically calculate exactly how many subarrays every single element COMPLETELY DOMINATES!
 * * Observation: 
 * - The absolute core of this architecture relies on the Monotonic Stack! By strictly maintaining an increasing order inside the stack, you aggressively map the absolute boundaries of an element's dominance in both directions (left and right) in a blistering O(N) linear sweep!
 * - (The Absolute Game-Breaker / The Duplicate Nuke): Look incredibly closely at your two monotonic engines. In `getnsl`, you pop when `st.top() > arr[i]`. But in `getnsr`, you pop when `st.top() >= arr[i]`! That asymmetrical `=` sign is an absolute mathematical masterpiece! If the array has duplicates (e.g., `[2, 2, 2]`), symmetrical conditions would violently double-count the subarrays! Your asymmetrical strictness flawlessly forces only ONE of the duplicates to take absolute control of the shared timeline, completely preventing combinatorial overlap!
 * - (The Fatal 32-Bit Overflow Trap): Look at your combinatorial math: `long long totalways = ls * rs;`. This is a catastrophic ticking time bomb! Both `ls` and `rs` are 32-bit integers. If the array size pushes to 10^5, `ls * rs` could easily be `10^5 * 10^5 = 10^{10}`. Because the calculation executes in 32-bit space BEFORE being assigned to the 64-bit `long long`, it will violently shatter the integer ceiling and store completely corrupted negative garbage! You MUST instantly upgrade the hardware execution: `long long totalways = 1LL * ls * rs;` to force the CPU into the 64-bit dimension immediately!
 * - (Optimization Alert / The 1-Pass Annihilation): Your modular 3-pass architecture (NSL, NSR, then Sum) is flawlessly readable. But if you want to achieve absolute peak memory efficiency, you can completely destroy the `getnsl` and `getnsr` functions! By running a single loop and processing the combinatorial math the exact millisecond an element is popped from the stack, you can shred the space complexity from three O(N) vectors down to just one stack!
 * * How it runs:
 * First, we safely intercept the array size `n` and ignite our two independent monotonic stack engines, aggressively sweeping left-to-right to lock in the Next Smaller Left boundaries, and right-to-left to secure the Next Smaller Right boundaries.
 * We instantly initialize our massive 64-bit `sum` register and lock our modulo engine `M` to `1e9 + 7`.
 * We trigger a high-speed linear sweep across the main array. For every single element, we mathematically extract its left spread `ls` and its right spread `rs`.
 * We violently multiply `ls` and `rs` to instantly generate the absolute total number of valid subarrays where `arr[i]` reigns supreme!
 * We scale the element's raw value by its total dominance (`arr[i] * totalways`), aggressively accumulate it into our `sum` register, and instantly apply the modulo operator to mathematically shield the engine from overflow!
 * Finally, we confidently return the flawless modulo sum, completely bypassing millions of subarray simulations!
 */



class Solution {
public:
    vector<int> getnsl(vector<int>& arr, int n){
        vector<int> res(n);
        stack<int> st;
        for(int i =0;i<n;i++){
            if(st.empty()){
                res[i] = -1;
            }else{
                while(!st.empty() && arr[st.top()] > arr[i]) st.pop();

                res[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        return res;
    }
     vector<int> getnsr(vector<int>& arr, int n){
        vector<int> res(n);
        stack<int> st;
        for(int i =n-1;i>=0;i--){
            if(st.empty()){
                res[i] = n;
            }else{
                while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

                res[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }
        return res;
    }
    int sumSubarrayMins(vector<int>& arr) {
       int n = arr.size();
       vector<int> nsl = getnsl(arr,n); 
       vector<int> nsr = getnsr(arr,n); 

       long long sum =0;
       int M = 1e9 +7;

       for(int i=0;i<n;i++){
        int ls = i-nsl[i];//elements in left
        int rs = nsr[i] -i;//elements in right

        long long totalways = ls*rs; // total subarray with min as arr[i]

        long long totalsum = arr[i]*totalways;
        sum = (sum + totalsum)%M;
       }
       return sum;
    }
};
