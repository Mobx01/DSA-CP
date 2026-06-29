/*Leetcode ps - 560. Subarray Sum Equals K
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.*/


/* Approach - Prefix Sum with Hash Map
 * Basically, we use cumulative sums to find subarrays that add up to 'k' without needing slow nested loops. By remembering the frequencies of all previous prefix sums, we can instantly look back and verify if a valid subarray exists.
 * Observation: 
 * - The sum of any subarray from index 'i+1' to 'j' is just `prefix[j] - prefix[i]`. 
 * - If we want this sum to equal 'k' (`prefix[j] - prefix[i] == k`), we can mathematically rearrange the equation to `prefix[i] = prefix[j] - k`. This means if we are currently at a running sum of `prefix[j]`, we just need to check our history to see if we have ever encountered the sum `prefix[j] - k`!
 *
 * We keep 3 main variables/structures to track this: 
 * - 'prefixsum' array stores the running total of elements up to each index.
 * - 'freq' is a hash map that remembers exactly how many times we've seen each specific prefix sum in the past.
 * - 'count' keeps a running tally of all the valid subarrays we've found.
 *
 * How it runs:
 * First, we do an initial pass through the array to build our 'prefixsum' array, adding the current number to the previous sum.
 * Then, we loop through our 'prefixsum' array to evaluate the sums:
 * If the current prefix sum is exactly 'k', it means the entire subarray from the very beginning up to this point naturally equals 'k', so we immediately increment our 'count'.
 * Next, we check if our required mathematical complement (`prefixsum[i] - k`) already exists in our 'freq' map. If it does, we add its recorded frequency to our 'count', because each past occurrence represents a valid starting point for a subarray that perfectly ends at our current position.
 * Finally, right before moving to the next number, we tally our current `prefixsum[i]` into the 'freq' map so it can act as a starting point for future elements!
 */


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0,n=nums.size();
        vector<int> prefixsum(n);//including the number itself in the prefixsum
        prefixsum[0] = nums[0];
        for(int i=1;i<n;i++){
            prefixsum[i] = prefixsum[i-1] + nums[i];
        }      

        // prefix[j]-prefix[i]=k  -> prefix[i] = prefix[j] -k we can store occurence of one to find the other
        unordered_map<int,int> freq;
        for(int i =0 ;i<n;i++){
            if(prefixsum[i] == k){
                count++;
            }
            if(freq.find(prefixsum[i] - k) != freq.end()) count += freq[prefixsum[i] - k];//we got the subarray
            freq[prefixsum[i]]++;
        }
        return count;
    }
};
