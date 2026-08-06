/*Leetcode ps-3345. Smallest Divisible Digit Product I
You are given two integers n and t. Return the smallest number greater than or equal to n such that the product of its digits is divisible by t.*/


/* Approach - Bounded Brute Force / Mathematical Loophole (Time: O(log N), Space: O(1))
 * Basically, we aggressively test consecutive numbers starting directly from 'n', ruthlessly shredding them into their individual digits, and relying on a brilliant mathematical guarantee that we will forcefully hit a valid answer in less than 10 steps!
 * * Observation: 
 * - At first glance, searching for a number whose digit product is perfectly divisible by 't' seems like it would require a massive, dangerous while-loop that could potentially run for thousands of iterations.
 * - (The Absolute Game-Breaker): The digit product of ANY number that contains a '0' is mathematically exactly 0! And 0 modulo 't' is always a perfect 0!
 * - Because the last digit of any integer cycles through 0-9 every 10 numbers, it is strictly physically impossible to check 10 consecutive integers without hitting a number that ends in 0. Therefore, the search space is flawlessly, permanently bounded to a maximum of exactly 10 iterations! 
 * - This turns a potentially scary unbounded search into a lightning-fast, guaranteed O(1) loop (with the only scaling factor being the O(log N) time to extract the digits)!
 * * How it runs:
 * First, we trigger our `smallestNumber` function, deploying a strict, hyper-bounded loop that simply checks the next 10 consecutive integers (`n + i`).
 * Then, for every single candidate, we fiercely toss it into our `isdiv` helper function. This function violently rips the number apart digit by digit using modulo 10 and division by 10, continuously multiplying them into our `prod` tracker.
 * Next, the exact millisecond we finish processing the digits, we mathematically evaluate `prod % t == 0`. If it perfectly divides (or if the product is 0), it instantly returns true!
 * Finally, our main loop aggressively intercepts that true signal and instantly returns the current `n + i`, flawlessly delivering the absolute minimum valid number without wasting a single CPU cycle!
 */

class Solution {
public:
    bool isdiv(int n ,int t){
        int prod = 1;
        while(n>0){
            prod *= n%10;
            n /= 10;
        }
        return (prod%t == 0 ? true : false);
    }
    int smallestNumber(int n, int t) {
        for(int i = 0;i<10;i++){
            if(isdiv(n+i,t)) return n+i;
        }
        return 0;
    }
};

