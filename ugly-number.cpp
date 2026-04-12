/*Leetcode ps- 263. Ugly Number
An ugly number is a positive integer which does not have a prime factor other than 2, 3, and 5.
Given an integer n, return true if n is an ugly number.*/

class Solution {
public:
    bool isUgly(int n) {
        if(n<0) return false;// has factor -1;
        if(n == 0) return false; 
        while(n>1){
            if(n%2 == 0) n /= 2;
            else if(n%3 == 0) n /= 3;
            else if(n%5 == 0) n /= 5;
            else return false ; // number has other prime fastor than 2,3,5.
        }
        return true;
    }
};
