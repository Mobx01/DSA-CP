/*Leetcode ps-238. Product of Array Except Self
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.*/
/**
 * Approach: Prefix and Suffix Products
 * * 1. Concept: For any element at index 'i', the product of all elements except 
 * nums[i] is equal to (Product of all elements to the left) * (Product of all elements to the right).
 * * 2. Prefix Pass: 
 * - Create a 'preprod' array where preprod[i] stores the product of all elements 
 * from index 0 to i-1. 
 * - Base case: preprod[0] = 1 (nothing to the left of the first element).
 * * 3. Suffix Pass:
 * - Create a 'postprod' array where postprod[i] stores the product of all elements 
 * from index i+1 to n-1.
 * - Base case: postprod[n-1] = 1 (nothing to the right of the last element).
 * * 4. Final Calculation:
 * - result[i] = preprod[i] * postprod[i].
 * * Complexity:
 * - Time: O(n) - We iterate through the array three separate times.
 * - Space: O(n) - We use two auxiliary arrays (preprod and postprod) of size n.
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> preprod(n);
        vector<int> postprod(n);
        preprod[0]=1;
        postprod[n-1]=1;
        for(int i = 1;i<n;i++){
            preprod[i] = preprod[i-1]*nums[i-1];
        }
        for(int i = n-2 ;i >= 0;i--){
            postprod[i] = postprod[i+1]*nums[i+1];
        }
        vector<int> result(n);
        for(int i = 0 ; i<n;i++){
            result[i] = preprod[i]*postprod[i];
        }
        return result;
    }
};
