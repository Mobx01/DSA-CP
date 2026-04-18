/* Leetcode PS - 50 pow(x,n) 
   Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
     // Approach:
     Use binary exponentiation to calculate x^n efficiently.
     If n is negative, convert it to positive by taking reciprocal of x.
     Multiply result with x when n is odd, square x each step, and divide n by 2.

      // Time Complexity: O(log n)
      // Space Complexity: O(1)
*/

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1.0 / x;
            N = -N;
        }

        double result = 1.0;
        while (N > 0) {
            if (N % 2 == 1) {
                result *= x;
            }
            x *= x;
            N /= 2;
        }

        return result;
    }
};

