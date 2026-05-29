/*Leetcode ps- 3300. Minimum Element After Replacement With Digit Sum
You are given an integer array nums.
You replace each element in nums with the sum of its digits.
Return the minimum element in nums after all replacements.*/

/*Approach-
  -just do what they ask for
 */

class Solution {
public:
    int digsum(int i){
        int sum=0;
        while(i>0){
            sum += i%10;
            i/=10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int minsum = INT_MAX;
        for(int i : nums){
            minsum = min(minsum,digsum(i));
        }
        return minsum;
    }
};
