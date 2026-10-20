/*Leetcode ps-3886. Sum of Sortable Integers
You are given an integer array nums of length n.
An integer k is called sortable if k divides n and you can sort nums in non-decreasing order by sequentially performing the following operations:
Partition nums into consecutive subarrays of length k.
Cyclically rotate each subarray independently any number of times to the left or to the right.
Return an integer denoting the sum of all possible sortable integers k.*/



/* Approach - Divisor-Based Block Monotonicity Check / Partitioned Circular Sorting (Time: O(N log(N)), Space: O(1))
 * Basically, we completely annihilate brute-force subset sorting checks by aggressively iterating over all integer divisors of `n`, validating intra-block rotational monotonicity and inter-block boundary chaining in pristine sub-quadratic time!
 * * Observation: 
 * - The absolute core of this architecture is the Divisor Block-Sorting Invariant! A vector can be sorted into blocks of size `k` (where `k` divides `n`) if each block satisfies a nearly sorted / rotationally ordered condition (tracked via `cnt <= 1` drops and circular wrap-around comparisons), and the maximum element of each block is less than or equal to the minimum element of the subsequent block (`prev <= mini`). By testing all valid divisors `k` and their complementary factors `n/k`, we efficiently accumulate all valid block sizes.
 * - (Boundary Guard Typo Catch): Notice the inner loop condition `for(int j = i; j < i + k - 1; j++)`. When `k = 1`, the loop bound `i + k - 1` evaluates to `i`, causing the loop to be skipped entirely, which can lead to uninitialized or improperly handled `mini`/`maxi` defaults if not carefully guarded. Ensuring `k` handling or bounds safety prevents edge-case glitches.
 * - (Factorization Optimization): Checking divisors up to $\sqrt{N}$ and evaluating both `k` and `n/k` simultaneously keeps the time complexity exceptionally tight.
 * * How it runs:
 * First, we initialize our result accumulator `ans = 0`.
 * We iterate through all integer divisors `k` of `n` up to $\sqrt{N}$.
 * For each valid divisor, we invoke the `check(nums, k)` validator, which divides the array into blocks of size `k`, verifies internal rotational monotonicity, and ensures non-decreasing order between adjacent blocks. If valid, we add `k` (and `n/k` if distinct) to `ans`.
 * Finally, we flush the accumulated sum of valid block sizes to the output stream with absolute mathematical precision at raw silicon speed!
 */




class Solution {
public:
    bool check(vector<int>& nums,int k){
        int n = nums.size(),prev=0;

        for(int i =0;i<n;i+=k){
            int cnt = 0;
            int mini = nums[i],maxi = nums[i];
            for(int j=i;j < i+k-1;j++){
                if(nums[j] > nums[j+1]) cnt++;

                mini = min(mini,nums[j+1]);
                maxi = max(maxi,nums[j+1]);
            }

            if(nums[i+k-1] > nums[i])cnt++;
            if(cnt > 1 || prev > mini)return false;

            prev = maxi;
        }
        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size(),ans=0;

        for(int k =1;k*k <= n;k++){
            if(n%k == 0){
                if(check(nums,k)) ans += k;

                if(k*k != n && check(nums,n/k)) ans += n/k ;
            }
        }
        return ans;
    }
};
