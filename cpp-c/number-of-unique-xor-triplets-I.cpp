/*Leetcode ps-3513. Number of Unique XOR Triplets I
You are given an integer array nums of length n, where nums is a permutation of the numbers in the range [1, n].
A XOR triplet is defined as the XOR of three elements nums[i] XOR nums[j] XOR nums[k] where i <= j <= k.
Return the number of unique XOR triplet values from all possible triplets (i, j, k).*/

/* Approach - Next Power of Two / Math (Time: O(log N), Space: O(1))
 * Basically, we mathematically compute the smallest exact power of 2 that is strictly greater than the array's size, handling sizes 1 and 2 as special base cases!
 * * Observation: 
 * - The logic inherently scales exponentially. Instead of stepping through linearly, multiplying by 2 allows us to find the upper bound in logarithmic time.
 * - For any array size 'n' greater than 2, the loop continuously doubles 'ans' until it completely surpasses 'n', effectively locking in the next immediate power of 2.
 * - For the extreme edge cases where the array only has 1 or 2 elements, the code explicitly bypasses the math loop and instantly returns 'n' directly.
 * * How it runs:
 * First, we extract the size of the array 'n'. If 'n' is exactly 1 or 2, we immediately trigger our edge-case condition and return 'n'.
 * Then, we initialize our tracker 'ans' to 1.
 * Next, we enter a while loop that continuously scales 'ans' by multiplying it by 2 as long as it remains less than or equal to 'n'.
 * Finally, the exact moment 'ans' mathematically exceeds 'n', the loop breaks, and we return our newly calculated upper bound!
 */


class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 || n == 2) return n;
        int ans= 1;
        while(ans <= n){
            ans *= 2;
        }
        return ans;
    }
};
