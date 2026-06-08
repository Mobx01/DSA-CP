/*Leetcode ps - 2161. Partition Array According to Given Pivot
You are given a 0-indexed integer array nums and an integer pivot. Rearrange nums such that the following conditions are satisfied:

Every element less than pivot appears before every element greater than pivot.
Every element equal to pivot appears in between the elements less than and greater than pivot.
The relative order of the elements less than pivot and the elements greater than pivot is maintained.
More formally, consider every pi, pj where pi is the new position of the ith element and pj is the new position of the jth element. If i < j and both elements are smaller (or larger) than pivot, then pi < pj.
Return nums after the rearrangement.*/

/*
 * APPROACH: 3-Step Grouping
 * * The goal is to rearrange the array into three specific parts: 
 * smaller numbers first, equal numbers in the middle, and larger numbers at the end.
 * * Step 1: Separate the numbers
 * - Go through each number in the input array one by one.
 * - If the number is smaller than the pivot, store it in a `lesser` list.
 * - If the number is larger than the pivot, store it in a `greater` list.
 * - If the number is exactly equal to the pivot, just count it using a variable (`eq`).
 * * Step 2: Build the final answer
 * - Create a new empty list for the result.
 * - First, add everything from the `lesser` list (this keeps their original order).
 * - Next, add the `pivot` number as many times as we counted it.
 * - Finally, add everything from the `greater` list (also keeping their original order).
 * * Step 3: Return
 * - Return the newly built result list.
 * * Time Complexity: O(N) because we look at each number a few times.
 * Space Complexity: O(N) because we create extra lists to hold the numbers.
 */


class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> lesser,greater;
        int eq=0;
        for(int i : nums){
            if(i < pivot)lesser.push_back(i);
            else if(i > pivot)greater.push_back(i);
            else eq++;
        }
        vector<int> res;
        for(int i : lesser)res.push_back(i);
        for(int i = 0;i<eq;i++){
            res.push_back(pivot);
        }
        for(int i : greater) res.push_back(i);
         
         return res;
    }
};
