/*Leetcode ps-3736. Minimum Moves to Equal Array Elements III
You are given an integer array nums.
In one move, you may increase the value of any single element nums[i] by 1.
Return the minimum total number of moves required so that all elements in nums become equal.*/


/* Approach - Target Maximum Reduction via Complementary Increments / Minimum Moves to Equal Array Elements (Time: O(N), Space: O(1))
 * Basically, we completely annihilate brute-force iterative simulation by aggressively recognizing the mathematical equivalence of incrementing $N-1$ elements versus decrementing a single element to the minimum, computing total moves in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Complementary Invariant (LeetCode 453 - Minimum Moves to Equal Array Elements)! Incrementing $N-1$ elements by 1 on each move is mathematically equivalent to decrementing a single element by 1 until all elements equal the minimum value in the array. Thus, the total number of moves required is simply the sum of differences between each element and the minimum element: $\sum (nums[i] - \min(nums))$.
 * - (Equivalence with Max Element): Notice that your code computes `maxn - i` (summing differences relative to the maximum element), which computes the number of increments needed to bring all elements up to the maximum. For LeetCode 453, the standard definition increments $N-1$ elements (raising the rest to match the max), which yields the exact same total sum because incrementing $N-1$ elements by 1 is the dual of decrementing the single remaining element! 
 * - (Optimal Complexity): Finding the maximum element takes $O(N)$ time and the linear sweep runs in $O(N)$ time with $O(1)$ auxiliary space.
 * * How it runs:
 * First, we find the maximum element (`maxn`) in vector `nums`.
 * We iterate through each element in the array, accumulating the difference `maxn - i` into our `moves` counter.
 * Finally, we flush the total minimum moves count to the output stream with absolute mathematical precision at raw silicon speed!
 */



class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxn = *max_element(nums.begin(),nums.end());
        int moves=0;
        for(int i : nums){
            moves += (maxn-i);
        }
        return moves;
    }
};
