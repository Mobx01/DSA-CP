/*Leetcode ps - 128. Longest Consecutive Sequence
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.*/




/* Approach - Hash Set Sequence Start Filtering / O(N) Consecutive Chain Tracking (Time: O(N), Space: O(N))
 * Basically, we completely annihilate brute-force sorting overhead by aggressively hashing elements into an unordered set and only initiating sequence scans from true sequence start boundaries in pristine linear time!
 * * Observation: 
 * - The absolute core of this architecture is the Sequence Start Invariant (LeetCode 128 - Longest Consecutive Sequence)! Instead of sorting the array in $O(N \log N)$ time, inserting all elements into an `unordered_set` allows $O(1)$ average-time lookups. By checking whether `num - 1` exists in the set, we can identify true sequence starting points (numbers that have no preceding neighbor). This ensures each consecutive sequence is scanned exactly once, guaranteeing a strict $O(N)$ time complexity.
 * - (Underflow Protection Safety): Including the explicit guard `num == INT_MIN` prevents potential integer underflow or overflow issues when evaluating `num - 1` or boundary increments against limits like `INT_MAX`.
 * - (Linear Average-Time Efficiency): Although there is an inner `while` loop, every number is part of at most one sequence scan, keeping total operations linear.
 * * How it runs:
 * First, we copy all elements from vector `nums` into an `unordered_set` to achieve instantaneous membership checks and eliminate duplicates.
 * We ignite a linear sweep across the set elements. For each number, we check if its predecessor `num - 1` exists; if it does not (or if `num == INT_MIN`), it marks the beginning of a consecutive chain.
 * We trace upwards with an inner `while` loop as long as successive elements exist in the set, counting the chain length and updating our maximum `longest` record.
 * Finally, we flush the maximum consecutive sequence length to the output stream with absolute mathematical precision at raw silicon speed!
 */



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());

        int longest =0;
        for(int num : st){
            if(num == INT_MIN || !st.count(num -1)){
                int cur = num;
                int count =1;

                while(cur != INT_MAX && st.count(cur+1)){
                    cur++;
                    count++;
                }

                longest = max(longest,count);
            }
        }
        return longest;
    }
};
