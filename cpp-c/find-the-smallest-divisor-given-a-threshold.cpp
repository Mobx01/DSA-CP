/*Leetcode ps- 1283. Find the Smallest Divisor Given a Threshold
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.
Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).
The test cases are generated so that there will be an answer.*/

/* Approach - Binary Search on Answer (Time: O(N log M), Space: O(N) due to pass-by-value) where M is max(nums)
 * Basically, we use binary search to guess the optimal divisor. Since a larger divisor mathematically guarantees a smaller or equal total sum, the relationship is perfectly monotonic, making it ideal for binary search.
 * * Observation:
 * - The smallest possible valid divisor is 1, and the largest practically useful divisor is the maximum element in the array (because any divisor larger than the max element will just round every single element down to 1 anyway).
 * - Every division requires rounding up (ceiling). Using `num % div != 0 ? num / div + 1 : num / div` handles this perfectly using purely integers, avoiding slow floating-point math.
 * - (Note on Space: Your 'rescal' function currently takes the 'nums' vector by value! This creates a brand new O(N) copy of the entire array every single time binary search takes a guess. Changing the parameter to pass-by-reference like `const vector<int>& nums` will instantly optimize your solution to O(1) space!)
 * * How it runs:
 * First, we establish our binary search boundaries: 'l' is 1 (the smallest possible divisor) and 'r' is the maximum element in the array.
 * Then, we enter our standard while loop to guess a middle divisor ('mid'). We pass this guess to our 'rescal' helper function, which loops through the array, divides every element by 'mid', rounds up, and returns the total sum.
 * Finally, we evaluate that sum. If the sum is strictly greater than our 'threshold', it means our divisor was too small (resulting in a sum that is too big), so we push our lower bound up ('l = mid + 1'). If the sum is safely within the threshold, it is a valid answer! We record 'mid' as our 'ans' and pull our upper bound down ('r = mid - 1') to hunt for an even smaller valid divisor!
 */

class Solution {
public:
    int rescal(int div,vector<int> nums){
        int sum =0;
        for(int num : nums){
            sum += num%div != 0 ? num/div + 1 : num/div;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = *max_element(nums.begin(),nums.end());
        int ans;

        while(l<=r){
            int mid = l +(r-l)/2;
            int sum = rescal(mid,nums);
            if(sum > threshold){// not a valid divisior need bigger divisior
                l = mid+1;
            }else{// valid divisor check for lesser one
                r = mid- 1;
                ans = mid;
            }
        }
        return ans;
    }
};
