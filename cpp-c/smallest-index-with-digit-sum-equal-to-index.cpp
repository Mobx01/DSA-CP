/*Leetcode ps- 3550. Smallest Index With Digit Sum Equal to Index
You are given an integer array nums.
Return the smallest index i such that the sum of the digits of nums[i] is equal to i.
If no such index exists, return -1.*/



/* Approach - Linear Scan with Iterative Digit Summation / Index-Value Matching (Time: O(N log10(MAX)), Space: O(1))
 * Basically, we completely annihilate complex string conversion overhead by aggressively extracting digits using arithmetic modulo-10 operators, identifying the first matching index-digit sum pair in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Modular Digit Extraction Invariant! Instead of casting numbers to strings to count or sum digits (which introduces heavy memory allocations and runtime overhead), your `digsum` helper function cleanly peels off digits via repeated division (`n /= 10`) and modulo (`n % 10`) operations. This operates in logarithmic time relative to the magnitude of each element, making it blazing fast.
 * - (Early Exit Efficiency): Returning immediately upon the first successful match (`if (digsum(nums[i]) == i) return i;`) ensures optimal $O(1)$ best-case performance if a valid condition is met early in the array.
 * - (Zero Auxiliary Space Footprint): The traversal and digit summation require no extra memory structures, maintaining an absolute $O(1)$ auxiliary space complexity.
 * * How it runs:
 * First, we safely intercept the size of our input vector `nums`.
 * We ignite a high-speed linear scan from index `0` up to `n - 1`.
 * For each element, we pass its value to the `digsum` function to calculate the total sum of its individual decimal digits.
 * We compare the resulting digit sum against the current loop index `i`; the moment they match, we return the index.
 * If the loop completes without any matches, we flush `-1` to the output stream with absolute mathematical precision at raw silicon speed!
 */



class Solution {
public:
    int digsum(int n){
        int sum=0;
        while(n>0){
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(digsum(nums[i]) == i) return i;
        }
        return -1;
    }
};
