/*Leetcode ps - 179. Largest Number
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
Since the result may be very large, so you need to return a string instead of an integer.

*/

/*
 * APPROACH:
 * 1. Convert to Strings: Transform integers into strings to compare their concatenations easily.
 * 2. Custom Sort: Sort using a lambda comparator: `return a + b > b + a`. 
 * (e.g., For "3" and "30", "330" > "303", so "3" is placed before "30").
 * 3. Handle Zeroes Edge Case: If the largest sorted string is "0" (e.g., input [0, 0]), 
 * return "0" instead of "00".
 * 4. Build Result: Concatenate the sorted strings into the final result.
 * * Time: O(N log N) for sorting.
 * Space: O(N) to store the string representations.
 */

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> str_nums;
        for (int num : nums) {
            str_nums.push_back(to_string(num));
        }
  
        sort(str_nums.begin(), str_nums.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });

        if (str_nums[0] == "0") {
            return "0";
        }
        string res = "";
        for (const string& s : str_nums) {
            res += s;
        }
        
        return res;
    }
};
