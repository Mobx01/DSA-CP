/*Leetcode ps -3978. Unique Middle Element
You are given an integer array nums of odd length n.
Return true if the middle element of nums appears exactly once in the array. Otherwise return false.
*/

/* Approach - Sorting and Neighbor Checking
 * Basically, we identify the middle element, sort the entire array to group any identical numbers together, and then search for our target to see if it has any duplicate neighbors.
 * Observation: 
 * - Sorting inherently forces all duplicate numbers to sit directly next to each other. Therefore, if our target element appears more than once in the array, those extra copies will definitively be found at index `i - 1` or `i + 1` relative to where we initially spot it.
 * - (Note: While this logic works perfectly, sorting the array takes O(N log N) time. You could optimize this to O(N) space and time by skipping the sort entirely and just doing a single loop to count how many times `middlelement` appears!)
 *
 * How it runs:
 * First, we check our base case: if the array has exactly 1 element, it is mathematically guaranteed to be unique, so we return true.
 * Then, we extract and save our target number from the middle of the array (`nums[n/2]`) before we lose its original structural position, and we sort the entire array.
 * Next, we sweep through our newly sorted array to find where our target landed.
 * The moment we find it at index 'i', we inspect its immediate boundaries. If the element directly to its left (`nums[i-1]`) or directly to its right (`nums[i+1]`) is identical to it, we know a duplicate exists, so we return false.
 * If neither neighbor matches (safeguarded by bound checks), the element stands completely alone, meaning it's unique, so we return true!
 */

class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        int middlelement = nums[n/2];
        sort(nums.begin(),nums.end());
        for(int i = 0 ;i < n; i++){
            if(nums[i] == middlelement){
                if((i > 0 && nums[i-1] == middlelement) || (i<n-1 && nums[i+1] == middlelement)) return false;
                return true;
            }
        }
        return false;
    }
};
