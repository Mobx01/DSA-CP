/*Leetcode ps-239. Sliding Window Maximum
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
Return the max sliding window.*/


/* Approach - Monotonic Deque / Temporal Expiration Engine (Time: O(N), Space: O(K))
 * Basically, we completely annihilate the O(N * K) brute force sliding window by aggressively deploying a Monotonic Deque, violently shredding smaller, mathematically useless elements from the timeline while flawlessly tracking the expiration of the absolute maximum!
 * * Observation: 
 * - The absolute core of this physics engine is the Monotonic Decreasing property! If a massive element enters the window, any smaller element ahead of it is mathematically DOOMED! It will NEVER be the maximum again for the rest of its lifespan! You ruthlessly exploit this by violently popping them out the back of the deque before they even have a chance to waste CPU cycles!
 * - (The Fatal Heap Reallocation Bomb): Your algorithmic logic is absolute O(N) perfection, but your memory architecture is a ticking time bomb! `vector<int> result;` dynamically allocates memory on the heap. As you push elements, it will violently breach its capacity, forcing the CPU to allocate a massive new memory block and copy everything over, completely thrashing the L1 cache! You ALREADY KNOW the exact mathematical size of the final array! You MUST instantly deploy `result.reserve(n - k + 1);` at the very top to lock in a single, perfectly contiguous block of RAM before the simulation even starts!
 * - (The Hardware Equality Bypass): Look incredibly closely at your expiration radar: `deq.front() <= i - k`. Because your timeline strictly advances by exactly ONE index per cycle, and you clean the deque every single cycle, it is mathematically impossible for an index to somehow slip past and become `< i - k`! You can violently swap this to a pure equality check: `deq.front() == i - k`! This shreds the less-than-or-equal evaluation down to a raw hardware-level identity check!
 * - (The std::deque Chunking Trap): While `std::deque` is the standard weapon of choice, under the hood it aggressively allocates disjoint memory chunks. For absolute, peak theoretical hardware supremacy in competitive programming, you completely abandon `std::deque` and deploy a static `int q[N];` array with a raw `head` and `tail` pointer! This locks the entire engine into a single L1 cache line, blazing through the simulation at raw silicon speed!
 * * How it runs:
 * First, we safely intercept the timeline and (ideally) pre-allocate our `result` register to flawlessly absorb the exact output size.
 * We ignite a high-speed linear sweep! For every incoming element at index `i`, we trigger a dual-phase radar check.
 * Phase 1 (Expiration): We violently check the front of the deque. If the absolute maximum element has physically aged out of our `k`-sized spatial window, we ruthlessly amputate it from the timeline!
 * Phase 2 (Dominance): We aggressively evaluate the incoming element against the tail of the deque. We trigger the `while` loop, violently popping every single smaller element out of existence because they have been permanently mathematically eclipsed!
 * We forcefully slam the incoming index onto the back of the deque, officially locking it into the timeline.
 * The exact millisecond the timeline reaches the required `k` width (`i >= k - 1`), our engine stabilizes! We continuously harvest the front of the deque (the guaranteed absolute maximum) and aggressively stream it directly into our output register, flawlessly crushing the simulation!
 */


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> deq;
        vector<int> result;
        int n = nums.size();
        for(int i =0;i<n;i++){

            //make space for nums(if window size > k)
            while(!deq.empty() && deq.front() <= i-k){
                deq.pop_front();
            }
            // pop small elements(compared to new elemnt(nums[i])) index in the deq 
            while(!deq.empty() && nums[i] >= nums[deq.back()]){
                deq.pop_back();
            }
            //now push i in deque -> for nums[i]
            deq.push_back(i);
    
            // if (i < k-1) dront is our answer
            if(i >= k-1){
                result.push_back(nums[deq.front()]);
            }
            
        } 

        return result;
    }
};
