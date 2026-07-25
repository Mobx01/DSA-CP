/*Leetcode ps-3536. Maximum Product of Two Digits
You are given a positive integer n.
Return the maximum product of any two digits in n.
Note: You may use the same digit twice if it appears more than once in n.*/

/* Approach - Digit Extraction & Sorting (Time: O(log N), Space: O(log N))
 * Basically, we tear the integer apart into its individual digits, sort them from smallest to largest, and multiply the two absolute biggest digits together to find the maximum possible product!
 * * Observation: 
 * - The maximum product of any two individual digits will mathematically always come from the two absolutely largest digits available.
 * - By repeatedly using modulo 10 (`% 10`), we cleanly strip off the last digit, and integer division by 10 (`/ 10`) smoothly shifts the remaining number down.
 * - (Bug Alert: The code currently has absolutely no safety net for small numbers! If `n` is less than 10, the vector will have fewer than 2 elements, causing a fatal out-of-bounds crash when accessing `digits.size() - 2`. Additionally, if `n` is 0 or negative, the `while(t > 0)` loop completely fails to execute, returning garbage data!)
 * * How it runs:
 * First, we create a temporary copy 't' of our number and initialize an empty 'digits' vector to physically hold our extracted numbers.
 * Then, we trigger a while loop to rip apart the integer base-10 style, pushing every single extracted digit directly into our vector until the number is completely reduced to 0.
 * Next, we sweep through and sort the entire vector in ascending order using C++'s built-in `sort()`, which flawlessly pushes the largest digits to the absolute back of the array.
 * Finally, we blindly reach into the back of the vector to grab the two largest elements, instantly multiply them together, and confidently return our maximum product!
 */


class Solution {
public:
    int maxProduct(int n) {
        int t = n;
        vector<int> digits;
        while(t > 0){
            digits.push_back(t%10);
            t /= 10;            
        }
        sort(digits.begin(),digits.end());
        return digits[digits.size() - 1] * digits[digits.size() - 2];
    }
};
