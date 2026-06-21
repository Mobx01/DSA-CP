/*Leetcode ps - 509. Fibonacci Number
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).*/

// Approach - recursion + memoization.

class Solution {
public:
    vector<int> t;
    int rec(int n){
        if(n <= 1) return n;
        if(t[n] != -1)return t[n];

        return rec(n-1) + rec(n-2);
    }
    int fib(int n) {
        t.resize(n+1);
        for(int i = 0;i<n+1;i++) t[i] = -1;
        return rec(n);
    }
};
