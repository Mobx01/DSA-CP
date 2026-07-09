/*Leetcode ps-1539. Kth Missing Positive Number
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
Return the kth positive integer that is missing from this array.*/

/* Approach - Binary Search on Missing Numbers (Time: O(log N), Space: O(1))
 * Basically, we use binary search to quickly locate the interval where the Kth missing number falls by mathematically calculating how many numbers are missing up to any given index.
 * * Observation: 
 * - In a perfect array with zero missing numbers (1, 2, 3, 4...), the value at index 'i' should always be exactly 'i + 1'.
 * - Therefore, if we look at any index 'mid', the exact number of missing elements *before* that index is simply 'nums[mid] - (mid + 1)'.
 * - Because the array is strictly increasing, this count of missing numbers is monotonically increasing. This guarantees we can use binary search! 
 * - When the search perfectly converges and finishes, pointer 'l' will represent the exact number of existing array elements that appear *before* our target missing number. Since we want the Kth missing number, the mathematical answer is just the elements we skipped plus 'k' itself (l + k)!
 * * How it runs:
 * First, we initialize our binary search boundaries 'l = 0' and 'r = n - 1'.
 * Then, we loop as long as 'l <= r', calculating 'mid' and checking how many numbers are currently missing before it ('missing_till_mid = nums[mid] - (mid + 1)').
 * Next, we evaluate: if 'missing_till_mid < k', we haven't skipped enough numbers yet, so the Kth missing number must be further to the right ('l = mid + 1'). If it is greater than or equal to 'k', the target is either at 'mid' or to its left, so we pull our right boundary down ('r = mid - 1').
 * Finally, once the pointers cross, our search is complete. We simply return 'l + k' to get the exact value of the Kth missing positive integer!
 */

class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0 , r= n-1;
        int mid = -1;
        while(l<=r){
            mid = l + (r-l)/2;
            int missing_till_mid= nums[mid] - (mid+1);

            if(missing_till_mid < k){// gp on right
                l = mid+1;
            }else{// gp left side
                r = mid-1;
            }
        }
        return l+k;
    }
};
