/*Leetcode ps-3783. Mirror Distance of an Integer
You are given an integer n.
Define its mirror distance as: abs(n - reverse(n))​​​​​​​ where reverse(n) is the integer formed by reversing the digits of n.
Return an integer denoting the mirror distance of n​​​​​​​.
abs(x) denotes the absolute value of x.*/



class Solution {
public:
    int rev(int n){
        int res =0;
        while(n>0){
            res = res*10 + n%10;
            n/=10;
        }
        return res;
    }
    int mirrorDistance(int n) {
        return abs(n-rev(n));
    }
};
