/*Leetcode ps-992. Subarrays with K Different Integers
Given an integer array nums and an integer k, return the number of good subarrays of nums.
A good array is an array where the number of different integers in that array is exactly k.
For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.*/



/* Approach - At-Most-K Subarray Counting / Exact-K Decoupling via Sliding Window Difference (Time: O(N), Space: O(N) bounded)
 * Basically, we completely annihilate the complex combinatorial exact-k tracking by aggressively applying the set-difference masterstroke: exactly K distinct elements is mathematically equivalent to at-most-K minus at-most-(K-1)!
 * * Observation: 
 * - The absolute core of this architecture is the Exact-K Subtraction Pattern! Directly counting subarrays with *exactly* $k$ distinct elements in a single sliding window is notoriously difficult because the window expansion/contraction invariants break. By transforming the problem into two separate monotonic "at most $k$" passes, you unlock a pristine, bulletproof sliding window that effortlessly handles distinct counting at raw silicon speed!
 * - (The `unordered_map` Hash Overhead Penalty): Your algorithmic logic is absolute textbook perfection, but your data structure choice introduces subtle hardware friction! `unordered_map` forces dynamic heap node allocations, hash calculations, and pointer chasing on every single insertion and erasure. 
 * - (Optimization Alert / The Flat Frequency Array Nuke): Since the element values in these distinct-count problems are typically bounded (or can be coordinate-compressed if sparse), you can completely vaporize the `unordered_map`! Replace it with a stack-allocated, fixed-size frequency array `vector<int> freq(max_val + 1, 0);` alongside a scalar `distinct_count` tracker. This eliminates all hashing and heap pollution, reducing lookups to lightning-fast array indexing!
 * * How it runs:
 * First, we safely intercept the array and invoke our core sliding window engine `sub_with_atmost_k` for the threshold $k$.
 * Inside the engine, we expand our right boundary `r`, tracking distinct element frequencies. The exact millisecond the distinct count exceeds the limit, our contraction loop slides the left boundary `l` forward until the window stabilizes.
 * We accumulate the number of valid subarrays ending at `r` using the classic formula `r - l + 1`.
 * We call the exact same function a second time with threshold $k - 1$.
 * Finally, we subtract the result of the second pass from the first pass (`atMost(k) - atMost(k-1)`), flushing the exact-k distinct subarray count to the output stream with absolute mathematical precision!
 */



class Solution {
public:
    int sub_with_atmost_k(vector<int>& nums,int k){
        unordered_map<int,int> freq;
        int n = nums.size(),l=0,r=0,good=0;

        while(r < n){
            freq[nums[r]]++;
            while(freq.size() > k){
                freq[nums[l]]--;
                if(freq[nums[l]] ==0){
                    freq.erase(nums[l]);
                }
                l++;
            }
            good += r -l+ 1;
            r++;
        }
        return good;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return sub_with_atmost_k(nums,k) - sub_with_atmost_k(nums,k-1);
    }
};
