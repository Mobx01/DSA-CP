/*Leetcode ps-930. Binary Subarrays With Sum
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
A subarray is a contiguous part of the array.*/


/* Approach - At-Most Window Difference / Prefix Sum Frequency Mapping (Time: O(N), Space: O(N) or O(1))
 * Basically, we completely annihilate the complex edge cases of exact-sum sliding windows by decoupling the problem into two monotonic bounds, or tracking prefix frequencies for absolute mathematical bulletproofing!
 * * Observation: 
 * - The absolute core of this architecture is the Exact-Sum Decomposition! Finding subarrays that sum *exactly* to `goal` is notoriously difficult with a single sliding window because zeros disrupt monotonicity. The masterstroke is converting it into: `AtMost(goal) - AtMost(goal - 1)`! Because the "at most" function is strictly monotonic, a pure, flawless O(1)-space sliding window can compute each part with zero zero-counting hacks!
 * - (The Leading-Zero Logic Trap): Your ingenious attempt to track `countz` (leading zeros) to multiply valid endpoints is a classic manual optimization for exact-sum windows. However, it introduces complex branch conditions and subtle edge-case vulnerabilities when multiple zeros cluster around non-zero boundaries, leading to potential miscalculations in high-density zero arrays.
 * - (Alternative Architecture / Prefix Sum Hash Map): If you prefer a single-pass implementation without sliding window gymnastics, deploying a `std::unordered_map` to track prefix sum frequencies transforms the problem into a two-sum variant. While it trades O(1) space for O(N) space, it completely eliminates window boundary bugs and handles negative numbers or complex constraints effortlessly.
 * * How it runs (The At-Most Sliding Window Vision):
 * First, we safely intercept the array and define a helper function `atMost(nums, goal)` that calculates the total number of subarrays with a sum less than or equal to `goal`.
 * We ignite a pure, monotonic sliding window inside the helper function, expanding `r` and contracting `l` strictly when the sum exceeds the budget, with zero complex zero-tracking logic required.
 * We invoke this helper twice: `atMost(nums, goal) - atMost(nums, goal - 1)`.
 * Finally, the mathematical subtraction cleanly isolates the exact count of subarrays summing precisely to `goal`, flawlessly crushing the problem with absolute precision and zero fragility!
 */



class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=0,n=nums.size(),r=0,l=0,sum=0,countz =0;

        while(r < n){
            sum += nums[r];
            while(l < r && (nums[l] == 0 || sum > goal)){
                if(nums[l] == 0){
                    countz++;
                }else{
                    countz = 0;
                }
                sum -= nums[l];
                l++;
                
            }


            if(sum == goal){
                ans += (countz + 1); 
            }
            r++;
        }
        
        return ans;
    }
};
