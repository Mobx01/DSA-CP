/*Leetcode ps:- 3471. Find the Largest Almost Missing Integer
You are given an integer array nums and an integer k.
An integer x is almost missing from nums if x appears in exactly one subarray of size k within nums.
Return the largest almost missing integer from nums. If no such integer exists, return -1.
A subarray is a contiguous sequence of elements within an array.*/

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int ret = -1;
        if(k == n) {
            for(int i =0 ;i<n;i++){
                ret = max(ret,nums[i]);
            }
            return ret;
        }
        unordered_map<int,int> freq;
        for(int i = 0 ; i <= n -k ; i++){
            for(int j =i ; j< k+i ;j++){
                freq[nums[j]]++;
            }
        }
        for(auto it = freq.begin();it != freq.end();it++){
            if(it->second == 1) ret = max(ret,it->first);
        }
        return ret;
    }
};


/* Approach - Pure Combinatorial Coverage / O(1) Boundary Isolation (Time: O(N), Space: O(N) -> O(1))
 * Basically, we completely annihilate the need to generate and cross-reference thousands of shifting subarrays by mathematically proving that the geometric coverage of sliding windows ruthlessly disqualifies almost the entire array!
 * * Observation: 
 * - The absolute core of this problem is geometric window coverage. If an element sits anywhere near the middle of the array, a sliding window of size `1 < k < n` will inevitably shift over it multiple times! This mathematically guarantees its subarray frequency will be > 1.
 * - (The Absolute Game-Breaker): You brilliantly deduced that the ONLY elements that can physically survive exactly ONE pass of a sliding window (when 1 < k < n) are the absolute extreme boundary anchors: `nums[0]` and `nums[n-1]`! Every single element trapped between them is structurally doomed to be covered at least twice!
 * - If `k == n`, the window IS the array, so every element is covered exactly once, meaning we just ruthlessly hunt for the global maximum!
 * - (Optimization Alert 1 / The Pre-computation Trap): You aggressively build the massive `unordered_map` at the absolute top of the function! If `k == n`, you instantly return `max_element`, meaning you just burned O(N) time and O(N) memory hashing the entire array for absolutely no reason! Always delay expensive memory allocations until the exact millisecond they are mathematically required!
 * - (Optimization Alert 2 / The O(1) Memory Annihilation): For the `1 < k < n` timeline, you DO NOT need a frequency map! You already mathematically proved you ONLY care about `nums[0]` and `nums[n-1]`. You can instantly shred the space complexity to absolute peak O(1) by dropping the map entirely and simply running a lightning-fast `std::count` strictly for those two boundary targets! 
 * * How it runs:
 * First, we safely extract the array size `n`. (Optimized State): We violently check the `k == n` timeline FIRST! If true, we completely bypass all memory allocations and instantly return the global maximum!
 * If `k == 1`, the window size is a single element, so we physically must track every global frequency. We safely deploy our map, aggressively tally the counts, and relentlessly sweep the keys to extract the maximum element that survived with a frequency of exactly 1!
 * If we land in the `1 < k < n` dimension, we completely bypass the map! We violently isolate the structural boundaries `nums[0]` and `nums[n-1]`.
 * We trigger a strict mathematical radar (using your map, or ideally `std::count`) to verify if they are completely unique in the entire array.
 * If both boundaries are flawless, we ruthlessly pit them against each other and lock in the `max()`. If only one survives, we return it. If the entire array collapses, we mathematically concede and return `-1`, flawlessly crushing the logic with peak theoretical efficiency!
 */


class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
        for(int i:nums){
            freq[i]++;
        }
        if(k == n){
            return *max_element(nums.begin(),nums.end());
        }
        int ans = -1;
        if(k == 1){
            for(auto p : freq){
                if(p.second == 1){
                    ans = max(ans,p.first);
                }
            }
            return ans;
        }else{
            //only extreme end appear single time
            if(freq[nums[0]] == 1 && freq[nums[n-1]] == 1) return max(nums[0],nums[n-1]);
            else if(freq[nums[0]] == 1) return nums[0];
            else if(freq[nums[n-1]] == 1) return nums[n-1];
        }
        return -1;
    }
};
