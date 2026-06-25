/*Leetcode ps - 3737. Count Subarrays With Majority Element I
You are given an integer array nums and an integer target.
Return the number of subarrays of nums in which target is the majority element.
The majority element of a subarray is the element that appears strictly more than half of the times in that subarray.*/

/* Approach - Brute Force (Not optimal)
 * Basically just checking every single possible subarray to see if the target element appears in it strictly more than half the time.
 * We keep 2 main variables to track our progress: 
 * - 'totalcount' keeps a running tally of all the valid majority subarrays we've found so far.
 * - 'count' tracks how many times our specific 'target' number has appeared in the current subarray we are looking at.
 *
 * How it runs:
 * First, we start an outer loop with 'i' to pick the starting index of our subarray, resetting 'count' to 0 for each new start.
 * Then we start an inner loop with 'j' starting from 'i' to incrementally expand our subarray element by element.
 * As we expand the subarray, if the current element matches the target, we increase our 'count'.
 * Right after that, we calculate the length of the current subarray ('len') and check if our 'count' is strictly greater than half the length (written as 'len < 2 * count'). If it is, we found a valid majority subarray and increment 'totalcount'!
 */

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int totalcount =0, n=nums.size();
        for(int i =0 ; i< n;i++){
            int count=0;
            for(int j = i;j<n;j++){
                if(nums[j] == target) count++;

                int len = j-i+1;
                if(len < 2*count)  totalcount++;
            }
        }
        return totalcount;
    }
};



/* Approach - Prefix Sum with +1/-1 Mapping (Not optimal - space complexity O(N))
 * Basically, we transform the problem into finding subarrays with a positive sum by treating our target number as +1 and all other numbers as -1. If a subarray's sum is strictly greater than 0, the target appears more times than everything else combined.
 * We keep 2 main variables/structures to track this: 
 * - 'pref' array tracks the cumulative sum of these +1s and -1s from the start of the array.
 * - 'ans' keeps a running tally of all the valid majority subarrays we've found.
 *
 * How it runs:
 * First, we do a single pass through the array to build our 'pref' array. We add 1 to the running total if we see the target, and subtract 1 otherwise.
 * Then, we use a nested loop to check all possible subarrays. The outer loop 'i' sets the start point, and the inner loop 'j' sets the end point.
 * For each subarray from index 'i' to 'j', we instantly find its sum by calculating `pref[j+1] - pref[i]`. If this difference is strictly greater than 0, we found a valid majority subarray and increment 'ans'!
 */

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        long long ans=0;
        vector<int> pref(n+1,0);

        for(int i = 0 ; i < n ; i++){
            pref[i+1] = pref[i] + (nums[i]== target ? 1 : -1);
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if((pref[j+1] - pref[i]) > 0) ans++; // if number of target  > number of non target then target has more than len/2 frequency. 
            }
        }
        return ans;
    }
};


// target -> +1
// target -> -1








