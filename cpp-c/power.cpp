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


/* Approach - Fast Exponentiation / Recursive Divide and Conquer (Time: O(log N), Space: O(log N))
 * Basically, we mathematically slice the exponent in half at every single step, allowing us to compute massive powers in mere fractions of a second instead of endlessly multiplying one by one!
 * * Observation: 
 * - A naive loop multiplying `x` exactly `n` times takes O(N) time, which will absolutely crash with a Time Limit Exceeded (TLE) error on massive inputs. By squaring the base and halving the exponent, we brilliantly drop the time complexity to a lightning-fast O(log N)!
 * - Converting `int n` to a `long long N` in the wrapper function is an absolute masterstroke! The absolute minimum 32-bit integer is -2147483648. If you try to flip that to a positive `int` using `-n`, it mathematically overflows the integer limit and completely crashes the program. Using `long long` flawlessly protects against this fatal error!
 * - (Optimization Note: While this recursive approach is incredibly clean and intuitive, it heavily relies on the call stack, burning O(log N) auxiliary memory! You can easily optimize this down to a strict, guaranteed O(1) space by unwinding it into a simple iterative while loop!)
 * * How it runs:
 * First, we safely capture our incoming exponent `n` into a massive `long long N` to flawlessly protect against negative overflow. If the power is negative, we mathematically invert the operation by returning `1.0 / power(x, -N)`.
 * Then, we trigger our recursive `power` function. We instantly check our extreme base cases: if the power is completely drained to 0, we return 1.0, and if it is exactly 1, we return the base `x`.
 * Next comes the true magic! If the exponent is perfectly even (`n % 2 == 0`), we aggressively square our base (`x * x`) and instantly cut our remaining workload exactly in half (`n / 2`).
 * If the exponent is oddly shaped, we mathematically extract one single instance of `x` and recursively process the remaining strictly even exponent (`n - 1`).
 * Finally, the recursive stack beautifully collapses back up, seamlessly multiplying the cascading results together to confidently return our precise final answer!
 */


class Solution {
public:
    double power(double x, long long n) {
        if (n == 0) return 1.0;
        if (n == 1) return x;

    
        if (n % 2 == 0) {
            return power(x * x, n / 2);
        }
        
        return x * power(x, n - 1);
    }
    
    double myPow(double x, int n) {
        
        long long N = n; 
        
        if (N < 0) {
            return 1.0 / power(x, -N);
        }
        
        return power(x, N);
    }
};
