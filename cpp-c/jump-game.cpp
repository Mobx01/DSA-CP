/*Leetcode ps-55. Jump Game
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.*/




/* Approach - Greedy Max-Reachability Tracking (Time: O(N), Space: O(1))
 * Basically, we completely annihilate the O(N^2) top-down DP time complexity and recursion stack overhead by aggressively deploying a greedy pointer, tracking the furthest reachable index in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Maximum Reachability Invariant! You don't actually need to simulate every single jump path or cache intermediate states. As you sweep across the array from left to right, you only need to maintain a single scalar register (`max_reach`) representing the furthest index you can possibly jump to. If your current index ever exceeds `max_reach`, you've hit a dead wall and can return `false`. If `max_reach` extends past or touches the last index, you instantly return `true`!
 * - (The O(N^2) Top-Down Bottleneck): Your current memoized recursion is logically sound, but the inner loop (`for(int i = 1; i <= nums[ind]; i++)`) can still evaluate up to $O(N)$ states per position in the worst case (e.g., when all jump values are large), leading to an overall $O(N^2)$ time complexity and heavy recursive stack frames that risk stack overflow on massive arrays.
 * - (Optimization Alert / The O(1) Space Greedy Nuke): By stripping away the memoization vector `t`, the recursive function stack, and the inner loop entirely, you reduce the space complexity from O(N) down to absolute peak O(1) with zero allocation overhead!
 * * How it runs:
 * First, we initialize our `max_reach` register to 0.
 * We ignite a high-speed linear traversal, sweeping our index `i` across the array up to `n - 1`.
 * The exact millisecond our current index `i` exceeds `max_reach`, we know movement is blocked and return `false`.
 * Otherwise, we greedily expand our horizon: `max_reach = max(max_reach, i + nums[i])`.
 * If our reach sweeps past the final index, we triumphantly return `true` with absolute mathematical precision at raw silicon speed!
 */



class Solution {
public:
    vector<int> t;
    bool solve(int ind,vector<int>& nums){
        int n = nums.size();
        if(ind >= n-1) return true;

        if(t[ind] != -1)return t[ind];

        for(int i = 1 ; i<= nums[ind];i++){
            if(solve(ind+i,nums)){
                return t[ind] = true;
            }
        }
        return t[ind] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        t.assign(n, -1);   
        return solve(0,nums);
    }
};


/* Approach - Greedy Max-Reachability Engine (Time: O(N), Space: O(1))
 * Basically, we completely annihilate redundant iterations by aggressively tracking the furthest boundary, executing an absolute masterclass in clean, optimal greedy architecture!
 * * Observation: 
 * - The absolute core of this architecture is the Optimal Greedy Invariant! Your implementation is pristine: checking `if (i > maxreach)` upfront catches dead ends immediately, and updating `maxreach` dynamically maps the exact frontier of movement.
 * - (The Early-Exit Optimization Win): `if (maxreach >= n - 1) return true;`. This is an absolute stroke of engineering genius! By breaking out of the loop the exact millisecond the finish line is guaranteed within reach, you save precious CPU cycles on trailing elements, squeezing out maximum performance at raw silicon speed!
 * * How it runs:
 * First, we initialize our `maxreach` register to 0 and intercept the array size `n`.
 * We ignite a high-speed linear sweep across the array indices.
 * If our current index exceeds `maxreach`, movement is blocked, and we instantly return `false`.
 * Otherwise, we greedily expand our horizon and check if the finish line has been breached.
 * If the sweep completes successfully or triggers an early exit, we flush the boolean result with absolute mathematical precision at raw silicon speed!
 */


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxreach =0;
        for(int i=0;i<n;i++){

            if(i > maxreach) return false; //we cant reach this index to move forword
            int reach = i + nums[i];

            maxreach = max(maxreach , reach);

            if(maxreach >= n-1) return true;
        }
        return false;
    }
};




