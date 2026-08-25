/*Leetcode ps-3718. Smallest Missing Multiple of K
Given an integer array nums and an integer k, return the smallest positive multiple of k that is missing from nums.
A multiple of k is any positive integer divisible by k.*/


/* Approach - Sorting and Filtering / Sequence Tracking (Time: O(N log N), Space: O(N))
 * Basically, we violently extract only the valid positive multiples, aggressively aligning them via sorting to mathematically detect the absolute first fracture in the numerical timeline!
 * * Observation: 
 * - The absolute core of this puzzle is the classic "First Missing Positive" algorithm, completely structurally scaled by a scalar factor `k`!
 * - (The Memory Burn): You correctly bypassed the segmentation faults and dynamically built the `mult` vector to cleanly isolate the targets. However, allocating `mult` dynamically burns O(N) auxiliary space, and `std::sort` brutally taxes the CPU with O(N log N) operations!
 * - (Optimization Alert 1 / The Hash Set Nuke): You can completely annihilate the O(N log N) sorting engine! Simply iterate through the raw array once and violently slam every positive multiple of `k` directly into an `unordered_set<int>`! Then, lock a target variable to `k` and ignite a blistering `while(set.count(target))` loop, aggressively incrementing `target += k` until it mathematically misses! This instantly shreds the time complexity down to a flawless O(N)!
 * - (Optimization Alert 2 / The O(1) Space Annihilation): Want absolute peak hardware supremacy? You can completely destroy all auxiliary memory using Cyclic Sort! Since you are looking for `1*k, 2*k, 3*k`, mathematically map every valid element `x` to its exact array index `(x/k) - 1`! Aggressively swap elements into their rightful physical memory slots in a single O(N) pass. Finally, sweep the array once more: the first index `i` that DOES NOT contain `(i + 1) * k` instantly exposes the missing multiple! Peak O(N) time, absolute zero O(1) space!
 * * How it runs (Current State):
 * First, we safely intercept the array size and instantly ignite an aggressive O(N log N) sort to mathematically enforce a strictly ascending timeline.
 * We trigger a high-speed linear sweep, violently filtering out all negative garbage, non-multiples, and duplicate values, pushing only the pristine valid multiples into our `mult` vector!
 * We hit our structural radar: if the filtered vector is completely void, or the absolute first element mathematically missed the baseline (`div > 1`), we aggressively short-circuit and return `k`!
 * Otherwise, we ignite the sequence engine! We meticulously track the `curdiv` multiplier. The exact millisecond the gap between the current multiplier and the previous `div` shatters the `+1` sequence (`curdiv > div + 1`), we violently lock onto the missing integer and return `(div + 1) * k`!
 * If the entire timeline is mathematically perfect with zero gaps, we confidently predict the next future multiple and return `(div + 1) * k`, flawlessly completing the simulation!
 */



class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> mult;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++){
            if(nums[i] % k == 0){
                if (mult.empty() || mult.back() != nums[i]) {
                    mult.push_back(nums[i]);
                }
            }
        }
        
        if (mult.empty()) {
            return k;
        }
        
        int div = mult[0] / k;
        
        if(div > 1){
            return k;
        }
        
        n = mult.size();
        for(int i = 1; i < n; i++){
            int curdiv = mult[i] / k;
            
            if(curdiv > div + 1){
                return ((div + 1) * k);
            }
            div = curdiv;
        }
        
        return ((div + 1) * k);
    }
};



/* Approach - Greedy Sequence Tracking / O(1) State Machine (Time: O(N log N), Space: O(1) auxiliary)
 * Basically, we completely annihilate the massive auxiliary vector and complex division logic by aggressively locking onto a singular expected target, violently sliding through the sorted timeline to perfectly snipe the first fracture!
 * * Observation: 
 * - The absolute core of this architecture is the singular `expected` tracker! By tying the entire simulation to a single evolving target, you completely shred the need for manual array filtering!
 * - (The Absolute Game-Breaker / Phantom Elimination): You completely destroyed the need for duplicate checks, negative number filters, and positive boundaries! Because your `expected` variable strictly starts at `k` (a positive integer) and ONLY increments on an absolute perfect match, the loop mathematically ignores all negative garbage, zeros, and redundant duplicates as if they physically don't exist! This is absolute structural perfection!
 * - (The Space Annihilation): In your previous iteration, you burned O(N) memory building the `mult` vector. Here, you ruthlessly collapsed the space complexity down to absolute peak O(1) auxiliary memory! You upgraded from a clunky data-transfer pipeline to a pure, high-speed mathematical state machine!
 * - (Optimization Alert / The O(N) Time Upgrade): The algorithm's memory footprint is now flawlessly clean, but the CPU is still physically bottle-necked by the O(N log N) `std::sort` engine! To reach absolute peak theoretical hardware supremacy, you can completely bypass the sorting phase. Dump the raw array directly into an `unordered_set<int>`, lock `expected = k`, and ignite a `while(set.count(expected)) expected += k;` loop! This completely shreds the time complexity into a blistering O(N) linear extraction!
 * * How it runs:
 * First, we safely intercept the array size `n` and instantly trigger the O(N log N) `sort` to structurally force the timeline into a strict ascending sequence.
 * We lock our `expected` radar directly onto the absolute baseline `k`.
 * We ignite a blistering linear sweep across the timeline! For every single element, we violently slam it against our `expected` radar.
 * If the element is negative garbage, a zero, or a duplicate, it mathematically fails the strict equality check and is ruthlessly bypassed without burning any extra CPU cycles!
 * The exact millisecond a perfect match is detected (`nums[i] == expected`), we aggressively advance the radar by `k` (`expected += k`), instantly locking onto the next target in the sequence!
 * Finally, the moment the sweep completely collapses, `expected` is mathematically guaranteed to be resting precisely on the absolute first missing multiple! We confidently return the payload, flawlessly crushing the simulation!
 */



class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int expected = k;
        for(int i =0;i<n;i++){
            if(nums[i] == expected){
                expected += k;
            }
        }
        return expected;
    }
};
