/*Leetcode ps-2958. Length of Longest Subarray With at Most K Frequency
You are given an integer array nums and an integer k.
The frequency of an element x is the number of times it occurs in an array.
An array is called good if the frequency of each element in this array is less than or equal to k.
Return the length of the longest good subarray of nums.
A subarray is a contiguous non-empty sequence of elements within an array.*/


/* Approach - Sliding Window / Dynamic Frequency Map (Time: O(N), Space: O(N))
 * Basically, we aggressively expand a sliding window to gobble up elements, and the exact millisecond any number's frequency violently breaches our limit 'k', we ruthlessly shrink the left boundary until mathematical equilibrium is restored!
 * * Observation: 
 * - The sliding window technique completely annihilates the need for a catastrophic O(N^2) brute force! Because the left pointer 'i' ONLY ever moves forward, every single element in the array is processed a maximum of exactly two times (once entering the window, once leaving). This mathematically guarantees a blistering O(N) total runtime!
 * - (The Absolute Game-Breaker): We don't need to waste CPU cycles scanning the entire frequency map to verify if the window is valid! Because the window was flawlessly valid *before* we expanded 'j', the ONLY element that could possibly break the structural integrity is the exact number we just pulled in: `nums[j]`! Therefore, our inner `while` loop hyper-fixates strictly on fixing `nums[j]`!
 * - (Optimization Note): In your inner loop condition `while(i < j && freq[nums[j]] > k)`, the `i < j` boundary check is actually mathematically redundant! Because `nums[j]` is the exact number causing the overflow, the left pointer `i` is guaranteed to eventually hit an instance of `nums[j]` and violently decrement its frequency long before it could ever physically cross `j`! You could cleanly optimize it to just `while(freq[nums[j]] > k)` to shave off micro-operations!
 * * How it runs:
 * First, we safely deploy our `unordered_map` to track real-time frequencies, securely anchor both our fast pointer `j` and slow pointer `i` exactly at index 0, and set our absolute maximum `result` tracker to 0.
 * Then, we trigger a high-speed forward sweep with `j`. At every single step, we aggressively absorb `nums[j]` into our active window and instantly bump its frequency count in the map!
 * Next, we hit our strict validity check! If the newly added `nums[j]` violently overflows our strict limit `k`, we instantly ignite the inner recovery loop!
 * We ruthlessly evict elements from the extreme left of our window (`freq[nums[i]]--`) and violently snap our left boundary forward (`i++`) step-by-step until the overflowing `nums[j]` is forced perfectly back into compliance!
 * Finally, with the window mathematically verified as completely valid, we aggressively calculate the current window size (`j - i + 1`), relentlessly lock the highest value into our `result` tracker, and confidently advance `j` until the entire array is conquered!
 */


class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int , int> freq;
        int i = 0;
        int j =0;
        int result = 0;
        while(j < n){
            freq[nums[j]]++;

            while(i<j && freq[nums[j]] > k){
                freq[nums[i]]--;
                i++;
            }
            result = max(result,j-i+1);
            j++;
        }
        return result;
    }
};


