/*Leetcode ps- 2149. Rearrange Array Elements by Sign
You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.
You should return the array of nums such that the array follows the given conditions:
Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.*/

/* Approach - Two-Pass Separation and Merge 
 * Basically, we separate the positive and negative numbers into two different lists to preserve their original relative order, then weave them back together in an alternating pattern.
 * We keep 2 auxiliary arrays and some pointers to track the elements: 
 * - 'pos' array tracks all strictly positive numbers in the exact order they appear.
 * - 'neg' array tracks all strictly negative numbers in the exact order they appear.
 * - 'j' and 'k' act as pointers to track our current position in the 'pos' and 'neg' arrays during the merge step.
 *
 * How it runs:
 * First, we do a single pass through the original 'nums' array and push elements into either 'pos' or 'neg' depending on whether they are greater or less than zero.
 * Then we loop through the 'nums' array a second time to overwrite it using an index 'i':
 * If our current index 'i' is even (0, 2, 4...), we grab the next available number from our 'pos' array, assign it to nums[i], and increment our positive pointer 'j'.
 * If our current index 'i' is odd (1, 3, 5...), we grab the next available number from our 'neg' array, assign it to nums[i], and increment our negative pointer 'k'.
 */


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos , neg;
        for(int x : nums){
            if(x > 0)pos.push_back(x);
            else neg.push_back(x);
        }
        int n = nums.size();
        for(int i = 0,j=0,k=0;i < n;i++){
            if(i%2 ==0 ){
                nums[i] = pos[j];
                j++;
            }else{
                nums[i] = neg[k];
                k++;
            }
        }
        return nums;
    }
};
