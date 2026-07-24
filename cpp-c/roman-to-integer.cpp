/*Leetcode ps-13. Roman to Integer
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.*/


/* Approach - Hash Map & Look-Ahead Evaluation (Time: O(N), Space: O(1))
 * Basically, we sweep through the string, comparing each Roman numeral to the one immediately following it to instantly determine whether we should mathematically add or subtract its value!
 * * Observation: 
 * - Standard Roman numerals are always written largest to smallest from left to right. When this rule is followed perfectly, we just continuously add the values.
 * - The ONLY exception is when a smaller numeral appears directly before a larger one (like 'IV' for 4 or 'IX' for 9). In this specific case, the smaller number is mathematically subtracted from our running total!
 * - Using an `unordered_map` beautifully links each character to its exact integer value. Since the dictionary size is strictly fixed to exactly 7 symbols regardless of the string length, our space complexity is a guaranteed, lightning-fast O(1)!
 * * How it runs:
 * First, we initialize our hash map 'roman' with the seven standard symbols, grab the total string length 'n', and set our running total 'res' to 0.
 * Then, we trigger a loop from index 0 up to 'n - 2'. Stopping exactly one character short of the end completely protects us from out-of-bounds errors during our look-ahead check.
 * Next, at every single step, we evaluate the current character against the next one (`s[i+1]`). If the current value is strictly less than the next one, we subtract it from our result 'res'. Otherwise, we confidently add it!
 * Finally, because our loop intentionally skipped the absolute last character (which never has a character after it to ever force a subtraction), we simply add its value directly to 'res' and return the fully converted integer!
 */

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> roman = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int n = s.size(),res= 0;
        for(int i = 0 ; i < n-1;i++){
            if(roman[s[i]] < roman[s[i+1]]){
                res -= roman[s[i]];
            }else{
                res += roman[s[i]];
            }
        }
        res += roman[s[n-1]];
        return res;
    }
};
