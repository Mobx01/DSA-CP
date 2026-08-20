/*Leetcode ps-3069. Distribute Elements Into Two Arrays I
You are given a 1-indexed array of distinct integers nums of length n.
You need to distribute all the elements of nums between two arrays arr1 and arr2 using n operations. In the first operation, append nums[1] to arr1. In the second operation, append nums[2] to arr2. Afterwards, in the ith operation:
If the last element of arr1 is greater than the last element of arr2, append nums[i] to arr1. Otherwise, append nums[i] to arr2.
The array result is formed by concatenating the arrays arr1 and arr2. For example, if arr1 == [1,2,3] and arr2 == [4,5,6], then result = [1,2,3,4,5,6].

Return the array result.

*/


/* Approach - Greedy Array Partitioning / O(1) Endpoint Polling (Time: O(N), Space: O(N))
 * Basically, we violently split the universe into two dynamic arrays, mathematically polling strictly their extreme right boundaries to aggressively route every incoming element in a blistering O(N) linear sweep!
 * * Observation: 
 * - The absolute core of this simulation is the hyper-fixation on the `back()` elements. Because the routing strictly cares ONLY about the most recently inserted element, you completely bypass the need for massive subarray scans or frequency maps!
 * - (Optimization Alert 1 / The Memory Pre-Allocation): `std::vector` dynamically doubles its capacity behind the scenes, aggressively burning CPU cycles repeatedly reallocating memory as it grows! Since you mathematically know the absolute combined size of `arr1` and `arr2` will ALWAYS exactly equal `N`, you can instantly deploy `arr1.reserve(n)` and `arr2.reserve(n)` right out of the gate! This forces the hardware to permanently lock in the maximum memory footprint in a single, flawless O(1) operation!
 * - (Optimization Alert 2 / The Concatenation Nuke): You deployed a manual `for` loop to meticulously push elements from `arr2` into `arr1` one by one. You can completely annihilate this loop by triggering the C++ standard library's built-in block copy: `arr1.insert(arr1.end(), arr2.begin(), arr2.end())`! This aggressively memory-maps the entire second array directly onto the tail of the first array in absolute peak theoretical time, completely bypassing element-by-element iteration!
 * * How it runs:
 * First, we safely intercept the array size `n`, instantly seeding our two parallel dimensions `arr1` and `arr2` with the absolute first two elements of `nums`.
 * Then, we ignite a high-speed forward sweep starting exactly at index 2.
 * For every single incoming element, we aggressively fire our boundary radar! We pit `arr1.back()` directly against `arr2.back()`.
 * If `arr1`'s tail mathematically dominates, we violently smash the new element into `arr1`. Otherwise, it gets ruthlessly routed to `arr2`!
 * Finally, the exact millisecond the sweep finishes, we aggressively fuse the two timelines together, appending `arr2` directly onto the back of `arr1`, and confidently return the flawlessly distributed array without dropping a single integer!
 */



class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int n = nums.size();
        for(int i=2;i<n;i++){
            if(arr1.back() > arr2.back()) arr1.push_back(nums[i]);
            else arr2.push_back(nums[i]);
        }
        n = arr2.size();
        for(int i =0;i<n;i++){
            arr1.push_back(arr2[i]);
        }
        return arr1;
    }
};
