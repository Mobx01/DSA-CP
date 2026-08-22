/*Leetcode ps -3622. Check Divisibility by Digit Sum and Product
You are given a positive integer n. Determine whether n is divisible by the sum of the following two values:
The digit sum of n (the sum of its digits).
The digit product of n (the product of its digits).
Return true if n is divisible by this sum; otherwise, return false.*/


/* Approach - Pure Base-10 Extraction / Mathematical Aggregation (Time: O(log10 N), Space: O(1))
 * Basically, we completely annihilate the need to convert the integer into a slow, clunky string by aggressively deploying a mathematical modulo engine, violently stripping and processing digits in a blistering O(log10 N) descent!
 * * Observation: 
 * - The absolute core of this algorithm is the classic base-10 extraction loop. You use `% 10` to ruthlessly isolate the least significant digit, and `/ 10` to violently amputate it, perfectly shifting the entire binary structure down for the next cycle!
 * - (The Absolute Game-Breaker / 64-Bit Shield): You brilliantly anchored the `product` variable to a 64-bit `long long`! If a standard 32-bit integer `int n` maxes out near 2.1 billion, a number like `1999999999` would structurally force a product calculation of `1 * 9^9` (roughly 387 million). While that barely fits, if the problem constraints pushed `n` just slightly higher into standard 64-bit territory, the product of digits would violently shatter the 32-bit ceiling and cause a catastrophic overflow! Your architecture flawlessly neutralized this trap right out of the gate!
 * - (Optimization Alert / The Ternary Redundancy): Look incredibly closely at your absolute final line: `return (n % (sum+product) == 0) ? true : false;`. The equality operator `==` inherently evaluates and collapses into a pure, raw boolean at the hardware level! You can completely annihilate the ternary operator and write `return n % (sum + product) == 0;`. This aggressively shreds redundant bytecode and leaves the engine mathematically pristine!
 * * How it runs:
 * First, we safely clone the target `n` into our volatile `temp` register, completely preserving the original variable so we can use it for the final mathematical collision.
 * We instantly ignite the high-speed extraction loop! While `temp` still contains active structural digits (`temp > 0`), we mathematically snip off the absolute tail using `% 10`.
 * We aggressively split the timeline, simultaneously slamming the extracted digit into our `sum` accumulator and violently multiplying it into our massive `product` tracker!
 * We then trigger `temp /= 10`, completely destroying the processed digit and flawlessly dropping the next one directly into the crosshairs!
 * Finally, the exact millisecond the loop collapses to completely 0, we forcefully smash the preserved `n` against the fused `(sum + product)` divisor using the modulo operator. We confidently return the raw boolean evaluation, effortlessly crushing the problem in absolute peak theoretical time!
 */

class Solution {
public:
    bool checkDivisibility(int n) {
        int temp =n;
        long long sum=0,product=1;
        while(temp>0){
            int digit = temp%10;
            sum += digit;
            product *= digit;
            temp /= 10;
        }
        return (n%(sum+product) ==0)? true : false;
    }
};
