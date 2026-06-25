/*Leetcode ps - 3739. Count Subarrays With Majority Element II
You are given an integer array nums and an integer target.
Return the number of subarrays of nums in which target is the majority element.
The majority element of a subarray is the element that appears strictly more than half of the times in that subarray.

*/

/* Approach - Optimized Prefix Sum with Hash Map 
 * Basically, we optimize our previous +1/-1 prefix sum approach to run in O(N) time! Instead of using a nested loop to look back at all previous sums, we dynamically maintain a running count of valid starting points that are strictly less than our current running sum.
 * We keep 3 main variables/structures to track this magic:
 * - 'cumsum' tracks the running balance of +1s (targets) and -1s (non-targets).
 * - 'freq' is a hash map that remembers exactly how many times we've seen each specific 'cumsum' value in the past.
 * - 'validlpoints' keeps a running total of how many past prefix sums are strictly smaller than our current 'cumsum'.
 *
 * How it runs:
 * First, we initialize our 'freq' map by recording that a sum of 0 has appeared exactly once (representing the empty prefix before the array starts).
 * Then we loop through the array exactly once:
 * If we hit our target (+1), our 'cumsum' is about to increase. This means all previous points where the sum was exactly our *current* 'cumsum' will now be strictly less than our *new* sum. So, we add their frequency to 'validlpoints', and then increase our 'cumsum'.
 * If we hit a non-target (-1), our 'cumsum' is about to decrease. This means the previous points that equal our *new* 'cumsum' are no longer strictly less than our current state (they are now equal to it). So, we decrease our 'cumsum', and subtract their frequency from 'validlpoints'.
 * Right after updating the math for the current step, we add our 'validlpoints' to our total 'ans', and tally our new 'cumsum' in the 'freq' map so it can be used by future steps!
 */

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        long long ans=0;
        long long cumsum=0,validlpoints=0;
        unordered_map<int,int> freq;//store frequecy of cumsum apperad before
        freq[0]++; //at starting the cumsum is 0

        for(int i = 0 ; i < n ; i++){
            if(nums[i] == target){
                validlpoints += freq[cumsum];
                cumsum +=1;
            }else{
                cumsum -= 1;
                validlpoints -= freq[cumsum];
            }
            freq[cumsum]++;
            ans += validlpoints;
        }
        return ans;
    }
};

