/*Leetcode ps-3942. Minimum Operations to Sort a Permutation
You are given an integer array nums of length n, where nums is a permutation of the integers from 0 to n - 1.

You may perform only the following operations:

Reverse the entire array.
Rotate Left by One: Move the first element to the end of the array, and rest elements to left by one position.
Return an integer denoting the minimum number of operations required to sort the array in increasing order. If it is not possible to sort the array using only the given operations, return -1.*/

/* Approach - Circular Rotation Monotonicity Analysis / Rotated Array Shift Optimization (Time: O(N), Space: O(1))
 * Basically, we completely annihilate brute-force rotation simulation by aggressively tracking contiguous ascending and descending modulo-step patterns, calculating minimum shift distances in pristine linear time and constant space!
 * * Observation: 
 * - The absolute core of this architecture is the Rotated Sequence Monotonicity Invariant! By scanning adjacent elements to check whether they form a continuous circular sequence (ascending or descending modulo $N$), we can instantly determine if the array is rotationally sortable. If `asc == n - 1` or `des == n - 1`, the array represents a valid rotated permutation.
 * - (Constant Auxiliary Space Footprint): Tallying transitions with scalar registers (`asc`, `des`) avoids any auxiliary data structure allocation, running in strict $O(1)$ auxiliary space.
 * - (Linear Time Efficiency): Inspecting the array in a single linear pass guarantees optimal $O(N)$ execution speed.
 * * How it runs:
 * First, we initialize our sequence counters `asc` and `des`.
 * We ignite a high-speed linear scan from index `1` to `n - 1`, tracking wrap-around monotonic relationships between adjacent elements.
 * We evaluate whether the ascending or descending tally matches the required `n - 1` threshold: if valid, we calculate the optimal shift distance via boundary offsets; otherwise, we return `-1` to indicate the array cannot be sorted via rotation.
 * Finally, we flush the minimum operation count to the output stream with absolute mathematical precision at raw silicon speed!
 */


class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int asc=0;
        int des=0;
        for(int i=1;i<n;i++){
            asc+=nums[i]==(nums[i-1]+1)%n;
            des+=nums[i-1]==(nums[i]+1)%n;

        }
        if(asc==n-1){
            if(nums[0]==0){
                return 0;

            }
            int left=n-nums[0];
            int right=(nums.back()+1)+2;
            return min(left,right);
        }
        if(des==n-1){
            int left=n-nums.back()+1;
             int right=(nums[0]+1)%n+1;
             return min(left,right);
        }
        return -1;
    }
};
