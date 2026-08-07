/*Leetcode ps-410. Split Array Largest Sum
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
Return the minimized largest sum of the split.
A subarray is a contiguous part of the array.*/

/* Approach - Binary Search on Answer & Greedy Allocation (Time: O(N log(SUM)), Space: O(1))
 * Basically, we mathematically weaponize Binary Search to guess the exact optimal maximum subarray sum, and deploy a hyper-aggressive greedy checker to flawlessly verify if the array can be sliced up without violating our 'k' limit!
 * * Observation: 
 * - This problem screams Binary Search! Why? Because the validity of our "max sum limit" is perfectly monotonic. If a max sum of 50 allows us to successfully split the array, a max sum of 51 is mathematically guaranteed to work too. But if 49 fails, 48 will violently fail as well! This creates a flawless true/false boundary.
 * - (The Absolute Bounds): What is the absolute smallest maximum sum we could ever possibly have? It's the single largest element in the entire array (because you physically cannot split a single number)! What is the absolute largest sum? It's simply grabbing the entire array and shoving it into 1 massive block (sum of all elements)! This beautifully locks our binary search space strictly between `max_element` and `total_sum`.
 * - To verify a guessed sum (`mid`), we don't need any complex dynamic programming. We just greedily sweep left-to-right, forcefully packing as many numbers as physically possible into our current subarray until adding one more would push it over `mid`. The exact millisecond it overflows, we ruthlessly sever the subarray, start a new one, and check if our total slice count exceeds `k`!
 * * How it runs:
 * First, we safely trigger a quick linear sweep to calculate our absolute highest bound (`sum` of all elements), and deploy `max_element` to securely anchor our lowest possible bound `l`.
 * Then, we ignite our massive binary search. For every single `mid` guessed, we instantly throw it into our high-speed `isposs` checker function.
 * Inside `isposs`, we aggressively sweep through `nums`, accumulating `cursum`. The second a number pushes `cursum` strictly greater than `mid`, we snap the chain, increment our `subarr` cut counter, and drop that number directly into the brand new subarray. 
 * If our greedy slicing forces us to make strictly more than `k` subarrays, the `mid` limit is far too tight, and it instantly returns `false`!
 * Finally, back in the binary search, if the limit was mathematically possible, we securely lock `mid` into `ans` and violently crush our right bound (`r = mid - 1`) to hunt for an even tighter max sum. If it failed, we forcefully push our left bound up. Once the search collapses, we confidently return our flawless optimal limit!
 */


class Solution {
public:

    bool isposs(int mid,vector<int>& nums,int k){
        int cursum = 0 , subarr =0;
        for(int i : nums){
            cursum += i;
            if(cursum > mid){
                subarr++;
                cursum = i;
            }
        }
        if(cursum <= mid)subarr++;
        if(subarr > k) return false;
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int sum = 0;
        for(int i : nums){
            sum += i;
        }
        //binary search ion output
        int l = *max_element(nums.begin(),nums.end());
        int r = sum;
        int ans = r;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(isposs(mid,nums,k)){
                ans = mid;
                r = mid -1;
            }else{
                l = mid +1;
            }
        }
        return ans;
    }
};
