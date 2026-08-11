/*Leetcode ps-2996. Smallest Missing Integer Greater Than Sequential Prefix Sum
You are given a 0-indexed array of integers nums.
A prefix nums[0..i] is sequential if, for all 1 <= j <= i, nums[j] = nums[j - 1] + 1. In particular, the prefix consisting only of nums[0] is sequential.
Return the smallest integer x missing from nums such that x is greater than or equal to the sum of the longest sequential prefix.

*/


/* Approach - Sequential Prefix Sum & Linear Search (Time: O(N^2) [Worst Case], Space: O(1))
 * Basically, we mathematically trace the longest strictly increasing prefix chain, aggressively accumulate its sum, and violently search the array to find the absolute smallest integer greater than or equal to that sum that doesn't physically exist in the array!
 * * Observation: 
 * - The strict constraint of the problem defines a "sequential prefix" as a chain that MUST start directly at index 0 and continuously increment by exactly 1. The exact millisecond the numbers stop perfectly ascending by 1, the prefix is permanently severed!
 * - Once we have our baseline `sum`, we are forced to increment it until we find a number completely absent from the array. 
 * - (The Absolute Game-Breaker / Optimization Alert): Your code deploys `std::find()` inside a massive `while(1)` loop! Because `find()` performs a raw linear scan, this aggressively burns O(N) time for every single increment, structurally dragging your time complexity down to O(N^2)! You could beautifully completely bypass this by dumping the entire array into a `std::unordered_set` or a boolean frequency array in a single O(N) sweep! This would instantly upgrade your search phase to a blistering O(1) lookup per increment, flawlessly guaranteeing a true O(N) overall runtime!
 * * How it runs:
 * First, we safely extract the array size `n`, and securely anchor our baseline `sum` exactly to the very first element `nums[0]`.
 * Then, we trigger a high-speed forward sweep starting directly from index 1. At every single step, we fiercely check the mathematical linkage: `nums[i] == nums[i-1] + 1`. 
 * If the link holds, we aggressively absorb the value into our running `sum`. If the structural chain is broken, we violently snap the loop with a `break`, perfectly isolating our sequential prefix!
 * Next, we ignite an infinite `while(1)` hunting loop. We aggressively deploy `std::find()` to sweep the entire array for our current `sum`.
 * If it physically exists in the array, we aggressively increment `sum++` and immediately hunt again. The exact millisecond `std::find` crashes into `nums.end()` (meaning the number is flawlessly absent), we permanently break the loop!
 * Finally, we confidently return our newly discovered integer, flawlessly delivering the absolute smallest missing valid number!
 */


class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0],n= nums.size();
        for(int i = 1;i< n;i++){
            if(nums[i] == nums[i-1] + 1){
                sum += nums[i];
            }else{
                break;
            }
        }
        while(1){
            auto it = find(nums.begin(),nums.end(),sum);
            if(it == nums.end()) break;
            else{
                sum++;
            }
        }
        return sum;
    }
};
