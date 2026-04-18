/*Leetcode ps:-1009. Complement of Base 10 Integer
The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.
For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
Given an integer n, return its complement*/

//Approach- mathematical approach
// count length of binary of n . for length n maximum number of that length (let max_p )is 2^n -1. so compliment of n is max_p - n;.
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;

        int z = n;
        int len_bin = 0;
        while(z>0){
            len_bin++;
            z /= 2;
        }
        int max_p = pow(2,len_bin)-1;
        return max_p - n;
    }
};
