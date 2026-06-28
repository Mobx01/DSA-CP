/*Leetcode ps -1846. Maximum Element After Decreasing and Rearranging
You are given an array of positive integers arr. Perform some operations (possibly none) on arr so that it satisfies these conditions:
The value of the first element in arr must be 1.
The absolute difference between any 2 adjacent elements must be less than or equal to 1. In other words, abs(arr[i] - arr[i - 1]) <= 1 for each i where 1 <= i < arr.length (0-indexed). abs(x) is the absolute value of x.
There are 2 types of operations that you can perform any number of times:
Decrease the value of any element of arr to a smaller positive integer.
Rearrange the elements of arr to be in any order.
Return the maximum possible value of an element in arr after performing the operations to satisfy the conditions.*/


/* Approach - Greedy with Sorting (Time complexity O(nlog(n)))
 * Basically, we sort the array first to naturally arrange the smallest numbers at the beginning, which allows us to build up to the maximum possible value step-by-step without breaking the rules.
 * We don't need any extra data structures, just modifying the array in-place!
 *
 * How it runs:
 * First, we sort the array in ascending order. Since the problem allows us to rearrange elements however we want, sorting guarantees we don't waste small numbers at the end where they would force our final answer down.
 * Then, we forcefully set the very first element at index 0 to 1, perfectly satisfying the first rule of the problem.
 * Next, we loop through the rest of the array starting from index 1:
 * We compare the current number to the previous one. To maximize our elements while obeying the rules, the current number can be at most one greater than the previous number. If it's larger than that, we greedily reduce it to exactly 'previous + 1'. If it's equal, we just leave it alone!
 * Because we sorted it and are greedily incrementing by at most 1, the absolute maximum possible valid element will naturally end up at the very last index of our array. We just return that!
 */

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        arr[0]=1;//according to condition
        for(int i=1 ;i<n;i++){
            if(arr[i]>arr[i-1]){
                arr[i] = arr[i-1]+1;//can only differ by 1
            }
        }
        return arr[n-1];
    }
};
