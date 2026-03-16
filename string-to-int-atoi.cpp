/*Leetcode ps-8. String to Integer (atoi)
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
Return the integer as the final result.

*/
// Approach:
// 1. Skip all leading spaces in the string.
// 2. Check if the next character is '+' or '-' to determine the sign.
// 3. Traverse the string while characters are digits (0–9).
// 4. Build the number using: num = num * 10 + (digit).
// 5. Check for overflow; clamp result within INT_MAX or INT_MIN.
// 6. Return sign * num as the final integer.
class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        long long num = 0;
        int sign = 1;

        // skip leading spaces
        while(i < n && s[i] == ' ')
            i++;

        // checking sign
        if(i < n && (s[i] == '+' || s[i] == '-')){
            if(s[i] == '-') sign = -1;
            i++;
        }

        // converting digits
        while(i < n && isdigit(s[i])){
            num = num * 10 + (s[i] - '0');

            // overflow check
            if(sign * num > INT_MAX) return INT_MAX;
            if(sign * num < INT_MIN) return INT_MIN;

            i++;
        }

        return sign * num;
    }
};
