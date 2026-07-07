/*Leetcode ps-3754. Concatenate Non-Zero Digits and Multiply by Sum I
You are given an integer n.
Form a new integer x by concatenating all the non-zero digits of n in their original order. If there are no non-zero digits, x = 0.
Let sum be the sum of digits in x.
Return an integer representing the value of x * sum.*/

/* Approach - String Parsing & Math (Time: O(D), Space: O(D)) where D is the number of digits in n
 * Basically, we extract all the non-zero digits to simultaneously build our new number 'x' and calculate the total digit sum.
 * * Observation: 
 * - Zeros contribute absolutely nothing to the final concatenated value of 'x', nor do they add any value to the digit 'sum'.
 * - Converting the integer to a string allows us to easily isolate and concatenate the non-zero digits while preserving their exact original order from left to right.
 * * How it runs:
 * First, we convert the given integer 'n' into a string to easily iterate through its individual characters. We also initialize an empty string 'x_str' to build our new number and an integer 'sum' to zero.
 * Then, we loop through every character in the string. If the character is NOT '0', we append it to 'x_str' and mathematically add its true integer value (char - '0') to our running 'sum'.
 * Finally, we check if 'x_str' is empty (which happens if 'n' was 0 or contained only zeros). If it is, we return 0. Otherwise, we convert 'x_str' back into an integer (using long long to prevent overflow) and return the product of 'x' and 'sum'!
 */
class Solution {
public:
    long long concatenateAndMultiply(int n) {
        string s = to_string(n);
        string x_str = "";
        long long sum = 0;
        
        for (char c : s) {
            if (c != '0') {
                x_str += c;
                sum += (c - '0');
            }
        }
        
        if (x_str.empty()) {
            return 0;
        }
        
        long long x = stoll(x_str);
        return x * sum;
    }
};

class Solution {
public:
    int xlen(int x){
        int count =0;
        while(x != 0){
            x /= 10;
            count++;
        }
        return count;
    }
    long long sumAndMultiply(int n) {
        long long sum= 0;
        int x = 0;
        while(n != 0){
            if(n%10) x = x + (n%10)*pow(10,xlen(x));

            sum += n%10;
            n /= 10;
        }
        return x*sum;
    }
};

