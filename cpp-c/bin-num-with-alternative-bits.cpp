/*Leetcode PS:-693. Binary Number with Alternating Bits
Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.*/

class Solution {
public:
    bool hasAlternatingBits(int n) {
        string binary = "";
        while (n > 0) {
            binary += (n % 2 == 0 ? "0" : "1");
            n /= 2;
        }
        reverse(binary.begin(), binary.end());
        for(int i = 0 ; i < binary.size() - 1 ; i++){
            if(binary[i]==binary[i+1]) return false ;
        }
        return true;
    }
};
