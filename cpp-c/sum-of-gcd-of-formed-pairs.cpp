/*Leetcode ps-3867. Sum of GCD of Formed Pairs
You are given an integer array nums of length n.
Construct an array prefixGcd where for each index i:
Let mxi = max(nums[0], nums[1], ..., nums[i]).
prefixGcd[i] = gcd(nums[i], mxi).
After constructing prefixGcd:
Sort prefixGcd in non-decreasing order.
Form pairs by taking the smallest unpaired element and the largest unpaired element.
Repeat this process until no more pairs can be formed.
For each formed pair, compute the gcd of the two elements.
If n is odd, the middle element in the prefixGcd array remains unpaired and should be ignored.
Return an integer denoting the sum of the GCD values of all formed pairs.

The term gcd(a, b) denotes the greatest common divisor of a and b.*/


/* Approach - In-place Prefix Tracking & Two Pointers (Time: O(N log N), Space: O(1))
 * Basically, we optimize the problem by calculating the prefix max and its GCD with the current element on the fly, modifying the array in-place before sorting it to naturally pair up the smallest and largest values.
 * * Observation:
 * - We don't need a separate array to store the prefix maximums or the prefix GCDs. Since we only need the maximum up to index 'i' to calculate the GCD for index 'i', we can just keep a running 'curmax' variable and instantly overwrite 'nums[i]' with the GCD result to save O(N) space!
 * - The pairing condition ("smallest unpaired and largest unpaired") is a textbook use case for sorting the array and using two pointers (one at the start, one at the end).
 * - The two-pointer while loop (`i < j`) perfectly handles the odd-length edge case automatically. If the array length is odd, the pointers will eventually point to the exact same middle element (i == j), which safely breaks the loop without processing or pairing it!
 * * How it runs:
 * First, we initialize our running `curmax` to the first element and sweep through the array. At every step, we update `curmax` with `max()` and immediately replace `nums[i]` with the calculated GCD of itself and `curmax`.
 * Then, we sort the completely modified `nums` array in non-decreasing order.
 * Next, we set up our two pointers: `i` at 0 (smallest) and `j` at the last index (largest), along with a `long long sum` variable to track our answer and prevent overflow.
 * Finally, as long as `i < j`, we calculate the GCD of the elements at our two pointers, add it to `sum`, and move the pointers inward (`i++`, `j--`). Once they meet in the middle or cross, the loop breaks, and we return the total sum!
 */


class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int curmax = nums[0],n=nums.size();
        for(int i =0 ;i < n;i++){
            curmax = max(curmax,nums[i]);
            nums[i] = gcd(nums[i],curmax);
        }
        sort(nums.begin(),nums.end());
        int i = 0 , j = n-1;
        long long sum=0;
        while(i<j){
            sum += gcd(nums[i],nums[j]);
            i++;
            j--;
        }
        return sum;
    }
};
