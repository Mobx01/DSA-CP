/*Leetcode ps-3754. Concatenate Non-Zero Digits and Multiply by Sum I
You are given an integer n.
Form a new integer x by concatenating all the non-zero digits of n in their original order. If there are no non-zero digits, x = 0.
Let sum be the sum of digits in x.
Return an integer representing the value of x * sum.*/


/* Approach - Pure Mathematical Digit Extraction (Time: O(D^2), Space: O(1)) 
 * Basically, we reconstruct the number 'x' mathematically from right to left by extracting the last digit of 'n' using modulo, and prepending it to 'x' by shifting it into the correct decimal place based on 'x's current length.
 * * Observation: 
 * - Instead of converting to strings, we can isolate the rightmost digit using 'n % 10' and strip it away using 'n / 10'.
 * - Because we are reading 'n' from right-to-left, we must *prepend* valid digits to our newly forming number 'x' to preserve their original order. We achieve this by multiplying the extracted digit by 10 raised to the power of 'x's current length, effectively pushing the new digit to the absolute front.
 * - Zeros contribute nothing to addition, so we can just blindly add 'n % 10' to our 'sum' every iteration without even needing an if-statement for it.
 * * How it runs:
 * First, we initialize our 'sum' and 'x' to 0, and start a while loop that chops down 'n' until it hits 0.
 * Then, for each iteration, we check if the current last digit ('n % 10') is non-zero. If it is, we call our helper function 'xlen' to see how many digits 'x' currently has, multiply our extracted digit by 10^length to position it correctly, and add the existing 'x' to it.
 * Finally, we add the extracted digit to our running 'sum' and divide 'n' by 10 to move to the next digit. Once the loop ends, we return 'x * sum'!
 */


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

