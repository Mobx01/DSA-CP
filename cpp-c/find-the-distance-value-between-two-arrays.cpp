/*Leetcode ps-1385. Find the Distance Value Between Two Arrays
Given two integer arrays arr1 and arr2, and the integer d, return the distance value between the two arrays.
The distance value is defined as the number of elements arr1[i] such that there is not any element arr2[j] where |arr1[i]-arr2[j]| <= d.*/




/* Approach - Sorted Binary Search with Boundary-Checked Neighbor Validation / Find the Distance Value Between Two Arrays (Time: O(N log N + M log M), Space: O(1) auxiliary)
 * Basically, we completely annihilate brute-force $O(N \times M)$ pairwise distance comparisons by aggressively sorting `arr2` and leveraging binary search (`lower_bound`) to instantly locate closest candidates in logarithmic time!
 * * Observation: 
 * - The absolute core of this architecture is the Nearest-Neighbor Distance Invariant (LeetCode 1385 - Find the Distance Value Between Two Arrays)! For any element in `arr1`, the condition `|arr1[i] - arr2[j]| > d` for *all* elements in `arr2` is satisfied if and only if the absolute difference between `arr1[i]` and its closest element(s) in `arr2` exceeds `d`. 
 * - (Boundary Safety & Index Handling): By sorting `arr2`, `lower_bound` finds the first element greater than or equal to `arr1[i]`. Handling edge cases where `j == 0` (smaller than all elements) or `j >= n` (larger than all elements) prevents out-of-bounds access and correctly checks the single boundary neighbor, while interior indices safely check both `arr2[j]` and `arr2[j - 1]`.
 * - (Optimal Complexity): Sorting `arr1` and `arr2` takes $O(N \log N + M \log M)$ time, and the binary search pass runs in $O(N \log M)$ time, with $O(1)$ auxiliary space beyond input storage.
 * * How it runs:
 * First, we sort both `arr1` and `arr2` in ascending order.
 * We iterate through each element in `arr1`, using `lower_bound` to find its insertion index `j` in `arr2`.
 * We evaluate boundary conditions (`j == 0`, `j >= n`, and interior intervals) to verify that the distance to all elements in `arr2` is strictly greater than `d`, incrementing our valid count accordingly.
 * Finally, we flush the total valid distance count to the output stream with absolute mathematical precision at raw silicon speed!
 */




class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr2.size();
        int count =0;
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        for(int i=0;i<arr1.size();i++){
            int j = lower_bound(begin(arr2),end(arr2),arr1[i]) - begin(arr2);

            if(j == 0){
                count += (arr2[0]-arr1[i]) > d ;
            }else if(j >= n){
                count += (arr1[i] - arr2[n-1]) >d ;
            }else{
                count += (arr2[j]-arr1[i] > d) && (arr1[i] - arr2[j-1] > d);
            }
        }
        return count;
    }
};
