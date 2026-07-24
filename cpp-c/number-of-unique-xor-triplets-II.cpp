/*Leetcode ps-3514. Number of Unique XOR Triplets II
You are given an integer array nums.
A XOR triplet is defined as the XOR of three elements nums[i] XOR nums[j] XOR nums[k] where i <= j <= k.
Return the number of unique XOR triplet values from all possible triplets (i, j, k).*/


/* Approach - Brute-Force Hash Sets / All Combinations (Time: O(N^3), Space: O(N^2))
 * Basically, we use hash sets to exhaustively compute and store every single possible XOR combination of two elements, and then XOR those results with the array again to find all unique triplet combinations!
 * * Observation: 
 * - By starting the inner loop at `j = i`, you brilliantly include the XOR of an element with itself (which always yields 0). This correctly covers cases where triplets might reuse the same index!
 * - An `unordered_set` is the perfect data structure here because it automatically filters out duplicate values, preventing us from overcounting identical XOR results.
 * - However, this brute-force approach generates up to O(N^2) unique pairs in the first step. In the second step, looping through the array (size N) and the `pairxor` set (size up to N^2) brings the worst-case time complexity to a massive O(N^3). Depending on the problem constraints, this could very easily hit a Time Limit Exceeded (TLE) error!
 * * How it runs:
 * First, we initialize an `unordered_set` named `pairxor` to physically track our unique pairwise results, and grab the total array size 'n'.
 * Then, we trigger a double nested loop to sweep through the array, XORing every possible pair `nums[i]` and `nums[j]` together, and directly inserting the result into `pairxor`.
 * Next, we create a second `unordered_set` named `ans`. We loop through every element `nums[i]` in the original array one more time, and inner-loop through every single saved value 'k' inside `pairxor`.
 * Finally, we compute the final triplet XOR (`k ^ nums[i]`) and insert it into 'ans'. Once the exhaustive sweep completely finishes, we confidently return the absolute `size()` of our beautifully filtered 'ans' set!
 */

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> pairxor;
        int n = nums.size();
        for(int i = 0 ; i < n ;i++){
            for(int j = i ; j<n;j++){
                pairxor.insert(nums[i]^nums[j]);
            }
        }
        unordered_set<int> ans;
        for(int i = 0 ; i < n;i++){
            for(int k : pairxor){
                ans.insert(k^nums[i]);
            }
        }
        return ans.size();
    }
};


/* Approach - Bitwise Upper Bound & Boolean Array Hashing (Time: O(N^2 + N * maxEl), Space: O(maxEl))
 * Basically, we optimize the previous hash set approach by mathematically bounding the maximum possible XOR value and using lightning-fast boolean arrays for direct O(1) lookups!
 * * Observation: 
 * - The absolute maximum XOR value that can be produced by any elements in the array is mathematically bounded by the next perfect power of 2 strictly greater than the array's maximum element (`maxEl`).
 * - By precomputing this upper bound `T`, we can completely replace the heavy, collision-prone `unordered_set` with two simple `vector<bool>` arrays (`s1` and `s2`). This beautifully drops the lookup and insertion time to a true, guaranteed O(1)!
 * - Using the bitwise left shift operator (`T <<= 1`) is a highly optimized, low-level way to repeatedly multiply by 2 until we safely exceed `maxEl`.
 * * How it runs:
 * First, we find the largest element in the array and calculate our bitwise ceiling `T`. We then initialize our two boolean vectors, `s1` and `s2`, perfectly sized to hold any valid XOR result up to `T`.
 * Then, we run a double nested loop to compute all pairwise XOR combinations, instantly flagging their exact indices in `s1` as true.
 * Next, we sweep through our safely bounded range `T`. Any time we encounter a valid pair (`s1[i] == true`), we trigger an inner loop to XOR it against every single element in `nums` and flag the newly formed triplet result in `s2`.
 * Finally, we perform one last simple linear sweep directly across `s2` to tally up all the uniquely flagged triplet results, and confidently return the final `count`!
 */

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int maxEl = *max_element(begin(nums), end(nums));

        int T = 1;
        while(T <= maxEl) {
            T <<= 1; //T = T*2
        }

        vector<bool> s1(T, false); //XOR pair values set to true
        vector<bool> s2(T, false); //XOR triplet values set to true

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                s1[nums[i] ^ nums[j]] = true;
            }
        }

        for(int i = 0; i < T; i++) {
            if(s1[i] == true) {
                for(int &num : nums) {
                    s2[i ^ num] = true;
                }
            }
        }

        int count = 0; //unique xor count
        for(int i = 0; i < T; i++) {
            if(s2[i] == true)
                count++;
        }

        return count;

        
    }
};


