/*Leetcode ps -2104. Sum of Subarray Ranges
You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.
Return the sum of all subarray ranges of nums.
A subarray is a contiguous non-empty sequence of elements within an array.*/


/* Approach - Monotonic Stack / Combinatorial Superposition (Time: O(N), Space: O(N))
 * Basically, we completely annihilate the catastrophic O(N^2) brute force simulation by aggressively mapping the absolute boundaries of dominance for every single element, mathematically superpositioning the total maximums against the total minimums to instantly extract the global range!
 * * Observation: 
 * - The absolute core of this architecture is the "Subarray Range = Max - Min" mathematical property! Instead of violently calculating the range of every individual subarray, you compute the total sum of all maximums and ruthlessly subtract the total sum of all minimums! 
 * - (The Absolute Game-Breaker / The Duplicate Symmetry): Look incredibly closely at your strict vs. non-strict inequalities across all FOUR stack engines! For minimums: `>=` (left) and `>` (right). For maximums: `<=` (left) and `<` (right). This is an absolute combinatorial masterpiece! By purposefully making one side strict and the other non-strict, you flawlessly prevent violently double-counting subarrays when identical twins (duplicates) appear in the timeline! ONE duplicate is mathematically forced to take absolute control!
 * - (The Hardware Shield / 64-Bit Supremacy): You aggressively anchored `ls`, `rs`, `totalways`, and `totalsum` into massive 64-bit `long long` registers right at the source! If the array size pushed to massive constraints, `ls * rs` would violently shatter a standard 32-bit integer ceiling before it even reached the total sum! Your architecture flawlessly tanks the impact!
 * - (Optimization Alert / The 6-Pass CPU Burn): Your logic is mathematically pristine and wonderfully modular, but you aggressively burn CPU cycles looping over the array EXACTLY SIX TIMES (NSL, NSR, MinSum, NGL, NGR, MaxSum)! You can completely destroy this architectural bloat! By calculating the combinatorial weight the exact millisecond an element is violently popped from the stack, you can shred all 6 passes down to just a single unified O(N) sweep, completely annihilating the need for four separate O(N) `vector<int>` memory allocations!
 * * How it runs:
 * First, we safely intercept the array and ignite a massive 4-engine monotonic stack sequence, aggressively sweeping back and forth to securely lock in the absolute Next Smaller and Next Greater boundaries in both directions!
 * We trigger the `sumSubarrayMins` calculation! For every single element, we mathematically extract its left spread `ls` and its right spread `rs`, violently multiplying them to capture every possible timeline where `arr[i]` reigns as the absolute minimum.
 * We instantly ignite the `sumSubarraymaxs` engine, repeating the exact same combinatorial math to map the absolute peaks!
 * Finally, we violently smash the two massive sums together! We aggressively subtract the total minimums directly from the total maximums, instantly forging the absolute global sum of all subarray ranges in blistering O(N) hardware speed!
 */



class Solution {
public:
    // Nearest Smaller to Left (Strictly less on left, or less-than-or-equal)
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

    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nsl = getnsl(arr, n); 
        vector<int> nsr = getnsr(arr, n); 

        long long sum = 0;

        for (int i = 0; i < n; i++) {
            long long ls = i - nsl[i]; // elements in left
            long long rs = nsr[i] - i; // elements in right

            long long totalways = ls * rs; // total subarrays with min as arr[i]
            long long totalsum = (long long)arr[i] * totalways;
            sum += totalsum;
        }
        return sum;
    }

    // Nearest Greater to Left
    vector<int> getngl(vector<int>& arr, int n) {
        vector<int> res(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            res[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return res;
    }

    // Nearest Greater to Right
    vector<int> getngr(vector<int>& arr, int n) {
        vector<int> res(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            res[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return res;
    }

    long long sumSubarraymaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> ngl = getngl(arr, n); 
        vector<int> ngr = getngr(arr, n); 

        long long sum = 0;

        for (int i = 0; i < n; i++) {
            long long ls = i - ngl[i]; // elements in left
            long long rs = ngr[i] - i; // elements in right

            long long totalways = ls * rs; // total subarrays with max as arr[i]
            long long totalsum = (long long)arr[i] * totalways;
            sum += totalsum;
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarraymaxs(nums) - sumSubarrayMins(nums);
    }
};
