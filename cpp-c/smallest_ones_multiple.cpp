/*Leetcode weekly contest 482 qno 3 -  Smallest All-Ones Multiple©leetcode
  You are given a positive integer k.
 Find the smallest integer n divisible by k that consists of only the digit 1 
 in its decimal representation (e.g., 1, 11, 111, ...).
 Return an integer denoting the number of digits in the decimal representation of n.
 If no such n exists, return -1.
*/

class Solution {
public:
    int minAllOneMultiple(int k) {
        if (k % 2 == 0 || k % 5 == 0) return -1;

        int rem = 0;
        for (int len = 1; len <= k; len++) {
            rem = (rem * 10 + 1) % k;
            if (rem == 0) return len;
        }
        return -1;
    }
};
©leetcode
