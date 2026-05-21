/*Leetcode ps- 3043. Find the Length of the Longest Common Prefix
You are given two arrays with positive integers arr1 and arr2.
A prefix of a positive integer is an integer formed by one or more of its digits, starting from its leftmost digit. For example, 123 is a prefix of the integer 12345, while 234 is not.
A common prefix of two integers a and b is an integer c, such that c is a prefix of both a and b. For example, 5655359 and 56554 have common prefixes 565 and 5655 while 1223 and 43456 do not have a common prefix.
You need to find the length of the longest common prefix between all pairs of integers (x, y) such that x belongs to arr1 and y belongs to arr2.
Return the length of the longest common prefix among all pairs. If no common prefix exists among them, return 0.*/

/*
 * APPROACH:
 * 
 * 1. Build a lookup table of all prefixes from the first array.
 *    - We iterate through every number in arr1.
 *    - For each number, we continuously chop off the last digit (by dividing by 10) 
 *      and store every resulting prefix into a hash set. 
 *    - This gives us a quick O(1) way to check if any specific prefix exists in arr1.
 * 
 * 2. Compare prefixes from the second array against our lookup table.
 *    - We iterate through every number in arr2.
 *    - For each number, we first count its total number of digits so we know the length 
 *      of the prefix we are currently looking at.
 * 
 * 3. Find the longest match.
 *    - Starting with the full number from arr2, we check if it exists in our hash set.
 *    - If it does, we've found a match! We update our maximum length tracking variable 
 *      (`ans`) and `break` out of the inner loop. 
 *    - We can safely `break` early because we are shrinking the number digit by digit. 
 *      This means the very first match we hit for a number is guaranteed to be its 
 *      longest possible prefix.
 *    - If it doesn't match, we chop off the last digit, decrease our current length 
 *      counter, and check again.
 */


class Solution {
public:
    int digitcount(int i){//count number of digits in number
        int ans =0;
        while(i>0){
            i /= 10;
            ans++;
        }
        return ans;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefix; //store every prefix of every number in arr1
        for(int i1 : arr1){
            int x = i1;
            while(x>0){
                prefix.insert(x); // store all prefixes of x
                x /= 10;
            }
        }
        int ans = 0;
        for(int i2 : arr2){
            int len = digitcount(i2);
            int x = i2;
            while(x>0){
                if(prefix.count(x)){//if prefix is available store answer
                    ans = max(ans,len); // this is the largest possible prefix this number can have
                    break;
                }
                len--;
                x /= 10;
            }
        }
        return ans;
    }
};
